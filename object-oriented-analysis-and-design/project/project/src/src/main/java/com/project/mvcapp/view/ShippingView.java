package com.project.mvcapp.view;

import java.util.ArrayList;
import java.util.Scanner;

public class ShippingView {
	
	// Kullanıcı girişlerini almak için Scanner nesnesi
	private Scanner scanner = new Scanner(System.in);
	
	// Constructor
	public ShippingView() {}
	
	// Kullanıcıya kargo firmalarını gösterir ve seçim yaptırır
	public String getShippingType(ArrayList<String> shippingTypes) {
		for(String s:shippingTypes) {
			System.out.println("- " + s);
		}
		
		System.out.print("hangi kargo firmasini istiyorsunuz?(ismini yaziniz): ");
		
		String shippingCarrier = scanner.next();
		
		return shippingCarrier.toLowerCase();
	}
	
	// Kullanıcıdan mesafe bilgisini kilometre cinsinden alır
	public double getDistance() {
		System.out.println("Uzaklıgınızı kilometre cinsinden yazınız: ");
		
		double distance = scanner.nextDouble();
		
		return distance;
	}
}