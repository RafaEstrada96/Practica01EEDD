//
// Created by erafa on 20/09/2022.
//

#include "contenedor_Imagenes.h"
#include "algorithm"

contenedor_Imagenes::contenedor_Imagenes() {
    tam_Contenedor = 100;
    delete[] contenedor;
    contenedor = new imagen[tam_Contenedor];
}


contenedor_Imagenes::contenedor_Imagenes(unsigned int tamMax) {
    tam_Contenedor = tamMax;
    delete[] contenedor;
    contenedor = new imagen[tam_Contenedor];
}

contenedor_Imagenes::contenedor_Imagenes(const contenedor_Imagenes &ci) : contenedor(ci.contenedor), tam_Contenedor(ci.tam_Contenedor){}

contenedor_Imagenes::contenedor_Imagenes(const contenedor_Imagenes &ci, unsigned int posicionInicial,
                                         unsigned int numElementos) {
    int j = 0;
    contenedor = new imagen[numElementos];

    for(int i = posicionInicial; i < (posicionInicial+numElementos); i++, j++)
    {
        contenedor[j] = ci.contenedor[i];
    }
}

contenedor_Imagenes &contenedor_Imagenes::operator=(contenedor_Imagenes &contenedorImagenes) {

    delete[] contenedor;
    tam_Contenedor = contenedorImagenes.tam_Contenedor;
    contenedor = new imagen[tam_Contenedor];

    for (int i = 0; i < contenedorImagenes.tam_Contenedor; i++)
    {
        contenedor[i] = contenedorImagenes.contenedor[i];
    }
    return *this;
}

void contenedor_Imagenes::asigna(const imagen &dato, unsigned int pos) {
    try
    {
        contenedor[pos] = dato;
    } catch (out_of_range &e)
    {
        cout << "Posición no válida" << endl;
    }
}

imagen contenedor_Imagenes::recupera(unsigned int pos) {
    try
    {
        return contenedor[pos];
    } catch (out_of_range &e)
    {
        cout << "Posición no válida" << endl;
    }
    return imagen();
}

void contenedor_Imagenes::ordenar() {
    sort(contenedor, contenedor+tam_Contenedor);
}

void contenedor_Imagenes::ordenarRev() {
    sort(contenedor, contenedor+tam_Contenedor, std::greater<imagen>());
}

unsigned int contenedor_Imagenes::tam() {
    return tam_Contenedor;
}

contenedor_Imagenes::~contenedor_Imagenes() {
    delete[] contenedor;
    tam_Contenedor = 0;
}

bool contenedor_Imagenes::compare(imagen &imagen1, imagen &imagen2) {

    return imagen1 < imagen2;

}

bool contenedor_Imagenes::operator<(const contenedor_Imagenes &rhs) const {
    return stoi(this->contenedor->getId()) < stoi(rhs.contenedor->getId());
}

bool contenedor_Imagenes::operator>(const contenedor_Imagenes &rhs) const {
    return stoi(this->contenedor->getId()) > stoi(rhs.contenedor->getId());
}

bool contenedor_Imagenes::operator<=(const contenedor_Imagenes &rhs) const {
    return stoi(this->contenedor->getId()) <= stoi(rhs.contenedor->getId());
}

bool contenedor_Imagenes::operator>=(const contenedor_Imagenes &rhs) const {
    return stoi(this->contenedor->getId()) >= stoi(rhs.contenedor->getId());
}

bool contenedor_Imagenes::operator==(const contenedor_Imagenes &rhs) const {
    return stoi(this->contenedor->getId()) == stoi(rhs.contenedor->getId());
}

bool contenedor_Imagenes::operator!=(const contenedor_Imagenes &rhs) const {
    return stoi(this->contenedor->getId()) != stoi(rhs.contenedor->getId());
}
