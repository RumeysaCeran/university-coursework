package com.project.mvcapp.controller;

import java.util.ArrayList;

import com.project.mvcapp.service.business.CommandInvoker;
import com.project.mvcapp.service.business.PermissionService;
import com.project.mvcapp.view.PermissionView;

public class PermissionController {
	
	private PermissionService service; // yetki ve menü işlemleri için servis
	
	private PermissionView view; // yetki menüsünü ekrana basmak için view
	
	private CommandInvoker commandInvoker; // komutları çalıştırmak için invoker
	    
	
	public PermissionController() {
		this.commandInvoker = CommandInvoker.getInstance(); // singleton invoker alınır
		this.service = new PermissionService(); // permission service oluşturulur	
		this.view = new PermissionView(); // permission view oluşturulur
	}
	
	public void showPermissions() {
		
		 boolean gecersizKomutMu; // girilen komutun geçerli olup olmadığını tutar
		 
	      do {
	    	  PermissionView.clearScreen(); // ekran temizlenir
	    	  
	    	  int index = showPermissionsAndGetSelected(); // kullanıcıdan seçim alınır
	    	  
	          gecersizKomutMu = commandInvoker.executeCommand(index); // komut çalıştırılır
	          
	      } while(gecersizKomutMu); // geçersizse tekrar menü gösterilir
	}
	
	public int showPermissionsAndGetSelected() {
		
		ArrayList<String> permissions = service.getPermissionMenu(); // yetki menüsü alınır
		
		int index;	
		
		view.showPermissions(permissions); // menü ekrana basılır

		do {
			index = view.selectedPermission(); // kullanıcıdan seçim alınır
		}
		while(!service.getPermissionsIndexes().contains(index)); // geçerli seçim kontrol edilir
		
		return index; // seçilen index döndürülür
	}
	
	
}
