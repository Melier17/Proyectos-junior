import random
import string

def generar_contraseña(longitud):
    if longitud < 4:
        return "La contraseña debe tener mínimo 4 caracteres"
    
    # 1. Aseguramos 1 de cada tipo
    contraseña = [
        random.choice(string.ascii_lowercase), # 1 minúscula
        random.choice(string.ascii_uppercase), # 1 mayúscula  
        random.choice(string.digits),          # 1 número
        random.choice("!@#$%^&*()")            # 1 símbolo
    ]
    
    # 2. Rellenamos el resto con todo mezclado
    todos_caracteres = string.ascii_letters + string.digits + "!@#$%^&*()"
    for _ in range(longitud - 4):
        contraseña.append(random.choice(todos_caracteres))
    
    # 3. Revolvemos todo para que no siempre empiece igual
    random.shuffle(contraseña)
    
    return ''.join(contraseña)

print("--- GENERADOR DE CONTRASEÑAS ---")
while True:
    try:
        longitud = int(input("¿De cuántos caracteres la quieres? Ej: 12. Pon 0 para salir: "))
        if longitud == 0:
            print("Chao! Cuida esas claves")
            break
            
        nueva_clave = generar_contraseña(longitud)
        print(f"Tu nueva contraseña: {nueva_clave}")
        print("100% segura: tiene mayúscula, minúscula, número y símbolo\n")
        
    except ValueError:
        print("Oye, pon solo números ome")
