Given a m x n grid filled with non-negative numbers, find a path from top left to
 bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


//1st solution: space- O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                   dp[i][j]= grid[i][j];
                }
                else if(i==0){
                    dp[i][j]= grid[i][j]+dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j]= grid[i][j]+dp[i-1][j];
                }
                else{
                    dp[i][j]= grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};


//2nd solution: space- O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<int> dp(n,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                   dp[j]= grid[i][j];
                }
                else if(i==0){
                    dp[j]= grid[i][j]+dp[j-1];
                }
                else if(j==0){
                    dp[j]= grid[i][j]+dp[j];
                }
                else{
                    dp[j]= grid[i][j]+min(dp[j], dp[j-1]);
                }
            }
        }
        return dp[n-1];
    }
};


//3rd solution

Here's the full C++ solution to the “Minimum Cost Path in Grid with Obstacles + Path Reconstruction” problem.
This version: Calculates the minimum cost from (0,0) to (m-1,n-1)
Skips over -1 cells (which are blocked)
Reconstructs the path as a string using 'D' and 'R'
Returns -1 and empty string if no path exists



class Solution {
public:
    pair<int, string> minPathWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<char>> dir(m, vector<char>(n, ' ')); // Direction tracker

        // Base case
        if (grid[0][0] == -1) return {-1, ""};
        dp[0][0] = grid[0][0];

        // Fill first row
        for (int j = 1; j < n; ++j) {
            if (grid[0][j] == -1 || dp[0][j-1] == INT_MAX) break;
            dp[0][j] = dp[0][j-1] + grid[0][j];
            dir[0][j] = 'R';
        }

        // Fill first column
        for (int i = 1; i < m; ++i) {
            if (grid[i][0] == -1 || dp[i-1][0] == INT_MAX) break;
            dp[i][0] = dp[i-1][0] + grid[i][0];
            dir[i][0] = 'D';
        }

        // Fill rest of dp + direction
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == -1) continue;

                if (dp[i-1][j] != INT_MAX && dp[i-1][j] + grid[i][j] < dp[i][j]) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                    dir[i][j] = 'D';
                }
                if (dp[i][j-1] != INT_MAX && dp[i][j-1] + grid[i][j] < dp[i][j]) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    dir[i][j] = 'R';
                }
            }
        }

        // No path
        if (dp[m-1][n-1] == INT_MAX) return {-1, ""};

        // Reconstruct path
        string path;
        int i = m - 1, j = n - 1;
        while (i != 0 || j != 0) {
            char d = dir[i][j];
            path += d;
            if (d == 'D') --i;
            else if (d == 'R') --j;
        }
        reverse(path.begin(), path.end());

        return {dp[m-1][n-1], path};
    }
};
