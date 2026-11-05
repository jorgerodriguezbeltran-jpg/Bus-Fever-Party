// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: FilaEstatica.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: FilaEstatica
  ==============================================================================
  Responsabilidades:
  - Almacenar la cola FIFO de pasajeros que aguardan por ingresar al juego.
  - Proveer el siguiente pasajero en orden para alimentar la FilaRotatoria.

  Colaboradores:
  - Pasajero
  ==============================================================================
*/

#ifndef FILAESTATICA_H
#define FILAESTATICA_H

#include <queue>
#include "Pasajero.h"

/**
 * @class FilaEstatica
 * @brief Fila de espera inicial de pasajeros (FIFO).
 */
class FilaEstatica {
private:
    std::queue<Pasajero*> colaPasajeros;

public:
    FilaEstatica() = default;

    void agregarPasajero(Pasajero* p) {
        if (p) colaPasajeros.push(p);
    }

    Pasajero* extraerSiguiente() {
        if (colaPasajeros.empty()) return nullptr;
        Pasajero* p = colaPasajeros.front();
        colaPasajeros.pop();
        return p;
    }

    bool estaVacia() const {
        return colaPasajeros.empty();
    }

    int getCantidadRestante() const {
        return static_cast<int>(colaPasajeros.size());
    }
};

#endif