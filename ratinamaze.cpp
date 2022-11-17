#include <iostream>
using namespace std;

bool isPath(int** maze, int x, int y, int n) {

    if(x < n && y < n && maze[x][y] == 1) return true;
    return false;
}

bool calculateSoln(int** maze, int x, int y, int n, int** soln) {
    if(x == n-1 && y == n-1) {
        soln[x][y] = 1;
        return true;
    }
    
    if(isPath(maze, x, y, n)) {
        soln[x][y] = 1;

        if(calculateSoln(maze, x+1, y, n, soln)) return true;
        if(calculateSoln(maze, x, y+1, n, soln)) return true;
        soln[x][y] = 0;
        return false;
    }
    return false;
}

int main() {

    int n; cin >> n;

    int** maze = new int*[n];
    for(int i = 0; i < n; i++) {
        maze[i] = new int[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    int** soln = new int*[n];
    for(int i = 0; i < n; i++) {
        soln[i] = new int[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            soln[i][j] = 0;
        }
    }

    calculateSoln(maze, 0, 0, n, soln);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << soln[i][j] << " ";
        }
        cout << endl;
    }


}