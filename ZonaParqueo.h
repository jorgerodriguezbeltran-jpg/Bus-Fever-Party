// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: ZonaParqueo.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: ZonaParqueo
  ==============================================================================
  Responsabilidades:
  - Administrar los espacios límite de estacionamiento (máximo 4 espacios).
  - Recibir vehículos procedentes del tablero y liberarlos cuando completan su cupo.

  Colaboradores:
  - Vehiculo
  ==============================================================================
*/

#ifndef ZONAPARQUEO_H
#define ZONAPARQUEO_H

#include <vector>
#include <algorithm>
#include "Vehiculo.h"

/**
 * @class ZonaParqueo
 * @brief Almacena temporalmente los vehículos listos para recibir pasajeros.
 */
class ZonaParqueo {
private:
    int maxCapacidad;
    std::vector<Vehiculo*> espacios;

public:
    ZonaParqueo(int cap = 4) : maxCapacidad(cap) {}

    bool agregarVehiculo(Vehiculo* v) {
        if (espacios.size() < static_cast<size_t>(maxCapacidad) && v != nullptr) {
            espacios.push_back(v);
            return true;
        }
        return false;
    }

    void removerVehiculo(Vehiculo* v) {
        espacios.erase(std::remove(espacios.begin(), espacios.end(), v), espacios.end());
    }

    bool estaLlena() const {
        return espacios.size() >= static_cast<size_t>(maxCapacidad);
    }

    std::vector<Vehiculo*>& getVehiculos() {
        return espacios;
    }
};

#endif