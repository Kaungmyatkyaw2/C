#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *nextPtr;
};

struct node *firstNode;

void createNodeList(int numberOfNodes);
void insertAtEnd(int nodeData);
void display();

int main(){


    int numberOfNodes;
    int nodeData;

    test :
    printf("Input the number of nodes : ");
    scanf("%d",&numberOfNodes);



    if(numberOfNodes >= 1){
        createNodeList(numberOfNodes);
        printf("\nThe data you have entered are : \n");
        display();
    }
    if(numberOfNodes < 1){
        printf("Pls create 1 data at least!\n");
        goto test;
    }


    int definder;


    while(1==1){
        puts("\n1.INSERT LAST\n2.DISPLAY NODE\n");

        scanf("%d",&definder);

        if(definder == 1){
                printf("Input to store the latest value : ");
                scanf("%d",&nodeData);
                insertAtEnd(nodeData);
        }else if(definder == 2){
            display();
        }


    }

//    printf("Input to store the latest value : ");
//    scanf("%d",&nodeData);
//    insertAtEnd(nodeData);
//
//    display();



    return 0;
}


void createNodeList(int numberOfNodes){
    struct node *newNode;
    struct node *tempNode;

    int nodeData;
    int nodeCtr;

    firstNode = (struct node *) malloc(sizeof (struct node));

    if(firstNode == NULL){
        printf("Failed to allocated\n");
    }else{
        printf("Input data for node 1 : ");
        scanf("%d",&nodeData);

        firstNode->data  = nodeData;
        firstNode->nextPtr = NULL;

        tempNode = firstNode;

        for (nodeCtr = 2; nodeCtr <= numberOfNodes ;nodeCtr++) {

            newNode = (struct node *) malloc(sizeof (struct node));

            if(newNode == NULL){
                printf("failed");
                break;
            }else{
                printf("Input data for node %d : ",nodeCtr);
                scanf("%d",&nodeData);

                newNode->data = nodeData;
                newNode->nextPtr = NULL;

                tempNode->nextPtr = newNode;
                tempNode = tempNode->nextPtr;

            }

        }

    }

}



void insertAtEnd(int nodeData){

    struct node *newNode;
    struct node *tempNode;

    newNode = (struct node *) malloc(sizeof (struct node));

    if(newNode == NULL){
        printf("failed");
    }else{
        newNode->data = nodeData;
        newNode->nextPtr = NULL;

        tempNode = firstNode;

        while (tempNode->nextPtr != NULL){
            tempNode = tempNode->nextPtr;
        }


        tempNode->nextPtr = newNode;

    }


}


void display(){
    struct node *tempNode;


    if(firstNode == NULL){
        printf("No data");
    }else{
        tempNode = firstNode;

        while (tempNode != NULL){
            printf("Data = %d\n",tempNode->data);
            tempNode = tempNode->nextPtr;
        }
    }

}
