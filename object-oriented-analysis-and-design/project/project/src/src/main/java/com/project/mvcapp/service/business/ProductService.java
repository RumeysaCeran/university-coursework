package com.project.mvcapp.service.business;

import java.util.List;
import java.util.Optional;

import com.project.mvcapp.model.Product;
import com.project.mvcapp.repository.ProductFileRepository;

public class ProductService {
	
	// Ürün dosya işlemlerini yöneten repository
	private ProductFileRepository productFiling;
	
	public ProductService() {
		productFiling = new ProductFileRepository();
	}
	
	// Dosyadaki tüm ürünleri string olarak döndürür
	public List<String> getProducts(){
		List<String> products = productFiling.readFromFile();
		return products;
	}
	
	// Ürün stoğunu artırır ve günceller
	public void addProduct(String id, int amount) {
		int sayi = Integer.parseInt(id);
		
		// Ürün bulunur ve stok güncellenir
		Optional<Product> product = productFiling.findById(sayi);
		product.get().add(amount);
		
		// Güncellenmiş ürün tekrar dosyaya yazılır
		productFiling.update(product.get());
	}
}