#include <iostream>					
#include <string>
#include <iomanip>
using namespace std;



int main() {

	double initialInvestment = 0;								// Here I am creating a set of variables for my code that will be
	double monthlyDeposit = 0;									// used to gather userinput and run calculations with
	double annualInterest = 0;
	int numberOfYears = 0;
	string userInput;

	cout << "********************************" << endl;			// This is my template for all of the banking information thats going to be
	cout << "********* Data Input ***********" << endl;			// requested from the user
	cout << "Initial Investment Amount: "  << endl;
	cout << "Monthly Deposit: " <<  endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	cout << endl << endl;

	cout << "Please enter the following" << endl;				// Asking the user to enter all of the information from the template
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	while (initialInvestment < 0) {								// I added this to prevent the user from entering negative values
		if (initialInvestment < 0) {
			cout << "Values must be positive and real. Please try again" << endl;
			cin >> initialInvestment;
		}
	}
	double investmentTwo = initialInvestment;					// I created this vaiable here so that I could save a copy of the initial investment
																// entered by the user before calculations are ran and change the value
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	while (monthlyDeposit < 0) {
		if (monthlyDeposit < 0) {
			cout << "Values must be positive and real. Please try again" << endl;		// All of these loops are the same just asking the user to enter 
			cin >> monthlyDeposit;														// values for the different variables 
		}
	}
	cout << "Annual Interest: ";
	cin >> annualInterest;
	while (annualInterest < 0) {
		if (annualInterest < 0) {
			cout << "Values must be positive and real. Please try again" << endl;
			cin >> annualInterest;
		}
	}
	annualInterest = annualInterest / 100;

	cout << "Number of years: ";
	cin >> numberOfYears;
	while (numberOfYears < 0) {
		if (numberOfYears < 0) {
			cout << "Values must be positive and real. Please try again" << endl;
			cin >> numberOfYears;
		}
	}	
	cout << endl << endl;															// Request for info is over

	cout << "********************************" << endl;								// This prints the same template as before except this time adding in the values the user
	cout << "********* Data Input ***********" << endl;								// entered so that it can be reviewd before continuing. 
	cout << "Initial Investment Amount: $" << initialInvestment << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << "Annual Interest: %" << annualInterest << endl;
	cout << "Number of years: " << numberOfYears << endl;
	cout << endl << endl;

	system("Pause");																// System pauses here to allow user to check their values
	cout << endl << endl;

	const int REPORT_ROWS = numberOfYears;											// I created an array here using pointers to create my colums
	const int NUM_COLS = 3;															// I did this because visual studio doesn't like arrays that take 
	double **bankReport = new double* [REPORT_ROWS];								// user entered values as their size parameters
	for (int i = 0; i < REPORT_ROWS; i++) {											// Kept spitting out errors for an array that didn't have a const value size
		bankReport[i] = new double[NUM_COLS];
	}

	cout << fixed << setprecision(2);															// Setting the precision of my values
																								// I wanted to eventually get around to changing years to have no decimal
	cout << "      Balance and Interest Without Additional Monthly Depositys" << endl;			// but I just didn't have the time!
	cout << "====================================================================" << endl;
	cout << " Year           Year End Balance           Year End Earned Interest" << endl;		// Printing my first bank statements template
	cout << "-------------------------------------------------------------------" << endl;
	
	for (int x = 0; x < REPORT_ROWS; ++x) {														// This for loop stores the user entered number of years in the first 
		int y = 0;																				// column of every row in the array starting at 1 and ending when the number of years
		bankReport[x][y] = x + 1;
	}

	double stackInvest = 0;																		// This for loop populates the second column of every row with the year end balance
	for (int x = 0; x < REPORT_ROWS; ++x) {														// performs the annual interest calculation, and then updates the balance before printing again
		int y = 1;
			stackInvest = initialInvestment + (initialInvestment * annualInterest);
			bankReport[x][y] = stackInvest;
			initialInvestment = stackInvest;
	}


	for (int x = 0; x < REPORT_ROWS; ++x) {														// This for loop calculates the year end interest earned by accessing other array elements
		int y = 2;																				// and performing calculations on them before printing to the current position in loop
		bankReport[x][y] = (bankReport[x][y - 1] * annualInterest);

	}


	for (int x = 0; x < REPORT_ROWS; ++x) {				// This loop actually prints the array by using a double/nested for loop
		for (int y = 0; y < NUM_COLS; ++y) {			// for each row it iterates through all 3 columns and prints each one. 
			cout << bankReport[x][y] << "                     ";
		}
		cout << endl << endl;
	}


	cout << "           Balance and Interest With Monthly Depositys" << endl;						// This is essentially the same as the first bank statement with one minor change
	cout << "====================================================================" << endl;			// This bank statement adds a reoccuring monthly deposit into the equation
	cout << " Year           Year End Balance           Year End Earned Interest" << endl;			// This change really only affected the for loop that calculated the year end balance
	cout << "-------------------------------------------------------------------" << endl;			// The interest was still calculated in the same manor. 

	double** bankReportPlus = new double* [REPORT_ROWS];
	for (int i = 0; i < REPORT_ROWS; i++) {
		bankReportPlus[i] = new double[NUM_COLS];
	}

	for (int x = 0; x < REPORT_ROWS; ++x) {		// Years for loop
		int y = 0;
		bankReportPlus[x][y] = x + 1;
	}

	stackInvest = 0; 
	for (int x = 0; x < REPORT_ROWS; ++x) {			// Year End balance for loop
		int y = 1;
		stackInvest = investmentTwo + (investmentTwo * annualInterest) + monthlyDeposit;
		bankReportPlus[x][y] = stackInvest;
		investmentTwo = stackInvest;
	}

	for (int x = 0; x < REPORT_ROWS; ++x) {			// Interest for loop
		int y = 2;
		bankReportPlus[x][y] = (bankReportPlus[x][y - 1] * annualInterest);

	}


	for (int x = 0; x < REPORT_ROWS; ++x) {			// FOR LOOP TO PRINT ALL VALUES of bankReport ON THE SCREEN
		for (int y = 0; y < NUM_COLS; ++y) {
			cout << bankReportPlus[x][y] << "                     ";
		}
		cout << endl << endl;
	}

	

}





/*
Add ons if time permits

- Add dollar signs in front of values in column two and three
- Eliminate decimal values for years in column one
- Create functions for printing the two statements to clean up main()
-
*/