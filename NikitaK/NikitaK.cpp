#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "headerFile.h";//prototypy funkcji

using namespace std;

int dataCounter = 0;
int limit = 100;

int main() {
    double tab_wartosci [100] = { 0 };
	char tab_jednostki [100] = { ' ' };

    while (true) {

        menu();
        menuProgram(tab_wartosci, tab_jednostki);

		cout << "\nWpisz enter aby kontynuowac..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
    }
}

void wartosc(double war[], float st_wart, float nw_wart, int wsk) {
	if (wsk < limit) {
        war[wsk] = st_wart;
        war[wsk + 1] = nw_wart;
    }   
    else cout << "Osiagnieto limit przechowywanych danych!" << endl;
    return;
}

void jednostka(char jed[], char st_jed, char nw_jed, int wsk) {
    if (wsk < limit) {
        jed[wsk] = st_jed;
        jed[wsk + 1] = nw_jed;
    }
	return;
}

void los_his(double wart[], char jedn[]) {
    int liczba;
	float fahr, celsiusz, kelwin;
	fahr = celsiusz = kelwin = 0;
    
    cout << "Ile losowych wartosci przeliczyc: ";
	cin >> liczba;

    if (liczba > (limit - dataCounter) / 2) {
        cout << "Czy wygenerować tylko tyle losówek ile zostało miejsca, czy nie?(1 - tak, 0 - nie): ";
        if (cin >> liczba && liczba == 1) {
            liczba = (limit - dataCounter) / 2;
        }
        else {
            cout << "Nie można wygenerować tylu losowych wartości!" << endl;
            return;
        }
    }
    if (liczba <= (limit - dataCounter) / 2) {
        for (int i = 0; i < liczba; i++) {
            switch (1 + (rand() % 3))
            {
            case 1://F to C
                fahr = rand() % 1459 - 459; //od -459 do 1814
                celsiusz = FtoC(fahr);
                wartosc(wart, fahr, celsiusz, dataCounter);
                jednostka(jedn, 'F', 'C', dataCounter);
                dataCounter += 2;
                break;
            case 2: //F to K
                fahr = rand() % 1459 - 459; //od -459 do 1814
                kelwin = FtoK(fahr);
                wartosc(wart, fahr, kelwin, dataCounter);
                jednostka(jedn, 'F', 'K', dataCounter);
                dataCounter += 2;
                break;
            case 3://C to K
                celsiusz = rand() % 1000 - 273;
                kelwin = CtoK(celsiusz);
                wartosc(wart, celsiusz, kelwin, dataCounter);
                jednostka(jedn, 'C', 'K', dataCounter);
                dataCounter += 2;
                break;
            case 4://C to F
                celsiusz = rand() % 1000 - 273; //od -273 do 1000
                fahr = CtoF(celsiusz);
                wartosc(wart, celsiusz, fahr, dataCounter);
                jednostka(jedn, 'C', 'F', dataCounter);
                dataCounter += 2;
                break;
            case 5://K to C
                kelwin = rand() % 1000 + 1; //od -273 do 1000
                celsiusz = KtoC(kelwin);
                wartosc(wart, kelwin, celsiusz, dataCounter);
                jednostka(jedn, 'K', 'C', dataCounter);
                dataCounter += 2;
                break;
            case 6://K to F
                kelwin = rand() % 1000 + 1; //od -273 do 1000
                fahr = KtoF(kelwin);
                wartosc(wart, kelwin, fahr, dataCounter);
                jednostka(jedn, 'K', 'F', dataCounter);
                dataCounter += 2;
                break;
            default:
                break;
            }
        }
    }
    system("cls");
    wyswietl_his(wart, jedn);
}

