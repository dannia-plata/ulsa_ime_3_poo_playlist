#include "Duracion.h"

#include <iostream>

Duracion::Duracion(int min, int seg) : minutos(0), segundos(0) {
    // Caso límite: cualquier valor negativo deja la duración en 0:00.
    if (min >= 0 && seg >= 0) {
        int total = min * 60 + seg;   // normaliza segundos > 59
        minutos = total / 60;
        segundos = total % 60;
    }
}

int Duracion::getMinutos() const { return minutos; }

int Duracion::getSegundos() const { return segundos; }

int Duracion::totalSegundos() const { return minutos * 60 + segundos; }

void Duracion::imprimir() const {
    std::cout << minutos << ":" << (segundos < 10 ? "0" : "") << segundos;
}
