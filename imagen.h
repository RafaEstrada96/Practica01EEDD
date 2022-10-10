//
// Created by admin on 20/09/2022.
//

#ifndef IMAGENES_IMAGEN_H
#define IMAGENES_IMAGEN_H

#include "string"
#include "iostream"
#include "fecha.h"
using namespace std;

class imagen {
private:
    string id="";
    string email="";
    string nombre="";
    int tam=0;
    Fecha fecha;
    string etiquetas="";

public:
    /** Crea una imágen vacia. */
    imagen();
    /** Crea una imágen con unos datos en concreto. */
    imagen(string id, string email, string nombre,int tam, Fecha fecha, string etiqueta);
    /** Constructor copia. */
    imagen(const imagen& img);
    /** Obtener id. */
    const string &getId() const;
    /** Asignar id. */
    void setId(const string &id);
    /** Obtener email. */
    const string &getEmail() const;
    /** Asignar email. */
    void setEmail(const string &email);
    /** Obtener nombre. */
    const string &getNombre() const;
    /** Asgnar nombre. */
    void setNombre(const string &nombre);
    /** Obtener el tamaño. */
    int getTam() const;
    /** Asignar el tamaño. */
    void setTam(int tam);
    /** Obtener Fecha. */
    const Fecha &getFecha() const;
    /** Asignar Fecha. */
    void setFecha(const Fecha &fecha);
    /** Obtener etiquetas. */
    const string &getEtiquetas() const;
    /** Asignar etiquetas. */
    void setEtiquetas(const string &etiquetas);

    virtual ~imagen();

    bool operator<(const imagen &rhs) const;

    bool operator>(const imagen &rhs) const;

    bool operator<=(const imagen &rhs) const;

    bool operator>=(const imagen &rhs) const;
};


#endif //IMAGENES_IMAGEN_H
