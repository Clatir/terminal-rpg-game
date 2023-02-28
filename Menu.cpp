using namespace std;

#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include "Funkcje2.h"



void opcje_gl(int *pos) // obsluga menu glownego cz.1
{

    string opcje[liczba_opcji_gl] = {" 1. Rozpocznij gre ", " 2. Wczytaj slownik", " 3. Pokaz opis gry", " 4. Wyjdz z gry"};
    opcje[*(pos)][0] = '>';

    system("CLS");
    cout<<"Wybierz opcje "<<endl;
    for(int i = 0; i<liczba_opcji_gl; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_glowne(int *(dzialanie)) // obsluga menu glownego cz.2
{



    if(*(dzialanie) == 0)
        {


        cout<<"Uruchamianie gry "<<endl;
        dodaj_do_ekwipunku("Podreczna apteczka ",3);
        obsluga_menu_pt();
        graj();
        }
    else if(*(dzialanie) == 1)
        {


        wczytaj_slownik();
        getch();
        obsluga_menu_gl();

        }
    else if(*(dzialanie) == 2)
        {


        wczytaj_zasady();
        getch();
        obsluga_menu_gl();
        }
    else if(*(dzialanie) ==3)
    {
         system("taskkill /im cb_console_runner.exe /f");

    }
    else
    {cout<<"Wystapil problem przy dzialaniu funkcji menu_glowne "<<endl;
    getch();
    }


}
void obsluga_menu_gl() // obsluga menu glownego cz.3
{
    int pos = 0, *w_pos=&pos;
    unsigned char input = 0;




    do
    {
        opcje_gl((w_pos));
        input = getch();
        if(input=='w' or input == 's')
        {

            if(input == 'w')
            {
                if((*w_pos) == 0)
                    (*w_pos)=liczba_opcji_gl-1;
                else
                    (*w_pos)= (*w_pos) -1;
            }
            else if(input == 's')
            {
                if((*w_pos) == liczba_opcji_gl-1)
                    (*w_pos) = 0;
                else
                    (*w_pos) = (*w_pos)+1;
            }
        }

    }
    while(input != 13);

    menu_glowne((w_pos));
}



void opcje_rp(int *(pos)) // obsluga menu rozmiaru planszy cz.1
{

    string opcje[liczba_opcji_rp] = {" 1. Mala ", " 2. Srednia"," 3. Duza"};
    opcje[*(pos)][0] = '>';

    system("CLS");
    cout<<"Wybierz rozmiar mapy "<<endl;
    for(int i = 0; i<liczba_opcji_rp; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_rp(int (*dzialanie)) // obsluga menu rozmiaru planszy cz.2
{

    if((*dzialanie) == 0)
    {cout<<"Utworzono plansze mala "<<endl;
        sklauj_plansze_elem(10);
        rozmiar_planszy = 10;

    }



    else if ((*dzialanie) == 1)
    {
         cout<<"Utworzono plansze srednia "<<endl;
        sklauj_plansze_elem(20);
        rozmiar_planszy = 20;

    }



    else if ((*dzialanie) == 2)
    {
        cout<<"Utworzono plansze duza "<<endl;
        sklauj_plansze_elem(30);
        rozmiar_planszy = 30;
    }




   //utworz_plansze_przeciwnikow(rozmiar_planszy);
   //pokaz_plansze(plansza_przeciwnikow);
   getch();
   system("CLS");

}
void obsluga_menu_rp() // obsluga menu rozmiaru planszy cz.3
{
    int pos = 0, *w_pos;
    w_pos = &pos;
    unsigned char input = 0;




    do
    {
        opcje_rp((w_pos));
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if((*w_pos) == 0)
                    (*w_pos)=liczba_opcji_rp-1;
                else
                    (*w_pos)=(*w_pos)-1;
            }
            else if(input == 's')
            {
                if((*w_pos) == liczba_opcji_rp-1)
                    (*w_pos) = 0;
                else
                    (*w_pos)=(*w_pos)+1;
            }
        }

    }
    while(input != 13);

    menu_rp((w_pos));
}
void opcje_pt(int (*pos)) // obsluga menu poziomu trudnosci cz.1
{

    string opcje[liczba_opcji_rp] = {" 1. Latwy ", " 2. Sredni"," 3. Trudny"};
    opcje[(*pos)][0] = '>';

    system("CLS");
    cout<<"Wybierz poziom trudnosci "<<endl;
    for(int i = 0; i<liczba_opcji_pt; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_pt(int *dzialanie) // obsluga menu poziomu trudnosci cz.2
{


    if((*dzialanie) == 0)
        poziom_trudnosci =1;

    else if((*dzialanie) == 0)
       poziom_trudnosci =2;
    else if((*dzialanie) == 3)
        poziom_trudnosci =3;
    else
        {//cout<<"Wystapil problem przy ustawieniu poziomu trudnosci "<<endl;
        //getch();
        }




   system("CLS");

}
void obsluga_menu_pt() // obsluga menu poziomu trudnosci cz.3
{
    int pos = 0,*w_pos=&pos;
    unsigned char input = 0;




    do
    {
        opcje_pt((w_pos));
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if((*w_pos) == 0)
                    (*w_pos)=liczba_opcji_pt-1;
                else
                    (*w_pos)=(*w_pos)-1;
            }
            else if(input == 's')
            {
                if((*w_pos) == liczba_opcji_pt-1)
                    (*w_pos) = 0;
                else
                    (*w_pos)=(*w_pos)+1;
            }
        }

    }
    while(input != 13);

    menu_pt((w_pos));
}



void opcje_apt(int (*pos)) // obsluga menu apteczek cz.1
{

    string opcje[liczba_opcji_apt] = {" 1. Uzyj apteczki ", " 2. Schowaj apteczke do ekwipunku"};
    opcje[(*pos)][0] = '>';

    system("CLS");
    cout<<"Co chcesz zrobic z apteczka ? "<<endl;
    for(int i = 0; i<liczba_opcji_apt; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_apt(int *dzialanie) // obsluga menu apteczek cz.2
{

ustaw_maks_zdrowie();

bool stan =1;

while(stan)
{





    if((*dzialanie)==0)
    {
        if(gracz.zdrowie==zdrowie_maks)
            {cout<<"Masz maksymalnac liczbe zdrowia "<<endl
            <<"apteczka zostanie przeniesiona do ekwipunku "<<endl;
            dodaj_do_ekwipunku("Podreczna apteczka ",1);
            for(int i =0; i<1000; i++)
               {if(ekwipunek[i] == "Podreczna apteczka ")
                    {cout<<"Masz w ekwipunku "<<ekwipunek[i+1]<<" apteczek"<<endl;
                    getch();
                    stan=0;

                    }

               }
            }



         if((gracz.zdrowie+0.2*zdrowie_maks)<=zdrowie_maks and stan ==1)
            {
            gracz.zdrowie+=0.2*zdrowie_maks;
            cout<<"Masz teraz "<<gracz.zdrowie<<" zdrowia "<<endl;
            for(int i =0; i<1000; i++)
                {if(ekwipunek[i] == "Podreczna apteczka ")
                   {cout<<"Masz w ekwipunku "<<ekwipunek[i+1]<<" apteczek"<<endl;
                    getch();
                    stan=0;


                   }

                }



            }
        if((gracz.zdrowie+0.2*zdrowie_maks)>=zdrowie_maks and stan ==1)
            {
            gracz.zdrowie=zdrowie_maks;
            cout<<"Masz teraz "<<gracz.zdrowie<<" zdrowia "<<endl;
            for(int i =0; i<1000; i++)
               {if(ekwipunek[i] == "Podreczna apteczka ")
                    {cout<<"Masz w ekwipunku "<<ekwipunek[i+1]<<" apteczek"<<endl;
                    getch();
                    stan=0;

                    }


               }



            }
    }




    else if((*dzialanie)==1)
    {
        dodaj_do_ekwipunku("Podreczna apteczka ",1);
        stan=0;
       //for(int i =0; i<1000; i++)
       //{
       //    cout<<"i = "<<i<<" t[i] ="<<ekwipunek[i]<<"|"<<endl;
       //
    }
    else
    {
        cout<<"Wystapil blad przy dodawaniu apteczki do ekwipunku "<<endl;
        getch();
        stan=0;
    }
}

}






void obsluga_menu_apt() // obsluga menu apteczek cz.3
{
    int pos = 0,*w_pos = &pos;
    unsigned char input = 0;




    do
    {
        opcje_apt((w_pos));
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if((*w_pos) == 0)
                    (*w_pos)=liczba_opcji_apt-1;
                else
                    (*w_pos)=(*w_pos)-1;
            }
            else if(input == 's')
            {
                if((*w_pos) == liczba_opcji_apt-1)
                    (*w_pos) = 0;
                else
                    (*w_pos)=(*w_pos)+1;
            }
        }

    }
    while(input != 13);   //Enter

    menu_apt((w_pos));
}

void opcje_s(int (*pos)) // obsluga menu skrzyni cz.1
{

    string opcje[liczba_opcji_s] = {" 1. Otworz skrzynie ", " 2. Pozostaw skrzynie"};
    opcje[(*pos)][0] = '>';

    system("CLS");
    cout<<"Co chcesz zrobic ze skrzynka ?"<<endl;
    for(int i = 0; i<liczba_opcji_s; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_s(int *dzialanie) // obsluga menu skrzyni cz.2
{
    int zawartosc=0;
    int szansa=0;


    if((*dzialanie) == 0)
    {cout<<"Otwieranie skrzynki "<<endl;
        if(poziom_trudnosci == 1)
            {
            zawartosc = (rand() % 10 + 1)*poziom_trudnosci;
            gracz.pieniadze+=(zawartosc);
            cout<<"W skrzyni znajdowalo sie "<<zawartosc<<" monet, teraz masz "<<gracz.pieniadze<<" monet"<<endl;
            }






        if(poziom_trudnosci == 2)
        {
            szansa = (rand() % 4 + 1);
            if(szansa %2 == 7)
                {zawartosc = zawartosc = (rand() % 10 + 1)*poziom_trudnosci;
                gracz.pieniadze+=zawartosc;
                cout<<"W skrzyni znajdowalo sie "<<zawartosc<<" monet, teraz masz "<<gracz.pieniadze<<" monet"<<endl;
                }
            else
            {
                cout<<"Skrzynia okazala sie byc pulapka "<<"tracisz "<<ceil(0.10*float(gracz.zdrowie))<<" zdrowia "<<endl;
                gracz.zdrowie-=ceil(0.10*float(gracz.zdrowie));
                if(gracz.zdrowie<=0)
                    {
                        cout<<"Przegrywasz "<<endl;
                        getch();
                        plansza_przeciwnikow.clear();
                        obsluga_menu_gl();
                        for(int i =0; i<1000;i++)
                            ekwipunek[i]="";
                        poziom_trudnosci =2;
                    }
                cout<<"masz teraz "<<gracz.zdrowie<<" zdrowia "<<endl;
            }

        }


        if(poziom_trudnosci == 3)
        {
            szansa = (rand() % 3 + 1);
            if(szansa %2 == 0)
                {zawartosc = zawartosc = (rand() % 10 + 1)*poziom_trudnosci;
                gracz.pieniadze+=zawartosc;
                cout<<"W skrzyni znajdowalo sie "<<zawartosc<<" monet, teraz masz "<<gracz.pieniadze<<" monet"<<endl;
                }
            else
            {
                cout<<"Skrzynia okazala sie byc pulapka "<<"tracisz "<<ceil(0.20*float(gracz.zdrowie))<<" zdrowia "<<endl;
                gracz.zdrowie-=ceil(0.20*float(gracz.zdrowie));
                if(gracz.zdrowie<=0)
                    {
                        cout<<"Przegrywasz "<<endl;
                        getch();
                        plansza_przeciwnikow.clear();
                        obsluga_menu_gl();
                    }
                cout<<"masz teraz "<<gracz.zdrowie<<" zdrowia "<<endl;
            }

        }

    }

    else if((*dzialanie) == 1)
        cout<<"Pozostawiles skrzynke "<<endl;
    else
        cout<<"Wystapil blad przy w menu_s "<<endl;




   getch();
   system("CLS");

}
void obsluga_menu_s() // obsluga menu skrzyni cz.3
{
    int pos = 0, *w_pos = &pos;
    unsigned char input = 0;




    do
    {
        opcje_s(w_pos);
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if(*w_pos == 0)
                    *w_pos=liczba_opcji_s-1;
                else
                    *w_pos=*w_pos-1;
            }
            else if(input == 's')
            {
                if(*w_pos == liczba_opcji_s-1)
                    *w_pos = 0;
                else
                    *w_pos=*w_pos+1;
            }
        }

    }
    while(input != 13);

    menu_s(w_pos);
}

