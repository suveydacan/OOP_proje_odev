#include <iostream>
#include <locale.h> //türkçe karakter kullanmak için ekledik.
#include "kisi.h"
#include "yonetici.h"
#include "kullanici.h"
#include <string>
#include <fstream>
 

using namespace std;

void uyeKaydýFormu();
int yoneticiGiris();
int musteriGiris();
void printOneri();
void OneriYaz();
void sifreDegistirme();


int main()
{
	setlocale(LC_ALL, "Turkish");
	

	cout << "1. sisteme giriþ" << endl << "2. üye kaydý" << endl<< "3.çýkýþ" << endl;

	int number;
	cin >> number;
	switch (number) {
	case 1:
		cout << "1. yönetici giriþi" << endl << "2. müþteri giriþi" << endl << "3.Geri" << endl;
		int num;
		cin >> num;
		switch (num) {
			case 1:
			{
				int n = yoneticiGiris();
				switch (n) {
				case 0:
				{
					cout << "Kullanýcý adý veya þifre hatalý.Tekrar Deneyiniz!" << endl;
					yoneticiGiris();
					break;
				}
				case 1:
					cout << "1.Ürün giriþi" << endl << "2.Kurye ekle" << endl << "3.Þikayet ve Öneri" << endl 
						<< "4.Ýndirim kodu tanýmla" << endl << "5.Faturalarý görüntüle" << endl;
					int num;
					cin >> num;
					switch (num){
					case 1:
						break;
					case 2:
						break;
					case 3:
						printOneri();
						break;
					case 4:
						break;
					case 5:
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
			case 2:
			{
				int n=musteriGiris();
				switch(n){
				case 0:
				{
					cout << "Kullanýcý adý veya þifre hatalý.Tekrar Deneyiniz!" << endl;
					musteriGiris();
					break;
				}
				case 1:
					cout << "1.Kýyafet kategorisi ve ürün seçimi" << endl << "2.Sipariþ Takip" << endl << "3.Þikayet/Öneri" << endl
						<< "4.Þifre deðiþtir" << endl << "5.Geri dön" << endl;
					int num;
					cin >> num;
					switch (num){
					case 1:
						break;
					case 2:
						break;
					case 3:
						OneriYaz();
						break;
					case 4:
						sifreDegistirme();
						break;
					case 5:
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
				exit(1);
                break; //koddan çýkýþ yapýlýyor ama bir önceki menüye dönmesi gerek.
			
		}
		break;
	case 2:
		uyeKaydýFormu();
		break;
	
	case 3:
		exit(1);
		break;
	default:
		break;

	}

	
	
}
void uyeKaydýFormu()
{
	char* k_ad=new char[15];
	char* k_tno=new char[15];
	char* k_nickname=new char[15];
	char* k_mail = new char[15];
	char* k_adres = new char[15];
	char* sfr = new char[15];
	char* kpn = new char[15];
	char* dt = new char[15];

	

	cout << "üye kaydý için bilgileri giriniz: "<<endl;
	cout << "ad-soyad: " << endl;  cin >> k_ad;
	cout << "telno: " << endl;  cin >> k_tno;                                     //cin.getline(k_tno, sizeof(k_tno));
	cout << "kullanýcý adý: " << endl; cin >> k_nickname;
	cout << "email: " << endl; cin >> k_mail;
	cout << "adres: " << endl; cin >> k_adres;
	cout << "þifre: " << endl; cin >> sfr;
	cout << "doðum tarihi(gg/aa/yyyy formatýnda giriniz): " << endl; cin >>dt;

  kullanici nesne(k_ad, k_tno,k_nickname,k_mail,k_adres,sfr,"0", dt);
	
   

}
int yoneticiGiris()
{
	const int LINE = 20;
	const int SIZE = 7;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\suvey\\OneDrive\\Masaüstü\\kullanýcýlar.txt";
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

	cout << "Ad-Soyad :"; cin >> adSoyad; cout << endl;
	cout << "Þifre :"; cin >> sifre; 

	for (int i = 0; i < LINE; i++)
	{
		if (sifre == veri[i][2])
		{
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
		cout << "Baþarýlý Giriþ" << endl;
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
	const int SIZE = 7;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\suvey\\OneDrive\\Masaüstü\\kullanýcýlar.txt";
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

	cout << "Kullanýcý Adý : ";  cin >> name; cout << endl;
	cout << "Þifre : ";  cin >> sifre;

	for (int i = 0; i < LINE; i++)
	{
		if (name == veri[i][2])
		{
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
		cout << "Baþarýlý Giriþ"<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
	

}
void printOneri()
{
	ifstream dosyaOku("C:\\Users\\suvey\\OneDrive\\Masaüstü\\öneri.txt");


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
	string oneri = "";
	cout << "þikayet/öneri yazýnýz:" <<endl;
	getline(cin, oneri); //burayý atlýyor??
	cout <<"yazdýðýnýz öneri:" << oneri;


	ofstream DosyaYazma("C:\\Users\\suvey\\OneDrive\\Masaüstü\\öneri.txt", ios::out | ios::app);
	DosyaYazma <<oneri ;
	DosyaYazma.close();

}

void sifreDegistirme()
{
	cout << "Lütfen þifre deðiþikliði için eposta adresinizi doðrulayýn"<<endl;
	cout << "Eposta adresinini giriniz:"<<endl;
	string eposta = "";
	cin >> eposta;
	

	const int LINE = 20;
	const int SIZE = 7;
	string veri[LINE][SIZE];


	string inFileName = "C:\\Users\\suvey\\OneDrive\\Masaüstü\\kullanýcýlar.txt";
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
	int line=0;

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
		cout << "Epostanýzý kontrol ediniz!" << endl;
	}

	

	cout << "Yeni þifrenizi giriniz: "<<endl;
	string yeniSifre = "";
	cin >> yeniSifre;
	
	veri[line][5] = yeniSifre;

}









