package com.project.mvcapp.service.business;

import java.util.HashMap;
import java.util.Map;

import com.project.mvcapp.command.Command;

public class CommandInvoker {
	
	// Singleton instance (tek bir CommandInvoker nesnesi kullanılır)
	private static final CommandInvoker INSTANCE = new CommandInvoker();
	
	// Komutların index'e göre saklandığı map yapısı
	private Map<Integer, Command> commandMap = new HashMap<>();
	
	private CommandInvoker() {}

	// Singleton erişim noktası
	public static CommandInvoker getInstance() {
	        return INSTANCE;
	}

	// Yeni komutları sisteme kayıt eder
	public void register(int index, Command command) {
		commandMap.put(index, command);
	}
	
	// Verilen index'e göre komutu çalıştırır
	public boolean executeCommand(int index, Object... args) {
		Command command = commandMap.get(index);
		
		if(command != null) {
			command.execute(args);
		}else {
			System.out.println("Gecersiz yetki/komut");
			return true;
		}
		return false;
	}
}
}
