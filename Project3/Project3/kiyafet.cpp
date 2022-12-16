#include "kiyafet.h"
#include <string.h>
#include <iostream>
using namespace std;
kiyafet::kiyafet(const char* category, int kiyafetAdi, double fiyatt, const char* boyutt, const char* renkk) {
	setKategori(category);
	setKiyafet_adi(kiyafetAdi);
	setFiyat(fiyatt);
	setBoyut(boyutt);
	setRenk(renkk);



}

void kiyafet::setKategori(const char* cateegory) {
	slen = strlen(cateegory);
	kategori = new char[slen + 1];
	if (kategori) {
		strcpy_s(kategori, (slen + 1), cateegory);
	}
}

void kiyafet::setKiyafet_adi(int kiyafAdi) {
	kiyafet_adi = kiyafAdi;
}

void kiyafet::setFiyat(double fyt) {
	fiyat = fyt;
}
void kiyafet::setBoyut(const char* byt) {
	slen = strlen(byt);
	boyut = new char[slen + 1];
	if (boyut) {
		strcpy_s(boyut, (slen + 1), byt);
	}
}
void kiyafet::setRenk(const char* rnk) {
	slen = strlen(rnk);
	renk = new char[slen + 1];
	if (renk) {
		strcpy_s(renk, (slen + 1), rnk);
	}
}

void kiyafet::print()const {
	cout << "Kategori: " << kategori << " kiyafet adi: " << kiyafet_adi << " fiyat: " << fiyat << " beden: " << boyut << " renk: " << renk << endl;
}

int kiyafet::len()const {
	return slen;
}

char* kiyafet::getKategori() {
	return kategori;
}

int kiyafet::getKiyafet_adi() {
	return kiyafet_adi;
}
double kiyafet::getFiyat() {
	return fiyat;
}

char* kiyafet::getBoyut() {
	return boyut;
}

char* kiyafet::getRenk() {
	return renk;
}
