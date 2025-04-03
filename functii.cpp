#include <iostream>
#include <string.h>
#include "functii.h"
using namespace std;



void initHT(element *HT[],int M)
{
    for(int i=0;i<M;i++)
    {
        HT[i]=0;
    }
}
int f(string key)
{
    int r;
    if(key[0]>='A' && key[0]<='Z')
        r=key[0]-65;
    else if (key[0]>='a' && key[0]<='z')
        r=key[0]-97;
    return r;
}
element *find(element *HT[],int M, string key)
{
    int h=f(key);
    element *p=HT[h];
    while(p)
    {
        if(p->key==key)
            return p;
        p=p->succ;
    }
    p=0;
    return p;
}
void insert(element *HT[],int M, string key)
{
    element *p;
    p=new element;
    p->key=key;
    int h=f(key);
    if(HT[h]==0)
    {
        HT[h]=p;
        HT[h]->succ=0;
    }
    else
    {
        element *q=find(HT,M,key);
        if(q==0)
        {
            p->succ=HT[h];
            HT[h]=p;
        }
    }

}

void AfisareTabel(element *HT[], int M)
{
    element *p;
    for (int i=0;i<M;i++)
    {
        if(HT[i])
        {   
            p=HT[i];
            while(p)
            {
                cout<<p->key<<' ';
                p=p->succ;
            }
            cout<<endl;
        }
    }   
}
void Afisare(element *HT[],int M, string key)
{
    int ok=1;
    element *p;
    for (int i=0;i<M && ok;i++)
    {
        p=HT[i];
        while(p)
        {
            if(p->key==key)
                {
                    cout<<p->key<<' ';
                    ok=0;
                }
            p=p->succ;
        }
    }
    if(ok)
        cout<<"N-am gasit boss";
}