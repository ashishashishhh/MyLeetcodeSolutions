class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && server(grid,i,j))
                    res++;
            }
        }
        return res;
    }
   bool server(vector<vector<int>>& grid , int r,int c){ // to check if there's a 1 in same row and col
           
       for(int i = 0;i < grid.size() ;i++){
           if(i!=r && grid[i][c]==1)
               return true;
       }
            
       for(int i = 0;i < grid[0].size() ;i++){
           if(i!=c && grid[r][i]==1)
               return true;
       }
       return false;
      
     }
};