package com.project.mvcapp.service.business;

import java.util.ArrayList;
import java.util.Set;

import com.project.mvcapp.model.Permission;
import com.project.mvcapp.model.User;

public class AuthorizationService {
	
	// Kullanıcının görebileceği menü seçenekleri
	private static ArrayList<String> permissionMenu = new ArrayList<>();
	
	// Kullanıcının rolüne bağlı izin seti
	private static Set<Permission> permissions;
	
	// Menü başlığında gösterilecek kullanıcı adı
	private static String user_name;

	public AuthorizationService(User user) {
		// Kullanıcının rolüne göre yetkiler atanır
		permissions = user.getRole().getPermissions();
		user_name = user.getName();
	}
	
	public static Set<Permission> getPermissions() {
		return permissions;
	}
	  
	public static ArrayList<String> getPermissionMenu(){
		
		// Menü her çağrıldığında sıfırlanır
		permissionMenu.clear();
		
		// Menü üst başlık oluşturulur
		String topBar1 = "*****************************************************************************\n";
		String topBar2= "HOSGELDİNİZ " + user_name.toUpperCase() + " !" + "\n";
		String topBar3= "*****************************************************************************\n";
		String fullTopBar = topBar1 + topBar2 + topBar3;
		
		permissionMenu.add(fullTopBar);
		
		// Kullanıcının ana menüde görebileceği izinler eklenir
		for(Permission p:permissions) {
			if(p.isInMainMenu()) {
				String permission = p.getIndex() + "- " + p.inMenu() + "\n";
				permissionMenu.add(permission);
			}
		}	
		
		return permissionMenu;
	}
}