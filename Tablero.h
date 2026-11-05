// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Tablero.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: Tablero
  ==============================================================================
  Responsabilidades:
  - Gestionar las dimensiones de la cuadrícula de juego (filas x columnas).
  - Almacenar la colección de vehículos activos en el tablero.
  - Verificar la presencia de obstáculos y calcular si la trayectoria recta
    hacia la salida está despejada.

  Colaboradores:
  - Vehiculo
  ==============================================================================
*/

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include "Vehiculo.h"

class Tablero {
private:
    int filas;
    int columnas;
    std::vector<Vehiculo*> vehiculos;

public:
    Tablero(int f, int c) : filas(f), columnas(c) {}

    ~Tablero() {
        for (auto v : vehiculos) {
            delete v;
        }
        vehiculos.clear();
    }

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    const std::vector<Vehiculo*>& getVehiculos() const { return vehiculos; }

    void agregarVehiculo(Vehiculo* v) {
        vehiculos.push_back(v);
    }

    Vehiculo* buscarVehiculoPorId(int id) {
        for (auto v : vehiculos) {
            if (v->getId() == id) return v;
        }
        return nullptr;
    }

    // Comprueba si alguna posición (f, c) en la matriz está ocupada por un vehículo
    bool hayVehiculoEn(int f, int c, Vehiculo* ignorar = nullptr) const {
        for (auto v : vehiculos) {
            if (v == ignorar) continue;

            int vx = v->getPosX();
            int vy = v->getPosY();
            int vlargo = v->getLargo();
            Orientacion ori = v->getOrientacion();

            if (ori == Orientacion::HORIZONTAL) {
                if (vx == f && c >= vy && c < vy + vlargo) return true;
            } else {
                if (vy == c && f >= vx && f < vx + vlargo) return true;
            }
        }
        return false;
    }

    // Verifica que el camino desde la posición frontal del vehículo hasta la salida esté despejado
    bool caminoDespejadoHastaSalida(Vehiculo* v) {
        if (!v) return false;

        int x = v->getPosX();
        int y = v->getPosY();
        int largo = v->getLargo();
        Orientacion ori = v->getOrientacion();

        if (ori == Orientacion::HORIZONTAL) {
            for (int col = y + largo; col < columnas; ++col) {
                if (hayVehiculoEn(x, col, v)) return false;
            }
        } else {
            for (int fila = x + largo; fila < filas; ++fila) {
                if (hayVehiculoEn(fila, y, v)) return false;
            }
        }
        return true;
    }

    bool removerVehiculo(Vehiculo* v) {
        for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
            if (*it == v) {
                vehiculos.erase(it);
                return true;
            }
        }
        return false;
    }
};

#endif