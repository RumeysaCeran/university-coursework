package com.project.mvcapp.service.business;


import java.util.Optional;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.model.Role;
import com.project.mvcapp.model.shipping.ShippingCarrier;
import com.project.mvcapp.repository.UserFileRepository;

public class ShippingService {
	
	private ShippingCarrier carrier;
	private UserFileRepository userFiling;
	private OrderService orderService;
	
	public ShippingService() {
		this.userFiling = new UserFileRepository();
		this.orderService = new OrderService();
	}
	
	// Kargo tipini (Aras, Yurtiçi, GlobalExpress vb.) belirler
	public void setShippingType(ShippingCarrier carrier) {
		this.carrier = carrier;
	}
	
	// Sipariş için kargo ücretini hesaplar
	public double calculateCost(Order order) {
		double cargoPrice = carrier.calculateBasePrice(order);		
		return cargoPrice;
	}
	
	// Sipariş için takip numarası üretir
	public String setTrackingNumber(Order order) {
		String trackingNumber = carrier.generateTrackingNumber(order);
		return trackingNumber;
	}

	// Rastgele bir kuryeyi siparişe atama işlemi
	public int assignCourier() {
		Optional<Role> role = Role.getRoleByName("kurye");
		int id = userFiling.findByRoleGetId(role);
		return id;
	}

	// Sipariş mesafesini günceller
	public Order setDistance(double distance, Order order) {
		Order orderUpdated = orderService.setDistance(distance, order);
		return orderUpdated;
	}
}