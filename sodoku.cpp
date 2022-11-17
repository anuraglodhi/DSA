#include <iostream>
using namespace std;

bool canPlace(int n, int x, int y, int mat[9][9]) {
    for(int i = 0; i < 9; i++) {
        if(mat[x][i] == n) return false;
        if(mat[i][y] == n) return false;
    }

    int x1 = (x / 3) * 3;
    int y1 = (y / 3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(mat[x1+i][y1+j] == n) return false;
        }
    }

    return true;
}

int nextX(int x, int y) {
    if(x == 8) return 0;
    return x+1;
}
int nextY(int x, int y) {
    if(x == 8) return y+1;
    return y;
}

bool solve(int mat[9][9], int x, int y) {
    if(x == 8 && y == 9) {
        return true;
    }

    if(y > 8) {
        y = 0;
        x++;
    }


    if(mat[x][y] > 0) {
        return solve(mat, x, y+1);
    }

    for(int i = 1; i <= 9; i++) {
        if(canPlace(i, x, y, mat)) {
            mat[x][y] = i;
            if(solve(mat, x, y+1)) {
                return true;
            }
        }
        mat[x][y] = 0;
    }
    return false;
}

int main() {
    int mat[9][9] = {   {3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    solve(mat, 0, 0);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}