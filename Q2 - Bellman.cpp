// Bellman Ford graph algorithm

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <fstream>

#define MAX 99
using namespace std;

struct edges{
    int  u;
    int  v;
    int     w;
};


void readIn(string filename, vector<edges> &E){

    ifstream ifs(filename.c_str());
    int u,v, w;
    
    struct edges singleEdge;

    if (ifs.fail()){
        cout << "error opening file" << endl;
    }

    int i=0;
    while(! ifs.eof()){
        ifs >> u >> v >> w;

        singleEdge.u = u;
        singleEdge.v = v;
        singleEdge.w = w;
        i++;

        E.push_back(singleEdge);
    }

}

void bellman(char src, int numE, int numV, const vector<edges> &E){
    int u,v,w;
    int dist[numV];

    cout << "start of bellman" << endl;
    
    // initiate all dist to inf except source = 0
    for (int i=0; i < numE; i++){
        dist[i] = MAX; 
    }
    dist[src] = 0;

    // for v-1 times
    for (int i = 0; i < numV - 1; i++){
        // for every edge
        cout << "progress: " << i << "/" << numV << endl;
        for (int j = 0; j < numE - 1; j++){
            cout << "progress: " << j << "/" << numE << endl;
            u = E[j].u;
            v = E[j].v;
            w = E[j].w;
            cout << "distu(" << u << ") + w( " << w << ") < distv(" << v << ") =" << dist[u]+w << "<" << dist[v] << endl;
            if (dist[u] != MAX && dist[u] + w < dist[v]){
                cout << "make dist[v] = " << dist[u] + w << endl;
                dist[v] = dist[u] + w;
            }
            cout << endl;

        }
        cout << "done " << endl;
    }
    cout << "items relaxed" << endl;

    for(int j = 0; j < numE; j++){
        u=E[j].u;
        v=E[j].v;
        w=E[j].w;
    
        if(dist[u]+w < dist[v]){
            cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
            return;
        }  
    }
  
    cout<<"\nVertex"<<"  Distance from source";
    for(int i = 1; i <= numV; i++){
        cout<<"\n"<<i<<"\t"<<dist[i];
    }

}

int main() {
    // get file name as parameter for file else use default
    string filename = "Q2input.txt";
    int numV = 5;
    int numE = 10;
    int src = 1;
    // set edges  
    vector<edges> E;
    readIn(filename, E);

    for (int i=0; i<10; i++){
        cout << " " << E[i].u << " " << E[i].v << " " << E[i].w << endl;
    }

    // pass data to  bellman
    // maybe pass a vector that contains the path
    bellman(src, numE, numV, E);
}
