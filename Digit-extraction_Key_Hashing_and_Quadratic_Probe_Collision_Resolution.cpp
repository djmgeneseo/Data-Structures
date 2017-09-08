//David Murphy HW Assignment page 638 5
//CSC 244
//Digit-extraction key hashing (first, third, and fifth digits) and quadratic probing
#include <iostream>

using namespace std;

void main()
{
	cout << "David Murphy - Digit-extraction key hashing (first, third, and fifth digits)" << endl << 
		" and quadratic probing collision detection" << endl << endl;
	int key[9] = {224562, 137456, 214562, 140145, 214576, 162145, 144467, 199645, 234534};
	int storedKeys[20] = {0};

	int hashedKey;
	int quadraticProbe = 1;

	for(int i=0; i<9; i++)
	{
		// Digit extraction/Hash key
		cout << key[i] << " = ";
		int first = (key[i] / 100000) % 10 *100;
		int third = (key[i] / 1000) % 10 *10;
		int fifth =	(key[i] / 10) % 10;
		hashedKey = first+third+fifth;
		hashedKey = hashedKey % 19;
		cout << "hashedKey = " << hashedKey << endl;

		// Check for collision
		if (storedKeys[hashedKey]!=0)
		{
			cout << "Collision in " << hashedKey << endl;
			
			// Quadtratic Probe
			while(storedKeys[hashedKey]!=0)
			{
				hashedKey=hashedKey+(quadraticProbe*quadraticProbe);
				quadraticProbe++;
			}
			cout << "Key moved to " << hashedKey << endl;
			storedKeys[hashedKey] = key[i];
		} //nested if

		else 
		{
		storedKeys[hashedKey] = key[i];
		} //nested else

		cout << endl;
	} // for

	// Print array of stored keys
	cout << "Array of Stored Keys: " << endl;
	for(int i = 0; i<20; i++)
	{
		cout << storedKeys[i] << endl;
	}
	
} // main