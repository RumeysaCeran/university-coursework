package com.project.mvcapp.model.OrderStatement;

import com.project.mvcapp.model.Order;

public interface OrderState {
	
	// sipariş durum adını döndürür
	String getName();
	
	// bir sonraki sipariş durumuna geçiş işlemi
	String next(Order order);
	
	// siparişi iptal etme işlemi
	String cancelOrder(Order order);
	
	// siparişi iade etme işlemi
	String returnOrder(Order order);
		
}