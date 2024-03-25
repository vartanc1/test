//Vartan CHakryan
//Comp 322 Spring 2024
//Project 2

#include <stdio.h>
#include <stdlib.h>



//Data structs
typedef struct relation {
    int * to_resource;
    //Indices: Resources
    //0 - None, 
    //1 - Process requested Resource, 
    //2 - Process allocated resource

}relation;

//Global Variables
relation * process = NULL;
int processes = 0;
int resources = 0;


//Function protypes
void print_relations();
void change_relations{());
void detect_deadlock{};
int detect_deadlock_recursively(int target_index, intcurrent_index);


//functions
int main(){
    int i;
    int j;
    int option = 0;
    //Enter the number of processes
    printf("Enter the number of processes\n");
    scanf("%d",&processes);

    if(processes <= 0){
        printf("Invalid # of processes");
        return 0;
    }

    //Enter the number of resources
    printf("Enter the number of resources\n");
    scanf("%d",&resources);
    
    if(resources <= 0){
        printf("Invalid # of resources");
        return 0;
    }

    //Create all process to resource relations
    process = (relation *)malloc(processes * sizeof(relation));
    for(i = 0; i < processes; i++){
        processes[i].to_resource = (int *)malloc(resources * sizeof(int)); 
        for(j = 0; j < resources; ++j){
            processes[i].to_resource[j] = 0;
        }

    }
    //Main program loop
    while(option != 4){
        option = 4;
        printf("Print theprocess to reosource relations\n");
        printf("Change a process to resorce relation");
        printf("Detect the system for deadlock");
        printf("4)");
        printf("5)");
        scanf("%d",&option);

        switch(option){
            case 1:
                print_relations();
                break;
            case 2:
            change_relations();
                break;

            case 3:
            detect_deadlock();
                break;

            case 4:
                printf("Goodbye");
                break;

            default:
                printf("Invalid input");
        }
    }

    //deallocate the process-to-resource- relation
    for(i = 0; i < processes;++i){
        free(process[i].to_resource);
    }
    free(process);
    return 0;


}//end of main function

void print_relations(){
    int i;
    int j;
    for(j = 0; j < resources; ++j){
        printf("\tr%d",j);        
    }
    printf("\n");


    //print header row

    //print every process as row
    for(i = 0; i < processes; i++){
        printf("p%d",i);
        for(j = 0; j < resources; ++j){
        printf("\t");
        if(process[i].to_resource[j] != 0){
            printf("%d",process[i].to_resource[j]);

        }    
    }
    printf("\n");

    }

};
void change_relations(){
    int process_index = -1;
    int resource_index = -1;
    int new_relation = -1;
    //Enter the process index
    printf("Enter the process index:\n");
    scanf("%d",&process_index);
    if(process_index < 0 || process_index >= processes){
        printf("Invalid process index.\n");
        return;

    }
    //Enter teh resource index
    printf("Enter the resource index:\n");
    scanf("%d",&resource_index);
    if(resource_index < 0 || resource_index >= resources){
        printf("Invalid resource index.\n");
        return;

    }

    //Enter the new relation between the process and resource
    printf("Enter the new relation");
    scanf("%d",&new_relation);

    //Perform a different action based on the new relation
    switch(new_relation){
        case 0: //no relation
            process[process_index].to_resource[resource_index] = 0;
            printf("There is now no relation between process %d and resource %d.\n",process_index, resource_index);
            break;
        case 1: //process requirested resource
            process[process_index].to_resource[resource_index] = 1;
            printf("Process %d is requesting to use resource %d", process_index, resource_index);
            break;
        case 2: //process allocated resource
            for(i = 0; i < processes; ++i){
                if(i != process_index && process[i].to_resource[resource_index] == 2){
                    printf("Process %d cannot be allocated resource %d because process %d is using it.\n",process_index, resource_index);
                    return;
                }
            }

            process[process_index].to_resource[resource_index] = 2;
            printf("Process %d has been allocated resource %d for usage\n",process_index, resource_index);

            break;
        default: //anything else or error
            printf("Invalid relation value.\n");
    }

};
void detect_deadlock(){
        printf("DETECT DEADLOCK");//temp delete later

};
int detect_deadlock_recursively(int target_index, intcurrent_index){
    printf("DETECT DEADLOCK RECURISVELY");
    return 0;
};