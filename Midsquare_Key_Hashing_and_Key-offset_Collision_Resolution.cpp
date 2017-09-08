// David Murphy CSC 244 HW Assignment page 639 #8
// Midsquare key hashing method, and key-offset method for collision.
// Divide key by 19, and add the quotient to the key. Module the sum by 19.

#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy: Midsquare key hashing method, and " << endl
		<< "key-offset method for collision. " << endl << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[19] = {0};

	int hashedKey;
	int offSet;

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
			
			// key-offset Probe
			while(storedKeys[hashedKey]!=0) {
				offSet = key[i]/19;
				hashedKey = ((offSet+key[i]) % 19);
			} //nested while
			cout << "Key moved to " << hashedKey << endl;
			storedKeys[hashedKey] = key[i];
		} //nested if

		else {
		storedKeys[hashedKey] = key[i];
		} //nested else

		cout << endl;
	}

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<19; i++) {
		cout << storedKeys[i] << endl;
	}

} //main