/*
*CREATED BY: E KEALEBOGA 
*-----This source code file implements the functions declared in the CopmoundModule header file---NOTE the #include"CopmoundModule.h"
*/
#include "stdafx.h"
#include "CopmoundModule.h"


CopmoundModule::CopmoundModule()
{

}

float CopmoundModule::futureValue(int PV, double IR, int period) {
	//----returns the future value--///Note type cast before calculation
	return (float)PV * pow(1.0 + IR, period);
}

float CopmoundModule::presentValue(float FV, double IR, int period) {
	//---returns the present value--///Note type cast before calculation
	return (float)FV / pow(1.0 + IR, period);

}

double CopmoundModule::periodInterestRate(double FV, int PV, int period) {
	//---returns the interest rate
	double a = (double) (FV / PV);
	double b = (double)(1.0 / period);
	
	return (double) (pow(a,b) - 1.0) / 0.01;

}

double  CopmoundModule::compoundingPeriod(double FV, int PV, double IR) {
	//--returns the compounding period
	return (double) (log10((FV / PV))) / log10((1.0 + IR));
}
