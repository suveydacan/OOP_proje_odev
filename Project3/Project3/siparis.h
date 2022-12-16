#pragma once
#include "kiyafet.h"
#include "zaman.h"
#include "kullanici.h"
#include "kiyafet.h"
#include <string.h>
#include <string>

class siparis :
    public kiyafet

{

public:
    int static kuryeSayisi;

    siparis(const char*, int, const char*, const char*, int, double, zaman, zaman);
    siparis();
    void setSiparis_no(int);
    int getSiparis_no();
    void siparisFatura(kullanici, zaman, kiyafet);
    void siparisTakip(kiyafet, kullanici, zaman);
    void setSiparis_ulasim(zaman);




private:
    int siparis_no;
    double siparis_fiyat;
    zaman siparis_baslangic;
    zaman siparis_ulasim;


};
