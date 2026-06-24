package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.service.business.EmailService;
import com.project.mvcapp.view.NotificationsView;

public class CheckEmailsCommand implements Command{
	
	private EmailService service; // email bildirimlerini okumak için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public CheckEmailsCommand() {
		this.service = new EmailService(); // email servisi oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}

	@Override
	public void execute(Object... args) {
		
		// sistemdeki tüm email bildirimleri okunur
		List<String> emails = service.readNotifications();

		// emailler ekrana listelenir
		NotificationsView.showAllNotifications(emails);

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	


}
