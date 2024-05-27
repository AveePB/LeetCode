#https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution:

    def findMedianSortedArrays(self, arr1: list[int], arr2: list[int]) -> float:
        #Initialize parameters
        n, m, ptr1, ptr2 = len(arr1), len(arr2), 0, 0
        firstNum, secNum = 0, 0

        #Safety check
        if (n + m == 0): return 0

        #Find middle
        while ((ptr1+ptr2) <= (n + m)/2):
            #Shift numbers
            firstNum = secNum

            #ptr1 is out of bounds
            if (ptr1 >= n):
                secNum = arr2[ptr2]
                ptr2 += 1
                continue

            #ptr2 is out of bounds
            if (ptr2 >= m):
                secNum = arr1[ptr1]
                ptr1 += 1
                continue

            #Move pointers
            if (arr1[ptr1] <= arr2[ptr2]):
                secNum = arr1[ptr1]
                ptr1 += 1
            else:
                secNum = arr2[ptr2]
                ptr2 += 1

        #Amount of numbers is odd
        if ((n + m) % 2 == 1):
            return secNum

        #Amount of numbers is even
        else:
            return (firstNum + secNum) / 2

