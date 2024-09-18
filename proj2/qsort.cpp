// qsort.cpp
// Team: Vansh Joshi, Om Patel, Sarvvesh Vindokumar
// Date: 9/18/2024

// credit to geeksforgeeks for helping me understand the difference between sort and qsort
// and how to implement the algorithm
//https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
// used code from stl.cpp to finish this program
// credit to nachtimwald for show me how to make comparison functions
// https://nachtimwald.com/2018/11/27/general-comparison-functions-in-c/

#include "volsort.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// compares the nodes numerically
int compareNumeric(const void *a, const void *b) {
    const Node* node1 = *(const Node**)a;
    const Node* node2 = *(const Node**)b;

    if (node1->number < node2->number) return -1;
    if (node1->number > node2->number) return 1;
    return 0;

}

// compares the nodes lexicographically
int compareLexicographic(const void *a, const void *b) {
    const Node* node1 = *(const Node**)a;
    const Node* node2 = *(const Node**)b;

    string string1 = node1->string;
    string string2 = node2->string;

    if (string1 < string2) return -1;
    if (string1 > string2) return 1;
    return 0;
}

// sort the list using qsort
void qsort_sort(List &l, bool numeric){
	vector<Node*> nodeVec(l.size);

    // populating the vector with node pointers
    Node* current = l.head;
    for (size_t i = 0; i < l.size; i++) {
        nodeVec[i] = current;
        current = current->next;
    }

    // sorting the vector
    if (numeric) {
        qsort(nodeVec.data(), l.size, sizeof(Node*), compareNumeric);
    } else {
        qsort(nodeVec.data(), l.size, sizeof(Node*), compareLexicographic);
    }

    // relink the nodes based on the sorted order
    for (size_t i = 0; i < l.size - 1; i++) {
        nodeVec[i]->next = nodeVec[i + 1];
    }
    nodeVec[l.size - 1]->next = NULL;

    // update the head of the list
    l.head = nodeVec[0];
}
