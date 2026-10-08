// Implementación de la clase Podcast.

#include "Podcast.h"

#include <iostream>

// TODO 3.2: implementa el constructor, los accedentes y mostrar() de Podcast.

Podcast::Podcast(const std::string& titulo, int min, int seg,
                 const std::string& anfitrion, int episodio)
    : Pista(titulo, min, seg), anfitrion(anfitrion), episodio(episodio) {}

const std::string& Podcast::getAnfitrion() const { return anfitrion; }

int Podcast::getEpisodio() const { return episodio; }

void Podcast::mostrar() const {
    std::cout << "[Podcast] ";
    mostrarInfo();
    std::cout << " - Anfitrión: " << anfitrion << " | Episodio " << episodio << "\n";
}
