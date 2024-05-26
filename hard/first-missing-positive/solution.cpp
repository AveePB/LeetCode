//https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Initialize variables
        int n = nums.size();
        bool isVis[n];
        for (int i = 0; i < n; i++) isVis[i] = false;
        
        //Mark seen numbers
        for (int i = 0; i < n; i++) {
            //Number out of bounds
            if (nums.at(i) < 1) continue;
            if (nums.at(i) > n) continue;

            isVis[nums.at(i) - 1] = true;
        }

        //Find first missing positive
        for (int num = 0; num < n; num++) {
            //Number is marked
            if (isVis[num]) continue;

            //Number is missing
            return num + 1;
        }

        return n + 1;
    }
};