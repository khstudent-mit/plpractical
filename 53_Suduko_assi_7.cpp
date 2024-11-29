//  Design and implement a program for 2 * 2 Suduko Solver using Recursive Backtracking

#include <iostream>
using namespace std;
#define N 4
void print(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 2;
    int startCol = col - col % 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main() {
    int grid[N][N];
    cout << "Enter the Sudoku puzzle:" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    if (solveSudoku(grid, 0, 0)){
	
    cout << "Solved Sudoko is:" << endl;
        print(grid);
    }
    else
        cout << "No solution exists" << endl;

    return 0;
}
/*Enter the Sudoku puzzle:
0 1 0 0
2 0 0 0
0 0 3 0
0 0 0 4
Solved Sudoko is:
3 1 4 2
2 4 1 3
4 2 3 1
1 3 2 4
*/

