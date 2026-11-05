// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Enums.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Enum: Enums
  ==============================================================================
  Responsabilidades:
  - Definir las enumeraciones globales del juego (Orientacion y Color).
  - Proveer un tipado fuerte para la dirección de movimiento y representación
    visual de los elementos.

  Colaboradores:
  - Ninguno (Tipos base del sistema)
  ==============================================================================
*/

#ifndef ENUMS_H
#define ENUMS_H

/**
 * @file Enums.h
 * @brief Definición de enumeraciones globales para el juego.
 */

/**
 * @enum Orientacion
 * @brief Indica la dirección del movimiento del vehículo en el tablero.
 */
enum class Orientacion {
    HORIZONTAL,
    VERTICAL
};

/**
 * @enum Color
 * @brief Colores asociados a vehículos y pasajeros.
 */
enum class Color {
    ROJO,
    AZUL,
    AMARILLO,
    VERDE,
    MORADO
};

#endif