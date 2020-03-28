#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cctype> // zawiera isdigit() i isspace()
#include <string>

using namespace std;

int priority(elementtype el)
{
    switch((char)el)
    {
    case '+':
    case '-':
       return 1;
       break;

    case '*':
    case '/':
        return 2;
        break;

    case '^':
        return 3;
        break;

    case '(':
        return 0;
        break;

    case '~':
        return 4;
        break;

    default:
        return -1;
        break;
    }
}

void convertToRPN(string expression)
{
    int i = 0;

    Stos *S = new Stos;

    string digit;

    while (i < expression.length())
    {
        // ignoruje spacje
        while(isspace(expression[i]))
            i++;

        // sprawdza czy to liczba
        if(isdigit(expression[i]))
        {
            while(isdigit(expression[i]))
            {
                digit += expression[i];
                i++;
            }

            cout << digit << " ";
            digit = "";
            i--;
        }

        // sprawdza czy to operator
        else if(IsOperator(expression[i]))
        {
            // kontrola minusa unarnego
            if ((expression[i] == '-' && i == 0) || (expression[i] == '-' && isdigit(expression[i + 1]) && expression[i - 1] == '('))
            {
                int j = i + 1;
                int counter = 0;

                while (isdigit(expression[j]))
                {
                    digit += expression[j];
                    j++;
                    counter++;
                }

                cout << digit << " ~ ";
                digit = "";

                i += counter;
            }

            else
            {
                while (priority(S->TopElem()) >= priority(expression[i]) && !(S->Empty()))
                {
                    cout << (char)S->TopElem() << " ";
                    S->Pop();
                }

                S->Push(expression[i]);
            }
        }

        else if(expression[i] == '(')
        {
            S->Push(expression[i]);
        }

        else if(expression[i] == ')')
        {
            while((char)S->TopElem() != '(')
            {
                cout << (char)S->TopElem() << " ";
                S->Pop();
            }

            S->Pop();
        }

        i++;
    }

    // czyści stos z pozostałych operatorów
    while (!(S->Empty()))
    {
        cout << (char)S->TopElem() << " ";
        S->Pop();
    }

    cout << endl;
}