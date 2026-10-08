#include "Cancion.h"

#include <iostream>

Cancion::Cancion(const std::string& titulo, int min, int seg,
                 const std::string& artista, const std::string& genero)
    : Pista(titulo, min, seg), artista(artista), genero(genero) {}

const std::string& Cancion::getArtista() const { return artista; }

const std::string& Cancion::getGenero() const { return genero; }

void Cancion::mostrar() const {
    std::cout << "[Canción] ";
    mostrarInfo();
    std::cout << " - " << artista << " | " << genero << "\n";
}
