//https://leetcode.com/problems/trapping-rain-water/description/
public class Solution {

    public int trap(int[] height) {
        //Initialize parameter
        int n = height.length;

        //DP: find max height from left
        int[] maxHeightL = new int[n];
        maxHeightL[0] = height[0];

        for (int i = 1; i < n; i++)
            maxHeightL[i] = Math.max(maxHeightL[i-1], height[i]);

        //Compute amount of trapped water
        int maxHeightR = height[n-1], trappedWater = 0;

        for (int i = n-1; i >= 0; i--) {
            //Find max height from right
            maxHeightR = Math.max(maxHeightR, height[i]);

            int currHeight = Math.min(maxHeightL[i], maxHeightR);
            trappedWater += currHeight - height[i];
        }

        return trappedWater;
    }
}
