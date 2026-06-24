package com.project.mvcapp.service.business;

import com.project.mvcapp.model.User;
import com.project.mvcapp.repository.UserFileRepository;

import java.util.List;
import java.util.Optional;

public class HomeService {

    // Kullanıcı verilerinin dosya işlemlerini yapan repository
    private final UserFileRepository userFiling;

    public HomeService() {
        this.userFiling = new UserFileRepository();
    }

    // ------------------------------------------------------------------ //
    //  Giriş
    // ------------------------------------------------------------------ //

    /**
     * E-posta ve şifre kontrolü yapar; başarılıysa oturumu başlatır.
     */
    public boolean logInControl(List<String> userInfos) {
        String email    = userInfos.get(0);
        String password = userInfos.get(1);

        Optional<User> user = userFiling.findByEmailAndPassword(email, password);

        // Kullanıcı doğrulanırsa session başlatılır
        if (user.isPresent()) {
            SessionService.logIn(user.get());
            return true;
        }
        return false;
    }

    // ------------------------------------------------------------------ //
    //  Kayıt
    // ------------------------------------------------------------------ //

    /**
     * Kullanıcı zaten varsa false döner; yoksa kaydeder ve true döner.
     */
    public boolean signInControl(List<String> userInfos) {
        String email    = userInfos.get(0);
        String password = userInfos.get(1);

        Optional<User> existing = userFiling.findByEmailAndPassword(email, password);

        // Kullanıcı zaten varsa kayıt yapılmaz
        if (existing.isPresent()) {
            return false;
        }

        // Yeni kullanıcı oluşturma işlemi burada yapılabilir
        return true;
    }
}