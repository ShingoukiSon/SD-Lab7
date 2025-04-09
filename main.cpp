#include "functii.h"
#include <iostream>
using namespace std;

int main()
{
    /*stivas s;
    init(s);
    int x,y;
    cin>>x>>y;
    push(s,x);
    push(s,y);
    top(s);
    cout<<endl;
    pop(s);
    top(s);
    stivad *stiva;
    initD(stiva);
    cout<<endl;
    cin>>x>>y;
    pushD(stiva,x);
    pushD(stiva,y);
    topD(stiva);
    cout<<endl;
    popD(stiva);
    topD(stiva);*/
    stivad *s;
    initD(s);
    char expresie[50],postfix[50]={};
    cin>>expresie;
    postfixare(expresie,postfix,s);
    cout<<postfix;
    evaluarepostfix(s,postfix);
    int rez=topD(s)-48;
    cout<<endl<<rez;
    return 0;
}