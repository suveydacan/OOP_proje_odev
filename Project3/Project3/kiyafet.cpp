#include "kiyafet.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

kiyafet::kiyafet(const char* category, int kiyafetAdi, double fiyatt, const char* boyutt, const char* renkk) {
	setKategori(category);
	setKiyafet_adi(kiyafetAdi);
	setFiyat(fiyatt);
	setBoyut(boyutt);
	setRenk(renkk);

	ofstream myfile1;
			myfile1.open("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kiyafet1.txt", ios::out | ios::app);
			myfile1 << category << " " << boyutt << "  " << renkk <<" "<< fiyatt << endl;
			myfile1.close();
}
kiyafet::kiyafet() {

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
string arraytemp[10];
void kiyafet::print()const {
	for (int i = 0; i < 10; i++) {
		cout << arraytemp[i] << endl;
	}
	cout << "Toplam siparis tutariniz: " << toplamFiyat <<" TL" << endl;
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

void kiyafet::kiyafetMenu(kullanici kullanan)
{
	int secim = -1;
	while (secim != 0)
	{
		menu:
		cout << "Urun secimi yapiniz." << endl;
		string satir;

		ifstream okumaDosyasi("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kategori.txt");
		if (okumaDosyasi.is_open())
		{
			while (!okumaDosyasi.eof())
			{
				getline(okumaDosyasi, satir);
				cout << satir << endl;

			}

			okumaDosyasi.close();

		}

		

		kategori = new char[8];

		cin >> kategori;

		const int line1 = 15;
		const int size1 = 3;
		string veri1[line1][size1];

		string inFileName = "C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kategori.txt";
		ifstream inFile;
		inFile.open(inFileName.c_str());

		if (inFile.is_open())
		{
			for (int i = 0; i < line1; i++)
			{
				for (int j = 0; j < size1; j++)
				{
					inFile >> veri1[i][j];
				}

			}

			inFile.close();
		}
		else { //Error message
			cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
		}

		int urunKontrol = 0;
		for (int i = 0; i < line1; i++)
		{
			string ktg = veri1[i][0];
			int n = ktg.length();
			const char* ktgr = new char[n + 1];
			ktgr = ktg.c_str();

			if (strcmp(kategori, ktgr) == 0) {
				string fyt = veri1[i][1];
				fiyat = atof(fyt.c_str());
				kiyafet_adi = fiyat + 1000;

				toplamFiyat += fiyat;
				

				urunKontrol = 1;
			}

		}

		if (urunKontrol == 0)
		{
			cout << "Böyle bir urun bulunmamaktadir.Tekrar deneyiniz." << endl;
			goto menu;
		}





		cout << "|beden bilgisi: S,M,L,XL,XXL,36,37,38,39,40       |\n|renk bilgisi: siyah, mavi, beyaz |\n" << endl;



	beden1:

		cout << "Beden seciniz : " << endl;
		boyut = new char[10];
		cin >> boyut;



		if ((strcmp(boyut, "s") && strcmp(boyut, "m") && strcmp(boyut, "l") && strcmp(boyut, "xl") && strcmp(boyut, "xxl")&& strcmp(boyut, "S") && strcmp(boyut, "M")
			&& strcmp(boyut, "L") && strcmp(boyut, "XL") && strcmp(boyut, "XXL") && (strcmp(boyut, "36") && strcmp(boyut, "37") && strcmp(boyut, "38") && strcmp(boyut, "39")
				&& strcmp(boyut, "40"))) == 1) {
			cout << boyut << " boyle bir beden mevcut degil.." << endl;
			goto beden1;
		}

	renk1:

		cout << "Renk seciniz: " << endl;
		renk = new char[10];
		cin >> renk;

		if ((strcmp(renk,"siyah") && strcmp(renk, "mavi") && strcmp(renk, "beyaz"))==1) {
			cout << renk << " boyle bir renk mevcut degil.." << endl;
			goto renk1;
		}

		
		kiyafet kiyafet1(kategori, kiyafet_adi, fiyat, boyut, renk);
		
	    
		cout << "urun secimine devam etmek icin 1 e siparis vermek icin 0 a basiniz." << endl;
		cin >> secim;
		
	}
		cout << "FATURALANDIRMA..." << endl;
		
		short loop = 0;
		string line;
		ifstream myfile("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kiyafet1.txt");
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				getline(myfile, line);
				arraytemp[loop] = line;
				++loop;
			}

			myfile.close();
			remove("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kiyafet1.txt");
		}

		else
		{
			cout << "can't open the file";
			system("PAUSE");
		}

		ofstream yazmaDosya("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\fatura.txt", ios::out | ios::app);
		yazmaDosya << kullanan.getAd_soyad() <<endl;
		for (int i = 0; i < 10; i++) {
			yazmaDosya << arraytemp[i] << endl;
		}
		yazmaDosya << "Toplam siparis tutariniz: " << toplamFiyat << " TL" << endl << endl<< endl;
		

		yazmaDosya.close();



}

double kiyafet::gettoplamFiyat() {
	return toplamFiyat;
}


void kiyafet::faturaPrint()
{
	string line;
	ifstream myfile("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\fatura.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			cout << line<<endl;
			
		}

		myfile.close();
	}

	else
	{
		cout << "can't open the file";
		system("PAUSE");
	}
}

