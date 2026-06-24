// @ Rümeysa Ceran 

package PrinciplesOfProgrammingLanguagesAssignment1;

public class Kisi {
	String ad_soyad;
	int yas;
	static int ID = 0;
	int id;

	public Kisi(String ad_soyad, int yas) {
		this.ad_soyad = ad_soyad;
		this.yas = yas;
		this.id = ID;
		ID++;
	}
}
