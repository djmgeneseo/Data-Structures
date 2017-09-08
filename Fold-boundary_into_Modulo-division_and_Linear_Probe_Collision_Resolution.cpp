//David Murphy CSC 244 HW Assignment page 638 #10
// fold-boundary key hash into a modulo-division key hash 
// with linear probe collision detection
// Fold-boundary = flip first two digits, save next two, flip remaining two, and 
// find the sum of those three numbers. 
#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy: fold-boundary key hash into a modulo-division key hash" << endl <<
		"with linear probe collision detection" << endl << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[19] = {0};

	int hashKey;

	for(int i=0; i<9; i++) {
		// Fold-Boundary key hash
		cout << key[i] << " = " << endl;
		int x1 = key[i]/100000; 
		int x2 = (key[i]/10000) % 10; x2 = x2*10;
		int x = x1+ x2; cout << x << endl;
		int y = key[i]/100;
		y = y %100; cout << y << endl; 
		int z2 = key[i] % 10; 
		int z = key[i] % 100;
		int z1 = z-z2; z1 = z1/10;
		z2 = z2*10;
		z = z1+z2; cout << z << endl;
		hashKey = x+y+z; cout << hashKey << endl;

		// Modulo-division key hash
		hashKey = hashKey % 100; 
		hashKey = hashKey % 19;
		cout << "hashKey = " << hashKey << endl;

		// Check for collision
		if (storedKeys[hashKey]!=0) {
			cout << "Collision in " << hashKey << endl;
			
			// Linear Probe
			while(storedKeys[hashKey]!=0)
			{
				hashKey++;
			}//nested while
			cout << "Key moved to " << hashKey << endl;
			storedKeys[hashKey] = key[i];
		}//nested if

		else {
		storedKeys[hashKey] = key[i];
		}//nested else

		cout << endl;
	} //for

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<19; i++) {
		cout << storedKeys[i] << endl;
	}
	
} // main