void modyf_his(double wart[], char jedn[]) {
    float st_wart, nw_wart;
    char st_jed, nw_jed;
    int modyf;

    system("cls");
    wyswietl_his(wart, jedn);

    cout << "Wpisz ktory wpisch chcesz zmodyfikowac: ";
    cin >> modyf;
    cout << "Podaj nowa wartosc poczatkowa: ";
    cin >> st_wart;
    cout << "Podaj nowa jednostke poczatkowa: ";
    cin >> st_jed;
    cout << "Na jaka jednostke chcesz przeliczyc (F/C/K): ";
    cin >> nw_jed;

    if (st_jed == 'F') {
        check(st_wart, st_jed);
        if (nw_jed == 'C')
            nw_wart = FtoC(st_wart);
        else if (nw_jed == 'K')
            nw_wart = FtoK(st_wart);
        else {
            cout << "Bledna jednostka docelowa!" << endl;
        }

    }
    else if (st_jed == 'C') {
        check(st_wart, st_jed);
        if (nw_jed == 'F')
            nw_wart = CtoF(st_wart);
        else if (nw_jed == 'K')
            nw_wart = CtoK(st_wart);
        else {
            cout << "Bledna jednostka docelowa!" << endl;
        }
    }
    else if (st_jed == 'K') {
        check(st_wart, st_jed);
        if (nw_jed == 'C')
            nw_wart = KtoC(st_wart);
        else if (nw_jed == 'F')
            nw_wart = KtoF(st_wart);
        else {
            cout << "Bledna jednostka docelowa!" << endl;
        }
    }
    if (st_jed != nw_jed) {
        wartosc(wart, st_wart, nw_wart, (modyf - 1) * 2);
        jednostka(jedn, st_jed, nw_jed, (modyf - 1) * 2);

        system("cls");
        wyswietl_his(wart, jedn);
    }

}

void usun_his(double wartosc[], char jednostka[]) {
    int entityToRemove;
	entityToRemove = 0;

    system("cls");
    wyswietl_his(wartosc, jednostka);

	cout << "Podaj element ktory chcesz usunac: ";
    cin >> entityToRemove;
    if (entityToRemove > 0 && entityToRemove <= (dataCounter / 2)) {
        for (int i = entityToRemove * 2 - 2;i < dataCounter;i+=2) {
			wartosc[i] = wartosc[i + 2];
			wartosc[i + 1] = wartosc[i + 3];
			jednostka[i] = jednostka[i + 2];
			jednostka[i + 1] = jednostka[i + 3];
        }
		dataCounter -= 2;
    }
    else {
        cout << "Bledny element!" << endl;
	}
    system("cls");
    wyswietl_his(wartosc, jednostka);
}

int wybor_his() {
	int wybor;
    cout << "\n1.Tylko C - >\n2.Tylko F - >\n3.Tylko K - >\n"<<endl;
	cin >> wybor;
    if (wybor >= 1 && wybor <= 3)
        return wybor;
    else if (wybor < 1 || wybor > 3) {
        cout << "Bledny wybor!" << endl;
        return 0;
	}
    return 0;
}

void wyswietl_his(double wartosc[], char jednostka[]) {
	int num = 0;

    for (int i = 0; i < (dataCounter / 2); i++) {
        cout << "<" << i + 1 << ">" << " " << wartosc[num] << jednostka[num] << " = " << wartosc[num + 1] << jednostka[num + 1] << endl;
        num += 2;
    }
}

void wyswietl_his_new(double wartosc[], char jednostka[], char jed) {
    int num = 1;
    cout << "\n";
    for (int i = 0; i < dataCounter; i += 2) {
        if (jednostka[i] == jed) {
            cout << "<" << num << ">" << " " << wartosc[i] << jednostka[i] << " = " << wartosc[i + 1] << jednostka[i + 1] << endl;
            num++;
        }
    }
    if (num == 1)
        cout << "Brak danych do wyswietlenia!" << endl;
    cout << "\n";
}

void his(double wartosc[], char jednostka[], int wybor) {
    int num = 1;
    switch (wybor) {
    case 1: 
        wyswietl_his_new(wartosc, jednostka, 'C');
        break;
    
    case 2: 
        wyswietl_his_new(wartosc, jednostka, 'F');
        break;
    
    case 3:
        wyswietl_his_new(wartosc, jednostka, 'K');
        break;
    }
    /*    int num = 0;
    for (int i = 0; i < (dataCounter / 2); i++) {
        cout << "<" << i + 1 << ">" << " " << wartosc[num] << jednostka[num] << " = " << wartosc[num+1] << jednostka[num+1] << endl;
		num += 2;
    }*/
}

