//https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {

    public double findMedianSortedArrays(int[] arr1, int[] arr2) {
        //Initialize variables
        int num1 = 0, num2 = 0, ptr1 = 0, ptr2 = 0,
                n = arr1.length, m = arr2.length;

        //Find middle
        while ((ptr1 + ptr2) <= (n + m) / 2) {
            //Shift last two numbers
            num1 = num2;

            //Stop increasing ptr1
            if (ptr1 >= n) {
                num2 = arr2[ptr2++];

                continue;
            }

            //Stop increasing ptr2
            if (ptr2 >= m) {
                num2 = arr1[ptr1++];

                continue;
            }

            //Increase ptr1
            if (arr1[ptr1] <= arr2[ptr2])
                num2 = arr1[ptr1++];

            //Increase ptr2
            else
                num2 = arr2[ptr2++];
        }

        //Compute median
        if ((n + m) % 2 == 0)
           return (double) (num1 + num2) / 2;
        return num2;
    }
}