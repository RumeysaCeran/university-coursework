package com.project.mvcapp.command;

import com.project.mvcapp.controller.HomeController;
import com.project.mvcapp.service.business.SessionService;

public class LogOutCommand implements Command{
	
	private HomeController homeController; // giriş ekranına yönlendirme için controller
	
	public LogOutCommand() {
		this.homeController = new HomeController(); // home controller oluşturuluyor
	}
	
	@Override
	public void execute(Object... args) {
		
		// kullanıcı çıkış işlemi yapılır (session temizlenir)
		SessionService.logOut();

		// giriş sayfası tekrar açılır
		homeController.startPage();
	}
	
}