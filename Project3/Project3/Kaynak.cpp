#include <iostream>
#include <locale.h> //türkçe karakter kullanmak için ekledik.
#include "kisi.h"
#include "siparis.h"
#include "zaman.h"
#include "kurye.h"
#include "yonetici.h"
#include "kullanici.h"
#include "kiyafet.h"
#include <string>
#include <string.h>
#include <fstream>
#include <conio.h> 
#include <cstdio>


using namespace std;

void uyeKaydiFormu();
int yoneticiGiris();
int musteriGiris();
void printOneri();
void OneriYaz();
void sifreDegistirme();
void urunGirisi();


kiyafet kiyafet1;
siparis siparis1;
zaman zaman1;
kullanici kullanici1;

yonetici yonetici1;
kurye kurye1;



int main()
{
	setlocale(LC_ALL, "Turkish");
	/*kiyafet kiyafet11("kadin", 33, 41.00, "m", "mavi");
	zaman* zaman2;
	kullanici kullanici11("zeyno","530","zeyy","@gmail","Ortahisar","123","0","0804");
	siparis sipa("kadin",23,"m","mavi",3,40.0,zaman1,zaman1);
	sipa.siparisTakip(kiyafet11,kullanici11,zaman1);
	kurye kuryes(zaman1, sipa, kullanici11.getKullanici_ad(), kullanici11.getTelno());*/
	
	anasayfa:
	cout << "1. sisteme giris" << endl << "2. Uye kaydi" << endl<< "3. cikis" << endl;

	int number;
	cin >> number;
	switch (number) {
	case 1:
		sistemG:
		cout << "1. yönetici girisi" << endl << "2. musteri girisi" << endl << "3.Geri" << endl;
		int num;
		cin >> num;
		switch (num) {
			case 1:
			{
				yoneticii:
				int n = yoneticiGiris();
				switch (n) {
					case 0:
					{
						cout << "Kullanici adi veya sifre hatali.Tekrar Deneyiniz!" << endl;
						goto yoneticii;
						break;
					}
					case 1:
					{
						    urunEkle:
							cout << "\n1.Urun girisi" << endl << "2.Kurye ekle" << endl << "3.Sikayet ve Oneri Gor" << endl
								<< "4.Indirim kodu tanimla" << endl << "5.Faturalari goruntule" <<endl<<"6.Geri"<< endl;
							int num;
							cin >> num;
							switch (num) {
							case 1:
								urunGirisi();
								goto urunEkle;
								break;
							case 2:
								kurye1.kuryeEkle();
								goto urunEkle;
								break;
							case 3:
								printOneri();
								goto urunEkle;
								break;
							case 4:
								yonetici1.indirimTanimla();
								goto urunEkle;
								break;
							case 5:
								kiyafet1.faturaPrint();
								goto urunEkle;
								break;
							case 6:
								goto sistemG;
								break;
							default:
								break;
							}
							break;
						default:
							break;
					}

					   break;
				}
			}
			case 2:
			{
			    musterii:
				int n=musteriGiris();
				switch(n){
				case 0:
				{
					
					cout << "Kullanici adi veya sifre hatali.Tekrar Deneyiniz!" << endl;
					goto musterii;
					break;
				}
				case 1:
					sipariss:
					cout << "1.Kiyafet kategorisi ve ürün seçimi" << endl << "2.Siparis Takip" << endl << "3.Sikayet/Öneri paylas" << endl
						<< "4.Sifre degistir" << endl << "5.Geri dön" << endl;
					int num;
					cin >> num;
					switch (num){
					case 1:
					{
						kiyafet1.kiyafetMenu(kullanici1);
						
						if (kullanici1.getKupon() != "NULL")
						{
							cout << "Aktif indirim kuponunuz varsa faturaniza yansitilacaktir. Yoksa standart ucretlendirmeyi goreceksiniz." << endl;
						}
						siparis1.siparisFatura(kullanici1, zaman1, kiyafet1);
						cout << "Indirimli sepet tutariniz: " << (kiyafet1.gettoplamFiyat() - yonetici1.getIndMiktar()) << " TL"<<endl;
						goto sipariss;
					}
						break;
					case 2:
					{
						int no = 1091;
						siparis1.setSiparis_no(no);
						siparis1.siparisTakip(kiyafet1, kullanici1, zaman1);
						no++;
						goto sipariss;
							break;
							
					}
					case 3:
					{

						OneriYaz();  //yazmıyor.
						goto sipariss;
						break;
					}
					case 4:
					{
						sifreDegistirme();
						goto sipariss;
						break;
					}
					case 5:
						goto sistemG;
						break;
					default:
						break;
					}
				default:
					break;
				}
				break;
			}
			case 3:
				goto anasayfa;
                break; 
			
		}
		break;
	case 2:
		uyeKaydiFormu();
		goto anasayfa;
		break;
	
	case 3:
		exit(1);
		break;
	default:
		break;

	}

	
	
}
void uyeKaydiFormu()
{
	char* k_ad=new char[15];
	char* k_tno=new char[15];
	char* k_nickname=new char[15];
	char* k_mail = new char[15];
	char* k_adres = new char[15];
	char* sfr = new char[15];
	char* kpn = new char[15];
	char* dt = new char[15];

	

	cout << "uye kaydi icin bilgileri giriniz: "<<endl;
	cout << "ad-soyad: " << endl;  cin >> k_ad;
	cout << "telno: " << endl;  cin >> k_tno;                                     //cin.getline(k_tno, sizeof(k_tno));
	cout << "kullanici adi: " << endl; cin >> k_nickname;
	cout << "email: " << endl; cin >> k_mail;
	cout << "adres: " << endl; cin >> k_adres;
	cout << "sifre: " << endl; 
	string sifre;
	int ch;
	ch = _getch();
	while (ch != 13)
	{
		sifre.push_back(ch);
		cout << '*';
		ch = _getch();
	}
    cout << endl;

	char* _sfr = new char[sifre.length() + 1];
	strcpy_s(_sfr, sifre.size() + 1, sifre.c_str());
	

	cout << "\nDogum Tarihi(gg/aa/yyyy formatinda giriniz): " << endl; cin >>dt;

  kullanici nesne(k_ad, k_tno,k_nickname,k_mail,k_adres,_sfr,"NULL", dt);
	
   

}
int yoneticiGiris()
{
	const int LINE = 20;
	const int SIZE = 8;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
	}
	
	string sifre="";
	string adSoyad = "";
	int bayrak1 = 0,bayrak2=0;
	int line ;

	cout << "Ad-Soyad :"; cin >> adSoyad; cout << endl;
	cout << "Sifre :"; 
	int ch;
	ch = _getch();
	while (ch != 13)
	{
		sifre.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;

	for (int i = 0; i < LINE; i++)
	{
		if (sifre == veri[i][2])
		{
			line = i;
			bayrak1 = 1;
		
		}
		if (adSoyad == veri[i][0])
		{
			bayrak2 = 1;
		}
		if (bayrak1 != bayrak2)
		{
			break;
		}
	}
	if (bayrak1 == 1 && bayrak2==1)
	{
		cout << "Basarili Giris" << endl;
		
		string st = veri[line][0];
		const char* str = st.c_str();
		yonetici1.setAd_soyad(str);


		string st1 = veri[line][1];
		const char* str1 = st1.c_str();
		yonetici1.setTelno(str1);


		string st2 = veri[line][2];
		const char* str2 = st2.c_str();
		yonetici1.setSifre(str2);

		return 1;
	}
	else
	{
		return 0;
	}
	
}
int musteriGiris()
{
	const int LINE = 20;
	const int SIZE = 8;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
	}

	string name;
	string sifre;
	int bayrak1 = 0, bayrak2 = 0;
	int line;

	cout << "Kullanici Adi : ";  cin >> name; cout << endl;
	cout << "Þifre : ";  
	int ch;
	ch = _getch();
	while (ch != 13)
	{
		sifre.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;

	for (int i = 0; i < LINE; i++)
	{
		if (name == veri[i][2])
		{
			line = i;
			bayrak1 = 1;
		}
		if (sifre == veri[i][5])
		{
			bayrak2 = 1;
		}
		if (bayrak1 != bayrak2)
		{
			break;
		}

		
	}
	if (bayrak1 ==1 && bayrak2==1)
	{
		cout << "Basarili Giris"<<endl;

		string st = veri[line][0];
		const char* str = st.c_str();
		kullanici1.setAd_soyad(str);

		


		string st1 = veri[line][1];
		const char* str1 = st1.c_str();
		kullanici1.setTelno(str1);

		


		string st2 = veri[line][2];
		const char* str2 = st2.c_str();
		kullanici1.setKullanici_ad(str2);

	


		string st3 = veri[line][3];
		const char* str3 = st3.c_str();
		


		string st4 = veri[line][4];
		const char* str4 = st4.c_str();
		kullanici1.setAdres_ilce(str4);

		

		string st5 = veri[line][5];
		const char* str5 = st5.c_str();
		
		

		
		string st6 = veri[line][6];
		const char* str6 = st6.c_str();
		kullanici1.setKupon(str6);

		
		string st7 = veri[line][7];
		const char* str7 = st7.c_str();

		kullanici1.setMusteri(str3, str5,str7);

	
		
		return 1;
	}
	else
	{
		return 0;
	}
	

}
void printOneri()
{
	ifstream dosyaOku("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\oneri.txt");


	string satir = "";

	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			cout << satir << endl;
		}

		dosyaOku.close();
	
	}
	

}
void OneriYaz()
{
	string oneri ;
	cout << "sikayet/oneri yaziniz:" <<endl;
	getline(cin, oneri); //burayý atlýyor??
	cout <<"yazdiginiz oneri:" << oneri;

	/*char oneri[1000];
	cout << "sikayet/oneri yaziniz: ";
	gets(oneri);*/

	


	ofstream DosyaYazma("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\oneri.txt", ios::out | ios::app);
	DosyaYazma <<oneri ;
	DosyaYazma.close();

}

