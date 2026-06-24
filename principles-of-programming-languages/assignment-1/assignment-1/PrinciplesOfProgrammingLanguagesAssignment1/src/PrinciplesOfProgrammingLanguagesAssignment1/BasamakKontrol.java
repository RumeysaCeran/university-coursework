// @ Rümeysa Ceran

package PrinciplesOfProgrammingLanguagesAssignment1;

import java.util.ArrayList;

import com.github.javafaker.Faker;

public class BasamakKontrol {

	public BasamakKontrol(ArrayList<Sehir> sehirler) {
	}

	public static Faker faker = new Faker();

	// sehrin ilce sayısını ikiye böler, eger tek ilçe varsa basamakKontroluMahalle
	// fonksiyonunu döndürür
	public static ArrayList<Ilce> basamakKontroluIlce(Sehir sehir) {
		int ilce_sayisi = sehir.ilceler.size();
		int yeni_ilce_sayisi = ilce_sayisi / 2;
		if (yeni_ilce_sayisi != 0) {// ilce sayısı birden fazla
			ArrayList<Ilce> yeni_ilceler = new ArrayList<>();
			for (int j = 0; j < yeni_ilce_sayisi; j++) { // sehrin ilce sayısının yarısı kadar ilceyi yeni_ilceler
															// listesine ekler
				yeni_ilceler.add(sehir.ilceler.get(j));
			}
			for (int j = yeni_ilce_sayisi - 1; j >= 0; j--) { // sehirden yeni sehre eklenen ilceleri mevcut sehirden
																// siler
				sehir.ilceler.remove(j);
			}
			return yeni_ilceler;
		} else {
			return basamakKontroluMahalle(sehir.ilceler.get(0));
		} // ilce sayısı 1'dir, ilceler bölünemez o yüzden mahalleler bölünmeli

	}

	// mahalle sayısını ikiye böler ve yeni ilce olusturur ve mahallelerin yarısını
	// yeni ilçeye gecirir, eger mahalle sayısı 1 ise basamakSayisiKontroluKisi
	// fonksiyonunu cagırır.
	public static ArrayList<Ilce> basamakKontroluMahalle(Ilce ilce) {
		int yeni_mahalle_sayisi = ilce.mahalleler.size() / 2;
		if (yeni_mahalle_sayisi != 0) { // mahalle sayısı 1'den fazla
			ArrayList<Ilce> yeni_ilceler = new ArrayList<>();
			ArrayList<Mahalle> yeni_mahalleler = new ArrayList<>();
			int yeni_nufus = 0;
			for (int j = 0; j < yeni_mahalle_sayisi; j++) { // ilcenin mahallelerinin yarısı yeni_mahalleler dizisine
															// eklenir
				yeni_mahalleler.add(ilce.mahalleler.get(j));
			}
			yeni_nufus = yeni_mahalle_sayisi * yeni_mahalleler.get(0).nufus; // yeni olusacak ilcenin nufusu hesaplanır
			for (int j = yeni_mahalle_sayisi - 1; j >= 0; j--) { // mevcut ilceden yeni ilceni mahalleleri cıkartılır
				ilce.mahalleler.remove(j);
			}
			ilce.nufus -= yeni_nufus; // mevcut ilcenin nufusu güncellenir(yeni ilceye mahalleler eklendigi için)
			String ilce_adi = faker.address().cityName(); // yeni ilce adı alınır faker ile
			Ilce yeni_ilce = new Ilce(ilce_adi, yeni_nufus);
			yeni_ilce.mahalleler = yeni_mahalleler; // yeni ilceye yeni mahalleler verilir
			yeni_ilceler.add(yeni_ilce); // yeni ilce ArrayListe eklenir
			return yeni_ilceler;
		} else { // mahalle sayisi 1'dir, o yüzden kisiler ikiye bölünmelidir
			return basamakKontroluKisi(ilce);
		}
	}

