// https://leetcode.com/problems/maximum-subarray/
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int* arr, int n) {
    int globalSum = *(arr), localSum = *(arr);

    for (int i = 1; i < n; i++) {
        localSum = max(localSum + *(arr+i), *(arr+i));
        globalSum = max(globalSum, localSum);
    }

    return globalSum;
}
