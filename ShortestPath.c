#include<stdio.h>
#include<stdlib.h>

static int max = 10000;
int node;
int counter = 0;

void printweight(int arr[][node]){
	for(int i=0;i<node;i++){
    	for(int j=0;j<node;j++){
        	printf("%d ",arr[i][j]);
    	}
    	printf("\n");
	}
}

void initialiseSingleSource(int source, int dist[], int parent[]){
	for(int i=0;i<node;i++){
    	dist[i] = max;
    	parent[i] = -1;
	}

	dist[source] = 0;
}

int extractMin(int queue[], int dist[]){
	int x=0;
	while(queue[x]==-1 && x<node)
    	x++;

	int min=dist[x];
	int i=x;
	for(i;i<node;i++){
    	if(min>dist[i] && queue[i]!=-1){
        	min=dist[i];
        	x=i;
    	}
	}
	queue[x]=-1;
	return x;
}

void relax(int dist[], int weight[][node], int parent[], int u, int v){
	if(dist[v]>dist[u] + weight[u][v]){
    	dist[v]= dist[u] + weight[u][v];
    	parent[v]=u;
	}
}

int emptyQueue(int q[]){
	for(int i=0;i<node;i++){
    	if(q[i]!=-1)
        	return 1;
	}
	return 0;
}

void djkstras(int weight[][node], int source, int dist[], int parent[], int s[]){
	initialiseSingleSource(source,dist,parent);

	int u;
	int queue[node];
	for(int i=0;i<node;i++)
    	queue[i]=i;

	while(emptyQueue(queue)){
	u =extractMin(queue,dist);
	s[counter] = u;
	counter++;

	for(int k = 0 ;k<node;k++){
    	relax(dist,weight,parent,u,k);
    	}
	}
}

void printpath(int p[], int source, int dest){
	if(source==dest){
    	printf("%d ",source);
	}else if(p[dest]==-1){
    	printf("No path available");
	}else {
    	printpath(p,source,p[dest]);
    	printf("%d ",dest);
	}
}

void main(){
	int start,end, pair, w, source, dest;

	printf("enter number of nodes:");
	scanf("%d",&node);

	int weight[node][node];
	for(int i=0;i<node;i++)
    	for(int j=0;j<node;j++){
        	if(i==j)
            	weight[i][j]=0;
        	else weight[i][j]=max;
    	}


	printf("Enter number of pairs to entered: ");
	scanf("%d",&pair);

	for(int i=0;i<pair;i++){
    	printf("Enter start of pair %d: ",i);
    	scanf("%d",&start);
    	printf("Enter end of pair %d: ",i);
    	scanf("%d",&end);
    	printf("Enter weight: ");
    	scanf("%d",&w);
    	printf("\n");

    	weight[start][end] =w;
	}

	printf("\nEnter starting node: ");
	scanf("%d",&source);

	printf("Enter destination node: ");
	scanf("%d",&dest);

	int dist[node];
	int parent[node];
	int s[node];
	for(int i=0;i<node;i++)
    	s[i]=-1;

	//printweight(weight);

	djkstras(weight,source,dist,parent,s);

	printf("\n");
	printf("Path: ");
	printpath(parent,source,dest);

}
