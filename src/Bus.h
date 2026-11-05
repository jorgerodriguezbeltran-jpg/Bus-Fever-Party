// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Bus.h
// Autores:
//   Samuel Martinez Muñoz  | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: Bus
  ==============================================================================
  Responsabilidades:
  - Representar un autobús de pasajeros en el juego.
  - Soportar largo y capacidad parametrizables según la definición del nivel.

  Colaboradores:
  - Vehiculo (Clase padre)
  ==============================================================================
*/

#ifndef BUS_H
#define BUS_H

#include "Vehiculo.h"

/**
 * @class Bus
 * @brief Representa un autobús (Largo y Capacidad variables).
 */
class Bus : public Vehiculo {
public:
    Bus(int id, int x, int y, int largo, Orientacion o, Color c, int cap)
        : Vehiculo(id, x, y, largo, o, c, cap) {}

    std::string getType() const override {
        return "Bus";
    }
};

#endif