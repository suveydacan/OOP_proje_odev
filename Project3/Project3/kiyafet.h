#pragma once
#include <string>
#include <string.h>
#include "kullanici.h"
class kiyafet
{
public:
	kiyafet(const char*, int, double, const char*, const char*);
	kiyafet();
	char* getKategori();
	void setKategori(const char*);
	int getKiyafet_adi();
	void setKiyafet_adi(int);
	double getFiyat();
	void setFiyat(double);
	char* getBoyut();
	void setBoyut(const char*);
	char* getRenk();
	void setRenk(const char*);
	int len()const;
	void print()const;
	double gettoplamFiyat();
	void faturaPrint();
	

	void kiyafetMenu(kullanici);
private:
	char* kategori;
	int kiyafet_adi;
	double fiyat;
	char* boyut;
	char* renk;
	int slen;


	
	double toplamFiyat=0.0;

	
};

