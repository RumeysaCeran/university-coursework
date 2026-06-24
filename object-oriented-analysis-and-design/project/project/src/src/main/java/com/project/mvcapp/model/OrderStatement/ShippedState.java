package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class ShippedState implements OrderState {

	private String name = "kargoda"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		order.setState(new DeliveredState()); // bir sonraki durum teslim edildi
		return "teslim edildi"; // yeni durum
		
	}
	
	public String cancelOrder(Order order) {
		throw new IllegalStateException("kargo asamasında iptal etme islemi olmamaktadir"); // kargo aşamasında iptal yok
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