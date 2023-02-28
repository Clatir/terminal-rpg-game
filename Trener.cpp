
using namespace std;

#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
#include "funkcje2.h"

void opcje_tr(int *pos) // obsluga 2 menu trenera cz.1
{

    string opcje[liczba_opcji_rp] = {" 1. Atak ", " 2. Zdrowie"," 3. Szybkosc"};
    opcje[*pos][0] = '>';



    system("CLS");
    cout<<"Jaka ceche chcesz wzmocnic "<<endl;
    for(int i = 0; i<liczba_opcji_pt; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_tr(int *dzialanie) // obsluga 2 menu trenera cz.2
{

ustaw_maks_zdrowie();

    if((*dzialanie) == 0)

        {

        if((gracz.pieniadze)>=stoi(uleprzenia[1]))
        {gracz.atak+=5;
        gracz.pieniadze-=stoi(uleprzenia[1]);
        cout<<"Trening wzmocnil sile twojego ataku o 5 "<<endl<<"teraz sila twojego ataku wynosi "<<gracz.atak;
        getch();
        obsluga_menu_t_g();


        }

        else
        {
            cout<<"Nie masz wystarczajaco monet "<<endl;
            getch();
            obsluga_menu_t_g();
        }
        }



    else if((*dzialanie) == 1)
    {



       if((gracz.pieniadze)>=(stoi(uleprzenia[3])))
       {    zdrowie_maks+=5;
            gracz.pieniadze-=stoi(uleprzenia[3]);
            cout<<"Trening wzmocnil twoje zdrowie o 5 "<<endl<<"teraz maksymalna ilosc zdrowia wynosi "<<zdrowie_maks;
            getch();
            obsluga_menu_t_g();

       }

        else
        {
            cout<<"Nie masz wystarczajaco monet "<<endl;
            getch();
            obsluga_menu_t_g();

        }
    }
     else if((*dzialanie) == 2)
     {



        if((gracz.pieniadze)>=(stoi(uleprzenia[5])))
            {gracz.predkosc+=5;
            gracz.pieniadze-=stoi(uleprzenia[5]);;
            cout<<"Trening wzmocnil twoja predkosc o 5 "<<endl<<"teraz twoja predkosc wynosi "<<gracz.predkosc;
            getch();
            obsluga_menu_t_g();

            }
        else
        {
            cout<<"Nie masz wystarczajaco monet "<<endl;
            getch();
            obsluga_menu_t_g();;

        }
        }
    else
    {
        cout<<"Wystapil blad w funkcji menu_tr "<<endl;
        getch();
    }




   system("CLS");

}
void obsluga_menu_tr() // obsluga2  menu trenera cz.3
{
    int pos = 0, *w_pos=&pos;
    unsigned char input = 0;




    do
    {
        opcje_tr((w_pos));
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if((*w_pos) == 0)
                    (*w_pos)=liczba_opcji_tr-1;
                else
                    (*w_pos)=(*w_pos)-1;
            }
            else if(input == 's')
            {
                if((*w_pos) == liczba_opcji_tr-1)
                    (*w_pos) = 0;
                else
                    (*w_pos)=(*w_pos)+1;;
            }
        }

    }
    while(input != 13);   //Enter

    menu_tr((w_pos));
}

void opcje_t_h(int *pos) // obsluga menu handlu cz.1
{   for(int i =0; i<1000;i++)
        t_opcje[i]="";
    liczba_opcji_t_h =0;
    for(int i =0; i<1000;i++)
    {



        if((i%2 == 0) and (ekwipunek[i]!=""))
        {   t_opcje[liczba_opcji_t_h]+=" ";
            t_opcje[liczba_opcji_t_h]+= to_string(liczba_opcji_t_h+1);
            t_opcje[liczba_opcji_t_h]+=". ";
            for(int j =0; j<(ekwipunek[i].length());j++)
            {
                t_opcje[liczba_opcji_t_h].push_back(ekwipunek[i][j]);
            }

            //cout<<t_opcje[liczba_opcji_t_h]<<endl;
            liczba_opcji_t_h++;

        }


    }
    system("CLS");

    t_opcje[(*pos)][0] = '>';

    cout<<endl;
    for(int i = 0; i<2*liczba_opcji_t_g; i++)
    {
        cout<<t_opcje[i]<<endl;
    }

}


