package com.project.mvcapp.command;

import java.util.List;
import java.util.Optional;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.view.OrderView;


public class UpdateOrderStateCommand implements Command{
	
	private OrderFileRepository orderFileRepo; // sipariş dosya işlemleri için repository
	
	private OrderView orderView; // siparişleri ekranda göstermek için view
	
	private OrderService orderService; // sipariş durumlarını güncellemek için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public UpdateOrderStateCommand() {
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.orderFileRepo = new OrderFileRepository(); // repository oluşturuluyor
		this.orderView = new OrderView(); // view oluşturuluyor
		this.orderService = new OrderService(); // service oluşturuluyor
	}
	
	@Override
	public void execute(Object... args) {
		
		// tüm siparişler dosyadan okunur
		List<String> allOrders = orderFileRepo.readFromFile();

		// siparişler ekrana basılır
		orderView.showAllOrders(allOrders);

		int id;

		// geçerli sipariş id girilene kadar tekrar sorulur
		do {
			id = orderView.getOrderId();

			// sipariş bulunamazsa uyarı gösterilir
			if(orderFileRepo.findById(id) == null) {
				orderView.showNotFoundAlert();
			}

		} while(orderFileRepo.findById(id) == null);

		// sipariş bulunur
		Optional<Order> order = orderFileRepo.findById(id);

		// sipariş bir sonraki duruma geçirilir
		order = Optional.ofNullable(orderService.nextState(order.get()));

		// güncellenmiş sipariş dosyaya yazılır
		orderFileRepo.update(order.get());

		// yeni durum ekrana yazdırılır
		orderView.showState(orderService.getState(order.get()));

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	
}