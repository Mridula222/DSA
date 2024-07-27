#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*lchild;
    struct node*rchild;
};
void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void delete1();
void caseA(struct node*,struct node*);
void caseB(struct node*,struct node*);
void caseC(struct node*,struct node*);
struct node*root=NULL;
int main(){
    int choice;
    while(1){
            printf("1.insert\n2.inorder traversal\n3.preorder traversal\n4.postorder traversal\n5.deletion\n");
            printf("enter your choice\n");
            scanf("%d",&choice);
            switch(choice){
            case 1: insert(); break;
            case 2: if(root==NULL){
                printf("tree is empty\n");
            }
            else{
                inorder(root);
                printf("\n");
            }
            break;
            case 3: if(root==NULL){
                printf("tree is empty\n");
            }
            else{
                preorder(root);
            }
            break;
            case 4: if(root==NULL){
                printf("tree is empty\n");
            }
            else{
                postorder(root);
                printf("\n");
            }
            break;
            case 5: delete1(); break;
            default: printf("wrong choice\n");
        }
    }
    return 0;
}
void insert(){
    struct node*temp,*ptr,*par;
    int item;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("memory allocation failed\n");
    }
    else{
        printf("enter the item\n");
        scanf("%d",&item);
        temp->info=item;
        temp->lchild=NULL;
        temp->rchild=NULL;
        if(root==NULL){
            root=temp;//for first node
        }
        else{
            ptr=root;
            while(ptr!=NULL){
                par=ptr;
                if(item<ptr->info){
                    ptr=ptr->lchild;
                }
                else if(item>ptr->info){
                    ptr=ptr->rchild;
                }
                else{
                    printf("duplicate element cannot be inserted\n");
                    break;
                }
            }
            if(ptr==NULL){//got the position where to insert
                if(item<par->info){
                    par->lchild=temp;
                }
                else{
                    par->rchild=temp;
                }
            }
        }
    }
}
void inorder(struct node*temp){
    if(temp!=NULL){
        inorder(temp->lchild);//L+
        
        printf("%d",temp->info);//N
        inorder(temp->rchild);//R

    }
}
void preorder(struct node*temp){
    if(temp!=NULL){
        printf("%d",temp->info);//N
        inorder(temp->lchild);//L
        inorder(temp->rchild);//R
    }
}
void postorder(struct node*temp){
    if(temp!=NULL){
        inorder(temp->lchild);//L
        inorder(temp->rchild);//R
        printf("%d",temp->info);//N
    }
}
void delete1(){
    struct node*ptr,*par;//ptr will point to that node which needs to be deleted and par points to prev node which needs to be updated.
    int item;
    if(root==NULL){
        printf("tree is empty\n");
    }
    else{
        ptr=root;
        par=NULL;
        printf("enter the node to be deleted\n");
        scanf("%d",&item);
        while(ptr!=NULL){
            if(ptr->info==item){
                break;
            }
            par=ptr;
            if(item<ptr->info){
                ptr=ptr->lchild;
            }
            else{
                ptr=ptr->rchild;
            }
        }
        if(ptr==NULL){
            printf("node is not present\n");
        }
        else{
            printf("deleted node is %d\n",ptr->info);
            if((ptr->lchild==NULL)&&(ptr->rchild==NULL)){
                caseA(par,ptr);
            }
            else if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL)){
                caseC(par,ptr);
            }
            else{
                caseB(par,ptr);
            }
        }
    }
}
void caseA(struct node*par,struct node*ptr){
    if(par==NULL){ //deleting the root
        root=NULL;
        free(ptr);
    }
    else{
        if(ptr->info<par->info){
            par->lchild=NULL;
        }
        else{
            par->rchild=NULL;
        }
        free(ptr);
    }
}
void caseB(struct node*par,struct node*ptr){
    struct node*child;
    if(ptr->lchild!=NULL){
        child=ptr->lchild;
    }
    else{
        child=ptr->rchild;
    }
    if(par==NULL){
        root=child;
        free(ptr);
    }
    else{
        if(ptr==par->lchild){
            par->lchild=child;
        }
        else{
            par->rchild=child;
        }
        free(ptr);
    }
}
void caseC(struct node*ptr,struct node*par){
    struct node*pptr,*ppar;
    pptr=ptr->rchild;
    ppar=ptr;
    while(pptr->lchild!=NULL){ //extreme left
        ppar=pptr;
        pptr=pptr->lchild;
    }
    ptr->info=pptr->info;//inorder successor
    if(pptr->rchild!=NULL){
        caseB(ppar,pptr);//pptr which we want to delete is a node with one child
    }
    else{
        caseA(ppar,pptr);//we want to delete a node with 0 child
    }
}