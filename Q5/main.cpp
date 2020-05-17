#include "minHeap.cpp"
#include "maxHeap.cpp"

struct DS {
private:

    PriorityQueueMin pArr;
    PriorityQueueMax pkArr;
    int              pkMax = 5;
    int              k;

public:

    DS(int k) {
        this->k = k;
    }

    void insertd(int val) {
        // if (pkArr.size() >= k) {
        //     pkArr.push(val);
        // }

        if ((val < pkMax) || (pkArr.size() <= k)) {
            if (pkArr.size() > k) {
                int tmp = pkArr.top();
                pkArr.pop();
                pArr.push(tmp);
            }
            pkArr.push(val);
            pkMax = pkArr.top();
        } else {
            pArr.push(val);
        }
    }

    void del(int val) {
        if (val < pkMax) {
            pkArr.remove(val);
            int tmp = pArr.top();
            pArr.pop();
            pkArr.push(tmp);
            pkMax = pkArr.top();
        } else {
            pArr.remove(val);
        }
    }

    void printK() {
        cout << k << " smallest values: " << endl;
        cout << "------------------------------------------" << endl;
        pkArr.printData();
        cout << endl << endl;
    }

    void printAll() {
        cout << "All Data: " << endl;
        cout << "------------------------------------------" << endl;
        pkArr.printData();
        pArr.printData();
        cout << endl << endl;
    }
};


// Min Heap C++ Implementation
int main()
{
    int n = 10;
    int k = 5;

    cout << "K = " << k << endl;
    DS dataStructure(k);

    dataStructure.insertd(30);
    dataStructure.insertd(10);
    dataStructure.insertd(8);
    dataStructure.insertd(3);
    dataStructure.insertd(13);
    dataStructure.insertd(7);
    dataStructure.insertd(6);
    dataStructure.insertd(20);
    dataStructure.insertd(28);
    dataStructure.insertd(23);
    dataStructure.insertd(23);
    dataStructure.insertd(27);
    dataStructure.insertd(26);
    dataStructure.insertd(19);


    dataStructure.printAll();
    dataStructure.printK();

    dataStructure.del(8);
    dataStructure.printAll();
    dataStructure.printK();


    return 0;
}
