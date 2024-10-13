// https://leetcode.com/problems/unique-paths/
int** initDp(int n_rows, int n_cols) {
    // Create array
    int** arr = (int**) malloc(n_rows * sizeof(int*));
    for (int i=0; i<n_rows; i++)
        arr[i] = (int*) malloc(n_cols * sizeof(int));
    
    // Set initial values
    for (int i=0; i<n_rows; i++) arr[i][n_cols-1] = 1;
    for (int i=0; i<n_cols; i++) arr[n_rows-1][i] = 1;

    arr[n_rows-1][n_cols-1] = 0;
    return arr;
}


int uniquePaths(int n_rows, int n_cols) {
    int** dp = initDp(n_rows, n_cols);

    // Safety check
    if (n_rows == 1 || n_cols == 1)
        return 1;

    // Find number of paths
    for (int r=n_rows-2; r>=0; r--) {
        for (int c=n_cols-2; c>=0; c--) {
            dp[r][c] = dp[r+1][c] + dp[r][c+1]; 
        }
    }
    int nPaths = dp[0][0];

    // Free space
    for (int i=0; i<n_rows; i++)
        free(dp[i]);
    free(dp);

    return nPaths;
}
