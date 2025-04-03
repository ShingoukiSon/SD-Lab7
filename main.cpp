#include <iostream>
#include <string.h>
#include "functii.h"
#include <fstream>
using namespace std;
ifstream fin("dictionar_termeni_PC.txt");
int main()
{
    int M,i;
    M=28;
    element *HT[M];
    initHT(HT,M);
    string key;
    while(fin>>key)
    {
        insert(HT,M,key);
    }
    fin.close();
    key="RAM";
    cout<<endl;
    AfisareTabel(HT,M);
    Afisare(HT,M,key);
}