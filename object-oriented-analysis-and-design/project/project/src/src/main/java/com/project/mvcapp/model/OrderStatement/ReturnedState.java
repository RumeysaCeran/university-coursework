package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class ReturnedState implements OrderState{

	private String name = "iade"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		throw new IllegalStateException("iade edilmis sipariste durum degısımı yaplamaz"); // iade edilen siparişte durum değişmez
		
	}
	
	public String cancelOrder(Order order) {
		throw new IllegalStateException("siparis zaten iade edilmistir"); // zaten iade edilmiş sipariş tekrar iptal edilemez
	}
	
	public String returnOrder(Order order) {
		throw new IllegalStateException("iade edilmis urun iade edilemez"); // iade edilmiş ürün tekrar iade edilemez
	}

	@Override
	public String getName() {
		
		return this.name; // durum adı döndürülür
	}
	
	
}