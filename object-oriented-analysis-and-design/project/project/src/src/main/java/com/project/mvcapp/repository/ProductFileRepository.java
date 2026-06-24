package com.project.mvcapp.repository;

import java.util.ArrayList;
import java.util.List;

import com.project.mvcapp.model.CompositeProduct;
import com.project.mvcapp.model.Product;
import com.project.mvcapp.model.SimpleProduct;

public class ProductFileRepository extends FileRepository<Product> {
	
	public ProductFileRepository() {
		super("data/Products.txt"); // ürün dosya yolu
		
		List<Product> all = findAll(); // tüm ürünleri oku

		int maxId = all.stream()
		            .mapToInt(Product::getId)
		            .max()
		            .orElse(0); // en büyük id

		Product.setLastId(maxId); // id güncelle
	}

	@Override
	protected String toLine(Product product) {
		String product_string = product.getId() + "," + product.getName() + "," +
			product.getStock() + "," + product.getWeight() + "," +
			product.getFragile() + "," + product.getPrice() + "," +
			product.getThreshold(); // temel ürün bilgileri

		if (product.getChildren() != null) {
			for (Product p : product.getChildren()) {
				product_string += ","; // child ürün ekleniyor
				product_string += p.getId();
			}
		}
		return product_string;
	}

	@Override
	protected Product fromLine(String line) {
		String[] parts = line.split(",");

		boolean isFragile = false;

		if (parts[4].trim().equals("kirilabilir")) {
			isFragile = true;
		} else if (parts[4].trim().equals("kirilmaz")) {
			isFragile = false;
		} else {
			System.out.println("hata var"); // veri hatası
		}

		int id = Integer.parseInt(parts[0].trim());
		int stock = Integer.parseInt(parts[2].trim());
		double weight = Double.parseDouble(parts[3].trim());
		double price = Double.parseDouble(parts[5].trim());
		int threshold = Integer.parseInt(parts[6].trim());

		if (parts.length == 7) {
			SimpleProduct product = new SimpleProduct(parts[1], stock, threshold, isFragile, weight, price);
			product.setIsFragile(isFragile); // kırılganlık
			product.setId(id); // id
			return product;
		} else {
			List<Product> children = new ArrayList<>();

			for (int i = 7; i < parts.length; i++) {
				children.add(getByName(parts[i])); // child ürün ekleme
			}

			CompositeProduct product = new CompositeProduct(parts[1], stock, threshold, children);
			product.setId(id);
			product.setWeight(weight);
			product.setPrice(price);
			product.setFragile(isFragile);
			return product;
		}
	}

	public Product getByName(String name) {
		List<Product> all = findAll();

		for (Product product : all) {
			if (product.getName().equals(name)) {
				return product; // isimle ürün bulma
			}
		}
		return null;
	}

	@Override
	protected int getId(Product product) {
		return product.getId(); // id döndür
	}
}