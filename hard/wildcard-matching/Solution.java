//https://leetcode.com/problems/wildcard-matching/
public class Solution {

    private char[] removeDuplicatedAsterisks(String p) {
        StringBuilder res = new StringBuilder();

        //Remove duplicates
        for (int i = 0; i < p.length(); i++) {
            //Skip if duplicated
            if ((i > 0) && (p.charAt(i-1) == '*' && p.charAt(i) == '*'))
                continue;

            res.append(p.charAt(i));
        }

        return res.toString().toCharArray();
    }

    public boolean isMatch(String s, String p) {
        char[] str = s.toCharArray(), pat = removeDuplicatedAsterisks(p);
        int n = str.length, m = pat.length;
        boolean[][] dp = new boolean[n+1][m+1];
        dp[0][0] = true;

        //Pattern starts with asterisk
        if ((m > 0) && pat[0] == '*')
            dp[0][1] = true;

        //Try to match strings
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //Chars are equal
                if (str[i-1] == pat[j-1] || pat[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                //Found asterisk
                if (pat[j-1] == '*')
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
}
