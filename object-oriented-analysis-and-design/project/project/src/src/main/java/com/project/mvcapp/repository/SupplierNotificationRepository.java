package com.project.mvcapp.repository;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import com.project.mvcapp.model.Role;

public class SupplierNotificationRepository implements SystemNotificationRepository {
	
	@Override
	public void notify(String user, String message) {
	    try (FileWriter writer = new FileWriter("data/notifications.txt", true)) {
	        // sistem bildirimini dosyaya ekler
	        writer.write(user.trim() + "," + message.trim() + System.lineSeparator());
	    } catch (IOException e) {
	        e.printStackTrace(); // hata loglama
	    }
	}

	@Override
	public void updatedBrought(String id) {
	    String index = String.valueOf(id);
	    try {
	        Path path = Paths.get("data/notifications.txt");
	        if (!Files.exists(path)) return;

	        List<String> updatedLines = Files.readAllLines(path).stream()
	                .map(line -> {
	                    String[] parts = line.split(",");
	                    // ürün alındıysa durum güncellenir
	                    if (parts.length >= 4 && parts[3].trim().equals("alindi") && parts[1].trim().equals(index)) {
	                        parts[3] = "goturuldu";
	                    }
	                    return String.join(",", parts);
	                })
	                .toList();

	        Files.write(path, updatedLines); // dosyaya geri yaz
	    } catch (IOException e) {
	        throw new RuntimeException("Dosya güncellenemedi", e);
	    }
	}
	
	@Override
	public List<String> readNotifications() {
	    try {
	        Path path = Paths.get("data/notifications.txt");

	        if (!Files.exists(path)) {
	            return List.of(); // boş liste
	        }

	        return Files.readAllLines(path)
	                .stream()
	                .filter(line -> {
	                    String[] parts = line.split(",");
	                    return parts.length > 0 && parts[0].equals(Role.SUPPLIER.getName());
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

	        if (!Files.exists(path)) {
	            return List.of();
	        }

	        return Files.readAllLines(path)
	                .stream()
	                .filter(line -> {
	                    String[] parts = line.split(",");
	                    // işlenmemiş bildirimler
	                    return parts.length > 0
	                            && parts[3].equals("alindi")
	                            && parts[0].equals(Role.SUPPLIER.getName());
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

			return Files.readAllLines(path)
					.stream()
					.anyMatch(line -> {
						String[] parts = line.split(",");
						return parts.length > 0 && parts[1].trim().equals(index); // ürün id kontrolü
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

			return Files.readAllLines(path)
					.stream()
					.map(line -> line.split(","))
					.filter(parts -> parts.length >= 4
							&& parts[1].trim().equals(index)
							&& parts[3].trim().equals("alindi"))
					.mapToInt(parts -> Integer.parseInt(parts[2].trim()))
					.findFirst()
					.orElse(0);

		} catch (IOException e) {
			throw new RuntimeException("Dosya okunamadi", e);
		}
	}
}