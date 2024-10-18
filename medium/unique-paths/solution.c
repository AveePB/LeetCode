// https://leetcode.com/problems/unique-paths/
int uniquePaths(int n_rows, int n_cols) {
    // Initialize dp array
    int* dp = (int*) malloc(n_cols * sizeof(int));
    for (int i=0; i<n_cols; i++) dp[i] = 1;

    // Analyze paths
    for (int r=n_rows-2; r>=0; r--) {
        for (int c=n_cols-1; c>=0; c--) {
            // Edge detected
            if (c+1 == n_cols)
                continue;

            dp[c] += dp[c+1];
        }
    }
    int nPaths = dp[0];

    // Free space
    free(dp);

    return nPaths;
}
