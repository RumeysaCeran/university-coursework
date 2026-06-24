package com.project.mvcapp.model.shipping;

import com.project.mvcapp.model.Order;

public interface ShippingCarrier {
		
	// kargo firmasının adını döndürür
	public String getName();
	
	// siparişe göre takip numarası üretir
	public String generateTrackingNumber(Order order);
	
	// kargo ücretini hesaplar
	double calculateBasePrice(Order order);
	
	
}
