package com.project.mvcapp.repository;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import com.project.mvcapp.model.Order;
import com.project.mvcapp.model.OrderStatement.ApprovedState;
import com.project.mvcapp.model.OrderStatement.CancelledState;
import com.project.mvcapp.model.OrderStatement.DeliveredState;
import com.project.mvcapp.model.OrderStatement.OrderState;
import com.project.mvcapp.model.OrderStatement.PendingState;
import com.project.mvcapp.model.OrderStatement.ReturnedState;
import com.project.mvcapp.model.OrderStatement.ShippedState;

public class OrderFileRepository extends FileRepository<Order> {
	public OrderFileRepository() {
		super("data/Orders.txt"); // order dosya yolu
		
		List<Order> all = findAll(); // tüm siparişleri okur

		int maxId = all.stream()
		            .mapToInt(Order::getId)
		            .max()
		            .orElse(0); // en büyük id bulunur

		Order.setLastId(maxId); // id resetlenir
	}

	@Override
	protected String toLine(Order order) {
		return order.getId() + "," + order.getTrackingNumber() + "," + order.getCustomerId() + "," +
		       order.getAssignedCourierId() + "," + order.getProductId() + "," + order.getState() + "," +
		       order.getAmount() + "," + order.getDistance() + "," + order.getPrice() + "," +
		       order.getCargoPrice() + "," + order.getTotalPrice(); // dosyaya yazılacak format
	}

	@Override
	protected Order fromLine(String line) {

	    String[] parts = line.split(","); // satır parçalanır

	    Order order = new Order(); // yeni order oluşturulur

	    order.setTrackingNumber(parts[1].trim()); // tracking number

	    order.setCustomerId(Integer.parseInt(parts[2].trim())); // müşteri id

	    order.setAssignedCourierId(Integer.parseInt(parts[3].trim())); // kargo id

	    order.setProductd(Integer.parseInt(parts[4].trim())); // ürün id

	    String state = parts[5].trim(); // durum bilgisi

	    switch(state) {
	        case "onaylandi":
	            order.setState(new ApprovedState()); // onaylandı durumu
	            break;

	        case "hazirlaniyor":
	            order.setState(new PendingState()); // beklemede
	            break;

	        case "kargoda":
	            order.setState(new ShippedState()); // kargoda
	            break;

	        case "teslim edildi":
	            order.setState(new DeliveredState()); // teslim edildi
	            break;

	        case "iade":
	            order.setState(new ReturnedState()); // iade
	            break;

	        case "iptal":
	            order.setState(new CancelledState()); // iptal
	            break;

	        default:
	            throw new IllegalArgumentException("Gecersiz state: " + state); // hata
	    }

	    order.setAmount(Integer.parseInt(parts[6].trim())); // adet

	    order.setDistance(Double.parseDouble(parts[7].trim())); // mesafe

	    order.setCargoPrice(Double.parseDouble(parts[9].trim())); // kargo ücreti

	    order.setId(Integer.parseInt(parts[0].trim())); // id

	    order.setPrice(Double.parseDouble(parts[8].trim())); // ürün fiyatı

	    order.setTotalPrice(Double.parseDouble(parts[10].trim())); // toplam fiyat

	    return order;
	}

	@Override
	protected int getId(Order order) {
		return order.getId(); // id döndür
	}

	public List<String> getOrdersOfUser(int userId) {
		String id = String.valueOf(userId);
		try {
			Path path = Paths.get(filePath);

			if (!Files.exists(path)) {
				return List.of(); // dosya yoksa boş liste
			}

			return Files.readAllLines(path)
					.stream()
					.filter(line -> {
						String[] parts = line.split(",");
						if (parts.length < 2) return false;
						return parts[2].equals(id); // kullanıcıya ait sipariş
					})
					.toList();

		} catch (IOException e) {
			throw new RuntimeException("Dosya okunamadı", e); // hata
		}
	}

	public List<String> findByCourierId(int id) {
		String index = String.valueOf(id);
		try {
			Path path = Paths.get(filePath);

			if (!Files.exists(path)) {
				return List.of(); // boş
			}

			return Files.readAllLines(path)
					.stream()
					.filter(line -> {
						String[] parts = line.split(",");
						return parts.length > 5
							&& parts[3].equals(index)
							&& parts[5].equals("kargoda"); // kargoda olan siparişler
					})
					.toList();

		} catch (IOException e) {
			throw new RuntimeException("Dosya okunamadi", e); // hata
		}
	}

	public List<String> trackingNumbersOfCouriersUndeliveredOrders(int id) {
		List<Order> all = findAll();
		List<String> trackingNumbers = new ArrayList<>();

		for (Order order : all) {
			if (order.getAssignedCourierId() == id
					&& order.getState().equals("kargoda")) {
				trackingNumbers.add(order.getTrackingNumber()); // teslim edilmemiş siparişler
			}
		}
		return trackingNumbers;
	}

	public Order findByTrackingNumber(String trackingNumber, int customerId) {
		List<Order> all = findAll();

		for (Order order : all) {
			if (order.getTrackingNumber().equals(trackingNumber)
					&& order.getCustomerId() == customerId) {
				return order; // sipariş bulundu
			}
		}
		return null; // bulunamadı
	}

	public Order getByTrackingNumber(String trackingNumber) {
		List<Order> all = findAll();

		for (Order order : all) {
			if (order.getTrackingNumber().equals(trackingNumber)) {
				return order; // sipariş bulundu
			}
		}
		return null; // yok
	}
}