package com.project.mvcapp.command;

import java.util.List;

import com.project.mvcapp.service.business.LogService;
import com.project.mvcapp.view.LogView;

public class ViewLogCommand implements Command {
	
	private LogService logService; // log kayıtlarını almak için servis
	
	private LogView logView; // logları ekranda göstermek için view
	
	private ShowPermissionsCommand permissionCommand; // yetkileri tekrar göstermek için komut
	
	public ViewLogCommand() {
		this.permissionCommand = new ShowPermissionsCommand(); // yetki komutu oluşturuluyor
		this.logView = new LogView(); // log view oluşturuluyor
		this.logService = new LogService(); // log servisi oluşturuluyor
	}

	@Override
	public void execute(Object... args) {
		
		// sistem logları alınır
		List<String> logs = logService.getLogs();

		// loglar ekrana yazdırılır
		logView.showLogs(logs);
		

		// yetkiler tekrar gösterilir
		permissionCommand.execute();
	}
	
	
}
