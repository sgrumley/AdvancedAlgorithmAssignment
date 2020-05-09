#include <bits/stdc++.h>
#include "DisjointSet.h"

DSet::DSet(int n) {
    rank    = new int[n + 1];
    parent  = new int[n + 1];
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

    // optimzation using size
    if (rank[p1] > rank[p2]) {
        storeSetValues(p1, p2);
        parent[p2] = p1;
    } else {
        storeSetValues(p2, p1);
        parent[p1] = p2;

        // update size
        rank[p2] += rank[p1];
    }
}

bool DSet::isConnected(int e1, int e2) {
    if (find(e1) == find(e2)) {
        return true;
    }
    return false;
}

void DSet::storeSetValues(int p1, int p2) {
    // if both elements are in the dictionary - copy p2 set into p1
    if ((elements.count(p2) == 1) && (elements.count(p1) == 1)) {
        for (auto& elem : elements[p2]) {
            elements[p1].push_back(elem);
        }

        // delete elements[p2]
        elements.erase(p2);
        elements[p1].push_back(p2);
    } else if ((elements.count(p1) == 0) && (elements.count(p2) == 0)) {
        // create and push p2 into the vector
        std::vector<int> t;
        t.push_back(p2);
        elements.insert(std::pair<int, std::vector<int> >(p1, t));
    } else if (elements.count(p1) == 0) {
        std::vector<int> t;

        for (auto& elem : elements[p2]) {
            t.push_back(elem);
        }
        elements.erase(p2);

        // delete elements [p2]
        t.push_back(p2);
        elements.insert(std::pair<int, std::vector<int> >(p1, t));
        elements[p1].push_back(p2);
    } else if (elements.count(p2) == 0) {
        elements[p1].push_back(p2);
    }
}

void DSet::listSet(int e) {
    int p = find(e);
    std::cout << "All elements in set: "  << e << std::endl;

    for (auto& elem : elements[p]) {
        std::cout << elem << " ";
    }
    std::cout << p << std::endl;
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

    // print true parent
    for (int i = 0; i < n; i++) {
        std::cout << find(i) << " ";
    } std::cout << std::endl;
    std::cout << "Rank: " << std::endl;

    // print parents
    for (int i = 0; i < n; i++) {
        std::cout << rank[i] << " ";
    } std::cout << std::endl;

    std::cout << "----------------------------------------------" << std::endl;

    for (std::unordered_map<int, std::vector<int> >::iterator ii = elements.begin(); ii != elements.end(); ++ii) {
        std::cout << (*ii).first << ": ";
        std::vector<int> inVect = (*ii).second;

        for (unsigned j = 0; j < inVect.size(); j++) {
            std::cout << inVect[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
}
