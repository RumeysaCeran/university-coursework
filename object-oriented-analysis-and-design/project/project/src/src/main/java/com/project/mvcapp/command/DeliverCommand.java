package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.model.Permission;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.service.business.SessionService;
import com.project.mvcapp.view.OrderView;

public class DeliverCommand implements Command{

	private OrderFileRepository orderFileRepo; // sipariş dosya işlemleri için repository
	
	private OrderView orderView; // siparişleri kullanıcıya göstermek için view
	
	private OrderService orderService; // sipariş durumlarını yönetmek için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public DeliverCommand() {
		this.orderFileRepo = new OrderFileRepository(); // repository oluşturuluyor
		this.orderView = new OrderView(); // view oluşturuluyor
		this.orderService = new OrderService(); // service oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}

	
	@Override
	public void execute(Object... args) {

		// mevcut kurye id alınır
		int currentCourierId = SessionService.getCurrentUser().getId();

		// kurye ile ilgili tüm siparişler alınır
		List<String> allOrders = orderFileRepo.findByCourierId(currentCourierId);

		// siparişler ekrana basılır
		orderView.showAllOrders(allOrders);
		
		String trackingNumber;

		// kurye kendi teslim etmediği siparişlerden birini seçene kadar tekrar sorulur
		do {
			trackingNumber = orderView.getTrackingNumber();
		}
		while(!orderFileRepo.trackingNumbersOfCouriersUndeliveredOrders(currentCourierId).contains(trackingNumber));
		
		// sipariş tracking number ile alınır
		Order order = orderFileRepo.getByTrackingNumber(trackingNumber);

		// sipariş bir sonraki duruma geçirilir (örneğin: yola çıktı -> teslim edildi)
		order = orderService.nextState(order);

		// güncel sipariş dosyaya yazılır
		orderFileRepo.update(order);

		// işlem tamamlandı mesajı
		orderView.processCompleted(Permission.DELIVER.inMenu());

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	

}