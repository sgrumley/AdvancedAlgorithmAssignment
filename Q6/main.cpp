#include <bits/stdc++.h>

using namespace std;

class DSet {
    int *rank;
    int *parent;
    int n;

public:

    DSet(int n) {
        rank    = new int[n];
        parent  = new int[n];
        this->n = n;

        makeSet();
    }

    void makeSet() {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // rescursive find
        if (x != parent[x]) {
            // set parent to parent (path compression)
            parent[x] = find(parent[x]);

            // return find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int e1, int e2) {
        int x = find(e1);
        int y = find(e2);

        if (x == y) {
            return;
        }

        // optimzation using rank
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;

            if (rank[x] == rank[y]) {
                ++rank[y];
            }
        }

        // parent[root2] = root1;
    }
};


int getDirection(int row, int col, int nCol, int nRow) {
    // N=1 S=2 E=3 W=4
    nCol--;
    nRow--;
    cout << nRow << " " << nCol << endl;
    cout << row << " " << col << endl;
    int e;
    int NSEW[4] = { 1, 2, 3, 4 };

    int SEW[3] = { 2, 3, 4 };
    int NEW[3] = { 1, 3, 4 };
    int NSW[3] = { 1, 2, 4 };
    int NSE[3] = { 1, 2, 3 };

    int SE[2] = { 2, 3 };
    int NE[2] = { 1, 3 };
    int SW[2] = { 2, 4 };
    int NW[2] = { 1, 4 };

    // if chosen cell isnt on a boarder use full list of direction
    if ((row > 0) && (row != nRow) && (col > 0) && (col != nCol)) {
        e = rand() % 4;
        return NSEW[e];
    }

    // if chosen cell is in North East corner only make South West available
    if ((row == 0) && (col == nCol)) {
        // don't consider West or North
        e = rand() % 2;

        // cout << "Go South(i+1) or west(j-1) " << SW[e] << " N=1 S=2 E=3 W=4" << endl;
        return SW[e];
    }

    // if chosen cell is in South West corner only make North East available
    if ((row == nRow) && (col == 0)) {
        // don't consider South or East
        e = rand() % 2;

        // cout << "Go North(i-1) or East(j+1) " << NE[e] << " N=1 S=2 E=3 W=4" << endl;
        return NE[e];
    }

    // if chosen cell is in North West corner only make South East available
    if ((row == 0) && (col == 0)) {
        // don't consider West or South
        e = rand() % 2;

        // cout << "Go South(i+1) or east(j+1) " << SE[e] << " N=1 S=2 E=3 W=4" << endl;
        return SE[e];
    }

    // if chosen cell is in South East corner only make North West available
    if ((row == nRow) && (col == nCol)) {
        // don't consider East or North
        e = rand() % 2;

        // cout << "Go North(i-1) or west(j-1) " << NW[e] << " N=1 S=2 E=3 W=4" << endl;
        return NW[e];
    }

    if (row == 0) {
        // don't condsider North
        e = rand() % 3;

        // cout << "Don't Go North(i-1)  " << SEW[e] << " N=1 S=2 E=3 W=4" << endl;
        return SEW[e];
    }

    if (row == nRow) {
        // don't consider South
        e = rand() % 3;

        // cout << "Don't Go South(i+1)  " << NEW[e] << " N=1 S=2 E=3 W=4" << endl;
        return NEW[e];
    }

    if (col == 0) {
        // don't condsider West
        e = rand() % 3 + 1;

        // cout << "Don't Go West(j-1)  " << NSE[e] << " N=1 S=2 E=3 W=4" << endl;
        return NSE[e];
    }

    if (col == nCol) {
        // don't consider East
        e = rand() % 3 + 1;

        // cout << "Don't Go east(j+1)  " << NSW[e] << " N=1 S=2 E=3 W=4" << endl;
        return NSW[e];
    }
}

