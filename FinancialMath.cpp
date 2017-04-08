/*
*CREATED BY: E. KEALEBOGA
*/

// -----------------FinancialMath.cpp : Defines the entry point for the console application.-------------


#include "stdafx.h"
#include "CopmoundModule.h"
#include "NetPresentValueModule.h"
#include <iostream>
using namespace std;

//////-----The submenu of Compound Module
void compoundMenu(char selection) {
	CopmoundModule cm;
	selectionMenu:
	switch (selection)
	{
	case 'a':
	
		////------future value computations done here-----
		int pv, interestRate, period;
		double ir;
		cout << "Enter the Present Value" << endl;
		cin >> pv;
		cout << "Enter the Interest Rate" << endl;
		cin >> interestRate;
		//---converts the interest rate to compatible type----NOTE type cast is to prevent data loss
	    ir = (double) interestRate * 0.01;
		cout << "Enter the Number of Years" << endl;
		cin >> period;

		cout << "The Future Value at the end of " << period << " years at " << interestRate << "% interest Rate  is: ";
		//----NOTE .2f controls the number of decimal places (2 in this case)---USED THRU OUT
		printf("%.2f\n",cm.futureValue(pv, ir, period));

		////----------end of future value computations---------
		break;
	

	case 'b':

		////------present value computations done here------
		float fv;
		int pvInterestRate, pvPeriod;
		double pvIr;
	    cout << "Enter the Future Value" << endl;
	    cin >> fv;
	    cout << "Enter the Interest Rate" << endl;
	    cin >> pvInterestRate;
	    //---converts the interest rate to compatible type
		pvIr = (double)pvInterestRate * 0.01;
	    cout << "Enter the Number of Years" << endl;
	    cin >> pvPeriod;

	cout << "The Present Value of " << pvPeriod << " years at " << pvInterestRate << "% interest Rate  is: ";
	printf("%.2f\n", cm.presentValue(fv, pvIr, pvPeriod));

	   /////-------------end of present value computation
	break;

	case 'c':
		////-------period interest rate computation done here-----
		double irFutureVal;
		int irPresentVal, irPeriod;
		cout << "Enter the Future Value" << endl;
		cin >> irFutureVal;
		cout << "Enter the Present Value" << endl;
		cin >> irPresentVal;
		cout << "Enter the number of Years" << endl;
		cin >> irPeriod;

		cout << "The Interest Rate of " << irFutureVal << " Future Value with " << irPresentVal << " Present Value";
		cout << " after " << irPeriod << " years, is: " ;
		printf("%.1f", cm.periodInterestRate(irFutureVal, irPresentVal, irPeriod));
		cout << "%\n" << endl;

		////------------end of period interest rate computation
		break;
		 
	case 'd':
		////-------Number of years computations done here------
		double cpFutureVal, cpIr;
		int cpPresentVal, cpInterestRate;
		cout << "Enter the Future Value" << endl;
		cin >> cpFutureVal;
		cout << "Enter the Present Value" << endl;
		cin >> cpPresentVal;
		cout << "Enter the Interest Rate" << endl;
		cin >> cpInterestRate;
		//---converts the interest rate to compatible type
		cpIr = (double) cpInterestRate * 0.01;

		
		cout << "The Number of Compounding Periods for " << cpFutureVal << " Future Value and " << cpPresentVal << " Present Value";
		cout << " at " << cpInterestRate << "% Interest Rate is: ";
		printf("%.1f\n", cm.compoundingPeriod(cpFutureVal, cpPresentVal, cpIr));

		////-------end of computation
		break;

	default: 
		cout << "Invalid entry, Retry...\n" << endl;
		char selection2;
			cin >>  selection2;
			goto selectionMenu;
		break;
	}
}

