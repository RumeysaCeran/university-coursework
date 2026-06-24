/**********************************************************
*               SAKARYA ÜNİVERSİTESİ					  *
*       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ		  *
*          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ                 * 
*														  *
* PROGRAMLAMAYA GİRİŞ ÖDEVİ NUMARASI: 1                   *
* ÖĞRENCİ ADI: RÜMEYSA CERAN                              *
***********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <locale.h>

//Satış fiyatını belirleyen fonksiyonu çağırma
float satis_fiyati_belirleme(float alisFiyati);

using namespace std;
int main()
{
	srand(time(NULL));
	//Yazdırılan stringin türkçe karakter ierebilmesi için
	setlocale(LC_ALL, "Turkish");

	string firmaurun = "";

	//12 ayın adını içeren dizi oluşturma
	string aylar[12] = { "OCAK", "ŞUBAT", "MART", "NİSAN", "MAYIS", "HAZİRAN", "TEMMUZ", "AĞUSTOS", "EYLÜL", "EKİM", "KASIM", "ARALIK" };

	//Ürünlerin isimlerinin içeren dizi oluşturma
	string urun_isimleri[20] = { "defter", "kitap", "kalem", "bant", "kağıt", "zımba", "klasör", "dosya", "makas", "cetvel", "silgi", "tebeşir", "damga", "yapıştırıcı", "kalemtraş", "kitapayracı", "raptiye", "boyakalemi", "karton", "etiket" };

	//Ürünlerin ilk aydaki alış fiyatını hesaplayabilmek için varsayılan olarak alış fiyatları atamak
	
	float alis_fiyatlari[20] = { 80.5F, 100.5F ,50.5F, 21.0F, 5.25F, 34.5F, 20.5F, 12.4F, 7.8F, 10.2F, 20.5F, 30.0F, 24.7F, 9.9F, 4.2F, 4.6F, 15.0F, 60.0F, 14.2F, 26.7F };
	

	//Ürünlerin alış fiyatlarındaki artış oranlarını tutmak için matris oluşturma
	float alis_fiyati_artis_oranlari[12][20];

	//Ürünlerin ilk aydaki stok miktarlarını varsayılan olarak rastgle 1000-2000 arasında  değer atama
	int stok_miktarlari[12][20];
	for (int adet = 0; adet < 20; adet++)
	{
		stok_miktarlari[0][adet] = rand() % 1000 + 1001;
	}

	//Ürünlerin her ay satılan miktarlarını tutmak için matris oluşturma
	int aylik_satilan_miktarlar[12][20];

	//Ürünlerin ilk aydaki satış fiyatlarını satis_fiyati_belirleme fonksiyonu ile değer atama
	float satis_fiyatlari[12][20];
	for (int adet = 0; adet < 20; adet++)
	{
		satis_fiyatlari[0][adet] = satis_fiyati_belirleme(alis_fiyatlari[adet]);

	}

	//Ürünlerin her ay edilen kar miktarlarını tutmak için matris oluşturma
	float yillik_kar_miktari = 0.0F;
	float aylik_kar_miktarlari[12][20];

	//Firmanın her ay yaptığı masrafları tutmak için matris oluşturma(bir gider çeşidinin değeri 10000-20000.5 arasında rastgele bir sayı )
	float yillik_gider = 0.0F;
	float genel_masraflar[12][5];

	for (int ay = 0; ay < 12; ay++)
	{
		for (int gider = 0; gider < 5; gider++)
		{
			genel_masraflar[ay][gider] = rand() % 10000 + 10000.5F;
			yillik_gider += genel_masraflar[ay][gider];//yıllık toplam masraf hesaplama
		}
		
	
	}

	struct urun
	{
		string urun_ismi;
		float alis_fiyati;
		int stok_miktari;
		float satis_fiyati;
		float kdv_orani;
		float alis_fiyati_artis_orani;
	};
	
;	//Üye değişkenlerine ilk değerlerini atama
	int k = 0;
	urun Defter = { urun_isimleri[k], alis_fiyatlari[k],stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F, alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Kitap = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Kalem = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Bant = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Kagit = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Zimba = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Klasor = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Dosya = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Makas = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Cetvel = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Silgi = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Tebesir = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Damga = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Yapistirici = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]};k++;
	urun Kalemtras = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Kitapayraci = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Raptiye = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Boyakalemi = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	urun Karton = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k] }; k++;
	urun Etiket = { urun_isimleri[k], alis_fiyatlari[k], stok_miktarlari[0][k], satis_fiyatlari[0][k], 0.18F ,alis_fiyati_artis_oranlari[0][k]}; k++;
	k = 0;

	//12 ay boyunca firmaurun stringi oluşturma ve yazdırma işlemleri için döngü oluşturma
	for (int ay = 0; ay < 12; ay++)
	{	
		srand(time(NULL));

		//Ürünlerin alış fiyatlarını güncelleme
		for (int adet = 0; adet<20; adet++)
		{
			float min_max_deger = (rand() / static_cast<float>(RAND_MAX)) * ((alis_fiyatlari[adet] * 100 / 100) - (alis_fiyatlari[adet] * 50 / 100)) + (alis_fiyatlari[adet] * 50 / 100);//alış fiyatının %50-%100'ü arasında bir değer bulunur
			alis_fiyati_artis_oranlari[ay][adet] = (min_max_deger / alis_fiyatlari[adet]) * 100;//zam miktarı ilk baştaki zam olmadan önceki alış fiyatına bölünüp 100 ile çarpılarak artış oranı bulunur.
			alis_fiyatlari[adet] = alis_fiyatlari[adet] + min_max_deger;//alış fiyatı bir önceki ayın alış fiyatının %50-%100 arasında zamlı hali olur

		}
	
		//Ürünlerin satış fiyatılarını fonksiyon ile güncelleme
		for (int adet = 0; adet < 20; adet++)
		{
			satis_fiyatlari[ay][adet] = satis_fiyati_belirleme(alis_fiyatlari[adet]);
		}
	
		//Ürünlerin stok miktarlarını güncelleme
		for (int adet=0; adet<20; adet++)
		{
			int satilan_miktar = 0;
			int kalan_stok = stok_miktarlari[ay][adet];//ilk günün başlangıcında satılan miktar 0 olduğu için kalan stok stok miktarına eşittir.
			for (int gun = 0; gun < 30; gun++)//30 gün boyunca gün gün satış miktarları toplanılıp stok miktarından çıkartılarak ay sonu kalan stok bulunur.
			{
				satilan_miktar += int((rand()/static_cast<float>(RAND_MAX))*(int(kalan_stok * 80 / 100.0) - int(kalan_stok * 60 / 100)))+ (kalan_stok * 60 / 100);
				kalan_stok = stok_miktarlari[ay][adet] - satilan_miktar;
			}
			aylik_satilan_miktarlar[ay][adet] = satilan_miktar;
			aylik_kar_miktarlari[ay][adet] = aylik_satilan_miktarlar[ay][adet] * (satis_fiyatlari[ay][adet] - alis_fiyatlari[adet]);
			if (ay != 11)
			{
				stok_miktarlari[ay+1][adet] = 2 * kalan_stok + (rand() % (int(float(aylik_satilan_miktarlar[ay][adet]) * 100 / 100) - int(float(aylik_satilan_miktarlar[ay][adet]) * 70 / 100.)) + int(float(aylik_satilan_miktarlar[ay][adet]) * 70 / 100.0));
			}
		}
		//İlk ay için ürünün adı ve diğer üyelerinin değerleri dizeleri parçalayarak firmaürün string oluşturulur
		//Her dizinin bölünmesinden sonra her ay için oluşturulan string
		for (int adet = 0; adet < 20; adet++)
		{
			
			if (adet == 0)
			{
				firmaurun = urun_isimleri[adet] + '-' + to_string(satis_fiyatlari[ay][adet]) + '-' + to_string(alis_fiyatlari[adet]) + '-' + to_string(stok_miktarlari[ay][adet]) + '-' + to_string(0.18F) + '-' + '%' + to_string(alis_fiyati_artis_oranlari[ay][adet]) + '\n';
			}
			else
			{
				firmaurun = firmaurun + '-' + urun_isimleri[adet] + '-' + to_string(satis_fiyatlari[ay][adet]) + '-' + to_string(alis_fiyatlari[adet]) + '-' + to_string(stok_miktarlari[ay][adet]) + '-' + to_string(0.18) + '-' + '%' + to_string(alis_fiyati_artis_oranlari[ay][adet]) + '\n';
			}
		
		
		}
		//firmaurun stringi tablo şeklinde yazdırmak için döngü oluşturulur
		int harf = 0;
		string kelime;
		cout << setw(50) << "- " << aylar[ay] << " AYI - " << endl << endl;
		cout << setw(18) << "ÜRÜN ADI" << setw(18) << "SATIŞ FİYATI(TL)" << setw(18) << "ALIŞ FİYATI(TL)"<< setw(18) << "STOK MİKTARI" << setw(18) <<"KDV ORANI"<< setw(18) << "FİYAT ARTIŞI(%)" << endl << endl;

		while (firmaurun[harf] != '\0')
		{

			if (firmaurun[harf] != '-')
			{
				kelime += firmaurun[harf];
			}
			else
			{
				cout << setw(18) << kelime;
				kelime.clear();
			}
			harf++;

		}
		//Aylık olarak ayın en çok ve en az satılan ürünlerin isimlerini belirleme
		string en_cok_satilan_ismi = urun_isimleri[0];//en büyük değer
		string en_az_satilan_ismi = urun_isimleri[0];//en küçük değer
		int en_cok_satilan = aylik_satilan_miktarlar[ay][0];
		int en_az_satilan = aylik_satilan_miktarlar[ay][0];
		
		for (int adet = 1; adet < 20; adet++)
		{

			if (aylik_satilan_miktarlar[ay][adet] > en_cok_satilan)//en çok satılan
			{
				en_cok_satilan = aylik_satilan_miktarlar[ay][adet];
				en_cok_satilan_ismi = urun_isimleri[adet];
			}

			if (aylik_satilan_miktarlar[ay][adet] < en_az_satilan)//en az satılan
			{
				en_az_satilan = aylik_satilan_miktarlar[ay][adet];
				en_az_satilan_ismi = urun_isimleri[adet];
			}
		}

		//aylık olarak ayın en çok ve en az kar edilen ürünlerinin isimlerini belirleme
		string en_cok_kar_ismi = urun_isimleri[0];
		string en_az_kar_ismi = urun_isimleri[0];
		int en_cok_kar = aylik_kar_miktarlari[ay][0];
		int en_az_kar = aylik_kar_miktarlari[ay][0];
		for (int adet = 1; adet < 20; adet++)
		{

			if (aylik_kar_miktarlari[ay][adet] > en_cok_kar)//en çok kar edilen
			{
				en_cok_kar = aylik_kar_miktarlari[ay][adet];
				en_cok_kar_ismi = urun_isimleri[adet];
			}

			if (aylik_kar_miktarlari[ay][adet] < en_az_kar)//en az kar edilen
			{
				en_az_kar = aylik_kar_miktarlari[ay][adet];
				en_az_kar_ismi = urun_isimleri[adet];
			}
		}
		
		//1 ay sonundaki ürünlerden elde edilen toplam kar
		float aylik_urun_geliri = 0.0F;
		for (int adet = 0; adet < 20; adet++)
		{
			aylik_urun_geliri += aylik_kar_miktarlari[ay][adet];
		}

		//1 ay sonundaki toplam gider miktarı
		float aylik_gider = 0.0F;
		for (int gider = 0; gider < 5; gider++)
		{
			aylik_gider += genel_masraflar[ay][gider];
		}
		
		//1 ay sonundaki net toplam kar
		float aylik_toplam_kar = aylik_urun_geliri - aylik_gider;
		yillik_kar_miktari += aylik_toplam_kar;

		//Ay sonu masrafları yazdırma
		cout << endl << endl;

		cout << aylar[ay] << " AYI GENEL MASRAFLARI:" << endl;
		cout << "Kira: " << genel_masraflar[ay][0] << setw(15) << "Personel: " << genel_masraflar[ay][1] << setw(15) << "Elektrik: " << genel_masraflar[ay][2] << setw(15) << "Su: " << genel_masraflar[ay][3] << setw(15) << "Diğerleri: " << genel_masraflar[ay][4] << endl;
		cout << "toplam Masraf: " << aylik_gider << endl;

		//Ay sonu istatistiki verilerini yazdırma
		cout << endl << endl;

		cout << aylar[ay] << " AYI İSTATİSTİKİ VERİLERİ: " << endl;
		cout << "En çok satılan ürün: " << en_cok_satilan_ismi << endl;
		cout << "En az satılan ürün: " << en_az_satilan_ismi << endl;
		cout << "En çok kar edilen: " << en_cok_kar_ismi << endl;
		cout << "En az kar edilen: " << en_az_kar_ismi << endl;
		cout << "Toplam Kar: " << aylik_toplam_kar;

		cout << endl << endl;


	}
	
	//Yıl sonu en çok ve en az satılan ürünlerin isimlerini belirleme
	string en_cok_satilan_ismi = urun_isimleri[0];//en büyük değer
	string en_az_satilan_ismi = urun_isimleri[0];//en küçük değer
	int en_cok_satilan = aylik_satilan_miktarlar[0][0];
	int en_az_satilan = aylik_satilan_miktarlar[0][0];
	for (int ay = 0; ay < 12; ay++)
	{
		for (int adet = 0; adet < 20; adet++)
		{
			if (aylik_satilan_miktarlar[ay][adet] > en_cok_satilan)//en çok satılan yıl sonu
			{
				en_cok_satilan = aylik_satilan_miktarlar[ay][adet];
				en_cok_satilan_ismi = urun_isimleri[adet];
			}
			
			if (aylik_satilan_miktarlar[ay][adet] < en_az_satilan)//en az satılan yıl sonu
			{
				en_az_satilan = aylik_satilan_miktarlar[ay][adet],
				en_az_satilan_ismi = urun_isimleri[adet];
			}
		}
	
	}

	//Yıl sonu en çok ve en az kar edilen ürünlerin isimlerini belirleme
	string en_cok_kar_ismi = urun_isimleri[0];//en büyük değer
	string en_az_kar_ismi = urun_isimleri[0];//en küçük değer
	int en_cok_kar = aylik_kar_miktarlari[0][0];
	int en_az_kar = aylik_kar_miktarlari[0][0];
	for (int ay = 0; ay < 12; ay++)
	{
		for (int adet = 0; adet < 20; adet++)
		{
			if (aylik_kar_miktarlari[ay][adet] > en_cok_kar)//en çok kar edilen
			{
				en_cok_kar = aylik_kar_miktarlari[ay][adet];
				en_cok_kar_ismi = urun_isimleri[adet];
			}
		
			if (aylik_kar_miktarlari[ay][adet] < en_az_kar)//en az kar edilen
			{
				en_az_kar = aylik_kar_miktarlari[ay][adet];
				en_az_kar_ismi = urun_isimleri[adet];
			}
		
		}
	}


	//Yıl sonu istatistiki verilerini yazdırma
	cout << endl << endl;
	cout << "YIL SONU İSTATİSTİKİ VERİLERİ: " << endl;
	cout << "En çok satılan ürün: " << en_cok_satilan_ismi << endl;
	cout << "En az satılan ürün: " << en_az_satilan_ismi << endl;
	cout << "En çok kar edilen: " << en_cok_kar_ismi << endl;
	cout << "En az kar edilen: " << en_az_kar_ismi << endl;
	cout << "Yıllık Masraf: " << yillik_gider << endl;
	cout << "Toplam Kar: " << yillik_kar_miktari;

	cout << endl << endl;

	return 0;

};

//İstenilen formüle uygun satış fiyatını belirleme fonksiyonu
float satis_fiyati_belirleme(float alisFiyati)
{
	float min_max_deger = (rand() / static_cast<float>(RAND_MAX)) * ((alisFiyati * 50 / 100) - (alisFiyati * 30 / 100)) + (alisFiyati * 30 / 100);
	float satis_fiyati_kdvsiz = alisFiyati + min_max_deger;
	//kdvli halini hesaplama(kdv oranını %18 olarak hesapladım)
	float satis_fiyati = (satis_fiyati_kdvsiz * 18 / 100) + satis_fiyati_kdvsiz;

	return satis_fiyati;

};