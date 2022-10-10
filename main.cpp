#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "contenedor_Imagenes.h"
#include "imagen.h"
#include "fecha.h"

using namespace std;
/** Esta función realiza la ordenación del contenedor de imágenes de mayor a menor
 *  y se mostrará en pantalla los datos que se nos piden.
 *  En este caso se mostraria (Id, Email, Fichero, Tamaño, Fecha, Etiquetas).
 * */
void ejercicio2 (contenedor_Imagenes &cont_Image)
{
    int contador2 = 0;
    ///Función de ordenar el contenedor de imágenes de mayor a menor.
    cont_Image.ordenarRev();
    for (int i = 0; i < cont_Image.tam(); i++)
    {
        std::cout << ++contador2
                  << " Imagen: ( ID=" << cont_Image.recupera(i).getId()
                  << " Email=" << cont_Image.recupera(i).getEmail() << " Fichero=" << cont_Image.recupera(i).getNombre()
                  << " Tam=" << cont_Image.recupera(i).getTam()
                  << " Fecha=" << cont_Image.recupera(i).getFecha().verDia() << "/" << cont_Image.recupera(i).getFecha().verMes() << "/" << cont_Image.recupera(i).getFecha().verAnio()
                  << " Etiquetas=" << cont_Image.recupera(i).getEtiquetas()
                  << ")" << std::endl;
    }
}
/** Esta función realiza la ordenación del contenedor de imágenes de menor a mayor
 *  y se mostrará en pantalla los datos que se nos piden.
 *  En este caso se mostraria (Id).
 * */
void ejercicio3(contenedor_Imagenes &cont_Image)
{
    int contador3 = 0;
    ///Función de ordenar el contenedor de imágenes de menor a mayor.
    cont_Image.ordenar();
    for(int i = 0; i < 20; i++){
        std::cout << ++contador3
                  << " Imagen: ( ID=" << cont_Image.recupera(i).getId()
                  << ")" << std::endl;
    }
}
/** Esta función realiza la búsqueda de una imágen segun el id de la imágen.
 *  Se devuelve la posición de la imágen en el contenedor (Si se encuentra).
 *  Si no se encuentra, se devolverá -1.
 * */
int buscar_Id(contenedor_Imagenes &contenedor_Img, string id_Buscar)
{
    int i = 0, pos = -1;
    bool esta = false;

    while (i < contenedor_Img.tam() && esta == false)
    {
        if (contenedor_Img.recupera(i).getId() == id_Buscar)
        {
            esta = true;
            pos = i;
        }
        i++;
    }
    return pos;
}
/** @author Rafael Aznar Estrada rae00010@red.ujaen.es
 *  @author Manuel Sánchez Salazar mss00048@red.ujaen.es
 **/
