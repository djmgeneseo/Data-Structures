// David Murphy
// CSC 244
// Project: List Manipulation
//		- Create a linked list of nodes
//		- Give the user complete control over that linked list
//		- Option to add integer, delete integer, delete all matching numbers, destroy the list, or quit
//		- All print statements print to both the console and a file named "ListManipulation.txt"

#include <iostream>
#include <fstream>
using namespace std;

// Declare fstream output for file as global
fstream myFile;

// node.d1 in phead is the node counter; otherwise, stores the value of node
// node.next points to the address of a node;
struct node {
int d1;
node * next;
}; // struct node

node * createList() {
node *phead = new node;
(*phead).d1 = 0;
(*phead).next = 0;
return phead;
} // node * createList()

void insert(node * pred, node * newNode, node * head) {
(*newNode).next = (*pred).next;
(*pred).next = newNode;
(*head).d1++;
} // void insert(node * pred, node * newNode, node * phead)

void advance(node *& ptr) {
ptr = (*ptr).next;
} // void advance(node *& ptr)

// prints amount of nodes, and the node.d1 values of each node in the list on a 
// single line.
void printList(node * head) {
myFile << endl << "List contains " << (*head).d1 << " node(s): ";
cout << endl << "List contains " << (*head).d1 << " node(s): ";

if((*head).next!=0) {
	node * temp = (*head).next;

	myFile << (*temp).d1 << " ";
	cout << (*temp).d1 << " ";

	while ((*temp).next!=0) {
		temp = (*temp).next;
		myFile << (*temp).d1 << " ";
		cout << (*temp).d1 << " ";
	}
} //if

myFile << endl << endl;
cout << endl << endl;
} // void printList(node * phead)

// Calls insert()
void insertInOrder(node * newNode, node * head) {
	node *pred = head;
	int i = (*newNode).d1;
	node * succ = (*pred).next;

	//search
	while(succ!= 0 && i >(*succ).d1) {
	//advance
	advance(pred);
	advance(succ);
	}

//insert
insert(pred, newNode, head);
} // void insertInOrder(node * newNode, node * phead)

// Print the value of and remove the node ahead of the 'pred' node.
// decrement head.d1
void remove(node * head, node * pred) {
	if ((*pred).next!=0) { // If there exists a node ahead of 'pred' to delete
		node *elim = (*pred).next;
		myFile << "Deleting: " << (*elim).d1 << endl;
		cout << "Deleting: " << (*elim).d1 << endl;
	
		(*pred).next = (*elim).next;
		delete elim;
		--(*head).d1;
	} 
	else {
		cout << endl << "No node to delete!" << endl;
		myFile << endl << "No node to delete!" << endl;
	}
} // remove(node * head, node * pred)

// remove() OVERLOAD
// Print the value of and remove the first node from the head node
void remove(node * head) {
	if ((*head).next!=0) {
		node *elim = (*head).next;
		cout << "Deleting: " << (*elim).d1 << endl;
		myFile << "Deleting: " << (*elim).d1 << endl;
		(*head).next = (*elim).next;
		delete elim;
		--(*head).d1;
	}
	else {
		cout << endl << "No node to delete!" << endl;
		myFile << endl << "No node to delete!" << endl;
	}
}

// Calls remove()
// Removes one sought integer (x) from the list
// Sends error message if the list does not contain the sougnt integer (x)
void removeOne(int x, node * head) {
	int numNodesDel = 0;
	int numNodes = (*head).d1;
	node *pred = (*head).next;
	
	for(int i = 0; i<numNodes; i++) { // search through the list
		node * elim = (*pred).next;
		
		if(i==0) { // on first loop
			if((*pred).d1==x){ // test first node
				remove(head);
				numNodesDel++;
				break;
			}
		}                                     
		
		if (i>0) { // move to next node on second run-through and thereafter
			if ((*elim).d1 == x) {
				remove(head, pred);
				numNodesDel++;
				break;
			}

			// No hit? move search down.
			pred = (*pred).next;
		}
		
	} //for

	if (numNodesDel > 0) {
		myFile << "Number of deleted nodes: " << numNodesDel << endl;
		cout << "Number of deleted nodes: " << numNodesDel << endl;
	}

	else {
		myFile << "No matching nodes were found" << endl << endl;
		cout << "No matching nodes were found" << endl << endl;
	}

} // removeOne(int x, node * head)

