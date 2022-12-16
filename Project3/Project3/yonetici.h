#pragma once
#include "kisi.h"
class yonetici :
    public kisi
{
    public:
        yonetici(const char*, const char*, const char*);
        char getSifre();
        void setSifre(const char* sfr);
       
    private:
        char* sifre;
        int slen;

};

