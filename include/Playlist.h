// Interfaz de la clase Playlist.
// Relación: una Playlist USA canciones y podcasts que ya existen (agregación).

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>

#include "Cancion.h"
#include "Duracion.h"
#include "Podcast.h"

class Playlist {
private:
    std::string nombre;
    // Punteros a pistas que NO le pertenecen: la playlist nunca hace delete.
    std::vector<Cancion*> canciones;
    std::vector<Podcast*> podcasts;

public:
    explicit Playlist(const std::string& nombre);

    // Devuelven false si el puntero es nullptr o la pista ya estaba agregada.
    bool agregarCancion(Cancion* cancion);
    bool agregarPodcast(Podcast* podcast);

    const std::string& getNombre() const;
    int cantidadPistas() const;
    Duracion duracionTotal() const;
    void mostrar() const;
};

#endif
