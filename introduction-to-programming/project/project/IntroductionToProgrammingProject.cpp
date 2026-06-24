/****************************************************************
*                    SAKARYA ÜNİVERSİTESİ                       *
*              BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ        *
*                 BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ                *
*                           PROJE                               *
*                                                               *
*AD..............:RÜMEYSA                                       *
*SOYAD...........:CERAN                                         *                                        *
*****************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;
//Mekan sınıfı kalıtım için
class Mekan{
public:
	int blokNo;
	int kisi_sayisi;
	Mekan() :blokNo(0), kisi_sayisi(0)
	{}

	// kişi syaısını arttırma fonksiyonu
	void kisiEkle()
	{
		kisi_sayisi++;
	}	
};

//Havuz Sınıfı 
class Havuz :public Mekan {
public:
	Havuz():Mekan()
	{}

	void KisiEkle()
	{
		Mekan::kisiEkle();
	}
};

class Fitness :public Mekan {
public:
	Fitness():Mekan()
	{}

	void KisiEkle()
	{
		Mekan::kisiEkle();
	}

};

//Daire sınıfı
class Daire :public Mekan {
public:
	int daireNo;
	int daireninHavuzBorcu;
	int daireninFitnessBorcu;

	Daire():Mekan(),daireNo(0),daireninHavuzBorcu(0),daireninFitnessBorcu(0)
	{}

	//Havzu borcunu hesaplama fonksiyonu
	void havuzBorcunuArttir()
	{
		daireninHavuzBorcu++;
	}

	//fitness borcunu arttırma fonksiyonu 
	void fitnessBorcunuArttir()
	{
		daireninFitnessBorcu++;
	}

	//Kişi sayma fonksiyonu
	void kisiEkle()
	{
		Mekan::kisiEkle();
	}

};

//oturan sınıfı kalıtım için
class Oturan {
public:
	string isim;
	string soyisim;
	int blokNo;
	int daireNo;

	Oturan() :isim(), soyisim(), blokNo(0), daireNo(0)
	{}

	//Kullanıcıdan bilgileri alma fonksiyonu
	void KisiBilgileriAl()
	{
		cout << "\n İsim....:"; cin >> isim;
		cout << "\n Soyisim.:"; cin >> soyisim;
		cout << "\n Blok No.:"; cin >> blokNo;
		cout << "\n Daire No:"; cin >> daireNo;
	}

	void OturanYazdir();

};

//Bilgileri yazdırma fonksiyonu
void Oturan::OturanYazdir()
{
	cout << setw(5) << isim << setw(5) << soyisim << setw(5) << blokNo << setw(5) << daireNo << endl;
}

//Site sakini olanların sınıfı
class AileReisi :public Oturan {
public:
	string grup = "site-sakini";
	string havuz_kullanimi;
	string fitness_kullanimi;

	AileReisi() :Oturan(), havuz_kullanimi(), fitness_kullanimi()
	{}

	// kullanıcıdan bilgileri alma fonksiyonu
	void KisiBilgileriAl()
	{
		Oturan::KisiBilgileriAl();
	}

	// bilgileri yazdırma fonksiyonu
	void yazdir()
	{
		cout << setw(5) << grup; Oturan::OturanYazdir();
	}
};


//Misafir olanların sınıfı
class Misafir :public Oturan {
public:
	string grup = "misafir";
	string havuz_kullanimi;
	string fitness_kullanimi;

	Misafir() :Oturan(), havuz_kullanimi(), fitness_kullanimi()
	{}

	//Misafir bilgilerini alma fonksiyonu
	void KisiBilgileriAl()
	{
		Oturan::KisiBilgileriAl();
	}

	//Bilgileri yazdırma fonksiyonu
	void yazdir()
	{
		cout << setw(5) << grup; Oturan::OturanYazdir();
	}
};



//Misafir olup havuzu kullananların sayısını hesaplayan fonksiyon
void MisafirHavuzKullananSayisi(int* ptr2, int* ptr)
{
	
	ofstream MekanYaz("mekan.tmp");
	ifstream MekanOku("mekan.txt");

	//Mekan dosyası sonuna gelip gelmediğini kontrol etme
	for(int i = 0 ; i< *ptr2; i++)
	{
		Mekan bina;
		Havuz havuz;
		Fitness fitness;
		
		//fitness salonu kişi sayısına kadar okuma
		MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
		//Mekan.tmp ye bina bilgilerini yazdırma
		MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " ";
		//Aynı satırın devamında bulunan daire bilgilerini yazdırmak için daire sayısı kadra döngü oluşturrma
		for (int j = 0; j < *ptr; j++)
		{
			Daire daire;
			Misafir misafir;
			//daire bilgilerini dosyadan okuma
			MekanOku >> daire.daireNo >> daire.kisi_sayisi;

			//Havuz kullananların sayısını öğrenmek için havuzkul.txt okuma
			ifstream HavuzOku("havuzkul.txt");
			while (HavuzOku >> misafir.grup >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo >> misafir.havuz_kullanimi)
			{
				//Eğer kullandırıldı yazan kişi varsa havuz.kisisay fonksiyonu ile o havuzun kişi sayısını arttırma
				if (bina.blokNo == misafir.blokNo && daire.daireNo == misafir.daireNo && misafir.havuz_kullanimi == "kullandırıldı")
				{
					havuz.KisiEkle();
				}
			}
			HavuzOku.close();
			//Eğer ilk satırsa havuz ve fitness bilgileri dahil daire bilgilerini yazdırma
			if (i == 0)
			{
				MekanYaz << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " " << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
			//değilse sadece aynı satırın devamı olarak daire bilgilerini yazdırma
			else if (i == *ptr - 1)
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << endl;
			}			
			else
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
		}
		MekanYaz << endl;
	}
	MekanOku.close(); MekanYaz.close();remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");
}



//Misafir olup fitness kullananların sayısını hesaplayan fonksiyon
void MisafirFitnessKullananSayisi(int* ptr2, int* ptr)
{
	ofstream MekanYaz("mekan.tmp");
	ifstream MekanOku("mekan.txt");
	
	 for(int i = 0; i< *ptr2; i++ )
	 {
		Mekan bina;
		Havuz havuz;
		Fitness fitness;

		//Fitness salonu kişi sayısına kadar okuma
		MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
		//Fitness salonu bilgilerine kadar yazdırma çünkü fitness bilgileri değişecek
		MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " ";
		//Satırın devamı için daire sayısı kadar döngü oluşturma
		for (int j = 0; j < *ptr; j++)
		{
			Misafir misafir;
			Daire daire;
			//fitnessa gidenlerin bilgilerini okuma
			ifstream FitnessOku("fitnesskul.txt");
			// sırasıyla daireleri okuma
			MekanOku >> daire.daireNo >> daire.kisi_sayisi;
			while (FitnessOku >> misafir.grup >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo >> misafir.fitness_kullanimi)
			{
				//fitness kullanımında kullandırıldı yazıyorsa o salonun kişi sayısını arttırma
				
				if (bina.blokNo == misafir.blokNo && daire.daireNo == misafir.daireNo && misafir.fitness_kullanimi == "kullandırıldı")
					fitness.kisiEkle();
			}
			FitnessOku.close();
			//Satır başındaysa fitness bilgileri dahil daire bilgilerini yazdırıyor
			if (i == 0) 
			{
				MekanYaz << fitness.blokNo << " " << fitness.kisi_sayisi << " " << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
			//değilse sadece daire bilgilerinin ekliyor
			else if (i == *ptr - 1)
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << endl;
			}
			else
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
		}		
		MekanYaz << endl;	
	}
	MekanOku.close(); MekanYaz.close(); remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");

}


void SiteSakiniKisiSayisi(int* ptr2,int* ptr)
{
	ofstream MekanYaz("mekan.tmp");
	ifstream MekanOku("mekan.txt");


	for(int i = 0; i < *ptr2 ; i++)
	{
		Mekan bina;
		Havuz havuz;
		Fitness fitness;
		MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
		for (int j = 0; j < *ptr; j++)
		{
			AileReisi site_sakini;
			Daire daire;
			ifstream KisiOku("data.txt");
			MekanOku >> daire.daireNo >> daire.kisi_sayisi;
			while (KisiOku >> site_sakini.grup >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo)
			{
				if (bina.blokNo == site_sakini.blokNo && daire.daireNo == site_sakini.daireNo)
					daire.kisiEkle(); bina.kisiEkle();					
			}
			KisiOku.close();
			if (j == 0)
			{
				MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " ";
			}
			else if (j == *ptr - 1)
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << endl;
			}
			else
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
			daire.kisi_sayisi = 0;
		}
		bina.kisi_sayisi = 0;
	}
	MekanYaz.close(); MekanOku.close(); remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");
}

void MisafirKisiSayisi(int* ptr2 ,int* ptr)
{
	ofstream MekanYaz("mekan.tmp");
	ifstream MekanOku("mekan.txt");
	for(int i = 0; i < *ptr2 ; i++)
	{
		Mekan bina;
		Havuz havuz;
		Fitness fitness;
		MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
		MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " ";
		for (int j = 0; j < *ptr; j++)
		{
			Misafir misafir;
			Daire daire;
			ifstream KisiOku("data.txt");
			MekanOku >> daire.daireNo >> daire.kisi_sayisi;
			while (KisiOku >> misafir.grup >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo)
			{
				if (bina.blokNo == misafir.blokNo && daire.daireNo == misafir.daireNo)
					daire.kisiEkle(); bina.kisiEkle();
			}
			KisiOku.close();
			if (j == 0)
			{
				MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " ";
			}
			else if (j == *ptr - 1)
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << endl;
			}
			else
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
			daire.kisi_sayisi = 0;
		}
		bina.kisi_sayisi = 0;
	}
	MekanYaz.close(); MekanOku.close(); remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");
}

void SiteSakiniHavuzKullananSayisi(int* ptr2,int* ptr) 
{
	ofstream MekanYaz("mekan.tmp");
	ifstream MekanOku("mekan.txt");

	
	for(int i=0 ; i<*ptr2; i++)
	{
		Mekan bina;
		Havuz havuz;
		Fitness fitness;

		MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " ";
		for(int j = 0; j < *ptr ; j++)
		{
			Daire daire;
			ifstream HavuzOku("havuzkul.txt");
			AileReisi site_sakini;
			MekanOku >> daire.daireNo >> daire.kisi_sayisi;
			while (HavuzOku >> site_sakini.grup >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo >> site_sakini.havuz_kullanimi)
			{				
				if (bina.blokNo == site_sakini.blokNo && site_sakini.daireNo == daire.daireNo && site_sakini.havuz_kullanimi == "kullandırıldı")
					havuz.KisiEkle();
			}
			HavuzOku.close();
			if (j == 0)
			{
				MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " " << daire.daireNo << " " << daire.kisi_sayisi << " ";
				
			}
			else if (j == (*ptr - 1))
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << endl;
			}
			else 
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
		}
		MekanYaz << endl;
	}
	MekanOku.close(); MekanYaz.close(); remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");
}

void SiteSakiniFitnessKullananSayisi(int* ptr2 ,int* ptr)
{
	ofstream MekanYaz("mekan.tmp");
	ifstream MekanOku("mekan.txt");
	
	for ( int i = 0; i< *ptr2 ; i++)
	{
		Mekan bina;
		Havuz havuz;
		Fitness fitness;

		MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
		MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " ";
		for (int j = 0; j < *ptr; j++)
		{
			Daire daire;
			AileReisi site_sakini;
			ifstream FitnessOku("fitnesskul.txt");
			MekanOku >> daire.daireNo >> daire.kisi_sayisi;
			while (FitnessOku >> site_sakini.grup >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo >> site_sakini.fitness_kullanimi)
			{
				
				if (bina.blokNo == site_sakini.blokNo && daire.daireNo == site_sakini.daireNo && site_sakini.fitness_kullanimi == "kullandırıldı")
					fitness.kisiEkle();
			}
			FitnessOku.close();
			if (j == 0) 
			{
				MekanYaz <<  bina.blokNo <<" " << bina.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " " << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
			else if (j == (*ptr-1))
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << endl;
			}
			
			else 
			{
				MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
			}
		}
		MekanYaz << endl;		
	}
	MekanOku.close(); MekanYaz.close(); remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");
}


void SiteSakiniBilgileriDosyayaYaz()
{
	ofstream SiteSakiniYaz;
	SiteSakiniYaz.open("data.txt", ios::app);
	
	AileReisi site_sakini;
	site_sakini.KisiBilgileriAl();
	SiteSakiniYaz << site_sakini.grup << " " << site_sakini.isim << " " << site_sakini.soyisim << " " << site_sakini.blokNo << " " << site_sakini.daireNo << endl;
	
	SiteSakiniYaz.close();
}

void SiteSakiniDosyadanBilgileriYazdir()
{
	ifstream SiteSakiniOku("data.txt");
	while (!(SiteSakiniOku.eof()))
	{
		AileReisi site_sakini;
		SiteSakiniOku >> site_sakini.grup >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo;
		site_sakini.yazdir();
	}
	SiteSakiniOku.close();
}

void MisafirBilgileriDosyayaYaz()
{
	ofstream MisafirYaz;
	MisafirYaz.open("data.txt", ios::app);
	Misafir misafir;
	misafir.KisiBilgileriAl();
	MisafirYaz << misafir.grup << " " << misafir.isim << " " << misafir.soyisim << " " << misafir.blokNo << " " << misafir.daireNo << endl;
	MisafirYaz.close();
}

void MisafirDosyadanBilgileriYazdir()
{
	ifstream MisafirOku("data.txt");
	while (!(MisafirOku.eof()))
	{
		Misafir misafir;
		MisafirOku >> misafir.grup >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo;
		misafir.yazdir();
	}
	MisafirOku.close();
}


int main()
{
	setlocale(LC_ALL, "Turkish");

	char program_devam = 'e';
	do 
	{	
		int secim;
		do
		{
			cout << "\n        - ANA MENU -            ";
			cout << "\n Hangi işlemi yapmak istersiniz?";
			cout << "\n 1-Mekan........................";
			cout << "\n 2-Odemeler.....................";
			cout << "\n 3-Kisiler......................";
			cin >> secim;
		
		} while (!(secim == 1 || secim == 2 || secim == 3));

		
		
		
		int daire_sayisi;
		int* ptr;
		ptr = &daire_sayisi;
		int blok_sayisi;
		int* ptr2;
		ptr2 = &blok_sayisi;

		if (secim == 1)
		{
			int secim1;
			do
			{
				cout << "\n            - MEKAN -           ";
				cout << "\n Hangi işlemi yapmak istersiniz?";
				cout << "\n 1-Ekleme.......................";
				cout << "\n 2-Silme........................";
				cout << "\n 3-Düzeltme......................";
				cout << "\n 4-Raporlama.....................";
				cin >> secim1;
			} while (!(secim1 == 1 || secim1 == 2 || secim1 == 3 || secim1 == 4));
			
			if (secim1 == 1)
			{
							
				cout << "Kaç blok olmasını istiyorsunuz...........?"; cin >> *ptr2;
				cout << "Bir blokta kaç daire olmasını istiyorsunuz?"; cin >> *ptr;

				ofstream MekanYaz("mekan.txt");
				ofstream OdemeYaz("odemeler.txt");
				for (int i = 0; i < blok_sayisi; i++)
				{
					Mekan bina;
					Havuz havuz;
					Fitness fitness;
					Daire daire;
					bina.blokNo = havuz.blokNo = fitness.blokNo = i+1;
					bina.kisi_sayisi = havuz.kisi_sayisi = fitness.kisi_sayisi = 0;
					
					MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " ";
					for (int j = 0; j < daire_sayisi; j++)
					{
						Daire daire;
						daire.blokNo = i+1; daire.daireNo = j + 1;
						daire.daireninHavuzBorcu = 0; daire.daireninFitnessBorcu;
						OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
						MekanYaz << daire.daireNo << " " << daire.kisi_sayisi << " ";
					}
					MekanYaz << endl;
				}
				MekanYaz.close(); OdemeYaz.close();
			}

			else if (secim1 == 2)
			{
				int SilinecekBlokNo;

				cout << "\n Silinecek Blok No.....:"; cin >> SilinecekBlokNo;
			
				ifstream MekanOku("mekan.txt");ofstream MekanYaz("mekan.tmp");
				for (int i = 0; i < *ptr2; i++)
				{
					Mekan bina;
					Havuz havuz;
					Fitness fitness;
					
					MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
					for (int j = 0; j < *ptr; j++)
					{
						Daire daire;
						MekanOku >> daire.daireNo >> daire.kisi_sayisi;
						if (!(bina.blokNo == SilinecekBlokNo))
						{
							if (j == 0)
							{
								MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " " << daire.daireNo << " " << daire.kisi_sayisi;
							}
							else if ( j == *ptr -1)
							{
								MekanYaz << " " << daire.daireNo << " " << daire.kisi_sayisi << endl;
							}
							else 
							{
								MekanYaz << " " << daire.daireNo << " " << daire.kisi_sayisi;

							}						
						}					
					}
				}
						
				MekanYaz.close(); MekanOku.close(); remove("mekan.txt"); rename("mekan.tmp", "mekan.txt");

				AileReisi site_sakini;
				Misafir misafir;
				string grup;
				ifstream KisiOku("data.txt"); ofstream KisiYaz("data.tmp");
				while (KisiOku >> grup)
				{
					if (grup == "misafir")
					{
						if (KisiOku >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo)
						{
							if (!(misafir.blokNo == SilinecekBlokNo))
							{
								KisiYaz << grup << " " << misafir.isim << " " << misafir.soyisim << " " << misafir.blokNo << " " << misafir.daireNo << endl;
							}
						}
					}
					else
					{
						if(KisiOku >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo)
						{
							if (!(site_sakini.blokNo == SilinecekBlokNo))
							{
								KisiYaz << grup << " " << site_sakini.isim << " " << site_sakini.soyisim << " " << site_sakini.blokNo << " " << site_sakini.daireNo << endl;
							}
						}
						}
				}KisiOku.close(); KisiYaz.close(); remove("data.txt"); rename("data.tmp", " data.txt");

			}

			else if (secim1 == 3)
			{

				int DuzeltmeYapilacakBlok;
				int DuzeltmeYapilacakDaire;
				int EksiltilecekKisiSayisi;

				cout << "Kişi sayısında düzeltme yapılacak blok No:"; cin >> DuzeltmeYapilacakBlok;
				cout << "Kişi sayısında düzeltme yapılacak daire No:"; cin >> DuzeltmeYapilacakDaire;
				cout << "Eksiltme yapılacak kişi sayısı............:"; cin >> EksiltilecekKisiSayisi;
				Mekan bina; Daire daire; Havuz havuz; Fitness fitness;

				ifstream MekanOku("mekan.txt"); ofstream MekanYaz("mekan.tmp"); 
				for(int j = 0; j<*ptr2 ; j++)
				{
					Mekan bina;Havuz havuz; Fitness fitness;
					MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;
					for (int i = 0; i < *ptr; i++)
					{

						Daire daire;
						MekanOku >> daire.daireNo >> daire.kisi_sayisi;							
						if (bina.blokNo == DuzeltmeYapilacakBlok && daire.daireNo == DuzeltmeYapilacakDaire)
						{
							cout << setw(10) << "Blok No" << setw(10) << "Daire No" << setw(10) << "Kişi Sayısı" << endl;
							cout << setw(10) << bina.blokNo << setw(10) << daire.daireNo << setw(10) << daire.kisi_sayisi << endl;
							if (EksiltilecekKisiSayisi >= daire.kisi_sayisi)
							{
								daire.kisi_sayisi = 0;
							}
							else 
							{
								daire.kisi_sayisi -= EksiltilecekKisiSayisi;
								bina.kisi_sayisi -= EksiltilecekKisiSayisi;
							}
							string grup;
							AileReisi site_sakini;
							Misafir misafir;
							int sayim = EksiltilecekKisiSayisi;
							ifstream KisiOku("data.txt"); ofstream KisiYaz("data.tmp");
							while (!KisiOku.eof())
							{
								KisiOku >> grup;
								if (grup == "misafir")
								{
									KisiOku >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo;
									if (misafir.daireNo == daire.daireNo && misafir.blokNo == bina.blokNo)
									{
										sayim--;
										if (sayim <= 0)
											KisiYaz << grup << " " << misafir.isim << " " << misafir.soyisim << " " << misafir.blokNo << " " << misafir.daireNo << endl;
									}
									else
									{
										KisiYaz << grup << " " << misafir.isim << " " << misafir.soyisim << " " << misafir.blokNo << " " << misafir.daireNo << endl;
									}

								}
								else
								{
									KisiOku >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo;
									if (site_sakini.daireNo == daire.daireNo && site_sakini.blokNo == bina.blokNo)
									{
										sayim--;
										if (sayim <= 0)
											KisiYaz << grup << " " << site_sakini.isim << " " << site_sakini.soyisim << " " << site_sakini.blokNo << " " << site_sakini.daireNo << endl;

									}
									else
									{
										KisiYaz << grup << " " << site_sakini.isim << " " << site_sakini.soyisim << " " << site_sakini.blokNo << " " << site_sakini.daireNo << endl;
									}
								}							
						}KisiOku.close(); KisiYaz.close(); remove("data.txt"); rename("data.tmp", "data.txt");
						if (i == 0)
							MekanYaz << bina.blokNo << " " << bina.kisi_sayisi << " " << havuz.blokNo << " " << havuz.kisi_sayisi << " " << fitness.blokNo << " " << fitness.kisi_sayisi << " " << daire.daireNo << " " << daire.kisi_sayisi;
						else if (i == *ptr - 1)
						{
							MekanYaz << " " << daire.daireNo << " " << daire.kisi_sayisi << endl;
						}
						else 
						{
							MekanYaz << " " << daire.daireNo << " " << daire.kisi_sayisi << " ";
						}
							
						}
					}									
				}MekanYaz.close(); MekanOku.close(); remove("mekan.tmp"); rename("mekan.tmp", "mekan.txt");
			}

			else if (secim1 == 4)
			{
				ifstream MekanOku("mekan.txt");

				Mekan bina;
				Havuz havuz;
				Fitness fitness;

				for (int j = 0; j < *ptr2; j++)
				{
					Mekan bina;
					Havuz havuz;
					Fitness fitness;

					MekanOku >> bina.blokNo >> bina.kisi_sayisi >> havuz.blokNo >> havuz.kisi_sayisi >> fitness.blokNo >> fitness.kisi_sayisi;

					cout << "\n Blok No..............:" << bina.blokNo;
					cout << "\n Blok kişi sayısı.....:" << bina.kisi_sayisi;
					cout << "\n Havuz No.............:" << havuz.blokNo;
					cout << "\n Havuz kişi sayısı....:" << havuz.kisi_sayisi;
					cout << "\n Fitness No...........:" << fitness.blokNo;
					cout << "\n Fitness kisi sayısı..:" << fitness.kisi_sayisi;

					for (int i = 0; i < *ptr; i++)
					{
						Daire daire;
						MekanOku >> daire.daireNo >> daire.kisi_sayisi;
						cout << "\n Daire No.............:" << daire.daireNo;
						cout << "\n Daire kişi sayısı....:" << daire.kisi_sayisi;
					}
					cout << endl << endl;


				}
				MekanOku.close();
			}		
		}

		else if (secim == 2)
		{
			int secim2;
			do
			{
				cout << "\n        - ODEMELER -              ";
				cout << "\n Hangi işlemi yapmak istiyorsunuz?";
				cout << "\n 1-Ödeme..........................";
				cout << "\n 2-Ekle...........................";
				cout << "\n 3-Sil............................";
				cout << "\n 4-Düzelt.........................";
				cout << "\n 5-Raporlama......................";
				cin >> secim2;
			} while (!(secim2 == 1 || secim2 == 2 || secim2 == 3 || secim2 == 4|| secim2==5));
			if (secim2 == 1)
			{
				int ArananBinaNo;
				int ArananDaireNo;

				cout << "Blok No..........:"; cin >> ArananBinaNo;
				cout << "Daire No.........:"; cin >> ArananDaireNo;

				Daire daire;

				ifstream OdemeOku("odemeler.txt");
				ofstream OdemeYaz("odemeler.tmp");

				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
					
					if (daire.blokNo == ArananBinaNo && daire.daireNo == ArananDaireNo)
					{
						int borc;
						cout << setw(10) << "Blok No" << setw(10) << "Daire No" << setw(10) << "Havuz Borcu" << setw(10) << "Fitness Borcu" << endl;
						cout << setw(10) << daire.blokNo << setw(10) << daire.daireNo << setw(10) << daire.daireninHavuzBorcu << setw(10) << daire.daireninFitnessBorcu << endl;
						do 
						{
							cout << "\n 1-Havuz Borcu..........................";
							cout << "\n 2-Fitness Borcu........................";
							cout << "\n Hangi türde borcunuzu ödemek istersiniz"; cin >> borc;
						} while (!(borc == 1 || borc == 2));

						if (borc == 1 && daire.daireninHavuzBorcu != 0)
						{
							daire.daireninHavuzBorcu = 0;
						}
						else if (borc == 1 && daire.daireninHavuzBorcu == 0)
						{
							cout << "Ödeme yapamazsınız çünkü havuza ait borcunuz bulunmamaktadır." << endl;
						}
						else if (borc == 2 && daire.daireninFitnessBorcu != 0)
						{
							daire.daireninFitnessBorcu = 0;
						}
						else if (borc == 2 && daire.daireninFitnessBorcu == 0)
						{
							cout << "Ödeme yapamazsınız çünkü fitness salonuna ait borcunuz bulunmamaktadır." << endl;
						}
					}
					OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
				}
				OdemeOku.close(); OdemeYaz.close(); remove("odemeler.txt"); rename("odemeler.tmp", "odemeler.txt");
			}

			else if (secim2 == 2)
			{
				int EklenecekBinaNo;
				int EklenecekDaireNo;
				int EklenecekHavuzBorcu;
				int EklenecekFitnessBorcu;

				cout << "\n Blok No................:"; cin >> EklenecekBinaNo;
				cout << "\n Daire No...............:"; cin >> EklenecekDaireNo;
				cout << "\n Eklenecek Havuz Borcu..:"; cin >> EklenecekHavuzBorcu;
				cout << "\n Eklenecek Fitness Borcu:"; cin >> EklenecekFitnessBorcu;

				Daire daire;

				ifstream OdemeOku;
				OdemeOku.open("odemeler.txt");
				ofstream OdemeYaz;
				OdemeYaz.open("odemeler.tmp");

				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
					

					if (EklenecekBinaNo == daire.blokNo && EklenecekDaireNo == daire.daireNo)
					{
						cout << setw(10) << "Blok No" << setw(10) << "Daire No" << setw(10) << "Havuz Borcu" << setw(10) << "Fitness Borcu"<<endl;
						cout << setw(10) << daire.blokNo << setw(10) << daire.daireNo << setw(10) << daire.daireninHavuzBorcu << setw(10) << daire.daireninFitnessBorcu<<endl;
						daire.daireninHavuzBorcu += EklenecekHavuzBorcu; 
						daire.daireninFitnessBorcu += EklenecekFitnessBorcu;
					}
					OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
				}
				OdemeYaz.close(); OdemeOku.close(); remove("odemeler.txt"); rename("odemeler.tmp", "odemeler.txt");
			}


			
			else if (secim2 == 3)
			{
				int SilinecekBinaNo;
				int SilinecekDaireNo;

				cout << "\n Silinecek Blok No..........:"; cin >> SilinecekBinaNo;
				cout << "\n Silinecek Daire No.........:"; cin >> SilinecekDaireNo;

				Daire daire;

				ifstream OdemeOku("odemeler.txt"); ofstream OdemeYaz("odemeler.tmp");

				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
					
					if (!(SilinecekBinaNo == daire.blokNo && SilinecekDaireNo == daire.daireNo))
					{
						OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu<<endl;
					}
					else
					{
						daire.daireninFitnessBorcu = 0;
						daire.daireninHavuzBorcu = 0;
						OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
					}
				}OdemeOku.close(); OdemeYaz.close(); remove("odemeler.txt"); rename("odemeler.tmp", "odemeler.txt");
			}
			else if (secim2 == 4)
			{
				int GuncellenecekBinaNo;
				int GuncellenecekDaireNo;
				int GuncellenecekHavuzBorcu;
				int GuncellenecekFitnessBorcu;

				cout << "\n Güncellemecek Blok No.....:"; cin >> GuncellenecekBinaNo;
				cout << "\n Güncellenecek Daire No....:"; cin >> GuncellenecekDaireNo;
				cout << "\n Guncellenecek Havuz Borcu..:"; cin >> GuncellenecekHavuzBorcu;
				cout << "\n Guncellenecek Fitness Borcu:"; cin >> GuncellenecekFitnessBorcu;

				Daire daire;
				ifstream OdemeOku("odemeler.txt");
				ofstream OdemeYaz("odemeler.tmp");

				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
					
					if (GuncellenecekBinaNo == daire.blokNo && GuncellenecekDaireNo == daire.daireNo)
					{
						daire.daireninHavuzBorcu = GuncellenecekHavuzBorcu;
						daire.daireninFitnessBorcu = GuncellenecekFitnessBorcu;
					}
					OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
				}
				OdemeOku.close(); OdemeYaz.close(); remove("odemeler.txt"); rename("odemeler.tmp", "odemeler.txt");
			}
		
			else if (secim2 == 5)
			{
				Daire daire;

				ifstream OdemeOku("odemeler.txt");

				cout << setw(10) << "BlokNo" << setw(10) << "Daire No" << setw(10) << "Havuz Borcu" << setw(10) << "Fitness Borcu" << endl;
				cout << setw(10) << "-------" << setw(10) << "---------" << setw(10) << "----------" << setw(10) << "-------------" << endl;
				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
					cout << setw(10) << daire.blokNo << setw(10) << daire.daireNo << setw(10) << daire.daireninHavuzBorcu << setw(10) << daire.daireninFitnessBorcu << endl;
				}
				OdemeOku.close();
			}
		}

		else if (secim == 3)
		{
			int secim3;
			do
			{
				cout << "\n           - KİSİLER -          ";
				cout << "\n Hangi işlemi yapmak istersiniz?";
				cout << "\n 1-Kayıt oluşturma..............";
				cout << "\n 2-Kayıt silme..................";
				cout << "\n 3-Kayıt güncelleme.............";
				cout << "\n 4-Raporlama....................";
				cout << "\n 5-Havuz kaydı oluşturma........";
				cout << "\n 6-Fitness kaydı oluşturma......";
				cin >> secim3;
			} while (!(secim3 == 1 || secim3 == 2 || secim3 == 3 || secim3 == 4 || secim3 == 5 || secim3 == 6 ));
			if (secim3 == 1)
			{
				int grup;
				int kisi_sayisi;
				cout << "Kaç kişi kaydedeceksiniz?"; cin >> kisi_sayisi;
				for (int i = 0; i < kisi_sayisi; i++)
				{
					do {
						cout << "1-Site sakini" << endl;
						cout << "2-Misafir...." << endl;
						cout << "Grup seçiniz"; cin >> grup;
						
					} while (!(grup==1 || grup==2));
					if (grup == 1) 
					{
						SiteSakiniBilgileriDosyayaYaz();
					}
					else 
					{
						MisafirBilgileriDosyayaYaz();
					}
				}
				
				
				SiteSakiniKisiSayisi(&blok_sayisi,&daire_sayisi);
				MisafirKisiSayisi(&blok_sayisi,&daire_sayisi);
			}
			else if (secim3 == 2)
			{
				int arananKisiBinasi;
				int arananKisiDairesi;
				string arananKisiGrubu;
				string arananKisiIsmi;
				string arananKisiSoyismi;

				cout << "silinecek kişi grubu(misafir/site-sakini):"; cin >> arananKisiGrubu;
				cout << "Silinecek kişi isim......................:"; cin >> arananKisiIsmi;
				cout << "Silinecek kişi soyisim...................:"; cin >> arananKisiSoyismi;
				cout << "Silinecek kişi daire do..................:"; cin >> arananKisiDairesi;
				cout << "Silinecek kişi bina no...................:"; cin >> arananKisiBinasi;

				string grup;
				ifstream KisiOku("data.txt"); ofstream KisiYaz("data.tmp");
				while (KisiOku >> grup)
				{
					if (arananKisiGrubu == "misafir")
					{
						Misafir misafir;
						KisiOku >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo;
						if (!(arananKisiIsmi == misafir.isim && arananKisiSoyismi == misafir.soyisim && misafir.blokNo == arananKisiBinasi && arananKisiDairesi == misafir.daireNo))
						{
							KisiYaz << grup << " " << misafir.isim << " " << misafir.soyisim << " " << misafir.blokNo << " " << misafir.daireNo << endl;
						}
					}
					else if(arananKisiGrubu == "site-sakini")
					{
						AileReisi site_sakini;
						KisiOku >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo;
						if (!( arananKisiDairesi == site_sakini.daireNo && arananKisiBinasi == site_sakini.blokNo && arananKisiIsmi == site_sakini.isim && arananKisiSoyismi == site_sakini.soyisim))
						{
							KisiYaz << grup << " " << site_sakini.isim << " " << site_sakini.soyisim << " " << site_sakini.blokNo << " " << site_sakini.daireNo << endl;
						}	
					}
				
				}
				KisiYaz.close(); KisiOku.close(); remove("data.txt"); rename("data.tmp", "data.txt");
				if (arananKisiGrubu == "misafir")
					MisafirKisiSayisi(&blok_sayisi,&daire_sayisi);
				else
				{
					SiteSakiniKisiSayisi(&blok_sayisi, &daire_sayisi);
				}
			}
			else if (secim3 == 3)
			{
				int arananKisiBinasi;
				int arananKisiDairesi;
				string arananKisiGrubu;
				string arananKisiIsmi;
				string arananKisiSoyismi;

				cout << "Güncellenecek kişi grubu(misafir/site-sakini):"; cin >> arananKisiGrubu;
				cout << "Güncellencek kişi isim..:"; cin >> arananKisiIsmi;
				cout << "Güncellenecek kişi soyismi:"; cin >> arananKisiSoyismi;
				cout << "Güncellenecek kişi daire no:"; cin >> arananKisiDairesi;
				cout << "Güncellenecek kişi bina no.:"; cin >> arananKisiBinasi;

				string grup;
				ifstream DosyaOku("data.txt");
				ofstream DosyaYaz("data.tmp");
				while (DosyaOku >> grup)
				{
					if (grup == "misafir")
					{
						Misafir misafir;
						DosyaOku >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo;
						if (arananKisiGrubu == grup && arananKisiIsmi == misafir.isim && arananKisiSoyismi == misafir.soyisim && arananKisiBinasi == misafir.blokNo && arananKisiDairesi == misafir.daireNo)
						{
							cout << "Güncellenmek istenen kişinin bilgileri" << endl;
							cout << setw(12) << "Grup" << setw(12) << "İsim" << setw(12) << "Soyisim" << setw(12) << "Blok No" << setw(12) << "Daire No" << endl;
							cout << setw(12) << grup << setw(12) << misafir.isim << setw(12) << misafir.soyisim << setw(12) << misafir.blokNo << setw(12) << misafir.daireNo;
							cout << "\n Güncel bilgileri giriniz.";
							cout << "\n Grup....:"; cin >> grup;
							cout << "\n İsim....:"; cin >> misafir.isim;
							cout << "\n Soyisim.:"; cin >> misafir.soyisim;
							cout << "\n Blok No.:"; cin >> misafir.blokNo;
							cout << "\n Daire No:"; cin >> misafir.daireNo;
						}
						DosyaYaz << grup << " " << misafir.isim << " " << misafir.soyisim << " " << misafir.blokNo << " " << misafir.daireNo << endl;
					}
					else if(grup == "site-sakini")
					{
						AileReisi site_sakini;
						DosyaOku >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo;
						if (arananKisiGrubu == grup && arananKisiIsmi == site_sakini.isim && arananKisiSoyismi == site_sakini.soyisim && arananKisiBinasi == site_sakini.blokNo && arananKisiDairesi == site_sakini.daireNo)
						{
							cout << "Güncellenmek istenen kişinin bilgileri" << endl;
							cout << setw(12) << "Grup" << setw(12) << "İsim" << setw(12) << "Soyisim" << setw(12) << "Blok No" << setw(12) << "Daire No" << endl;
							cout << setw(12) << grup << setw(12) << site_sakini.isim << setw(12) << site_sakini.soyisim << setw(12) << site_sakini.blokNo << setw(12) << site_sakini.daireNo;
							cout << "\n Güncel bilgileri giriniz.";
							cout << "\n Grup.....................:"; cin >> grup;
							cout << "\n İsim....................:"; cin >> site_sakini.isim;
							cout << "\n Soyisim.................:"; cin >> site_sakini.soyisim;
							cout << "\n Blok No.................:"; cin >> site_sakini.blokNo;
							cout << "\n Daire No................:"; cin >> site_sakini.daireNo;
						}
						DosyaYaz << grup << " " << site_sakini.isim << " " << site_sakini.soyisim << " " << site_sakini.blokNo << " " << site_sakini.daireNo << endl;
					}

				}DosyaOku.close(); DosyaYaz.close(); remove("data.txt"); rename("data.tmp", "data.txt");
				arananKisiGrubu == "misafir" ? MisafirKisiSayisi(&blok_sayisi,&daire_sayisi) : SiteSakiniKisiSayisi(&blok_sayisi,&daire_sayisi);
			}
			else if (secim3 == 4)
			{
				cout << setw(12) << "Grup" << setw(12) << "İsim" << setw(12) << "Soyisim" << setw(12) << "Blok No" << setw(12) << "Daire No" << endl;

				string grup;
				ifstream KisiOku("data.txt");
				while (KisiOku >> grup)
				{
					if (grup == "misafir")
					{
						Misafir misafir;
						KisiOku >> misafir.isim >> misafir.soyisim >> misafir.blokNo >> misafir.daireNo;
						cout << setw(12) << misafir.grup << setw(12) << misafir.isim << setw(12) << misafir.soyisim << setw(12) << misafir.blokNo << setw(12) << misafir.daireNo << endl;
					}
					else if(grup == "site-sakini")
					{
						AileReisi site_sakini;
						KisiOku >> site_sakini.isim >> site_sakini.soyisim >> site_sakini.blokNo >> site_sakini.daireNo;
						cout << setw(12) << site_sakini.grup << setw(12) << site_sakini.isim << setw(12) << site_sakini.soyisim << setw(12) << site_sakini.blokNo << setw(12) << site_sakini.daireNo << endl;
					}
					
				}KisiOku.close();
					
			}
			else if (secim3 == 5)
			{
				string arananKisiGrubu;
				string arananKisiIsim;
				string arananKisiSoyisim;
				int arananKisiBinasi;
				int arananKisiDairesi;
				
				cout << "\n Grup(site-sakini/misafir):"; cin >> arananKisiGrubu;
				cout << "\n İsim:"; cin >> arananKisiIsim;
				cout << "\n Soyisim:"; cin >> arananKisiSoyisim;
				cout << "\n Blok No:"; cin >> arananKisiBinasi;
				cout << "\n Daire No:"; cin >> arananKisiDairesi;

				ifstream OdemeOku("odemeler.txt");
				ofstream OdemeYaz("odemeler.tmp");
				ofstream HavuzYaz;
				HavuzYaz.open("havuzkul.txt", ios::app);

				
				Daire daire;
				
				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
				
								
					if (arananKisiGrubu == "site-sakini")
					{
						if (arananKisiBinasi == daire.blokNo && arananKisiDairesi == daire.daireNo && daire.daireninHavuzBorcu == 0)
						{
							HavuzYaz << arananKisiGrubu << " " << arananKisiIsim << " " << arananKisiSoyisim << " " << arananKisiBinasi << " " << arananKisiDairesi << " " << "kullandırıldı" << endl;
							cout << "Havuzu kullanabilirsiniz, dairenize ait borcunuz bulunmamaktadır." << endl;
							SiteSakiniHavuzKullananSayisi(&blok_sayisi,&daire_sayisi); daire.havuzBorcunuArttir();
							HavuzYaz.close();
						}
						else if ((arananKisiBinasi == daire.blokNo) && (arananKisiDairesi == daire.daireNo) && (daire.daireninHavuzBorcu != 0))
						{
							HavuzYaz << arananKisiGrubu << " " << arananKisiIsim << " " << arananKisiSoyisim << " " << arananKisiBinasi << " " << arananKisiDairesi << " " << "kullandırılmadı" << endl;
							cout << "Havuzu kullanamazsınız, dairenize ait borcunuz bulunmaktadır. Ödemeler menüsünden ödemenizi yapmanız gerekmektedir." << endl;
							HavuzYaz.close();
						}
					
					}
					else if("misafir")
					{
						HavuzYaz << arananKisiGrubu << " " << arananKisiIsim << " " << arananKisiSoyisim << " " << arananKisiBinasi << " " << arananKisiDairesi << " " << "kullandırıldı" << endl;
						MisafirHavuzKullananSayisi(&blok_sayisi,&daire_sayisi);
						if (daire.blokNo == arananKisiBinasi && daire.daireNo == arananKisiDairesi)
						{
							daire.havuzBorcunuArttir();
							HavuzYaz.close();
							
						}
					}OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
					
					

				}OdemeOku.close(); OdemeYaz.close(); remove("odemeler.txt"); rename("odemeler.tmp", "odemeler.txt");
		
			}
			
			
			else if (secim3 == 6)
			{
				string arananKisiGrubu;
				string arananKisiIsim;
				string arananKisiSoyisim;
				int arananKisiBinasi;
				int arananKisiDairesi;

				cout << "\n Grup(misafir*site-sakini):"; cin >> arananKisiGrubu;
				cout << "\n İsim:"; cin >> arananKisiIsim;
				cout << "\n Soyisim:"; cin >> arananKisiSoyisim;
				cout << "\n Blok No:"; cin >> arananKisiBinasi;
				cout << "\n Daire No:"; cin >> arananKisiDairesi;

				ifstream OdemeOku("odemeler.txt");
				ofstream OdemeYaz("odemeler.tmp");
				ofstream FitnessYaz;
				FitnessYaz.open("fitnesskul.txt", ios::app);

				Daire daire;

				while (OdemeOku >> daire.blokNo >> daire.daireNo >> daire.daireninHavuzBorcu >> daire.daireninFitnessBorcu)
				{
				
					if (arananKisiGrubu == "site-sakini")
					{
						if (arananKisiBinasi == daire.blokNo && arananKisiDairesi == daire.daireNo && daire.daireninFitnessBorcu == 0)
						{
							FitnessYaz << arananKisiGrubu << " " << arananKisiIsim << " " << arananKisiSoyisim << " " << arananKisiBinasi << " " << arananKisiDairesi << " " << "kullandırıldı" << endl;
							cout << "Fitness salonunu kullanabilirsiniz, dairenize ait borç bulunmamaktadır.";
							SiteSakiniFitnessKullananSayisi(&blok_sayisi,&daire_sayisi); daire.fitnessBorcunuArttir();
						}
						else if ((arananKisiBinasi == daire.blokNo) && (arananKisiDairesi == daire.daireNo) && (daire.daireninFitnessBorcu != 0))
						{
							FitnessYaz << arananKisiGrubu << " " << arananKisiIsim << " " << arananKisiSoyisim << " " << arananKisiBinasi << " " << arananKisiDairesi << " " << "kullandırılmadı" << endl;
							cout << "Fitness salonunu kullanamazsınız, dairenize ait borcunuz bulunmaktadır. Ödemeler menüsünden ödemenizi yapmanız gerekmektedir." << endl;
							
						}


					}
					else if(arananKisiGrubu =="misafir")
					{
						FitnessYaz << arananKisiGrubu << " " << arananKisiIsim << " " << arananKisiSoyisim << " " << arananKisiBinasi << " " << arananKisiDairesi << " " << "kullandırıldı" << endl;
						MisafirFitnessKullananSayisi(&blok_sayisi, &daire_sayisi);
						if (daire.blokNo == arananKisiBinasi && daire.daireNo == arananKisiDairesi) {
							daire.fitnessBorcunuArttir();
						}
					}
					OdemeYaz << daire.blokNo << " " << daire.daireNo << " " << daire.daireninHavuzBorcu << " " << daire.daireninFitnessBorcu << endl;
				}OdemeOku.close(); OdemeYaz.close(); FitnessYaz.close(); remove("odemeler.txt"); rename("odemeler.tmp", "odemeler.txt");

			}
				
		}
		
		cout << "Ana menüye dönmek ister misiniz?(e/h)"; cin >> program_devam;
	} while (program_devam == 'e');
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

