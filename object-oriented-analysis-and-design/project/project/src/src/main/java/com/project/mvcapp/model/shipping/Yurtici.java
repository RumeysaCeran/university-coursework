package com.project.mvcapp.model.shipping;

import com.project.mvcapp.model.Order;

public class Yurtici implements ShippingCarrier {

	// Yurtiçi kargo sınıfı
	
	public Yurtici() {}
	
	@Override
	public String getName() {
		
		return "Yurtici"; // kargo firma adı
	}

	@Override
	public String generateTrackingNumber(Order order) {
		return "YUR-" + order.getId(); // takip numarası oluşturma
	}

	@Override
	public double calculateBasePrice(Order order) {
		
		double basePrice = order.getWeight()*8 + order.getDistance()*2; // temel ücret
		
		if(order.isFragile()) {
			basePrice += 20; // kırılgan ürün ek ücreti
		}
		
		return basePrice; // toplam kargo ücreti
	}

}