#include <iostream>
#include <stdlib.h>
using namespace std;

int check(float temp, char stopnie);
float pobiezF(float stopnie);
float pobiezC(float stopnie);
float pobiezK(float stopnie);
float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);
void menu();

int main() { //kod 04_02
    float fahr, celsius, kelwin;
	int fn;
    while (true) {
        menu();
        cin >> fn;
        switch (fn)
        {
        case 1:
            fahr = pobiezF(0);
            celsius = FtoC(fahr);
            cout << fahr << "   " << celsius << endl;
            break;
        case 2:
            fahr = pobiezF(0);
            kelwin = FtoK(fahr);
            cout << fahr << "   " << kelwin << endl;
            break;
        case 3:
            celsius = pobiezC(0);
            fahr = CtoF(celsius);
            cout << celsius << "   " << fahr << endl;
            break;
        case 4:
            celsius = pobiezC(0);
            kelwin = CtoK(celsius);
            cout << celsius << "   " << kelwin << endl;
            break;
        case 5:
            kelwin = pobiezK(0);
            celsius = KtoC(kelwin);
            cout << kelwin << "   " << celsius << endl;
            break;
        case 6:
            kelwin = pobiezK(0);
            fahr = KtoF(kelwin);
            cout << kelwin << "   " << fahr << endl;
            break;
        default: return 0;
        }
		cout << "Wpisz enter aby kontynuowac..." << endl;
		cin.ignore();
		cin.get();
        system("cls");
    }
}

int check(float temp, char stopnie) {
    if (stopnie == 'F' && temp < -459.67) {
        cout << "Bledna wartosc temperatury dla stopni Fahrenheita!" << endl;
        return 0;
    }
    else if (stopnie == 'C' && temp < -273.15) {
        cout << "Bledna wartosc temperatury dla stopni Celsjusza!" << endl;
        return 0;
    }
    else if (stopnie == 'K' && temp < 0) {
        cout << "Bledna wartosc temperatury dla stopni Kelwina!" << endl;
        return 0;
    }
    else {
        return 1;
    }
}

float pobiezF(float stopnie) {
    cout << "Podaj stopnie Fahr: ";
    cin >> stopnie;
	int che = check(stopnie, 'F');
    if (che == 1) {
        return stopnie;
	}
}
float pobiezC(float stopnie) {
    cout << "Podaj stopnie Celsius: ";
    cin >> stopnie;
	int che = check(stopnie, 'C');
    if (che == 1) {
        return stopnie;
    }
}
float pobiezK(float stopnie) {
    cout << "Podaj stopnie Kelwin: ";
    cin >> stopnie;
	int che = check(stopnie, 'K');
    if (che == 1) {
        return stopnie;
    }
}

void menu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - zakoncz dzialanie programu" << endl;
    cout << "Wybierz funkcje konwersji temperatury: " << endl;
}

float FtoC(float stopnie) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);
    return wynik;
}
float FtoK(float stopnie) { //naglowek funkcji
    float wynik = (5.0 / 9.0) * (stopnie + 459.67);
    return wynik;
}
float CtoF(float stopnie) { //naglowek funkcji
    float wynik = stopnie * 9.0 / 5.0 + 32.0;
    return wynik;
}
float CtoK(float stopnie) { //naglowek funkcji
    float wynik = stopnie + 273.15;
    return wynik;
}
float KtoC(float stopnie) { //naglowek funkcji
    float wynik = stopnie - 273.15;
    return wynik;
}
float KtoF(float stopnie) { //naglowek funkcji
    float wynik = stopnie * 9.0 / 5.0 - 459.67;
    return wynik;
}