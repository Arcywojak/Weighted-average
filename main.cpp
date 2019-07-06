#include <iostream>
#include <cstdio>
#include <windows.h>
#include <vector>
#include <fstream>
#include <math.h>


using namespace std;

void licz(string przedmiot);
void stworz();
void wybierz();
void menu();
void wczytaj_zapis(vector<string>&przedmioty);
///////////////////////////
int main()
{

    menu();

}
///////////////////////////

void menu()
{
    for(;;) {
    int opcja;

    cout<<"\n PROGRAM DO LICZENIA SREDNIEJ WAZONEJ"<<endl<<endl;
    cout<<" ------------MENU-------------"<<endl;
    cout<<" Wpisz nr opcji :"<<endl;
    cout<<" 1.Stworz nowy plik"<<endl;
    cout<<" 2.Wczytaj istniejacy plik"<<endl;
    cout<<" 3.Wyjdz"<<endl<<endl;
    cin>>opcja;


    switch(opcja)
    {
        case 1:Sleep(100); system("cls"); stworz(); break;
        case 2:Sleep(100); system("cls"); wybierz(); break;
        case 3: exit(0);break;
        default: cout<<"Nie ma takiej opcji"<<endl;
    }
         Sleep(1000); system("cls");                }

}


void licz(string przedmiot)
{
    przedmiot+=".txt";

    fstream plik;
    plik.open(przedmiot, ios::in);
    float ocena=0, pamiecOceny=0, licznik=0, mianownik=0, srednia=0, wartosc=0;
    int waga = 0, pamiecWagi = 0;
    plik>>licznik;
    plik>>mianownik;
    plik>>srednia;
    plik.close();

    vector <int> Waga1(0);
    vector <int> Waga2(0);
    vector <int> Waga3(0);

    for(;;)
    {
        cout<<"\n POLICZ SWOJA SREDNIA WARZONA "<<endl<<endl;
        cout<<"Jestes w pliku "<<przedmiot<<endl;
        cout<<" Twoja aktualna srednia wazona to: "<<srednia<<endl<<endl;
        cout<<" Aktualnie wpisane oceny:";

     /////////////////////////////////////////////////////
         cout<<endl<<"O wadze 1: ";
         if(Waga1.empty()) {cout<<"Brak";}
        else {
            for(auto elem: Waga1)
                {
                    cout<<elem<<", ";
                }
             }
     /////////////////////////////////////////////////////
         cout<<endl<<"O wadze 2: ";
         if(Waga2.empty()) {cout<<"Brak";}
        else {
            for(auto elem: Waga2)
                {
                    cout<<elem<<", ";
                }
             }
     /////////////////////////////////////////////////////
        cout<<endl<<"O wadze 3: ";
        if(Waga3.empty()) {cout<<"Brak";}
        else {
            for(auto elem: Waga3)
                {
                    cout<<elem<<", ";
                }
             }
     /////////////////////////////////////////////////////
        cout<<"\n Aby przejsc do menu glownego wpisz dowolna litere"<<endl;
        cout<<" Aby wyjsc z programu wpisz '0' (do dowolnej wartosci)"<<endl;
        cout<<" Jesli chcesz usunac wpisana poprzednio ocene"<<endl<<
              " wpisz do 'oceny' wartosc mniejsza od '0'"<<endl;
        cout<<" Podaj ocene (od 1 do 10) a po spacji wage (1,2 lub 3)\n"<<endl;
        pamiecWagi = waga;
        pamiecOceny = ocena;

        cin>>ocena;
        if(cin && ocena<0)
           {
             if(pamiecOceny==0 || pamiecWagi==0) {
               cout<<endl<<" Aktualnie nie dodales jeszcze zadnej oceny!"<<endl; }
             else if(pamiecOceny==11) {
               cout<<"Mozna usunac tylko 1 ocene naraz"<<endl; }

             else {
             licznik = licznik - (pamiecWagi*pamiecOceny);
             mianownik = mianownik - pamiecWagi;
             cout<<licznik<<" "<<mianownik<<endl;
             if(mianownik==0) {srednia = 0;}
              else  {srednia = licznik/mianownik;}

             if(pamiecWagi == 1)      { Waga1.pop_back();}
             else if(pamiecWagi == 2) { Waga2.pop_back();}
             else if(pamiecWagi == 3) { Waga3.pop_back();}
             cout<<endl<<" * USUWANIE *";
             pamiecOceny = 11;
             }
           }
       else if(cin && ocena>=0)
        {
           cin>>waga;
           if(waga==0 || ocena==0) {exit(0) ;}


           else if( ocena>10 ) {cout<<" Oceny nie moga byc wieksze od 10!";}

           else if(waga==1 || waga==2 || waga==3) {
                   if(waga==1) {
                Waga1.push_back(ocena);cout<<endl<<"*  PRZELICZANIE  *";}
                   else if(waga==2) {
                Waga2.push_back(ocena);cout<<endl<<"*  PRZELICZANIE  *";}
                   else if(waga==3) {
                Waga3.push_back(ocena);cout<<endl<<"*  PRZELICZANIE  *";}

                wartosc=ocena*waga;
                licznik+=wartosc;
                mianownik+=waga;
                srednia=licznik/mianownik;
                plik.open(przedmiot, ios::out);
                plik<<licznik<<endl;
                plik<<mianownik<<endl;
                plik<<srednia<<endl;
                plik.close();
                }
        }
   else if(!cin) {  cin.clear();cin.sync(); //czyszczenie strumienia wejscia
    cout<<" Jedna z podanych wartosci nie jest liczba!"<<endl;
    cout<<" Przekierowanie do menu glownego"; Sleep(1000);system("cls");menu(); }

         Sleep(1000); system("cls");


    }

}

