#include "kurye.h"
#include <iostream>

using namespace std;


kurye::kurye(zaman* teslimat, siparis siparisNo, const char* isim, const char* tlf_no) :kisi(isim, tlf_no), dagitim_bitisler(teslimat) {
	setSiparis_numaralari(siparisNo);//compositioni : ile atamak lazimdi ama bu comp. degil?
}

void kurye::setKurye_id(int* no) {
	int* kuryeNo = new int[siparis::kuryeSayisi];
	for (int i = 0; i++; i <= siparis::kuryeSayisi) {
		kuryeNo[i] = i;

	}
}

void kurye::setSiparis_numaralari(siparis siparis_nolar) {
	int nolar;
	nolar = siparis_nolar.getSiparis_no(); //lar eki neden?
}

void kurye::kuryeSayiGuncel(int n) {
	siparis::kuryeSayisi = n;
}

//void kurye::kuryeMusaitMi(zaman kontrol, zaman teslim) {
//	
//    kontrol.setSaat();
//	kontrol.setDakika();
//	if (teslim.getTemp() <= kontrol.getSaat() && teslim.getTemp1() <= kontrol.getDakika()) {
//		siparis::kuryeSayisi++;
//		cout << "\n kurye sayisi:" << siparis::kuryeSayisi;
//
//	}
//	else
//		cout << "\n kurye sayisi:" << siparis::kuryeSayisi << endl;
//}