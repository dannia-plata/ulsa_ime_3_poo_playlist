// Interfaz de la clase Podcast.
// Relación: un Podcast ES UNA Pista (herencia).

#ifndef PODCAST_H
#define PODCAST_H

#include <string>

#include "Pista.h"

class Podcast : public Pista {
private:
    std::string anfitrion;
    int episodio;

public:
    Podcast(const std::string& titulo, int min, int seg,
            const std::string& anfitrion, int episodio);

    const std::string& getAnfitrion() const;
    int getEpisodio() const;
    void mostrar() const;
};

#endif
