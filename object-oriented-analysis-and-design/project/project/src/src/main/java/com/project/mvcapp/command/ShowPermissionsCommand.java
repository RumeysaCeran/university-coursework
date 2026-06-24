package com.project.mvcapp.command;

import com.project.mvcapp.router.AppController;
import com.project.mvcapp.view.PermissionView;

public class ShowPermissionsCommand implements Command{
	
	private AppController router; // sayfa yönlendirmeleri için controller
	
	private PermissionView permissionView; // kullanıcıya menü seçimi göstermek için view

	
	public ShowPermissionsCommand() {
		this.router = new AppController(); // controller oluşturuluyor
		this.permissionView = new PermissionView(); // permission view oluşturuluyor
	}
	

	@Override
	public void execute(Object... args) {

		// kullanıcıya ana menüye dönmek isteyip istemediği sorulur
		boolean goTo = permissionView.goToMainMenu();

		// eğer kullanıcı evet derse menü tekrar gösterilir
		if(goTo) {
			router.showPermissions();
		}		
	}
	
}