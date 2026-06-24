package com.project.mvcapp.service.business;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import com.project.mvcapp.model.User;
import com.project.mvcapp.repository.UserFileRepository;
import com.project.mvcapp.model.Role;
import com.project.mvcapp.model.Permission;

public class UserService {
	private UserFileRepository userFiling;
	
	public UserService() {
		this.userFiling = new UserFileRepository();
	};
	
	// Yeni kullanıcı bilgilerini alıp User nesnesi oluşturur
	public User createUser(ArrayList<String> new_user_infos) {
		
		int indexRol = Integer.parseInt(new_user_infos.get(2));
		Optional<Role> rol = Role.getRole(indexRol);
		
		User user = new User(
				new_user_infos.get(0),
				new_user_infos.get(1),
				rol.get(),
				new_user_infos.get(3),
				new_user_infos.get(4)
			
				);
		
		return user;
	};
	
	// Kullanıcıyı ID'ye göre siler
	public void deleteUser(int id) {
		userFiling.delete(id);
	}
	
	// ID'ye göre kullanıcı bulur
	public Optional<User> findById(int id) {
		Optional<User> user = userFiling.findById(id);
		return user;
	}
	
	// Kullanıcı giriş kontrolü yapar (email + şifre)
	public boolean signInControl(ArrayList<String> new_user_infos) {
		String user_password = new_user_infos.get(1);
		String user_email = new_user_infos.get(0);
		Optional<User> user = userFiling.findByEmailAndPassword(user_email, user_password);//Dosyada oyle birisi var mı
		if(user.get() != null)//dosyada oyle birisi varsa
		{				
			return true;
		}
		else {
			return false;
		}
		
	}

	// Kullanıcıyı dosyaya kaydeder
	public void save(User user) {
		userFiling.save(user);
		
	}

	// Tüm kullanıcıları listeler
	public List<String> showUsers() {
				
		return userFiling.readFromFile();
				
	}

	// Role göre email bulur
	public Optional<String> findByRole(String string) {
		
		return userFiling.findByRoleGetEmail(Role.PAYMENT_UNIT);
	}
}