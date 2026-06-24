package com.project.mvcapp.service.business;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.model.OrderStatement.ApprovedState;
import com.project.mvcapp.model.payment.PaymentStrategy;
import com.project.mvcapp.util.Logger;

public class PaymentService {
	
	// Ödeme stratejisini (kredi kartı, crypto vb.) temsil eder
	private PaymentStrategy paymentStrategy;
	
	// Sipariş işlemlerini yöneten servis
	private OrderService orderService;
	
	
	public PaymentService() {
		this.orderService = new OrderService();
	}
	
	// Ödeme işlemini gerçekleştirir ve sipariş durumunu günceller
	public Order pay(Order order) {
		String message = paymentStrategy.pay(order.getId(), order.getTotalPrice());
		
		// Ödeme başarılı olduktan sonra sipariş onaylanır
		Order orderUpdated = orderService.setState(order, new ApprovedState());
		
		// Loglama işlemi yapılır
		Logger logger = Logger.getInstance();
		logger.log(message);
		
		return orderUpdated;
	}

	// Kullanılacak ödeme yöntemini belirler
	public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
		this.paymentStrategy = paymentStrategy;
	}
	
}