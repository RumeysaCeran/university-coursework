package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.service.business.SessionService;
import com.project.mvcapp.view.OrderView;

public class RefundCommand implements Command{
	
	private OrderFileRepository orderFileRepo; // sipariş dosya işlemleri için repository
	
	private OrderView orderView; // siparişleri kullanıcıya göstermek için view
	
	private OrderService orderService; // sipariş iade işlemleri için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public RefundCommand() {
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.orderFileRepo = new OrderFileRepository(); // repository oluşturuluyor
		this.orderView = new OrderView(); // view oluşturuluyor
		this.orderService = new OrderService(); // service oluşturuluyor
	}

	@Override
	public void execute(Object... args) {
		
		// mevcut müşteri id alınır
		int currentCustomerId = SessionService.getCurrentUser().getId();

		// kullanıcıya ait tüm siparişler listelenir
		List<String> orders = orderFileRepo.getOrdersOfUser(currentCustomerId);

		// siparişler ekrana basılır
		orderView.showAllOrders(orders);

		String trackingNumber;

		// geçerli bir sipariş seçilene kadar kullanıcıdan istenir
		do {
			trackingNumber = orderView.getTrackingNumber();

			// eğer sipariş bulunamazsa hata gösterilir
			if(orderFileRepo.findByTrackingNumber(trackingNumber, currentCustomerId) == null) {
				orderView.showError(trackingNumber + " bu takip numarasina ait siparisiniz bulunmamaktadir!");
			}

		} while(orderFileRepo.findByTrackingNumber(trackingNumber, currentCustomerId) == null);
		
		// sipariş bulunur
		Order order = orderFileRepo.findByTrackingNumber(trackingNumber, currentCustomerId);

		try {
			// iade işlemi yapılır
			order = orderService.refund(order);
		}
		catch(IllegalStateException e) {
			// iade başarısız olursa hata mesajı gösterilir
			orderView.showError(e.getMessage());
		}

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
}
