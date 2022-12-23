#pragma once
#include "kisi.h"
#include "zaman.h"
#include "siparis.h"

class kurye :
	public kisi {
public:

	int static count;
	int static count1;
	kurye(zaman, siparis, const char*, const char*);
	kurye();
	void kuryeEkle();
	zaman* setDagitim_bitisler(zaman);
	int* setSiparis_numaralari(siparis);
	//zaman operator= (const zaman&);
	//void kuryeMusaitMi(zaman,zaman);//dagitim_bitisler zaman* yapmad?m dziiye atmad???m için
private:

	zaman* dagitim_bitisler;
	int* siparis_numaralari;
	//galiba kuryelere sipari? at?yoruz ya diziyle


};

