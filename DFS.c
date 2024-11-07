#include<stdio.h>
#include<stdlib.h>

#define MAX 20
int vertex,graph[MAX][MAX],stack[MAX],visited[MAX];
int top=-1;

void push(int elem){
    if(top>=MAX){
        return;
    }
    for(int i=top;i>=0;i--){
        if(stack[i]==elem) return;
    }
    stack[++top]=elem;
}

int pop(){
    if(top>-1){
        return stack[top--];
    }
}

void display(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void dfs(int elem){
    for(int i=0;i>vertex;i++){
        visited[i]=0;
    }
    while(elem<vertex){
        printf("%d ",elem);
        visited[elem]=1;
        for(int j=vertex-1;j>=0;j--){
            if(visited[j]==0 && graph[elem][j]==1){
                push(j);
            }
        }
        if(top==-1) break;
        elem=pop();
    }
}

void main(){
    printf("Enter the number of vertex : ");
    scanf("%d",&vertex);
    int choice,from,to,elem;
    while(1){
        printf("1.Add edge\n2.DFS\n3.Display matrix\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("From : ");
            scanf("%d",&from);
            printf("To : ");
            scanf("%d",&to);
            graph[from][to]=1;
            break;
        case 2:
            printf("From which vertex : ");
            scanf("%d",&elem);
            dfs(elem);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting..\n");
            exit(0);
        default:
            printf("Invalid entry");
            break;
        }
    }
}