int main() {
    /// Variables que se usarán para la lectura del fichero.
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;
    std::string id = "", email="", nombre="", etiquetas="";
    int tam = 0, dia = 0, mes = 0, anno = 0;
    clock_t t_ini_total = clock();
    ///Realización del primer ejercicio.
    cout << "Primer ejercicio:" << endl;
    /// Creción de un contenedor de imágenes cuyo tamaño seria 10000.
    contenedor_Imagenes *cont_Image = new contenedor_Imagenes(10000);   //Instanciar el contenedor de imágenes a un tamaño de 10000.
    int cont = 0;   //Contador para movernos por el contenedor.
    /// Lectura del fichero y añadir al contenedor de imagenes.
    is.open("../imagenes_v1.csv");
    if( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {
            if (fila!="") {

                columnas.str(fila);

                imagen img = imagen();

                //formato de fila: id;email;nombre;tam;fecha;etiquetas

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                //img.setId(id);
                getline(columnas,email,';');
                //img.setEmail(email);
                getline(columnas,nombre,';');
                //img.setNombre(nombre);

                columnas >> tam;   //las secuencia numéricas se leen y trasforman directamente
                columnas.ignore(); //omitimos carácter ';' siguiente
                //img.setTam(tam);

                columnas >> dia; columnas.ignore();
                columnas >> mes; columnas.ignore();
                columnas >> anno; columnas.ignore();

                //img.setFecha(Fecha(dia, mes, anno));

                getline(columnas,etiquetas,';');
                //img.setEtiquetas(etiquetas);

                img = imagen(id,email,nombre,tam, Fecha(dia,mes,anno),etiquetas);
                cont_Image->asigna(img, cont);  //Se introduce la imagen obtenida en el contenedor de imágenes.
                cont++; //Se aumenta el contenedor de imágenes.

                fila="";
                columnas.clear();
            }
        }
        is.close();
        ///Recorremos el contenedor de imágenes para poder mostrar las 50 primeras.
        for(int i = 0; i < 50; i++){

            imagen image = cont_Image->recupera(i); //Recuperamos la imagen de la posición i.
            std::cout << ++contador
                      << " Imagen: ("
                      << " Nombre=" << image.getNombre()
                      << " Fecha=" << image.getFecha().verDia() << "/" << image.getFecha().verMes() << "/" << image.getFecha().verAnio()
                      << " Etiquetas=" << image.getEtiquetas()
                      << ")" << std::endl;

        }


        std::cout << "Tiempo de ejecucion del primer ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }

    ///Realización del segundo ejercicio.
    cout << "Segundo ejercicio: " << endl;
    clock_t t_ini = clock();

    ejercicio2(*cont_Image);

    std::cout << "Tiempo de ejecucion del segundo ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    ///Realización del tercer ejercicio.
    cout << "Tercer ejercicio: " << endl;

    t_ini = clock();

    ejercicio3(*cont_Image);

    std::cout << "Tiempo de ejecucion del tercer ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    ///Realización del cuarto ejercicio.
    cout << "Cuarto ejercicio: " << endl;

    t_ini = clock();

    string id_Buscar = "687290194";
    int pos = buscar_Id(*cont_Image, id_Buscar);
    if (pos != -1)
    {
        cout << "La imagen con el Id: " << id_Buscar << " se encuentra en la posicion: " << pos << "." << endl;
    } else
    {
        cout << "La imagen con el Id: " << id_Buscar << "no se encuentra en el contenedor." << endl;
    }

    id_Buscar = "0";
    pos = buscar_Id(*cont_Image, id_Buscar);

    if (pos != -1)
    {
        cout << "La imagen con el Id: " << id_Buscar << " se encuentra en la posicion: " << pos << "." << endl;
    } else
    {
        cout << "La imagen con el Id: " << id_Buscar << " no se encuentra en el contenedor." << endl;
    }

    std::cout << "Tiempo de ejecucion del cuarto ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    ///Realización del quinto ejercicio.
    cout << "Quinto ejercicio: " << endl;

    t_ini = clock();

    contenedor_Imagenes *cont_Img_Email = new contenedor_Imagenes(20);
    int tam_Cont_Email = 0, i = 0;
    while (i < cont_Image->tam() && tam_Cont_Email < 20)
    {
        if ((cont_Image->recupera(i).getEmail() == "magdalen_upton99@gmail.com") && (cont_Image->recupera(i).getFecha().verAnio() == 2020))
        {
            cont_Img_Email->asigna(cont_Image->recupera(i), tam_Cont_Email);
            tam_Cont_Email++;
        }
        i++;
    }


    int contador5 = 0;
    for (int j = 0; j < tam_Cont_Email; j++) {
        std::cout << ++contador5
                << " Imagen: ( ID=" << cont_Img_Email->recupera(j).getId()
                << " Email=" << cont_Img_Email->recupera(j).getEmail() << " Fichero=" << cont_Img_Email->recupera(j).getNombre()
                << " Tam=" << cont_Img_Email->recupera(j).getTam()
                << " Fecha=" << cont_Img_Email->recupera(j).getFecha().verDia() << "/" << cont_Img_Email->recupera(j).getFecha().verMes() << "/" << cont_Img_Email->recupera(j).getFecha().verAnio()
                << " Etiquetas=" << cont_Img_Email->recupera(j).getEtiquetas()
                << ")" << std::endl;
    }
    delete cont_Img_Email;
    std::cout << "Tiempo de ejecucion del quinto ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    delete cont_Image;

    std::cout << "El tiempo total para la realizacion de la practica es: " << ((clock() - t_ini_total) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
}