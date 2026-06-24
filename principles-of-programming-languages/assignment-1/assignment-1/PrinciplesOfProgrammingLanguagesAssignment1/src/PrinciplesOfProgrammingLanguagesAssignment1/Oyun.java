// @ Rümeysa Ceran 

package PrinciplesOfProgrammingLanguagesAssignment1;

import java.util.ArrayList;
import java.util.Scanner;
import com.github.javafaker.Faker;

public class Oyun {
	int tur_sayisi;
	ArrayList<Sehir> sehirler = new ArrayList<Sehir>();
	static Scanner scanner = new Scanner(System.in);

	public Oyun() {
	};

	Faker faker = new Faker();

	// tur sayısı alma fonksiyonu
	int turSayisiniAl() {

		do {
			System.out.printf("tur sayisi: ");
		} while (!(scanner.hasNextInt()));

		int tur_sayisi = scanner.nextInt();

		return tur_sayisi;
	}

	// bir tur atma fonksiyonu
	void turAt(ArrayList<Sehir> sehirler) {
		for (int s = 0; s < sehirler.size(); s++) {
			int nufus_birler_basamagı = sehirler.get(s).nufus % 10;
			int nufus_onlar_basamagı = sehirler.get(s).nufus / 10;
			if (nufus_onlar_basamagı > 9) {
				nufus_onlar_basamagı = nufus_onlar_basamagı % 10;
			}
			int mahalle_nufus_artis_kati = nufus_birler_basamagı + nufus_onlar_basamagı;
			if (mahalle_nufus_artis_kati != 0) // birler ve onlar basamagi toplami 0 degil ise
			{
				ArrayList<Ilce> ilceler = sehirler.get(s).ilceler;
				for (int i = 0; i < ilceler.size(); i++) {
					ArrayList<Mahalle> mahalleler = ilceler.get(i).mahalleler;
					for (int m = 0; m < mahalleler.size(); m++) { // dongu ilcedeki her bir mahalle icin doner
						int olusturulacakKisiSayisi = mahalleler.get(m).nufus;
						mahalleler.get(m).nufus = mahalleler.get(m).nufus * mahalle_nufus_artis_kati; // mahalle nufusu
																										// artirilir
						olusturulacakKisiSayisi = mahalleler.get(m).nufus - olusturulacakKisiSayisi; // yeni nufusa gore
																										// olusturulmasi
																										// gereken kisi
																										// sayisi
																										// hesaplanir
						ArrayList<Kisi> yeniOlusturulanKisiler = NesneleriOlustur
								.kisileriOlustur(olusturulacakKisiSayisi); // yeni kisileri olusturur
						mahalleler.get(m).kisiler.addAll(yeniOlusturulanKisiler);
						ArrayList<Kisi> kisiler = mahalleler.get(m).kisiler;
						for (int k = 0; k < kisiler.size(); k++) { // tur sonu her kisinin yası bir artirilir
							kisiler.get(k).yas++;
						}
					}
					ilceler.get(i).nufus = (mahalleler.size()) * (mahalleler.get(0).nufus); // ilcenin yeni nufusu
																							// guncellenir
				}
				sehirler.get(s).nufus = (ilceler.size()) * (ilceler.get(0).nufus); // sehrin yeni nufusu guncellenir
			} else { // birler ve onlar basamagı toplami 0 ise
				ArrayList<Ilce> ilceler = sehirler.get(s).ilceler;
				for (int i = 0; i < ilceler.size(); i++) {
					ArrayList<Mahalle> mahalleler = ilceler.get(i).mahalleler;
					for (int m = 0; m < mahalleler.size(); m++) {
						mahalleler.get(m).nufus = mahalleler.get(m).nufus + 1; // mahalle nufusu 1 artirilir
						ArrayList<Kisi> yeniOlusturulanKisiler = NesneleriOlustur.kisileriOlustur(1); // 1 yeni kisi
																										// olusturulur
						mahalleler.get(m).kisiler.addAll(yeniOlusturulanKisiler); // yeni kisi mahalleye eklenir
						ArrayList<Kisi> kisiler = mahalleler.get(m).kisiler;
						for (int k = 0; k < kisiler.size(); k++) {
							kisiler.get(k).yas++; // kisilerin yaslar bir artirilir
						}
					}
					ilceler.get(i).nufus = (mahalleler.size()) * (mahalleler.get(0).nufus); // ilcenin yeni nufusu
																							// guncellenir
				}
				sehirler.get(s).nufus = (ilceler.size()) * (ilceler.get(0).nufus); // sehrin yeni nufusu guncellenir
			}
		}
	}

