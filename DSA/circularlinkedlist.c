#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node*start=NULL;
void create();
void traverse();
void insertbegin();
void insertend();
void insertloc();
void deletebeg();
void deleteend();
void deleteloc();
int main(){
    int choice;
    while(1){
        printf("1.create\n2.traverse\n3.insertbegin\n4.insertend\n5.insert at loc\n6.deletebeg\n7.deleteend\n8.deleteloc");
        printf("enter yourchoice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: create(); break;
            case 2: traverse(); break;
            case 3: insertbegin(); break;
            case 4: insertend(); break;
            case 5: insertloc(); break;
            case 6: deletebeg(); break;
            case 7: deleteend(); break;
            case 8: deleteloc(); break;
            default: printf("invalid choice\n");
        }
    }
}
void create(){
    int total,item,index;
    struct node *newnode,*temp;
    if(start==NULL){
        printf("enter total number of nodes you want to keep");
        scanf("%d",&total);
    }
    if(total<=0){
        printf("list size must be greater than zero");
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));//CREATION OF FIRST NODE
        printf("enter the value to keep in the node");
        scanf("%d",&item);
        temp->info=item;
        temp->next=temp;
        start=temp;
        for(int i=2;i<=total;i++){
            newnode= (struct node*)malloc(sizeof(struct node));
            printf("enter the value to keep in the node");
            scanf("%d",&item);
            newnode->info=item;
            newnode->next=start;//last node will keep the adress of first one
            temp->next=newnode;
            temp=newnode;
        }
        printf("list is created\n");
    }
}
void traverse(){
    struct node*temp;
    if(start==NULL){
        printf("list is empty");
    }
    else{
        temp=start;
        printf("values are:");
        do{
            printf("%d\t",temp->info);
            temp=temp->next;
        }
        while(temp!=start);
        printf("\n");
    }
}
void insertbegin(){
    struct node*newnode,*temp;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory is not allocated\n");
    }
    else{
        printf("enter the value to insert\n");
        scanf("%d",&item);
        newnode->info=item;
        newnode->next=newnode;
    }
    if(start==NULL){
        start=newnode;
    }
    else{
        temp=start;
        while(temp->next!=start){
            temp=temp->next;
        }
        newnode->next=start;//newnode contains the address of prev 1st node
        start=newnode;
        temp->next=newnode;
    }
}
void insertend(){
    struct node*newnode,*temp;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory not allocated");
    }
    else{
        printf("enter the value to insert");
        scanf("%d",&item);
        newnode->info=item;
        newnode->next=newnode;//if any single node is created keep the same address in the node.
        if(start==NULL){
            start=newnode;
        }
        else{
            temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=start;
        }
    }
}
void insertloc(){
    struct node*newnode,*temp,*ptr;
    int item,loc,count=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory not allocated");
    }
    else{
        printf("enter the value to insert");
        scanf("%d",&item);
        newnode->info=item;
        newnode->next=newnode;//if there is the single node then it will keep its own address in the next part.
    }
    if(start==NULL){
        start=newnode;
    }
    else{
        printf("enter the location at which you want to insert\n");
        scanf("%d",&loc);
        temp=start;
        do{
            count++;
            ptr=temp;
            temp=temp->next;
        }
        while(temp!=start && count!=loc);
        if(temp==start){
            printf("node is not present");
        }
        else{
            ptr->next=newnode;
            newnode->next=temp;
        }
    }
}
void deletebeg(){
    struct node*temp,*ptr;
    if(start==NULL){
        printf("list is empty\n");
    }
    else{
        temp=start;
        ptr=start;
        while(ptr->next!=start){
            ptr=ptr->next;
        }
        printf("deleted value is %d",temp->info);
        start=start->next;//start is pointing to 2nd node
        ptr->next=start;
        free(temp);
    }
}
void deleteend(){
    struct node*temp,*ptr;
    if(start==NULL){
        printf("list is empty");
    }
    else{
        temp=start;
        if(start==NULL){
            printf("memory not allocated");
        }
        else{
            while(temp->next!=start){
                ptr=temp;//ptr will point to the prev node of the last node
                temp=temp->next;
            }
            printf("deleted node is %d",temp->info);
            ptr->next=start;
            free(temp);
        }
    }
}
void deleteloc(){
    struct node*temp,*ptr;
    int item,count=1,loc;
    if(start==NULL){
        printf("memory not allocated");
    }
    else{
        temp=start;
        if(start->next==NULL){
            start=NULL;
            printf("delted value is %d",temp->info);
            free(temp);
        }
        else{
            printf("enter the location from which you want to delete\n");
            scanf("%d",&loc);
            temp=start;
                do{
                    ptr=temp;
                    temp=temp->next;
                    count++;
                }
                while(temp!=start && count!=loc);
                if(temp==start){
                    printf("node is not present\n");
                }
                else{
                    ptr->next=temp->next;
                    printf("deleted value is %d",temp->info);
                    free(temp);
                }
            }
        }
    }
