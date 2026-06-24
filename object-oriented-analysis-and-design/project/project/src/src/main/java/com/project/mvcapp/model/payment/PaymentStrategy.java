package com.project.mvcapp.model.payment;

public interface PaymentStrategy {
	public String pay(int orderId, double amount);

}
