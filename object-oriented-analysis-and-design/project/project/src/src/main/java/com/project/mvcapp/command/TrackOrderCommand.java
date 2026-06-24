package com.project.mvcapp.command;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.service.business.SessionService;
import com.project.mvcapp.view.OrderView;

public class TrackOrderCommand implements Command{
	
	private OrderView orderView; // siparişleri göstermek için view
	
	private OrderFileRepository orderFileRepo; // siparişleri dosyadan almak için repository
	
	private SessionService session; // (kullanılmıyor ama session bilgisi için tutulmuş)
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public TrackOrderCommand() {
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.orderFileRepo = new OrderFileRepository(); // repository oluşturuluyor
		this.orderView = new OrderView(); // view oluşturuluyor
		
	}

	@Override
	public void execute(Object... args) {
		// kullanıcıya ait geçmiş siparişler gösterilir
		orderView.showPastOrders(
				orderFileRepo.getOrdersOfUser(SessionService.getCurrentUser().getId()));

		String trackingNumber;

		// geçerli tracking number girilene kadar tekrar istenir
		do {
			trackingNumber = orderView.getTrackingNumber();
		}
		while(orderFileRepo.findByTrackingNumber(trackingNumber,
				SessionService.getCurrentUser().getId()) == null);

		// sipariş bulunur
		Order order = orderFileRepo.findByTrackingNumber(trackingNumber,
				SessionService.getCurrentUser().getId());

		// siparişin durumu ekrana yazdırılır
		orderView.showOrderState(trackingNumber, order.getState());

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
}