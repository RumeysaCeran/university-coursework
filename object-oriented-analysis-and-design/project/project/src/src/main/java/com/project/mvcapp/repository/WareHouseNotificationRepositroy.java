package com.project.mvcapp.repository;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import com.project.mvcapp.model.Role;

public class WareHouseNotificationRepositroy implements SystemNotificationRepository {
	
	@Override
	public void notify(String user, String message) {
	    // Bildirimleri dosyaya ekleyerek kaydeder (append mode)
	    try (FileWriter writer = new FileWriter("data/notifications.txt", true)) {
	        // Kullanıcı ve mesaj bilgisi virgülle ayrılarak dosyaya yazılır
	        writer.write(user.trim() + "," + message.trim() + System.lineSeparator());
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}

	@Override
	public void updatedBrought(String id) {
	    String index = String.valueOf(id);
	    try {
	        Path path = Paths.get("data/notifications.txt");
	        if (!Files.exists(path)) return;

	        List<String> lines = Files.readAllLines(path);
	        
	        // Bildirimleri güncelleyerek durum değişimi yapar
	        List<String> updatedLines = lines.stream()
	                .map(line -> {
	                    String[] parts = line.split(",");
	                    // ilgili ürün ve durum eşleşirse güncelleme yapılır
	                    if (parts.length >= 4 && parts[3].trim().equals("getirildi") && parts[1].trim().equals(index)) {
	                        parts[3] = "eklendi"; 
	                    }
	                    return String.join(",", parts);
	                })
	                .toList();

	        Files.write(path, updatedLines);
	    } catch (IOException e) {
	        throw new RuntimeException("Dosya güncellenemedi", e);
	    }
	}
	
	@Override
	public List<String> readNotifications() {
	    try {
	        Path path = Paths.get("data/notifications.txt");

	        // Dosya yoksa boş liste döndür
	        if (!Files.exists(path)) {
	            return List.of();
	        }

	        // Sadece depo görevlisine ait bildirimleri filtrele
	        return Files.readAllLines(path)
	                .stream()
	                .filter(line -> {
	                    String[] parts = line.split(",");
	                    return parts.length > 0 && parts[0].equals(Role.WAREHOUSE_WORKER.getName());
	                })
	                .toList();

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
	
	@Override
	public List<String> readNotificationsNotProcessedYet(){
		try {
	        Path path = Paths.get("data/notifications.txt");

	        // Dosya yoksa boş liste döndür
	        if (!Files.exists(path)) {
	            return List.of();
	        }

	        // Henüz işlenmemiş (getirildi) bildirimleri getir
	        return Files.readAllLines(path)
	                .stream()
	                .filter(line -> {
	                    String[] parts = line.split(",");
	                    return parts.length > 0 
	                            && parts[3].equals("getirildi") 
	                            && parts[0].equals(Role.WAREHOUSE_WORKER.getName());
	                })
	                .toList();

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}	
	
	@Override
	public boolean findByProductId(String id) {
		String index = String.valueOf(id);
		try {
	        Path path = Paths.get("data/notifications.txt");

	        if (!Files.exists(path)) {
	            return false;
	        }

	        // Belirli ürün ID’sine sahip bildirim var mı kontrol eder
	        return Files.readAllLines(path)
	                .stream()
	                .anyMatch(line -> {
	                    String[] parts = line.split(",");
	                    return parts.length > 0 && parts[1].trim().equals(index);
	                });

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
	
	@Override
	public int getProductAmount(String id) {
		String index = String.valueOf(id);
		try {
	        Path path = Paths.get("data/notifications.txt");

	        if (!Files.exists(path)) {
	            return 0;
	        }

	        // Ürün miktarını ilgili kayıt üzerinden getirir
	        return Files.readAllLines(path)
	                .stream()
	                .map(line -> line.split(","))
	                .filter(parts -> parts.length >= 4
	                        && parts[1].trim().equals(index)
	                        && parts[3].trim().equals("getirildi"))
	                .mapToInt(parts -> Integer.parseInt(parts[2].trim()))
	                .findFirst()
	                .orElse(0);

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
}