// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Carro.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: Carro
  ==============================================================================
  Responsabilidades:
  - Representar un automóvil estándar en el juego.
  - Concretar sus dimensiones fijas (largo 2) y capacidad predeterminada.

  Colaboradores:
  - Vehiculo (Clase padre)
  ==============================================================================
*/

#ifndef CARRO_H
#define CARRO_H

#include "Vehiculo.h"

/**
 * @class Carro
 * @brief Representa un carro estándar (Largo 2, Capacidad 2).
 */
class Carro : public Vehiculo {
public:
    Carro(int id, int x, int y, Orientacion o, Color c)
        : Vehiculo(id, x, y, 2, o, c, 2) {}

    std::string getType() const override {
        return "Carro";
    }
};

#endif