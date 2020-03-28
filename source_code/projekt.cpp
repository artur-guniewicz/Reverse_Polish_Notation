/*
************************************************************
*               Algorytmy i Struktury Danych               *
*                                                          *
*                     Artur Guniewicz                      *
************************************************************
*/

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "klasaStos.cpp"
#include "convertToRPN.cpp"
#include "calculateRPN.cpp"

using namespace std;

int main()
{
menu:

    cout << "************************************************************" << endl
         << "                  ODWROTNA NOTACJA POLSKA                   " << endl
         << "************************************************************" << endl
         << endl;

    cout << "Co chcesz zrobić?" << endl
         << "1. Przekonwertować wyrażenie z notacji tradycyjnej do ONP" << endl
         << "2. Obliczyć wyrażenie w ONP" << endl
         << "3. Zakończyć program" << endl
         << "Twój wybór: ";

    int choice;
    char choice2;

    cin >> choice;

    cout << endl;

    string expression;

    switch (choice)
    {
    case 1:
        cin.ignore();
        cout << "Podaj wyrażenie w notacji tradycyjnej: ";
        getline(cin, expression);
        cout << "To samo wyrażenie w ONP: ";
        convertToRPN(expression);
        break;

    case 2:
        cin.ignore();
        cout << "Podaj wyrażenie w ONP: ";
        getline(cin, expression);
        cout << "Wynik: ";
        calculateRPN(expression);
        break;

    case 3:
        cout << "Miłego dnia!" << endl;
        exit(1);
        break;

    default:
        system("clear");
        cout << "Błędnie podana cyfra!" << endl << "Proszę podać cyfrę 1, 2 albo 3..." << endl << endl;
        goto menu;
        break;
    }


    cout << endl << "Zakończyć program? (T/N): ";

end:
    cin >> choice2;

    switch(choice2)
    {
    case 'T':
    case 't':
        cout << endl << "Miłego dnia!" << endl;
        exit(1);

    case 'N':
    case 'n':
        cout << endl;
        system("clear");
        goto menu;

    default:
        cout << "Wpisz <T> aby zakończyć lub <N> aby wrócić do menu: ";
        goto end;
    }

    return 0;
}