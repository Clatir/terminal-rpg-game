
using namespace std;

#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include "funkcje2.h"

// plansza przeciwnikow to plansza na ktorej umieszczeni sa przeciwnicy, skrzynie, apteczki, trenerzy


void czyszcz_plansze(int y,int x,vector <vector <string> > plansza) // zastepowanie elementow planszy przeciwnikow elementem domyslnym
{
    plansza_przeciwnikow[y][x] = elem;
}


void sklauj_plansze_elem(int rozmiar,string elem ,vector <vector <string> > &plansza) // ustawianie rozmiaru planszy
{

    plansza.resize(rozmiar);
  for (int i = 0;i<plansza.size();i++)
    plansza[i].resize(rozmiar);
for (int i = 0; i < plansza.size();i++)
{
  for (int j = 0; j<plansza[i].size();j++)
  {
    plansza[i][j] = elem;
  }
}



}

void utworz_plansze_przeciwnikow(int rozmiar_planszy,int poziom_trudnosci,string prz) // dodawanie przeciwnikow, skrzyn, apteczek, trenerow do planszy przeciwnikow
{

int x=0,*w_x=&x,y=0,*w_y=&y,k=0,*w_k=&k,i=0,*w_i = &i;

    plansza_przeciwnikow.resize(rozmiar_planszy);
  for (*w_i = 0;*(w_i)<plansza_przeciwnikow.size();*(w_i)=*w_i+1)
    plansza_przeciwnikow[*w_i].resize(rozmiar_planszy);

for(i =0;i<rozmiar_planszy+poziom_trudnosci;i++) // apteczki
{
    *w_x= rand() % (rozmiar_planszy-1);
    *w_y= rand() % (rozmiar_planszy-1);
    plansza_przeciwnikow[*w_y][*w_x] = elem_apteczka;




}



for(int i =0;i<((rozmiar_planszy/2)+3);i++) // trenerzy
{

    *w_x= rand() % (rozmiar_planszy-1);
    *w_y= rand() % (rozmiar_planszy-1);

    if(plansza_przeciwnikow[*w_y][*w_x] != elem_apteczka)
        plansza_przeciwnikow[*w_y][*w_x] = elem_targ;


}

for(int i =0,wy=0;i<rozmiar_planszy/2;i++,wy++) // skrzynie
{

    *w_x= rand() % (rozmiar_planszy-1);
    if(plansza_przeciwnikow[wy][*w_x] != elem_apteczka and plansza_przeciwnikow[wy][*w_x] != elem_targ)
        plansza_przeciwnikow[wy][*w_x] = "S";

}

*w_k =1+(poziom_trudnosci-1)*0.5*2*3;




for(int i =0;i<k*rozmiar_planszy;i++) // przeciwnicy
{

    *w_x= rand() % (rozmiar_planszy-1);
    *w_y= rand() % (rozmiar_planszy-1);
    if(plansza_przeciwnikow[*w_y][*w_x] != elem_apteczka and plansza_przeciwnikow[*w_y][*w_x] != elem_targ and plansza_przeciwnikow[*w_y][*w_x] != "S")
        plansza_przeciwnikow[*w_y][*w_x] = elem_prz;
     *w_x= rand() % (rozmiar_planszy-1);
    if(plansza_przeciwnikow[*w_y][*w_x] != elem_apteczka and plansza_przeciwnikow[*w_y][*w_x] != elem_targ and plansza_przeciwnikow[*w_y][*w_x] != "S")
        plansza_przeciwnikow[*w_y][*w_x] = elem_prz;


}






for (int i = 0; i < plansza_przeciwnikow.size();i++)
{
  for (int j = 0; j<plansza_przeciwnikow[i].size();j++)
  {
    if(plansza_przeciwnikow[i][j] == "")
        plansza_przeciwnikow[i][j] = elem;
  }
}


}

void pokaz_plansze(vector <vector <string> > plansza) // wyswietlanie plalnszy
{
    for(int i =0; i<plansza.size();i++)
    {
        for(int j=0; j<plansza.size(); j++)
        {
            cout<<plansza[i][j]<<" ";
        }
        cout<<endl;
    }
    //getch();
    //pokaz_plansze2();
    //system("CLS");

}

