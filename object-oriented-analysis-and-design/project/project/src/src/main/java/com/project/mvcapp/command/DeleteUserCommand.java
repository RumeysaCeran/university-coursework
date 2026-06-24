package com.project.mvcapp.command;



import com.project.mvcapp.service.business.UserService;
import com.project.mvcapp.view.UserView;

public class DeleteUserCommand implements Command {
	
	private UserService userService; // kullanıcı işlemleri için servis
	
	private UserView userView; // kullanıcıdan veri almak için view
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public DeleteUserCommand() {
		this.userService = new UserService(); // user service oluşturuluyor
		this.userView = new UserView(); // user view oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}
	
	@Override
	public void execute(Object... args) {

		int id = userView.getId(); // kullanıcıdan id alınır

		// geçerli bir kullanıcı bulunana kadar tekrar sorulur
		do {
			id = userView.getId();
		} while(userService.findById(id) == null);

		// kullanıcı silinir
		userService.deleteUser(id);

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	

	
}