#include <iostream>
#include <string>
using namespace std;

int grid[9][9];
bool row[9][10], col[9][10], subgrid[3][3][10];

void input() {
    for(int row = 0; row < 9; row++) {
        string buffer;
        cin >> buffer;
        for(int col = 0; col < 9; col++) {
            grid[row][col] = buffer[col] - '0';
        }
    }
}

bool illegal(int r, int c, int num) {
    return row[r][num] || col[c][num] || subgrid[r/3][c/3][num];
}

void update(int r, int c, int num, bool val) {
    row[r][num] = val;
    col[c][num] = val;
    subgrid[r/3][c/3][num] = val;
}

bool check() {
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            if(grid[r][c] == 0)
                continue;
            if(illegal(r, c, grid[r][c]))
                return false;
            update(r, c, grid[r][c], true);
        }
    }
    return true;
}

int main() {
    input();
    cout << (check() ? "Legal" : "Illegal") << endl;
    return 0;
}
