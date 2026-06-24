package com.project.mvcapp.view;


import java.util.List;
import java.util.Scanner;

public class UserView {

	// Kullanıcı girişlerini almak için Scanner nesnesi
	Scanner scanner = new Scanner(System.in);
	
	// Constructor
	public UserView() {}
	
	// Kullanıcıdan ad bilgisini alır
	public String getName() {
		System.out.println("-ad:");
		String name = scanner.next();
		return name;
	}
	
	// Kullanıcıdan soyad bilgisini alır
	public String getSurname() {
		System.out.println("-soyad:");
		String surname = scanner.next();
		return surname;
	}

	
	// Kullanıcıdan email bilgisini alır
	public String getEmail() {
		System.out.println("-email:");
		String email = scanner.next();
		return email;
	}
	
	// Kullanıcıdan şifre bilgisini alır
	public String getPassword() {
		System.out.println("-password:");
		String password = scanner.next();
		return password;
	}
	
	// Kullanıcıdan id bilgisi alır
	public int getId() {
		System.out.println("-id:");
		int id = scanner.nextInt();
		return id;
	}
	
	// Kullanıcıdan rol seçimi alır
	public String getRole() {

		System.out.println("Rol seciniz:");
		System.out.println("1-Kurye");
		System.out.println("2-Depo Gorevlisi");
		System.out.println("3-Musteri");
		System.out.println("4-Satin Alma Birimi");
		System.out.println("5-Tedarikci");
		
		String rol;
		
		do {
			rol = scanner.next();
		}while(rol== "1" || rol=="2"|| rol=="3" || rol=="4" || rol=="5");
		
		return rol;
	}
	
	// Kayıt işlemi başarısız olduğunda hata mesajı gösterir
	public void signInErrorPage() {
		
		System.out.println("-------------------------------------------------------------------------------");
		System.out.println("-	              Bu email veya sifre daha once kullanılmıstır!                ");
		System.out.println("-------------------------------------------------------------------------------");
		
	}

	// Tüm kullanıcıları ekrana yazdırır
	public void showAllUsers(List<String> users) {
		for(String s:users) {
			System.out.println(s);
		}
	}

}