#pragma once
class kisi
{
public:
	kisi(const char*,const char*);
	kisi();
	char* getAd_soyad();
	void setAd_soyad(const char*) ;
	void setTelno(const char*);
	char* getTelno();
	int len()const;
	void print();
private:
	char* ad_soyad ;
	char* telno;
	int slen;

};

//NOT:destructor tanýmlayýp bellekte yer tahsis ettiðimiz kýsýmlarý delete et.