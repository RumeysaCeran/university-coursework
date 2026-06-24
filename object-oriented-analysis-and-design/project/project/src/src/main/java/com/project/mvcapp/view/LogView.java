package com.project.mvcapp.view;

import java.util.List;

public class LogView {
	
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
	
	// Log kayıtlarını ekrana yazdırır
	public void showLogs(List<String> logs){
		clearScreen();
		System.out.println("LOGS");
		for(String l:logs) {
			System.out.println(l);
		}
	}
}