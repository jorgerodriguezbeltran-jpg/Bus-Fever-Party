// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: JuegoController.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: JuegoController
  ==============================================================================
  Responsabilidades:
  - Actuar como intermediario entre la entrada del jugador (Vista) y el Modelo.
  - Procesar la selección e intento de movimiento de los vehículos por su ID.

  Colaboradores:
  - JuegoModel, JuegoView, Vehiculo
  ==============================================================================
*/

#ifndef JUEGOCONTROLLER_H
#define JUEGOCONTROLLER_H

#include "JuegoModel.h"
#include "JuegoView.h"

/**
 * @class JuegoController
 * @brief Módulo controlador que coordina eventos de entrada entre Vista y Modelo.
 */
class JuegoController {
private:
    JuegoModel* model;
    JuegoView* view;

public:
    JuegoController(JuegoModel* m, JuegoView* v) : model(m), view(v) {}

    void iniciarJuego() {
        if (!model || !view) return;
        view->mostrarMenuPrincipal();
    }

    void seleccionarYMoverVehiculo(int id) {
        if (!model) return;
        Vehiculo* v = model->getTablero()->buscarVehiculoPorId(id);
        if (v && model->getTablero()->caminoDespejadoHastaSalida(v)) {
            if (model->getZonaParqueo()->agregarVehiculo(v)) {
                model->getTablero()->removerVehiculo(v);
                model->ejecutarCicloAbordaje();
            }
        }
    }
};

#endif