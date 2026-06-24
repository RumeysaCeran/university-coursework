package com.project.mvcapp.factory.Payment;

import java.util.ArrayList;

import com.project.mvcapp.model.payment.BankTransferPayment;
import com.project.mvcapp.model.payment.CreditCardPayment;
import com.project.mvcapp.model.payment.CryptoPayment;
import com.project.mvcapp.model.payment.PaymentStrategy;


public class PaymentFactory {
	
	private static ArrayList<String> paymentTypes = new ArrayList<>(); // ödeme türlerini tutan liste
	
	public PaymentFactory() {
		// desteklenen ödeme türleri listeye ekleniyor
		paymentTypes.add("kredi karti");
		paymentTypes.add("crypto");
		paymentTypes.add("para transferi");
	}
	
	// ödeme türlerini dışarıya vermek için
	public static ArrayList<String> getPaymentStrategies() {
		return paymentTypes;
	}
	
	// girilen ödeme tipine göre uygun strategy döndürülür
	public static PaymentStrategy getPaymentStrategy(String type) {
		
		String type1 = type.trim().toLowerCase(); // girilen veri normalize edilir
		
		switch(type1) {
		
		case "kredi karti": 
			return new CreditCardPayment(); // kredi kartı ödeme
		
		case "crypto": 
			return new CryptoPayment(); // kripto ödeme
		
		case "para transferi": 
			return new BankTransferPayment(); // banka transferi
		
		default:
			throw new IllegalArgumentException(); // geçersiz ödeme tipi
		}
	}
}