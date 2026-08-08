#include <iostream>
#include <string>
#include <iomanip> // para las tablas bonitas
using namespace std;

struct Producto {
    string nombre;
    int stock;
    float precio;
};

void dibujarLinea() {
    cout << "========================================" << endl;
}

void titulo() {
    system("cls"); // limpia pantalla. En Mac/Linux usa "clear"
    dibujarLinea();
    cout << " 🛒 SUPERMERCADO MELIER v2.0 🛒" << endl;
    cout << " Sistema de Inventario Pro" << endl;
    dibujarLinea();
    cout << endl;
}

int main() {
    Producto inventario[100];
    int totalProductos = 0;
    int opcion;

    do {
        titulo();
        cout << " [1] ➕ Agregar Producto" << endl;
        cout << " [2] 📦 Ver Inventario" << endl;
        cout << " [3] 💰 Vender Producto" << endl;
        cout << " [4] 🔍 Buscar Producto" << endl;
        cout << " [5] ❌ Salir" << endl;
        dibujarLinea();
        cout << " Elige una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            titulo();
            cout << "--- AGREGAR PRODUCTO ---" << endl << endl;
            cout << " Nombre: ";
            getline(cin, inventario[totalProductos].nombre);
            cout << " Stock inicial: ";
            cin >> inventario[totalProductos].stock;
            cout << " Precio: $";
            cin >> inventario[totalProductos].precio;
            totalProductos++;
            cout << "\n✅ Producto agregado con exito!" << endl;
            system("pause");
        
        } else if (opcion == 2) {
            titulo();
            cout << "--- INVENTARIO ACTUAL ---" << endl << endl;
            cout << left << setw(5) << "No" 
                 << setw(20) << "PRODUCTO" 
                 << setw(10) << "STOCK" 
                 << setw(12) << "PRECIO" << endl;
            dibujarLinea();
            
            float valorTotal = 0;
            for (int i = 0; i < totalProductos; i++) {
                cout << left << setw(5) << i+1 
                     << setw(20) << inventario[i].nombre 
                     << setw(10) << inventario[i].stock
                     << "$" << setw(11) << fixed << setprecision(0) << inventario[i].precio << endl;
                valorTotal += inventario[i].stock * inventario[i].precio;
            }
            dibujarLinea();
            cout << " VALOR TOTAL EN BODEGA: $" << valorTotal << endl;
            system("pause");
        
        } else if (opcion == 3) {
            titulo();
            cout << "--- VENDER PRODUCTO ---" << endl << endl;
            //... aquí va tu mismo código de vender
            system("pause");
        }
        // el resto igual...

    } while (opcion!= 5);

    titulo();
    cout << "Gracias por usar Supermercado Melier!" << endl;
    return 0;
}
