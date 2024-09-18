// quick.cpp
// Team: Vansh Joshi, Om Patel, Sarvvesh Vindokumar
// Date: 9/18/2024

// credit to Zack for helping me understand how quick sort works in lab, and helping me understand the partition function
// credit to geeksforgeeks for giving a deeper understanding of how quick sort works and the logic of it
// https://www.geeksforgeeks.org/quick-sort-algorithm/

#include "volsort.h"

#include <iostream>
#include <vector>
using namespace std;
// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    l.head=qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {
    Node *leftHalf = NULL;
    Node *rightHalf = NULL;

    // base case - list is empty or has only 1 element
    if ((head == NULL) || head->next == NULL) {
        return head;
    }

    // partition the list
    partition(head, head, leftHalf, rightHalf, numeric);

    // recursively sore the left and right partitions
    leftHalf = qsort(leftHalf,numeric);
    rightHalf = qsort(rightHalf,numeric);

    // disconnect the pivot from the rest of the list
    head->next=NULL;

    // concatenate the sorted parts with the the pivot in the middle
    leftHalf = concatenate(leftHalf,head);
    return concatenate(leftHalf,rightHalf);
}

//
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node *current = pivot->next;
    Node *rightTail = NULL;
    Node *leftTail = NULL;

    if (numeric) {

        // numeric comparisons
        while (current != NULL){
            if (current->number >= pivot->number) {

                // add to the right partition
                if (right == NULL) {
                    right = current;
                    rightTail = right;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
                else {
                    rightTail->next = current;
                    rightTail = rightTail->next;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
            }
            else {
                if (left == NULL) {
                    left = current;
                    leftTail = left;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
                else {
                    leftTail->next = current;
                    leftTail = leftTail->next;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
            }
        }
        if(left != NULL) {
            leftTail->next = NULL;
        }
        if(right != NULL){
            rightTail->next = NULL;
        }
    }
    else {

        // string comparison
        while (current != NULL){
            if (current->string.compare(pivot->string) >= 0) {

                // add to the right partition
                if (right == NULL) {
                    right = current;
                    rightTail = right;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
                else{
                    rightTail->next = current;
                    rightTail = rightTail->next;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
            }
            else {

                // add to the left partition
                if (left == NULL) {
                    left = current;
                    leftTail = left;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
                else {
                    leftTail->next = current;
                    leftTail = leftTail->next;
                    if (current->next == NULL){
                        break;
                    }
                    current = current->next;
                }
            }
        }

        // terminate the partitions
        if(left != NULL) {
            leftTail->next = NULL;
        }
        if(right != NULL){
            rightTail->next = NULL;
        }
    }
}

// concatenate the 2 linked lists
Node *concatenate(Node *left, Node *right) {
    if (left == NULL) {
        return right;
    }

    Node *tail = left;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = right;
    return left;
}