void przygotuj_do_handlu()
{
    ifstream plik;

    poz=0;
    plik.open("Ekwipunek.txt");

    if(!plik.is_open())
        cout<<" Nie udalo sie wczytac cennika z pliku ekwipunek ";
    else
    {
        string wiersz="";
        string cena = "";
        string przedmiot ="";

        while(getline(plik,wiersz))
        {

            cena = "";
            przedmiot = "";


            for(int i =0; i<wiersz.length();i++)
            {
            if(wiersz[i]>='0' and wiersz[i]<='9')

            cena.push_back(wiersz[i]);

            if((wiersz[i]>='A' and wiersz[i]<='z') or (wiersz[i] ==32))
                przedmiot.push_back(wiersz[i]);

            }
            ceny[poz] = stoi(cena);
            przedmioty[poz] = przedmiot;
            cout<<"Przedmiot: "<<przedmiot<<" "<<"cena: "<<cena<<endl;
            poz++;



        }



}
}

void sprzedarz(int nr) // sprzedawanie przedmiotow
{
string nowy_napis="";
int poz_w_ekwipunku=0;
int pozycja_w_spisie=0;

 cout<<"Twoj ekwipunek to: "<<endl;
        gracz.pokaz_ekwipunek();
        cout<<"oraz ";
        gracz.pokaz_pieniadze();
        cout<<"monet";
cout<<endl;



for(int i=4; i<((t_opcje[nr]).length());i++)
    nowy_napis.push_back(t_opcje[nr][i]);
//cout<<"Zamierzasz sprzedac "<<nowy_napis<<"|";

for(int i =0; i<1000;i++)
{if(ekwipunek[i] == nowy_napis)
    {poz_w_ekwipunku = i;
    //cout<<"Znaleziono przedmiot "<<"jego index to: "<<poz_w_ekwipunku<<endl;
    //cout<<"Masz "<<ekwipunek[poz_w_ekwipunku+1]<<" sztuk"<<endl;

    }
if(nowy_napis == przedmioty[i])
    pozycja_w_spisie =i;

}









przygotuj_do_handlu();
int sztuk=0;
int indeks =0;
/**for(int i =0; i<poz;i++)
        {
            if(ekwipunek[2*nr] == przedmioty[i])
            {indeks =i;
            //cout<<"Numer indeksu to: "<<indeks<<endl;
            i=poz+1;
            }


        }
    **/
         handel_start:



        cout<<"Podaj ile sztuk chcesz sprzedac "<<endl;
        cin>>sztuk;

        if(cin.fail())
            {   system("cls");
                cout<<"Trener nie lubi cwaniakow "<<endl;
                sztuk =0;
                getch();
                //system("taskkill /im cb_console_runner.exe /t /f");


            }




        if(sztuk>(stoi(ekwipunek[poz_w_ekwipunku+1])))
           {

            cout<<"Nie masz tyle sztuk tego przedmiotu "<<endl;
            //cout<<"Nr: "<<nr<<" "<<ekwipunek[nr]<<" "<<ekwipunek[nr+1]<<endl;

            /**
            for(int i =0; i<25;i++)
                cout<<"i = "<<i<<" "<<ekwipunek[i]<<endl;
                **/
            goto handel_start;

           }


        if (!czy_byl)
        {
        cout<<" Zarobiles "<<ceny[pozycja_w_spisie]*3*sztuk<<" monet "<<endl;
        gracz.dodaj_pieniadze(ceny[pozycja_w_spisie]*3*sztuk);
        czy_byl=1;


        }
        else
        {
        cout<<" Zarobiles "<<ceny[pozycja_w_spisie]*sztuk<<" monet "<<endl;
        gracz.dodaj_pieniadze(ceny[pozycja_w_spisie]*sztuk);
        }


        cout<<"Pozsotalo tobie "<<stoi(ekwipunek[poz_w_ekwipunku+1])-sztuk<<" sztuk "<<endl;
        ekwipunek[poz_w_ekwipunku+1] = to_string(stoi(ekwipunek[poz_w_ekwipunku+1])-sztuk);

        /**
        for(int i =0; i<25;i++)
                cout<<"i = "<<i<<" "<<ekwipunek[i]<<endl;
                **/
        getch();

        if(((ekwipunek[poz_w_ekwipunku+1])) == "0")
            {ekwipunek[poz_w_ekwipunku] = "";
            ekwipunek[poz_w_ekwipunku+1] = "";

            }





}



