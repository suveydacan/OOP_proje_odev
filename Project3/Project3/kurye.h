#pragma once
#include "kisi.h"
#include "zaman.h"
#include "siparis.h"

class kurye :
	public kisi {
public:


	kurye(zaman*, siparis, const char*, const char*);
	void setKurye_id(int*);
	void setSiparis_numaralari(siparis);
	void kuryeSayiGuncel(int);
	//void kuryeMusaitMi(zaman,zaman);//dagitim_bitisler zaman* yapmad?m dziiye atmad???m için
private:

	zaman* dagitim_bitisler;
	int* siparis_numaralari;
	//galiba kuryelere sipari? at?yoruz ya diziyle


};