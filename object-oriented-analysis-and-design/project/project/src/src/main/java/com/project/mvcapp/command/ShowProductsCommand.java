package com.project.mvcapp.command;

import com.project.mvcapp.model.Permission;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.repository.ProductFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.view.OrderView;
import com.project.mvcapp.view.ProductView;

public class ShowProductsCommand implements Command{
	
	private ProductFileRepository productFileRepo; // ürünleri dosyadan okumak için repository
	
	private ProductView productView; // ürünleri ekranda göstermek için view
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public ShowProductsCommand() {
		this.productFileRepo = new ProductFileRepository(); // product repository oluşturuluyor
		this.productView = new ProductView(); // product view oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	};
	
	@Override
	public void execute(Object... args) {
		
		// tüm ürünler dosyadan okunup ekrana basılır
		productView.showAllProducts(productFileRepo.readFromFile());

		// işlem tamamlandı mesajı gösterilir
		productView.processedCompleted(Permission.SHOW_PRODUCTS.inMenu());

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}

	

}