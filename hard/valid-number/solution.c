// https://leetcode.com/problems/valid-number/

bool isInteger(int dotCtr[], int expCtr[], int digitCtr[], char* s, int n, int idx, int jdx) {
    // Reading values
    int nDots = dotCtr[jdx] - dotCtr[idx-1];
    int nExps = expCtr[jdx] - expCtr[idx-1];
    int nDigits = digitCtr[jdx] - digitCtr[idx-1];

    // Safety check
    if (nDots != 0 || nExps != 0 || nDigits == 0)
        return false;

    // Starts with sign
    if (s[idx-1] == '+' || s[idx-1] == '-') 
        return nDigits == (jdx - idx);
    
    // No sign
    return nDigits == (jdx - idx) + 1;
}

bool isDecimal(int dotCtr[], int expCtr[], int digitCtr[], char* s, int n, int idx, int jdx) {
    // Reading values
    int nDots = dotCtr[jdx] - dotCtr[idx-1];
    int nExps = expCtr[jdx] - expCtr[idx-1];
    int nDigits = digitCtr[jdx] - digitCtr[idx-1];

    // Safety check
    if (nDots != 1 || nExps != 0 || nDigits == 0) 
        return false;

    // Starts with sign
    if (s[idx-1] == '+' || s[idx-1] == '-') 
        return nDots + nDigits == (jdx - idx);
    
    // No sign
    return nDots + nDigits == (jdx - idx) + 1;
}


bool isNumber(char* s) {
    int n = strlen(s);
    int dotCtr[n+1], expCtr[n+1], digitCtr[n+1];
    dotCtr[0] = expCtr[0] = digitCtr[0] = 0;

    // Count all valid chars
    for (int i = 0; i < n; i++) {
        dotCtr[i+1] = dotCtr[i];
        expCtr[i+1] = expCtr[i];
        digitCtr[i+1] = digitCtr[i];

        // Dot
        if (s[i] == '.') 
            dotCtr[i+1]++;
        // Exponent
        else if (s[i] == 'e' || s[i] == 'E') 
            expCtr[i+1]++;
        // Digit
        else if ('0' <= s[i] && s[i] <= '9') 
            digitCtr[i+1]++;
    }

    if (isInteger(dotCtr, expCtr, digitCtr, s, n, 1, n)) return true;
    if (isDecimal(dotCtr, expCtr, digitCtr, s, n, 1, n)) return true;

    int expIdx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'e' || s[i] == 'E') {
            expIdx = i+1;
            break;
        }
    }

    if (expIdx == -1 || expIdx == 1 || expIdx == n) return false;

    if (isDecimal(dotCtr, expCtr, digitCtr, s, n, 1, expIdx-1))
        return isInteger(dotCtr, expCtr, digitCtr, s, n, expIdx+1, n);
    
    return (isInteger(dotCtr, expCtr, digitCtr, s, n, 1, expIdx-1)) &&
            isInteger(dotCtr, expCtr, digitCtr, s, n, expIdx+1, n);
}