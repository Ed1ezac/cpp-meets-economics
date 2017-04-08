/*
*CREATED BY: E. KEALEBOGA 
*----This header file only defines the class interface, the implementations are in the .cpp file----
*/

#pragma once
#include<math.h>
//
class CopmoundModule
{
public:
	CopmoundModule();//------No arguments constructor


	float futureValue(int , double , int );

	float presentValue(float , double , int );

	double periodInterestRate(double , int , int );

	double compoundingPeriod(double, int, double);

};
