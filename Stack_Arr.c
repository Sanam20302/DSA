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
        printf("Underflow\n");
    }
    else{
        printf("Popped %d\n",arr[top]);
        top-=1;
    }
}
void peak(){
    printf("Top value is %d\n",arr[top]);
}
void display(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{
        for (int i=top;i>=0;i--){
            printf("%d ", arr[i]);
        }printf("\n");
    }
}

int main(){
    int elem,choice;
    while(1){
    printf("1. Push, 2. Pop, 3. Peak, 4. Display, 5. Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the value : ");
            scanf("%d",&elem);
            push(elem);
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting. . . \n");
            exit(0);
            break;
        default:
            printf("Invalid input\n");
    
    }
    }
    
    return 0;
}
