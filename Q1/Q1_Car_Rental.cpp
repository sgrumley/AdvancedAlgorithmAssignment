#include <bits/stdc++.h>

#define MAX 999

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

int minCost(vector<Trip>& trips, vector<int>& src, vector<int>& company,  vector<int>& bestCostAt, int n) {
    int nTrips = trips.size();

    for (int i = 0; i < n + 1; i++) {
        bestCostAt[i] = MAX;
    }

    // initiate best cost for getting to stop 1
    bestCostAt[trips[0].dest] = trips[0].cost;
    src[trips[0].dest]        = trips[0].start;
    company[trips[0].dest]    = trips[0].brand;

    // Loop through each trips information
    for (int i = 1; i < nTrips; i++) {
        // find starting and ending points
        int shopUID = trips[i].start;
        int shopVID = trips[i].dest;

        if (shopUID == 1) {
            // If the starting point of the trip is the starting point of the journey
            if ((bestCostAt[shopVID] == MAX) || (bestCostAt[shopVID] > trips[i].cost)) {
                // If the destination does not yet have a best cost
                bestCostAt[shopVID] = trips[i].cost;
                src[shopVID]        = trips[i].start;
                company[shopVID]    = trips[i].brand;
            }
        }  else if ((trips[i].cost + bestCostAt[shopUID] < bestCostAt[shopVID]) || (bestCostAt[shopVID] == MAX)) {
            // If the current trips cost + the total cost to the town its leaving from
            // is smaller than the current best cost for the destination ? update best cost
            bestCostAt[shopVID] = trips[i].cost + bestCostAt[shopUID];
            src[shopVID]        = trips[i].start;
            company[shopVID]    = trips[i].brand;
        }
    }

    for (int i = 2; i < n + 1; i++) {
        cout << " Best Costs: " << bestCostAt[i];
    } cout << endl;

    return bestCostAt[n];
}

int main() {
    int n = 4;
    vector<Trip> trips;
    vector<int>  src(n + 1, 0);
    vector<int>  company(n + 1, 0);
    vector<int>  bestCostAt(n + 1, 0);


    // Test data
    srand(unsigned(time(0)));
    struct Trip iter;

    vector<int> d;

    /* Comment this section for constant data  */
    for (int i = 0; i < 10; i++) {
        iter.brand = (rand() % 100 + 1);
        iter.cost  = (rand() % 900 + 1);
        int h = (rand() % n + 1);

        if (h == 1) {
            h++;
            iter.dest = h;
        } else {
            iter.dest = h;
        }

        if (h <= 2) {
            iter.start = 1;
        } else {
            h--;
            iter.start = (rand() % h + 1);
        }

        trips.push_back(iter);
    }

    /* Comment this section for constant data  */

    // Uncomment this section for constant data - test case
    // iter = { 1, 1, 2, 41 };
    // trips.push_back(iter);
    // iter = { 1, 1, 3, 97 };
    // trips.push_back(iter);

    // iter = { 3, 2, 3, 53 };
    // trips.push_back(iter);
    // iter = { 1, 1, 4, 160 };
    // trips.push_back(iter);
    // iter = { 1, 2, 4, 106 };
    // trips.push_back(iter);

    // iter = { 6, 3, 4, 49 };
    // trips.push_back(iter);
    // random_shuffle(trips.begin(), trips.end());


    sort(trips.begin(), trips.end(), compareDistance);

    // Print test data
    cout << "Test data: " << endl;

    for (int i = 0; i < trips.size(); i++) {
        cout << trips[i].brand << " " << trips[i].start << " " << trips[i].dest << " " << trips[i].cost  << endl;
    } cout << endl;

    int costRes = minCost(trips, src, company, bestCostAt, n);

    // connect the dots
    vector<int> path;
    vector<int> companies;
    int cost = 0;
    int j;
    j = n;

    while (j > 1) {
        path.push_back(src[j]);
        companies.push_back(company[j]);
        j = src[j];
    }

    cout << "Min cost: " << bestCostAt[n] << endl;
    reverse(path.begin(),      path.end());
    reverse(companies.begin(), companies.end());

    cout << "Location path: " << endl;

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    } cout << n << endl;

    cout << "Companies to use: " << endl << "  ";

    for (int i = 0; i < path.size(); i++) {
        cout << companies[i] << " ";
    }
}
