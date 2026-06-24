package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.service.business.SessionService;
import com.project.mvcapp.service.business.SystemNotificationService;
import com.project.mvcapp.view.NotificationsView;

public class CheckSystemNotificationsCommand implements Command{
	
	private SystemNotificationService service; // sistem bildirimlerini okumak için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public CheckSystemNotificationsCommand() {
		this.service = new SystemNotificationService(); // sistem bildirim servisi oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		
	}

	@Override
	public void execute(Object... args) {
		
		// mevcut kullanıcının rolüne göre bildirimler alınır
		List<String> notifications =
				service.readNotifications(SessionService.getCurrentUser().getRole().getName());

		// bildirimler ekrana basılır
		NotificationsView.showAllNotifications(notifications);

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	

	
}