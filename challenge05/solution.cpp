/*
 Challenge 04/05: Graph Paths
 Signature: Om Patel opatel11
 
 Description: Using a DFS traversal, determine if a request for
 a route exists in a given map of routes
 */


#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

// Recursive DFS function that checks if a value is reachable from a key
bool DFS(unordered_map<char, vector<char>>& routesMap, char key, char value, unordered_set<char>& visited) {
    // If the desination is the same as the origin, return true
    if (key == value) {
        return true;
    }

	visited.insert(key);

    // search map for route
    if (routesMap.find(key) != routesMap.end()) {
        for (char neighbor : routesMap[key]) {
            // Continue DFS if the neighbor hasn't been visited yet
            if (visited.find(neighbor) == visited.end()) {
                if (DFS(routesMap, neighbor, value, visited)) {
                    return true;
                }
            }
        }
    }

    // If route is not found, return false
    return false;
}

int main() {
    
    unordered_map<char, vector<char>> routesMap;

    // declare variables
    int edges;
    int graphCount = 1;

    
    while (cin >> edges) {
        // Insert route source and destination pair into map
        for (int i = 0; i < edges; i++) {
            char key, value;
            cin >> key >> value;
            routesMap[key].push_back(value);
        }

        // Number of searches to perform
        int requests;
        cin >> requests;
        
        // Vector holding requested source and destination data
        vector <char> keysVector;
        vector <char> valuesVector;

        // Insert route request data into vectors
        for (int i = 0; i < requests; i++) {
            char key, value;
            cin >> key >> value;
            keysVector.push_back(key);
            valuesVector.push_back(value);
        }
        
        // perform DFS search and output results
        for (int i = 0; i < requests; i++) {
            unordered_set<char> visited;  
            if (DFS(routesMap, keysVector[i], valuesVector[i], visited)) {
                cout << "In Graph " << graphCount << " there is a path from " << keysVector[i] << " to " << valuesVector[i] << endl;
            } else {
                cout << "In Graph " << graphCount << " there is no path from " << keysVector[i] << " to " << valuesVector[i] << endl;
            }
        }

        // Clear data structures for the next graph
        routesMap.clear();
        keysVector.clear();
        valuesVector.clear();

        cout << endl;
        // Increment number of graphs
        graphCount++;

	}
    return 0;
}






