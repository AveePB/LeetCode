//https://leetcode.com/problems/n-queens/
public class Solution {

    private boolean[] isCol, isNegDiag, isPosDiag;
    private List<List<String>> chessBoards;

    private void backtrack(List<String> board, int n, int row) {
        //Stop placing queens
        if (row == n) {
            chessBoards.add(new ArrayList<>(board));
            return;
        }

        //Create char array
        char[] arr = new char[n];
        Arrays.fill(arr, '.');

        //Analyze every column
        for (int col = 0; col < n; col++) {
            //Compute diagonals
            int negDiag = col - row + (n-1);
            int posDiag = col + row;

            //Can't place queen
            if (isCol[col]) continue;
            if (isNegDiag[negDiag]) continue;
            if (isPosDiag[posDiag]) continue;

            //Mark position
            isCol[col] = true;
            isNegDiag[negDiag] = true;
            isPosDiag[posDiag] = true;

            arr[col] = 'Q';
            board.add(new String(arr));

            //Go to next row
            backtrack(board, n, row+1);

            //Unmark position
            isCol[col] = false;
            isNegDiag[negDiag] = false;
            isPosDiag[posDiag] = false;

            arr[col] = '.';
            board.removeLast();
        }
    }

    public List<List<String>> solveNQueens(int n) {
        //Initialize structs
        isCol = new boolean[n];
        isNegDiag = new boolean[2*n - 1];
        isPosDiag = new boolean[2*n - 1];
        chessBoards = new ArrayList<>();

        //Use smart backtracking
        backtrack(new ArrayList<>(), n, 0);

        return chessBoards;
    }
}