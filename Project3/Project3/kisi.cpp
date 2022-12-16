#include "kisi.h"
#include<iostream>
#include <string>

using namespace std;


kisi::kisi(const char *ad,const char *tno) 
{
	setAd_soyad(ad);
	setTelno(tno);
}

kisi::kisi() {

}

char* kisi::getAd_soyad()  
{
	return ad_soyad;
}
void kisi::setAd_soyad(const char *a_s) 
{
	
	slen = strlen(a_s);
	ad_soyad = new char[slen + 1];
	if (ad_soyad) {
		strcpy_s(ad_soyad, (slen + 1), a_s);
	}
}
void kisi::setTelno(const char* tln)
{
	slen = strlen(tln);
	telno = new char[slen + 1];
	if (telno) {
		strcpy_s(telno,(slen + 1), tln);
	}
}

char* kisi::getTelno() 
{
	return telno;
}
void kisi::print()
{
	cout << ad_soyad<<","<<telno<<endl;
}

int kisi::len()const
{
	return slen;
}