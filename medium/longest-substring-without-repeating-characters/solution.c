// https://leetcode.com/problems/longest-substring-without-repeating-characters

void setFalse(bool* b, int n) {
    for (int i = 0; i < n; i++) 
        b[i] = false;
}

int lengthOfLongestSubstring(char* s) {
    bool* marked = (bool*) malloc(128 * sizeof(bool));
    int n = strlen(s), ans = 0;

    for (int i = 0; i < n; i++) {
        setFalse(marked, 128);

        for (int j = i; j < n; j++) {
            if (marked[s[j]]) break;
            marked[s[j]] = true;

            ans = (ans > (j - i) + 1) ? ans : (j - i) + 1;
        }
    }
    free(marked);

    return ans;
}
