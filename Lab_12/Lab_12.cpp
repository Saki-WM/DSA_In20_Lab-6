#include <iostream>
#include <climits>

#define V 6 // Number of vertices

int minTime(int Time[], bool visited[]) {
    
    
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && Time[v] <= min) {
            min = Time[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int source) {
    int Time[V]; 
    bool visited[V]; 

    for (int i = 0; i < V; i++) {
        Time[i] = INT_MAX;
        visited[i] = false;
    }

    
    
    Time[source] = 0;

    // Find the shortest path for all cities
    for (int count = 0; count < V - 1; count++) {
        
        int u = minTime(Time, visited);

        // Mark the selected city as visited
        visited[u] = true;

        // Update Time of the adjacent cities of the selected city
        for (int v = 0; v < V; v++) {
            
            if (!visited[v] && graph[u][v] && Time[u] != INT_MAX &&
                Time[u] + graph[u][v] < Time[v]) {
                Time[v] = Time[u] + graph[u][v];
            }
        }
    }
    std::cout << "Shortest Time from source city " << source << ":\n";
    
    for (int i = 0; i < V; i++) {
        std::cout << "City " << i << ": " << Time[i] << "\n";
    }
    int totalTime = 0;
    int numCities = V - 1;
    
    for (int i = 0; i < V; i++) {
        
        if (i != source) {
            totalTime += Time[i];
        }
    }
    double averageTime = static_cast<double>(totalTime) / numCities;
    std::cout << "Average Time from source city " << source << ": " << averageTime << "\n";
    std::cout << "------------------------\n";
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    // Run Dijkstra's algorithm for each source city (0 to 5)
    for (int source = 0; source < V; source++) {
        dijkstra(graph, source);
    }
    return 0;
}