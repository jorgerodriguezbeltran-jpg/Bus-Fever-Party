// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: JuegoView.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: JuegoView
  ==============================================================================
  Responsabilidades:
  - Gestionar la presentación visual en consola (Vista del patrón MVC).
  - Imprimir menús, estado detallado del tablero, parqueo y mensajes del sistema.

  Colaboradores:
  - JuegoModel
  - Vehiculo (para consultar propiedades de los vehículos activos)
  ==============================================================================
*/

#ifndef JUEGOVIEW_H
#define JUEGOVIEW_H

#include <iostream>
#include <string>
#include <vector>

// Includes necesarios para evitar tipos incompletos
#include "JuegoModel.h"
#include "Tablero.h"
#include "ZonaParqueo.h"
#include "FilaEstatica.h"
#include "Vehiculo.h"

/**
 * @class JuegoView
 * @brief Gestiona la interfaz gráfica y presentación en consola.
 */
class JuegoView {
private:
    std::string colorToString(Color c) const {
        switch (c) {
            case Color::ROJO: return "ROJO";
            case Color::AZUL: return "AZUL";
            case Color::VERDE: return "VERDE";
            case Color::MORADO: return "MORADO";
            case Color::AMARILLO: return "AMARILLO";
            default: return "DESCONOCIDO";
        }
    }

    std::string orientacionToString(Orientacion o) const {
        return (o == Orientacion::HORIZONTAL) ? "HORIZONTAL" : "VERTICAL";
    }

public:
    void mostrarMenuPrincipal() const {
        std::cout << "\n===================================\n";
        std::cout << "     BUS JAM - MENU PRINCIPAL      \n";
        std::cout << "===================================\n";
        std::cout << "1. Cargar y Jugar Nivel\n";
        std::cout << "2. Salir\n";
        std::cout << "Seleccione una opcion: ";
    }

    void mostrarTablero(JuegoModel* model) const {
        if (!model || !model->getTablero()) return;

        std::cout << "\n======================================================\n";
        std::cout << "               ESTADO ACTUAL DEL TABLERO              \n";
        std::cout << "======================================================\n";

        const auto& vehiculos = model->getTablero()->getVehiculos();
        std::cout << "Vehiculos activos en cuadricula (" << vehiculos.size() << "):\n";
        
        if (vehiculos.empty()) {
            std::cout << "  [!] No quedan vehiculos en la cuadricula.\n";
        } else {
            for (const auto* v : vehiculos) {
                if (v) {
                    std::cout << "  -> ID: " << v->getId()
                              << " | Color: " << colorToString(v->getColor())
                              << " | Pos: (" << v->getX() << "," << v->getY() << ")"
                              << " | Ori: " << orientacionToString(v->getOrientacion())
                              << "\n";
                }
            }
        }
    }

    void mostrarEstadoParqueoYFilas(JuegoModel* model) const {
        if (!model) return;

        std::cout << "\n---------------- ZONA DE PARQUEO ---------------------\n";
        if (model->getZonaParqueo()) {
            const auto& parqueo = model->getZonaParqueo()->getVehiculos();
            std::cout << "Espacios ocupados: " << parqueo.size() << "/4\n";
            for (const auto* v : parqueo) {
                if (v) {
                    std::cout << "  [Parqueado] ID: " << v->getId()
                              << " | Color: " << colorToString(v->getColor())
                              << " | Pasajeros: " << v->getPasajerosAbordo() 
                              << "/" << v->getCapacidad() << "\n";
                }
            }
        }

        std::cout << "\n---------------- FILA DE PASAJEROS -------------------\n";
        if (model->getFilaEstatica()) {
            std::cout << "Pasajeros restantes en Fila: " 
                      << model->getFilaEstatica()->getCantidadRestante() << "\n";
        }
        std::cout << "======================================================\n";
    }

    void mostrarMensaje(const std::string& msg) const {
        std::cout << "\n[Info] " << msg << std::endl;
    }
};

#endif