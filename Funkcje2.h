using namespace std;
#ifndef Funkcje2_H
#define Funkcje2_H

class postac
{

    string nazwa;
    int pozycja_x;
    int pozycja_y;
    int zdrowie;
    int atak;
    int predkosc;
    int pieniadze;


    public:


    postac(string nw ="Nienazwana postac", int w_x = 0, int w_y =0, int zdr =1, int atk=1, int prd = 100,int pln =0);

    void pokaz_statystyki();
    void pokaz_statystyki_przeciwnika();
    void dodaj_pieniadze(int ile);
    void pokaz_pieniadze();
    void chodzenie();
    void nadaj_atrybuty(string nw="Postac bez nazwy ", int zdr=1, int atk=1, int prd=1, int pln =1);
    void pokaz_ekwipunek();
    friend void graj();
    friend int main();
    friend void walcz();
    friend void atak(postac &nasz, postac &przeciwnik);
    friend void menu_s(int *dzialanie);
    friend void menu_apt(int *dzialanie);
    friend void menu_w(int dzialanie,postac przeciwnik);
    friend  void walcz();
    friend  void menu_tr(int *dzialanie);



};



int liczba_opcji_gl = 4;
int liczba_opcji_w =3;
int liczba_opcji_rp =3;
int liczba_opcji_s =2;
int liczba_opcji_pt =3;
int liczba_opcji_t_g=3;
int liczba_opcji_t_h=2;
int liczba_opcji_tr=3;
int rozmiar_planszy=5;
int poziom_trudnosci = 2;
int liczba_opcji_apt =2;;
int zdrowie_maks=0;
bool czy_byl=0;

int poz=0;

string elem = "*",elem_prz = "0",elem_handel = "H",elem_targ="T",elem_skrzynka = "S",elem_apteczka = "A";
string ekwipunek[1000] = {""};
int ceny[1000] = {0};
string przedmioty [1000] ={"0"};
string t_opcje[1000] = {""};
string uleprzenia[1000] = {""};

void graj();
void obsluga_menu_gl();
vector<vector<string>> plansza;

vector<vector<string>> plansza_przeciwnikow;
void wczytaj_slownik();
void wczytaj_zasady();
void sklauj_plansze_elem(int rozmiar=rozmiar_planszy,string elem = "*",vector <vector <string> > &plansza = plansza);
void pokaz_plansze(vector <vector <string> > plansza1 = plansza);
void czyszcz_plansze(int y,int x,vector <vector <string> > plansza1=plansza);
void utworz_plansze_przeciwnikow(int rozmiar_planszy,int poziom_trudnosci,string prz=elem_prz);
void opcje_tr(int *pos);
void opcje_t_h(int *pos);
void menu_tr(int *dzialanie);
void obsluga_menu_tr();
void opcje_t_h(int pos);
void przygotuj_do_handlu();
void sprzedarz(int nr);
void menu_t_h(int *dzialanie);
void obsluga_menu_t_h();
void opcje_t_g(int *pos);
void menu_t_g(int *dzialanie);
void obsluga_menu_t_g();
void opcje_s(int *pos);
void menu_s(int *dzialanie);
void obsluga_menu_s();
void obsluga_menu_w(postac);
void walcz();
void graj();
void opcje_apt(int *pos);
void menu_apt(int *dzialanie);
void obsluga_menu_apt();
void opcje_w(int pos);
void ustaw_maks_zdrowie();
void czysc_tablice();
void opcje_pt(int *pos);
void menu_pt(int *dzialanie);
void obsluga_menu_pt();
void dodaj_do_ekwipunku(string nazwa_przedmiotu, int ilosc);
void opcje_gl(int *pos);
void menu_glowne(int *dzialanie);
void obsluga_menu_gl();
void opcje_rp(int *pos);
void menu_rp(int *dzialanie);
void obsluga_menu_rp();
void wczytaj_slownik();
void wczytaj_zasady();
int main();



postac gracz;

#endif





