// David Murphy
// 09/25/17
// Discrete Math Practice

/*
 *	A graphic sequence is a sequence of integers that is the degree sequence
 *	of a SIMPLE undirected graph; that is, the graph does NOT contain loops and/or multiple edges.
 *		To be a graphic sequence, the following two cases must be true:
 *			1) Handshaking Theorem: The sum of the degrees of all vertices in an undirected graph 
 *			is exactly TWICE the total number of the graph's edges.
 *			2) Every non-increasing degree sequence of non-negative integers that has an 
 *			EVEN NUMBER OF ODD TERMS is the degree sequence of an undirected graph.
 *			3) In any simple graph, if a vertex has a quantity of degrees that exceeds 
 *			the # of other verticies, then it CANNOT be SIMPLE; 'simple' denotes a graph that 
 *			does NOT consist of loops and multiple edges.
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

/* Prints the amount of vertices, and the degree value of each vertex in the list on a 
 * single line. The order is determined by the order of the link list, from head -> tail.
 */
void printList(vertex * head) {
	cout << endl << "List now contains " << (*head).d1 << " vertices with available endpoints: ";

	if((*head).next!=0) {
		vertex * temp = (*head).next;
		cout << (*temp).label << "(" << (*temp).d1 << ") ";

		while ((*temp).next!=0) {
			temp=(*temp).next;
			cout << (*temp).label << "(" << (*temp).d1 << ") ";
			}
	} //if

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
} // void insert(vertex * pred, vertex * newvertex, vertex * phead)

/* The position of the vertices along the linked list is contingent on their assigned degree.
 * The vertices will arrange from that of highest degree to lowest.
 *
 *	Calls functions:
 *		- advancd()
 *		- insert()
*/
void insertInOrder(vertex * newVertex, vertex * head) {
	vertex*pred = head;
	// int i = the degree value of the newly inserted vertex. 
	int i = (*newVertex).d1;
	vertex*succ = (*pred).next;

	//search: while a vertex is ahead of pred, and that vertex is less than succ.d1
	while(succ!= 0 && i <= (*succ).d1) { 
		advance(pred);
		advance(succ);
	}

	insert(pred, newVertex, head);
} // void insertInOrder(vertex * newVertex, vertex * head)

/* Checks if degree sequence: the sum of degrees is even 
 * 
 *	Calls functions:
 *		- advance()
*/
bool isDegreeSequence(vertex * head) {
	
	// RETURN FALSE: No vertices remain, which means that the edges of each vertex found a neighbor
	if((*head).next==0){
		cout << "No vertices remain!" << endl;
		return false;
	}
	
	vertex*temp = new vertex;
	temp=(*head).next;
	
	int i = (*temp).d1;
	
	// loop through list, incrementing the degree value of each vertex in graph
	while ((*temp).next !=0) { 
		advance(temp);
		i = i + (*temp).d1;
	}

	// RETURN FALSE: if SUM of degrees of graph is ODD
	if(i%2 !=0) {return false;}
	// RETURN TRUE: else SUM of degrees is EVEN
	else {return true;}
} // isDegreeSequence(vertex * head)

void printIfDegree(bool degBool) {
	// YES, is a degree sequence
	if(degBool) {
		cout << "*****************************************************************" << endl;
		cout << "* YES! This is a valid DEGREE sequence for an UNDIRECTED graph. *" << endl;
		cout << "*****************************************************************" << endl << endl;
	} 
	else { // NO, is NOT a degree sequence
		cout << "********************************************************************" << endl;
		cout << "* NO! This is NOT a valid DEGREE sequence for an UNDIRECTED graph. *" << endl;
		cout << "********************************************************************" << endl << endl;
	}
} // void checkIfDegree(bool degBool)

void printIfGraphic(bool graphBool) {
	// YES, is a graphic sequence
	if(graphBool) {
		cout << "******************************************************************" << endl;
		cout << "* YES! This is a valid GRAPHIC sequence for an UNDIRECTED graph. *" << endl;
		cout << "******************************************************************" << endl << endl;
	} else { // NO, is NOT a graphic sequence
		cout << "*********************************************************************" << endl;
		cout << "* NO! This is NOT a valid GRAPHIC sequence for an UNDIRECTED graph. *" << endl;
		cout << "*********************************************************************" << endl << endl;
	}
} // void checkIfGraphic(bool graphBool)

