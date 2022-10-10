//
// Created by erafa on 20/09/2022.
//

#ifndef IMAGENES_CONTENEDOR_IMAGENES_H
#define IMAGENES_CONTENEDOR_IMAGENES_H

#include "vector"
#include "imagen.h"
#include "iostream"

using namespace std;

class contenedor_Imagenes {
private:

    /** Vector de imágenes. */
    imagen *contenedor = new imagen[0];
    /** Tamaño del vector de imágenes. */
    int tam_Contenedor = 0;

public:

    /** Crea un contenedor de imágenes con un tamaño de 100. */
    contenedor_Imagenes();
    /** Crea un contenedor de imágenes con un tamaño en concreto. */
    contenedor_Imagenes(unsigned int tamMax);
    /** Constructor copia */
    contenedor_Imagenes(const contenedor_Imagenes &ci);
    /** Constructor copia parcial. Se realizario una copia parcial de un contenedor de imágenes. */
    contenedor_Imagenes(const contenedor_Imagenes &contenedor, unsigned int posicionInicial, unsigned int numElementos);
    /** Asignar contenedores de imágenes. */
    contenedor_Imagenes& operator=(contenedor_Imagenes& contenedorImagenes);
    /** Asignará una imagen en una posición concreta en el contenedor de imágenes. */
    void asigna(const imagen& dato, unsigned int pos);
    /** Devolverá una imagen dada una posición. */
    imagen recupera(unsigned int pos);
    /** Ordena el contenedor de imágenes de menor a mayor. */
    void ordenar();
    /** Ordena el contenedor de imágenes de mayor a menor. */
    void ordenarRev();
    /** Devuelve el tamaño del contenedor de imágenes es decir la cantidad de imágenes que caben en él. */
    unsigned int tam();
    /** Destructor del contenedor de imágenes. */
    virtual ~contenedor_Imagenes();
    bool compare(imagen &imagen1, imagen &imagen2);

    bool operator<(const contenedor_Imagenes &rhs) const;

    bool operator>(const contenedor_Imagenes &rhs) const;

    bool operator<=(const contenedor_Imagenes &rhs) const;

    bool operator>=(const contenedor_Imagenes &rhs) const;

    bool operator==(const contenedor_Imagenes &rhs) const;

    bool operator!=(const contenedor_Imagenes &rhs) const;
};


#endif //IMAGENES_CONTENEDOR_IMAGENES_H
