// merge.cpp
// Team: Vansh Joshi, Om Patel, Sarvvesh Vindokumar
// Date: 9/18/2024

#include "volsort.h"
#include <iostream>
using namespace std;

// credit to Dr.Scott for providing pseudo code given in class to help me complete this program
// credit to geeksforgeeks for helping me how to merge 2 lists
// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

// Prototypes
Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations
void merge_sort(List &l, bool numeric) {
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {
    Node* current = head;
    Node* leftHalf;
    Node* rightHalf;

    // base care - list is empty or has 1 element
    if ((current == NULL) || (current->next == NULL)) {
        return current;
    }

    // splits the list into 2 sublists
    split(current, leftHalf, rightHalf);

    // sorting the 2 sublists recursively
    leftHalf = msort(leftHalf, numeric);
    rightHalf = msort(rightHalf, numeric);

    // merges the 2 lists into 1
    return merge(leftHalf, rightHalf, numeric);
}

void split(Node *head, Node *&left, Node *&right) {
    Node* slow;
    Node* faster;
    slow = head;
    faster = head->next;

    // moves the faster pointer 2 steps and the slow pointer 1 step
    while (faster != NULL) {
        faster = faster->next;
        if (faster != NULL) {
            faster = faster->next;
            slow = slow->next;
        }
    }

    // spliting the list at the slow pointer
    left = head;
    right = slow->next;
    slow->next = NULL;
}

Node *merge(Node *left, Node *right, bool numeric) {
    if (left == NULL) {
        return right;
	}
    if (right == NULL) {
        return left;
    }

    Node* combined = NULL;

	if (numeric) {

         // comparing the numbers for numeric sorting
		if (left->number < right->number) {
			combined = left;
			combined->next = merge(left->next, right, numeric);
        } else {
			combined = right;
			combined->next = merge(left, right->next, numeric);
		}

	} else {
		if (left->string < right->string) {
			combined = left;
			combined->next = merge(left->next, right, numeric);
		} else {
			combined = right;
			combined->next = merge(left, right->next, numeric);
		}
	}
    return combined;
}
