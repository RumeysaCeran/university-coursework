package com.project.mvcapp.service.business;

import java.util.Optional;

import com.project.mvcapp.model.Product;
import com.project.mvcapp.repository.ProductFileRepository;

public class StockService {
	
	private NotificationService notificationService;	
	private ProductFileRepository productFileRepo;
	
	public StockService() {
		this.notificationService = new NotificationService();
		this.productFileRepo = new ProductFileRepository();
	}
	
	// Stok miktarını azaltır ve kritik seviyenin altına düşerse bildirim gönderir
	public void decreaseStock(int id, int amount) {
		
		Optional<Product> product = productFileRepo.findById(id);
		product.get().setStock(product.get().getStock()-amount);
		
		if(product.get().getStock() < product.get().getThreshold()) {
			notificationService.stockAlert(product.get());
		}
		
		productFileRepo.update(product.get());
	}
	
	// Stok miktarını artırır ve günceller
	public void increaseStock(int id, int amount) {
		Optional<Product> product = productFileRepo.findById(id);
		product.get().setStock(product.get().getStock()+amount);
		productFileRepo.update(product.get());
	}
}