/////------The submenu of N.P.V Module-------*N.P.V = Net Present Value
void npvMenu(char selection) {
	NetPresentValueModule npv;
	selectionCheck:
	switch (selection)
	{
	case 'a':
		///////---------Net Present Value [1 Project] Calculations done here
		int investment, discountRate, period, discountedSum;
		cout << "Enter the Initial investment" << endl;
		cin >> investment;
		cout << "Enter the Discount rate" << endl;
		cin >> discountRate;

	Correction:
		cout << "Enter the discounting period [maximum is 10]" << endl; 
		cin >> period;

		if (period <= 10) {
			//do calculations
			////-------Everything else handled by the function
			discountedSum = npv.npvCalculator(discountRate, period);
		}
		else
		{
			cout << "Too large..\n";
			goto Correction;
		}

	
		cout << "The Net Present Value for Project is: " << discountedSum - investment << endl;
		

		break;

	case 'b':
		int investmentP1, discountRateP1, periodP1, discountedSumP1, NPV1;
		int investmentP2, discountRateP2, periodP2, discountedSumP2, NPV2;
		cout << "Enter the Initial investment of First Project" << endl;
		cin >> investmentP1;
		cout << "Enter the Discount rate of First Project" << endl;
		cin >> discountRateP1;

	Correction2:
		cout << "Enter the discounting period of First Project [maximum is 10]" << endl;
		cin >> periodP1;

		if (periodP1 <= 10) {
			discountedSumP1 = npv.npvCalculator(discountRateP1, periodP1);
		}
		else {
			cout << "Too large..\n"; 
			goto Correction2;

		}

		
		NPV1 = discountedSumP1 - investmentP1;
		cout << "The Net Present Value for Project is: " << NPV1  << endl;

		//----------NPV for second project
		cout << "Enter the Initial investment of Second Project" << endl;
		cin >> investmentP2;
		cout << "Enter the Discount rate of Second Project" << endl;
		cin >> discountRateP2;

	Correction3:
		cout << "Enter the discounting period of Second Project [maximum is 10]" << endl;
		cin >> periodP2;

		if (periodP2 <= 10) {
			discountedSumP2 = npv.npvCalculator(discountRateP2, periodP2);
		}
		else {
			cout << "Too large..\n";
			goto Correction3;
		
		}

		
		NPV2 = discountedSumP2 - investmentP2;
		cout << "The Net Present Value for Project is: " << NPV2 << endl;

	    npv.analyzeNPV(NPV1, NPV2);
		break;

	default:
		cout << "Invalid entry, Retry...\n" << endl;
		char selection2;
		cin >> selection2;
		goto selectionCheck;
		break;
	}
}


int main()
{
	///////------------Entry Point
	appEntry:
	cout << "Choose a module:\n Press [1]/[2]\n\n" << "1.) Compound Module\n" << "2.) Net Present Value Module" << endl;
	int moduleSelection;

	cin >> moduleSelection;

	switch (moduleSelection) 
	{
	case 1: 
		cout << "Choose a compound sub-Module from below\n" << endl;
		cout << " a)Future Value\n b)Present Value\n c)Period Interest Rate\n d)Number of Compounding Periods\n" << endl;
		char compoundSelection;
		cin >> compoundSelection;
		compoundMenu(compoundSelection);

		//////----Choice Block
		choiceBlock:
		cout << "Press [m] to return to main menu, [e] to exit" << endl;
		char choice;
		cin >> choice;

		if (choice == 'm') {
			system("cls");
			goto appEntry;
		}
		else if(choice == 'e') {
			exit(EXIT_SUCCESS);
		}
		else if (!(choice == 'e' || 'm'))
		{
			cout << "Invalid Selection, try again...." << endl;
				goto choiceBlock;
		}
		//--end of choice block
		break;

	case 2:
	subMenuLabel:

		cout << "Choose a Net PresentnValue sub-Module from below\n" << endl;
		cout << " a)Net Present Value [1 Project]\n b)Net Present Value [Projects Evaluation]\n" << endl;
		char npvSelection;
		cin >> npvSelection;

		////////------------------------------------------
		npvMenu(npvSelection);


		char currentSelection;
		if (npvSelection == 'a') {
			currentSelection = 'a';
		}
		else
		{
			currentSelection = 'b';
		}


		//////----Choice Block
	npvChoiceBlock:
		cout << "Press [r] to reuse module, [b] to go back to Net Present Value submenu, [m] to return to main menu or [e] to exit" << endl;
		char npvChoice;
		cin >> npvChoice;
		
		if (npvChoice == 'r') {
			//---reuse module
			system("cls");
			npvMenu(currentSelection);
			
		}
		else if (npvChoice == 'b') {
			system("cls");
			goto subMenuLabel;
		}
		else if (npvChoice == 'm') {
			system("cls");
			goto appEntry;
		}
		else if (npvChoice == 'e') {
			exit(EXIT_SUCCESS);
		}
		else if (!(npvChoice == 'e' || 'm' || 'b' || 'r'))
		{
			cout << "Invalid Selection, try again...." << endl;
			goto npvChoiceBlock;
		}
		/////--end of choice block
		break;

	default:
		cout << "Invalid selection\n" << endl;
		goto appEntry;
		break;
	}

    return 0;
}
