package com.project.mvcapp.view;

import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class OrderView {
	
	Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
	
	public OrderView() {}
	
	// Konsolu temizler (Windows ve diğer işletim sistemleri için)
	public static void clearScreen() {
		try {
			if(System.getProperty("os.name").contains("Windows")) {
				new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
			}
			else {
				System.out.print("033[H\033[2J");
				System.out.flush();
			}
		}catch(Exception e) {
			for(int i=0;i<50;i++)System.out.println();
		}
	}

	// Sipariş oluşturma işlemi tamamlandı mesajı
	public void creatingOrderCompleted() {
		System.out.println("Siparisiniz basariyla olusturuldu");
	}

	// Geçmiş siparişleri ekrana yazdırır
	public void showPastOrders(List<String> pastOrders) {
		clearScreen();
		for(String o:pastOrders) {
			System.out.println(o);
		}
		
	}

	// Sipariş ID girişi alır
	public int getOrderId() {
		System.out.println("Siparis id: ");
		int id = scanner.nextInt();
		return id;
		
	}

	// Sipariş iade mesajı
	public void orderReturnedCompleted() {
		System.out.println("Siparis iadesi basariyla tamamlandi");
		
	}

	// Sipariş iptal mesajı
	public void orderCanceledCompleted() {
		System.out.println("Siparis iptali basariyla tamamlandi");
		
	}

	// Mesafe bilgisi alır
	public double getDistance() {
		System.out.print("Mesafe giriniz: ");
		double distance = scanner.nextDouble();
		return distance;
	}

	// Geçersiz mesafe uyarısı
	public void showDistanceAlert() {
		System.out.println("gecersiz mesafe giriniz!");
	}

	// İşlem tamamlandı mesajı
	public void processCompleted(String inMenu) {
		System.out.println(inMenu+" tamamlandi.");
		
	}

	// Tüm siparişleri ekrana yazdırır
	public void showAllOrders(List<String> allOrders) {
		clearScreen();
		for(String o:allOrders) {
			System.out.println(o);
		}
		
	}

	// Sipariş bulunamadı uyarısı
	public void showNotFoundAlert() {
		
		System.out.println("Aranilan kriterde siparis bulunamamistir!");
	}

	// Sipariş durumu gösterilir
	public void showState(String state) {
		System.out.println("siparisin durumu "+ state+ " olarak guncellenmistir!");
		
	}
	
	// Takip numarası girişi alır
	public String getTrackingNumber() {
		System.out.println("durumunu gormek istediginiz siparisinizin takip numarasini giriniz!: ");
		return scanner.next();
	}

	// Sipariş durumu gösterilir
	public void showOrderState(String trackingNumber, String state) {
		System.out.println(trackingNumber + " takip numarali siparisinizin durumu: " + state);	
	}

	// Hata mesajı gösterir
	public void showError(String message) {
		System.out.println(message);
		
	}
}