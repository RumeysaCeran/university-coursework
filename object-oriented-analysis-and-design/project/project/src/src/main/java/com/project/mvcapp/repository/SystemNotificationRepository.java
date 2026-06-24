package com.project.mvcapp.repository;

import java.util.List;

public interface SystemNotificationRepository {
	
	// sistem içi bildirim ekleme işlemi
	public void notify(String user, String message);
	
	// tüm bildirimleri okuma işlemi
	public List<String> readNotifications();
	
	// işlenmemiş bildirimleri okuma işlemi
	public List<String> readNotificationsNotProcessedYet();
	
	// ürün id'ye göre bildirim var mı kontrolü
	public boolean findByProductId(String id);
	
	// ürün getirildi olarak güncelleme işlemi
	public void updatedBrought(String id);

	// ürün miktarını alma işlemi
	int getProductAmount(String id);
	
}