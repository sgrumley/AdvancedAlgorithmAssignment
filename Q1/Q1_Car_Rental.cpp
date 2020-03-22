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
struct Trip{
	int brand;
	int start;
	int dest;
	int cost;
};

int minCost(vector<Trip> &trips, int n){
	// Lookup array for costs
	int numShops = 4;
	int bestCostAt[4] = {0};

	// initiate best cost for getting to stop 1
	bestCostAt[trips[0].dest - 1] = trips[0].cost;
	cout << "Edge: " << "0" << " uid: " << trips[0].start<< " vid " <<  trips[0].dest << " cost " << trips[0].cost << endl;

	for (int i = 1; i < n; i++){
		// find starting and ending points
		int shopUID = trips[i].start - 1;
		int shopVID = trips[i].dest - 1;

		// if the route starts from the starting point
		if (shopUID == 0){
			// check if destination has a best cost
			if (bestCostAt[shopVID] == 0){
				bestCostAt[shopVID] = trips[i].cost;
				cout << "Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
			} else {
				cout << "This one should be normal num Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
			}

		} else if (bestCostAt[shopUID] == 0){
			cout << "if this happen the algo is fucked" << " ";
			cout << "Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
		} else if (trips[i].cost + bestCostAt[shopUID] < bestCostAt[shopVID]){
			bestCostAt[shopVID] = trips[i].cost + bestCostAt[shopUID];
			cout << "Edge: " << i << " uid: " << trips[i].start << " vid " <<   trips[i].dest << " cost " << bestCostAt[shopVID] << endl;
		}


		// check the best path to the start node (lookup)
	}
	
	for (int i = 0; i<numShops; i++){
		cout << "final check" << bestCostAt[i] << endl;
	}

	return bestCostAt[numShops - 1];
}

int main (){

	vector<Trip> trips;
	int n = 6;

	struct Trip iter;
	
	iter = {1, 1, 2, 41};
	trips.push_back(iter);
	iter = {1, 1, 3, 97};
	trips.push_back(iter);
	iter = {1, 2, 3, 53};
	trips.push_back(iter);
	iter = {1, 1, 4, 160};
	trips.push_back(iter);
	iter = {1, 2, 4, 106};
	trips.push_back(iter);
	iter = {1, 3, 4, 49};
	trips.push_back(iter);
	
	int costRes = minCost(trips, n);
	cout << "Shortest cost: " << costRes << endl;
	
	//TODO: save path (ref to previous company and station)
	//TODO: test new data sets with other companies
	//TODO: Find unique data for testing (some companies done visit certain stations ..)

}