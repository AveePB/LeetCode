// https://leetcode.com/problems/longest-palindromic-substring/
int len(int l, int r) { return (r-l) + 1; }

int extendPalindrome(char* str, int l, int r) {
    int n = strlen(str), depth = 0; 
    
    while (true) {
        if ((l - depth) == -1 || (r + depth) == n) break;
        if (str[l - depth] != str[r + depth]) break;
        depth++;
    }

    return depth - 1;
}

char* longestPalindrome(char* str) {
    int n = strlen(str), bestL = 0, bestR = -1;

    for (int ptr = 0; ptr < n; ptr++) {
        // Odd Palindrome check
        int oddDepth = extendPalindrome(str, ptr, ptr);
        int oddLen = len((ptr - oddDepth), (ptr + oddDepth));

        if (oddLen > len(bestL, bestR)) {
            bestL = (ptr - oddDepth);
            bestR = (ptr + oddDepth);
        }

        // Even Palindrome check
        int evenDepth = extendPalindrome(str, ptr, ptr+1);
        int evenLen = len((ptr - evenDepth), (ptr+1 + evenDepth));
        
        if (evenLen > len(bestL, bestR)) {
            bestL = (ptr - evenDepth);
            bestR = (ptr+1 + evenDepth);
        }
    }

    // Save selected part
    char* pal = (char*) malloc((bestR-bestL+2)* sizeof(char));
    for (int i = bestL; i <= bestR; i++) pal[i-bestL] = str[i];
    pal[bestR-bestL+1] = '\0';
    
    return pal;
}
