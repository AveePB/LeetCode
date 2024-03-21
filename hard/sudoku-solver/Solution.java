public class Solution {

    private static final int NUM_OF_VALUES = 9, NUM_OF_SQUARES = 3,
            NUM_OF_COLS = 9, NUM_OF_ROWS = 9;

    private boolean isCol[][], isRow[][], isSquare[][][];
    private char[][] board;

    private boolean backtrackSolution(int row, int col) {
        //Return successful result
        if (row == NUM_OF_ROWS) return true;

        //Compute next coordinates
        int nextRow = row + (col + 1) / 9, nextCol = (col + 1) % 9;

        //Current field isn't empty
        if (this.board[row][col] != '.')
            return backtrackSolution(nextRow, nextCol);

        //Check every possible value
        for (int val = 0; val < NUM_OF_VALUES; val++) {
            //Can't use value
            if (this.isCol[col][val]) continue;
            if (this.isRow[row][val]) continue;
            if (this.isSquare[row / 3][col / 3][val]) continue;

            //Use current value
            this.board[row][col] = (char) ('1' + val);

            //Mark value as used
            this.isCol[col][val] = true;
            this.isRow[row][val] = true;
            this.isSquare[row / 3][col / 3][val] = true;

            //Return successful result
            if (backtrackSolution(nextRow, nextCol)) return true;

            //Stop using current value
            this.board[row][col] = '.';

            //Mark value as unused
            this.isCol[col][val] = false;
            this.isRow[row][val] = false;
            this.isSquare[row / 3][col / 3][val] = false;
        }

        return false;
    }

    public void solveSudoku(char[][] board) {
        //Initialize structures
        this.isCol = new boolean[NUM_OF_COLS][NUM_OF_VALUES];
        this.isRow = new boolean[NUM_OF_ROWS][NUM_OF_VALUES];
        this.isSquare = new boolean[NUM_OF_SQUARES][NUM_OF_SQUARES][NUM_OF_VALUES];
        this.board = board;

        //Go through every row
        for (int row = 0; row < NUM_OF_ROWS; row++) {
            //Go through every col
            for (int col = 0; col < NUM_OF_COLS; col++) {
                //Skip empty field
                if (board[row][col] == '.') continue;

                //Map and mark value as used
                int val = board[row][col] - '1';

                this.isCol[col][val] = true;
                this.isRow[row][val] = true;
                this.isSquare[row / 3][col / 3][val] = true;
            }
        }

        //Check every possible combination
        backtrackSolution(0, 0);
    }
}
