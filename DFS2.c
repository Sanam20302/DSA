#include<stdio.h>
#include<stdlib.h>

#define MAX 20
int vertex,graph[MAX][MAX],visited[MAX];


void display(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void dfs(int elem){
    printf("%d ",elem);
    visited[elem]=1;
    for(int j=0;j<vertex;j++){
        if(visited[j]==0 && graph[elem][j]==1){
            dfs(j);
        }
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
            for(int i=0;i>vertex;i++){
                visited[i]=0;
            }
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
