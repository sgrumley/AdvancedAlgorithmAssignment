#include <bits/stdc++.h>
#include "RBTree.cpp"


using namespace std;

// using namespace std::chrono;

int main() {
    int n = 500000;

    RBTree tree;

    cout << "N = " << n << endl;


    tree.insert(5);
    tree.deleteByVal(5);


    // Get time for insert
    auto starti = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        tree.insert(i);
    }
    auto stopi     = chrono::high_resolution_clock::now();
    auto durationi = chrono::duration_cast<chrono::microseconds>(stopi - starti);
    cout << "duration for RB tree insert " << durationi.count() << "ms" << endl;

    // Get time for find
    auto startf = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        tree.search(i);
    }
    auto stopf     = chrono::high_resolution_clock::now();
    auto durationf = chrono::duration_cast<chrono::microseconds>(stopf - startf);
    cout << "duration for RB tree search " << durationf.count() << "ms" << endl;

    // Get time for delete
    auto startd = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        tree.deleteByVal(i);
    }
    auto stopd     = chrono::high_resolution_clock::now();
    auto durationd = chrono::duration_cast<chrono::microseconds>(stopd - startd);
    cout << "duration for RB tree delete " << durationd.count() << "ms" << endl;

    // put all functions into class
    // tree.printInOrder()
}
