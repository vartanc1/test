#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//global variables
struct cell {
    int position;
    int adjcount;
    int mined;
    int covered;
    int flagged;
};

typedef struct cell cell;

cell **board; //2-d dynamically allocated array of cells
int rows;
int cols;
int mines;

void init_cell(cell *c, int p){
    c->position = p;
    c->mined = 0;
    c->adjcount = 0;
    c->covered = 1;
    c->flagged = 0;
}


int get_random(int range){ //random num generator
    return ((int)floor((float)range*rand()/RAND_MAX))%range;
}

void command_new(){
    board = (cell **) malloc(sizeof(cell *) * rows);

    for(int i = 0 ; i < rows; ++i){
        board[i] = (cell *) malloc(sizeof(cell) * cols);
    }
    for(int i = 0 ; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            int p = i*cols + j;
            init_cell(&board[i][j],p);
            //board[i][j].position = i*cols + j;
        }
    }

    //insert mines section
    for(int m = 1; m < mines; ++m){
        int r = get_random(rows-1);
        int c = get_random(cols-1);

        while(board[r][c].mined == 1){ //if board cell has mine, keep looping till u get rand cell with no mine
            r = get_random(rows-1);
            c = get_random(cols-1);
        }
        board[r][c].mined = 1; //place mine into cell

    }

    //adjcount calculation
    int neighborcount = 8;
    int rowneighbors[] = {-1,-1,+0,+1,+1,+1,+0,-1};
    int colneighbors[] = {+0,+1,+1,+1,+0,-1,-1,-1};
    for(int r = 0; r < rows;++r){
        for(int c = 0; c < cols; ++c){
            int minecount = 0;
            for(int d = 0; d < neighborcount; ++d){
                int rn = r + rowneighbors[d];
                int cn = c + colneighbors[d];

                if(0 <= rn && rn < rows && 0 <= cn && cn < cols){
                    if(board[rn][cn].mined == 1){
                        minecount++;
                    }
                }

            }// loops around specific cell and checks all 8 corners for *'s and adds 1 to minecount if found
            //loop breaks gives specific cell mine count and continues to next cell
            board[r][c].adjcount = minecount;
        }
    }

}



void display_cell(cell *c) {
    if(c->flagged == 1){
        printf("P");
    }
    else if(c->covered == 1){
        printf("/");
    }
    else if (c->mined == 1){
        printf("%2s", "*");

    }
    else if (c->adjcount > 0){
        printf("%2d",c->adjcount);
    }
    else printf("%2s", ".");
}




void command_show(){

    for(int i = 0 ; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            display_cell(&board[i][j]);
        }
        printf("\n");
    }

}



void uncoverall(){
    for(int i = 0 ; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            cell *c = &board[i][j];
            c->covered = 0;
            display_cell(&board[i][j]);
        }
        printf("\n");
    }

}


void coverall(){
    for(int i = 0 ; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            cell *c = &board[i][j];
            c->covered = 1;
            display_cell(&board[i][j]);
        }
        printf("\n");
    }

}


void uncover(int r, int col){ //uncover not working

    for(int i = 0 ; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            cell *c = &board[i][j];
            display_cell(&board[i][j]);
        }
        printf("\n");
    }
    cell *c = &board[r][col];
    c->covered = 0;

    if(c->mined == 1){
        printf("Uncovered mine, you lose!");
            }
            

}

// void command_flag(int r, int c){ //not working wityh board, making new whole board
//     if(board[r][c].flagged == 0){
//         board[r][c].flagged = 1;
//     }
//     else{
//         printf("cell already flagged\n");
//     }
// }
#define MAXTOKENS 20
#define MAXCHARLENGTH 80
int rungame(){
    char line[MAXCHARLENGTH];
    char linecopy[MAXCHARLENGTH];
    char tokens[MAXTOKENS][MAXCHARLENGTH];
    char *tok;
    int tokencount;

    while(1){
        //get next command
        printf(">>  ");
        fgets(line,80,stdin);
        line[strlen(line)-1] = '\0';
        strcpy(linecopy,line);

        //tokenize inputs
        tok = strtok(linecopy, " ");
        tokencount = 0;
        while(tok != NULL){
            strcpy(tokens[tokencount],tok);
            tok = strtok(NULL, " ");
            ++tokencount;
        }

        
        // printf("total tokens = %d\n",tokencount);

        // //process next command
        // printf("name command = %s\n", tokens[0]);

        if(strcmp(tokens[0],"quit") == 0){
            printf("Bye!\n");
            break;
        }
        else if(strcmp(tokens[0],"new") == 0) {
            printf("New Board Command\n");
            rows = atoi(tokens[1]);
            cols = atoi(tokens[2]);
            mines = atoi(tokens[3]);
            command_new();
            //new command
        }
        else if(strcmp(tokens[0],"show") == 0) {
            //show command
            printf("Show Board Command \n");
            command_show();
        }
        else if(strcmp(tokens[0],"uncoverall") == 0) {
            uncoverall();
        }
        else if(strcmp(tokens[0],"coverall") == 0) {
            coverall();
        }
        else if(strcmp(tokens[0],"uncover") == 0) {
            rows = atoi(tokens[1]); 
            cols = atoi(tokens[2]);
            uncover(rows,cols);
        }
        // else if(strcmp(tokens[0],"flag") == 0){
        //     rows = atoi(tokens[1]);
        //     cols = atoi(tokens[2]);
        //     command_flag(rows,cols);
        // }


    }

    return 0;
}

int main(void){
   srand(time(0));
    rungame();
    return 0;
}