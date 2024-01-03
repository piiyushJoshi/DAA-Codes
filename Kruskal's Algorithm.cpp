#include <bits/stdc++.h>
using namespace std;

class DSU{
    int *parent;
    int *rank;
    public:
	DSU(int n){
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}
    int find(int i){
        if(parent[i] == -1)
            return i;
        
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y){
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2){
			if (rank[s1] < rank[s2])
				parent[s1] = s2;
			else if (rank[s1] > rank[s2])
				parent[s2] = s1;
			else{
				parent[s2] = s1;
				rank[s1] += 1;
			}
		}
	}
};

class Graph{
    vector<vector<int>> edgelist;
    int v;
    public:
    Graph(int v){
        this->v = v;
    }
    void addedge(int a, int b, int c){
        edgelist.push_back({c,a,b});
    }
    void kruskal_algo(){
        sort(edgelist.begin(), edgelist.end());
        DSU s(v);
        int ans = 0;
        cout << "Following will be the edges in the MST"<< endl;
        for(auto edge : edgelist){
            int c = edge[0];
            int a = edge[1];
            int b = edge[2];
            
            if(s.find(a) != s.find(b)){
                s.unite(a,b);
                ans += c;
                cout << a << " -- " << b << " == " << c << endl;
            }
        }
        cout << "Minimum Cost of Spanning Tree will be: " << ans;
    }
};

int main(){
    Graph g(4);
    g.addedge(0,1,9);
    g.addedge(1,3,11);
    g.addedge(2,3,4);
    g.addedge(2,0,5);
    g.addedge(0,3,2);
    g.kruskal_algo();
    
    return 0;
}
