package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class DeliveredState implements OrderState{

	private String name = "teslim edildi"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		throw new IllegalStateException("Siparis teslim edildi"); // teslim edilmiş siparişte durum değişmez		
	}
	
	public String cancelOrder(Order order) {
		throw new IllegalStateException("teslim edildikten sonra iptal etme islemi olmamaktadir"); // teslim sonrası iptal yapılamaz
	}
	
	public String returnOrder(Order order) {
		order.setState(new ReturnedState()); // iade durumuna geçiş
		return "iade"; // iade durumu
	}

	@Override
	public String getName() {
		
		return this.name; // durum adı
	}
	
}