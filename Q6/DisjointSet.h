
using namespace std;

#ifndef DSET_H
# define DSET_H

class DSet {
private:

    int *rank;
    int *parent;
    int n;

public:

    DSet(int);

    void makeSet();

    int  find(int);

    void unionSet(int,
                  int);
};
#endif // ifndef DSET_H
