// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: JuegoModel.h
// Autores:
//   Samuel Martinez Muñoz | Código: 202535015 | samuel.martinez.munoz@correounivalle.edu.co
//   Sofia Montealegre Polanco | Código: 2129809 | Sofia.montealegre@correounivalle.edu.co
//   Samuel Tellez Caicedo | Código: 202540928 | samuel.tellez@correounivalle.edu.co
//   Alejandro Murillo Renteria | Código: 202538979 | alejandro.murillo@correounivalle.edu.co
//   Jorge Andres Rodriguez Beltran | Código: 202618237 | jorge.rodriguez.beltran@correounivalle.edu.co
// Fecha: 02/11/2026

/*
  ==============================================================================
  TARJETA CRC - Clase: JuegoModel
  ==============================================================================
  Responsabilidades:
  - Cargar el estado inicial de la partida desde archivos planos (.txt).
  - Coordinar la interacción entre el Tablero, Filas y ZonaParqueo.
  - Ejecutar el ciclo de abordaje y verificar las reglas de victoria o derrota.

  Colaboradores:
  - Tablero, FilaEstatica, FilaRotatoria, ZonaParqueo, Carro, Bus, Pasajero
  ==============================================================================
*/

#ifndef JUEGOMODEL_H
#define JUEGOMODEL_H

#include <iostream>
#include <fstream>
#include <string>

#include "Enums.h"
#include "Tablero.h"
#include "Carro.h"
#include "Bus.h"
#include "Pasajero.h"
#include "FilaEstatica.h"
#include "FilaRotatoria.h"
#include "ZonaParqueo.h"

/**
 * @class JuegoModel
 * @brief Administrador central del estado del juego y carga de niveles.
 */
class JuegoModel {
private:
    Tablero* tablero;
    FilaEstatica* filaEstatica;
    FilaRotatoria* filaRotatoria;
    ZonaParqueo* zonaParqueo;
    bool juegoTerminado;
    bool victoria;

    Color stringToColor(const std::string& str) {
        if (str == "ROJO") return Color::ROJO;
        if (str == "AZUL") return Color::AZUL;
        if (str == "VERDE") return Color::VERDE;
        if (str == "AMARILLO") return Color::AMARILLO;
        if (str == "MORADO") return Color::MORADO;
        return Color::ROJO;
    }

public:
    JuegoModel() {
        tablero = nullptr;
        filaEstatica = new FilaEstatica();
        filaRotatoria = new FilaRotatoria();
        zonaParqueo = new ZonaParqueo();
        juegoTerminado = false;
        victoria = false;
    }

    ~JuegoModel() {
        if (tablero != nullptr) delete tablero;
        delete filaEstatica;
        delete filaRotatoria;
        delete zonaParqueo;
    }

    void ejecutarCicloAbordaje() {
        // Lógica reservada para el procesamiento de pasajeros y buses
    }

    bool cargarNivel(const std::string& filename) {
        std::ifstream file;

        // Búsqueda usando exclusivamente rutas relativas portátiles
        file.open(filename);
        if (!file.is_open()) file.open("./" + filename);
        if (!file.is_open()) file.open("output/" + filename);
        if (!file.is_open()) file.open("PROYECTO/" + filename);
        if (!file.is_open()) file.open("../" + filename);

        if (!file.is_open()) return false;

        int filas, cols;
        if (!(file >> filas >> cols)) {
            file.close();
            return false;
        }

        if (tablero != nullptr) {
            delete tablero;
        }
        tablero = new Tablero(filas, cols);

        int cantVehiculos;
        if (!(file >> cantVehiculos)) {
            file.close();
            return false;
        }

        for (int i = 0; i < cantVehiculos; ++i) {
            int id, x, y;
            std::string tipo, orientacionStr, colorStr;
            if (!(file >> id >> tipo >> x >> y >> orientacionStr >> colorStr)) {
                file.close();
                return false;
            }

            Orientacion o = (orientacionStr == "HORIZONTAL") ? Orientacion::HORIZONTAL : Orientacion::VERTICAL;
            Color c = stringToColor(colorStr);

            if (tipo == "Carro") {
                tablero->agregarVehiculo(new Carro(id, x, y, o, c));
            } else if (tipo == "Bus") {
                int largo, cap;
                if (!(file >> largo >> cap)) {
                    file.close();
                    return false;
                }
                tablero->agregarVehiculo(new Bus(id, x, y, largo, o, c, cap));
            }
        }

        int cantPasajeros;
        if (!(file >> cantPasajeros)) {
            file.close();
            return false;
        }

        for (int i = 0; i < cantPasajeros; ++i) {
            std::string colorStr;
            if (!(file >> colorStr)) {
                file.close();
                return false;
            }
            filaEstatica->agregarPasajero(new Pasajero(stringToColor(colorStr)));
        }

        file.close();
        juegoTerminado = false;
        victoria = false;
        return true;
    }

    Tablero* getTablero() const { return tablero; }
    FilaEstatica* getFilaEstatica() const { return filaEstatica; }
    FilaRotatoria* getFilaRotatoria() const { return filaRotatoria; }
    ZonaParqueo* getZonaParqueo() const { return zonaParqueo; }
    
    // Métodos de estado compatibles con Main.cpp
    bool estaTerminado() const { return juegoTerminado; }
    bool esVictoria() const { return victoria; }
    bool isJuegoTerminado() const { return juegoTerminado; }
    bool isVictoria() const { return victoria; }
};

#endif