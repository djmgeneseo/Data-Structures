// David Murphy CSC 244 HW Assignment page 638 #11
// Rotation method key hashing followed by digit extraction hashing 
// linear probe for collision detection
// Rotation method: rotate the two, far-right digits two digits to the left and then 
// Digit-extraction: add first, third, and fifth digits. 

#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy: Rotation key hashing method into Digit-extraction" << endl << 
		"Linear Probe to resolve collision detection"<<endl << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[19] = {0};

	int hashKey;

	for(int i=0; i<9; i++) {
		// Rotation method/hashing
		cout << key[i] << " = " << endl;
		int z = key[i] % 100; 
		hashKey = key[i] - z; 
		int y = key[i] % 10000; 
		y = y-z; 
		hashKey = hashKey - y; 
		z = z*100;
		y = y/100; 
		hashKey = hashKey + y + z;
		cout << "hashKey after rotation method = " << hashKey << endl;
		
		// Digit Extraction/hashing
		int first = (hashKey / 100000) % 10 *100;
		int third = (hashKey / 1000) % 10 *10;
		int fifth =	(hashKey / 10) % 10;
		hashKey = first+third+fifth;
		hashKey = hashKey % 19;
		cout << "hashKey after digit extraction = " << hashKey << endl;

		// Check for collision
		if (storedKeys[hashKey]!=0) {
			cout << "Collision in " << hashKey << endl;
			
			// Linear Probe
			while(storedKeys[hashKey]!=0) {
				hashKey++;
			} 

			cout << "Key moved to " << hashKey << endl;
			storedKeys[hashKey] = key[i];
		} //nested if

		else {
		storedKeys[hashKey] = key[i];
		}//nested else

		cout << endl;
	} // for

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<19; i++) {
		cout << storedKeys[i] << endl;
	}
	
} // main