void stworz()
{
    vector<string>wyrazy ;
    wczytaj_zapis(wyrazy);

    int opcja;
    fstream plik;
    string wyraz;
    string wyrazPliku;
    bool czy_istnieje = true;

    cout<<"\n ----TWORZENIE NOWEGO PLIKU----"<<endl;
    cout<<" Jak chcesz go nazwac?"<<endl<<endl;
    cin>>wyraz;

    for(string elem : wyrazy)
    {
        if(wyraz==elem) {czy_istnieje = false;}
    }

    if(czy_istnieje == false)
    {
        cout<<"\n Istnieje plik o takiej nazwie!";
        Sleep(1000); system("cls"); stworz();
    } else {
        wyrazy.push_back(wyraz);
        plik.open("Dane_przedmioty.txt", ios::app);

        plik<<wyraz<<endl;
        plik.close();

        fstream nowy;
        wyraz+=".txt";
        nowy.open(wyraz, ios::out);
        for(int i=0; i<3; i++)
        {
            nowy<<0<<endl;
        }
        nowy.close();

        system("cls");
        cout<<"\n Gratulacje, udalo Ci sie stworzyc nowy plik do liczenia sredniej wazonej!"<<endl;
        cout<<"\n Jego nazwa to: "<<wyraz<<endl;
        cout<<"\n Co chcesz zrobic dalej?(Wpisz odpowiedni numer opcji)"<<endl;
        cout<<"\n 1.Stworz kolejny plik"<<endl;
        cout<<" 2.Wroc do MENU glownego"<<endl;
        cout<<" 3.Wyjdz"<<endl;
        cin>>opcja;
        switch(opcja)
        {
            case 1: system("cls");stworz(); break;
            case 2: system("cls");menu ();   break;
            case 3: exit(0);  break;
            default: cout<<"Nie ma takiej opcji";
            Sleep(1000);system("cls"); stworz();
        }

    }

}

void wybierz()
{
    vector<string> przedmioty;
    wczytaj_zapis(przedmioty);

     if(przedmioty.empty())
    {
      cout<<endl<<"\n Jeszcze nie stworzyles zadnego pliku!";
       Sleep(1000); system("cls"); menu();
    }

    int wybor;
    cout<<"\n Wybierz przedmiot:\n"<<endl;
    for(int i=0; i<przedmioty.size();i++)
    {
       cout<<" "<<i+1<<"."<<przedmioty[i]<<endl;
    }
    cin>>wybor;
    Sleep(500);
    system("cls");
    licz(przedmioty[wybor-1]);
}

void wczytaj_zapis(vector<string> &przedmioty)
{
    fstream plik;
    plik.open("Dane_przedmioty.txt", ios::in);
    if(plik.good()==false)
        {
          plik.open( "Dane_przedmioty.txt", ios::app );
          plik.close();
          plik.open("Dane_przedmioty.txt", ios::in);
        }

    string wyraz;
    while(getline(plik,wyraz))
        {
            przedmioty.push_back(wyraz);
        }

    plik.close();
}

