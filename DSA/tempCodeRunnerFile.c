#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*right;
    struct node*left;
};
struct node*createnode(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node*insertnode(struct node*root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data<root->data){
        root->left=insertnode(root->left,data);
    }
    if(data>root->data){
        root->right=insertnode(root->right,data);
    }
    return root;
}
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node*root=NULL;
    int key,item,choice;
    while(1){
        printf("1.insert node\n2.inorder\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the item\n");
            scanf("%d",&item);
            root=insertnode(root,item);
            break;
            case 2:inorder(root); break;
            default: printf("invalid choice\n");
        }
    }
}
