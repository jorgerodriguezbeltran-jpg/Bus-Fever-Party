// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Pasajero.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: Pasajero
  ==============================================================================
  Responsabilidades:
  - Representar a un pasajero individual dentro del juego.
  - Almacenar y retornar su color asociado para la validación de abordaje.

  Colaboradores:
  - Enums (Color)
  ==============================================================================
*/

#ifndef PASAJERO_H
#define PASAJERO_H

#include "Enums.h"

/**
 * @class Pasajero
 * @brief Representa a un pasajero individual con un color específico.
 */
class Pasajero {
private:
    Color color;

public:
    /**
     * @brief Constructor de Pasajero.
     * @param c Color asignado al pasajero.
     */
    Pasajero(Color c) : color(c) {}

    /**
     * @brief Obtiene el color del pasajero.
     * @return Color del pasajero.
     */
    Color getColor() const {
        return color;
    }
};

#endif