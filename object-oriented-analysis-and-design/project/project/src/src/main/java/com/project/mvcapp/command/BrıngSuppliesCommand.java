package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.model.Permission;
import com.project.mvcapp.model.Role;
import com.project.mvcapp.service.business.SystemNotificationService;
import com.project.mvcapp.view.NotificationsView;
import com.project.mvcapp.view.ProductView;

public class BrıngSuppliesCommand implements Command {
	// depo görevlisine getirdiğine dair sistem içi bildirim gönderme işlemi
	
	private ProductView productView; // ürün ile ilgili kullanıcıdan veri almak için view
	
	private SystemNotificationService systemNotificationService; // sistem bildirim işlemleri için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public BrıngSuppliesCommand(){
		this.systemNotificationService = new SystemNotificationService(); // bildirim servisi oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.productView = new ProductView(); // ürün view oluşturuluyor
	}

	@Override
	public void execute(Object... args) {
		
		// supplier'a ait işlenmemiş bildirimler alınıyor
		List<String> unprocessedNotifications =
				systemNotificationService.readNotificationsNotProcessedYet(Role.SUPPLIER.getName());

		// bildirimler ekrana yazdırılıyor
		NotificationsView.showAllNotifications(unprocessedNotifications);

		String id;

		// doğru ürün id girilene kadar kullanıcıdan istenir
		do {
			id = productView.getProductId();	
		}
		while(!systemNotificationService.findByProductId(Role.SUPPLIER.getName(), id));

		// ürün miktarı alınır
		int amount = systemNotificationService.getProductAmount(Role.SUPPLIER.getName(), id);

		// warehouse worker'a ürünün getirildiği bilgisi gönderilir
		systemNotificationService.notify(Role.WAREHOUSE_WORKER.getName(),
				id + "," + amount + "," + "getirildi");

		// supplier tarafında ürün getirildi olarak güncellenir
		systemNotificationService.updatedBrought(Role.SUPPLIER.getName(), id);

		// işlem tamamlandı mesajı
		productView.processedCompleted(Permission.BRING_SUPPLIES.inMenu() + " tamamlandi!");
		

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	};
}