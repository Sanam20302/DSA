#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max],front = -1, rear = -1;
void enqueue(int data){
    if(rear == (max-1)){
        printf("Overflow\n");
    }
    else if(front==-1){
        front = rear = 0;
        arr[rear]=data;
        printf("Enqueued %d\n",data);
    }
    else{
        arr[++rear]=data;
        printf("Enqueued %d\n",data);
    }
}
void dequeue(){
    if(front==-1){
        printf("Underflow\n");
    }
    else if(front==rear){
        printf("Dequeued %d\n",arr[front]);
        front = rear = -1;
    }
    else{
        printf("Dequeued %d\n",arr[front]);
        front++;
    }

}
void display(){
    if(front==-1){
        printf("Empty\n");
    }
    else{
        for (int i=front;i<=rear;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(21);
    enqueue(22);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    enqueue(33);
    enqueue(21);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