int check(float temp, char jedn) {
    if (jedn == 'F' && temp < -459.67) {
        cout << "Bledna wartosc temperatury dla stopni Fahrenheita!" << endl;
        return -999;
    }
    else if (jedn == 'C' && temp < -273.15) {
        cout << "Bledna wartosc temperatury dla stopni Celsjusza!" << endl;
        return -999;
    }
    else if (jedn == 'K' && temp < 0) {
        cout << "Bledna wartosc temperatury dla stopni Kelwina!" << endl;
        return -999;
    }
    else {
        return temp;
    }
}

float pobiezF(float stopnie) {
    cout << "Podaj stopnie Fahr: ";
    cin >> stopnie;
	stopnie = check(stopnie, 'F');
	return stopnie;
}
float pobiezC(float stopnie) {
    cout << "Podaj stopnie Celsius: ";
    cin >> stopnie;
    stopnie = check(stopnie, 'C');
    return stopnie;
}
float pobiezK(float stopnie) {
    cout << "Podaj stopnie Kelwin: ";
    cin >> stopnie;
    stopnie = check(stopnie, 'K');
    return stopnie;
}

void menu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr\n" << endl;
	cout << "7 - pokaz historie" << endl;
    cout << "8 - usun z historii" << endl;
    cout << "9 - modyfikuj historie" << endl;
    cout << "10 - losowe wypelnienie historii" << endl;
    cout << "11 - zakoncz dzialanie programu\n" << endl;
    cout << "Wybierz funkcje konwersji temperatury: ";
}

void menuProgram (double tab_wartosci[], char tab_jednostki[]) {
	float fahr, celsius, kelwin;
    int fn;
    cin >> fn;

    switch (fn)
    {
    case 1:
        fahr = pobiezF(0);
        celsius = FtoC(fahr);
        cout << "\n" << fahr << "   - >   " << celsius << "\n" << endl;
        wartosc(tab_wartosci, fahr, celsius, dataCounter);
        jednostka(tab_jednostki, 'F', 'C', dataCounter);
        if (dataCounter < limit) dataCounter += 2;
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
        cout << "\n" << fahr << "   ->   " << kelwin << "\n" << endl;
        wartosc(tab_wartosci, fahr, kelwin, dataCounter);
        jednostka(tab_jednostki, 'F', 'K', dataCounter);
        if (dataCounter < limit) dataCounter += 2;
        break;
    case 3:
        celsius = pobiezC(0);
        fahr = CtoF(celsius);
        cout << "\n" << celsius << "   ->   " << fahr << "\n" << endl;
        wartosc(tab_wartosci, celsius, fahr, dataCounter);
        jednostka(tab_jednostki, 'C', 'F', dataCounter);
        if (dataCounter < limit) dataCounter += 2;
        break;
    case 4:
        celsius = pobiezC(0);
        kelwin = CtoK(celsius);
        cout <<"\n" << celsius << "   ->   " << kelwin << "\n" << endl;
        wartosc(tab_wartosci, celsius, kelwin, dataCounter);
        jednostka(tab_jednostki, 'C', 'K', dataCounter);
        if (dataCounter < limit) dataCounter += 2;
        break;
    case 5:
        kelwin = pobiezK(0);
        celsius = KtoC(kelwin);
        cout << "\n" << kelwin << "   ->   " << celsius << "\n" << endl;
        wartosc(tab_wartosci, kelwin, celsius, dataCounter);
        jednostka(tab_jednostki, 'K', 'C', dataCounter);
        if (dataCounter < limit) dataCounter += 2;
        break;
    case 6:
        kelwin = pobiezK(0);
        fahr = KtoF(kelwin);
        cout << "\n" << kelwin << "   ->   " << fahr << "\n" << endl;
        wartosc(tab_wartosci, kelwin, fahr, dataCounter);
        jednostka(tab_jednostki, 'K', 'F', dataCounter);
        if (dataCounter < limit) dataCounter += 2;
        break;
    case 7:
        his(tab_wartosci, tab_jednostki, wybor_his());
        break;
    case 8:
		usun_his(tab_wartosci, tab_jednostki);  
        break;
    case 9:
        modyf_his(tab_wartosci, tab_jednostki);
		break;
    case 10: 
		los_his(tab_wartosci, tab_jednostki);
        break;
    default: exit(0);
    }

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