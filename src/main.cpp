#include <iostream>
#include <string>

#include "Cancion.h"
#include "Duracion.h"
#include "Playlist.h"
#include "Podcast.h"

namespace {

std::string formato(const Duracion& d) {
    return std::to_string(d.getMinutos()) + ":" +
           (d.getSegundos() < 10 ? "0" : "") + std::to_string(d.getSegundos());
}

void prueba(int caso, const std::string& nombre, const std::string& obtenido,
            const std::string& esperado) {
    std::cout << "Caso " << caso << " (" << nombre << "): esperado = " << esperado
              << " | obtenido = " << obtenido
              << (obtenido == esperado ? "  [OK]" : "  [FALLA]") << "\n";
}

std::string boolTexto(bool b) { return b ? "true" : "false"; }

}  // namespace

int main() {
    // ---------- Biblioteca de pistas (existen por su cuenta) ----------
    Cancion c1("Bohemian Rhapsody", 5, 55, "Queen", "Rock");
    Cancion c2("Billie Jean", 4, 54, "Michael Jackson", "Pop");
    Cancion c3("Clocks", 5, 7, "Coldplay", "Alternativo");
    Podcast p1("Introducción a C++", 32, 10, "Ana Torres", 1);
    Podcast p2("Herencia vs composición", 41, 25, "Luis Ramírez", 2);

    // ---------- Dos playlists que comparten pistas ----------
    Playlist estudio("Para estudiar");
    estudio.agregarCancion(&c3);
    estudio.agregarPodcast(&p1);
    estudio.agregarPodcast(&p2);

    Playlist fiesta("Fiesta");
    fiesta.agregarCancion(&c1);
    fiesta.agregarCancion(&c2);
    fiesta.agregarCancion(&c3);   // c3 está en las dos playlists

    estudio.mostrar();
    std::cout << "\n";
    fiesta.mostrar();

    // ---------- Fase 4: casos de prueba ----------
    std::cout << "\n--- Casos de prueba ---\n";

    prueba(1, "Duración normal", formato(Duracion(3, 45)), "3:45");
    prueba(2, "Segundos > 59", formato(Duracion(0, 75)), "1:15");
    prueba(3, "Valores negativos", formato(Duracion(-2, 10)), "0:00");

    Cancion sinTitulo("", 3, 0, "Anónimo", "Otro");
    prueba(4, "Título vacío", sinTitulo.getTitulo(), "Sin título");

    Playlist vacia("Vacía");
    prueba(5, "Playlist vacía", formato(vacia.duracionTotal()) + " y " +
           std::to_string(vacia.cantidadPistas()) + " pistas", "0:00 y 0 pistas");

    Playlist pruebas("Pruebas");
    Cancion a("Canción A", 3, 30, "Artista A", "Pop");
    Cancion b("Canción B", 4, 15, "Artista B", "Rock");
    Podcast pc("Podcast X", 20, 5, "Anfitrión X", 7);
    bool primera = pruebas.agregarCancion(&a);
    bool segunda = pruebas.agregarCancion(&a);
    prueba(6, "Canción duplicada", boolTexto(primera) + " y luego " + boolTexto(segunda),
           "true y luego false");

    prueba(7, "Puntero nulo", boolTexto(pruebas.agregarCancion(nullptr)), "false");

    pruebas.agregarCancion(&b);
    pruebas.agregarPodcast(&pc);
    // 3:30 + 4:15 + 20:05 = 27:50
    prueba(8, "Total mixto", formato(pruebas.duracionTotal()), "27:50");

    return 0;
}
