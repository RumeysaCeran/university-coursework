package com.project.mvcapp.model;

import java.util.Objects;

public class User {

    private int id; // kullanıcı id
    private static int ID=0; // otomatik id sayacı
    private String name; // kullanıcı adı
    private String surname; // kullanıcı soyadı
    private String email; // kullanıcı email
    private String password; // kullanıcı şifre
    private Role role; // kullanıcı rolü

    public static void setLastId(int id) {
        ID = id; // dışarıdan id resetleme
    }

    public User(
            String name,
            String surname,
            Role role,
            String email,
            String password
    ) {
    	ID++; // her kullanıcıda id artırılır
		this.id = ID;
        this.name = name;
        this.surname = surname;
        this.role = role;
        this.email = email;
        this.password = password;
    }

    // ------------------------------------------------------------------ //
    //  Getters & Setters
    // ------------------------------------------------------------------ //

    public int getId() { return id; } // id alma
    public void setId(int id) { this.id = id; } // id set etme

    public String getName() { return name; } // isim alma
    public void setName(String name) { this.name = name; } // isim set etme

    public String getSurname() { return surname; } // soyisim alma
    public void setSurname(String surname) { this.surname = surname; } // soyisim set etme

    public String getEmail() { return email; } // email alma
    public void setEmail(String email) { this.email = email; } // email set etme

    public String getPassword() { return password; } // şifre alma
    public void setPassword(String password) { this.password = password; } // şifre set etme

    public Role getRole() { return role; } // rol alma
    public void setRole(Role role) { this.role = role; } // rol set etme

    // ------------------------------------------------------------------ //
    //  equals, hashCode, toString
    // ------------------------------------------------------------------ //

    @Override
    public boolean equals(Object o) {
        if (this == o) return true; // aynı nesne kontrolü
        if (!(o instanceof User)) return false; // tip kontrolü
        User other = (User) o;
        return id == other.id && Objects.equals(email, other.email); // id ve email karşılaştırma
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, email); // hash üretme
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", surname='" + surname + '\'' +
                ", email='" + email + '\'' +
                ", role=" + role +
                '}'; // kullanıcı bilgilerini yazdırma
    }
}