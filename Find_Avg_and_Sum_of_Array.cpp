#include <iostream>
#include <iomanip>

using namespace std;

double sumArray(double a[], int aSize){
	double temp=0;

	for (int i=0; i<aSize; i++){
		temp+=a[i];
	}

	return temp;
} // sumArray

double avgArray(double a[], int aSize){
	double temp=0;

	for (int i=0; i<aSize; i++){
		temp+=a[i];
	}
	return temp/aSize;
} //avgArray

void main()
{
	// Number of student GPA's
	int s;
	// Number of tests
	int t;

	// Find # of students

	cout << "David Murphy" << endl << endl << "Please input the # of students whose GPAs you'd like to calculate: ";
	cin >> s;
	cout << endl << endl;

	//If input is less than or equal to 0, request # again
	while (s<=0) {
		cout << "Please input a number of students that is greater than 0: ";
		cin >> s; 
		cout << endl << endl;
	}

	// Find # of tests
	cout << "How many tests per gpa? ";
	cin >> t;
	cout << endl << endl;
	
	// If input is less than or equal to 0, request # again
	while (t<=0) {
		cout << "Please input a number of tests that is greater than 0: ";
		cin >> t; 
		cout << endl << endl;
	}

	// Initialize array and set size to the # of tests
	double *a;
	a = new double[t];
	
	// Assign grades into the array 
	cout << "Type in the " << t << " test scores to calculate their sum and average." << endl 
		<< "Type each grade, one at a time, and hit 'Enter' after each grade." << 
		endl << endl << "-------" << endl << "Grades:" << endl << "-------" << endl;
	
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}

	cout << endl << endl;
	
	// temp variable for nested loop
	int i2 = 1;

	for (int i = 0; i < s; i++) {
		cout << "The sum of the " << t <<  " tests is: " << setiosflags(ios::fixed) << setw(12) << setprecision(0) <<  sumArray(a, t) << endl; // <--- Start again here
		cout << "The average of the three scores are: " << setiosflags(ios::fixed) << setw(2) << setprecision(0) << avgArray(a, t) << endl << endl;

		if (i2!=s) {	
			cout << "Next Student: Type in the " << t << " test scores to calculate their sum and average. " << endl 
			<< "Type each grade, one at a time, and hit 'Enter' after each grade." << 
			endl << endl << "-------" << endl << "Grades:" << endl << "-------" << endl;
			
			for (int i = 0; i < t; i++) {
				cin >> a[i];
			} // nested for

		cout << endl;
		} // nested if
		i2++;
	} //for
	
} //main