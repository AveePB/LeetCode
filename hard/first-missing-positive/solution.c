//https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(int* arr, int n) {
    //Declare & initialize array
    bool isVis[n];
    for (int i = 0; i < n; i++) isVis[i] = false;

    //Go through array
    for (int i = 0; i < n; i++) {
        //Out of bounds
        if (*(arr+i) < 1 || *(arr+i) > n) continue;

        //Mark number
        isVis[*(arr+i) - 1] = true;
    }

    //Go through numbers
    for (int i = 0; i < n; i++) {
        //Number was marked
        if (isVis[i]) continue;
        
        //Number is missing
        return i + 1;
    }

    return n + 1;
}
