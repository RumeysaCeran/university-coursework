package com.project.mvcapp.service.business;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class EmailService {
	
	// Sisteme email gönderme işlemini dosyaya yazar
	public void send(String recevier, String topic, String message) {

	    try (FileWriter writer = new FileWriter("data/emails.txt", true)) {

	        writer.write(recevier + "," + topic + "," + message + "\r\n");

	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}
	
	// Tüm email kayıtlarını okur
	public List<String> readNotifications() {

	    try {

	        Path path = Paths.get("data/emails.txt");

	        if (!Files.exists(path)) {
	            return List.of();
	        }

	        return Files.readAllLines(path)
	                .stream()
	                .filter(line -> line.split(",").length >= 4)
	                .toList();

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
	
	// Kullanıcıya ait henüz işlenmemiş (aktif) emailleri getirir
	public List<String> readNotificationsNotBrougthYet(String email) {

	    try {

	        Path path = Paths.get("data/emails.txt");

	        if (!Files.exists(path)) {
	            return List.of();
	        }

	        return Files.readAllLines(path)
	                .stream()
	                .filter(line -> {

	                    String[] parts = line.split(",");

	                    return parts.length >= 6
	                    		&& parts[0].trim().equals(email)
	                            && parts[5].trim().startsWith("aktif");

	                })
	                .toList();

	    } catch (IOException e) {

	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
	
	// ID'ye göre email kaydı var mı kontrol eder
	public boolean findById(String id) {

	    try {
	        Path path = Paths.get("data/emails.txt");

	        if (!Files.exists(path)) {
	            return false;
	        }

	        return Files.readAllLines(path)
	                .stream()
	                .anyMatch(line -> {
	                    String[] parts = line.split(",");
	                    return parts.length >= 6
	                            && parts[3].trim().equals(id)
	                            && parts[5].trim().equalsIgnoreCase("aktif");
	                });

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
	
	// Email durumunu aktiften pasife çevirir
	public void updatedBrought(String topic) {

	    try {

	        Path path = Paths.get("data/emails.txt");

	        if (!Files.exists(path)) {
	            return;
	        }

	        List<String> updatedLines = Files.readAllLines(path)
	                .stream()
	                .map(line -> {

	                    String[] parts = line.split(",");

	                    if (parts.length >= 6
	                            && parts[1].trim().equalsIgnoreCase(topic)
	                            && parts[5].trim().equalsIgnoreCase("aktif")) {

	                        parts[5] = "pasif";
	                    }

	                    return String.join(",", parts);
	                })
	                .toList();

	        Files.write(path, updatedLines);

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya güncellenemedi", e);
	    }
	}
	
	// Email içinden ürün miktarını döndürür
	public int getProductAmount(String id) {

	    try {

	        Path path = Paths.get("data/emails.txt");

	        if (!Files.exists(path)) {
	            return 0;
	        }

	        return Files.readAllLines(path)
	                .stream()
	                .map(line -> line.split(","))
	                .filter(parts -> parts.length >= 6
	                        && parts[3].trim().equals(id)
	                        && parts[5].trim().equalsIgnoreCase("aktif"))
	                .mapToInt(parts -> Integer.parseInt(parts[4].trim()))
	                .findFirst()
	                .orElse(0);

	    } catch (IOException e) {
	        throw new RuntimeException("Dosya okunamadi", e);
	    }
	}
}