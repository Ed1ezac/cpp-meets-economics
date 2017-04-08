# cpp-meets-economics
A C++ program that does various basic financial calculations.

The program is made up of two modules:
1.	Compound 
2.	Net Present Value 

It prompts the user to choose which module he or she is willing to use. After selecting the module, the program prompts the user for the sub module they would like to use.

The Sub Modules for the Compound module are. 
a)	Future Value
b)	Present Value
c)	Period Interest Rate
d)	Number of Compounding Periods

The Sub Module for the Net Present Value module is. 
a)	Net Present Value for one Project.
b)	Net Present Value for Projects Evaluation

1. The Compound module

Compound Interest can be used to determine the present value of a future amount, this is called discounting. Compound interest can also be used to determine the future value of a current amount.
Compound Interest is the interest generated on a principal amount that compounds, that is that interest in one period will be added to principal and interest in the next period will be generated on the now increased principal amount. N.B This Assumes no withdrawals are made, and the interest rate is fixed for the compounding period

P - Principal Amount
i - interest rate
n/N - number of years


This module should provide sub menus for the following functionalities;
a)	Future Value

FV = P(1 + i)^N

This sub module should asks the user for P, i, n and calculate the Future Value (FV). After this point the user is given a choice to go back to Compound menu, Main menu or exit the application.

b)	Present Value

P = FV/(1 + i)^N

This sub module asks the user for FV, i, n and calculates the Present Value PV. After this point the user is given a choice to go back to Compound menu, Main menu or exit the application.

c)	Period Interest Rate

PIR = [(FV/PV)^1/n] - 1

This sub module asks the user for FV, PV, n and calculates the PIR (i) in Percentage. After this point the user is given a choice to go back to Compound menu, Main menu or exit the application.

d)	Number of Compounding Periods

n = [log(FV/PV)]/[log(1 + i)]

This sub module asks the user for FV, PV, i and calculates the n. After this point the user is given a choice to go back to Compound menu, Main menu or exit the application.

 2. Net Present Value Module

a) The Net Present Value (NPV) is a project Evaluation Technique that takes into account the profitability of the project and timings of the cash flows. The NPV for a project is obtained by discounting each cash flow (both negative and positive). This project assumes that the initial investment takes place immediately (indicated as year 0) and is not discounted. Later Cash flows take place at the end of each year and are discounted by the appropriate amount.  
The NPV is calculated using the formular found here;

http://www.financeformulas.net/Net_Present_Value.html

b)	Comparing the NPV for two Projects and choosing the most profitable one.

This module calculates NPV for two projects and decides which one a company should invest in. If both projects have a positive NPV, it compare the NPV figures. Whichever project has the higher NPV is the more profitable and should be the first priority.
The program prompts the user to enter the interest rate for both projects. It then calculates and displays the NPV for each project. Finally it makes a comparison, according to the NPV rules and select the most profitable project
















