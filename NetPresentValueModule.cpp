/*
*CREATED BY: E KEALEBOGA
*-----This source code file implements the functions declared in the NetPresentValueModule header file---NOTE the #include"NetPresentValueModule.h"
*/

#include "stdafx.h"
#include <iostream>
#include "NetPresentValueModule.h"
using namespace std;


int NetPresentValueModule::cashFlows[10];

NetPresentValueModule::NetPresentValueModule()
{
}

int NetPresentValueModule::discountedCashFlow(int cashFlows [], double discountRate ,int period) {
	//---------------
	int discountedSum = 0;
	discountRate = discountRate + 1.0;
	for (int i = 1; i <= period; i++) {
	//--------calculation
		double cf = (double) cashFlows[i] / pow(discountRate, i);
		int discountedItem = (int) cf;
			//---------show discounted cash flow
		cout << discountedItem << endl;
		discountedSum  += discountedItem;////increments discountedSum by the value of a discounted cash flow item
	}

	return discountedSum;
}

int NetPresentValueModule::npvCalculator(int discountRate, int period) {
	cout << "Enter " << period << " Cash flows" << endl;
	//--------convert the discount rate to a double precision value
	double discountRateD = (double) discountRate * 0.01;
	////----------add a cash flow to the array---Note, the [0] entry of array is Excluded for calculation implementation
	for (int i = 1; i <= period; i++) {
		cin >> cashFlows[i];
	}
	cout << "\n";
	/////----------discount calculations---------
	int dSum = discountedCashFlow(cashFlows, discountRateD, period);

	return dSum;
}

void NetPresentValueModule::analyzeNPV(int NPV1, int NPV2) {
	//----compare the two passed in NPV's and chooses whichever is greater
	if (NPV1 > NPV2) {
		cout << "The more profitable project is the FIRST project" << endl;
	}
	else
	{
		cout << "The more profitable project is the SECOND project" << endl;
	
	}
}

