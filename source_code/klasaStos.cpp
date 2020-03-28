#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int maxlegth = 100;

typedef int elementtype;
typedef int position;

class Stos
{

protected:
    int S[maxlegth];
    position Top; //szczyt stosu

public:
    Stos();
    ~Stos();

    void Push(elementtype x);
    void Pop();
    elementtype TopElem();
    bool Empty();
    void Makenul();
    void Print();
};

Stos::Stos(void)
{
    Top = -1;
}

void Stos::Push(elementtype x)
{
    if (Top < maxlegth - 1)
    {
        Top++;
        S[Top] = x;
    }
}

void Stos::Pop()
{
    if (Top >= 0)
        Top--;
}

elementtype Stos::TopElem()
{
    if (Top >= 0)
        return S[Top];
}

bool Stos::Empty()
{
    if (Top == -1)
        return true;
    else
        return false;
}

void Stos::Makenul()
{
    Top = -1;
}

void Stos::Print()
{
    int x = Top;
    while (x != -1)
    {
        cout << S[x] << " ";
        x--;
    }
    cout << endl;
}

// poza klasą - sprawdza czy to operator
bool IsOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '~':
        return true;
        break;

    default:
        return false;
        break;
    }
}