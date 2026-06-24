package com.project.mvcapp.view;

import java.util.List;

public class NotificationsView {
	
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
	
	// Bildirim listesini ekrana yazdırır
	public static void showAllNotifications(List<String> notifications) {
		clearScreen();
		for(String n:notifications) {
			System.out.println(n);
		}
		
	}

}