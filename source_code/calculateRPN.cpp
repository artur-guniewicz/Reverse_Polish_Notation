#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cctype> // zawiera isdigit() i isspace()
#include <string>

using namespace std;

int calculateRPN(string expression)
{
    int i = 0;
    elementtype a, b, result;

    Stos *S = new Stos;

    string digit = "";

    while(i < expression.length())
    {
        // ignoruje spacje
        while(isspace(expression[i]))
            i++;

        // sprawdza czy to liczba
        if (isdigit(expression[i]))
        {
            while (isdigit(expression[i]))
            {
                digit += expression[i];
                i++;
            }

            S->Push(stoi(digit.c_str()));
            digit = "";
        }

        // sprawdza czy i jaki to operator
        else if(IsOperator(expression[i]))
        {
            if (expression[i] == '+')
            {
                a = S->TopElem();
                S->Pop();
                b = S->TopElem();
                S->Pop();

                result = (b + a);
            }

            if (expression[i] == '-')
            {
                a = S->TopElem();
                S->Pop();
                b = S->TopElem();
                S->Pop();

                result = (b - a);
            }

            if (expression[i] == '*')
            {
                a = S->TopElem();
                S->Pop();
                b = S->TopElem();
                S->Pop();

                result = (b * a);
            }

            if (expression[i] == '/')
            {
                a = S->TopElem();
                S->Pop();
                b = S->TopElem();
                S->Pop();

                result = (b / a);
            }

            if (expression[i] == '^')
            {
                a = S->TopElem();
                S->Pop();
                b = S->TopElem();
                S->Pop();

                result = pow(b, a);
            }

            if (expression[i] == '~')
            {
                a = S->TopElem();
                S->Pop();

                result = -a;
            }

            i++;

            // dopisuje wynik na szczyt stosu
            S->Push(result);
        }

        else
        {
            cout << "Błędne wyrażenie!" << endl;
            break;
        }
    }

    cout << S->TopElem() << endl;
    S->Makenul();
}