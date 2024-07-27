#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node*top=NULL;
void push();
void pop();
void display();
int main(){
    int choice;
    while(1){
        printf("1.push\n2.pop\n3.display");
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            default: printf("invalid choice\n");
        }
    }
}
void push(){  //insert at begining
    struct node*temp;
    int item,start;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("memory is not allocated\n");
    }
    else{
        printf("enter the value to insert\n");
        scanf("%d",&item);
        temp->info=item;
        temp->next=NULL;
    }
    if(top==NULL){
        top=temp;
    }
    else{
        temp->next=top;
        top=temp;
    }
}
void pop(){  // delete from begining
    struct node*temp;
    if(top==NULL){
        printf("stack underflow");
    }
    else{
        temp=top;
        top=top->next;
        printf("deleted value is %d",temp->info);
        free(temp);
    }
}
void display(){
    struct node*temp;
    if(top==NULL){
        printf("stack underflow");
    }
    else{
        temp=top;
        printf("values are:");
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}
