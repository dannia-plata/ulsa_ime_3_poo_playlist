// Interfaz de la clase Duracion.
// Relación: una Pista TIENE UNA Duracion (composición).

#ifndef DURACION_H
#define DURACION_H

class Duracion {
private:
    int minutos;
    int segundos;

public:
    // Valida y normaliza: valores negativos -> 0:00; 0:75 -> 1:15.
    Duracion(int min = 0, int seg = 0);

    int getMinutos() const;
    int getSegundos() const;
    int totalSegundos() const;
    void imprimir() const;   // imprime m:ss (sin salto de línea)
};

#endif
