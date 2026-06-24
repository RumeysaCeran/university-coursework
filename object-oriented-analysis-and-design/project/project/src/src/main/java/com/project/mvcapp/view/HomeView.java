package com.project.mvcapp.view;

import com.project.mvcapp.model.Role;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class HomeView {

    private final Scanner scanner = new Scanner(System.in);

    public HomeView() {}

    // ------------------------------------------------------------------ //
    //  Sayfa Başlığı & Ekran
    // ------------------------------------------------------------------ //

    public void beginningOfPage() {
        System.out.println("-------------------------------------------------------------------------------");
        System.out.println("-          Akıllı Tedarik ve Lojistik Sistemine Hoş Geldiniz!                -");
        System.out.println("-------------------------------------------------------------------------------");
    }

    // Ekranı temizler (Windows ve Unix uyumlu)
    public static void clearScreen() {
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls")
                        .inheritIO().start().waitFor();
            } else {
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }
        } catch (Exception e) {
            for (int i = 0; i < 50; i++) {
                System.out.println();
            }
        }
    }

    // ------------------------------------------------------------------ //
    //  Ana Menü
    // ------------------------------------------------------------------ //

    // Giriş/Kayıt seçim menüsünü gösterir
    public void logInSignInPage() {
        beginningOfPage();
        System.out.println("1- Giriş Yap (Log In)");
        System.out.println("2- Kayıt Ol (Sign Up)");
    }

    // Kullanıcıdan seçim alır (1 veya 2)
    public int getChoice() {
        clearScreen();
        logInSignInPage();

        int secim;
        do {
            System.out.print("Seçim yapınız (1/2): ");
            while (!scanner.hasNextInt()) {
                System.out.println("Lütfen geçerli bir sayı giriniz!");
                scanner.next();
            }
            secim = scanner.nextInt();
        } while (secim != 1 && secim != 2);

        return secim;
    }

    // ------------------------------------------------------------------ //
    //  Kullanıcı Girdi Metotları
    // ------------------------------------------------------------------ //

    // Kullanıcı adı alır
    public String getName() {
        System.out.print("Ad: ");
        return scanner.next();
    }

    // Kullanıcı soyadı alır
    public String getSurname() {
        System.out.print("Soyad: ");
        return scanner.next();
    }

    // Kullanıcı e-posta alır
    public String getEmail() {
        System.out.print("E-posta: ");
        return scanner.next();
    }

    // Kullanıcı şifre alır
    public String getPassword() {
        System.out.print("Şifre: ");
        return scanner.next();
    }

    // ------------------------------------------------------------------ //
    //  Giriş / Kayıt Sayfaları
    // ------------------------------------------------------------------ //

    // Giriş ekranını hazırlar ve bilgileri döner
    public List<String> logInPage() {
        beginningOfPage();
        System.out.println("--- Giriş Yap ---");

        List<String> infos = new ArrayList<>();
        infos.add(getEmail());
        infos.add(getPassword());
        return infos;
    }

    // Kayıt ekranını hazırlar ve bilgileri döner
    public List<String> signInPage() {
        beginningOfPage();
        System.out.println("--- Kayıt Ol ---");

        List<String> infos = new ArrayList<>();
        infos.add(getEmail());
        infos.add(getPassword());
        infos.add(getName());
        infos.add(getSurname());
        infos.add(Role.CUSTOMER.getName());
        return infos;
    }

    // ------------------------------------------------------------------ //
    //  Hata & Bilgi Mesajları
    // ------------------------------------------------------------------ //

    // Giriş hatası mesajı
    public void logInErrorPage() {
        System.out.println("-------------------------------------------------------------------------------");
        System.out.println("-  Böyle bir kullanıcı bulunmamaktadır! Lütfen tekrar deneyiniz.             -");
        System.out.println("-------------------------------------------------------------------------------");
    }

    // Kayıt hatası mesajı
    public void signInErrorPage() {
        System.out.println("-------------------------------------------------------------------------------");
        System.out.println("-  Bu bilgilere ait kullanıcı zaten bulunmaktadır!                           -");
        System.out.println("-------------------------------------------------------------------------------");
    }

    // Genel mesaj gösterir
    public void showMessage(String message) {
        System.out.println(message);
    }
}