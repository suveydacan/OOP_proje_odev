#pragma once
#include <string>
#include <string.h>
class kiyafet
{
public:
	kiyafet(const char*, int, double, const char*, const char*);
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

	void kiyafetMenu();
	


	//void printkg();




private:
	char* kategori;
	int kiyafet_adi;
	double fiyat;
	char* boyut;
	char* renk;
	int slen;



	const char* elbise;
	const char*   tisort;
	const char*  pantolon;
	const char* gomlek;
	const char*   etek;
	const char*  ayakkabi;
	const char*   satir;

	int argc;
	char* argv[];

};

