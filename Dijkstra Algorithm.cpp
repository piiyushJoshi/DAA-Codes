#include <iostream>
#include <limits.h>
#define V 9

using namespace std;

int minDist(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSoln(int dist[]){
    cout<<"Vertex \t\t Distance from source "<<endl;
    for(int i=0;i<V;i++){
        cout<<i<< "\t\t " <<dist[i]<<endl;
    }
}

void dijkstra_algo(int graph[V][V], int src){
    
	int dist[V];
	bool sptSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++){
		int u = minDist(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSoln(dist);
}

int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 9, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 18, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 5, 0, 0, 0 },
                        { 0, 0, 4, 18, 5, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 9, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
                        
    dijkstra_algo(graph, 0);
    
    return 0;
}
