package com.project.mvcapp.service.business;

import java.util.Optional;

import com.project.mvcapp.model.Product;
import com.project.mvcapp.model.Role;

public class NotificationService {
	
	// Email gönderim işlemlerini yöneten servis
	private EmailService emailService;
	
	// Kullanıcı bilgilerine erişim sağlayan servis
	private UserService userService;
	
	// Sistem içi bildirimleri yöneten servis
	private SystemNotificationService systemNotificationService;
	
	public NotificationService() {
		this.emailService = new EmailService();
		this.systemNotificationService = new SystemNotificationService();
		this.userService = new UserService();
	}
	
	// Stok kritik seviyeye düştüğünde uyarı gönderir
	public void stockAlert(Product product) {
		Optional<String> email = userService.findByRole(Role.PAYMENT_UNIT.getName());
		int currentStock = product.getThreshold() - product.getStock();
		
		// Email ile satın alma birimine bildirim gönderilir
		emailService.send(
				email.get(),
				"Dusuk Stok!",
				"product" + "," + product.getId() + "," + currentStock + "," + "aktif"
		);
		
		// Sistem içi depo görevlisine bildirim atılır
		systemNotificationService.notify(
				"depo_gorevlisi",
				product.getId() + "," + currentStock + "," + "dusuk\n"
		);

	}
	
	// Tedarikçiye ürün talep bildirimi gönderir
	public void sendSupplier(Product product) {
		int currentStock = product.getThreshold() - product.getStock();
		
		systemNotificationService.notify(
				"tedarikci",
				product.getId() + "," + currentStock + "," + "alinmadi\n"
		);
	}
}