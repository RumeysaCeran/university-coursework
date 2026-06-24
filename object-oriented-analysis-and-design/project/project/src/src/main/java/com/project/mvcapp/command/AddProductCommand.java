package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.model.Permission;
import com.project.mvcapp.model.Role;
import com.project.mvcapp.service.business.StockService;
import com.project.mvcapp.service.business.SystemNotificationService;
import com.project.mvcapp.view.NotificationsView;
import com.project.mvcapp.view.ProductView;

public class AddProductCommand implements Command{
	
	private ProductView productView; // ürün ekranı ile ilgili işlemler için view
	
	private StockService stockService; // stok artırma/azaltma işlemleri için servis
	
	private SystemNotificationService systemNotificationService; // bildirim işlemleri için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public AddProductCommand() {
		this.systemNotificationService= new SystemNotificationService(); // bildirim servisi oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.productView = new ProductView(); // ürün view oluşturuluyor
		this.stockService = new StockService(); // stok servisi oluşturuluyor
	};

	@Override
	public void execute(Object... args) {
		List<String> unprocessedNotifications = systemNotificationService.readNotificationsNotProcessedYet(Role.WAREHOUSE_WORKER.getName()); // işlenmemiş bildirimleri alır
		
		NotificationsView.showAllNotifications(unprocessedNotifications); // bildirimleri ekrana basar
		
		String id;
		do {
			id = productView.getProductId();	// kullanıcıdan ürün id alınır
		}while(!systemNotificationService.findByProductId(Role.WAREHOUSE_WORKER.getName(),id)); // id doğru olana kadar tekrar ister
		
		int amount = systemNotificationService.getProductAmount(Role.SUPPLIER.getName(),id); // supplier’dan gelen ürün miktarı alınır
		
		stockService.increaseStock(Integer.parseInt(id),amount); // stok artırılır
		
		systemNotificationService.updatedBrought(Role.WAREHOUSE_WORKER.getName(),id); // ürün getirildi olarak güncellenir
		
		productView.processedCompleted(Permission.ADD_PRODUCT.inMenu() + " tamamlandi!"); // işlem tamamlandı mesajı verilir
		

		permissionCommand.execute(); // yetkiler tekrar gösterilir
	}
}