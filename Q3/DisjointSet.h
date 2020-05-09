

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

 #include <bits/stdc++.h>

class DSet {
private:

    int *rank;
    int *parent;
    int n;

    std::unordered_map<int, std::vector<int> >elements;

public:

    DSet(int);

    void makeSet();

    int  find(int);

    void unionSet(int,
                  int);

    bool isConnected(int,
                     int);

    void storeSetValues(int,
                        int);

    void listSet(int);

    void printSet(int);
};
#endif // ifndef DISJOINTSET_H
