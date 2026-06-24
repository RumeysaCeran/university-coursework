package com.project.mvcapp.view;

import java.util.ArrayList;
import java.util.Scanner;

public class PermissionView {
	
	Scanner scanner = new Scanner(System.in);
	
	public PermissionView() {}
	
	// Yetki listesini ekrana yazdırır
	public void showPermissions(ArrayList<String> permission) {
		for (String line : permission) {
	        System.out.print(line);
	    }
	}
	
	// Konsolu temizler (Windows ve diğer işletim sistemleri için)
	 public static void clearScreen() {
	        try {
	            if (System.getProperty("os.name").contains("Windows")) {
	                new ProcessBuilder("cmd", "/c", "cls")
	                        .inheritIO().start().waitFor();
	            } else {
	                System.out.print("\033[H\033[2J");
	                System.out.flush();
	            }
	        } catch (Exception e) {
	            for (int i = 0; i < 50; i++) {
	                System.out.println();
	            }
	        }
	}
	
	// Kullanıcının seçtiği yetki indeksini alır
	public int selectedPermission() {
		System.out.print("seceneklerden birini seciniz: ");
		int index = scanner.nextInt();
		return index;
	}

	
	// Kullanıcının ana menüye dönmek isteyip istemediğini kontrol eder
	public boolean goToMainMenu() {

	    String goTo;

	    do {
	        System.out.print("Ana menuye donmek ister misiniz?(y/n): ");
	        goTo = scanner.next().trim().toLowerCase();

	    } while(!(goTo.equals("y") || goTo.equals("n")));

	    if(goTo.equals("y")) {
	    	return true;
	    }
	    
	    return false;
	}
}