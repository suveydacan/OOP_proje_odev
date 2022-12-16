#include "kiyafet.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
kiyafet::kiyafet(const char* category, int kiyafetAdi, double fiyatt, const char* boyutt, const char* renkk) {
	setKategori(category);
	setKiyafet_adi(kiyafetAdi);
	setFiyat(fiyatt);
	setBoyut(boyutt);
	setRenk(renkk);



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

void kiyafet::kiyafetMenu()
{
	int secim = -1;
	while (secim != 0)
	{



		cout << "kiyafet kategorileri menusu:\n1-) elbise\n2-) tisort\n3-) pantolon\n4-) gomlek\n5-) etek\n6-) ayakkabi\n0-) cikis\n\n katagori seciniz: " << endl;
		cin >> secim;

		if (secim == 1) {

			elbise = new char[15];

			elbise = "elbise";
			/*ofstream myfile1;
			myfile1.open("kiyafet1.txt", ios::out | ios::app);*/

			cout << "------------ elbise --------------\n";
			cout << "|beden bilgisi: S,M,L,XL,XXL      |\n|renk bilgisi: siyah, mavi, beyaz |\n" << endl;



		beden1:

			cout << "elbise bedenini seciniz:" << endl;

			cin >> boyut;
			stringstream aa;
			aa << boyut;
			string a;
			aa >> a;
			if (a != "s" && a != "m" && a != "l" && a != "xl" && a != "xxl" && a != "S" && a != "M" && a != "L" && a != "XL" && a != "XXL") {
				cout << boyut << " bedenine ait urun stogu mevcut degil.." << endl;
				goto beden1;
			}

		renk1:

			cout << "elbise rengini seciniz: " << endl;
			cin >> renk;
			stringstream ss;
			ss << renk;
			string s;
			ss >> s;
			if (s != "siyah" && s != "mavi" && s != "beyaz") {
				cout << renk << " rengine ait urun stogu mevcut degil.." << endl;
				goto renk1;
			}

			//myfile1 << elbise << " " << boyut << "  " << renk << endl;

			kiyafet kiyafet1(elbise, 32, 10.0, boyut, renk);
			//setReturnKiyafet(kiyafet1);


			//myfile1.close();
			//system("PAUSE");

		}
		else if (secim == 2) {

			tisort = new char[15];
			tisort = "tisort";

			/*ofstream myfile1;
			myfile1.open("kiyafet1.txt", ios::out | ios::app);*/

			cout << " ----------- t-shirt -------------\n ";
			cout << "|beden bilgisi: S,M,L,XL,XXL     |\n |renk bilgisi: siyah, mavi, beyaz, lacivert, gri, kahverengi, bordo |\n" << endl;

		beden2:
			cout << "t-shirt bedenini seciniz:" << endl;
			cin >> boyut;
			stringstream aa;
			aa << boyut;
			string a;
			aa >> a;
			if (a != "s" && a != "m" && a != "l" && a != "xl" && a != "xxl" && a != "S" && a != "M" && a != "L" && a != "XL" && a != "XXL") {
				cout << boyut << " bedenine ait urun stogu mevcut degil.." << endl;
				goto beden2;
			}
		renk2:

			cout << "t-shirt rengini seciniz:" << endl;
			cin >> renk;
			stringstream ss;
			ss << renk;
			string s;
			ss >> s;
			if (s != "siyah" && s != "mavi" && s != "beyaz" && s != "kahverengi" && s != "gri" && s != "lacivert" && s != "bordo") {
				cout << renk << " rengine ait urun stogu mevcut degil.." << endl;
				goto renk2;
			}

			/*myfile1 << tisort << " " << boyut << "  " << renk << endl;

			myfile1.close();*/

			kiyafet kiyafet1(tisort, 37, 10.0, boyut, renk);
			//setReturnKiyafet(kiyafet1);

		}
		else if (secim == 3) {
			pantolon = new char[15];
			pantolon = "pantolon";

			/*ofstream myfile1;
			myfile1.open("kiyafet1.txt", ios::out | ios::app);*/

			cout << "------------ PANTOLON ------------\n ";
			cout << "|beden bilgisi: S,M,L,XL,XXL      |\n |renk bilgisi: siyah, mavi, beyaz, kahvrengi |\n" << endl;

		beden3:

			cout << "Pantolon bedenini seciniz:" << endl;
			cin >> boyut;
			stringstream aa;
			aa << boyut;
			string a;
			aa >> a;
			if (a != "s" && a != "m" && a != "l" && a != "xl" && a != "xxl" && a != "S" && a != "M" && a != "L" && a != "XL" && a != "XXL") {
				cout << boyut << " bedenine ait urun stogu mevcut degil.." << endl;
				goto beden3;
			}
		renk3:
			cout << "pantolon rengini seciniz:" << endl;
			cin >> renk;
			stringstream ss;
			ss << renk;
			string s;
			ss >> s;
			if (s != "siyah" && s != "mavi" && s != "beyaz" && s != "kahverengi") {
				cout << renk << " rengine ait urun stogu mevcut degil.." << endl;
				goto renk3;
			}

			/*myfile1 << pantolon << " " << boyut << "  " << renk << endl;

			myfile1.close();*/
			kiyafet kiyafet1(pantolon, 36, 10.0, boyut, renk);
			//setReturnKiyafet(kiyafet1);

		}
		else if (secim == 4) {
			gomlek = new char[15];
			gomlek = "gomlek";

			/*ofstream myfile1;
			myfile1.open("kiyafet1.txt", ios::out | ios::app);*/

			cout << "-------------- GOMLEK --------------\n ";
			cout << "|beden bilgisi: S,M,L,XL,XXL      |\n |renk bilgisi: siyah, mavi, beyaz , kahverengi |\n" << endl;
		beden4:
			cout << "gomlek bedenini seciniz:" << endl;
			cin >> boyut;
			stringstream aa;
			aa << boyut;
			string a;
			aa >> a;
			if (a != "s" && a != "m" && a != "l" && a != "xl" && a != "xxl" && a != "S" && a != "M" && a != "L" && a != "XL" && a != "XXL") {
				cout << boyut << " bedenine ait urun stogu mevcut degil.." << endl;
				goto beden4;
			}

		renk4:
			cout << "gomlek rengini seciniz:" << endl;
			cin >> renk;
			stringstream ss;
			ss << renk;
			string s;
			ss >> s;
			if (s != "siyah" && s != "mavi" && s != "beyaz" && s != "kahverengi") {
				cout << renk << " rengine ait urun stogu mevcut degil.." << endl;
				goto renk4;
			}

			/*myfile1 << gomlek << " " << boyut << "  " << renk << endl;

			myfile1.close();*/
			kiyafet kiyafet1(gomlek, 35, 10.0, boyut, renk);
			//setReturnKiyafet(kiyafet1);
		}
		else if (secim == 5) {
			etek = new char[15];
			etek = "etek";

			/*ofstream myfile1;
			myfile1.open("kiyafet1.txt", ios::out | ios::app);*/

			cout << "--------------- ETEK ---------------\n ";
			cout << "|beden bilgisi: S,M,L,XL,XXL      |\n |renk bilgisi: siyah, mavi, beyaz |\n" << endl;
		beden5:
			cout << "etek bedenini seciniz:" << endl;
			cin >> boyut;
			stringstream aa;
			aa << boyut;
			string a;
			aa >> a;
			if (a != "s" && a != "m" && a != "l" && a != "xl" && a != "xxl" && a != "S" && a != "M" && a != "L" && a != "XL" && a != "XXL") {
				cout << boyut << " bedenine ait urun stogu mevcut degil.." << endl;
				goto beden5;
			}
		renk5:
			cout << "etek rengini seciniz:" << endl;
			cin >> renk;
			stringstream ss;
			ss << renk;
			string s;
			ss >> s;
			if (s != "siyah" && s != "mavi" && s != "beyaz") {
				cout << renk << " rengine ait urun stogu mevcut degil.." << endl;
				goto renk5;
			}

			/*myfile1 << etek << " " << boyut << "  " << renk << endl;

			myfile1.close();*/
			kiyafet kiyafet1(etek, 34, 10.0, boyut, renk);
			//setReturnKiyafet(kiyafet1);

		}
		else if (secim == 6) {
			ayakkabi = new char[15];
			ayakkabi = "ayakkabi";

			/*ofstream myfile1;
			myfile1.open("kiyafet1.txt", ios::out | ios::app);*/

			cout << "------------  AYAKKABI -------------\n ";
			cout << "|beden bilgisi: 36,37,38,39,40      |\n |renk bilgisi: siyah, mavi, beyaz |\n" << endl;
		beden6:
			cout << "ayakkabi bedenini seciniz:" << endl;
			cin >> boyut;
			stringstream aa;
			aa << boyut;
			string a;
			aa >> a;
			if (a != "36" && a != "37" && a != "38" && a != "39" && a != "40") {
				cout << boyut << " bedenine ait urun stogu mevcut degil.." << endl;

				goto beden6;
			}
		renk6:
			cout << "ayakkabi rengini seciniz:" << endl;
			cin >> renk;
			stringstream ss;
			ss << renk;
			string s;
			ss >> s;
			if (s != "siyah" && s != "mavi" && s != "beyaz") {
				cout << renk << " rengine ait urun stogu mevcut degil.." << endl;
				goto renk6;
			}

			/*myfile1 << ayakkabi << " " << boyut << "  " << renk << endl;

			myfile1.close();
			system("PAUSE");*/
			kiyafet kiyafet1(ayakkabi, 33, 10.0, boyut, renk);
			//setReturnKiyafet(kiyafet1);
		}
		
		
		
	}


}
//void kiyafet::setReturnKiyafet(kiyafet kiyaf) {
//	kiyafet nesne = kiyaf;
//
//}
//
//kiyafet kiyafet::getReturnKiyafet() {
//	return nesne();
//}

