package com.project.mvcapp.model.shipping;

import com.project.mvcapp.model.Order;

public class Aras implements ShippingCarrier {
	
	// Aras kargo sınıfı
	
	public Aras() {}
	
	@Override
	public String getName() {
		return "Aras"; // kargo firması adı
	}

	@Override
	public String generateTrackingNumber(Order order) {
		return "ARAS-" + order.getId(); // siparişe özel takip numarası oluşturma
	}

	@Override
	public double calculateBasePrice(Order order) {
		double basePrice = order.getWeight()*5 + order.getDistance()*3; // temel fiyat hesaplama
		
		if(order.isFragile()) {
			basePrice += 20; // kırılgan ürün için ekstra ücret
		}
		
		return basePrice; // toplam kargo ücreti
	}
	
}