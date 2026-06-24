package com.project.mvcapp.service.business;

import com.project.mvcapp.model.User;

public class SessionService {

    // Aktif oturumdaki kullanıcıyı tutar
    private static User currentUser;
    
    // Kullanıcının yetkilerini yöneten servis
    private static AuthorizationService authService;
    
    // Utility sınıfı — nesne oluşturulamaz
    private SessionService() {}

    // ------------------------------------------------------------------ //
    //  Oturum Yönetimi
    // ------------------------------------------------------------------ //

    // Kullanıcı giriş yaptığında oturum başlatılır
    public static void logIn(User user) {
        if (user == null) {
            throw new IllegalArgumentException("Oturum açmak için geçerli bir kullanıcı gereklidir.");
        }
        currentUser = user;
        authService = new AuthorizationService(currentUser);
    }

    // Kullanıcı çıkış yaptığında oturum sonlandırılır
    public static void logOut() {
        currentUser = null;
    }

    // Aktif kullanıcıyı döndürür
    public static User getCurrentUser() {
        return currentUser;
    }

    // Sistemde oturum açık mı kontrol eder
    public static boolean isLoggedIn() {
        return currentUser != null;
    }
}------------------------------------------------------------------ 