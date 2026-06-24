// @ Rümeysa Ceran 

package PrinciplesOfProgrammingLanguagesAssignment1;

import java.util.ArrayList;
import java.util.Scanner;
import com.github.javafaker.Faker;

public class NesneleriOlustur {
	public NesneleriOlustur() {
	}

	public static Faker faker = new Faker();

	static Scanner scanner = new Scanner(System.in);

	// baslangıc değerlerini alma fonksiyonu
	public static ArrayList<Integer> baslangicDegerleriniAl() {
		boolean durum = false;
		ArrayList<Integer> girilen_degerler;
		while (true) {
			girilen_degerler = new ArrayList<Integer>();
			System.out.printf("baslangic degerlerini (2 basamakli sayilar) giriniz: ");
			String satir = scanner.nextLine().trim();
			String[] parcalar = satir.split(" ");
			durum = false;
			for (String p : parcalar) {
				int sayi;
				try {
					sayi = Integer.parseInt(p);
				} catch (Exception e) {
					System.out.println("Sadece sayi giriniz!");
					durum = true;
					break;
				}
				if (sayi < 10 || sayi > 99) {
					System.out.println("2 basamakli sayilar yaziniz!");
					durum = true;
					break;
				}
				girilen_degerler.add(sayi);
			}
			if (durum) {
				continue;
			}
			break;
		}

		System.out.println("baslangic degerleri alindi" + girilen_degerler);
		return girilen_degerler;
	}

	// her bir mahalle icin kisileri olusturma fonksiyonu
	public static ArrayList<Kisi> kisileriOlustur(int mahalle_nufusu) {
		ArrayList<Kisi> kisiler = new ArrayList<>();
		for (int i = 0; i < mahalle_nufusu; i++) {
			String ad_soyad = faker.name().fullName();
			int yas = faker.number().numberBetween(0, 50);
			Kisi kisi = new Kisi(ad_soyad, yas);
			kisiler.add(kisi);
		}
		return kisiler;
	}

	// her bir ilce icin mahalleleri olusturma fonksiyonu
	public static ArrayList<Mahalle> mahalleleriOlustur(int mahalle_nufusu, int ilcenin_mahalle_sayisi) {
		ArrayList<Mahalle> mahalleler = new ArrayList<>();
		for (int i = 0; i < ilcenin_mahalle_sayisi; i++) {
			String ad = faker.address().streetName();
			ArrayList<Kisi> kisiler = kisileriOlustur(mahalle_nufusu);
			Mahalle mahalle = new Mahalle(ad, mahalle_nufusu);
			mahalle.kisiler = kisiler;
			mahalleler.add(mahalle);
		}
		return mahalleler;
	}

	// her bir il icin ilceleri olusturma fonksiyonu
	public static ArrayList<Ilce> ilceleriOlustur(int nufus, int mahalle_sayisi, int ilce_sayisi) {
		ArrayList<Ilce> ilceler = new ArrayList<>();
		int ilcenin_nufusu = nufus / ilce_sayisi;
		int ilcenin_mahalle_sayisi = mahalle_sayisi / ilce_sayisi;
		int mahalle_nufusu = nufus / mahalle_sayisi;
		for (int i = 0; i < ilce_sayisi; i++) {
			String ad = faker.address().cityName();
			ArrayList<Mahalle> mahalleler = mahalleleriOlustur(mahalle_nufusu, ilcenin_mahalle_sayisi);
			Ilce ilce = new Ilce(ad, ilcenin_nufusu);
			ilce.mahalleler = mahalleler;
			ilceler.add(ilce);
		}
		return ilceler;
	}

	// verilen bir ArraList<Sehir> listesine sehirleri olusturur
	public static ArrayList<Sehir> sehirleriOlustur(ArrayList<Sehir> sehirler) {

		ArrayList<Integer> girilen_degerler = baslangicDegerleriniAl(); // kullanıcıdan nufuslari alir
		int sehir_sayisi = girilen_degerler.size();

		for (int i = 0; i < sehir_sayisi; i++) { // girilen nufus degeri kadar dongu doner
			int nufus = girilen_degerler.get(i);
			int ilce_sayisi = nufus / 10;
			int mahalle_sayisi = nufus % 10;

			// mahalle_sayisi/ilce_sayisi kontrolu
			int mahalle_ilce_orani = mahalle_sayisi % ilce_sayisi;
			if (mahalle_sayisi == 0) {
				mahalle_sayisi = ilce_sayisi;
			} // mahalle sayisi 0 ise ilce sayisi kadar mahalle olusturulmali
			else if (mahalle_ilce_orani != 0) { // eger mahalle sayisi ilce sayisina bolunemiyorsa mahalle sayisi
												// duzenlenmeli

				int mahalle_sayisi_artisi = ilce_sayisi - mahalle_ilce_orani;
				if ((nufus + mahalle_sayisi_artisi) / (10) != ilce_sayisi) {
					mahalle_sayisi -= mahalle_ilce_orani;
				} else {
					mahalle_sayisi += mahalle_sayisi_artisi;
				}
			}

			nufus = mahalle_sayisi + ilce_sayisi * 10;

			// nufus sayisi mahalle sayisina esit mi kontrolu yapılır
			int nufus_mahalle_orani = nufus % mahalle_sayisi;
			if (nufus_mahalle_orani != 0) { // nufus sayisi mahalle sayisina bolunemiyorsa, nufus sayisi artirilir.
				int nufus_artisi = mahalle_sayisi - nufus_mahalle_orani;
				nufus += nufus_artisi;
			}

			ArrayList<Ilce> ilceler = ilceleriOlustur(nufus, mahalle_sayisi, ilce_sayisi); // ilceler olusturulur
			String ad = faker.address().city();
			Sehir sehir = new Sehir(ad, nufus); // sehir olusturulur
			sehir.ilceler = ilceler; // sehire ilceler verilir.
			sehirler.add(sehir); // sehirler listesine olusturulan sehir eklenir.

		}

		return sehirler;

	}
}
