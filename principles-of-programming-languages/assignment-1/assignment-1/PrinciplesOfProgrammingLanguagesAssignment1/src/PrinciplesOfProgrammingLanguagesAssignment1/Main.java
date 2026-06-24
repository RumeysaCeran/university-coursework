// @ Rümeysa Ceran

package PrinciplesOfProgrammingLanguagesAssignment1;

public class Main {
	public static void main(String[] args) {

		Oyun.ekranTemizle();
		Oyun oyun = new Oyun();
		oyun.oyunaBasla();
		System.out.println("Devam etmek icin bir tusa bas...");
		try {
			System.in.read();
		} catch (Exception e) {
		}
	}
}
