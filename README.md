# 🚌 Bus Fever Party! — FPOO (C++ Edition)

Proyecto desarrollado para el curso de **Fundamentos de Programación Orientada a Objetos (FPOO)** - Universidad del Valle.

## 👥 Integrantes
* Jorge Rodríguez
* Samuel Martínez Muñoz
* Sofía Montealegre Polanco
* Samuel Tellez Caicedo
* Alejandro Murillo Renteria


---

## 🛠️ Arquitectura del Proyecto (Patrón MVC)
El proyecto implementa el patrón **Modelo-Vista-Controlador (MVC)** en C++:
* **Model (`src/JuegoModel`):** Lógica del tablero, vehículos y ciclo de abordaje.
* **View (`src/JuegoView`):** Renderizado del estado e interfaz de consola.
* **Controller (`src/JuegoController`):** Orquestador de comandos del usuario.

---

## 📁 Estructura del Repositorio
* `/src`: Archivos de código fuente `.h` y `.cpp`.
* `/niveles`: Archivos de configuración planos `.txt`.
* `/docs`: Documentación técnica e Historias de Usuario.

---

## 🚀 Compilación y Ejecución
```bash
g++ -std=c++11 src/*.cpp -o bus_jam
./bus_jam
