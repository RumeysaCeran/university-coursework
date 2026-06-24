package com.project.mvcapp.util;

import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;

public class Logger {
	
	private static Logger instance;
	private FileWriter writer;
	
	private Logger() {
		try {
			writer = new FileWriter("data/Logs.txt", true);
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	// Singleton Logger instance döner
	public static Logger getInstance() {
		if(instance == null) {
			instance = new Logger();
		}
		return instance;
	}
	
	// Log mesajını hem konsola hem dosyaya yazar
	public void log(String message) {
		String logMessage = LocalDateTime.now() + "-" + message;
		
		System.out.println(logMessage);
		
		try {
			writer.write(logMessage + "\n");
			writer.flush();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}