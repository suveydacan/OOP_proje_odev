#include "kullanici.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;




kullanici::kullanici(const char* k_adSoyad,const char* k_tno,const char* k_ad,
	const char* k_email,const char* k_adres,const char* k_sfr,const char* k_kupon,const char* k_tarih) :kisi(k_adSoyad,k_tno)
{
	setKullanici_ad(k_ad);
	setEposta(k_email);
	setAdres_ilce(k_adres);
	setK_Sifre(k_sfr);
	setKupon(k_kupon);
	setTarih(k_tarih);
     
	ofstream yazmaDosyasi("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt",ios::out|ios::app);
	yazmaDosyasi << k_adSoyad << " " <<k_tno<<" "<<k_ad<<" "<<k_email<<" "<<k_adres<<" "<<k_sfr<<" "<<k_tarih<< endl;
	yazmaDosyasi.close();
}
kullanici::kullanici():kisi() {

}

void kullanici::setKullanici_ad(const char* kl_ad)
{
	slen = strlen(kl_ad);
	kullanici_ad = new char[slen + 1];
	if (kullanici_ad) {
		strcpy_s(kullanici_ad, (slen + 1), kl_ad);
	}

}
char* kullanici::getKullanici_ad()
{
	return kullanici_ad;
}
void kullanici::setEposta(const char* kullanici_email)
{
	slen = strlen(kullanici_email);
	const regex EpostaPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	bool email_kontrol=regex_match(kullanici_email, EpostaPattern);
	if (email_kontrol != 0)
	{
		cout << "geçerli email." << endl;
		eposta = new char[slen + 1];
		if (eposta) {
			strcpy_s(eposta, (slen + 1), kullanici_email);
		}
	}
	else {
		cout << "geçersiz email." << endl;
	}

	
}
char* kullanici::getEposta()
{
	return eposta;
}
void kullanici::setAdres_ilce(const char* kullanici_adres)
{
	slen = strlen(kullanici_adres);
	adres_ilce = new char[slen + 1];
	if (adres_ilce) {
		strcpy_s(adres_ilce, (slen + 1), kullanici_adres);
	}

}
char* kullanici::getAdres_ilce()
{
	return adres_ilce;
}
void kullanici::setK_Sifre(const char* kullanici_sfr)
{
	slen = strlen(kullanici_sfr);
	bool hasLower = false, hasUpper = false;
	bool hasDigit = false, specialChar = false;
	string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
	for (int i = 0; i <slen; i++) {
		if (islower(kullanici_sfr[i]))
			hasLower = true;
		if (isupper(kullanici_sfr[i]))
			hasUpper = true;
		if (isdigit(kullanici_sfr[i]))
			hasDigit = true;
		/*size_t special = kullanici.find_first_not_of(normalChars);
		if (special != string::npos)
			specialChar = true;*/
	}
	// Þifre kontrolü
	cout << "Güçlü þifre kontrolü:-";
	if (hasLower && hasUpper && hasDigit &&
		specialChar && (slen >= 8))
		cout << "GÜÇLÜ" << endl;
	else if ((hasLower || hasUpper) &&
		(slen >= 6))
		cout << "ORTA" << endl;
	else
		cout << "ZAYIF" << endl;

	
	k_sifre = new char[slen + 1];
	if (k_sifre) {
		strcpy_s(k_sifre, (slen + 1), kullanici_sfr);
	}

}
char* kullanici::getK_Sifre()
{
	return k_sifre;
}
void kullanici::setKupon(const char* kullanici_kupon)
{
	slen = strlen(kullanici_kupon);
	indirim_kodu = new char[slen + 1];
	if (indirim_kodu) {
		strcpy_s(indirim_kodu, (slen + 1), kullanici_kupon);
	}

}
char* kullanici::getKupon()
{
	return indirim_kodu;
}
void kullanici::setTarih(const char* dTarih)
{
	slen = strlen(dTarih);	
	const regex TarihPattern("^([0-2][0-9]|(3)[0-1])\/(((0)[0-9])|((1)[0-2]))\/\\d{4}$");
	bool tarih_kontrol = regex_match(dTarih, TarihPattern);
	if (tarih_kontrol != 0)
	{
		cout << "geçerli tarih" << endl;
		dtarihi = new char[slen + 1];
		if (dtarihi) {
			strcpy_s(dtarihi, (slen + 1), dTarih);
		}
	}
	else
	{
		cout << "Lütfen geçerli bir tarih giriniz!" << endl;
	}
	
}
char* kullanici::getTarih()
{
	return dtarihi;
}


