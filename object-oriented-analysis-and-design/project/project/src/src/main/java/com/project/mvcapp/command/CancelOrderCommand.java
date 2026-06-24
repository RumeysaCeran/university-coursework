package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.service.business.SessionService;
import com.project.mvcapp.view.OrderView;

public class CancelOrderCommand implements Command{
	
	private OrderFileRepository orderFileRepo; // sipariş dosya işlemleri için repository
	
	private OrderView orderView; // siparişleri kullanıcıya göstermek için view
	
	private OrderService orderService; // sipariş iş kuralları için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public CancelOrderCommand() {
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}
	
	
	
	@Override
	public void execute(Object... args) {
		
		// mevcut kullanıcı id alınır
		int currentCustomerId = SessionService.getCurrentUser().getId();

		// kullanıcıya ait siparişler dosyadan alınır
		List<String> orders = orderFileRepo.getOrdersOfUser(currentCustomerId);

		// siparişler ekrana basılır
		orderView.showAllOrders(orders);

		String trackingNumber;

		// geçerli takip numarası girilene kadar tekrar istenir
		do {
			trackingNumber = orderView.getTrackingNumber();

			// sipariş yoksa hata mesajı gösterilir
			if(orderFileRepo.findByTrackingNumber(trackingNumber, currentCustomerId) == null) {
				orderView.showError(trackingNumber + " bu takip numarasina ait siparisiniz bulunmamaktadir!");
			}

		} while(orderFileRepo.findByTrackingNumber(trackingNumber, currentCustomerId) == null);
		
		// sipariş bulunur
		Order order = orderFileRepo.findByTrackingNumber(trackingNumber, currentCustomerId);

		try {
			// sipariş iptal işlemi yapılır
			order = orderService.cancel(order);
		}
		catch(IllegalStateException e) {
			// iptal edilemezse hata mesajı gösterilir
			orderView.showError(e.getMessage());
		}

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
		
	}
}