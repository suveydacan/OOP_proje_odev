#include "kurye.h"
#include <iostream>
#include <fstream>

using namespace std;

int kurye::count = 1;
int kurye::count1 = 1;

kurye::kurye(zaman teslimat, siparis siparisNo, const char* isim, const char* tlf_no) :kisi(isim, tlf_no), dagitim_bitisler(setDagitim_bitisler(teslimat)) {
	setSiparis_numaralari(siparisNo);//compositioni : ile atamak lazimdi ama bu comp. degil?
}
kurye::kurye()
{

}



//void kurye::setSiparis_numaralari(siparis siparis_nolar) {
//	int nolar;
//	nolar = siparis_nolar.getSiparis_no(); //lar eki neden?
//}

void kurye::kuryeEkle() {

	cout << "Kurye ismini giriniz: ";
	char* Kuryename = new char[15];
	cin >> Kuryename;
	setAd_soyad(Kuryename);


	cout << "\nKurye iletisim numarasi giriniz : ";
	char* kuryeTelno = new char[15];
	cin >> kuryeTelno;
	setTelno(kuryeTelno);

	

	ofstream yazmaDosyasi("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kurye.txt", ios::out | ios::app);
	yazmaDosyasi <<getAd_soyad()<<" "<<getTelno()<< endl;
	yazmaDosyasi.close();

	
	string line;

	ifstream okumaDosyasi("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kurye.txt");
	if (okumaDosyasi.is_open())
	{
		while (!okumaDosyasi.eof())
		{
			getline(okumaDosyasi, line);
			
			siparis::kuryeSayisi++;
		}

		okumaDosyasi.close();
		
	}

	else
	{
		cout << "DOSYA BULUNAMADI";
		system("PAUSE");
	}


}



zaman* kurye::setDagitim_bitisler(zaman time) {
	//zaman* array;
	dagitim_bitisler[count + 1];
	for (count; count <= siparis::kuryeSayisi; count++) {

		dagitim_bitisler[count - 1] = (time.getSiparisTeslimSaati());
	}
	return dagitim_bitisler;

}

int* kurye::setSiparis_numaralari(siparis sipnos) {
	siparis_numaralari[count1 + 1];
	for (count1; count1 <= siparis::kuryeSayisi; count1++) {
		siparis_numaralari[count1 - 1] = sipnos.getSiparis_no();
	}
	return siparis_numaralari;
}
