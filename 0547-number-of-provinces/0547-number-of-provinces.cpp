class Solution {
public:
    // Convert adjacency matrix to adjacency list
    vector<vector<int>> matrixToAdjacencyList(int V, const vector<vector<int>>& adjMatrix) {
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If there is an edge (i.e., 1 in the matrix), add it to the adjacency list
                if (adjMatrix[i][j] == 1 && i!=j) {
                    adjList[i].push_back(j);
                }
            }
        }
        return adjList;
    }

    void dfs(int src, unordered_map<int, bool>& visited, vector<vector<int>>& adjList) {
        visited[src] = true;

        for (auto& nbr : adjList[src]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, bool> visited;
        int count = 0;

        vector<vector<int>> adjList = matrixToAdjacencyList(n, isConnected);

        // Perform DFS to find the number of connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adjList);  
                count++;
            }
        }

        return count;
    }
};