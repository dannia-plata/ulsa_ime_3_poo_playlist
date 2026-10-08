#include "Playlist.h"

#include <algorithm>
#include <iostream>

Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

bool Playlist::agregarCancion(Cancion* cancion) {
    if (cancion == nullptr) return false;
    if (std::find(canciones.begin(), canciones.end(), cancion) != canciones.end()) {
        return false;   // duplicada
    }
    canciones.push_back(cancion);
    return true;
}

bool Playlist::agregarPodcast(Podcast* podcast) {
    if (podcast == nullptr) return false;
    if (std::find(podcasts.begin(), podcasts.end(), podcast) != podcasts.end()) {
        return false;   // duplicado
    }
    podcasts.push_back(podcast);
    return true;
}

const std::string& Playlist::getNombre() const { return nombre; }

int Playlist::cantidadPistas() const {
    return static_cast<int>(canciones.size() + podcasts.size());
}

Duracion Playlist::duracionTotal() const {
    int total = 0;
    for (const Cancion* c : canciones) total += c->getDuracion().totalSegundos();
    for (const Podcast* p : podcasts) total += p->getDuracion().totalSegundos();
    return Duracion(0, total);   // el constructor normaliza a m:ss
}

void Playlist::mostrar() const {
    std::cout << "=== Playlist: " << nombre << " (" << cantidadPistas()
              << " pistas, total ";
    duracionTotal().imprimir();
    std::cout << ") ===\n";
    int n = 1;
    for (const Cancion* c : canciones) {
        std::cout << n++ << ". ";
        c->mostrar();
    }
    for (const Podcast* p : podcasts) {
        std::cout << n++ << ". ";
        p->mostrar();
    }
}