	// Kısacası 1 sehrin 1 ilcesi ve 1 mahallesi olma durumudur, kisi sayısı yarıya
	// bölünür
	public static ArrayList<Ilce> basamakKontroluKisi(Ilce ilce) {
		Mahalle mevcut_mahalle = ilce.mahalleler.get(0);
		int yeni_kisi_sayisi = mevcut_mahalle.kisiler.size() / 2;
		ArrayList<Kisi> yeni_kisiler = new ArrayList<>();
		ArrayList<Ilce> yeni_ilceler = new ArrayList<>();
		for (int j = 0; j < yeni_kisi_sayisi; j++) { // mevcut mahallenin kisilerinin yarısı alınır ve yeni_kisiler
														// listesine eklenir
			yeni_kisiler.add(mevcut_mahalle.kisiler.get(j));
		}
		int yeni_nufus = yeni_kisiler.size(); // yeni mahallenin yeni ilcenin nufusu hesaplanir
		for (int j = yeni_kisi_sayisi - 1; j >= 0; j--) {// mevcut mahalleden yeni mahallenin kisileri cikartilir
			mevcut_mahalle.kisiler.remove(j);
		}
		mevcut_mahalle.nufus -= yeni_nufus;// mevcut mahallenin nufusu guncellenir
		ilce.nufus -= yeni_nufus;// mevcut ilcenin nufusu guncellenir
		ArrayList<Mahalle> yeni_mahalleler = new ArrayList<>();
		String mahalle_adi = faker.address().streetName();
		Mahalle yeni_mahalle = new Mahalle(mahalle_adi, yeni_nufus); // yeni bir mahalle olusturulur
		yeni_mahalle.kisiler = yeni_kisiler; // yeni mahalleye yenikisiler eklenir
		yeni_mahalleler.add(yeni_mahalle); // yeni mahalle yeni mahalleler listesine eklenir
		String ilce_adi = faker.address().cityName();
		Ilce yeni_ilce = new Ilce(ilce_adi, yeni_nufus); // yeni ilce olusturulur
		yeni_ilce.mahalleler = yeni_mahalleler; // yeni ilceye yeni mahalleler eklenir
		yeni_ilceler.add(yeni_ilce); // yeni ilcelere yeni ilce eklenir
		return yeni_ilceler;
	}

	// sehirlerin nufuslari 4 basamakli mi kontrolu yapar for dongusu ile
	public static void nufusBasamakSayisiKontrolu(ArrayList<Sehir> sehirler) {
		ArrayList<Sehir> yeniSehirler = new ArrayList<>();// yeni eklenecek sehirleri ıcınde tutar dongu ile tum
															// sehirler kontrol ettikten sonra yeni sehirleri eklemek
															// icin
		for (int s = 0; s < sehirler.size(); s++) {
			if (sehirler.get(s).nufus > 999) {
				ArrayList<Ilce> yeni_ilceler = new ArrayList<>(); // yeni sehire eklenecek yeni ilceleri tutmak icin
																	// liste olusturulur
				yeni_ilceler = basamakKontroluIlce(sehirler.get(s));// yeni sehrin ilcelerini almak icin sehrin
																	// ilcelerini bolen fonksiyonu cagırır.
				int yeni_sehir_nufusu = yeni_ilceler.size() * yeni_ilceler.get(0).nufus;// ilcelerden birinin nufusu ile
																						// ilce sayısını carparak yeni
																						// sehrin nufusu hesaplanir
				sehirler.get(s).nufus -= yeni_sehir_nufusu; // mevcut sehrin nufusu guncellenir
				String sehir_ad = faker.address().city();
				Sehir yeni_sehir = new Sehir(sehir_ad, yeni_sehir_nufusu);
				yeni_sehir.ilceler = yeni_ilceler; // yeni sehre alınan ilceler verilir
				yeniSehirler.add(yeni_sehir); // yeni sehir yeniSehirler listesine eklenir
			}
		}
		sehirler.addAll(yeniSehirler);// yeniSehirler var olan sehirlerin sonuna eklenir.
	}

}
