#include "Deque.h"
#include<iostream>
using namespace std;

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	head = tail = nullptr; // initially, there is no head and tail, meaning the deque is empty
	noOfItems = 0;         // number of items is zero
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	while (tail != nullptr) { // removes items from the rear as long as there is a tail node in the deque
		RemoveRear();
	}
	noOfItems = 0;          // resets the number of items to zero
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	DequeNode* newNode = new DequeNode(item); // creates a new node
	if (head == nullptr || tail == nullptr) { // if the deque is empty, the new node becomes the head and tail
		head = tail = newNode;
	}
	else {
		newNode->prev = nullptr;              // the previous link of the new node is null
		newNode->next = nullptr;              // the next link of the new node is null
		newNode->next = head;                 // connects the next link of the new node to the head
		head->prev = newNode;                 // connects the previous link of the old head to the new node
		head = newNode;                       // sets the new node as the head
	}
	noOfItems++;                              // increases the number of items by one
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	DequeNode* newNode = new DequeNode(item);
	if (head == nullptr || tail == nullptr) {
		head = tail = newNode;
	}
	else {
		newNode->prev = nullptr;              // the previous link of the new node is null
		newNode->next = nullptr;              // the next link of the new node is null
		newNode->prev = tail;                 // connects the previous link of the new node to the tail
		tail->next = newNode;                 // connects the next link of the old tail to the new node
		tail = newNode;                       // sets the new node as the tail
	}
	noOfItems++;
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	if (head == nullptr || tail == nullptr) { // if the deque is empty, prints an error message
		cerr << "Deque is empty!";
		return -1;                            // returns an error value
	}

	int value = head->item;                   // gets the value of the removed node
	head = head->next;                        // moves the head to the next node
	if (head != nullptr) {
		head->prev = nullptr;                 // resets the previous link of the new head
	}
	else {
		tail = nullptr;                       // if the deque is empty, also resets the tail
	}

	noOfItems--;                              // decreases the number of items by one
	return value;                             // returns the removed value
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	if (head == nullptr || tail == nullptr) {
		cerr << "Deque is empty!";
		return -1;
	}

	int value = tail->item;                   // gets the value of the removed node
	tail = tail->prev;                        // moves the tail to the previous node
	if (tail != nullptr) {
		tail->next = nullptr;                 // resets the next link of the new tail
	}
	else {
		head = nullptr;                       // if the deque is empty, also resets the head
	}

	noOfItems--;
	return value;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	if (head == nullptr || tail == nullptr) { // if the deque is empty, prints an error message
		cerr << "Deque is empty!";
		return -1;                            // returns an error value
	}
	int value = head->item;                   // gets the value of the head
	return value;                             // returns the value
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	if (head == nullptr || tail == nullptr) {
		cerr << "Deque is empty!";
		return -1;
	}
	int value = tail->item;                   // gets the value of the tail
	return value;                             // returns the value
} //end-Rear