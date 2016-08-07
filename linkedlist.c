#include<stdio.h>
#include<stdlib.h>


// A linked list node
struct node{
    int data;
   struct node *next;
};

void printList(struct node *ptr){
    
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

void insertAtBeganing(int datas, struct node **head_ref){
    //create a new node
   struct node *new_node=(struct node*) malloc(sizeof(struct node));
   //add the data to new node
   new_node->data=datas;
   //make new node point to head node
   new_node->next=(*head_ref);
   //make new head point to new node
   (*head_ref)= new_node;
}
void insertAfter(int datum,struct node *node_ref){
    if (node_ref==NULL){
        printf("node cannot be inserted after the null node ");
    }
    printf("adding new node after- %d",node_ref->data);
    //create a new node
    struct node *new_node= (struct node*)malloc(sizeof(struct node));
    //add the data to new node
    new_node->data=datum;
    //point the new node to next node pointed by earlier node
    new_node->next=node_ref->next;
    //point the next of old node to newly inserted node
    node_ref->next=new_node;
}

void insertAtEnd(int datum, struct node **startNode){
    //sdf
    struct node *last= *startNode;
     struct node *new_node= (struct node*)malloc(sizeof(struct node));
     new_node->data=datum;
     if(startNode==NULL){
         printf("empty list");
         *startNode=new_node;
         return;
     }
     while(last->next != NULL){
         last= last->next;
     }
     last->next=new_node;
     return;
}

//creating a sample linked list with 3 nodes
int main(){
   struct node *head = NULL;
    struct node *second = NULL;
    struct node * third = NULL;
    //allocating the memory to the nodes
    head= (struct node*)malloc(sizeof(struct node)); 
    second= (struct node*)malloc(sizeof(struct node));
    third= (struct node*)malloc(sizeof(struct node));
    
    head->data=1;
    second->data=2;
    third->data=3;
    
    head->next=second;
    second->next=third;
    third->next=NULL;
    
   // printList(head);
    insertAtEnd(99,&head);
    printList(head);
    printf("\n");
   // insertAfter(5,head);
    //printList(head);
    return 0;
}
