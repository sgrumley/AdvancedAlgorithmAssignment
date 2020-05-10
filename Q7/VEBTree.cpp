#include <bits/stdc++.h>
using namespace std;

class Van_Emde_Boas {
public:

    int universe_size;
    int minimum;
    int maximum;
    Van_Emde_Boas *summary;
    vector<Van_Emde_Boas *>clusters;

    // Function to return cluster numbers
    // in which key is present
    int high(int x)
    {
        int div = ceil(sqrt(universe_size));

        return x / div;
    }

    // Function to return position of x in cluster
    int low(int x)
    {
        int mod = ceil(sqrt(universe_size));

        return x % mod;
    }

    // Function to return the index from
    // cluster number and position
    int generate_index(int x, int y)
    {
        int ru = ceil(sqrt(universe_size));

        return x * ru + y;
    }

    // Constructor
    Van_Emde_Boas(int size)
    {
        universe_size = size;
        minimum       = -1;
        maximum       = -1;

        // Base case
        if (size <= 2) {
            summary  = nullptr;
            clusters = vector<Van_Emde_Boas *>(0, nullptr);
        }
        else {
            int no_clusters = ceil(sqrt(size));

            // Assigning VEB(sqrt(u)) to summary
            summary = new Van_Emde_Boas(no_clusters);

            // Creating array of VEB Tree pointers of size sqrt(u)
            clusters = vector<Van_Emde_Boas *>(no_clusters, nullptr);

            // Assigning VEB(sqrt(u)) to all its clusters
            for (int i = 0; i < no_clusters; i++) {
                clusters[i] = new Van_Emde_Boas(ceil(sqrt(size)));
            }
        }
    }
};

// Function to return the minimum value
// from the tree if it exists
int VEB_minimum(Van_Emde_Boas *helper)
{
    return helper->minimum == -1 ? -1 : helper->minimum;
}

// Function to return the maximum value
// from the tree if it exists
int VEB_maximum(Van_Emde_Boas *helper)
{
    return helper->maximum == -1 ? -1 : helper->maximum;
}

// Function to insert a key in the tree
void insert(Van_Emde_Boas *helper, int key)
{
    // If no key is present in the tree
    // then set both minimum and maximum
    // to the key (Read the previous article
    // for more understanding about it)
    if (helper->minimum == -1) {
        helper->minimum = key;
        helper->maximum = key;
    }
    else {
        if (key < helper->minimum) {
            // If the key is less than current minimum
            // then swap it with the current minimum
            // because this minimum is actually
            // minimum of one of the internal cluster
            // so as we go deeper into the Van Emde Boas
            // we need to take that minimum to its real position
            // This concept is similar to "Lazy Propagation"
            swap(helper->minimum, key);
        }

        // Not base case then...
        if (helper->universe_size > 2) {
            // If no key is present in the cluster then insert key into
            // both cluster and summary
            if (VEB_minimum(helper->clusters[helper->high(key)]) == -1) {
                insert(helper->summary, helper->high(key));

                // Sets the minimum and maximum of cluster to the key
                // as no other keys are present we will stop at this level
                // we are not going deeper into the structure like
                // Lazy Propagation
                helper->clusters[helper->high(key)]->minimum = helper->low(key);
                helper->clusters[helper->high(key)]->maximum = helper->low(key);
            }
            else {
                // If there are other elements in the tree then recursively
                // go deeper into the structure to set attributes accordingly
                insert(helper->clusters[helper->high(key)], helper->low(key));
            }
        }

        // Sets the key as maximum it is greater than current maximum
        if (key > helper->maximum) {
            helper->maximum = key;
        }
    }
}

// Function that returns true if the
// key is present in the tree
bool isMember(Van_Emde_Boas *helper, int key)
{
    // If universe_size is less than the key
    // then we can not search the key so returns
    // false
    if (helper->universe_size < key) {
        return false;
    }

    // If at any point of our traversal
    // of the tree if the key is the minimum
    // or the maximum of the subtree, then
    // the key is present so returns true
    if ((helper->minimum == key) || (helper->maximum == key)) {
        return true;
    }
    else {
        // If after attending above condition,
        // if the size of the tree is 2 then
        // the present key must be
        // maximum or minimum of the tree if it
        // is not then it returns false becuase key
        // can not be present in the sub tree
        if (helper->universe_size == 2) {
            return false;
        }
        else {
            // Recursive call over the cluster
            // in which the key can be present
            // and also pass the new position of the key
            // i.e., low(key)
            return isMember(helper->clusters[helper->high(key)],
                            helper->low(key));
        }
    }
}
