//https://leetcode.com/problems/largest-rectangle-in-histogram
int largestRectangleArea(int* hist, int size) {
    int ans = 0, ptr = 0, idxStck[size], heightStck[size];

    for (int i = 0; i < size; i++) {
        int startIdx = i;
        while (ptr > 0 && heightStck[ptr-1] > hist[i]) {
            //Pop from stack
            int idx = idxStck[ptr-1], height = heightStck[ptr-1];
            ptr--;

            //Set new start
            startIdx = idx;

            //Compute rectangle area
            int rectArea = (i - idx) * height;
            ans = (ans > rectArea) ? ans : rectArea;
        }

        //Push on stack
        idxStck[ptr] = startIdx;
        heightStck[ptr] = hist[i];
        ptr++;
    }

    //Handle leftovers
    while (ptr > 0) {
        //Pop from stack
        int idx = idxStck[ptr-1], height = heightStck[ptr-1];
        ptr--;

        //Compute rectangle area
        int rectArea = (size - idx) * height;
        ans = (ans > rectArea) ? ans : rectArea;
    }
    
    return ans;
}
