package com.project.mvcapp.model;

import java.util.Optional;
import java.util.Set;

public enum Role {

    ADMIN(1, "admin", Set.of(
            Permission.CREATE_USER,
            Permission.DELETE_USER,
            Permission.VIEW_LOG,
            Permission.SHOW_PERMISSIONS,
            Permission.LOG_OUT
    )),
    CUSTOMER(2, "musteri", Set.of(
            Permission.REFUND,
            Permission.CREATE_ORDER,
            Permission.TRACK_ORDER,
            Permission.SHOW_PERMISSIONS,
            Permission.LOG_OUT
    )),
    COURIER(3, "kurye", Set.of(
            Permission.DELIVER,
            Permission.SHOW_PERMISSIONS,
            Permission.LOG_OUT
    )),
    WAREHOUSE_WORKER(4, "depo_gorevlisi", Set.of(
            Permission.ADD_PRODUCT,
            Permission.CHECK_SYSTEM_NOTIFICATIONS,
            Permission.UPDATE_ORDER_STATE,
            Permission.SHOW_PERMISSIONS,
            Permission.LOG_OUT
    )),
    SUPPLIER(5, "tedarikci", Set.of(
            Permission.BRING_SUPPLIES,
            Permission.CHECK_SYSTEM_NOTIFICATIONS,
            Permission.SHOW_PERMISSIONS,
            Permission.LOG_OUT
    )),
    PAYMENT_UNIT(6, "satin_alma_birimi", Set.of(
            Permission.BUY_PRODUCTS,
            Permission.CHECK_EMAILS,
            Permission.SHOW_PERMISSIONS,
            Permission.LOG_OUT
    ));

    private final int index; // rolün sistemdeki numarası
    private final String name; // rol adı
    private final Set<Permission> permissions; // role ait izinler

    Role(int index, String name, Set<Permission> permissions) {
        this.index = index;
        this.name = name;
        this.permissions = permissions;
    }

    // ------------------------------------------------------------------ //
    //  Getters
    // ------------------------------------------------------------------ //

    public int getIndex()                   { return index; }
    public String getName()                 { return name; }
    public Set<Permission> getPermissions() { return permissions; }

    // ------------------------------------------------------------------ //
    //  Statik Arama Metotları
    // ------------------------------------------------------------------ //

    public static Optional<Role> getRoleByName(String name) {
        for (Role r : values()) {
            // isim eşleşirse role döndürülür
            if (r.name.equalsIgnoreCase(name)) {
                return Optional.of(r);
            }
        }
        return Optional.empty(); // bulunamazsa boş döner
    }

    public static Optional<Role> getRole(int index) {
        for (Role r : values()) {
            // index eşleşirse role döndürülür
            if (r.index == index) {
                return Optional.of(r);
            }
        }
        return Optional.empty(); // bulunamazsa boş döner
    }
}