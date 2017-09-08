//David Murphy HW Assignment page 638 3
//CSC 244
// Store keys into an array using the modulo-division method and linear probing. Record number of collisions
#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy: Modulo-division and linear probing collision detection" << endl << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[19] = {0};

	int moduloKey;

	for(int i=0; i<9; i++) {
		// Mod key
		moduloKey = key[i] % 19;
		cout << key[i] << " % " << "19 = hashedKey = " << key[i] % 19 << endl;

		// Check for collision
		if (storedKeys[moduloKey]!=0) {
			cout << "Collision in " << moduloKey << endl;
			
			// Linear Probe
			while(storedKeys[moduloKey]!=0) {
				moduloKey++;
			}
			cout << "Key moved to " << moduloKey << endl;
			storedKeys[moduloKey] = key[i];
		} // nested if

		else {
		storedKeys[moduloKey] = key[i];
		} // nested else

		cout << endl;
	} // for

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<19; i++) {
		cout << storedKeys[i] << endl;
	}
	
} // main