#pragma once
#include <iostream>
#include <ctime>
#include <string>
class zaman
{
public:
    zaman(int, int);
	zaman();
	void setSaat();
	int getSaat();
	void setDakika();
	int getDakika();

	zaman getZaman();
	void siparisTeslimSaati(zaman); //overload kullan?ls?n?
	zaman getSiparisTeslimSaati();
	void kuryekontrol();


	zaman operator+ (const zaman&);
	//bool operator>= (const zaman&);


private:

	int dakika;
	int saat;
	int tamzaman;
	int temp;
	int temp1;
	int slen;

};
