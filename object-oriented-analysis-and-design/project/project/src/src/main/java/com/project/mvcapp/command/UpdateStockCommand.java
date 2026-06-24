package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.model.Permission;
import com.project.mvcapp.repository.ProductFileRepository;
import com.project.mvcapp.service.business.StockService;
import com.project.mvcapp.view.ProductView;

public class UpdateStockCommand implements Command{
	
	private ProductFileRepository productFileRepo; // ürün dosya işlemleri için repository
	
	private ProductView productView; // ürünleri ekranda göstermek için view
	
	private StockService stockService; // stok artırma ve azaltma işlemleri için servis
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	
	public UpdateStockCommand() {
		this.productFileRepo = new ProductFileRepository(); // repository oluşturuluyor
		this.productView = new ProductView(); // view oluşturuluyor
		this.stockService = new StockService(); // stock servisi oluşturuluyor
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
	}
	
	@Override
	public void execute(Object... args) {
		
		// tüm ürünler dosyadan okunur
		List<String> allProducts = productFileRepo.readFromFile();

		// ürünler ekrana basılır
		productView.showAllProducts(allProducts);

		int id;

		// geçerli ürün id girilene kadar tekrar sorulur
		do {
			id = Integer.parseInt(productView.getProductId());			
		} while(productFileRepo.findById(id) == null);

		int choice;

		// kullanıcıdan stok artır/azalt seçimi alınır
		do {
			choice = productView.IncreaseOrDecrease();
		} while(choice == 1 || choice == 2);

		int amount;

		// miktar 0 olmasın diye kontrol edilir
		do {
			amount = productView.getAmount();
		} while(amount == 0);
		
		// stok artırma işlemi
		if(choice == 1) {
			stockService.increaseStock(id, amount);
			productView.processedCompleted(Permission.UPDATE_STOCK.inMenu());
		}
		// stok azaltma işlemi
		else if(choice == 2) {
			stockService.decreaseStock(id, amount);
		}

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	
}
}
