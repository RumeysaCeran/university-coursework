package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class ApprovedState implements OrderState {

	private String name = "onaylandi"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		order.setState(new PreparingState()); // bir sonraki duruma geçiş
		return "hazirlaniyor"; // yeni durum adı
		
	}

	public String cancelOrder(Order order) {
		order.setState(new CancelledState()); // sipariş iptal durumuna alınır
		return "iptal"; // iptal durumu
		
	}
	
	public String returnOrder(Order order) {
		throw new IllegalStateException("onaylama asamasında iade islem olmamaktadir"); // bu aşamada iade yapılamaz
	}

	@Override
	public String getName() {
		
		return this.name; // mevcut durum adı
	}
}