#include<stdio.h>
#include<stdlib.h>
struct Graph
{
	int V;
	int** adjMat;
};
struct Graph* createGraph(int V)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->V=V;
	graph->adjMat=(int**)malloc(V*sizeof(int*));
	for(int i=0;i<V;i++)
	{
		graph->adjMat[i]=(int*)malloc(V*sizeof(int));
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			graph->adjMat[i][j]=0;
		}
	}
	return graph;
}
void addEdge(struct Graph* graph,int src,int dest)
{
	graph->adjMat[src][dest]=1;
	graph->adjMat[dest][src]=1;
	return;
}
void printGraph(struct Graph* graph)
{
	for(int i=0;i<graph->V;i++)
	{
		printf("For Vertex %d The connected vertices are \n",i);
		for(int j=0;j<graph->V;j++)
		{
			if(graph->adjMat[i][j]==1)
				printf("%d ",j);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
int main()
{
	int V;
	printf("Please enter the number of Vertices you want the graph to have\n");
	scanf("%d",&V);
	//printf("%d",V);
	struct Graph* graph=createGraph(V);
	int n;
	printf("Please enter the number of edges your graph has\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int src,dst;
		scanf("%d %d",&src,&dst);
		addEdge(graph,src,dst);
	}
	printGraph(graph);
	return 0;
}