package com.project.mvcapp.service.business;

import java.io.IOException;
import java.nio.file.*;
import java.util.List;

public class LogService {

    // Sistem log dosyasını okuyan servis sınıfı
    public List<String> getLogs() {

        try {
            Path path = Paths.get("Logs.txt");

            // Log dosyası yoksa boş liste döndürülür
            if (!Files.exists(path)) {
                return List.of();
            }

            // Tüm log satırları okunarak geri döndürülür
            return Files.readAllLines(path);

        } catch (IOException e) {
            throw new RuntimeException("Loglar okunamadı", e);
        }
    }
}
