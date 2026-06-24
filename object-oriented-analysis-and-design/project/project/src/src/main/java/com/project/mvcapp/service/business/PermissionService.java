package com.project.mvcapp.service.business;

import java.util.ArrayList;
import com.project.mvcapp.model.Permission;

public class PermissionService {
	
	// Yetki işlemleri için servis sınıfı

	public PermissionService() {}
	
	// Kullanıcının görebileceği menü listesini döndürür
	public ArrayList<String> getPermissionMenu(){
		return AuthorizationService.getPermissionMenu();
	}
	
	// Kullanıcının sahip olduğu yetkilerin index listesini döndürür
	public ArrayList<Integer> getPermissionsIndexes(){
		ArrayList<Integer> indexes = new ArrayList<>();
		
		// AuthorizationService üzerinden tüm yetkiler alınır
		for(Permission p: AuthorizationService.getPermissions()) {
			indexes.add(p.getIndex());
		}
		
		return indexes;
	}
}