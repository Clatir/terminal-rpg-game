
using namespace std;

#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include "funkcje2.h"


void wczytaj_slownik()

{
    ifstream plik;
    plik.open("Slownik.txt");
    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac slowniczka ";
    else
    {
        string wiersz;
        while(getline(plik,wiersz))
        {


        cout<<wiersz<<endl;


        }

    }

}


void wczytaj_zasady()

{
    ifstream plik;
    plik.open("Zasady.txt");
    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac zasad gry ";
    else
    {
        string wiersz;
        while(getline(plik,wiersz))
        {


        cout<<wiersz<<endl;

        }

    }

}


int main1()
{
    return 0;
}
