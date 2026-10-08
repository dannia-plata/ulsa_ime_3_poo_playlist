// Interfaz de la clase Cancion.
// Relación: una Cancion ES UNA Pista (herencia).

#ifndef CANCION_H
#define CANCION_H

#include <string>

#include "Pista.h"

// Clase Cancion derivada de Pista (herencia pública).
class Cancion : public Pista {
private:
    std::string artista;
    std::string genero;

public:
    Cancion(const std::string& titulo, int min, int seg,
            const std::string& artista, const std::string& genero);

    const std::string& getArtista() const;
    const std::string& getGenero() const;
    void mostrar() const;
};

// Pregunta: ¿puede Cancion leer directamente el atributo titulo de Pista?
// ¿Por qué sí o por qué no?
// Respuesta: NO. titulo es privado en Pista; ni las clases derivadas lo ven.
// Cancion usa la interfaz pública de su base (getTitulo(), mostrarInfo()),
// igual que cualquier otro código. Así Pista conserva el control de su regla
// del "título vacío".

#endif
