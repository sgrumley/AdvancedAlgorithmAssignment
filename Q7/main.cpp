#include <bits/stdc++.h>
#include "RBTree.cpp"
#include "VEBTree.cpp"

using namespace std;

int main() {
    int n = 5;

    RBTree tree;
    Van_Emde_Boas *veb = new Van_Emde_Boas(n);


    tree.insert(5);
    tree.deleteByVal(5);

    // put all functions into class
    //
}
