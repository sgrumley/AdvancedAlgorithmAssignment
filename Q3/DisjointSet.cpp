#include <bits/stdc++.h>
#include "DisjointSet.h"

DSet::DSet(int n) {
    rank    = new int[n];
    parent  = new int[n];
    this->n = n + 1;

    makeSet();
}

void DSet::makeSet() {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rank[i]   = 1;
    }
}

int DSet::find(int e) {
    // rescursive find
    if (e != parent[e]) {
        // set parent to parent (path compression)
        parent[e] = find(parent[e]);
    }
    return parent[e];
}

void DSet::unionSet(int e1, int e2) {
    int p1 = find(e1);
    int p2 = find(e2);

    if (p1 == p2) {
        return;
    }

    // optimzation using rank/size
    if (rank[p1] > rank[p2]) {
        parent[p2] = p1;

        // add contents from "p2"
    } else {
        parent[p1] = p2;

        // represent size
        rank[p2] += rank[p1];

        // represent rank
        // if (rank[p1] == rank[p2]) {
        //     ++rank[p2];
        // }
    }
}

void DSet::printSet(int e) {
    int root = e;
    std::cout << std::endl << "Elements: " << std::endl;

    // print nodes
    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
    } std::cout << std::endl;

    std::cout << "Parents: " << std::endl;

    // print parents
    for (int i = 0; i < n; i++) {
        std::cout << parent[i] << " ";
    } std::cout << std::endl;

    std::cout << "Rank: " << std::endl;

    // print parents
    for (int i = 0; i < n; i++) {
        std::cout << rank[i] << " ";
    } std::cout << std::endl;
}
