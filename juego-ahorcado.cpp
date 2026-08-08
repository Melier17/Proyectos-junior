#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>
using namespace std;

const int MAX_VIDAS = 6;

struct Palabra {
    string texto;
    string pista;
    string categoria;
};

void dibujarAhorcado(int vidas) {
    cout << "\n +---+" << endl;
    cout << " |" << endl;
    cout << " | " << (vidas < 6? "O" : " ") << endl;
    cout << " | " << (vidas < 4? "/" : " ") << (vidas < 5? "|" : " ") << (vidas < 4? "\\" : " ") << endl;
    cout << " | " << (vidas < 2? "/" : " ") << " " << (vidas < 2? "\\" : " ") << endl;
    cout << " |" << endl;
    cout << "=========" << endl;
    cout << "Vidas: " << vidas << endl;
}

Palabra elegirPalabra(string categoria) {
    vector<Palabra> todas = {
        {"GATO", "Duerme 16 horas al día y dice miau", "ANIMAL"},
        {"ELEFANTE", "Tiene trompa y es el más grande de la tierra", "ANIMAL"},
        {"MANGO", "Amarillo por dentro, verde por fuera. De Colombia", "FRUTA"},
        {"BANANO", "Los monos lo aman y tiene cáscara", "FRUTA"},
        {"TECLADO", "Tiene muchas letras y lo usas para programar", "OBJETO"},
        {"CELULAR", "Lo usas para chatear y tomar fotos", "OBJETO"},
        {"SOFIA", "Nombre común de niña. Significa sabiduría", "NOMBRE"},
        {"CARLOS", "Nombre de rey. Muy común", "NOMBRE"},
        {"GITHUB", "Donde subimos nuestros proyectos", "PROGRAMACION"},
        {"VARIABLE", "Caja que guarda datos en el codigo", "PROGRAMACION"}
    };

    vector<Palabra> filtradas;
    for(Palabra p : todas) {
        if(p.categoria == categoria) filtradas.push_back(p);
    }

    srand(time(0));
    int indice = rand() % filtradas.size();
    return filtradas[indice];
}

void mostrarProgreso(string palabra, vector<char> letrasAdivinadas) {
    for(char c : palabra) {
        if(find(letrasAdivinadas.begin(), letrasAdivinadas.end(), c)!= letrasAdivinadas.end()) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    cout << "=================================" << endl;
    cout << " JUEGO DEL AHORCADO v4.1 " << endl;
    cout << " MODO CATEGORIAS " << endl;
    cout << "=================================" << endl;

    cout << "\nElige categoria:" << endl;
    cout << "1. ANIMALES" << endl;
    cout << "2. FRUTAS" << endl;
    cout << "3. OBJETOS" << endl;
    cout << "4. NOMBRES" << endl;
    cout << "5. PROGRAMACION" << endl;
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    string cat;
    if(opcion==1) cat="ANIMAL";
    if(opcion==2) cat="FRUTA";
    if(opcion==3) cat="OBJETO";
    if(opcion==4) cat="NOMBRE";
    if(opcion==5) cat="PROGRAMACION";

    Palabra palabraActual = elegirPalabra(cat);
    string palabraSecreta = palabraActual.texto;

    vector<char> letrasAdivinadas;
    vector<char> letrasUsadas;
    int vidas = MAX_VIDAS;
    int aciertos = 0;

    cout << "\n CATEGORIA: " << palabraActual.categoria << endl;
    cout << " PISTA: " << palabraActual.pista << endl;

    while(vidas > 0 && aciertos < palabraSecreta.length()) {
        dibujarAhorcado(vidas);
        cout << "\nPalabra: ";
        mostrarProgreso(palabraSecreta, letrasAdivinadas);
        cout << "Letras usadas: ";
        for(char l : letrasUsadas) cout << l << " ";
        cout << endl;

        cout << "\nIngresa una letra: ";
        char letra;
        cin >> letra;
        letra = toupper(letra);

        if(find(letrasUsadas.begin(), letrasUsadas.end(), letra)!= letrasUsadas.end()) {
            cout << "Ya usaste esa letra!\n";
            continue;
        }

        letrasUsadas.push_back(letra);

        if(palabraSecreta.find(letra)!= string::npos) {
            cout << "✅ Correcto!\n";
            letrasAdivinadas.push_back(letra);
            aciertos += count(palabraSecreta.begin(), palabraSecreta.end(), letra);
        } else {
            cout << "❌ Incorrecto!\n";
            vidas--;
        }
    }

    dibujarAhorcado(vidas);
    if(aciertos == palabraSecreta.length()) {
        cout << "\n GANASTE! La palabra era: " << palabraSecreta << endl;
    } else {
        cout << "\n PERDISTE! La palabra era: " << palabraSecreta << endl;
    }

    return 0;
}
