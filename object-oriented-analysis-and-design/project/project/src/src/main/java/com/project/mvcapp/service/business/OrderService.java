package com.project.mvcapp.service.business;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.model.OrderStatement.OrderState;
import com.project.mvcapp.model.OrderStatement.PendingState;

public class OrderService {

	// Siparişlerin başlangıç durumu (beklemede)
	private PendingState pendingState;
	
	public OrderService() {
		
	}
	
	// Sipariş oluşturur ve başlangıç bilgilerini set eder
	public Order createOrder(int productId, int amount, double distance) {
		int customerId = SessionService.getCurrentUser().getId();
			
		Order order = new Order();
		order.setCustomerId(customerId);
		order.setProductd(productId);
		order.setAmount(amount);
		order.setDistance(distance);
		order.setState(pendingState);

		return order;
	}
	
	// Kargo ücretini döndürür
	public double getCargoPrice(Order order) {
		return order.getCargoPrice();
	}
	
	// Ürün + kargo toplam fiyatını hesaplar
	public double getTotalPrice(int price, int cargoPrice) {
		double totalPrice = price + cargoPrice;
		return totalPrice;
	}
	
	// Sipariş durumunu günceller
	public Order setState(Order order, OrderState orderState) {
		order.setState(orderState);
		return order;
	}

	// Siparişin mevcut durumunu döndürür
	public String getState(Order order) {
		return order.getState();		
	}
	
	// Bir sonraki sipariş durumuna geçiş yapar
	public Order nextState(Order order) {
		order.nextState();
		return order;
	}
	
	// İade işlemi yapar
	public Order refund(Order order) {
		order.refund();
		return order;
	}
	
	// Siparişi iptal eder
	public Order cancel(Order order) {
		order.cancel();
		return order;
	}
	
	// Mesafe bilgisini günceller
	public Order setDistance(double distance, Order order) {
		order.setDistance(distance);	
		return order;
	}

	// Kargo fiyatını set eder ve toplamı günceller
	public Order setCargoPrice(double cargoPrice, Order order) {
		order.setCargoPrice(cargoPrice);
		order.setTotalPrice();
		return order;
	}

	// Kurye ataması yapar
	public Order setAssignedCorierId(int id, Order order) {
		order.setAssignedCourierId(id);
		return order;
	}

	// Fiyatları ve toplam tutarı hesaplar
	public Order setPrices(Order order, double cargoPrice) {
		order.setCargoPrice(cargoPrice);
		order.setPrice();
		order.setTotalPrice();
		return order;
	}
	
	// Takip numarası set eder
	public Order setTrackinNumber(Order order, String trackingNumber) {
		order.setTrackingNumber(trackingNumber);
		return order;
	}
	
	// Takip numarasını döndürür
	public String getTrackingNumber(Order order) {
		return order.getTrackingNumber();
	}
}