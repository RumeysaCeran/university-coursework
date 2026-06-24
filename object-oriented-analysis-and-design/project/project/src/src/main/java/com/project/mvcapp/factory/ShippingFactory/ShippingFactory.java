package com.project.mvcapp.factory.ShippingFactory;

import java.util.ArrayList;

import com.project.mvcapp.model.shipping.Aras;
import com.project.mvcapp.model.shipping.GlobalExpress;
import com.project.mvcapp.model.shipping.ShippingCarrier;
import com.project.mvcapp.model.shipping.Yurtici;

public class ShippingFactory {
	
	private static ArrayList<String> shippingTypes = new ArrayList<>(); // kargo türlerini tutan liste
	
	public ShippingFactory() {
		// desteklenen kargo firmaları ekleniyor
		shippingTypes.add("aras");
		shippingTypes.add("yurtici");
		shippingTypes.add("globalexpress");
	}
	
	// kargo türlerini dışarıya vermek için
	public static ArrayList<String> getShippingTypes() {
		return shippingTypes;
	}
	
	// girilen tipe göre uygun kargo firması döndürülür
	public static ShippingCarrier getCarrier(String type) {
		
		String type1 = type.toLowerCase(); // küçük harfe çevirme
		
		switch(type1) {
		
		case "aras": 
			return new Aras(); // Aras kargo
		
		case "yurtici": 
			return new Yurtici(); // Yurtiçi kargo
		
		case "globalexpress": 
			return new GlobalExpress(); // Global Express kargo
		
		default:
			throw new IllegalArgumentException(); // geçersiz kargo tipi
		}
	}
}