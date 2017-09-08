// David Murphy
// HW Assignment Page 638 #1
// CSC 244 - Data Structures
// Binary search

#include <iostream>

using namespace std;

/*  Returns a message that allocates the sought value's position in the array.
		Contingencies it will catch:
			- Array that is equal to or less than 1 in size
			- Odd or even numbered array sizes are functional
			- If the sought number does not exist in the given array
			- 

	@params:
		int a[] = array of integers
		int size = size of array
		int num = number to search for in array
*/
void binarySearch(int a[], int size, int num) { //binary search
	int first = 0;
	int mid = size/2;
	int last = size-1;

	if (size <= 1) { // if the array's size is either 1 or less
				cout << "-------------" << endl << "Your array either holds one or no numbers!" << endl << "-------------" << endl;
	}

	else if (a[mid]==num) { // if mid == num, then a binary search isn't necessary
		cout << "-------------" << endl << "FOUND IT!" << endl << "-------------" << endl;
			cout << "Array[" << mid << "] = " << a[mid] << endl << endl;
	}

	else { // binary search is necessary

		while (a[mid] != num) { // BINARY SEARCH: Loop breaks if mid# == num#.
			cout << "BINARY SEARCH" << endl;
			cout << "First = " << a[first] << endl;
			cout << "Mid = " << a[mid] << endl;
			cout << "Last = " << a[last] << endl << endl;
			
			if(num < a[mid]) { // test if num is less than mid# in array; if so, shift search to lesser half
				last = mid;
				mid = mid/2;

				if (mid<first) { // if mid# is placed below first#, then mid# must lay directly between first# and last#
					mid=first+1;
				} // nested inside if
			} 
		
			else { // else num is greater than mid#; shift search to greater half
				first = mid;
				mid = mid/2 + mid;

				if(mid>last) { // HOWEVER, if mid# is greater than last#, then mid# must be equal to last#
					mid=last;
				} // nested inside else
			} 
			
			if (first == mid && mid == last) { // Search ends empty-handed when first#, mid#, and last# equal each other.
				cout << "-------------" << endl << 
					num << " does not exist in this array." << endl << "-------------" << endl << endl;
				break;
			}
		
			if (a[mid]==num) { // condition for binary search is met, loop will break upon reset (following this message)
				cout << "-------------" << endl << "FOUND IT!" << endl << "-------------" << endl;
				cout << "Array[" << mid << "] = " << a[mid] << endl << endl;
			}
		} // while
	} // else
	
} // binarySearch()

void main()
{
	// Create a mock array and search for any number using the binarySearch method
	cout << "David Murphy: Binary Search (8,13,17,26,44,56,88,97)" << endl << endl;
	int arraySize = 8;
	int a[] = {8, 13, 17, 26, 44, 56, 88, 97};
	binarySearch(a, arraySize, 97);
} //main