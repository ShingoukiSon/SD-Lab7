#include <iostream>
#include <string.h>
#include "functii.h"
#include <fstream>
using namespace std;
ifstream fin("dictionar_termeni_PC.txt");
int main()
{
    int M,i;
    M=26;
    element *HT[M];
    initHT(HT,M);
    string key;
    while(fin>>key)
    {
        insert(HT,M,key);
    }
    fin.close();
    cout<<endl;
    AfisareTabel(HT,M);
    Afisare(HT,M,"RAM");
    Afisare(HT,M,"RA");
    Afisare(HT,M,"[][]");
    cout<<endl;
    Cluster(HT,M);
    cout<<endl;
    frec(HT,M);
    
}