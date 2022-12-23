#pragma once
#include "kisi.h"
class yonetici :
    public kisi
{
    public:
        yonetici(const char*, const char*, const char*);
        yonetici();
        char* getSifre();
        void setSifre(const char* );
        void indirimTanimla();
        int getIndMiktar();
       
    private:
        char* sifre;
        int slen;
        int indMiktar;

};

