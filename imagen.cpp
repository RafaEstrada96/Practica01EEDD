//
// Created by admin on 20/09/2022.
//

#include "imagen.h"

imagen::imagen() {}

imagen::imagen(string _id, string _email, string _nombre,int _tam, Fecha _fecha, string _etiqueta) {
    id = _id;
    email = _email;
    nombre = _nombre;
    tam = _tam;
    fecha = _fecha;
    etiquetas = _etiqueta;
}

imagen::imagen(const imagen &img) : id(img.id), email(img.email), nombre(img.nombre),
                                    tam(img.tam), fecha(img.fecha), etiquetas(img.etiquetas) {}

const string &imagen::getId() const {
    return id;
}

void imagen::setId(const string &id) {
    imagen::id = id;
}

const string &imagen::getEmail() const {
    return email;
}

void imagen::setEmail(const string &email) {
    imagen::email = email;
}

const string &imagen::getNombre() const {
    return nombre;
}

void imagen::setNombre(const string &nombre) {
    imagen::nombre = nombre;
}

int imagen::getTam() const {
    return tam;
}

void imagen::setTam(int tam) {
    imagen::tam = tam;
}

const Fecha &imagen::getFecha() const {
    return fecha;
}

void imagen::setFecha(const Fecha &fecha) {
    imagen::fecha = fecha;
}

const string &imagen::getEtiquetas() const {
    return etiquetas;
}

void imagen::setEtiquetas(const string &etiquetas) {
    imagen::etiquetas = etiquetas;
}

bool imagen::operator<(const imagen &rhs) const {
    if(stoi(id) < stoi(rhs.id))
    {
        return true;
    }
    return false;
}

bool imagen::operator>(const imagen &rhs) const {
    if(stoi(id) > stoi(rhs.id))
    {
        return true;
    }
    return false;
}

bool imagen::operator<=(const imagen &rhs) const {
    if(stoi(id) <= stoi(rhs.id))
    {
        return true;
    }
    return false;
}

bool imagen::operator>=(const imagen &rhs) const {
    if(stoi(id) >= stoi(rhs.id))
    {
        return true;
    }
    return false;
}

imagen::~imagen() {
    id="";
    email="";
    nombre="";
    tam=0;
    fecha = Fecha();
    etiquetas="";
}


