#include <iostream>
#include <cstdio>
#include <windows.h>
#include <vector>
#include <fstream>


using namespace std;

void menu();
void wybierz();
void licz(string przedmiot);
void stworz();
void wczytaj_zapis(vector<string> &przedmioty);

void menu()
{
    for(;;) {
    int opcja;
    cout<<"PROGRAM DO LICZENIA SREDNIEJ WAZONEJ"<<endl<<endl;
    cout<<"------------MENU-------------"<<endl;
    cout<<"Wpisz nr opcji :"<<endl;
    cout<<"1.Stworz nowy plik"<<endl;
    cout<<"2.Wczytaj istniejacy plik"<<endl;
    cout<<"3.Usun istniejacy plik(Nie dziala)"<<endl;
    cout<<"4.Wyjdz"<<endl<<endl;
    cin>>opcja;


    switch(opcja)
    {
        case 1:Sleep(1000); system("cls"); stworz(); break;
        case 2:Sleep(1000); system("cls"); wybierz(); break;
        case 3: cout<<"AAAAAAAAAAAAA"<<endl; break;
        case 4: exit(0);break;
        default: cout<<"Nie ma takiej opcji"<<endl;
    }
         Sleep(1500); system("cls");                }

}


void licz(string przedmiot)
{
    przedmiot+=".txt";

    fstream plik;
    plik.open(przedmiot, ios::in);
    float waga=0, ocena=0,  licznik=5, mianownik=5, srednia=5, wartosc=0; //wartosci podane dla testu
    plik>>licznik;
    plik>>mianownik;
    plik>>srednia;
    plik.close();

    vector <int> Waga1(0);
    vector <int> Waga2(0);
    vector <int> Waga3(0);

    for(;;)
    {
        cout<<"POLICZ SWOJA SREDNIA WARZONA "<<endl<<endl;
        cout<<"Twoja aktualna srednia wazona to: "<<srednia<<endl<<endl;
        cout<<"Aktualnie wpisane oceny:"<<endl;
     /////////////////////////////////////////////////////
       if(Waga1.size()>0) {  cout<<endl<<"O wadze 1: ";
        for(auto elem: Waga1)
            {
                cout<<elem<<", ";
            }   cout<<endl;                              }
     /////////////////////////////////////////////////////
       if(Waga2.size()>0) {  cout<<endl<<"O wadze 2: ";
        for(auto elem: Waga2)
            {
                cout<<elem<<", ";
            }   cout<<endl;                              }
     /////////////////////////////////////////////////////
       if(Waga3.size()>0) { cout<<endl<<"O wadze 3: ";
        for(auto elem: Waga3)
            {
                cout<<elem<<", ";
            }   cout<<endl;                              }
     /////////////////////////////////////////////////////
        cout<<"Aby przejsc do menu glownego wpisz litere"<<endl;
        cout<<"Aby wyjsc z programu wpisz 0(do dowolnej wartosci)"<<endl;
        cout<<"Podaj ocene a po spacji wage"<<endl;
        cin>>ocena>>waga;

        if(cin) {
           if(waga==0 || ocena==0) {exit(0) ;}
           else if(ocena<1 || ocena>6) {cout<<"Podaj prawidlowe oceny!";}
           else if(waga==1) {Waga1.push_back(ocena);cout<<endl<<"*  PRZELICZANIE  *";

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

            else if(waga==2) {Waga2.push_back(ocena);cout<<endl<<"*  PRZELICZANIE  *";

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

            else if(waga==3) {Waga3.push_back(ocena);cout<<endl<<"*  PRZELICZANIE  *";

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
            else {cout<<"Mozliwe wagi to tylko 1, 2 i 3!"<<endl;}  }
    else {  cin.clear();cin.sync(); //czyszczenie strumienia wejscia
    cout<<"Jedna z podanych wartosci nie jest liczba!"<<endl;
    cout<<"Przekierowanie do menu glownego"; Sleep(1500);system("cls");menu(); }

        Sleep(1000);
        system("cls");
    }
}

void stworz()
{
    vector<string>wyrazy = {};
    wczytaj_zapis(wyrazy);

    int opcja;
    fstream plik;
    string wyraz;
    string wyrazPliku;
    bool czy_istnieje = true;

    cout<<"----TWORZENIE NOWEGO PLIKU----"<<endl;
    cout<<"Jak chcesz go nazwac?";
    cin>>wyraz;

    for(string elem : wyrazy)
    {
        if(wyraz==elem) {czy_istnieje = false;}
    }

    if(czy_istnieje == false)
    {
        cout<<"Istnieje plik o takiej nazwie!";
        Sleep(1500); system("cls"); stworz();
    } else {
        wyrazy.push_back(wyraz);
        plik.open("Dane_przedmioty.txt", ios::app);
        if(plik.good()==false) {cout<<"Blad"<<endl;Sleep(1500); menu();}
        plik<<wyraz<<endl;
        plik.close();
        system("cls");
        cout<<"Gratulacje, udalo Ci sie stworzyc nowy plik do liczenia sredniej wazonej!"<<endl;
        cout<<"Jego nazwa to: "<<wyraz<<endl;
        cout<<"Co chcesz zrobic dalej?(Wpisz odpowiedni numer opcji)"<<endl;
        cout<<"1.Stworz kolejny plik"<<endl;
        cout<<"2.Wroc do MENU glownego"<<endl;
        cout<<"3.Wyjdz"<<endl;
        cin>>opcja;
        switch(opcja)
        {
            case 1: system("cls");stworz(); break;
            case 2: system("cls");menu ();   break;
            case 3: exit(0);  break;
            default: cout<<"Nie ma takiej opcji";
            Sleep(1500);system("cls"); stworz();
        }

    }

}

void wybierz()
{
    vector<string> przedmioty;
    wczytaj_zapis(przedmioty);

    int wybor;
    cout<<"Wybierz przedmiot:"<<endl;
    for(int i=0; i<przedmioty.size();i++)
    {
       cout<<i+1<<"."<<przedmioty[i]<<endl;
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
        {cout<<"Blad pliku!"<<endl; Sleep(1500); system("cls");menu();}
    string wyraz;
    while(getline(plik,wyraz))
        {
            przedmioty.push_back(wyraz);
        }
    plik.close();
}
