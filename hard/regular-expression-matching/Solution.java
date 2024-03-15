//https://leetcode.com/problems/regular-expression-matching/description/
public class Solution {

    private Boolean[][] dp;
    private char[] s, p;

    private boolean areCharsMatching(int ptrS, int ptrP) {
        //Match chars
        return (this.s[ptrS] == this.p[ptrP] || this.p[ptrP] == '.');
    }

    private boolean areStringsMatching(int ptrS, int ptrP) {
        //Strings match
        if (ptrS == -1 && ptrP == -1) return true;

        //Strings don't match
        if (ptrP == -1) return false;

        //Already solved
        if ((ptrS > -1) && this.dp[ptrS][ptrP] != null)
            return this.dp[ptrS][ptrP];

        //Chars match
        if ((ptrS > -1) && areCharsMatching(ptrS, ptrP))
            return this.dp[ptrS][ptrP] = areStringsMatching(ptrS - 1, ptrP - 1);

        //Astrid appears
        if (this.p[ptrP] == '*') {
            //Don't use astrid
            if (areStringsMatching(ptrS, ptrP - 2)) return true;

            //Preceding element matches
            if ((ptrS > -1) && areCharsMatching(ptrS, ptrP - 1)) {
                //Stretch astrid range
                if (areStringsMatching(ptrS - 1, ptrP))
                    return this.dp[ptrS][ptrP] = true;

                //Don't use astrid anymore
                if (areStringsMatching(ptrS - 1, ptrP - 2))
                    return this.dp[ptrS][ptrP] = true;
            }
        }

        //Try to save result
        if ((ptrS > -1))
            return this.dp[ptrS][ptrP] = false;

        return false;
    }

    public boolean isMatch(String s, String p) {
        //Initialize required structures
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        this.dp = new Boolean[this.s.length][this.p.length];

        return areStringsMatching(this.s.length - 1, this.p.length - 1);
    }
}