// stl.cpp
// Team: Vansh Joshi, Om Patel, Sarvvesh Vindokumar
// Date: 9/18/2024

// credit to geeksforgeeks for helping me understand how to implement this algorithm
// https://www.geeksforgeeks.org/sort-c-stl/

#include <string>
#include "volsort.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void stl_sort(List &l, bool numeric) {
	// store pointers to nodes
    vector<Node*> nodeVec;
	int list_length = l.size; 

	// fill the vector with node pointer
    for (Node* current = l.head; current != NULL; current = current->next) {
		nodeVec.push_back(current);
    }

	// sort the vector based on the comparison type
	if (numeric == true) {
		sort(nodeVec.begin(), nodeVec.end(), node_number_compare);
	} else {
		sort(nodeVec.begin(), nodeVec.end(), node_string_compare);
	}

	// rebuild the linked list with the sorted order
    for (int i = 0; i < list_length; i++){
		nodeVec[i]->next = nodeVec[i + 1];
	}
	nodeVec[list_length - 1]->next = NULL;

	//updating the head of the list
	l.head = nodeVec[0];
}

