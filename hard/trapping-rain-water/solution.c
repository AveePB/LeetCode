//https://leetcode.com/problems/trapping-rain-water/

int max(int* a, int* b) {
    return (*a > *b) ? *a : *b;
}

int min(int* a, int* b) {
    return (*a < *b) ? *a : *b;
}

int trap(int* arr, int n) {
    int ans = 0, rMAX = 0, lMAX[n];
    lMAX[0] = *arr;

    //Go from left
    for (int i=1; i<n; i++) {
        lMAX[i] = max(&lMAX[i-1], arr+i);
    }

    //Go from right
    for (int i=(n-1); i >= 0; i--) {
        rMAX = max(&rMAX, arr+i);

        //ans += waterLvL - height
        ans += min(&lMAX[i], &rMAX) - *(arr+i);
    }

    return ans;
}
