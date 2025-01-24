class Solution {
public:
    bool check(int source , vector<vector<int>>&graph,vector<int>&boo,int dest){
        if(source == dest)
        return true;
        boo[source] = 1;
        for(auto x:graph[source]){
            if(!boo[x] && check(x,graph,boo,dest))
            return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            int start = edges[i][0];
            int end = edges[i][1];
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
        vector<int>boo(n,0);
        return check(source,graph,boo,destination);
    }
};
