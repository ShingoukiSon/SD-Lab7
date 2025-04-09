#include "functii.h"
#include <iostream>
#include <string.h>
using namespace std;

void init(stivas &s)
{
    s.vf=-1;
}

bool isEmpty(const stivas &s)
{
    if(s.vf==-1)
        return true;
    else
        return false;
}

bool isFull(const stivas &s)
{
    if(s.vf==DIM-1)
        return true;
    else
        return false;
}
void push (stivas &s, int val)
{
    if(!isFull(s))
    {
        s.vf++;
        s.vect[s.vf]=val;   
    }
    else
    {
        cout<<"stiva este plina\n";
    }
}

void pop (stivas &s)
{
    if(!isEmpty(s))
    {
        s.vf--;
    }
    else
    {
        cout<<"stiva vida\n";
    }
}

int top (const stivas &s)
{
    if(!isEmpty(s))
    {
        return s.vect[s.vf];
    }
    else
    {
        return 0;
    }
}

void initD(stivad *&s)
{
    s=0;
}

bool isEmptyD(stivad *s)
{
    if(s==0)
        return true;
    else
        return false;
}

void pushD (stivad *&s, int val)
{
    stivad *p=new stivad;
    p->data=val;
    p->succ=s;
    s=p;
}

void popD (stivad *&s)
{
    if(!isEmptyD(s))
    {
        stivad *p=s;
        s=s->succ;
        delete p;
    }
    else
    {
        cout<<"stiva vida\n";
    }
}

int topD (stivad *s)
{
    if(!isEmptyD(s))
    {
        return s->data;
    }
    
    return 0;
}

void postfixare(char expresie[], char postfix[], stivad *s)
{
    int i,j=0;
    for(i=0;i<strlen(expresie);i++)
    {
        if(expresie[i]>='0' && expresie[i]<='9')
            postfix[j++]=expresie[i];
        else if(strchr("+-*/",expresie[i]))
            {
                if(isEmptyD(s))
                    {
                        pushD(s,expresie[i]);
                    }
                else
                {   
                    int ok=1;
                    while(topD(s)!='(' && s!=0 && ok)
                    {
                        if((expresie[i]=='*' || expresie[i]=='/') && (topD(s)=='+' || topD(s)=='-'))
                        {   
                            ok=0;
                        }
                        else
                        {
                            postfix[j++]=topD(s);
                            popD(s);
                        }
                    }
                    pushD(s,expresie[i]);
                }
            }
            else if(expresie[i]=='(')
                pushD(s,expresie[i]);
                else if(expresie[i]==')')
                {
                    while(topD(s)!='(')
                    {
                        postfix[j++]=topD(s);
                        popD(s);
                    }
                    popD(s);
                }
    }
    while(s!=0)
    {   
        postfix[j++]=topD(s);
        popD(s);
    }
}
void evaluarepostfix(stivad *&s,char postfix[])
{
    int i=0,x,y,rez;
    while(postfix[i])
    {
        if(postfix[i]>='0' && postfix[i]<='9')
            pushD(s,postfix[i]);
        else if(strchr("+-*/",postfix[i]))
        {
            x=topD(s)-48;
            popD(s);
            y=topD(s)-48;
            popD(s);
            switch (postfix[i])
            {
            case '+':
                rez=x+y;
                break;
            
            case '-':
                rez=y-x;
                break;
            case '*':
                rez=x*y;
                break;
            case '/':
                rez=y/x;
                break;
            }
            pushD(s,rez+48);
        }
        i++;
    }

}

void prefixrec(char expresie[], char prefix[], stivad *s)
{
    
}
