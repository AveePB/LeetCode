//https://leetcode.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays(int* arr, int len, int* arr2, int len2) {
    int first = 0, sec = 0, ptr = 0, ptr2 = 0;

    //Go to middle
    while ((ptr + ptr2) <= (len + len2) / 2) {
        //Shift nums
        first = sec;
    
        //Stop incrementing ptr
        if (ptr >= len) {
            sec = *(arr2 + ptr2++);
            continue;
        }

        //Stop incrementing ptr2
        if (ptr2 >= len2) {
            sec = *(arr + ptr++);
            continue;
        }

        //Take lesser value
        if (*(arr + ptr) < *(arr2 + ptr2)) 
            sec = *(arr + ptr++);
        else 
            sec = *(arr2 + ptr2++);
    }
    
    //Size of arrays is odd
    if ((len + len2) % 2 == 1)
        return (double) sec;
    
    //Size of arrays is even
    return (double)(first + sec) / 2;
}
