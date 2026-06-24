package com.project.mvcapp.model;

public enum Permission {
	
	CREATE_USER(1,"Kullanici Olustur", true),// main menu - admin
	
	DELETE_USER(2, "Kullanici Sil", true),// main menu - admin
	
	SHOW_USERS(3,"Kullanicilari Goster",true),// main menu - admin
	
	VIEW_LOG(4, "Loglari Goruntule", true),// main menu - admin
	
	ADD_PRODUCT(5, "Urun Ekle", true),// main menu - depo gorevlisi
	
	UPDATE_STOCK(6, "Stok Guncelle", true),// main menu - depo gorevlisi
	
	UPDATE_ORDER_STATE(7, "Siparis Durumunu Guncelle", true),// main menu - depo gorevlisi, kargocu
	
	DELIVER(8, "Siparisi Teslim Et", true),// main menu - kargocu
	
	CREATE_ORDER(9, "Siparis Olustur", true),// main menu - musteri
	
	TRACK_ORDER(10, "Siparisi Takip Et", true),// main menu - musteri 
	
	REFUND(11, "Iade Yap", true),// main menu - musteri
	
	CHECK_EMAILS(12, "Emaillere Bak", false),// satin alma birimi - tedarikci
	
	CHECK_SYSTEM_NOTIFICATIONS(13,"SistemIci Bildirimlere Bak",true),// depo gorevlisi
	
	BUY_PRODUCTS(14, "Urun Al", true),// main menu - satin alma birimi
	
	BRING_SUPPLIES(15, "Urunleri Getir", true),// main menu - tedarikci
	
	SHOW_PERMISSIONS(16, "Ana Menuye Git", false),// hepsi
	
	SHOW_PRODUCTS(17,"Urunleri Goster", true),// depo gorevlisi
	
	CANCEL_ORDER(18,"Siparis iptal et", true),// main menu - musteri
	
	LOG_OUT(19,"cıkıs yap",true);// main menu
	
	private final int index; // menüdeki numara
	
	private final String inMenu; // menüde görünen isim
	
	private final boolean isInMainMenu; // ana menüde görünüp görünmeyeceği
	
	
	Permission(int index, String inMenu, boolean isInMainMenu){
		this.index = index;
		this.inMenu = inMenu;
		this.isInMainMenu = isInMainMenu;
	}
	
	public int getIndex() {
		return this.index;
	}
	
	public String inMenu() {
		return this.inMenu;
	}
	
	public boolean isInMainMenu() {
		return this.isInMainMenu;
	}
}