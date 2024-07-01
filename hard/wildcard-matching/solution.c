//https://leetcode.com/problems/wildcard-matching/
void reduceAsterisks(char* str) {
    int len = strlen(str), ptr = 0;

    for (int i = 0; i < len; i++) {
        if (i > 0 && str[i] == '*' && str[i] == str[i-1])
            continue;
        str[ptr++] = str[i];
    }

    // Set Null-terminator
    str[ptr] = '\0';
}

bool isMatch(char* s, char* p) {
    reduceAsterisks(p);

    int n = strlen(s), m = strlen(p);
    bool dp[n+1][m+1];

    //Initialize dp array
    for (int i = 0; i <= n; i++) dp[i][0] = false;
    for (int j = 0; j <= m; j++) dp[0][j] = false;
    dp[0][0] = true;

    //Additional initialization
    if (m > 0 && p[0] == '*')
        dp[0][1] = true;

    //Compare chars
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Initialize cell
            dp[i][j] = false;

            if (s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            
            if (p[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];            
        }
    }

    return dp[n][m];
}
