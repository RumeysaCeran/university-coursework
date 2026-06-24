package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class PendingState implements OrderState {

	private String name = "beklemede"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		order.setState(new ApprovedState()); // bir sonraki durum onaylandı
		return "onaylandi"; // durum adı
		
	}
	
	public String cancelOrder(Order order) {
		order.setState(new CancelledState()); // sipariş iptal edilir
		return "iptal"; // iptal durumu
		
	}
	
	public String returnOrder(Order order) {
		throw new IllegalStateException("bekleme asamasında iade islem olmamaktadir"); // beklemede iade yapılmaz
	}

	@Override
	public String getName() {
		return this.name; // durum adı döndürülür
	}

}