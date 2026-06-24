package com.project.mvcapp.view;

import java.util.List;
import java.util.Scanner;

public class ProductView {
	
	// Constructor
	public ProductView() {}
	
	// Kullanıcı girişlerini almak için Scanner nesnesi
	private Scanner scanner = new Scanner(System.in);
	
	// Ürün listesini ekrana yazdırır
	public void showProducts(List<String> products) {
		for(String p:products) {
			System.out.println(p);
		}
	}

	// Kullanıcıdan ürün id bilgisi alır
	public String getProductId() {
		System.out.print("Urun id seciniz: ");
		String id = scanner.next();
		return id;
	}
	
	// Kullanıcıdan ürün adedi bilgisi alır
	public String getProductAmount() {
		System.out.print("Urun adedi seciniz: ");
		String adet = scanner.next();
		return adet;
	}
	
	// Sipariş oluşturmak için ürün bilgilerini alma denemesi
	//public List<Integer> selectProductToCreateOrder() {
	//	List<Integer> product_infos;
	//	product_infos.add(Integer.parseInt(getProductId()));
	//	product_infos.add(Integer.parseInt(getProductAmount()));
	//	product_infos.add(Integer.parseInt(getThreshold()));
	//	return product_infos;
	//}



	// Henüz alınmamış ürün bildirimlerini gösterir
	public int showNotBoughtProducts(List<String> notificationsNotBrougthYet) {
		for(String s:notificationsNotBrougthYet) {
			System.out.println(s);
		}
		return 0;
	}

	// İşlemin tamamlandığını ekrana yazdırır
	public void processedCompleted(String s) {
		System.out.println(s+" tamamlandi");
	}

	// Kullanıcıdan ürün miktarı alır
	public int getAmount() {
		System.out.print("urun miktari giriniz: ");
		int amount = scanner.nextInt();
		return amount;
	}
	
	// Tüm ürünleri ekrana yazdırır
	public void showAllProducts(List<String> allProducts) {
		for(String s:allProducts) {
			System.out.println(s);
		}
	}

	// Kullanıcıya stok artırma veya azaltma seçeneği sunar
	public int IncreaseOrDecrease() {
		System.out.println("1-miktar artir");
		System.out.println("2-miktar azalt");
		System.out.print("secenklerden birini seciniz(1 veya 2): ");
		int amount = scanner.nextInt();
		return amount;
	}

	// Stok yetersiz uyarısını gösterir
	public void showStockAlert(int kalan) {
		System.out.println(kalan+" adet urun eksik, tekrar secim yapiniz!");
	}

	// Genel mesaj gösterme metodu
	public void showMessage(String string) {
		System.out.println(string);
	}
}