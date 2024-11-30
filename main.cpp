#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<windows.h>
using namespace std;
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
int wybor,wynik=0;
void kolor(int k)
{
    SetConsoleTextAttribute(color,k);
}
void logo()
{
    kolor(13);cout<<R"(
 ___  __    ________  ___       ___  __    ___  ___  ___       ________  _________  ________  ________  ________
|\  \|\  \ |\   __  \|\  \     |\  \|\  \ |\  \|\  \|\  \     |\   __  \|\___   ___\\   __  \|\   __  \|\   __  \
\ \  \/  /|\ \  \|\  \ \  \    \ \  \/  /|\ \  \\\  \ \  \    \ \  \|\  \|___ \  \_\ \  \|\  \ \  \|\  \ \  \|\  \
 \ \   ___  \ \   __  \ \  \    \ \   ___  \ \  \\\  \ \  \    \ \   __  \   \ \  \ \ \  \\\  \ \   _  _\ \   _  _\
  \ \  \\ \  \ \  \ \  \ \  \____\ \  \\ \  \ \  \\\  \ \  \____\ \  \ \  \   \ \  \ \ \  \\\  \ \  \\  \\ \  \\  \|
   \ \__\\ \__\ \__\ \__\ \_______\ \__\\ \__\ \_______\ \_______\ \__\ \__\   \ \__\ \ \_______\ \__\\ _\\ \__\\ _\
    \|__| \|__|\|__|\|__|\|_______|\|__| \|__|\|_______|\|_______|\|__|\|__|    \|__|  \|_______|\|__|\|__|\|__|\|__|)";
cout<<endl;
}
int dodawanie(int a, int b)
{
    return a+b;
}
int dzieleniecalk(int a, int b)
{
    return a/b;
}
string dziesietnyNaSystem(int liczba, int system){
    if (system < 2 || system > 10) {
        return "Nieprawidlowy system (2-10)";
    }
    string wynik;
    if (liczba == 0) return "0";
    while(liczba>0){
        wynik+=to_string(liczba%system);
        liczba/=system;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

int systemNaDziesiet(const string& liczba, int system)
{
    int wynik = 0;
    for(char cyfra:liczba){
        wynik=wynik*system+(cyfra-'0');
    }
    return wynik;
}

string systemNaSystem(const string& liczba, int systemWej, int systemWyj){
    int dziesietny=systemNaDziesiet(liczba, systemWej);
    return dziesietnyNaSystem(dziesietny, systemWyj);
}
void menu()
{
    kolor(11);cout<<"Wybierz dzialanie:\n";kolor(9);
    cout<<" 1. Dodawanie\n 2. Dzielenie calkowite\n 3. Przeliczanie liczby dziesietnej na dowolny system (od 2 do 9)\n";
    cout<<" 4. Przeliczanie liczby z dowolnego systemu (od 2 do 9) na system dziesietny\n";
    cout<<" 5. Przeliczanie liczby z dowolnego systemu liczbowego na dowolny\n 0. Wyjscie\n";
    cout<<"Twoj wybor: ";kolor(89);cout<<"[   ]\b\b\b";cin>>wybor;kolor(7);
}
int main()
{
    logo();
    do{
        menu();
        switch(wybor){
            case 1:
                {
                int a,b;
                cout<<"Podaj dwie liczby do dodania (oddzielone spacja): ";
                cin>>a>>b;
                kolor(14);cout<<"Wynik: "<<dodawanie(a,b)<<endl;break;
                }

            case 2:
                {
                int a,b;
                cout<<"Podaj dwie liczby do dzielenia calkowitego (oddzielone spacja): ";
                cin>>a>>b;
                kolor(14);cout<<"Wynik: "<<dzieleniecalk(a,b)<<endl;break;
                }
            case 3:
                {
                int liczba,system;
                cout<<"Podaj liczbe dziesietna: ";cin>>liczba;
                cout<<"Podaj system docelowy: ";cin>>system;
                kolor(14);cout<<"Wynik: "<<dziesietnyNaSystem(liczba,system)<<endl;
                break;
                }
            case 4:
                {
                string liczba;int system;
                cout<<"Podaj liczbe w systemie zrodlowym: ";cin>>liczba;
                cout<<"Podaj system zrodlowy: ";cin>>system;
                kolor(14);cout<<"Wynik: "<<systemNaDziesiet(liczba,system)<<endl;
                break;
                }
            case 5:
                {
                string liczba;
                int systemwej,systemwyj;
                cout<<"Podaj liczbe w systemie zrodlowym:";cin>>liczba;
                cout<<"Podaj system zrodlowy:";cin>>systemwej;
                cout<<"Podaj system docelowy:";cin>>systemwyj;
                kolor(14);cout<<"Wynik: "<<systemNaSystem(liczba,systemwej,systemwyj)<<endl;
                break;
                }
            case 0:
                cout<<"Koniec programu."<<endl;break;
            default:
                kolor(12);cout<<"Nieprawidlowy wybor. Sprobuj ponownie."<<endl;break;
        }
    }while(wybor!=0);
    return 0;
}
