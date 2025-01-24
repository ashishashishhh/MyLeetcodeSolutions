class Solution {
public:
    bool check(int source, vector<vector<int>>& graph, vector<int>& visited, int dest) {
        if (source == dest) return true; // Base case: if source equals destination
        visited[source] = 1;            // Mark the current node as visited
        for (auto neighbor : graph[source]) {
            if (!visited[neighbor] && check(neighbor, graph, visited, dest))
                return true;
        }
        return false; // Path not found
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) { 
            // Constructing an undirected graph
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, 0); // Visited array to track visited nodes
        return check(source, graph, visited, destination);
    }
};
