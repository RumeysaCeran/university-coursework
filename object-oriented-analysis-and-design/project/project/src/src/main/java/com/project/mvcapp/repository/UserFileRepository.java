package com.project.mvcapp.repository;

import com.project.mvcapp.model.Role;
import com.project.mvcapp.model.User;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Random;

public class UserFileRepository extends FileRepository<User> {

    public UserFileRepository() {
        super("data/Users.txt"); // kullanıcı dosya yolu
        List<User> all = findAll(); // tüm kullanıcıları oku

        int maxId = all.stream()
                .mapToInt(User::getId)
                .max()
                .orElse(0); // en büyük id

        User.setLastId(maxId); // id güncelle
    }

    // ------------------------------------------------------------------ //
    //  Mapping
    // ------------------------------------------------------------------ //

    @Override
    protected String toLine(User user) {
        return user.getId()
                + ","
                + user.getName()
                + ","
                + user.getSurname()
                + ","
                + user.getRole().getName()
                + ","
                + user.getEmail()
                + ","
                + user.getPassword(); // dosyaya yazma formatı
    }

    @Override
    protected User fromLine(String line) {
        String[] parts = line.split(",");

        if (parts.length < 6) {
            throw new IllegalArgumentException("Hatalı satır: " + line); // veri hatası
        }

        Role role = Role.getRoleByName(parts[3])
                .orElseThrow(() -> new IllegalArgumentException("Geçersiz rol: " + parts[3])); // rol kontrol

        User user = new User(
                parts[1],
                parts[2],
                role,
                parts[4],
                parts[5].trim() // boşluk temizleme
        );

        user.setId(Integer.parseInt(parts[0].trim())); // id set
        return user;
    }

    @Override
    protected int getId(User user) {
        return user.getId(); // id döndür
    }

    // ------------------------------------------------------------------ //
    //  Sorgular
    // ------------------------------------------------------------------ //

    /**
     * Belirtilen role sahip kullanıcılar arasından rastgele birinin ID'sini döner.
     * Uygun kullanıcı yoksa -1 döner.
     */
    public int findByRoleGetId(Optional<Role> role) {
        List<User> users = getUsersByRole(role.get()); // role göre liste
        if (users.isEmpty()) {
            return -1; // kullanıcı yok
        }
        return users.get(new Random().nextInt(users.size())).getId(); // rastgele seçim
    }

    /**
     * Belirtilen role sahip ilk kullanıcının e-postasını döner.
     * Bulunamazsa Optional.empty() döner.
     */
    public Optional<String> findByRoleGetEmail(Role supplier) {
        return getUsersByRole(supplier).stream()
                .map(User::getEmail)
                .findFirst(); // ilk email
    }

    /**
     * E-posta ve şifreye göre kullanıcı arar.
     * Bulunamazsa Optional.empty() döner.
     */
    public Optional<User> findByEmailAndPassword(String email, String password) {
        return findAll().stream()
                .filter(u -> u.getEmail().equals(email) && u.getPassword().equals(password))
                .findFirst(); // login kontrol
    }

    // ------------------------------------------------------------------ //
    //  Yardımcı metotlar
    // ------------------------------------------------------------------ //

    private List<User> getUsersByRole(Role supplier) {
        List<User> result = new ArrayList<>();

        for (User user : findAll()) {
            if (user.getRole() == Role.getRoleByName(supplier.getName()).get()) {
                result.add(user); // role uygun kullanıcı
            }
        }

        return result;
    }
}