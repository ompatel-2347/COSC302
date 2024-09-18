// list.cpp
// Team: Vansh Joshi, Om Patel, Sarvvesh Vindokumar
// Date: 9/18/2024

// credit to Zack for helping me fix the memory issues I was having, and telling me how to implement the while loop in the destructor
// credit to Vansh Joshi for providing old code from 202 linked list lab to help finish this code

#include "volsort.h"

#include <iostream>
#include <string>
using namespace std;


List::List() {
    head = NULL;
    size = 0;
}

List::~List() {
    Node *current = head;

    // go through the list and delete each node
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;

    // reset the size to 0
    size = 0;
}

// adds a new node to the front of the list
void List::push_front(const std::string &s){
    Node* newNode = new Node;
    newNode->string =  s;
    newNode->number = stoi(s);
    newNode->next = head;
    head = newNode;
    size++;
}

// compares nodes based on the number value
bool node_number_compare(const Node *a, const Node *b){
    return a->number < b->number;
}

// compares nodes based on the string value
bool node_string_compare(const Node *a, const Node *b){
    return a->string < b->string;
}
