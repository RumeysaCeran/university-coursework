package com.project.mvcapp.model;

import java.util.Optional;

import com.project.mvcapp.model.OrderStatement.OrderState;
import com.project.mvcapp.repository.ProductFileRepository;

public class Order {
	
	private int id; // sipariş id
	
	private static int ID=0; // otomatik id üretmek için sayaç

    public static void setLastId(int id) {
        ID = id; // dışarıdan son id ayarlanabilir
    }

	private int customerId; // siparişi veren müşteri id
	
	private int assignedCourierId; // atanan kurye id
	
	private OrderState state; // sipariş durumu (state pattern)
	
	private double price=0; // ürün fiyatı
	
	private double distance; // teslimat mesafesi
	
	private double totalPrice=0; // toplam fiyat
	
	private double cargoPrice; // kargo ücreti
	
	private int productId; // ürün id
	
	private int amount; // sipariş miktarı
	
	private ProductFileRepository productFileRepo; // ürünleri dosyadan almak için repository
	
	private Optional<Product> product; // siparişe ait ürün
	
	private String trackingNumber; // sipariş takip numarası
	
	public Order() {	
		ID++; // her yeni siparişte id artırılır
		this.id = ID;
		this.productFileRepo = new ProductFileRepository(); // repository oluşturulur
		
	}
	
	public void setProductd(int id) {
		this.productId = id; // ürün id atanır
		
		this.product = productFileRepo.findById(productId); // ürün dosyadan bulunur
	}
	
	public int getProductId() {
		return this.productId;
	}
	
	public void setPrice() {
		this.product.get().getPrice(); // ürün fiyatı alınır (ama burada atama yok)
	}
	
	public double getPrice() {
		return this.price;
	}
		
	public int getCustomerId() {
		return this.customerId;
	}
	
	public void setCustomerId(int id) {
		this.customerId = id;
	}
	
	public void setAssignedCourierId(int id) {
		this.assignedCourierId = id;
	}
			
	public int getAssignedCourierId() {
		return this.assignedCourierId;
	}
	
	public double getWeight() {
		return this.product.get().getWeight(); // ürün ağırlığı
	}
	
	public boolean isFragile() {
		return this.product.get().getIsFragile(); // ürün kırılgan mı
	}
	
	public int getAmount() {
		return this.amount;
	}
	
	public void setAmount(int amount) {
		this.amount = amount;
	}

	public int getId() {	
		return this.id;
	}

	public double getDistance() {
		return this.distance;
	}
	
	public void setDistance(double distance) {
		this.distance = distance;
	}
	
	public String getState() {
		return this.state.getName(); // sipariş durum ismi
	}
	
	public void nextState() {
		state.next(this); // bir sonraki duruma geç
	}
	
	public void refund() {
		state.returnOrder(this); // iade işlemi
	}
	
	public void cancel() {
		state.cancelOrder(this); // iptal işlemi
	}
	
	public void setState(OrderState state) {
		this.state = state; // state atanır
		
	}
	
	public void setTotalPrice() {
		this.totalPrice = this.cargoPrice + this.price; // toplam fiyat hesaplanır
	}
	
	public double getTotalPrice() {
		return totalPrice;
	}
	
	public void setCargoPrice(double price) {
		this.cargoPrice = price; // kargo fiyatı atanır
	}
	
	public double getCargoPrice() {
		return this.cargoPrice;
	}

	public void setTrackingNumber(String trackingNumber) {
		this.trackingNumber = trackingNumber; // tracking numarası atanır
	}

	public String getTrackingNumber() {
		return this.trackingNumber;
	}
	
	public void setId(int id) {
	    this.id = id; // id manuel set edilir
	}
	
	public void setPrice(double price) {
	    this.price = price; // fiyat set edilir
	}
	
	public void setTotalPrice(double totalPrice) {
	    this.totalPrice = totalPrice; // toplam fiyat set edilir
	}

}