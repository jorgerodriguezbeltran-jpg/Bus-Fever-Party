// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Vehiculo.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: Vehiculo (Abstracta)
  ==============================================================================
  Responsabilidades:
  - Servir de clase base abstracta para todos los vehículos de la cuadrícula.
  - Almacenar coordenadas, orientación, tamaño, color y cupo de pasajeros.
  - Controlar el incremento de pasajeros y determinar si el vehículo está lleno.

  Colaboradores:
  - Enums (Orientacion, Color)
  ==============================================================================
*/
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "Enums.h"

/**
 * @class Vehiculo
 * @brief Clase abstracta base que representa cualquier vehículo en el juego.
 */
class Vehiculo {
protected:
    int id;
    int posX;
    int posY;
    int largo;
    Orientacion orientacion;
    Color color;
    int capacidadMaxima;
    int pasajerosActuales;

public:
    /**
     * @brief Constructor base de Vehiculo.
     */
    Vehiculo(int idVal, int x, int y, int l, Orientacion o, Color c, int cap)
        : id(idVal), posX(x), posY(y), largo(l), orientacion(o), color(c), capacidadMaxima(cap), pasajerosActuales(0) {}

    virtual ~Vehiculo() = default;

    /**
     * @brief Retorna el tipo concreto de vehículo.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Incrementa el conteo de pasajeros si hay espacio libre.
     * @return true si se pudo abordar, false si ya estaba lleno.
     */
    bool abordarPasajero() {
        if (!estaLleno()) {
            pasajerosActuales++;
            return true;
        }
        return false;
    }

    /**
     * @brief Revisa si el vehículo alcanzó su capacidad máxima.
     */
    bool estaLleno() const {
        return pasajerosActuales >= capacidadMaxima;
    }

    // --- Getters Principales ---
    int getId() const { return id; }
    Color getColor() const { return color; }
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    int getLargo() const { return largo; }
    Orientacion getOrientacion() const { return orientacion; }
    int getPasajerosActuales() const { return pasajerosActuales; }
    int getCapacidadMaxima() const { return capacidadMaxima; }

    // --- Métodos Alias (compatibilidad directa con JuegoView) ---
    int getX() const { return posX; }
    int getY() const { return posY; }
    int getCapacidad() const { return capacidadMaxima; }
    int getPasajerosAbordo() const { return pasajerosActuales; }

    // --- Setters ---
    void setPosX(int x) { posX = x; }
    void setPosY(int y) { posY = y; }
};

#endif