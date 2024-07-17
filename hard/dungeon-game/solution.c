// https://leetcode.com/problems/dungeon-game/

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int** init2DArr(int n, int m, int val) {
    int** arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*) malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) arr[i][j] = val;
    }
    return arr;
}

void free2DArr(int** arr, int n) {
    for (int i = 0; i < n; i++) 
        free(arr[i]);
    free(arr);
}

int backtrack(int** dp, int** dungeon, int nRows, int nCols, int r, int c) {
    // Boundary Guard
    if (r == nRows || c == nCols) return 1000000000;
    
    // Dead End
    if (r == nRows-1 && c == nCols-1) 
        return max(1 - dungeon[r][c], 1);

    // Already Solved
    if (dp[r][c] != -1) return dp[r][c];

    // Calculate answer
    int ans = min(
        backtrack(dp, dungeon, nRows, nCols, r+1, c), // Right
        backtrack(dp, dungeon, nRows, nCols, r, c+1)  // Bottom
    ) - dungeon[r][c];

    return dp[r][c] = max(ans, 1);
}

int calculateMinimumHP(int** dungeon, int nRows, int* nCols) {
    int** dp = init2DArr(nRows, *nCols, -1);
    int minHP = backtrack(dp, dungeon, nRows, *nCols, 0, 0);   
    free2DArr(dp, nRows);
    
    return minHP;
}
