#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include"Txt_start.cpp"
#include"Plansza.cpp"
#include"Menu.cpp"
#include "Postac2.cpp"
#include "funkcje2.h"
#include "Trener.cpp"
#include "Walka.cpp"




using namespace std;
ifstream fin;









void graj() // obsluga funkcji rozpoczynajacej rozgrywke
{
    obsluga_menu_rp();



    string statystyki_gracza[1000];
    int dl = sizeof(statystyki_gracza)/sizeof(statystyki_gracza[0]);
    int nr_wiersza=0;
    for(int i =0; i<dl;i++)
    statystyki_gracza[i] = "";


    ifstream plik;
    plik.open("Statystyki.txt");
    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac statystyk gracza ";
    else
    {
        string wiersz;
        while(getline(plik,wiersz))
        {
        statystyki_gracza[nr_wiersza] = wiersz;
        nr_wiersza++;

        }

            gracz.pozycja_y = stoi(statystyki_gracza[0]);
            gracz.pozycja_x = stoi(statystyki_gracza[1]);
            gracz.zdrowie = stoi(statystyki_gracza[2]);
            gracz.atak = stoi(statystyki_gracza[3]);
            gracz.predkosc = stoi(statystyki_gracza[4]);
            gracz.pieniadze = stoi(statystyki_gracza[5]);
   }






    utworz_plansze_przeciwnikow(rozmiar_planszy,poziom_trudnosci);
    //pokaz_plansze(plansza_przeciwnikow);

    string imiePostaci;
    cout<<"Jak sie nazywasz "<<endl;
    cin>>imiePostaci;
    system("CLS");
    gracz.nazwa = imiePostaci;
    gracz.pokaz_statystyki();
    plansza[gracz.pozycja_y][gracz.pozycja_x] = toupper(imiePostaci[0]);





    for(int i =1; i<rozmiar_planszy;i++)
    {   if(i%2 == 0)
            plansza_przeciwnikow[i][i] = elem_targ;


    }




    gracz.chodzenie();


}



void ustaw_maks_zdrowie() // ustawianie maksymalnej wartosci zdrowia gracza
{


ifstream plik;
    string wiersz="0";
    zdrowie_maks=stoi(wiersz);

    int linia=0;
    plik.open("Statystyki.txt");

    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac statystyk do menu apteczki ";
    else
    {



        while(getline(plik,wiersz))
        {
            if (linia!=2)
                linia++;
            else
                {zdrowie_maks = stoi(wiersz);
                break;
                }



        }
    }
}


void czysc_tablice() // czyszczenie ekwipunku
{

    for(int i =0; i<1000-1; i++)
    {
        for(int j=i+1;j<1000;j++)
        {
            if(*(ekwipunek +i) == *(ekwipunek +j) and *(ekwipunek +i) != "" and ekwipunek[i].length()>5)
            {
                int liczba =0;
                liczba = stoi(ekwipunek[i+1]);
                liczba++;
                ekwipunek[i+1] = to_string(liczba);
                ekwipunek[j] = "";
                ekwipunek[j+1]="";
            }
        }
    }
}


void dodaj_do_ekwipunku(string nazwa_przedmiotu, int ilosc) // dodawanie przedmiotu do ekwipunku
    {
    ifstream plik;

    int ind =0;
    plik.open("Ekwipunek.txt");
    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac ekwipunku ";
    else
    {
        string wiersz;
        string slowo = "";
        string liczba = "";

        while(getline(plik,wiersz))
        {


            slowo.clear();


            for(int i =0; i<wiersz.length();i++)
            {
                if((wiersz[i]>='A' and wiersz[i]<='z') or (wiersz[i] == 32))
                    slowo.push_back(wiersz[i]);




            }

            if((slowo == nazwa_przedmiotu))
            {


                        while(ekwipunek[ind]!="")
                            ind++;


                            ekwipunek[ind] = nazwa_przedmiotu;

                            ind++;
                            ekwipunek[ind] = to_string(ilosc);

                            ind++;


            }





        }



    }
    czysc_tablice();





    }




int main()
{

srand(time(NULL));

obsluga_menu_gl();



    return 0;
}
