package com.project.mvcapp.router;

import com.project.mvcapp.controller.PermissionController;

public class AppController {
	
	// Yetkilerin (menu ekranının) yönetildiği controller
	private PermissionController permissionController;
	
	public AppController() {
		// PermissionController oluşturuluyor
		permissionController = new PermissionController();
	}
	
	// Kullanıcıya yetki menüsünü gösterir ve akışı başlatır
	public int showPermissions() {
		permissionController.showPermissions();
		return 0;
	}
	
}