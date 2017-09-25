// David Murphy
// 09/19/17
// Discrete Math Practice

/*
	A degree sequence is a sequence of integers that represents the degrees of each vertex
	in an undirected graph.
		To be a degree sequence, the following two cases must be true:
			1) Handshaking Theorem: The sum of the degrees of all the vertices is exactly
			TWICE the total number of edges.
			2) Every non-increasing degree sequence of non-negative integers that has an 
			EVEN NUMBER OF ODD TERMS is the degree sequence of an undirected graph.
*/

#include <iostream>
using namespace std;

struct node {
	char label;
	int d1;

	node * next;
}; // node

node * createList() {
	node*phead = new node;
	(*phead).d1=0;
	(*phead).next=0;
	return phead;
}

// prints amount of nodes, and the vertex label along with its degree in a list on a 
// single line.
void printList(node * head) {
	cout << endl << "List contains " << (*head).d1 << " vertices: ";

	if((*head).next!=0) {
		node * temp = (*head).next;
		cout << (*temp).label << "(" << (*temp).d1 << ") ";

	while ((*temp).next!=0) {
		temp = (*temp).next;
		cout << (*temp).label << "(" << (*temp).d1 << ") ";
		}
	}

	cout << endl << endl;
} // void printList(node * phead)

void advance(node *& ptr) {
ptr = (*ptr).next;
} // void advance(node *& ptr)

void insert(node * pred, node * newNode, node * head) {
	(*newNode).next = (*pred).next;
	(*pred).next = newNode;
	(*head).d1++;
} // void insert(node * pred, node * newNode, node * phead)

void insertInOrder(node * newNode, node * head) {
	node*pred = head;
	int i = (*newNode).d1;
	node*succ = (*pred).next;

	//search
	while(succ!= 0 && i < (*succ).d1) {
		advance(pred);
		advance(succ);
	}

	insert(pred, newNode, head);
} // void insertInOrder(node * newNode, node * head)

// Add the # of degrees from each node (vertex) in list
bool isListDegreeEven(node * head) {
	node*temp = new node;
	temp=(*head).next;
	
	int i = (*temp).d1;

	while ((*temp).next !=0) { // loop through list until last node
		temp = (*temp).next;
		i = i + (*temp).d1;
	}
	
	// if sum of degrees is even
	if(i%2 !=0) {return false;}
	// else sum of degrees is odd
	else {return true;}
} // bool isListDegreeEven(node * head)

void remove(node * pred, node * head) {
	node * elim = (*head).next;
	
	cout << "Deleting vertex " << (*elim).label << ": deg = " << (*elim).d1 << endl << endl;
	(*pred).next = (*elim).next;
	delete elim;

	(*head).d1--;
} // void remove(node * pred, node * head)

void main(){
	cout << "David Murphy - Discrete Math Practice - 09/19/17" << endl;
	cout << "Is your degree sequence a valid sequence for an undirected graph?" << endl << endl;
	
	char label='.';
	int deg;
	bool degEven;

	// Initialize list: (*phead).d1 is the total # of vertices
	node*phead = createList();
	
	// PROMPT USER INPUT
	while(label != '/') {
		// create new node
		node*newNode = new node;
		
		// prompt for vertex label and degree #
		cout << "Label a vertex using one character: ";
		cin >> label;

		if(label=='/'){break;}
		cout << "Insert the vertex's degree (deg>0): ";
		cin >> deg;

		// Prompt if input is 0
		while(deg==0){
			cout << endl;
			cout << "ERROR: degree must be > 0: ";
			cin >> deg;
		}
		
		// assign values to node; insert node into list
		(*newNode).d1=deg;
		(*newNode).label=label;
		insertInOrder(newNode, phead);

		// Print
		printList(phead);
		cout << "[Type '/' when finished]" << endl;
	} // while

	cout << endl;

	// Check whether first list is a graphic sequence
	degEven = isListDegreeEven(phead);
	
	// YES
	if((*phead).d1>0 && degEven) {
		cout << "******************************************************************" << endl;
		cout << "* YES! This is a valid graphic sequence for an UNDIRECTED graph. *" << endl;
		cout << "******************************************************************" << endl;
	} else { // NO
		cout << "*********************************************************************" << endl;
		cout << "* NO! This is NOT a valid graphic sequence for an UNDIRECTED graph. *" << endl;
		cout << "*********************************************************************" << endl;
	}

	cout << endl;
} // main()