/* Checks if graphic sequence: the first vertex's degree quantity does NOT exceed available vertices
 * 
 *	Calls functions:
 *
*/
bool isGraphicSequence(vertex * head) {
	vertex * succ = (*head).next;
	
	// RETURN TRUE: if the first vertex's degree quantity is less than available vertices
	if((*succ).d1<(*head).d1) {
		return true;
	}
	// RETURN TRUE: else if verticies with available endpoints do NOT exist
	else if((*head).d1==0) {
		return true;
	}
	else{return false;}
} // bool isGraphicSequence(vertex * head)

/* MUST CHECK: 
 *	- if degree sequence: the sum of degrees is even  
 *  - if graphic sequence: the first vertex's degree quantity does NOT exceed available vertices
 *	
 * Calls functions:
 *		- isDegreeSequence()
 *		- isGraphicSequence()
 *		- printIfDegree()
 *		- printIfGraphic()
*/	
bool checkIfValidSequence(vertex * head) {
	bool degBool, graphBool;
	
	degBool = isDegreeSequence(head);  
	graphBool = isGraphicSequence(head);
	printIfDegree(degBool);
	printIfGraphic(graphBool);

	if(degBool && graphBool){
		return true;
	} else{
		return false;
	}
} // bool checkIfValidSequence(vertex * head)

/* Assumes that the sequence is a valid Graphic Sequence: 
 *  In other words, assumes that the degree of a vertex < amount of available vertices 
 *  (checked beforehand in function connectVertices())
 *  
 *  Calls functions:
 *		- advance()
*/
void decrementSequence(vertex * pred, vertex * head) {
	vertex*dec=(*pred).next;
	vertex*succ=(*dec).next;
	int degNum = (*dec).d1;

	// Prompt message to indicate connection of first vertex
	cout << endl << "Attempting to connect vertex " << (*dec).label << "(" << degNum << ")" 
		<< " to the " << (*head).d1 -1 << " other vertices:" << endl;
	
	(*dec).d1=0;
	(*head).d1--;

	for(int i=0; i<degNum; i++) {
		
		(*succ).d1--;

		if((*succ).d1==0) {
			(*head).d1--;
		}

		advance(succ);
	}
} // void decrementSequence(vertex * pred, vertex * head)

/* 	Calls functions: 
 *		- checkIfValidSequence()
 *		- decrementSequence()
 *		- advance()
 *		- printList()
*/
void connectVertices(vertex * head) {
	vertex*pred=head;
	// succ (successor) = biggest vertex that will be connected to other verticies
	vertex*succ=(*pred).next;
	int numVertices = (*head).d1;
	bool endConnecting = false;

	// Check if sequence is BOTH a valid degree AND graphic sequence
	bool seqIsValid = checkIfValidSequence(head);

	// Decrement sequence while sequence check == true, and while a vertex contains 
	// available endpoints 
	while(seqIsValid && !endConnecting) {
		decrementSequence(pred, head);
		
		// Skip verticies that do NOT contain available endpoints
		while((*succ).d1==0){
			advance(pred);
			advance(succ);

			// If recently targeted vertex is the last remaining vertex; break both loops 
			if((*succ).next==0){
				endConnecting=true;
				break;
			}
		} // nested while
		
		// print
		printList(head);
		// check if list is still a valid degree/graphic sequence
		seqIsValid=checkIfValidSequence(head);
		// advance onto next vertex
		
	} //while
		
} // void connectEdges(vertex * head)

void main(){
	cout << "David Murphy - Discrete Math Practice - 09/19/17" << endl;
	cout << "Is your degree sequence a graphic sequence?" << endl << endl;
	
	char label='.';
	int deg;
	bool degBool;
	bool graphBool;

	// Create list head: (*phead).d1 is the total # of vertices
	vertex*phead = createList();
	
	// PROMPT USER INPUT
	while(label != '/') {
		// create new vertex
		vertex*newvertex = new vertex;
		
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
		
		// assign values to new vertex; insert vertex into list
		(*newvertex).d1=deg;
		(*newvertex).label=label;
		insertInOrder(newvertex, phead);

		// Print list
		printList(phead);

		// Prompt termination option
		cout << "[Type '/' when finished]" << endl;
	} // while

	cout << endl;
	
	connectVertices(phead); 
} // main()