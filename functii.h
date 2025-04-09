#pragma once

#define DIM 5
struct stivas
{
    int vect[DIM];
    int vf;
};

void init(stivas &s);
bool isEmpty(const stivas &s);
bool isFull(const stivas &s);
void push (stivas &s, int val);
void pop (stivas &s);
int top (const stivas &s);

struct stivad
{
    int data;
    stivad *succ;
};

void initD(stivad *&s);
bool isEmptyD(stivad *s);
void pushD (stivad *&s, int val);
void popD (stivad *&s);
int topD (stivad *s);
void postfixare(char expresie[], char postfix[], stivad *s);
void evaluarepostfix(stivad *&s,char postfix[]);