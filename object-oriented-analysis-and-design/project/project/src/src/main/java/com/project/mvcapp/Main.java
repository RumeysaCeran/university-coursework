package com.project.mvcapp;

import com.project.mvcapp.command.AddProductCommand;
import com.project.mvcapp.command.BrıngSuppliesCommand;
import com.project.mvcapp.command.BuyProductCommand;
import com.project.mvcapp.command.CancelOrderCommand;
import com.project.mvcapp.command.CheckEmailsCommand;
import com.project.mvcapp.command.CheckSystemNotificationsCommand;
import com.project.mvcapp.command.CreateOrderCommand;
import com.project.mvcapp.command.CreateUserCommand;
import com.project.mvcapp.command.DeleteUserCommand;
import com.project.mvcapp.command.DeliverCommand;
import com.project.mvcapp.command.LogOutCommand;
import com.project.mvcapp.command.RefundCommand;
import com.project.mvcapp.command.ShowPermissionsCommand;
import com.project.mvcapp.command.ShowProductsCommand;
import com.project.mvcapp.command.ShowUsersCommand;
import com.project.mvcapp.command.TrackOrderCommand;
import com.project.mvcapp.command.UpdateOrderStateCommand;
import com.project.mvcapp.command.UpdateStockCommand;
import com.project.mvcapp.command.ViewLogCommand;
import com.project.mvcapp.controller.HomeController;
import com.project.mvcapp.service.business.CommandInvoker;

import com.project.mvcapp.command.AddProductCommand;
import com.project.mvcapp.command.BrıngSuppliesCommand;
import com.project.mvcapp.command.BuyProductCommand;
import com.project.mvcapp.command.CancelOrderCommand;
import com.project.mvcapp.command.CheckEmailsCommand;
import com.project.mvcapp.command.CheckSystemNotificationsCommand;
import com.project.mvcapp.command.CreateOrderCommand;
import com.project.mvcapp.command.CreateUserCommand;
import com.project.mvcapp.command.DeleteUserCommand;
import com.project.mvcapp.command.DeliverCommand;
import com.project.mvcapp.command.LogOutCommand;
import com.project.mvcapp.command.RefundCommand;
import com.project.mvcapp.command.ShowPermissionsCommand;
import com.project.mvcapp.command.ShowProductsCommand;
import com.project.mvcapp.command.ShowUsersCommand;
import com.project.mvcapp.command.TrackOrderCommand;
import com.project.mvcapp.command.UpdateOrderStateCommand;
import com.project.mvcapp.command.UpdateStockCommand;
import com.project.mvcapp.command.ViewLogCommand;
import com.project.mvcapp.controller.HomeController;
import com.project.mvcapp.service.business.CommandInvoker;

public class Main {
	public static void main(String[] args) {

        // CommandInvoker nesnesi oluşturuluyor (tek bir merkezden komutları yönetmek için)
        CommandInvoker invoker = CommandInvoker.getInstance();

        // Komutlar sisteme tek tek register ediliyor (id -> command eşleştirmesi)
        invoker.register(1, new CreateUserCommand());   // kullanıcı oluşturma
        invoker.register(2, new DeleteUserCommand());   // kullanıcı silme
        invoker.register(3, new ShowUsersCommand());    // kullanıcıları listeleme
        invoker.register(4, new ViewLogCommand());      // log görüntüleme
        invoker.register(5, new AddProductCommand());   // ürün ekleme
        invoker.register(6, new UpdateStockCommand());  // stok güncelleme
        invoker.register(7, new UpdateOrderStateCommand()); // sipariş durumu güncelleme
        invoker.register(8, new DeliverCommand());      // sipariş teslim etme
        invoker.register(9, new CreateOrderCommand());  // sipariş oluşturma
        invoker.register(10, new TrackOrderCommand());  // sipariş takip
        invoker.register(11, new RefundCommand());      // iade işlemi
        invoker.register(12, new CheckEmailsCommand());  // e-postaları kontrol etme
        invoker.register(13, new CheckSystemNotificationsCommand()); // sistem bildirimleri
        invoker.register(14, new BuyProductCommand());  // ürün satın alma
        invoker.register(15, new BrıngSuppliesCommand()); // tedarik getirme
        invoker.register(16, new ShowPermissionsCommand()); // yetkileri gösterme
        invoker.register(17, new ShowProductsCommand()); // ürünleri listeleme
        invoker.register(18, new CancelOrderCommand()); // sipariş iptal
        invoker.register(19, new LogOutCommand()); // sistemden çıkış

        // Ana ekran controller başlatılıyor
		HomeController homeController = new HomeController();	

        // programın giriş sayfası açılıyor
		homeController.startPage();		
	};
}