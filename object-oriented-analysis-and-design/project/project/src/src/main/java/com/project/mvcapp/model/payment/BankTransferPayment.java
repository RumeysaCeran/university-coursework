package com.project.mvcapp.model.payment;

public class BankTransferPayment implements PaymentStrategy{

	@Override
	public String pay(int orderId, double amount) {
		
		//log islemi icin mesaj dondurulur
		return orderId + "id'li urunun" + amount + "degerindeki odemesi para transferi ile alindi.";
	}

}
