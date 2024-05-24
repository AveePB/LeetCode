//https://leetcode.com/problems/n-queens-ii/
public class Solution {

    private boolean[] isCol, isNegDiag, isPosDiag;
    private int ans;

    private void backtrack(int n, int row) {
        //Found satisfying board
        if (row == n) {
            ans++;
            return;
        }

        //Check all columns
        for (int col = 0; col < n; col++) {
            //Compute diagonals
            int negDiag = row - col + (n-1);
            int posDiag = row + col;

            //Position is marked
            if (isCol[col]) continue;
            if (isNegDiag[negDiag]) continue;
            if (isPosDiag[posDiag]) continue;

            //Mark position
            isCol[col] = true;
            isNegDiag[negDiag] = true;
            isPosDiag[posDiag] = true;

            backtrack(n, row+1);

            //Unmark position
            isCol[col] = false;
            isNegDiag[negDiag] = false;
            isPosDiag[posDiag] = false;
        }
    }

    public int totalNQueens(int n) {
        //Initialize structs
        isCol = new boolean[n];
        isNegDiag = new boolean[2*n - 1];
        isPosDiag = new boolean[2*n - 1];

        ans = 0;

        //Run smart backtracking
        backtrack(n, 0);

        return ans;
    }
}