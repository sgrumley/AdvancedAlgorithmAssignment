#include <bits/stdc++.h>

using namespace std;

class List {
private:

    int n;
    int *index;
    vector<int>data;

public:

    List(int m) : n{m + 1}, index{new int[n]{ -1 }} {
        fill_n(index, n, -1);
    }

    ~List() {
        delete[] index;
    }

    int operator[](int index) {
        if (index >= n) {
            cout << "Out of range" << endl;
        } else if (index < 0) {
            cout << "Out of range" << endl;
        }
        return data.at(index);
    }

    int find(int term) {
        return index[term] != -1 ? index[term] : -1;
    }

    void add(int newVal) {
        // insert pointer into vector and create value in array
        int tempInd = data.size();

        data.push_back(newVal);
        index[newVal] = tempInd;
    }

    void remove(int val) {
        // remove the pointer and delete the value in array
        int temp = data.at(index[val]);

        // Overwrite last element to the one we won't to delete
        data.at(index[val]) = data.back();

        // Update indicies
        index[temp] =  data.at(index[val]);
        index[val]  = -1;
        data.pop_back();
    }

    void clear() {
        // clear all pointers and values
        // for reverse iter pop element and update the index
        for (auto elem = data.rbegin(); elem != data.rend(); elem++) {
            index[*(elem)] = -1;
            data.pop_back();
        }
    }

    void printBoth() {
        cout << "------------------------------------------------------------ " << endl;
        cout << "Data: " << endl;

        for (auto& elem : data) {
            cout << elem << " ";
        } cout << endl;

        cout << "Index: " << endl;

        for (int i = 0; i < n; i++) {
            if (index[i] == -1) {
                cout << " " << i << "| ";
            } else {
                cout << i << "| ";
            }
        } cout << endl;

        for (int i = 0; i < n; i++) {
            cout << index[i] << "| ";
        } cout << endl;
        cout << "------------------------------------------------------------ " << endl;
    }
};

int main() {
    List myList(10);

    myList.add(8);
    cout << "Add 8: " << endl;
    myList.printBoth();
    myList.add(3);
    cout << "Add 3: " << endl;
    myList.printBoth();
    myList.add(9);
    cout << "Add 9: " << endl;
    myList.printBoth();
    cout << "8 @ pos: " << myList.find(8) << endl;
    cout << "Remove 8: " << endl;
    myList.remove(8);
    cout << "8 @ pos: " << myList.find(8) << endl;
    myList.printBoth();
    cout << "Clear list: " << endl;
    myList.clear();
    myList.printBoth();


    return 1;
}