void printMaze(int n, int m, DSet cells, vector<vector<int> >& maze) {
    // top boundary
    for (int j = 1; j <= n; j++) {
        cout << " _";
    } cout << endl;

    // contents
    for (int i = 0; i < n; i++) {
        // start left border
        cout << "|";

        for (int j = 0; j < m; j++) {
            // row print
            if (i != n - 1) {
                if (cells.find(maze[i][j]) != cells.find(maze[i + 1][j])) {
                    cout << "_";
                } else {
                    cout << " ";
                }
            } else {
                cout << "_";
            }

            // Find a way if both are unions print " "
            // if col print
            if (j != m - 1) {
                if (cells.find(maze[i][j]) != cells.find(maze[i][j + 1])) {
                    cout << "|";
                } else {
                    cout << " ";
                }
            } else {
                // cout << "|";
            }
        }
        cout << "|";
        cout << endl;
    }
}

void mazeCreation(int row, int col) {
    // int maze[col][row];
    vector<vector<int> > maze(row, vector<int>(col, 0));
    int start, finish, n;
    int nCells = row * col;
    int cellID = 1;

    DSet cells(nCells);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = cellID;
            cellID++;
        }
    }

    start = maze[0][0];
    cout << "starting at: " << start << endl;
    finish = maze[row - 1][col - 1];
    cout << "finishing at: " << finish << endl;
    int cx, cy;
    int rCol, rRow;
    srand((unsigned)time(NULL));

    // cells.unionSet(3, 4);
    // cells.unionSet(3, 5);
    // cout << cells.find(4) << endl;

    // while goal is not reachable
    while (cells.find(start) != cells.find(finish)) {
        int d;

        //     edge = randomly select a wall;
        rCol = rand() % col;
        rRow = rand() % row;


        // get values
        cx = maze[rRow][rCol];

        // cout << endl;
        // cout << "Direction: N=1 S=2 E=3 W=4" << " = " <<  d << endl << "first  node " << cx  << " i, j " << rRow << "," << rCol << endl;

        // N=1 S=2 E=3 W=4
        d = getDirection(rRow, rCol, row, col);

        switch (d) {
        case 1:
            cy = maze[rRow - 1][rCol]; // North
            // cout << "second node " << cy  << " i, j " << rRow + 1 << "," << rCol << endl;
            // cout << "lookups cx and cy" << cx << " " << cy << endl;

            if (cells.find(cx) != cells.find(cy)) {
                cells.unionSet(cx, cy);
            }
            break;


        case 2:
            cy = maze[rRow + 1][rCol]; // South
            // cout << "second node " << cy  << " i, j " << rRow - 1 << "," << rCol << endl;
            // cout << "lookups cx and cy" << cx << " " << cy << endl;

            if (cells.find(cx) != cells.find(cy)) {
                cells.unionSet(cx, cy);
            }
            break;

        case 3:
            cy = maze[rRow][rCol + 1]; // East
            // cout << "second node " << cy  << " i, j " << rRow  << "," << rCol + 1 << endl;
            // cout << "lookups cx and cy" << cx << " " << cy << endl;


            if (cells.find(cx) != cells.find(cy)) {
                cells.unionSet(cx, cy);
            }
            break;

        case 4:
            cy =  maze[rRow][rCol - 1]; // West
            // cout << "second node " << cy  << " i, j " << rRow << "," << rCol - 1 << endl;
            // cout << "lookups cx and cy" << cx << " " << cy << endl;

            if (cells.find(cx) != cells.find(cy)) {
                cells.unionSet(cx, cy);
            }
            break;

        default:
            cout << "broke" << endl;
        }

        // break;
    }

    printMaze(row, col, cells, maze);
}

int main() {
    // init object
    int col, row;

    // row = 10; // 50;
    // col = 10; // 88;
    row = 10;
    col = 10;


    mazeCreation(row, col);
    cout << "complete";

    // cout << endl;

    // for (int i = 1; i <= 100; i++) {
    //     cout << i << " ";

    //     if (i % 10 == 0) {
    //         cout << endl;
    //     }
    // }

    // printMaze(col, row);
}
