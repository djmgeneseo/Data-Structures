/* David Murphy
/ CSC 244
/ Project: Postfix Stack
/
/ Arithmetic expressions: Infix = A + B     | Prefix = + A  B    | Postfix = A B +
/						  Infix = A + B * C | Prefix = + A * B C | Postfix = A B C * +
/
/		- Assume one digit operands (i.e the digits 0-9) 
/		- Assume binary operators + - * and /
/		- Implement using an array
/		- array[0] = top of stack
/
/	Suggested Tests: 
/		| 6523+8*+3-* | 47*35*- | 87+3/43*+ | 
/	The following will provide errors: 
/		| 2345*-0/+ | 47*35*-*21 | 47*35- |
*/

#include <iostream>
#include <string>

using namespace std;

// Global variables:
const int SIZE = 100; // Can only handle 100 operands/operations per expression
bool error = false; 

// array[0] = top of stack
int pop(double arry[], int& counter) {
	int x = arry[0];

	if(counter == 0) {   
		arry[0] = .1;
		counter --;
		return x;
	}
	else {

		for(int i = 0; i<counter; i++) {
			arry[i]=arry[i+1];
		}

		arry[counter]= .1;
		counter--;
		return x;
	}
} // int pop(double array, int& counter)

// array[0] = top of stack
void push(double arry[], int num, int& counter) {
	if(counter+1==SIZE) {cout << "overflow" << endl;}
	else {
		counter ++;
		if (counter == -1) {
			counter++;
			arry[0] = num;
		}
		else {
			for(int i = counter; i>0; i--) {

				arry[i]=arry[i-1];
			}
			arry[0] = num;
		} 
	} //else 
} // void push(double array, int number, int & counter)

// array[0] = top of stack
void printArray(double arry[], int arraySize) {	
	cout << "Stack contents: ";

	for(int i = 0; i<=arraySize; i++)
	{
		cout << arry[i] << "  ";
	}
	cout << endl;
}// void printArray(double arry[], int counter)

/* 
/	Identify the operator, pop operands from stack (array), perform operation, 
/	push product onto stack, and print stack. Print error durring attempt to divide by 0.
/	Requires global variable bool error, in event of error will change variable to true.
/	 
/	 Params:
/		- char _operator = chosen character from 'input' string (the expression).
/		- double arry[] = stack. Shares the address of passed array.
/		- int& arrayCounter = number of variables in array. Shares address from passed variable.
/
/	 Calls:
/		- void push(double array, int number, int & counter)
/		- int pop(double array, int& counter)
/		- void printArray(double arry[], int counter)
*/
 void operators(char _operator, double arry[], int& arrayCounter) {
	int x;
	int a;
	int b;

	if (_operator == '+') {
		b = pop(arry, arrayCounter);
		a = pop(arry, arrayCounter);
		x = a+b;
		push(arry, x, arrayCounter);
		printArray(arry, arrayCounter);
	} // Addition

	else if(_operator == '-'){
		b = pop(arry, arrayCounter);
		a = pop(arry, arrayCounter);
		x=a-b;
		push(arry, x, arrayCounter);
		printArray(arry, arrayCounter);
	} // Subtraction

	else if(_operator == '*')
	{
		b = pop(arry, arrayCounter); 
		a = pop(arry, arrayCounter); 
		x = a*b;
		push(arry, x, arrayCounter);
		printArray(arry, arrayCounter);
	} // Multiplication

	else if (_operator == '/')
	{
		b = pop(arry, arrayCounter);
		a = pop(arry, arrayCounter);

		if(a == 0 || b == 0) {
			cout << endl << "Error: Attempt to divide by 0" << endl; error = true;
		}
		else{
			x = a/b; 
			push(arry, x, arrayCounter);
			printArray(arry, arrayCounter);
		}
	} // Division
} // void operators(char current, double postfix[], int arrayCounter)

/* 
/	Identify operand, push operand onto stack (array), and print stack. Print error if input =! 1-9.
/	Requires global variable bool error, in event of error will change variable to true.
/	
/	Params:
/		- char _operand = chosen character from 'input' string (the expression).
/		- double arry[] = stack. Shares the address of passed array.
/		- int& arrayCounter = number of variables in array. Shares address of value from passed variable.
/  
/   Calls: 
/		- void push(double arry[], int num, int& counter)
/		- void printArray(double arry[], int counter)
 */
void operands(char _operand, double postfix[], int& arrayCounter) {
	int x;
	
	if(_operand == '0'){x=0; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '1'){x=1; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '2'){x=2; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '3'){x=3; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '4'){x=4; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '5'){x=5; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '6'){x=6; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '7'){x=7; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '8'){x=8; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else if(_operand == '9'){x=9; push(postfix, x, arrayCounter); printArray(postfix, arrayCounter);}
	else{cout << "Invalid input" << endl; error = true;}
} // void operands(char _operand, double postfix[], int& arrayCounter)

void main()
{
	cout << "David Murphy - CSC 244 - Project: Postfix Stack" << endl << endl;

	cout << "Arithmetic expression guidelines:" << endl;
	cout << "Infix = A + B     | Prefix = + A B     | Postfix = A B +" << endl;
	cout << "Infix = A + B * C | Prefix = + A * B C | Postfix = A B C * +" << endl << endl;

	//Declarations
	double postfix[SIZE] = {.1};
	string input;
	char current;
	int arrayCounter=-1;

	//Input expression into string 'input'
	cout << "(Integers only, no spaces)" << endl << "Input Postfix Expression : ";
	cin >> input;
	cout << endl;

	for(int i = 0; i < input.size(); i++) {	// Loop through string (expression)
		current = input.at(i);
		cout << "Input: " << current << endl;
		
		// search for operators
		if(current == '+' || current == '-' || current == '*' || current == '/') { 
			
			if(postfix[1] == .1) { // Check for underflow
				cout << endl << "Too few operands" << endl; error = true; break;
			} 
			else { //Identify the operator, pop operands, perform operation, push product onto stack, and print stack.
				operators(current,postfix,arrayCounter);
			}
		} // nested if

		else { // Identify operand, push operand onto stack (array), and print stack
			operands(current,postfix,arrayCounter);
		}

		cout << endl;
		if (error == true) {break;}
	} // for

	//Check for too many remaining operands
	if (error == false) {	
		if(arrayCounter == 0) {
			cout << "******************" << endl << "Answer: " << postfix[0] << endl << "******************" << endl << endl;
		}
		else {
			cout << endl << "Too few operators" << endl;
		}
	}
} // main()