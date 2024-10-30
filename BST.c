#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
}*temp;

struct node* insertion(struct node* root,int value){
    if (root==NULL){
        temp = (struct node*) malloc(sizeof(struct node));
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(root->value < value){
        root->right = insertion(root->right,value);
    }
    if(root->value > value){
        root->left = insertion(root->left,value);
    }
    return root;
}

void in_ord_trav(struct node* root){
    if(root!=NULL){
        in_ord_trav(root->left);
        printf("%d ",root->value);
        in_ord_trav(root->right);
    }
}

void post_ord_trav(struct node* root){
    if(root!=NULL){
        post_ord_trav(root->left);
        post_ord_trav(root->right);
        printf("%d ",root->value);
    }
}

void pre_ord_trav(struct node* root){
    if(root!=NULL){
        printf("%d ",root->value);
        pre_ord_trav(root->left);
        pre_ord_trav(root->right);
    }
}

struct node* delete(struct node*root,int value){
    if(root==NULL){
        return root;
    }
    if(value<root->value){
        root->left = delete(root->left,value);
    }
    else if(value>root->value){
        root->right = delete(root->right,value);
    }
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root); 
            return temp;
        }
        if(root->right == NULL){
            struct node* temp = root->left;
            free(root); 
            return temp;
        }
        struct node *current = root->right;
        while(current && current->left!=NULL){
            current  = current->left;
        }
        root->value = current->value;
        root->right = delete(root->right,current->value);
    }
    return root;
}

void search(struct node *root,int value){
    while(root!=NULL){
        if(root->value == value){
            printf("\nValue found");
            return;
        }
        else if(root->value<value){
            root = root->right;
        }
        else if(root->value>value){
            root = root->left;
        }
    }
    printf("\nValue not found");
}

int main()
{
    struct node *root = NULL;
    root = insertion(root,5);
    root = insertion(root,3);
    root = insertion(root,8);
    root = insertion(root,1);
    root = insertion(root,4);
    root = insertion(root,6);
    root = insertion(root,10);
    root = insertion(root,7);
    root = insertion(root,9);
    root = insertion(root,11);

    printf("\nOrginal tree : ");
    in_ord_trav(root);
    printf("\nAfter deletion :");
    root = delete(root,8);

    printf("\nIn-order traversal : ");
    in_ord_trav(root);

    printf("\nPost-order traversal : ");
    post_ord_trav(root);

    printf("\nPre-order traversal : ");
    pre_ord_trav(root);

    search(root,10);
    search(root,2);
    return 0;
}
