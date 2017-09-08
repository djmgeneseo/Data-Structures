// David Murphy
// Professor Hammerman
// 3/17/13
// CSC 120 01

#include <iostream>
#include <iomanip>

using namespace std;

void main ()
{	
	cout << "David Murphy" << endl << "Calculate interest over 'x' number of years" << endl << endl;
	// Declare counter and essential variables for the equation
	int i = 1;
	int years = 0;
	double oldAmount;
	double rate;
	double newAmount = 0;

	// Prompt the user to input the initial amount, the rate, and the desired amount of years
	cout << "Please enter the initial amount: ";
	cin >> oldAmount;
	cout << "Please enter the rate in decimal form: ";
	cin >> rate;
	cout << "Please enter the number of years: ";
	cin >> years;
	cout << endl;
	
	// Prompt the user, displaying his initial data before entering the loop
	cout << "At the beginning you have $" << setprecision(2) << setiosflags(ios::fixed) << oldAmount << endl;
	
	while (i<=years && years != 0)
	{
		newAmount = rate * oldAmount;
		cout << "At the end of year " << i << " you have $" << setprecision(2) << setiosflags(ios::fixed) << newAmount << endl;
		i++;
		oldAmount = newAmount;
	}// while
} // main