	// ekranda tur sonu goruntuleri yazdirma fonksiyonu
	void ekrandaGoster(ArrayList<Sehir> sehirler) {
		int sehir_sayisi = sehirler.size();
		ArrayList<String> ekran = new ArrayList<>();
		for (int sayac = 0; sayac < sehir_sayisi; sayac++) {

			String sehir_gosterimi = "[" + sehirler.get(sayac).nufus + "]";
			if (sayac + 1 != sehir_sayisi) {
				sehir_gosterimi = sehir_gosterimi + "-";
			}
			ekran.add(sehir_gosterimi);
		}

		int sayac = 0;
		String s = "";
		for (int i = 0; i < ekran.size(); i++) {
			if (sayac % 5 == 0) {
				s += "\n";
			}
			s += ekran.get(i);
			sayac++;
		}
		System.out.printf(s + "\n");
	}

	// ekrani full temizler
	public static void ekranTemizle() {
		try {
			if (System.getProperty("os.name").contains("Windows")) {
				new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
			} else {
				new ProcessBuilder("clear").inheritIO().start().waitFor();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// tum turlar sona erince kullanıcıdan alınan satir sutun bilgisiyle ilin
	// bilgilerini gosterme fonksiyonu
	void bilgileriGoster() {

		int sutun = 5;
		int toplam = this.sehirler.size();
		int satir = (int) Math.ceil(toplam / 5.0);

		int array_satir = 0;
		int array_sutun = 0;
		boolean durum;

		// Kullanıcıdan giriş alma
		do {
			durum = false;
			System.out.print("Sirasiyla satir ve sutun giriniz(0 dahil): ");

			if (scanner.hasNextInt()) {
				array_satir = scanner.nextInt();
			} else {
				durum = true;
				scanner.next(); // hatalı input temizle
				continue;
			}

			if (scanner.hasNextInt()) {
				array_sutun = scanner.nextInt();
			} else {
				durum = true;
				scanner.next();
				continue;
			}

			// sınır kontrolü
			if (array_satir < 0 || array_satir >= satir ||
					array_sutun < 0 || array_sutun >= sutun) {
				durum = true;
				System.out.println("Gecersiz deger girdiniz!");
				continue;
			}

			// index hesapla
			int index = array_satir * sutun + array_sutun;

			if (index < 0 || index >= this.sehirler.size()) {
				System.out.println("Bu konumda sehir yok!");
				durum = true;
				continue;
			}

		} while (durum);

		// Sehir bul
		int index = array_satir * sutun + array_sutun;
		Sehir sehir = this.sehirler.get(index);

		// Yazdırma
		System.out.println("Sehir: " + sehir.ad + " - Nufus: " + sehir.nufus);

		for (Ilce ilce : sehir.ilceler) {
			System.out.printf("  Ilce: %s - Nufus: %d\n", ilce.ad, ilce.nufus);

			for (Mahalle mahalle : ilce.mahalleler) {
				System.out.printf("    Mahalle: %s - Nufus: %d\n", mahalle.ad, mahalle.nufus);

				for (Kisi kisi : mahalle.kisiler) {
					System.out.println("      " + kisi.id + " - " + kisi.ad_soyad + " - " + kisi.yas);
				}
			}
		}
	}

	// tüm oyunun calıstıgı fonksiyon
	void oyunaBasla() {
		this.tur_sayisi = turSayisiniAl();
		scanner.nextLine();
		this.sehirler = NesneleriOlustur.sehirleriOlustur(this.sehirler);
		for (int i = 0; i < this.tur_sayisi; i++) {
			int kacıncıTurda = i + 1;
			turAt(this.sehirler);
			ekranTemizle();
			System.out.println("-------------- " + kacıncıTurda + ". " + "TUR SONU " + "-----------------------");
			ekrandaGoster(this.sehirler);
			BasamakKontrol.nufusBasamakSayisiKontrolu(this.sehirler);
			System.out.println("-------- " + kacıncıTurda + ". " + "TUR SONU YENI SEHIRLER ILE " + "-----------");
			ekrandaGoster(this.sehirler);
			System.out.println("-----------------------------------------------------------------------------");
		}
		bilgileriGoster();

	}

}