// Calls remove()
void removeAllMatching(int x, node * head) {
	int numNodesDel = 0;
	int numNodes = (*head).d1;
	node *pred = head;
	node * elim = (*pred).next;

	for(int i = 0; i<numNodes; i++) {
		if ((*elim).d1 == x) { // if we find a hit
			if ((*head).next == elim) { // if elim is the first node
				remove(head);
				numNodesDel++;
				elim = (*pred).next;
				
			}

			else { // else, if elim is not first node
				remove(head, pred);
				numNodesDel++;
				elim = (*pred).next; // *** Elim targets nonexistent pred.next at end of search
			}
		} //if

		else { // else, if elim does not equal x; we're either at end of list, or we must move search down the list
			if ((*elim).next == 0) { // at end of list?
					break;
			}
			pred = (*pred).next;
			elim = (*pred).next;	
		}
	} //for

	if (numNodesDel > 0) {
		myFile << endl << "Number of deleted nodes: " << numNodesDel << endl;
		cout << endl << "Number of deleted nodes: " << numNodesDel  << endl;
	}
	else {
		myFile << endl << "No matching nodes were found"  << endl << endl;
		cout << endl << "No matching nodes were found"  << endl << endl;
	}
} // removeAllMatching(int x, node * head)

// Calls printList() and remove()
// Prints list each time a number is removed from the list
void destroy(node * head) {
	node * elim = (*head).next;
	int numNodes = (*head).d1;
	
	printList(head);

	if((*head).next == 0) { // If nodes DO NOT exist in list
		cout << "Error: No list to delete!" << endl << endl;
		myFile << "Error: No list to delete!" << endl << endl;
	}

	else { // If list contains nodes
		for(int i = 0; i<numNodes; i++) {
				remove(head);
				printList(head);
				elim = (*head).next;
			}

		cout << "List Deleted!" << endl << endl;
		myFile << "List Deleted!" << endl << endl;
	} //else
} // destroy(node * head)

void main() {
// Declarations for printing to a file
myFile.open("ListManipulation.txt");

myFile << "David Murphy -- CSC 244 -- Project: List Manipulation" << endl << endl;
cout << "David Murphy -- CSC 244 -- Project: List Manipulation" << endl << endl;

node*phead = createList();

// Declarations
char input;
int num;
bool quit = false;

while(quit == false) {
	// Menu screen
	myFile << "****************************" << endl;
	myFile << "1 or a = add node (integer)" << endl;
	myFile << "2 or d = delete first matching node" << endl;
	myFile << "3 or m = delete all matching nodes" << endl;
	myFile << "4 or z = delete list" << endl;
	myFile << "5 or q = quit" << endl;
	myFile << "****************************" << endl;
	myFile << "Enter choice: ";

	cout << "****************************" << endl;
	cout << "1 or a = add node (integer)" << endl;
	cout << "2 or d = delete first matching node" << endl;
	cout << "3 or m = delete all matching nodes" << endl;
	cout << "4 or z = delete list" << endl;
	cout << "5 or q = quit" << endl;
	cout << "****************************" << endl;
	cout << "Enter choice: ";

	cin >> input;

	if (input == '1' || input == 'a' || input == 'A') {
		myFile << endl << "Selected add node (integer)" << endl;
		cout << endl << "Selected add node (integer)" << endl;
		int x;
		myFile << endl;
		cout << endl;
		myFile << "Input number: ";
		cout << "Input number: ";
		cin >> x;

		node *newNode = new node;
		(*newNode).d1=x;

		insertInOrder(newNode, phead);
		myFile << endl;
		cout << endl;
	} // Add node

	else if (input == '2' || input == 'd' || input == 'D') {
		myFile << endl << "Selected delete first matching node" << endl;
		cout << endl << "Selected delete first matching node" << endl;
		myFile << "Insert number to be deleted: ";
		cout << "Insert number to be deleted: ";
		cin >> num;
		myFile << endl;
		cout << endl;

		removeOne(num, phead);
	} // Delete node

	else if (input == '3' || input == 'm' || input == 'M') {
		myFile << endl << "Selected delete all matching nodes" << endl;
		cout << endl << "Selected delete all matching nodes" << endl;
		myFile << "Insert number to be deleted: ";
		cout << "Insert number to be deleted: ";
		cin >> num;
		myFile << endl;
		cout << endl;

		removeAllMatching(num, phead);
	} // Delete nodes

	else if (input == '4' || input == 'z' || input == 'Z') {
		myFile << endl << "Selected destroy the list" << endl;
		cout << endl << "Selected destroy the list" << endl;
		destroy(phead);
		node *phead = createList();
		
	} // Delete list

	else if (input == '5' || input == 'q' || input == 'Q') {
		myFile << endl << "Selected quit" << endl;
		cout << endl << "Selected quit" << endl;
		quit = true;
	} // Quit

	else {
		myFile << endl << "Error: Invalid input. Try again." << endl << endl;
		cout << endl << "Error: Invalid input. Try again." << endl << endl;
	} // Invalid input
	
	printList(phead);
	
} // end loop

} // main