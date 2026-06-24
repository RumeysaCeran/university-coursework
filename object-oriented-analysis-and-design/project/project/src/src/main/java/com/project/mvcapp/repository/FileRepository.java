package com.project.mvcapp.repository;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public abstract class FileRepository<T> {

    protected final String filePath; // dosya yolu

    public FileRepository(String filePath) {
        this.filePath = filePath; // repository hangi dosyayı kullanacak
    }

    protected abstract String toLine(T entity); // nesneyi dosya satırına çevirir
    protected abstract T fromLine(String line); // dosya satırını nesneye çevirir
    protected abstract int getId(T entity); // entity id bilgisini döndürür

    // ------------------------------------------------------------------ //
    //  Dosya I/O
    // ------------------------------------------------------------------ //

    public List<String> readFromFile() {
        Path path = Paths.get(filePath); // dosya yolu oluşturulur
        if (!Files.exists(path)) {
            return new ArrayList<>(); // dosya yoksa boş liste döner
        }
        try {
            return new ArrayList<>(Files.readAllLines(path)); // dosya satırlarını okur
        } catch (IOException e) {
            throw new RuntimeException("Dosya okunamadı: " + filePath, e); // hata fırlatır
        }
    }

    protected void writeToFile(List<String> lines) {
        try {
            Path path = Paths.get(filePath); // dosya yolu
            Files.write(
                    path,
                    lines,
                    StandardOpenOption.CREATE,
                    StandardOpenOption.TRUNCATE_EXISTING // dosya içeriğini silip yeniden yazar
            );
        } catch (IOException e) {
            throw new RuntimeException("Dosya yazılamadı: " + filePath, e); // hata fırlatır
        }
    }

    public void appendToFile(String line) {
        try {
            Path path = Paths.get(filePath); // dosya yolu
            Files.write(
                    path,
                    List.of(line),
                    StandardOpenOption.CREATE,
                    StandardOpenOption.APPEND // dosyaya ekleme yapar
            );
        } catch (IOException e) {
            throw new RuntimeException("Dosyaya ekleme yapılamadı: " + filePath, e); // hata fırlatır
        }
    }

    // ------------------------------------------------------------------ //
    //  CRUD
    // ------------------------------------------------------------------ //

    public List<T> findAll() {
        List<String> lines = readFromFile(); // tüm satırları alır
        List<T> result = new ArrayList<>();

        for (String line : lines) {
            if (line == null || line.isBlank()) {
                continue; // boş satırları atla
            }
            result.add(fromLine(line)); // nesneye çevirip listeye ekle
        }
        return result;
    }

    public Optional<T> findById(int id) {
        return findAll().stream()
                .filter(entity -> getId(entity) == id) // id eşleşen kaydı bulur
                .findFirst();
    }

    public void save(T entity) {
        appendToFile(toLine(entity)); // yeni kayıt ekler
    }

    public void update(T updatedEntity) {
        List<T> all = findAll(); // tüm kayıtları alır
        List<String> updated = new ArrayList<>();

        for (T entity : all) {
            if (getId(entity) == getId(updatedEntity)) {
                updated.add(toLine(updatedEntity)); // güncellenen kayıt
            } else {
                updated.add(toLine(entity)); // diğer kayıtlar
            }
        }

        writeToFile(updated); // dosyayı günceller
    }

    public void delete(int id) {
        List<T> all = findAll(); // tüm kayıtları alır
        List<String> updated = new ArrayList<>();

        for (T entity : all) {
            if (getId(entity) != id) {
                updated.add(toLine(entity)); // silinmeyenleri ekle
            }
        }

        writeToFile(updated); // dosyayı yeniden yazar
    }
}