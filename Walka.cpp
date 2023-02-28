
using namespace std;

#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include "funkcje2.h"

void opcje_w(int pos) // obsluga menu walki z przeciwnikiem cz.1
{
        ustaw_maks_zdrowie();

    string opcje[liczba_opcji_w] = {" 1. Atakowanie ", " 2. Uciekaj", " 3. Skorzystaj z apteczki"};
    opcje[(pos)][0] = '>';

    system("CLS");
    cout<<"Wybierz opcje za pomoca strzalek, nastepnie wcisnij ENTER"<<endl;
    for(int i = 0; i<liczba_opcji_w; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_w(int dzialanie,postac przeciwnik) // obsluga menu walki z przeciwnikiem cz.2
{
ustaw_maks_zdrowie();
    switch(dzialanie)
    {
    case 0:
        //cout<<"Atakowanie "<<endl;
        atak(przeciwnik,gracz);
        break;
    case 1:
        {
            if(poziom_trudnosci == 1)
                {cout<<"Uciekles przeciwnikowi "<<endl;
                getch();
                break;

                }
            if(poziom_trudnosci == 2 or poziom_trudnosci == 3)
            {
                int los = rand() % 4;
                if(los%2 ==0)
                    {
                        cout<<"Tym razem udalo ci sie uciec ";
                        getch();
                        break;
                    }
                else
                {
                    cout<<"Proba ucieczki zakonczona niepowodzeniem "<<endl;
                    getch();
                    atak(przeciwnik,gracz);
                    break;

                }
                if(poziom_trudnosci == 3)
                {
                    if(los == 0 or los == 3)
                    {   cout<<"Tym razem udalo ci sie uciec ";
                        getch();
                        break;

                    }

                    else
                    {
                        cout<<"Proba ucieczki zakonczona niepowodzeniem "<<endl;
                    getch();
                    atak(przeciwnik,gracz);
                    break;
                    }

                }
            }
        }
        break;
    case 2:
        bool posiadanie=0;
        int ind=0;
        for(int i =0; i<1000; i++)
        {
            if(ekwipunek[i] == "Podreczna apteczka " and ekwipunek[i+1]!="0" and ekwipunek[i+1]!="")
                posiadanie = 1;
                ind = i;
                //cout<<"Indeks ="<<ind<<"|"<<endl;
                i=1001;
               // cout<<"Jest "<<stoi(ekwipunek[ind+1])<<" apteczek "<<endl;

        }
        if(posiadanie)
            {   int sztuk=0;


                        if(gracz.zdrowie == zdrowie_maks)
                            {cout<<"Masz maksymalna ilosc zdrowia "<<endl;
                            getch();

                            obsluga_menu_w(przeciwnik);
                            break;
                            }

                        if((gracz.zdrowie+0.2*zdrowie_maks)<=zdrowie_maks)
                        {


                                gracz.zdrowie+=0.2*zdrowie_maks;
                            cout<<"Masz teraz "<<gracz.zdrowie<<" zdrowia "<<endl;
                            getch();

                            sztuk =stoi(ekwipunek[ind+1]);
                            ekwipunek[ind+1]=to_string(sztuk-1);
                            cout<<"Pozostalo ci "<<(ekwipunek[ind+1]) <<" apteczek "<<endl;
                            //ekwipunek[ind+1] = to_string(stoi(ekwipunek[ind+1])-1);

                            //cout<<"Zawartosc tablicy "<<endl;
                           // for(int i =0; i<1000;i++)
                                //cout<<"i = "<<i<<" ekwipunek[i] ="<<ekwipunek[i]<<"|"<<endl;

                           // cout<<"Pozostalo ci "<<ekwipunek[ind+1] <<"apteczek "<<endl;
                            getch();
                            obsluga_menu_w(przeciwnik);



                        }


                        if((gracz.zdrowie+=0.2*zdrowie_maks)>=zdrowie_maks)
                        {



                            gracz.zdrowie=zdrowie_maks;

                            cout<<"Masz teraz "<<gracz.zdrowie<<" zdrowia "<<endl;
                            getch();
                            cout<<"Zawartosc tablicy "<<endl;
                          //  for(int i =0; i<1000;i++)
                               // cout<<"i = "<<i<<" ekwipunek[i] ="<<ekwipunek[i]<<"|"<<endl;


                            sztuk = stoi(ekwipunek[ind+1]);
                            ekwipunek[ind+1]=to_string(sztuk-1);
                            cout<<"Pozostalo ci "<<(ekwipunek[ind+1]) <<"apteczek "<<endl;
                            getch();
                            obsluga_menu_w(przeciwnik);










                        }





            }
        else
            {
                cout<<"Nie ma apteczek w ekwipunku "<<endl;
                getch();
                obsluga_menu_w(przeciwnik);

            }






    }
}

void obsluga_menu_w(postac przeciwnik) // obsluga menu walki z przeciwnikiem cz.3
{
    int pos = 0,*w_pos = &pos;
    unsigned char input = 0;




    do
    {
        opcje_w(pos);
        input = getch();
        if(input=='w' or input == 's')
        {
            if(input == 'w')
            {
                if(pos == 0)
                    pos=liczba_opcji_w-1;
                else
                    pos = pos -1;
            }
            else if(input == 's')
            {
                if(pos == liczba_opcji_w-1)
                    pos = 0;
                else
                    pos = pos +1;
            }
        }

    }
    while(input != 13);

    menu_w(pos,przeciwnik);
}


void atak(postac &przeciwnik,postac &nasz = gracz)
{

while(nasz.zdrowie>0 and przeciwnik.zdrowie>0)
   {
int atak_naszego = rand() % nasz.atak + 1;
int atak_przeciwnika = rand() % przeciwnik.atak + 1;
    if(nasz.predkosc>przeciwnik.predkosc)
        {przeciwnik.zdrowie -= atak_naszego;
        cout<<przeciwnik.nazwa<<" otrzymuje "<<atak_naszego<<" punktow obrazen "<<endl;
        getch();
        if(przeciwnik.zdrowie<=0)
            break;
        nasz.zdrowie -= atak_przeciwnika;
        if(nasz.zdrowie<=0)
            break;
        cout<<nasz.nazwa<<" otrzymuje "<<atak_przeciwnika<<" punktow obrazen "<<endl;
        getch();





        }

    else
        {
            nasz.zdrowie -= atak_przeciwnika;
            cout<<nasz.nazwa<<" otrzymuje "<<atak_przeciwnika<<" punktow obrazen "<<endl;
            getch();
            if(nasz.zdrowie<=0)
            break;
            przeciwnik.zdrowie -= atak_naszego;
            cout<<przeciwnik.nazwa<<" otrzymuje "<<atak_naszego<<" punktow obrazen "<<endl;
            getch();
            if(przeciwnik.zdrowie<=0)
            break;




        }


}
if(nasz.zdrowie <= 0)
        {


            for(int i =0;i<250;i++)
            {
                ekwipunek[2*i+1] = ("0");
            }


            cout<<przeciwnik.nazwa<<" pokonuje Ciebie "<<endl;
            getch();

            plansza_przeciwnikow.clear();

                for(int i =0; i<1000;i++)
                            ekwipunek[i]="";
                poziom_trudnosci =2;

                main();





        }
if(przeciwnik.zdrowie <= 0)
        {


        ifstream plik;
    string przedmioty[1000] = {""};
    int wierszy =0, poz=0;
    plik.open("Ekwipunek.txt");

    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac nagrody po walce ";
    else
    {
        string wiersz;
        string slowo = "";

        while(getline(plik,wiersz))
        {

            slowo = "";

            for(int i =0; i<wiersz.length();i++)
            {
            if((wiersz[i]>='A' and wiersz[i]<='z') or (wiersz[i] == 32))

            slowo.push_back(wiersz[i]);

            }
            przedmioty[poz] = slowo;
            poz++;
            wierszy++;


        }


    }

    for(int i =0; i<2*wierszy+1;i++)
    {
        //cout<<"i = "<<i<<" "<<ekwipunek[i]<<"0"<<endl;
    }

        int indeks = rand() % (wierszy-1);
        int ilosc =rand()%poziom_trudnosci+1;




        dodaj_do_ekwipunku(przedmioty[indeks],ilosc);




            cout<<przeciwnik.nazwa<<" zostaje pokanany "<<endl;






            czyszcz_plansze(nasz.pozycja_y,nasz.pozycja_x);


            cout<<"Pozostalo tobie "<<gracz.zdrowie<<" punktow zdrowia "<<endl<<endl;

            cout<<przeciwnik.nazwa<<" pozostawia po sobie "<<przedmioty[indeks]<<" w ilosci "<<ilosc<<" oraz "<<przeciwnik.pieniadze<<" monet "<<endl;
            gracz.pieniadze+=przeciwnik.pieniadze;
            getch();

            cout<<"Twoj ekwipunek to: "<<endl;
            gracz.pokaz_ekwipunek();
            cout<<"oraz ";
            gracz.pokaz_pieniadze();
            cout<<" monet";
            getch();

        }

}

void walcz()
{




string info_o_przeciwnikach[1000];
int dl = sizeof(info_o_przeciwnikach)/sizeof(info_o_przeciwnikach[0]);
int nr_wiersza=0;
int i=0,*w_i =&i;
for(*(w_i) =0; *w_i<dl;*(w_i)=*(w_i)+1)
    info_o_przeciwnikach[*(w_i)] = "";


    ifstream plik;
    plik.open("Przeciwnicy.txt");
    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac przeciwnika ";
    else
    {
        string wiersz;
        while(getline(plik,wiersz))
        {
        info_o_przeciwnikach[nr_wiersza] = wiersz;
        //cout<<info_o_przeciwnikach[nr_wiersza]<<endl;
        nr_wiersza++;


        }

    }

    postac przeciwnik[2*nr_wiersza];
    for(*w_i =0; *w_i<(nr_wiersza/5);*w_i=*w_i+1)
    {
        int indeks = *w_i*5;
        //cout<<" Indeks: "<<indeks<<endl;

        przeciwnik[*w_i].nadaj_atrybuty(info_o_przeciwnikach[indeks],stoi(info_o_przeciwnikach[indeks+1]),stoi(info_o_przeciwnikach[indeks+2]),stoi(info_o_przeciwnikach[indeks+3]),stoi(info_o_przeciwnikach[indeks+4]));

    }

    int numer_przeciwnika = rand() % (nr_wiersza/5);




    //cout<<numer_przeciwnika<<endl;
    cout<<"Na twojej drodze staje: "<<przeciwnik[numer_przeciwnika].nazwa<<endl;
    przeciwnik[numer_przeciwnika].pokaz_statystyki_przeciwnika();
    cout<<endl<<"Twoje statystyki to: "<<endl;gracz.pokaz_statystyki_przeciwnika();
    //cout<<"Jego stan konta wynosi "<<przeciwnik[numer_przeciwnika].pieniadze<<endl;

    //getch();



    obsluga_menu_w(przeciwnik[numer_przeciwnika]);



}
