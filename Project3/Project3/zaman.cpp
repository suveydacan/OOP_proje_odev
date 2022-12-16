
#include "zaman.h"
#include <iostream>
#include <ctime>
#include <string>
#include "siparis.h"
//#include "kurye.h"
using namespace std;


zaman::zaman(int s, int d) {

    saat = s;
    dakika = d;

}
zaman::zaman() {
    setDakika();
    setSaat();
}

void zaman::setSaat() {
    time_t now = time(0);
    struct tm  tstruct;
    //char buf[3];
#pragma warning(disable : 4996)
    tstruct = *localtime(&now);
#pragma warning(default: 4996)
    char* saaat = new char[3]; //saat fix 2 karakter geliyor
    strftime(saaat, sizeof(saaat), "%H", &tstruct);
    saat = atoi(saaat);
    //int slen = sizeof(saat);

    /*for (int i = 0; i <= slen; i++) {
        saat[i] = buf[i];
    }*/

}
//sipariş teslim edildiyse kuryeyi serbest bırakacak setDakikayı yazmadım statik nere geliyo hatalı bi fonk
void zaman::siparisTeslimSaati(zaman teslimatSure) {

    zaman time(saat, dakika);
    zaman time1(0, 0);
    time1 = teslimatSure + time;


    //if (teslimatSure.dakika >= b.dakika || dakika + teslimatSure.dakika >= 60) {//toplam 120 dk da olabilir 2 kere artırmak gerekir
    //    saat =saat+ (dakika + teslimatSure.dakika )/60;
    //    dakika= ((dakika + teslimatSure.dakika) % 60);
    //}
    //else {
    //    dakika =((dakika + teslimatSure.dakika) % 60);

    //}
    temp = time1.saat;
    temp1 = time1.dakika;

    zaman müsait(temp, temp1);


    if (temp1 < 10 && temp < 10) {
        cout << "siparisiniz " << "0" << temp << "." << "0" << temp1 << " saatinde teslim edilecektir" << endl;
    }
    else if (temp < 10 && temp1 == 0) {
        cout << "siparisiniz " << "0" << temp << "." << "00" << temp1 << " saatinde teslim edilecektir" << endl;
    }
    else if (temp >= 10 && temp1 == 0) {
        cout << "siparisiniz " << temp << "." << "00" << temp1 << " saatinde teslim edilecektir" << endl;
    }
    else if (temp < 10 && temp1 >= 10) {
        cout << "siparisiniz " << "0" << temp << "." << temp1 << " saatinde teslim edilecektir" << endl;
    }
    else if (temp1 < 10 && temp >= 10) {
        cout << "siparisiniz " << temp << "." << "0" << temp1 << " saatinde teslim edilecektir" << endl;
    }
    else
        cout << "siparisiniz " << temp << "." << temp1 << " saatinde teslim edilecektir" << endl;




    //    siparis spr();
       // spr.setSiparis_ulasim(getSiparisTeslimSaati()); //ulaşıma saat setletiğime inanıyorum
}
void zaman::kuryekontrol() {
    setSaat();
    setDakika();
    if (temp <= getSaat() && temp1 <= getDakika()) {
        siparis::kuryeSayisi++;
        cout << "\n kurye sayisi:" << siparis::kuryeSayisi << endl;

    }
    else
        cout << "\n kurye sayisi:" << siparis::kuryeSayisi << endl;


}
zaman zaman::getSiparisTeslimSaati() {
    return zaman(temp, temp1); //bu nası yazılacak
}

int zaman::getSaat() {


    return saat;

}


zaman zaman::getZaman() {
    zaman a(saat, dakika);
    return a;
}
void zaman::setDakika() {
    time_t now = time(0);
    struct tm  tstruct;
    //char buf[3];
#pragma warning(disable : 4996)
    tstruct = *localtime(&now);
#pragma warning(default: 4996)
    char* dk = new char[3]; //saat fix 2 karakter geliyor
    strftime(dk, sizeof(dk), "%M", &tstruct);
    dakika = atoi(dk);
    //int slen = sizeof(dakika);

    /*for (int i = 0; i <= slen; i++) {
        dakika[i] = buf[i];
    }*/


}

int zaman::getDakika() {
    return dakika;
}



//bool zaman::operator>= (const zaman& zmn)  {
//    int thisval = (saat,dakika);
//    int zamanval = static_cast<int>(zmn.saat, zmn.dakika);
//    return zamanval >= thisval;
//}

zaman zaman::operator+ (const  zaman& zamanlama) {
    // zaman(saat + zamanlama.saat, dakika + zamanlama.dakika);

    int hour = this->saat + zamanlama.saat;
    int minute = this->dakika + zamanlama.dakika;
    if (minute >= 60 || dakika + minute >= 60) {//toplam 120 dk da olabilir 2 kere artırmak gerekir
        hour = hour + (dakika + minute) / 60;
        minute = (minute) % 60;
    }
    else {
        minute = ((minute) % 60);

    }
    zaman teslim_zaman(hour, minute);
    return teslim_zaman;
    /* temp = saat;
     temp1 = dakika;
     setSaat();
     setDakika();
     if (temp <= getSaat() && temp1 <= getDakika()) {
         siparis::kuryeSayisi++;
         cout << "\n kurye sayisi:" << siparis::kuryeSayisi;

     }*/
}