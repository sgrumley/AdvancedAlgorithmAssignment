// Bellman Ford graph algorithm

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <fstream>

#define MAX 99
using namespace std;

struct edges {
    int u;
    int v;
    int w;
};


void readIn(string filename, vector<edges>& E) {
    ifstream ifs(filename.c_str());
    int u, v, w;

    struct edges singleEdge;

    if (ifs.fail()) {
        cout << "error opening file" << endl;
    }

    int i = 0;

    while (!ifs.eof()) {
        ifs >> u >> v >> w;

        singleEdge.u = u;
        singleEdge.v = v;
        singleEdge.w = w;
        i++;

        E.push_back(singleEdge);
    }
}

void bellman(char src, int numE, int numV, const vector<edges>& E) {
    int u, v, w;
    int dist[numV];

    // initiate all dist to inf except source = 0
    for (int i = 0; i < numE; i++) {
        dist[i] = MAX;
    }
    dist[src] = 0;

    // for v-1 times
    for (int i = 0; i < numV - 1; i++) {
        // for every edge
        for (int j = 0; j < numE - 1; j++) {
            u = E[j].u;
            v = E[j].v;
            w = E[j].w;

            // if dist and weight < dist v
            if ((dist[u] != MAX) && (dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < numE; j++) {
        u = E[j].u;
        v = E[j].v;
        w = E[j].w;

        if (dist[u] + w < dist[v]) {
            cout << "Negative Cycle = True" << endl;

            // return;
        }
    }

    cout << "\nVertex" << "  Distance from source";

    for (int i = 1; i <= numV; i++) {
        cout << "\n" << i << "\t" << dist[i];
    }
}

int main() {
    // Data inputs
    string filename = "Q2input.txt";
    int    numV     = 5;
    int    numE     = 10;
    int    src      = 1;
    vector<edges> E;

    // Read edges into vector of structs
    readIn(filename, E);

    // Display initial read in data
    for (int i = 0; i < 10; i++) {
        cout << " " << E[i].u << " " << E[i].v << " " << E[i].w << endl;
    }

    // Pass data to function to get results printed
    bellman(src, numE, numV, E);
}
