package com.project.mvcapp.command;

import java.util.ArrayList;

import com.project.mvcapp.model.User;
import com.project.mvcapp.service.business.HomeService;
import com.project.mvcapp.service.business.UserService;
import com.project.mvcapp.view.HomeView;
import com.project.mvcapp.view.UserView;

public class CreateUserCommand implements Command {

	private UserService userService; // kullanıcı işlemleri için servis
	
	private UserView userView; // kullanıcıdan veri almak için view
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut

	
	
	public CreateUserCommand() {
		this.userService = new UserService(); // user service oluşturuluyor
		this.userView = new UserView(); // user view oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}
	
	@Override
	public void execute(Object... args) {

		ArrayList<String> new_user_infos = new ArrayList<String>(); // kullanıcı bilgilerini tutmak için liste

		String name = userView.getName(); // isim alınır
		new_user_infos.add(name);

		String surname = userView.getSurname(); // soyisim alınır
		new_user_infos.add(surname);

		String email = userView.getEmail(); // email alınır
		new_user_infos.add(email);

		String password = userView.getPassword(); // şifre alınır
		new_user_infos.add(password);

		String role = userView.getRole(); // rol alınır
		new_user_infos.add(role);

		// kullanıcı bilgileri kontrol edilir
		boolean thereIsNoError = userService.signInControl(new_user_infos);

		if(!thereIsNoError)
		{
			// hata varsa hata sayfası gösterilir
			userView.signInErrorPage();
		}
		else {
			// kullanıcı oluşturulur ve kaydedilir
			User user = userService.createUser(new_user_infos);
			userService.save(user);
		}
		

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
		
	}

}