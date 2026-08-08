import java.util.Scanner;

public class Conversor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Tasas fijas para practicar. Después las podemos actualizar con API
        final double USD = 4000.0; // 1 USD = 4000 COP
        final double EUR = 4300.0; // 1 EUR = 4300 COP
        
        System.out.println("--- CONVERSOR DE MONEDAS ---");
        System.out.println("Tasas de hoy: 1 USD = $" + USD + " COP | 1 EUR = $" + EUR + " COP");
        System.out.println(); // Línea en blanco
        
        System.out.println("1. COP a USD");
        System.out.println("2. COP a EUR");
        System.out.println("3. USD a COP");
        System.out.println("4. EUR a COP");
        System.out.print("Elige una opción: ");
        int opcion = scanner.nextInt();
        
        System.out.print("Ingresa la cantidad: ");
        double cantidad = scanner.nextDouble();
        double resultado = 0;
        
        switch(opcion) {
            case 1:
                resultado = cantidad / USD;
                System.out.printf("$%.2f COP = $%.2f USD\n", cantidad, resultado);
                break;
            case 2:
                resultado = cantidad / EUR;
                System.out.printf("$%.2f COP = €%.2f EUR\n", cantidad, resultado);
                break;
            case 3:
                resultado = cantidad * USD;
                System.out.printf("$%.2f USD = $%.2f COP\n", cantidad, resultado);
                break;
            case 4:
                resultado = cantidad * EUR;
                System.out.printf("€%.2f EUR = $%.2f COP\n", cantidad, resultado);
                break;
            default:
                System.out.println("Opción no válida");
        }
        
        System.out.println("Gracias por usar el conversor");
        scanner.close();
    }
} 
