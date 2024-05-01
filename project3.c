//Vartan Chakryan
//Comp 322 Spring 2024
//Project 3


#include <stdio.h>
#include <stdlib.h>

//Data structures
typedef struct block {
    int data;
    int next_index;


} block;
//Global Variables
int table_size = 0;
int head_index = -1;
block * table = NULL;



//Functions Prototypes

void print_table();
void add_block();
void remove_block();

//Functioins

int main(){
    int i;
    int option = 0;
    //Enter table size
    printf("Enter the table size:\n");
    scanf("%d",&table_size);

    if(table_size <= 0){
        printf("Error, Invalid table size.\n");
        return 0;
    }

    //Create file allocation table
    table = (block *)malloc(table_size * sizeof(block));
    for(int i = 0; i < table_size;++i){
        table[i].data = 0;
        table[i].next_index = -1;

    }
    //Main program loop 
    while(option != 4){
        option = 4;
        printf("\n");
        printf("1) Print the table\n");
        printf("2) Add a block to the tablen");
        printf("3) Remove a block from the table\n");
        printf("4) Quit the program\n");

        printf("Enter selection:\n");     
        scanf("%d",&option);


        switch(option){

            case 1:
                print_table();
                break;
            case 2:
                add_block();
                break;
            case 3:
                remove_block();
                break;

            case 4:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid option, try again.");
        }      


    //Deallocate the file allocation table :D
    free(table);
    return 0;
}
}
//End of main function

void print_table(){
    int i;
    int current_index;

    //Print the array view header row
    printf("Array view:\n");
    printf("Index\tData\tNext\n");
    //Print every block as a row from an array
    for(int i = 0; i < table_size;++i){
        printf("%d\t%d\t%d\n",i, table[i].data,table[i].next_index);
    }
    //Print the file viewer header row
    printf("File view:\n");
    printf("Index\tData\tNext\n");

    //Print every block as a row from a file
    current_index = head_index;

    while(current_index != 1){
        printf("%d\t%d\t%d\n",current_index, table[current_index].data,table[current_index].next_index);
        current_index = table[current_index].next_index;

    }

};

void add_block(){
    int new_index = -1;
    int new_data = -1;
    //Enter the new block index
    printf("Enter an index for the block to add");
    scanf("%d",&new_index);

    if(new_index < 0 || new_index >= table_size){
        prtinf("Invalid Index.\n");
        return;
    }
    //Enter the data for the new block
    printf("Enter an unsigned integer of data:\n");
    scanf("%d",&new_data);
    if(new_data < 0){
        printf("Invalid data returned\n");
        return;
    }

    //Check the value of the head index
    if(head_index == -1){
        head_index = new_index;
        table[new_index].data = new_data;
        printf("Added first block at index %d.\n",new_index);
        //Assign the new blcok to the head of the file


    }
    else{
        current_index = head_index;
        while(current_index != new_index){
            //the new index is not in use if the end of the file is reached
            if(table[current_index].next_index == -1){
                //asign the new blcok to the end of the file
                table[current_index].next_index = new_index;
                table[new_index].data = new_data;
                printf("Added new Block at index %d.\n",new_index);
                return;
            }


            current_index = table[current_index].next_index;


    }
    printf("Duplicate index detected.\n");
        //Iterate through the file and detect if the new index is in use or not

    }


};

void remove_block(){
    int block_index = 
    int new_index = -1;
    int removal_index = -1;

    printf("Enter an index for the block to remove");
    scanf("%d",&new_index);

    if(new_index < 0 || new_index >= table_size){
        prtinf("Invalid Index.\n");
        return;
    }

    //Check the value of the head index
    if(head_index == removal_index){
        head_index = block_index;
        table[new_index].data = new_data;

        printf("Added first block at index %d.\n",new_index);
        //Assign the new blcok to the head of the file


    }

};