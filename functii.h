#pragma once

#include <string.h>
#include <fstream>
struct element
{
    std::string key;
    element *succ;
};

void initHT(element *HT[],int M);
int f(std::string key);
element *find(element *HT[],int M, std::string key);
void insert(element *HT[],int M, std::string key);
void AfisareTabel(element *HT[], int M);
void Afisare(element *HT[],int M, std::string key);
