package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class CancelledState implements OrderState {

	private String name = "iptal"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		throw new IllegalStateException("iptal edilmis sipariste durum degısımı yaplamaz"); // iptal siparişte durum değişmez
	}
	
	public String cancelOrder(Order order) {
		throw new IllegalStateException("siparis zaten iptal edilmistir"); // zaten iptal olduğu için tekrar iptal edilemez
	}
	
	public String returnOrder(Order order) {
		throw new IllegalStateException("iptal edilmis urun iade edilemez"); // iptal siparişte iade yapılmaz
	}

	@Override
	public String getName() {	
		return this.name; // durum adı döndürülür
	}

}