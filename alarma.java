import java.util.Scanner;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Alarma {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DateTimeFormatter formato = DateTimeFormatter.ofPattern("HH:mm:ss");

        System.out.println("--- ALARMA JAVA ---");
        System.out.print("¿A que hora quieres que suene? Formato HH:mm:ss: ");
        String horaAlarma = scanner.nextLine();

        System.out.println("Alarma puesta para las: " + horaAlarma);
        System.out.println("Esperando... no cierres el programa ");

        while (true) {
            LocalTime ahora = LocalTime.now();
            String horaActual = ahora.format(formato);
            
            System.out.print("\rHora actual: " + horaActual); // \r sobreescribe la línea

            if (horaActual.equals(horaAlarma)) {
                System.out.println("\n\n¡¡¡¡DESPIERTAAAA!!!!");
                System.out.println("¡¡¡¡SON LAS " + horaActual + "!!!!");
                
                // Hacer ruido en consola
                for (int i = 0; i < 5; i++) {
                    System.out.print("\u0007"); // Beep
                    try { Thread.sleep(500); } catch (InterruptedException e) {}
                }
                break;
            }

            try {
                Thread.sleep(1000); // Espera 1 segundo
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        scanner.close();
    }
}
