package com.project.mvcapp.controller;

import com.project.mvcapp.router.AppController;
import com.project.mvcapp.service.business.CommandInvoker;
import com.project.mvcapp.service.business.HomeService;
import com.project.mvcapp.view.HomeView;

import java.util.List;

public class HomeController {

    private final HomeView homeView; // giriş/kayıt ekranı için view
    
    private final HomeService homeService; // login ve sign-in kontrol işlemleri
    
    private final AppController router; // sayfa yönlendirmeleri için controller
    
    public HomeController() {
    	
    	this.router = new AppController(); // router oluşturuluyor
        this.homeView = new HomeView(); // home view oluşturuluyor
        this.homeService = new HomeService(); // home service oluşturuluyor
    }

    // ------------------------------------------------------------------ //
    //  Sayfa Yönlendirme
    // ------------------------------------------------------------------ //

    public void startPage() {
        int secim = homeView.getChoice(); // kullanıcıdan seçim alınır
        HomeView.clearScreen(); // ekran temizlenir

        if (secim == 1) {
            logInPage(); // giriş sayfasına yönlendirme
        } else {
            signInPage(); // kayıt sayfasına yönlendirme
        }
        
        router.showPermissions(); // işlem sonrası yetkiler gösterilir
    }

    // ------------------------------------------------------------------ //
    //  Giriş / Kayıt
    // ------------------------------------------------------------------ //

    public void logInPage() {
        boolean success = false;

        // giriş başarılı olana kadar tekrar deneme
        while (!success) {
            List<String> userInfos = homeView.logInPage(); // kullanıcı bilgileri alınır
            success = homeService.logInControl(userInfos); // kontrol yapılır

            if (!success) {
                HomeView.clearScreen(); // hata durumunda ekran temizlenir
                homeView.logInErrorPage(); // hata ekranı gösterilir
            }
        }

        homeView.showMessage("Giriş işleminiz başarıyla gerçekleşti!"); // başarı mesajı
    }
    
    public void signInPage() {
        boolean success = false;

        // kayıt başarılı olana kadar tekrar deneme
        while (!success) {
            List<String> userInfos = homeView.signInPage(); // kullanıcı kayıt bilgileri alınır
            success = homeService.signInControl(userInfos); // kayıt kontrol edilir

            if (!success) {
                HomeView.clearScreen(); // hata durumunda ekran temizlenir
                homeView.signInErrorPage(); // hata ekranı gösterilir
            }
        }

        homeView.showMessage("Kayıt işleminiz başarıyla gerçekleşti!"); // başarı mesajı
    }
    
    
}