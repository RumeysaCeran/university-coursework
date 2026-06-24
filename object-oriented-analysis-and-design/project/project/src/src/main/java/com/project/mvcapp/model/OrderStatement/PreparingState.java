package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public class PreparingState implements OrderState{

	private String name = "hazirlaniyor"; // sipariş durumu adı
	
	@Override
	public String next(Order order) {
		order.setState(new ShippedState()); // bir sonraki durum kargoda
		return  "kargoda"; // yeni durum
		
	}
	
	
	public String cancelOrder(Order order) {
		order.setState(new CancelledState()); // sipariş iptal edilir
		return "iptal"; // iptal durumu
	}
	
	
	public String returnOrder(Order order) {
		throw new IllegalStateException("hazirlama asamasında iade islem olmamaktadir"); // bu aşamada iade yapılamaz
	}

	@Override
	public String getName() {
		 return this.name; // durum adı
	}
}