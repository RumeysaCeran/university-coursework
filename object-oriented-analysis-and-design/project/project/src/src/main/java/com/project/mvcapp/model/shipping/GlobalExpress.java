package com.project.mvcapp.model.shipping;

import com.project.mvcapp.model.Order;

public class GlobalExpress implements ShippingCarrier {
	
	// GlobalExpress kargo sınıfı
	
	public GlobalExpress() {}
	
	@Override
	public String getName() {
		
		return "GlobalExpress"; // kargo firma adı
	}
	
	@Override
	public String generateTrackingNumber(Order order) {
		return "GLO" + order.getId(); // takip numarası oluşturma
	}
	
	@Override
	public double calculateBasePrice(Order order) {
		
		double basePrice = order.getWeight()*3 + order.getDistance()*4; // temel kargo ücreti
		
		if(order.isFragile()) {
			basePrice += 20; // kırılgan ürün ek ücreti
		}
		
		return basePrice; // toplam ücret
	}

}