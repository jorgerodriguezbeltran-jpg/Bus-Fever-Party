// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: FilaRotatoria.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: FilaRotatoria
  ==============================================================================
  Responsabilidades:
  - Gestionar el arreglo circular de capacidad fija para el embarque de pasajeros.
  - Rotar las posiciones de los pasajeros y entregar el pasajero ubicado en la
    posición de embarque hacia los vehículos estacionados.

  Colaboradores:
  - Pasajero
  ==============================================================================
*/

#ifndef FILAROTATORIA_H
#define FILAROTATORIA_H

#include <vector>
#include "Pasajero.h"

/**
 * @class FilaRotatoria
 * @brief Mecanismo circular para la entrega de pasajeros a los vehículos.
 */
class FilaRotatoria {
private:
    int capacidad;
    int posicionEmbarque;
    std::vector<Pasajero*> asientos;

public:
    FilaRotatoria(int cap = 4) : capacidad(cap), posicionEmbarque(0), asientos(cap, nullptr) {}

    bool insertarPasajero(Pasajero* p) {
        for (int i = 0; i < capacidad; ++i) {
            if (asientos[i] == nullptr) {
                asientos[i] = p;
                return true;
            }
        }
        return false;
    }

    Pasajero* obtenerEnEmbarque() const {
        return asientos[posicionEmbarque];
    }

    Pasajero* removerEnEmbarque() {
        Pasajero* p = asientos[posicionEmbarque];
        asientos[posicionEmbarque] = nullptr;
        return p;
    }

    void rotar() {
        if (capacidad > 0) {
            posicionEmbarque = (posicionEmbarque + 1) % capacidad;
        }
    }

    bool estaVacia() const {
        for (const auto& p : asientos) {
            if (p != nullptr) return false;
        }
        return true;
    }

    bool tieneEspacio() const {
        for (const auto& p : asientos) {
            if (p == nullptr) return true;
        }
        return false;
    }
};

#endif