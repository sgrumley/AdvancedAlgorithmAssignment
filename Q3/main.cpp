#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;

bool isConnected(int u, int v, DSet& graph) {
    if (graph.find(u) == graph.find(v)) {
        return true;
    }
    return false;
}

void listConnected() {
    // print the connected nodes
}

int main() {
    int  n = 10;
    int  e1, e2;
    DSet graph(n);

    srand((unsigned)time(NULL));

    // for (int i = 0; i < n / 2; i++) {
    //     e1 = rand() % n + 1;
    //     e2 = rand() % n + 1;
    //     graph.unionSet(e1, e2);
    // }

    // graph.unionSet(1,  4);
    // graph.unionSet(4,  5);
    // graph.unionSet(5,  9);
    // graph.unionSet(6,  4);
    // graph.unionSet(10, 2);
    // graph.unionSet(10, 8);


    graph.unionSet(3, 7);
    cout << graph.find(3) << " " <<  graph.find(e2) << endl;
    cout << isConnected(3, 7, graph);

    graph.printSet(3);
}
