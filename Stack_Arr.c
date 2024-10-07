#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max],top = -1;
void push(int data){
    if(top==max-1){
        printf("Overflow\n");
    }else{
        arr[++top]=data;
        
    }
}
void pop(){
    if(top==-1){
        printf("Empty\n");
    }
    else{
        printf("Dequeued %d\n",arr[top]);
        top-=1;
    }
}
void peak(){
    printf("Top value is %d",arr[top]);
}
void display(){
    if(top==-1){
        printf("Empty\n");
    }
    else{
        for (int i=0;i<=top;i++){
            printf("%d ", arr[i]);
        }
    }
}

int main(){
    push(10);
    push(20);
    pop();
    pop();
    pop();
    push(22);
    push(21);
    display();
    return 0;
}
