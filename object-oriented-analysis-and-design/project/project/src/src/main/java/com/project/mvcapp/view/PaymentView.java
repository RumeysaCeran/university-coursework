package com.project.mvcapp.view;

import java.util.ArrayList;
import java.util.Scanner;

public class PaymentView {
	
	private Scanner scanner = new Scanner(System.in);
	
	public PaymentView() {}
	
	// Kullanıcıdan ödeme türünü seçmesini ister
	public String getPaymentType(ArrayList<String> paymentTypes) {
		for(String p: paymentTypes) {
			System.out.println("- " + p);
		}
		System.out.print("hangi yontemle odemek istiyorsunuz? (ismini aynen yukaridaki gibi yaziniz): ");
		String paymentType = scanner.nextLine();
		return paymentType.toLowerCase();
	}

	// Ödeme başarı mesajı
	public void paymentCompleted() {
		System.out.println("Odemeniz basariyla alindi!");
		
	}
}