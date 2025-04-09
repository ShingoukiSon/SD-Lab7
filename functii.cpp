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
    else 
        r=100;
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
    if(HT[h]==0 and h!=100)
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
    int ok=1,h;
    h=f(key);
    if (h==100)
    {
        cout<<"n-am gasit"<<endl;
    }
    else
    {
        element *p=find(HT,M,key);
        if(p)
        {
            cout<<p->key<<endl;
        }
        else
            cout<<"n-am gasit boss"<<endl;
    }
}

void Stergere(element *HT[],int M, string key)
{
    int ok=1,h;
    h=f(key);
    if (h==100)
    {
        cout<<"n-am gasit"<<endl;
    }
    else
    {
        if(HT[h]->key==key)
        {
            element*p=HT[h];
            HT[h]=HT[h]->succ;
            delete p;
        }
        else
        {
        element *p=HT[h];
        while(p->succ)
        {
            if(p->succ->key==key)
            {
                element *q=p;
                q=q->succ;
                p->succ=p->succ->succ;
                delete q;
                break;
            }
            p=p->succ;
        }
        cout<<"n-am gasit boss"<<endl;
        }
    }
}
int numarare(element *HT[], int M)
{
    int c=0;
    for (int i=0;i<M;i++)
    {
        if(HT[i])
        {   
            element *p=HT[i];
            while(p)
            {
                c++;
                p=p->succ;
            }
        }
    }
    return c;
}
void Cluster(element *HT[],int M)
{
    int N=numarare(HT,M),c;
    float alpha=N/M,sum=0;
    for (int i=0;i<M;i++)
    {   
        c=0;
        if(HT[i])
        {   
            element *p=HT[i];
            while(p)
            {
                c++;
                p=p->succ;
            }
        }
        sum=sum+(float)(c*c)/N;
    }
    sum=sum-alpha;
    cout<<sum<<endl;
    if(sum>1)
        cout<<"tabela hash este afectate de clusterizare";
    else
        cout<<"tabela hash nu este afectate de clusterizare";
}
void frec(element *HT[], int M)
{
    int c[26]={};
    char s[]="Aa";
    for (int i=0;i<M;i++)
    {
        if(HT[i])
        {   
            element *p=HT[i];
            while(p)
            {
                if(p->key[0]>='A' && p->key[0]<='Z')
                    c[p->key[0]-65]++;
                if(p->key[0]>='a' && p->key[0]<='z')
                    c[p->key[0]-97]++;
                p=p->succ;
            }
        }
    }
    for (int i=0;i<26;i++)
    {
        cout<<s<<' '<<c[i]<<endl;
        s[0]++;
        s[1]++;
    }
}