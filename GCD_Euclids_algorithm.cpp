// David Murphy
// CSC 121 - Project 2
// Recursion - Find the GCD of Two Integers
// Euclid's algorithm

#include <iostream>

using namespace std;


/*
	- Requires r0 to be greater than r1; swaps numbers if necessary
	- Requires positive numbers; changes signs if necessary
	- Checks whether r0 or r1 == 0;

*/
int GCD(int r0, int r1) {
	int zero = 0;
	// Output each time function is called
	cout << "r0 = " << r0 << ", r1 = " << r1 << endl << endl;

	// if either int is 0, return 0
	if (r0*r1==0) { 
		cout << "GCD = ";
		return zero;
	}

	// if r0 is neg, make pos
	if (r0 < 0) { 
		cout << "Turn r0 into positive num: ";
		return GCD(-r0, r1); 
	}

	// if r1 is neg, make pos
	if(r1 < 0) { 
		cout << "Turn r1 into positive num: ";
		return GCD(r0, -r1); 
	}

	// if r0 less than r1, switch
	if(r0 < r1) { 
		cout << "Swap r0 and r1: ";
		return GCD(r1, r0);
	}
	
	// if GCD is found
	if(r0 % r1 == 0) { 
		cout << "GCD = ";
		return r1; 
	}

	// else call GCD function
	else { 
		cout << "GCD: " << r0 << " % " << r1 << ": ";
		// Next GCD(): r0 becomes old r1, r1 becomes remainder of r0/r1
		return GCD(r1, r0%r1); 
	}

} // int GCD(int r0, int r1)

void main()
{	
	cout << "David Murphy\n" << "Project 2 - Recursion\n";
	cout << "Find the GCD of Two Integers: Euclid's Algorithm\n" << endl;

	// Declare r0, r1
	int r0, r1;

	// Input
	cout << "Input 1st integer (r0): ";
	cin >> r0;
	cout << endl;
	cout << "Input 2nd integer (r1): ";
	cin >> r1;
	cout << endl;

	// Output
	cout << "Original: ";
	cout << GCD(r0, r1) << endl << endl;

} // main()