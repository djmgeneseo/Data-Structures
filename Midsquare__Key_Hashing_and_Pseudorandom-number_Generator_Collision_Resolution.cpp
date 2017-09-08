//David Murphy HW Assignment page 639 7
//CSC 244
// Take the middle number of a key (two digits if even number of digits in key) 
// and multiply it by itself; take the third digit of the product. Set pseudorandom-number
// generator to a=3, c=-1
#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy: Midsquare method (center two digits) key hashing" << endl
		<< "and pseudorandom-number generator for rehashing if collision" <<
		endl << "occurs: a=3, c=-1." << endl << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[19] = {0};

	int hashedKey;

	for(int i=0; i<9; i++) {
		// misquare/Hash key
		cout << key[i] << " = ";
		hashedKey = key[i]/100; cout << hashedKey << endl;
		hashedKey = hashedKey % 100; cout << hashedKey << endl;
		hashedKey = hashedKey*hashedKey; cout << hashedKey << endl;
		hashedKey = hashedKey/10;
		hashedKey = hashedKey % 100;
		hashedKey = hashedKey % 19;
		cout << "hashedKey = " << hashedKey << endl;

		// Check for collision
		if (storedKeys[hashedKey]!=0) {
			cout << "Collision in " << hashedKey << endl;
			
			// Quadtratic Probe
			while(storedKeys[hashedKey]!=0) {
				hashedKey= (3*hashedKey-1) % 19;
			} //nested while

			cout << "Key moved to " << hashedKey << endl;
			storedKeys[hashedKey] = key[i];
		} //nested if

		else {
		storedKeys[hashedKey] = key[i];
		} //nested else

		cout << endl;
	} // for

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<19; i++) {
		cout << storedKeys[i] << endl;
	}
	
} // main