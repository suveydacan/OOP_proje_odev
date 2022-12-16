#include "yonetici.h"
#include<iostream>
#include <string>

using namespace std;

yonetici::yonetici(const char* y_adSoyad, const char* y_tno, const char* sfr) : kisi(y_adSoyad, y_tno)
{
	setSifre(sfr);
}
void yonetici::setSifre(const char* y_sfr)
{
	slen = strlen(y_sfr);
	sifre = new char[slen + 1];
	if (sifre) {
		strcpy_s(sifre, (slen + 1), y_sfr);
	}
}
char* yonetici::getSifre()
{
	return sifre;

}
