/*
Problem:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

*/

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 0 || n == 0)
            return 0;
          
        vector<vector<int>> Dijkstra;
        
        Dijkstra.resize(m);
        
        for(int i = 0; i < m; i++)
            Dijkstra[i].resize(n);
        
        
        //vector<vector<int>> Dijkstra(m, vector<int>(n, 0));
        
        Dijkstra[0][0] = grid[0][0];
        
        for(int i = 1; i < m; i++)
            Dijkstra[i][0] = grid[i][0] + Dijkstra[i-1][0];
        for(int i = 1; i < n; i++)
            Dijkstra[0][i] = grid[0][i] + Dijkstra[0][i-1];
            
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                Dijkstra[i][j] = min(Dijkstra[i-1][j], Dijkstra[i][j-1]) + grid[i][j];
            }
        }     
        
        return Dijkstra[m-1][n-1];
        
        
    }
};