#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define V 5

bool chkedge(int u, int v, vector<bool> MST){
    if (u == v)
    	return false;
    if (MST[u] == false && MST[v] == false)
    		return false;
    else if (MST[u] == true && MST[v] == true)
    		return false;
    return true;
}

void algo(int cost[][V]){
	vector<bool> MST(V, false);
	MST[0] = true;
	int edge_count = 0, mincost = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i=0;i<V;i++)
			for (int j=0;j<V;j++)		
				if (cost[i][j] < min)
					if (chkedge(i, j, MST)) {
						min = cost[i][j];
						a = i;
						b = j;
					}
		if (a != -1 && b != -1){
			printf("Edge %d:(%d, %d) cost: %d \n",edge_count++, a, b,min);
			mincost = mincost + min;
			MST[b] = MST[a] = true;
		}
	}
	cout<<"\n Minimum cost will be: "<< mincost;
}

int main(){
	int cost[][V] = {
		{ INT_MAX, 3, INT_MAX, 5, INT_MAX },
		{ 4, INT_MAX, 6, 1, 7},
		{ INT_MAX, 8, INT_MAX, INT_MAX, 2 },
		{ 6, 8, INT_MAX, INT_MAX, 4 },
		{ INT_MAX, 5, 3, 7, INT_MAX }
	};
	algo(cost);
	return 0;
}
