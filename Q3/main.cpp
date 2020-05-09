#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;


int main() {
    int  n = 10;
    int  e1, e2;
    DSet graph(n);

    // srand((unsigned)time(NULL));

    // for (int i = 0; i < n / 2; i++) {
    //     e1 = rand() % n + 1;
    //     e2 = rand() % n + 1;
    //     cout << e1 << " " << e2 << endl;
    //     graph.unionSet(e1, e2);
    // }

    graph.unionSet(1, 3);
    graph.unionSet(2, 3);
    graph.unionSet(2, 4);

    graph.unionSet(5, 6);
    graph.unionSet(6, 7);
    graph.unionSet(5, 8);

    cout << graph.isConnected(5, 7) << endl;
    graph.listSet(5);

    // graph.unionSet(4, 8);


    // graph.unionSet( 3, 7);
    // cout << graph.find(3) << " " <<  graph.find(7) << endl;
    // cout << isConnected(3, 7, graph);

    graph.printSet(3);
}
