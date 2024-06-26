//https://leetcode.com/problems/maximal-rectangle/

int maximalRectangleInHistogram(int* hist, int* size);
int** createHistograms(char** arr, int* nRows, int* nCols);
void delete2DArray(int** arr, int* nRows);

int maximalRectangle(char** matrix, int matrixSize, int* matColSize) {
    int n = matrixSize + 1, m = *matColSize + 1, ans = 0;
    int** hist = createHistograms(matrix, &n, &m);

    for(int i = 1; i < n; i++) {
        int maxRect = maximalRectangleInHistogram(hist[i], &m);
        ans = (ans > maxRect) ? ans : maxRect;
    }

    delete2DArray(hist, &n);
    return ans;
}

int maximalRectangleInHistogram(int* hist, int* size) {
    int ans = 0, ptr = 0, idxStck[*size], heightStck[*size];

    for (int i = 0; i < *size; i++) {
        int startIdx = i;
        while((ptr > 0) && (heightStck[ptr-1] > hist[i])) {
            // Pop from stack
            int idx = idxStck[ptr-1], height = heightStck[ptr-1];
            ptr--;

            // Find new start
            startIdx = idx;

            // Compute current rectangle
            int maxRect = (i-idx) * height;
            ans = (ans > maxRect) ? ans : maxRect;
        }

        //Push on stack
        idxStck[ptr] = startIdx;
        heightStck[ptr] = hist[i];
        ptr++;
    }

    // Handle leftovers
    while (ptr > 0) {
        // Pop from stack
        int idx = idxStck[ptr-1], height = heightStck[ptr-1];
        ptr--;

        // Compute current rectangle
        int maxRect = (*size-idx) * height;
        ans = (ans > maxRect) ? ans : maxRect;        
    }
    
    return ans;
}

int** createHistograms(char** mat, int* nRows, int* nCols) {
    // Initialize empty 2d array
    int** hist = (int**)malloc(*nRows * sizeof(int*));
    
    for (int i = 0; i < *nRows; i++)
        hist[i] = (int*)malloc(*nCols * sizeof(int));

    for (int i = 0; i < *nRows; i++) hist[i][0] = 0;
    for (int i = 0; i < *nCols; i++) hist[0][i] = 0;

    // Create histograms
    for (int row = 1; row < *nRows; row++) {
        for (int col = 1; col < *nCols; col++) {
            // Extend subarray
            if (mat[row-1][col-1] == '1') 
                hist[row][col] = 1 + hist[row-1][col];       
            
            // Cut subarray
            else
                hist[row][col] = 0;
        }
    }
    return hist;
}

void delete2DArray(int** arr, int* nRows) {
    for (int i = 0; i < *nRows; i++) free(arr[i]);
    free(arr);
}
