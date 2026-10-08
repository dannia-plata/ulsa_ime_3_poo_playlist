// Interfaz de la clase Pista (clase base).
// Relación: una Pista TIENE UNA Duracion (composición).

#ifndef PISTA_H
#define PISTA_H

#include <string>

#include "Duracion.h"

class Pista {
private:
    std::string titulo;
    Duracion duracion;   // composición: la Pista crea y destruye su Duracion

public:
    // Si el título viene vacío se guarda "Sin título".
    Pista(const std::string& titulo, int min, int seg);

    const std::string& getTitulo() const;
    const Duracion& getDuracion() const;
    void setTitulo(const std::string& nuevoTitulo);   // misma regla del título vacío

    void mostrarInfo() const;   // "Título (m:ss)" sin salto de línea
};

#endif
