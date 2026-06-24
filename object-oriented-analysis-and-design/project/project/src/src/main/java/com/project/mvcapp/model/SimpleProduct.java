package com.project.mvcapp.model;

import java.util.List;

public class SimpleProduct extends Product{
	
	protected boolean isFragile; // ürün kırılgan mı bilgisi
	
	public SimpleProduct(String name, int stock, int threshold, boolean isFragile, double weight, double price) {
		super(name, stock, threshold); // üst sınıf constructor çağrılır
		super.price = price; // fiyat atanır
		super.weight = weight; // ağırlık atanır
		this.stock = stock; // stok bilgisi atanır
		this.isFragile = isFragile; // kırılganlık bilgisi atanır
	}
	
	
	public void setPrice(double price) {
		this.price = price; // fiyat güncelleme
	}

	public void setIsFragile(boolean isFragile) {
		this.isFragile = isFragile; // kırılganlık güncelleme
	};
	
	@Override
	public String getFragile() {
		
		// kırılganlık durumuna göre string döner
		if(this.isFragile) {
			return "kirilabilir";
		}else {
			return "kirilmaz";
		}
	}

	@Override
	public boolean getIsFragile() {
		return isFragile; // kırılgan mı kontrolü
	}

	@Override
	public void add(int amount) {
		this.stock += amount; // stok artırma
	}

	@Override
	public void remove(int amount) {
		this.stock -= amount; // stok azaltma
	}


	@Override
	public double getPrice() {
		return this.price; // ürün fiyatı
	}

	public double getWeight() {
		return this.weight; // ürün ağırlığı
	}


	@Override
	public List<Product> getChildren() {
		return null; // simple product olduğu için child yok
	}


	public void setWeight(double weight) {
		this.weight = weight; // ağırlık güncelleme
	}
	
	
}