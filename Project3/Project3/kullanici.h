#pragma once
#include "kisi.h"
class kullanici :
    public kisi
{
   public:
       kullanici(const char*,const char*, const char*, const char*, const char*, const char*, const char* ,const char*);
       kullanici();
       void setKullanici_ad(const char*);
       char* getKullanici_ad();
       void setEposta(const char*);
       char* getEposta();
       void setAdres_ilce(const char*);
       char* getAdres_ilce();
       void setK_Sifre(const char*);
       char* getK_Sifre();
       void setKupon(const char*);
       char* getKupon();
       void setTarih(const char*);
       char* getTarih();
      
   private:
       char* kullanici_ad;
       char* eposta;
       char* adres_ilce;
       char* k_sifre;
       char* indirim_kodu;
       char* dtarihi;
       int slen;
};

