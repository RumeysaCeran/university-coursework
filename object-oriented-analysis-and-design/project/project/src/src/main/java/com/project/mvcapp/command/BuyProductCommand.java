package com.project.mvcapp.command;

import com.project.mvcapp.model.Role;
import com.project.mvcapp.service.business.EmailService;
import com.project.mvcapp.service.business.SessionService;
import com.project.mvcapp.service.business.SystemNotificationService;
import com.project.mvcapp.view.ProductView;

public class BuyProductCommand implements Command{

	private EmailService emailService; // e-posta/bildirim işlemleri için servis
	
	private ProductView productView; // kullanıcıdan ürün bilgisi almak için view
	
	private SystemNotificationService systemNotificationService; // sistem içi bildirim göndermek için
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public BuyProductCommand() {
		this.emailService = new EmailService(); // email servisi oluşturuluyor
		this.productView = new ProductView(); // ürün view oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.systemNotificationService = new SystemNotificationService(); // sistem bildirim servisi
	}

	@Override
	public void execute(Object... args) {

		// satın alınmamış ürünler ekranda gösteriliyor
		productView.showNotBoughtProducts(
				emailService.readNotificationsNotBrougthYet(SessionService.getCurrentUser().getEmail()));

		String id;

		// doğru ürün id girilene kadar kullanıcıdan istenir
		do {
			id = productView.getProductId();
		}
		while(!emailService.findById(id));

		// ürün miktarı email servisinden alınır
		int amount = emailService.getProductAmount(id);

		// tedarikçiye ürün alındı bilgisi gönderilir
		systemNotificationService.notify("tedarikci", id + "," + amount + "," + "alindi\n");

		// ürün satın alındı olarak güncellenir
		emailService.updatedBrought(id);

		// kullanıcıya mesaj gösterilir
		productView.showMessage("Urun alma islemi basariyla tamamlandi!");
		

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	
}