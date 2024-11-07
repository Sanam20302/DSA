#include<stdio.h>
#include<stdlib.h>

#define MAX 20
int vertex,graph[MAX][MAX],visited[MAX],queue[MAX];
int front =-1,rear=-1;

void display(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void enqueue(int elem){
    if(rear==MAX-1){
        return;
    }
    for(int i=front;i<=rear;i++){
        if(queue[i]==elem){
            return;
        }
    }
    if(rear==-1){
        front++;
    }
    queue[++rear]=elem;
}

int dequeue(){
    int temp = queue[front++];
    if(front>rear){
        front=rear=-1;
    }
    return temp;
}

void bfs(){
    int elem=0;
    while(elem<vertex){
        printf("%d ",elem);
        visited[elem]=1;
        for(int j=0;j<vertex;j++){
            if(visited[j]==0 && graph[elem][j]==1){
                enqueue(j);
            }
        }
        if(front==-1 || front>rear){
            break;
        }
        elem = dequeue();
    }
    printf("\n");
}

void main(){
    printf("Enter the number of vertex : ");
    scanf("%d",&vertex);
    int choice,from,to,elem;
    while(1){
        printf("1.Add edge\n2.BFS\n3.Display matrix\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("From : ");
            scanf("%d",&from);
            printf("To : ");
            scanf("%d",&to);
            graph[from][to]=1;
            graph[to][from]=1;
            break;
        case 2:
            printf("BFS sequence : ");
            for(int i=0;i<vertex;i++){
                visited[i]=0;
            }
            bfs();
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
