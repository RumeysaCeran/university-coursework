package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.service.business.UserService;
import com.project.mvcapp.view.UserView;

public class ShowUsersCommand implements Command{

	
	private UserService userService; // kullanıcı işlemleri için servis
	
	private UserView userView; // kullanıcıları ekranda göstermek için view
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public ShowUsersCommand() {
		this.userService = new UserService(); // user service oluşturuluyor
		this.userView = new UserView(); // user view oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}
	
	@Override
	public void execute(Object... args) {
		
		// sistemdeki tüm kullanıcılar alınır
		List<String> users = userService.showUsers();

		// kullanıcılar ekrana yazdırılır
		userView.showAllUsers(users);

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
		
	}

	
}
