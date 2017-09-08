// David Murphy CSC 244 HW Assignment page 638 #9
// Hash keys using fold-shift method and folding two digits at a time and 
// then use modulo-division on the folded sum. Linear Probe collisiond detection
#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy: Fold-shift key hash -> Modulo-division key hash" << endl << 
		"Linear Probe Collision Detection" << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[19] = {0};

	int hashKey;

	for(int i=0; i<9; i++) {
		// Fold-shift key hashing
		cout << key[i] << " = " << endl;
		int x = key[i]/10000; cout << x << endl;
		int y = key[i]/100; 
		y = y %100; cout << y << endl; 
		int z = key[i] % 100; cout << z << endl;
		hashKey = x+y+z; cout << hashKey << endl;

		// Modulo-division key hashing
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
			}
			cout << "Key moved to " << hashKey << endl;
			storedKeys[hashKey] = key[i];
		} //nested if

		else {
		storedKeys[hashKey] = key[i];
		} //nested else

		cout << endl;
	} // for

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<19; i++) {
		cout << storedKeys[i] << endl;
	}
	
} // main