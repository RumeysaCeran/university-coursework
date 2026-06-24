package com.project.mvcapp.model;

import java.util.List;

public class CompositeProduct extends Product {
	
	private List<Product> simpleProducts; // içindeki alt ürünleri tutan liste
	
	
	public CompositeProduct(String name, int stock, int threshold, List<Product> products) {
		super(name, stock, threshold); // üst sınıf (Product) constructor çağrısı
		this.simpleProducts = products; // alt ürünler atanıyor
	}
	
	@Override
	public List<Product> getChildren(){
		return simpleProducts; // alt ürünleri döndürür
	}
	
	@Override
	public String getFragile() {
		
		// eğer içindeki ürünlerden biri kırılgansa "kırılabilir" döner
		for(Product p : simpleProducts) {
			if(p.getIsFragile()) {
				return "kirilabilir";
			}
		}
		return "kirilmaz"; // hiçbiri kırılgan değilse
	}


	@Override
	public boolean getIsFragile() {
		
		// içindeki ürünlerden en az biri kırılgansa true döner
		for(Product p : simpleProducts) {
			if(p.getIsFragile()) {
				return true;
			}
		}
		return false; // hiçbiri kırılgan değilse false
	}


	@Override
	public void add(int amount) {
		
		// tüm alt ürünlerin stoğu artırılır
		for(Product p : simpleProducts) {
			p.add(amount);
		}
		
	}


	@Override
	public void remove(int amount) {
		
		// tüm alt ürünlerin stoğu azaltılır
		for(Product p : simpleProducts) {
			p.remove(amount);
		}
		
	}


	@Override
	public double getPrice() {
		
		double price = 0;
		
		// tüm alt ürünlerin fiyatı toplanır
		for(Product p : simpleProducts) {
			price += p.getPrice();
		}
		
		return price;
	}


	@Override
	public double getWeight() {
		
		double weight = 0;
		
		// tüm alt ürünlerin ağırlığı toplanır
		for(Product p : simpleProducts) {
			weight += p.getWeight();
		}
		
		return weight;
	}

	public void setWeight(double weight) {
		super.weight = weight; // üst sınıftaki weight alanı set edilir
	}
	
	public void setPrice(double price) {
		super.price = price; // üst sınıftaki price alanı set edilir
	}
	
	public void setFragile(boolean isFragile) {
		super.isFragile = isFragile; // kırılganlık bilgisi set edilir
	}
	
}