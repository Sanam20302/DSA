#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max],front = -1, rear = -1;
void enqueue(int data){
    if(rear==max-1){
        printf("Overflow\n");
    }else{
        front=0;
        arr[++rear]=data;
    }
}
void dequeue(){
    if(front==-1||front>rear){
        printf("Empty\n");
    }
    else{
        printf("Dequeued %d\n",arr[front]);
        front+=1;
    }
    if (front > rear) 
        { 
            front = rear = -1;
        }

}
void display(){
    if(front==-1||front>rear){
        printf("Empty\n");
    }
    else{
        for (int i=front;i<=rear;i++){
            printf("%d ", arr[i]);
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    dequeue();
    dequeue();
    dequeue();
    enqueue(22);
    enqueue(21);
    display();
    return 0;
}
