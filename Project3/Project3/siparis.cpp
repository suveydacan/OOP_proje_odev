#include "siparis.h"
#include "zaman.h"
#include "kullanici.h"
#include "kiyafet.h"
#include <iostream>
#include <string>
using namespace std;

int siparis::kuryeSayisi = 5;
siparis::siparis(const char* kategor, int kiyaf_ad, const char* size, const char* color, int sn, double sf, zaman baslangic, zaman ulasim) //başlangıcı get fonk ile saat mi vercez?
	:kiyafet(kategor, kiyaf_ad, sf, size, color), siparis_baslangic(baslangic.getZaman()), siparis_ulasim(ulasim.getSiparisTeslimSaati())

{

	/*siparis_baslangic = baslangic.getZaman(); burdan bi şey dönmüyo constructora gidiyo sadece  nesne oluşuyo doğru şeyler atanıyo da kullanmadım
	siparis_ulasim= */
	setSiparis_no(sn);




}

siparis::siparis() {

}

void siparis::setSiparis_no(int sip_no) {
	siparis_no = sip_no;
}

int siparis::getSiparis_no() {
	return siparis_no;
}
void siparis::siparisFatura(kullanici kullanan, zaman tarih, kiyafet bilgiler) {
	if (tarih.getSaat() < 10 && tarih.getDakika() < 10) {
		cout << "Sayin  " << kullanan.getKullanici_ad() << ": \n Siparisiniz " << "0" << tarih.getSaat() << "." << "0" << tarih.getDakika() << " saatinde olusturulmustur. Siparirisinize ait detaylar listelenmistir:" << endl;
		bilgiler.print();
	}
	else  if (tarih.getSaat() > 10 && tarih.getDakika() == 0) {
		cout << "Sayin  " << kullanan.getKullanici_ad() << ": \n Siparisiniz " << tarih.getSaat() << "." << "00" << tarih.getDakika() << " saatinde olusturulmustur. Siparirisinize ait detaylar listelenmistir:" << endl;
		bilgiler.print();
	}
	else if (tarih.getSaat() > 10 && tarih.getDakika() < 10) {
		cout << "Sayin  " << kullanan.getKullanici_ad() << ": \n Siparisiniz " << tarih.getSaat() << "." << "0" << tarih.getDakika() << " saatinde olusturulmustur. Siparirisinize ait detaylar listelenmistir:" << endl;
		bilgiler.print();
	}
	else if (tarih.getSaat() < 10 && tarih.getDakika() < 10) {
		cout << "Sayin  " << kullanan.getKullanici_ad() << ": \n Siparisiniz " << "0" << tarih.getSaat() << "." << "0" << tarih.getDakika() << " saatinde olusturulmustur. Siparirisinize ait detaylar listelenmistir:" << endl;
		bilgiler.print();
	}
	else if (tarih.getSaat() < 10) {
		cout << "Sayin  " << kullanan.getKullanici_ad() << ": \n Siparisiniz " << "0" << tarih.getSaat() << "." << tarih.getDakika() << " saatinde olusturulmustur. Siparirisinize ait detaylar listelenmistir:" << endl;
		bilgiler.print();
	}
	else {
		cout << "Sayin  " << kullanan.getKullanici_ad() << ": \n Siparisiniz " << tarih.getSaat() << "." << tarih.getDakika() << " saatinde olusturulmustur. Siparirisinize ait detaylar listelenmistir:" << endl;
		bilgiler.print();
	}



}

void siparis::siparisTakip(kiyafet kiyafeti, kullanici kullanicisi, zaman zamani) {

	cout << getSiparis_no() << " numarali siparisiniz alinmistir." << endl;
	cout << kiyafeti.getKiyafet_adi() << "\n"
		<< "size: " << kiyafeti.getBoyut() << "\n"
		<< "Renk: " << kiyafeti.getRenk() << "\n"
		<< kiyafeti.getFiyat()
		<< endl;

	const char* adres = kullanicisi.getAdres_ilce();
	if (siparis::kuryeSayisi > 0) {
		if (strcmp(adres, "Ortahisar") == 0) {
			cout << " Bilgileri belirtilen siparisiniz 35 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
			cout << "kurye sayisi:" << siparis::kuryeSayisi << endl;
			zaman a(0, 35);
			zamani.siparisTeslimSaati(a);
		}
		else if (strcmp(adres, "Akcaabat") == 0)
		{
			cout << " Bilgileri belirtilen siparisiniz 50 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
		}
		else if (strcmp(adres, "Vakfikebir") == 0)
		{
			cout << " Bilgileri belirtilen siparisiniz 90 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
		}
		else if (strcmp(adres, "Besikduzu") == 0)
		{
			cout << " Bilgileri belirtilen siparisiniz 110 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
		}
		else if (strcmp(adres, "Yomra") == 0)
		{
			cout << " Bilgileri belirtilen siparisiniz 55 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
		}
		else if (strcmp(adres, "Arsin") == 0)
		{
			cout << " Bilgileri belirtilen siparisiniz 70 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
		}
		else if (strcmp(adres, "Arakli") == 0)
		{
			cout << " Bilgileri belirtilen siparisiniz 100 dk içerisinde teslim edilecektir." << endl;
			siparis::kuryeSayisi--;
		}
		else {
			cout << "Hizmet verdigimiz bölgenin disindasiniz" << endl;
		}
		if (kuryeSayisi == 0)
			cout << "Uygun kurye bulunmadığı için siparisiniz siraya alinmistir." << endl;

	}
}




void siparis::setSiparis_ulasim(zaman zamansu) {
	siparis_ulasim = zamansu;
}