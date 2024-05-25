//https://leetcode.com/problems/longest-valid-parentheses/
public class Solution {

    public int longestValidParentheses(String s) {
        int n = s.length(), maxLen = 0, leftCount = 0, rightCount = 0;

        //Go from left
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(')
                leftCount++;
            else
                rightCount++;

            //Invalid parentheses
            if (rightCount > leftCount)
                leftCount = rightCount = 0;

            //Valid parentheses
            else if (leftCount == rightCount)
                maxLen = Math.max(maxLen, 2*rightCount);
        }

        //Reset variables
        leftCount = rightCount = 0;

        //Go from right
        for (int i = n-1; i >= 0; i--) {
            if (s.charAt(i) == '(')
                leftCount++;
            else
                rightCount++;

            //Invalid parentheses
            if (leftCount > rightCount)
                leftCount = rightCount = 0;

            //Valid parentheses
            else if (leftCount == rightCount)
                maxLen = Math.max(maxLen, 2*leftCount);
        }
        return maxLen;
    }
}