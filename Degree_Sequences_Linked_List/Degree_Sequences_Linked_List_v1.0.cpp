// David Murphy
// 09/19/17
// Discrete Math Practice
// v1.0

/*
 *	A degree sequence is a sequence of integers that represents the degrees of each vertex
 *	in an undirected graph.
 *	 	To be a degree sequence, the following two cases must be true:
 *			1) Handshaking Theorem: The sum of the degrees of all the vertices is exactly
 *			TWICE the total number of edges.
 *			2) Every non-increasing degree sequence of non-negative integers that has an 
 *			EVEN NUMBER OF ODD TERMS is the degree sequence of an undirected graph.
 *
 *	The position of the vertices along the linked list is contingent on their assigned degree.
 *  The vertices will arrange from that of highest degree to lowest.
*/

#include <iostream>
using namespace std;

struct vertex {
	char label;
	int d1;

	vertex * next;
}; // struct vertex

vertex * createList() {
	vertex*phead = new vertex;
	(*phead).d1=0;
	(*phead).next=0;
	return phead;
} // vertex * createList()

/*	Prints the amount of vertices, and the vertex label along with 
 *  its degree in a list on a single line. The order is determined by the 
 *  order of the link list, from head -> tail.
 *	
 *	Calls functions:
 *	
 */
void printList(vertex * head) {
	cout << endl << "List contains " << (*head).d1 << " vertices: ";

	if((*head).next!=0) {
		vertex * temp = (*head).next;
		cout << (*temp).label << "(" << (*temp).d1 << ") ";

	while ((*temp).next!=0) {
		temp = (*temp).next;
		cout << (*temp).label << "(" << (*temp).d1 << ") ";
		}
	}

	cout << endl << endl;
} // void printList(vertex * phead)

void advance(vertex *& ptr) {
ptr = (*ptr).next;
} // void advance(vertex *& ptr)

/* In order to insert new node, this function requires the passage of the node 
 * into the function that will be BEFORE the desired node to be inserted.
*/
void insert(vertex * pred, vertex * newVertex, vertex * head) {
	(*newVertex).next = (*pred).next;
	(*pred).next = newVertex;
	(*head).d1++;
} // void insert(vertex * pred, vertex * newVertex, vertex * phead)

/* The position of the vertices along the linked list is contingent on their assigned degree.
 * The vertices will arrange from that of highest degree to lowest.
 *
 *	Calls functions:
 *		- advance()
 *		- insert()
*/
void insertInOrder(vertex * newvertex, vertex * head) {
	vertex*pred = head;
	// int i = the degree value of the newly inserted vertex.
	int i = (*newvertex).d1;
	vertex*succ = (*pred).next;

	//search
	while(succ!= 0 && i <= (*succ).d1) {
		advance(pred);
		advance(succ);
	}

	insert(pred, newvertex, head);
} // void insertInOrder(vertex * newvertex, vertex * head)

/* Checks if degree sequence: the sum of degrees is even 
 * 
 *	Calls functions:
 *		- advance()
*/
bool isDegreeSequence(vertex * head) {
	vertex*temp = new vertex;
	temp=(*head).next;
	
	int i = (*temp).d1;

	// loop through list, accumulating the total degree value of each vertex in graph
	while ((*temp).next !=0) { 
		advance(temp);
		i = i + (*temp).d1;
	}
	
	// RETURN FALSE: if SUM of degrees of graph is ODD
	if(i%2 !=0) {return false;}
	// RETURN TRUE: else SUM of degrees is EVEN
	else {return true;}
} // bool isListDegreeEven(vertex * head)

void main(){
	cout << "v1.0" << endl;
	cout << "David Murphy - Discrete Math Practice - 09/19/17" << endl;
	cout << "Is your degree sequence a valid sequence for an undirected graph?" << endl << endl;
	
	char label='.';
	int deg;
	bool degBool;

	// Initialize list: (*phead).d1 is the total # of vertices
	vertex*phead = createList();
	
	// PROMPT USER INPUT
	while(label != '/') {
		// create new vertex
		vertex*newvertex = new vertex;
		
		// prompt for vertex label and degree #
		cout << "Label a vertex using one character: ";
		cin >> label;

		// A '/' input terminates the selection interface prompt
		if(label=='/'){break;}
		cout << "Insert the vertex's degree (deg>0): ";
		cin >> deg;

		// Prompt if input is 0
		while(deg==0){
			cout << endl;
			cout << "ERROR: degree must be > 0: ";
			cin >> deg;
		} // nested while
		
		// assign values to vertex; insert vertex into list
		(*newvertex).d1=deg;
		(*newvertex).label=label;
		insertInOrder(newvertex, phead);

		// Print
		printList(phead);

		// // Prompt termination option
		cout << "[Type '/' when finished]" << endl;
	} // while

	cout << endl;

	// Check whether first list is a graphic sequence
	degBool = isDegreeSequence(phead);
	
	// YES
	if((*phead).d1>0 && degBool) {
		cout << "******************************************************************" << endl;
		cout << "* YES! This is a valid degree sequence for an UNDIRECTED graph. *" << endl;
		cout << "******************************************************************" << endl;
	} else { // NO
		cout << "*********************************************************************" << endl;
		cout << "* NO! This is NOT a valid degree sequence for an UNDIRECTED graph. *" << endl;
		cout << "*********************************************************************" << endl;
	}

	cout << endl;
} // main()