package com.project.mvcapp.command;

import com.project.mvcapp.factory.Payment.PaymentFactory;
import com.project.mvcapp.factory.ShippingFactory.ShippingFactory;
import com.project.mvcapp.model.Order;
import com.project.mvcapp.model.Permission;
import com.project.mvcapp.model.payment.PaymentStrategy;
import com.project.mvcapp.model.shipping.ShippingCarrier;
import com.project.mvcapp.repository.OrderFileRepository;
import com.project.mvcapp.repository.ProductFileRepository;
import com.project.mvcapp.service.business.OrderService;
import com.project.mvcapp.service.business.PaymentService;
import com.project.mvcapp.service.business.ShippingService;
import com.project.mvcapp.service.business.StockService;
import com.project.mvcapp.view.OrderView;
import com.project.mvcapp.view.PaymentView;
import com.project.mvcapp.view.ProductView;
import com.project.mvcapp.view.ShippingView;

public class CreateOrderCommand implements Command {
	
	private ProductFileRepository productFileRepo; // ürünleri dosyadan okumak için repository
	
	private ProductView productView; // ürünleri kullanıcıya göstermek için view
	
	private OrderView orderView; // sipariş işlemleri için view
	
	private ShippingView shippingView; // kargo tipi seçimi için view
	
	private OrderService orderService; // sipariş oluşturma ve yönetme işlemleri
	
	private ShippingService shippingService; // kargo işlemleri için servis
	
	private StockService stockService; // stok azaltma işlemleri için servis
	
	private OrderFileRepository orderFileRepo; // siparişleri dosyaya kaydetmek için repository
	
	private PaymentService paymentService; // ödeme işlemleri için servis
	
	private PaymentView paymentView; // ödeme ekranı için view
	
	private ShippingFactory shippingFactory; // kargo türlerini üretmek için factory
	
	private PaymentFactory paymentFactory; // ödeme türlerini üretmek için factory
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public CreateOrderCommand() {
		this.productFileRepo = new ProductFileRepository();
	    this.productView = new ProductView();
		this.orderView = new OrderView();
		this.shippingView = new ShippingView();
		this.orderService = new OrderService();
		this.shippingService = new ShippingService();
		this.stockService = new StockService();
		this.orderFileRepo = new OrderFileRepository();
		this.paymentService = new PaymentService();
		this.paymentView = new PaymentView();
		this.shippingFactory = new ShippingFactory();
		this.paymentFactory = new PaymentFactory();
		this.orderService = new OrderService(); // (tekrar yazılmış ama değiştirilmedi)
		this.permissionCommand = new ShowPermissionsCommand();
	};

	
	@Override
	public void execute(Object... args) {
		
		// tüm ürünler kullanıcıya gösterilir
		productView.showAllProducts(productFileRepo.readFromFile());
		
		// ürün id alınır
		int productId;
		do {
			productId = Integer.parseInt(productView.getProductId());
		} while(productFileRepo.findById(productId) == null);
		
		// ürün miktarı alınır ve stok kontrolü yapılır
		int amount;
		do {
			amount = productView.getAmount();

			int kalan = productFileRepo.findById(productId).get().getStock() - amount;

			if(kalan < 0){
				productView.showStockAlert(kalan); // stok yetersiz uyarısı
			}

			if(amount == 0) {
				permissionCommand.execute(); // 0 girilirse menüye dön
			}

		} while(productFileRepo.findById(productId).get().getStock() < amount);
		
		// mesafe bilgisi alınır
		double distance;
		do {
			distance = orderView.getDistance();

			if(distance == 0) {
				orderView.showDistanceAlert(); // 0 girilirse uyarı
			}

		} while(distance == 0);
		
		// sipariş oluşturulur
		Order order = orderService.createOrder(productId, amount, distance);
		
		
		// kargo tipi seçilir
		String shippingType;
		do {
			shippingType = shippingView.getShippingType(ShippingFactory.getShippingTypes());
		} while(!ShippingFactory.getShippingTypes().contains(shippingType));
		
		// kargo atanır ve hesaplamalar yapılır
		ShippingCarrier carrier = ShippingFactory.getCarrier(shippingType);
		shippingService.setShippingType(carrier);

		int courierId = shippingService.assignCourier(); // kurye atanır

		double cargoPrice = shippingService.calculateCost(order); // kargo ücreti hesaplanır

		order = orderService.setAssignedCorierId(courierId, order); // kurye siparişe eklenir
		order = orderService.setPrices(order, cargoPrice); // fiyat güncellenir

		order.setTrackingNumber(shippingService.setTrackingNumber(order)); // takip numarası oluşturulur
		
		
		// ödeme tipi seçilir
		String paymentType;
		do {
			paymentType = paymentView.getPaymentType(PaymentFactory.getPaymentStrategies());
		} while(!PaymentFactory.getPaymentStrategies().contains(paymentType));
		
		// ödeme yapılır
		PaymentStrategy paymentStrategy = PaymentFactory.getPaymentStrategy(paymentType);
		paymentService.setPaymentStrategy(paymentStrategy);
		
		order = paymentService.pay(order);
		paymentView.paymentCompleted(); // ödeme tamamlandı mesajı

		// stok düşülür
		stockService.decreaseStock(productId, amount);

		// sipariş kaydedilir
		orderFileRepo.save(order);
		
		// işlem tamamlandı mesajı
		orderView.processCompleted(Permission.