#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node* next;
}
*temp,*front = NULL,*rear = NULL;

void enqueue(int data){
    temp = (struct node *)(malloc(sizeof(struct node)));
    temp->value = data;
    temp->next = NULL;
    if(front==NULL){
        front = rear = temp;
    }else{
        rear->next = temp;
        rear=temp;
    }
}
void dequeue(){
    if(front==NULL){
        printf("Empty\n");
    }
    if(front==rear){
	printf("Dequeued %d\n",front->value);
	front=rear=NULL;
    }
    else{
        printf("Dequeued %d\n",front->value);
        front = front->next;
    }    
}

void display(){
    if(front==NULL){
        printf("Empty\n");
    }
    else{
        for (struct node* temp = front; temp != NULL; temp = temp->next){
            printf("%d ", temp->value);
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(33);
    enqueue(33);
    enqueue(11);
    dequeue();
    dequeue();
    dequeue();
    enqueue(22);
    enqueue(21);
    display();
    return 0;
}
