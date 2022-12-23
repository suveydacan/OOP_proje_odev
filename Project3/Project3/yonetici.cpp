#include "yonetici.h"
#include<iostream>
#include <string>
#include <fstream>

using namespace std;

yonetici::yonetici(const char* y_adSoyad, const char* y_tno, const char* sfr) : kisi(y_adSoyad, y_tno)
{
	setSifre(sfr);
}
yonetici::yonetici() {
	
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
void yonetici::indirimTanimla()
{
	cout << "Indirim kodunu giriniz: ";
	string kupon;
	cin >> kupon;

	cout << "\nKuponun uygulacagi indirim miktari int turunden giriniz : ";

	cin >> indMiktar;
	cout << endl;

	const int LINE = 20;
	const int SIZE = 8;
	string veri[LINE][SIZE];
	int lineTemp=0;


	string inFileName = "C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; !inFile.eof(); i++)
		{
			lineTemp++;
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI a!" << inFileName << endl;
	}

	for (int i = 0;i<lineTemp-1; i++)
	{
		veri[i][6] = kupon;

	}
	ofstream DosyaYazma("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar1.txt");
	if (DosyaYazma.is_open())
	{
		for (int i = 0;i<lineTemp-1; i++)
		{
			for (int j = 0; j < SIZE; j++) {
				DosyaYazma << veri[i][j] << " ";
			}
			DosyaYazma << endl;
		}
	}

	DosyaYazma.close();

	cout << "kuponunuz basariyla kaydedildi.";

	remove("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt");
	rename("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar1.txt","C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt");
}

int yonetici::getIndMiktar()
{
	return indMiktar;
}