void menu_t_h(int *dzialanie) // obsluga menu handlu cz.2
{




if((*dzialanie == 0))
    sprzedarz(0);
else if((*dzialanie == 1))
    sprzedarz(1);
else if((*dzialanie == 2))
    sprzedarz(2);
else if((*dzialanie == 3))
    sprzedarz(3);
else if((*dzialanie == 4))
    sprzedarz(4);

else
{
    cout<<"Wsytapil blad w funkcji menu_t_h "<<endl;
    getch();
}



}


void obsluga_menu_t_h() // obsluga menu handlu cz.3
{
    int pos = 0,*w_pos = &pos;
    unsigned char input = 0;




    do
    {
        opcje_t_h(w_pos);
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if(*w_pos == 0)
                    *w_pos=liczba_opcji_t_h-1;
                else
                    *w_pos = *w_pos -1;
            }
            else if(input == 's')
            {
                if(*w_pos == liczba_opcji_t_h-1)
                    *w_pos = 0;
                else
                    *w_pos = *w_pos +1;
            }
        }

    }
    while(input != 13);
    menu_t_h(w_pos);
}

void opcje_t_g(int *pos) // obsluga menu glownego trenera cz.1
{

    string opcje[liczba_opcji_t_g] = {" 1. Trenuj umiejetnosci ", " 2. Sprzedaj przedmioty ", " 3. Odejdz"};
    opcje[(*pos)][0] = '>';

    system("CLS");
    cout<<"Wybierz opcje za pomoca strzalek, nastepnie wcisnij ENTER"<<endl;
    for(int i = 0; i<liczba_opcji_t_g; i++)
    {
        cout<<opcje[i]<<endl;
    }
}

void menu_t_g(int *dzialanie) // obsluga menu glownego trenera cz.2
{
bool czy_pusty =1;

if((*dzialanie == 0))



{
            cout<<"Masz ";gracz.pokaz_pieniadze();
            cout<<" monet "<<endl;



           ifstream plik;
           plik.open("Uleprzenia.txt");


            int linijka = 0;

            if(!plik.is_open())
                cout<<"Nie udalo sie otworzyc kosztow uleprzen ";
            else
            {   string linia ="";
                while(getline(plik,linia))
                {//cout<<linia<<endl;
                uleprzenia[linijka] = linia;
                linijka++;

                }
                for(int i =0;i<=(linijka/2)+1;i++)
                {
                    cout<<"Uleprzenie "<<uleprzenia[i]<<" kosztuje "<<uleprzenia[i+1]<<" monet "<<endl;
                    i++;
                }
            }

                getch();





        obsluga_menu_tr();
}

    else if((*dzialanie == 1))
        {
            for(int i =0; i<1000;i++)
        {
            if((ekwipunek[i]!="") and (ekwipunek[i] !="0"))
            {czy_pusty = 0;
            i=1001;
            }
        }
        if(czy_pusty)
        {cout<<"Nie masz zadnych przedmiotow "<<endl;
        getch();

        }
        else
            {obsluga_menu_t_h();
            obsluga_menu_t_g();
            }







        }


    else if((*dzialanie == 2))
        {
        }
    else
    {
        cout<<"Wystapil blad w funkcji menu_t_g "<<endl;
        getch();
    }



}

void obsluga_menu_t_g() // obsluga menu glownego trenera cz.3
{
    int pos = 0,*w_pos = &pos;
    unsigned char input = 0;




    do
    {
        opcje_t_g(w_pos);
        input = getch();
        if(input=='w' or input == 's')
        {
            //input=getch();
            if(input == 'w')
            {
                if(*w_pos == 0)
                    *w_pos=liczba_opcji_t_g-1;
                else
                    *w_pos = *w_pos -1;
            }
            else if(input == 's')
            {
                if(*w_pos == liczba_opcji_t_g-1)
                    *w_pos = 0;
                else
                    *w_pos = *w_pos +1;
            }
        }

    }
    while(input != 13);   //Enter

    menu_t_g(w_pos);
}

