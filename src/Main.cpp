// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Main.cpp
// Autores:
//   Esteban [Tus Apellidos] | Código: 20XXXXX | correo@correounivalle.edu.co
// Fecha: 02/11/2026

#include <iostream>
#include <string>
#include "JuegoModel.h"
#include "JuegoView.h"
#include "JuegoController.h"

int main() {
    JuegoModel model;
    JuegoView view;
    JuegoController controller(&model, &view);

    int opcion = 0;
    while (opcion != 2) {
        std::cout << "\n========================================\n";
        std::cout << "         BUS JAM - MENU PRINCIPAL       \n";
        std::cout << "========================================\n";
        std::cout << "1. Cargar Nivel (.txt)\n";
        std::cout << "2. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "\nSeleccione el numero de nivel (1, 2 o 3): ";
            int numNivel;
            std::cin >> numNivel;

            std::string nombreArchivo = "nivel" + std::to_string(numNivel) + ".txt";

            if (model.cargarNivel(nombreArchivo)) {
                std::cout << "\n[OK] ¡" << nombreArchivo << " cargado con exito!\n";

                // Bucle interactivo de la partida activa
                int idVehiculo = -1;
                while (idVehiculo != 0 && !model.estaTerminado()) {
                    view.mostrarTablero(&model);
                    view.mostrarEstadoParqueoYFilas(&model);

                    std::cout << "\nIngrese el ID del vehiculo a mover (0 para salir al menu): ";
                    std::cin >> idVehiculo;

                    if (idVehiculo > 0) {
                        controller.seleccionarYMoverVehiculo(idVehiculo);
                    }
                }

                // Al salir del bucle, verificar si el juego terminó por victoria o derrota
                if (model.estaTerminado()) {
                    view.mostrarTablero(&model);
                    view.mostrarEstadoParqueoYFilas(&model);
                    if (model.esVictoria()) {
                        std::cout << "\n*** ¡FELICIDADES! HAS GANADO EL NIVEL ***\n";
                    } else {
                        std::cout << "\n*** GAME OVER: La zona de parqueo se ha llenado ***\n";
                    }
                }
            } else {
                std::cout << "\n[ERROR] No se pudo abrir el archivo: " << nombreArchivo << "\n";
                std::cout << "Asegurese de haber creado el archivo .txt dentro de la carpeta PROYECTO.\n";
            }
        }
    }

    std::cout << "\n¡Gracias por jugar Bus Jam!\n";
    return 0;
}