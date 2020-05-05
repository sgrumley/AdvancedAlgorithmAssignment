#include <bits/stdc++.h>
#include "DisjointSet.h"

DSet::DSet(int n) {
    rank    = new int[n];
    parent  = new int[n];
    this->n = n;

    makeSet();
}

void DSet::makeSet() {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
}

int DSet::find(int x) {
    // rescursive find
    if (x != parent[x]) {
        // set parent to parent (path compression)
        parent[x] = find(parent[x]);

        // return find(parent[x]);
    }
    return parent[x];
}

void DSet::unionSet(int e1, int e2) {
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
