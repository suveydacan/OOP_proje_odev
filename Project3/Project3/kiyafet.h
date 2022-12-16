#pragma once
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



private:
	char* kategori;
	int kiyafet_adi;
	double fiyat;
	char* boyut;
	char* renk;
	int slen;
};

