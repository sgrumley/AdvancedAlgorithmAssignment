#include <bits/stdc++.h>
#include <vector>


using namespace std;

/*

   You are traveling by a cross-country by car and there are n car rentals along the way.
   Before starting your journey you are given for each 1<= i < j <= n the fee fi,j for renting a car from car rental i to car rental j.
   These fees are arbitrary. For example, it is possible that f1,3 = 10 and f1,4 = 4. You begin at car rental 1 and must end at car rental n using rented cars.
   Your goal is to minimize the rental cost. Give the most efficient algorithm you can for this problem.
   Be sure to prove that your algorithm yields an optimal solution and analyze the time complexity.

 */

// structure of trip
struct Trip {
    int brand;
    int start;
    int dest;
    int cost;
};

bool compareDistance(const Trip& a, const Trip& b) {
    return a.dest < b.dest;
}

int minCost(vector<Trip>& trips, vector<int>& src, vector<int>& company, int n) {
    // Lookup array for costs
    int numShops = 4;

    vector<int> bestCostAt(n, 0);

    // int bestCostAt[4] = { 0 };
    // int src[4]        = { 0 };
    // int company[4]    = { 0 };

    int nTrips = trips.size();


    for (int i = 0; i < 4; i++) {
        bestCostAt[i] = 999;
    }

    // initiate best cost for getting to stop 1
    bestCostAt[trips[0].dest - 1] = trips[0].cost;
    src[trips[0].dest - 1]        = trips[0].start;
    company[trips[0].dest - 1]    = trips[0].brand;

    cout << "Edge: " << "0" << " uid: " << trips[0].start << " vid " <<  trips[0].dest << " cost " << trips[0].cost << endl;

    // for destination 1 -> n loop through each stop
    for (int i = 1; i < nTrips; i++) {
        // find starting and ending points
        int shopUID = trips[i].start - 1;
        int shopVID = trips[i].dest - 1;
        cout << "u, v" << shopUID << " " << shopVID << endl;

        // if the route starts from the starting point
        if (shopUID == 0) {
            // check if destination has a best cost
            if (bestCostAt[shopVID] == 0) {
                bestCostAt[shopVID] = trips[i].cost;
                src[shopVID]        = trips[i].start;
                company[shopVID]    = trips[i].brand;
                cout << "Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
            } else {
                cout << "This one should be normal num Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
            }
        } else if (bestCostAt[shopUID] == 0) {
            cout << "if this happen the algo is fucked" << " ";
            cout << "Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
        } else if (trips[i].cost + bestCostAt[shopUID] < bestCostAt[shopVID]) {
            bestCostAt[shopVID] = trips[i].cost + bestCostAt[shopUID];
            src[shopVID]        = trips[i].start;
            company[shopVID]    = trips[i].brand;

            cout << "Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
        }
    }

    for (int i = 1; i < numShops; i++) {
        cout << "Best Costs: " << bestCostAt[i];
    }

    return bestCostAt[numShops - 1];
}

int main() {
    vector<Trip> trips;
    int n = 4;


    vector<int> src(n, 0);
    vector<int> company(n, 0);

    struct Trip iter;

    iter = { 1, 1, 2, 41 };
    trips.push_back(iter);
    iter = { 1, 1, 3, 97 };
    trips.push_back(iter);
    iter = { 3, 2, 3, 53 };
    trips.push_back(iter);
    iter = { 1, 1, 4, 160 };
    trips.push_back(iter);
    iter = { 1, 2, 4, 106 };
    trips.push_back(iter);
    iter = { 1, 3, 4, 49 };
    trips.push_back(iter);

    srand(unsigned(time(0)));

    random_shuffle(trips.begin(), trips.end());


    sort(trips.begin(), trips.end(), compareDistance);

    int costRes = minCost(trips, src, company, n);
    cout << "Shortest cost: " << costRes << endl;

    for (int i = 1; i < n; i++) {
        cout << "Use company " << company[i] << " from location " << src[i] << " to location " << src[i + 1] << endl;

        // cout << " From : " << src[i];
        // cout << " Company: " << company[i] << endl;
    }
}
