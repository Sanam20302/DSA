#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node* next;
}
*temp,*top = NULL;
void push(int data){
    temp = (struct node *)(malloc(sizeof(struct node)));
    temp->value = data;
    temp->next = NULL;
    if(top==NULL){
        top = temp;
    }else{
        temp->next = top;
        top=temp;
    }
}
void pop(){
    if(top==NULL){
        printf("Empty\n");
    }
    else{
        printf("Popped %d\n",top->value);
        top = top->next;
    }    
}
void peak(){
    printf("Top element is %d\n",top->value);
}
void display(){
    if(top==NULL){
        printf("Empty\n");
    }
    else{
        for (struct node* temp = top; temp != NULL; temp = temp->next){
            printf("%d ", temp->value);
        }
    }
}

int main(){
    push(10);
    push(20);
    peak();
    pop();
    pop();
    pop();
    push(22);
    push(21);
    display();
    return 0;
}
