// https://leetcode.com/problems/distinct-subsequences/
void backtrack(char* s, char* t, int** dp, int idx, int jdx) {
    // Already solved
    if (dp[idx][jdx] != -1) return;
    dp[idx][jdx] = 0;

    // Success (New Answer)
    if (jdx == strlen(t)) {
        dp[idx][jdx] = 1;
        return;
    }
    
    // Failure (No Answer)
    if (idx == strlen(s)) {
        dp[idx][jdx] = 0;
        return;
    }

    //Characters match
    if (s[idx] == t[jdx]) {
        backtrack(s, t, dp, idx+1, jdx+1);
        dp[idx][jdx] += dp[idx+1][jdx+1];
    }

    // Go to next index
    backtrack(s, t, dp, idx+1, jdx);
    dp[idx][jdx] += dp[idx+1][jdx];
}

int numDistinct(char* s, char* t) {
    //Initialize
    int n = strlen(s) + 1, m = strlen(t) + 1;
    int** dp = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) dp[i][j] = -1;
    }
    
    // Solve
    backtrack(s, t, dp, 0, 0);
    int ans = dp[0][0];

    // Clean up
    for(int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    
    return ans;
}
