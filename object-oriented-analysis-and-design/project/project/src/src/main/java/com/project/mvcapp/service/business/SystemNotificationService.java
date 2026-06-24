package com.project.mvcapp.service.business;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

import com.project.mvcapp.model.Role;
import com.project.mvcapp.repository.SupplierNotificationRepository;
import com.project.mvcapp.repository.WareHouseNotificationRepositroy;

public class SystemNotificationService {
	
	private SupplierNotificationRepository supplierNotificationRepo;
	private WareHouseNotificationRepositroy wareHouseNotificationRepo;
	
	public SystemNotificationService() {
		this.supplierNotificationRepo = new SupplierNotificationRepository();
		this.wareHouseNotificationRepo = new WareHouseNotificationRepositroy();
	}
	
	// Sistem içi bildirimleri dosyaya ekler
	public void notify(String user, String message) {
		try(FileWriter writer = new FileWriter("data/notifications.txt", true)){
			writer.write(user+ "," + message);
		} 
		catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	// Kullanıcı tipine göre bildirimleri okur
	public List<String> readNotifications(String user) {
	    if(user.equals(Role.SUPPLIER.getName())) {
	    	return supplierNotificationRepo.readNotifications();
	    }
	    else if(user.equals(Role.WAREHOUSE_WORKER.getName())) {
	    	return wareHouseNotificationRepo.readNotifications();
	    }
	    return null;
	}
	
	// İşlenmemiş bildirimleri kullanıcı tipine göre getirir
	public List<String> readNotificationsNotProcessedYet(String user){
		if(user == Role.SUPPLIER.getName()) {
	    	return supplierNotificationRepo.readNotificationsNotProcessedYet();
	    }
	    else if(user == Role.WAREHOUSE_WORKER.getName()) {
	    	return wareHouseNotificationRepo.readNotificationsNotProcessedYet();
	    }
	    return null;
	}	
	
	// Ürün ID’sine göre bildirim var mı kontrol eder
	public boolean findByProductId(String user, String id) {	
		if(user == Role.SUPPLIER.getName()) {
	    	return supplierNotificationRepo.findByProductId(id);
	    }
	    else if(user == Role.WAREHOUSE_WORKER.getName()) {
	    	return wareHouseNotificationRepo.findByProductId(id);
	    }
		return false;
	}
	
	// Bildirimin durumunu "işlendi" olarak günceller
	public void updatedBrought(String user, String id) {
		if(user == Role.SUPPLIER.getName()) {
	    	supplierNotificationRepo.updatedBrought(id);
	    }
	    else if(user == Role.WAREHOUSE_WORKER.getName()) {
	    	wareHouseNotificationRepo.updatedBrought(id);
	    }
	}
	
	// Ürün miktarını kullanıcı tipine göre getirir
	public int getProductAmount(String user, String id) {
		if(user == Role.SUPPLIER.getName()) {
	    	return supplierNotificationRepo.getProductAmount(id);
	    }
	    else if(user == Role.WAREHOUSE_WORKER.getName()) {
	    	return wareHouseNotificationRepo.getProductAmount(id);
	    }
		return 0;
	}
	
}