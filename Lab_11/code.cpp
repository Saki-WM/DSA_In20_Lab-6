#include <bits/stdc++.h>
using namespace std;
 
//vertices of the graph
#define V 6
 
int graph[V][V] = { {0, 3, 0, 0, 0, 1},
                  {3, 0, 2, 1, 10, 0},
                  {0, 2, 0, 3, 0, 5},
                  {0, 1, 3, 0, 5, 0},
                  {0, 10, 0, 5, 0, 4},
                  {1, 0, 5, 0, 4, 0} };
                  

int minimum(int key[], bool mst[]){
    
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++){
        
        if (mst[v] != true && key[v] < min)
            min = key[v], min_index = v;
    }
    
    return min_index;
}

void print_mst(int node[], int graph[V][V]){
    cout << "Edge \tWeight\n";
    
    for (int i = 1; i < V; i++){
        cout <<"["<< node[i] << " - " << i << "]"<<" \t"<< graph[i][node[i]] << " \n";
    }
}
 

void prim_mst(int graph[V][V]){
    
    int node[V],key[V];
    bool mst[V];
 
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX, mst[i] = false;
        
    }
 
    key[0] = 0;
    node[0] = -1;
    
    for (int count = 0; count <= V - 2; count++) {
        
        int u = minimum(key, mst);
        mst[u] = true;
        
        for (int v = 0; v < V; v++){
            
            if (graph[u][v] && mst[v] != true && graph[u][v] < key[v]){
                node[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    print_mst(node, graph);
}


int main(){
    prim_mst(graph);
    return 0;
}