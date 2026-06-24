package com.project.mvcapp.model;

import java.util.List;

public abstract class Product {
	
	private static int ID=0; // ürünler için otomatik id sayacı
	
	private int id; // ürün id
	
	protected String name; // ürün adı
	
	protected int stock; // ürün stok miktarı
	
	private int threshold; // stok alt sınırı
	
	protected double weight; // ürün ağırlığı
	
	protected double price; // ürün fiyatı
	
	protected boolean isFragile; // ürün kırılgan mı
	
	 public static void setLastId(int id) {
	        ID = id; // dışarıdan id resetleme için
	    }

	
	public Product(String name, int stock, int threshold) {
		ID++; // her yeni üründe id artar
		this.id = ID;
		this.name = name;
		this.stock = stock;
		this.threshold = threshold;
	}
	
	public int getThreshold() {
		return this.threshold;
	}
	
	public void setThreshold(int threshold) {
		this.threshold = threshold;
	}
	
	public int getId() {
		return this.id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public String getName() {
		return this.name;
	};
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setStock(int stock) {
		this.stock = stock;
	}
	
	public int getStock() {
		return this.stock;
	}
	
	// alt sınıflar tarafından implement edilecek metodlar
	public abstract double getWeight();
	public abstract String getFragile();
	public abstract boolean getIsFragile();
	public abstract void add(int amount);
	public abstract void remove(int amount);
	public abstract double getPrice();
	public abstract List<Product> getChildren();
	
}