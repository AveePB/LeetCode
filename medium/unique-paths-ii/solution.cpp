// https://leetcode.com/problems/unique-paths-ii/description/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // Initialize dp array
        int n = grid.size(), m = grid.at(0).size();
        unsigned int* dp = (unsigned int*) malloc(m * sizeof(unsigned int));
        
        for (int i=0; i<m; i++) dp[i] = 0;
        dp[m-1] = 1;

        // Analyze paths
        for (int r=n-1; r>=0; r--) {
            for (int c=m-1; c>=0; c--) {
                // Detected obstacle
                if (grid.at(r).at(c)) 
                    dp[c] = 0;

                // Column isn't last
                else if (c != m-1)
                    dp[c] += dp[c+1];
            }
        }

        // Clean memory
        int res = dp[0];
        free(dp);

        return res;
    }
};
