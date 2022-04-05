// Julian Espinoza
// Wesley Goo
// Hamza Patel
// Arturo Islas Mejia
// Date: 4/1/2022

#include <iostream>
#include <stack>
#include <map>
#include "input.h"
#include "nQueensSolution.h"
#include "translationOfArithmetic.h"
#include "simpleCalculator.h"
using namespace std;

int mainMenuOption();
int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case 1: simpleClaculator(); break;
        case 2: translationOfArithmetic(); break;
        case 3: nQueensSoultion(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//PostCondition:displays the main menu
int mainMenuOption()
{
    cout << endl << "Chapter 6: Assignment by by Julian Espinoza, Wesley Goo, Hamza Patel, Arturo Islas Mejia";
    cout << endl << "==========================================";
    cout << endl << "1> Simple Calculator (problem 9, pg 391)";
    cout << endl << "2> Translation of arithmetic expression (problem 10, pg 391)";
    cout << endl << "3> n-Queens Problem (problem 11, pg 391-392)";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 3);
    cout << endl << endl << endl;
    return options;
}