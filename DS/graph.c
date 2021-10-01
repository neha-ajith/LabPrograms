#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

struct adjlistnode{
    int dest;
    struct adjlistnode* next;
};

struct adjlist{
    struct adjlistnode* head;
};

struct Graph{
    int v;
    struct adjlist* array;
    int* visited;
};

struct queue{
    int items[SIZE];
    int front,rear;
};

struct queue* createqueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    return q;
}

void enqueue(struct queue* q,int key){
    if(q->rear == SIZE -1)
        printf("Queue is full.");
    else{
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = key;
    }
}

int isEmpty(struct queue* q){
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void printqueue(struct queue* q){
    int i;
    if(isEmpty(q))
        printf("Queue is empty.");
    else{
        printf("\nQueue contains:\n");
        for(i=q->front;i<=q->rear;i++){
            printf("%d ",q->items[i]);
        }
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty.");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front>q->rear){
            printf("Resetting queue...");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void bfs(struct Graph* graph,int vertex){
    struct queue* q = createqueue();
    graph->visited[vertex] = 1;
    enqueue(q,vertex);

    while(!isEmpty(q)){
        printqueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d",currentVertex);

        struct adjlistnode* temp = graph->array[currentVertex].head;

        while(temp){
            int adjvertex = temp->dest;
            if(graph->visited[adjvertex] == 0){
                graph->visited[adjvertex] = 1;
                enqueue(q,adjvertex);
            }
            temp = temp->next;
        }
    }
}

void dfs(struct Graph* graph,int vertex){
    struct adjlistnode* temp = graph->array[vertex].head;
    graph->visited[vertex] = 1;
    printf("Visited %d\n",vertex);
    while(temp){
        int connectedVertex = temp->dest;
        if(graph->visited[connectedVertex] == 0)
            dfs(graph,connectedVertex);
        temp = temp->next;
    }
}

struct Graph* newgraph(int v){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->array = (struct adjlist*)malloc(sizeof(v*sizeof(struct adjlist)));
    graph->visited = (int*)malloc(v*sizeof(int));

    int i;
    for(i = 0;i < v;i++){
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

struct adjlistnode* createnode(int dest){
    struct adjlistnode* newnode = (struct adjlistnode*)malloc(sizeof(struct adjlistnode));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
}

void addEdge(struct Graph* graph,int src,int dest){
    struct adjlistnode* newnode = createnode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
    newnode = createnode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
}

void printgraph(struct Graph* graph){
    int i;
    for(i = 0;i<graph->v;i++){
        struct adjlistnode* trav = graph->array[i].head;
        printf("Adjacency list for vertex %d:\n head",i);
        while(trav){
            printf(" -> %d",trav->dest);
            trav = trav->next;
        }
        printf("\n");
    }
}

void main(){
    int v  = 5,ch,rep;
    do{
        struct Graph* graph = newgraph(v);
        addEdge(graph,0,1);
        addEdge(graph,0,4);
        addEdge(graph,1,2);
        addEdge(graph,1,3);
        addEdge(graph,1,4);
        addEdge(graph,2,3);
        addEdge(graph,3,4);
        printf("--- Graph Traversal Operations ---\n1. BFS\n2. DFS\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                bfs(graph,0);
                break;
            case 2: 
                dfs(graph,2);
                break;
            default: 
                printf("Invalid input!!");
                break;
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no): ");
        scanf("%d",&rep);
    }while(rep==1);
}