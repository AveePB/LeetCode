//https://leetcode.com/problems/first-missing-positive/description/
public class Solution {

    public int firstMissingPositive(int[] arr) {
        //Initialize parameters
        int lowerBound = 0, upperBound = arr.length + 1;
        boolean[] isPresent = new boolean[upperBound];

        //Mark positive integers
        for (int num: arr) {
            if (num <= lowerBound || num >= upperBound) continue;

            isPresent[num] = true;
        }

        //Look for answer
        for (int i = 1; i < upperBound; i++) {
            if (isPresent[i]) continue;

            return i;
        }

        return upperBound;
    }
}
