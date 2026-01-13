#pragma once

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
void menuProgram(double tab_wartosci[], char tab_jednostki[]);

void wartosc(double war[], float st_wart, float nw_wart, int wsk);
void jednostka(char jed[], char st_jed, char nw_jed, int wsk);

void his(double wartosc[], char jednostka[], int wybor);
void wyswietl_his(double wartosc[], char jednostka[]);
void wyswietl_his_new(double wartosc[], char jednostka[], char jed);
int wybor_his();
void usun_his(double wartosc[], char jednostka[]);
void modyf_his(double wartosc[], char jednostka[]);
void los_his(double wartosc[], char jednostka[]);