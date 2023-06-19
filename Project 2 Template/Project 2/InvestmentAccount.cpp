#include "InvestmentAccount.h"
#include <cmath>

//Implementation for InvestmentAccount
//Constructor without deposit
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
	: initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(0.0)
{
	initialAmount = initialAmount;
	annualInterestRate = annualInterestRate;
	monthlyDeposit = 0.0;
}
//constructor with deposit
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit) 
	: initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit)
{
	initialAmount = initialAmount;
	annualInterestRate = annualInterestRate;
	monthlyDeposit = monthlyDeposit;

}
 // calculates balance  
double InvestmentAccount::getEndingBalance(int numberOfYears) {
	double endingBalance = initialAmount;
	for (int year = 1; year <= numberOfYears; ++year) {
		for (int month = 1; month <= 12; ++month) {
			endingBalance += endingBalance * (annualInterestRate / 12);
			endingBalance += monthlyDeposit;
		}
	}
	return endingBalance;
}

// interest earned 
double InvestmentAccount::getInterestEarned(int numberOfYears) {
	double maxDeposit = (initialAmount + monthlyDeposit) * ((annualInterestRate/100)/12);
	double endingBalance = getEndingBalance(numberOfYears);
	
	return endingBalance - maxDeposit;
}

std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears) {
	double endingBalance = getEndingBalance(numberOfYears);
	double roundedBalance = round(endingBalance, 2);
	
	return format(roundedBalance);
}

std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears) {
	double earnedInterest = getInterestEarned(numberOfYears);
	double roundedInterest = round(earnedInterest, 2);

	return format(roundedInterest);
}

double InvestmentAccount::getInitialAmount() {
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit() {
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate() {
	return annualInterestRate;
}





//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value , int places) {
	const double multiplier = pow(10, 2);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}