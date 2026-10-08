#include "Pista.h"

#include <iostream>

Pista::Pista(const std::string& titulo, int min, int seg)
    : titulo(titulo.empty() ? "Sin título" : titulo), duracion(min, seg) {
}

const std::string& Pista::getTitulo() const { return titulo; }

const Duracion& Pista::getDuracion() const { return duracion; }

void Pista::setTitulo(const std::string& nuevoTitulo) {
    titulo = nuevoTitulo.empty() ? "Sin título" : nuevoTitulo;
}

void Pista::mostrarInfo() const {
    std::cout << titulo << " (";
    duracion.imprimir();
    std::cout << ")";
}
