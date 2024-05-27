#https://leetcode.com/problems/longest-valid-parentheses/
class Solution:

    def longestValidParentheses(self, s: str) -> int:
        #Initialize variables
        lCount, rCount, maxLen = 0, 0, 0
        
        #Go from left
        for i in range(len(s)):
            if (s[i] == '('): 
                lCount += 1
            else:
                rCount += 1
            
            #Valid parentheses
            if (lCount == rCount):
                maxLen = max(maxLen, 2*lCount)
            
            #Impossible parentheses
            elif (rCount > lCount):
                lCount, rCount = 0, 0

        #Reset counters
        lCount, rCount = 0, 0

        #Go from right
        for i in range(len(s), 0, -1):
            if (s[i-1] == '('):
                lCount += 1
            else:
                rCount += 1
            
            #Valid parentheses
            if (lCount == rCount):
                maxLen = max(maxLen, 2*rCount)
            
            #Impossible parentheses
            elif (lCount > rCount):
                lCount, rCount = 0, 0

        return maxLen
