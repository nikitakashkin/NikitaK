#include <iostream>
#include <stdlib.h>

#include "headerFile.h";//prototypy funkcji

using namespace std;

int dataCounter = 0;

int main() {
    float fahr, celsius, kelwin;
	int fn;
    double tab_wartosci [100] = { 0 };
	char tab_jednostki [100] = { ' ' };
    while (true) {
        menu();
        cin >> fn;
        switch (fn)
        {
        case 1:
            fahr = pobiezF(0);
            celsius = FtoC(fahr);
            cout << fahr << "   " << celsius << endl;
			wartosc(tab_wartosci, fahr, celsius);
			jednostka(tab_jednostki, 'F', 'C');
			dataCounter += 2;
            /*
			tab_wartosci[dataCounter] = fahr;
			tab_jednostki[dataCounter] = 'F';
			tab_wartosci[dataCounter + 1] = celsius;
			tab_jednostki[dataCounter + 1] = 'C';
			dataCounter += 2;
            */
            break;
        case 2:
            fahr = pobiezF(0);
            kelwin = FtoK(fahr);
            cout << fahr << "   " << kelwin << endl;
            wartosc(tab_wartosci, fahr, kelwin);
            jednostka(tab_jednostki, 'F', 'K');
            dataCounter += 2;
            break;
        case 3:
            celsius = pobiezC(0);
            fahr = CtoF(celsius);
            cout << celsius << "   " << fahr << endl;
            wartosc(tab_wartosci, celsius, fahr);
            jednostka(tab_jednostki, 'C', 'F');
            dataCounter += 2;
            break;
        case 4:
            celsius = pobiezC(0);
            kelwin = CtoK(celsius);
            cout << celsius << "   " << kelwin << endl;
            wartosc(tab_wartosci, celsius, kelwin);
            jednostka(tab_jednostki, 'C', 'K');
            dataCounter += 2;
            break;
        case 5:
            kelwin = pobiezK(0);
            celsius = KtoC(kelwin);
            cout << kelwin << "   " << celsius << endl;
            wartosc(tab_wartosci, kelwin, celsius);
            jednostka(tab_jednostki, 'K', 'C');
            dataCounter += 2;
            break;
        case 6:
            kelwin = pobiezK(0);
            fahr = KtoF(kelwin);
            cout << kelwin << "   " << fahr << endl;
            wartosc(tab_wartosci, kelwin, fahr);
            jednostka(tab_jednostki, 'K', 'F');
            dataCounter += 2;
            break;
        case 7:
			his(tab_wartosci, tab_jednostki);
            break;
        default: return 0;
        }
		cout << "Wpisz enter aby kontynuowac..." << endl;
        cin.ignore();
        while (cin.get() != '\n');
        system("cls");
    }
}

void wartosc(double war[], float st_wart, float nw_wart) {
	war[dataCounter] = st_wart; 
	war[dataCounter + 1] = nw_wart;
    return;
}

void jednostka(char jed[], char st_jed, char nw_jed) {
	jed[dataCounter] = st_jed;
    jed[dataCounter + 1] = nw_jed;
	return;
}

void his(double wartosc[], char jednostka[]) {
    int num = 0;
    for (int i = 0; i < (dataCounter / 2); i++) {
        cout << "<" << i + 1 << ">" << " " << wartosc[num] << jednostka[num] << " = " << wartosc[num+1] << jednostka[num+1] << endl;
		num += 2;
    }
}

int check(float temp, char jedn) {
    if (jedn == 'F' && temp < -459.67) {
        cout << "Bledna wartosc temperatury dla stopni Fahrenheita!" << endl;
        return 0;
    }
    else if (jedn == 'C' && temp < -273.15) {
        cout << "Bledna wartosc temperatury dla stopni Celsjusza!" << endl;
        return 0;
    }
    else if (jedn == 'K' && temp < 0) {
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
    else { return -999; }
}
float pobiezC(float stopnie) {
    cout << "Podaj stopnie Celsius: ";
    cin >> stopnie;
	int che = check(stopnie, 'C');
    if (che == 1) {
        return stopnie;
    }
    else { return -999; }
}
float pobiezK(float stopnie) {
    cout << "Podaj stopnie Kelwin: ";
    cin >> stopnie;
	int che = check(stopnie, 'K');
    if (che == 1) {
        return stopnie;
    }
    else { return -999; }
}

void menu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
	cout << "7 - pokaz historie" << endl;
    cout << "8 - zakoncz dzialanie programu" << endl;
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