
using namespace std;

#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include "funkcje2.h"




void postac::pokaz_ekwipunek()
    {
        bool czy_pusty =1;
        for(int i =0; i<500;i++)
            {
                if(ekwipunek[i]!="")
                    czy_pusty =0;
            }
        if(czy_pusty)
            cout<<"Aktualnie nie posiadasz zadnych przedmiotow "<<endl;
        else
        {

         for(int i =0; i<500;i++)
            {
                if(ekwipunek[2*i]!="" and to_string(stoi(ekwipunek[2*i+1]))!="" and (stoi(ekwipunek[2*i+1])!=0))
                    cout<<ekwipunek[2*i]<<" "<<ekwipunek[(2*i)+1]<<endl;

            }
            }

    }


      void postac::nadaj_atrybuty(string nw, int zdr, int atk, int prd, int pln)
    {
        nazwa = nw;
        zdrowie = zdr;
        atak = atk;
        predkosc = prd;
        pieniadze = pln;

    }

    void postac::chodzenie()
{
    plansza_przeciwnikow[2][2] ="T";

    //pokaz_plansze();
    //system("CLS");
    //getch();
    pokaz_plansze();
    int przycisk;
    while(true)
    {
        if(pozycja_x == rozmiar_planszy -1 and pozycja_y == rozmiar_planszy -1)
            {
                system("CLS");
                cout<<"Gratulujemy ukonczenia gry "<<endl;
                getch();
                plansza_przeciwnikow.clear();
                for(int i =0; i<1000;i++)
                            ekwipunek[i]="";
                poziom_trudnosci =2;

                main();

            }

        przycisk = getch();
        switch(przycisk)
        {
        case 'w':
            if(pozycja_y ==0)
            {
                plansza[pozycja_y][pozycja_x] = toupper(nazwa[0]);
            }
            else
            {

            pozycja_y-=1;
            plansza[pozycja_y+1][pozycja_x] = "*";
            plansza[pozycja_y][pozycja_x]=toupper( nazwa[0]);
            if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_prz)
                {
                walcz();

                system("CLS");
                }

            if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_skrzynka)
                {
                cout<<"Znajdujesz skrzynke. "<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                obsluga_menu_s();
                system("CLS");


                }

            if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_apteczka)
                {
                cout<<"Znajdujesz apteczke."<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();

                obsluga_menu_apt();

                system("CLS");


                }


                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_targ)
                {
                cout<<"Na trasie swojej wendrowki zauwazasz trenera"<<endl;

                getch();
                obsluga_menu_t_g();
                //getch();


                system("CLS");


                }


            system("CLS");
            pokaz_plansze();
            }



            break;
        case 'a':
            if(pozycja_x == 0)
            {
            plansza[pozycja_y][pozycja_x] = toupper(nazwa[0]);
            }
            else
            {


            pozycja_x-=1;
            plansza[pozycja_y][pozycja_x+1] = "*";
             plansza[pozycja_y][pozycja_x]= toupper(nazwa[0]);
             if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_prz)
                {
                walcz();

                system("CLS");

                }

                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_skrzynka)
                {
                cout<<"Znajdujesz skrzynke. "<<endl<<" Czy chcesz ja otworzyc "<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                obsluga_menu_s();
                system("CLS");

                }

                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_apteczka)
                {
                cout<<"Znajdujesz apteczke."<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                 obsluga_menu_apt();


                system("CLS");


                }


                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_targ)
                {
                cout<<"Na trasie swojej wendrowki zauwazasz trenera"<<endl;
                plansza[pozycja_y][pozycja_x] == elem_targ;
                getch();
                obsluga_menu_t_g();
                //getch();


                system("CLS");


                }

             system("CLS");
            pokaz_plansze();
            }
            break;
        case 's':
            if(pozycja_y == rozmiar_planszy-1)
            {
                plansza[pozycja_y][pozycja_x] = toupper(nazwa[0]);
            }
            else
            {

            pozycja_y+=1;
            plansza[pozycja_y-1][pozycja_x] = "*";
             plansza[pozycja_y][pozycja_x]= toupper(nazwa[0]);
             if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_prz)
                {
                walcz();

                system("CLS");

                }

                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_skrzynka)
                {
                cout<<"Znajdujesz skrzynke. "<<endl<<" Czy chcesz ja otworzyc "<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                obsluga_menu_s();
                system("CLS");

                }
                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_apteczka)
                {
                cout<<"Znajdujesz apteczke."<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                 obsluga_menu_apt();



                system("CLS");


                }


                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_targ)
                {
                cout<<"Na trasie swojej wendrowki zauwazasz trenera"<<endl;


                getch();
                obsluga_menu_t_g();

                //getch();

                system("CLS");


                }

             system("CLS");
            pokaz_plansze();
            }
            break;
        case 'd':
            if(pozycja_x == rozmiar_planszy -1)
            {
                plansza[pozycja_y][pozycja_x] = toupper(nazwa[0]);
            }
            else
            {

            pozycja_x+=1;
            plansza[pozycja_y][pozycja_x-1] = "*";
             plansza[pozycja_y][pozycja_x]= toupper(nazwa[0]);
             if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_prz)
                {
                walcz();

                system("CLS");

                }
                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_skrzynka)
                {
                cout<<"Znajdujesz skrzynke. "<<endl<<" Czy chcesz ja otworzyc "<<endl;
               czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                obsluga_menu_s();
                system("CLS");

                }
                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_apteczka)
                {
                cout<<"Znajdujesz apteczke."<<endl;
                czyszcz_plansze(pozycja_y,pozycja_x);
                getch();
                 obsluga_menu_apt();


                system("CLS");


                }


                if(plansza_przeciwnikow[pozycja_y][pozycja_x] == elem_targ)
                {
                cout<<"Na trasie swojej wendrowki zauwazasz trenera"<<endl;

                getch();
                obsluga_menu_t_g();

                //getch();

                system("CLS");


                }


            system("CLS");
            pokaz_plansze();
            }

            break;

        }


    }

}


 void postac::pokaz_statystyki()
    {
        cout<<"Nazwa: "<<nazwa<<endl
            <<"Pozycja x: "<<pozycja_x<<endl
            <<"Pozycja y: "<<pozycja_y<<endl
            <<"Zdrowie: "<<zdrowie<<endl
            <<"Atak: "<<atak<<endl
            <<"Predkosc: "<<predkosc<<endl
            <<"Ilosc monet: "<<pieniadze<<endl;
            getch();
            system("CLS");



    }
    void postac:: pokaz_statystyki_przeciwnika()
    {
        //cout<<"Nazwa: "<<nazwa<<endl
            cout<<"Zdrowie: "<<zdrowie<<endl
            <<"Atak: "<<atak<<endl
            <<"Predkosc: "<<predkosc<<endl
            <<"Ilosc monet: "<<pieniadze<<endl;
            getch();
            //system("CLS");



    }

    void postac:: dodaj_pieniadze(int ile)
    {
        pieniadze+=ile;
    }
    void postac:: pokaz_pieniadze()
    {
        cout<<pieniadze;
    }
    postac::postac(string n, int x, int y, int z, int a , int s, int g)
    {
        nazwa =n;
        pozycja_x =x;
        pozycja_y=y;
        zdrowie =z;
        atak = a;
        predkosc =s;
        pieniadze =g;
    }



