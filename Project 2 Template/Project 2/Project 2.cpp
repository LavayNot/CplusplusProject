#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes
void displayOutput(InvestmentAccount accountNoDeposit, InvestmentAccount accountWithDeposit, int numberOfYears); //Displays the account details, as well as account balances and interest earned for each year.
   

int main() {
    double initialAmount;
    double monthlyDeposit;
    double annualInterestRate;
    int numberOfYears;


    // this will be the menu

    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << "Initial Investment Amount: ";
    cin >> initialAmount;
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
    cout << "Annual Interest: ";
    cin >> annualInterestRate;
    cout << "Number of years: ";
    cin >> numberOfYears;
    cout << "Press any key to continue. . .";
    
    cin.ignore(); // clears for user input 
    cin.get(); // this will accept a key from user
    
    InvestmentAccount accountWithDeposit(initialAmount, annualInterestRate, monthlyDeposit);
    InvestmentAccount accountNoDeposit(initialAmount, annualInterestRate);
    
    
    //Get the input...validate that the values are non-negative.

    //Create two InvestmentAccount variables...one with monthly deposit and one without monthly deposit

    //Display the output for each investment account
    cout << "==========================================================" << endl;
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    displayOutput(accountNoDeposit, accountWithDeposit, numberOfYears);
    cout << "==========================================================" << endl;
    cout << "Balance and Interest With Additional Monthly Deposit" << endl;
    displayOutput(accountWithDeposit, accountNoDeposit, numberOfYears);
    
    return 0;
}
// outputs year, endingbalance and interest for both accounts
void displayOutput(InvestmentAccount accountNoDeposit, InvestmentAccount accountWithDeposit, int numberOfYears) {
    cout << "==========================================================" << endl;
    cout << "Year Year End Balance Interest Earned " << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int year = 1; year <= numberOfYears; ++year) { // increases by increments of 1 until it reaches numberOfYears
        cout << year << accountNoDeposit.getEndingBalanceFormatted(year) << accountNoDeposit.getInterestEarnedFormatted(year) << endl;
        cout << year << accountWithDeposit.getEndingBalanceFormatted(year) << accountWithDeposit.getInterestEarnedFormatted(year) << endl;
    }
}
