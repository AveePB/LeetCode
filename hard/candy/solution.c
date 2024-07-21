//https://leetcode.com/problems/candy/

// Function that return the greater number
int max(int a, int b) { return (a > b) ? a : b; }

// Function that finds the min. number of req. candies
int candy(int* arr, int n) {
    int* dpL = (int*) malloc(n * sizeof(int));
    int* dpR = (int*) malloc(n * sizeof(int));
    int ans = 0;

    // Boundary Check
    if (n == 1) return 1;

    // Analyze edges
    dpL[0] = dpR[n-1] = 1;
    if (arr[0] > arr[1]) dpL[0]++;
    if (arr[n-1] > arr[n-2]) dpR[n-1]++;

    // Distribute candies from left
    for (int i = 1; i < n; i++) {
        if (arr[i-1] < arr[i])
            dpL[i] = dpL[i-1] + 1;
        else
            dpL[i] = 1;
    }
    
    // Distribute candies from right
    for (int i = n-2; i >= 0; i--) {
        if (arr[i+1] < arr[i])
            dpR[i] = dpR[i+1] + 1;
        else
            dpR[i] = 1;
    }
    
    // Find min. number of req. candies
    for (int i = 0; i < n; i++) 
        ans += max(dpL[i], dpR[i]);

    //Memo Clean-Up
    free(dpL);
    free(dpR);

    return ans;
}