void sifreDegistirme()
{
	cout << "Lutfen sifre degisikligi icin eposta adresinizi dogrulayin" << endl;
	cout << "Eposta adresinini giriniz:" << endl;
	string eposta = "";
	cin >> eposta;


	const int LINE = 20;
	const int SIZE = 8;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());

	if (inFile.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				inFile >> veri[i][j];
			}

		}

		inFile.close();
	}
	else { //Error message
		cerr << "DOSYA BULUNAMADI!" << inFileName << endl;
	}

	int kontrol1 = 0;
	int line = 0;

	for (int i = 0; i < LINE; i++)
	{
		if (eposta == veri[i][3])
		{
			line = i;
			kontrol1 = 1;
		}
	}
	if (kontrol1 != 1)
	{
		cout << "Epostanizi kontrol ediniz!" << endl;
	}


	if (kontrol1 == 1) {
		cout << "Yeni sifrenizi giriniz: " << endl;
		string yeniSifre = "";
		cin >> yeniSifre;

		veri[line][5] = yeniSifre;
	}

	ofstream DosyaYazma("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar1.txt");
	if (DosyaYazma.is_open())
	{
		for (int i = 0; i < LINE; i++)
		{
			for (int j = 0; j < SIZE; j++) {
				DosyaYazma << veri[i][j] << " ";
			}
			DosyaYazma << endl;
		}
	}

	DosyaYazma.close();

	cout << "sifreniz basariyla degistirildi."<<endl;

	remove("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt");
	rename("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar1.txt", "C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kullanicilar.txt");

}

void urunGirisi()
{
	
	cout << "Eklemek istediginiz urunu giriniz :";
	string urun;
	cin >> urun;
	double fiyat;
	cout << "\nUrunun fiyatini yaziniz :";
	cin >> fiyat;

	ofstream yazmaDosyasi("C:\\Users\\zeyne\\OneDrive\\Masaüstü\\kategori.txt", ios::out | ios::app);
	yazmaDosyasi <<urun<<" "<<fiyat<<" TL" << endl;

	
	yazmaDosyasi.close();

}




