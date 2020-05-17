#include <bits/stdc++.h>
#include "RBTree.cpp"


using namespace std;

// using namespace std::chrono;

int main() {
    int n = 5;

    RBTree tree;


    tree.insert(5);
    tree.deleteByVal(5);


    // Get starting timepoint
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < 500; i++) {
        tree.insert(i);
    }
    auto stop = chrono::high_resolution_clock::now();


    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "duration for RB tree insert" << endl;

    // put all functions into class
    //
}
