/*
*CREATED BY: E. KEALEBOGA
*----This header file only defines the class interface, the implementations are in the .cpp file----
*/


#pragma once
class NetPresentValueModule
{
public:
	NetPresentValueModule();

	 int npvCalculator(int, int);

	int discountedCashFlow(int[], double, int);

	void analyzeNPV(int, int);

static int cashFlows[10];

};
