#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
class Programa {
private :
    int largo_operaciones ;
    char * puntero_operaciones ;
    int * puntero_salida ;
    int * puntero_base;
    char * operaciones ;
    int cant_salida;
    bool flag_termino;
public :
    Programa(){};
    Programa ( int largo_operaciones );
    ~Programa(){};
    void ejecutar_operador () ;
    void mover ( char dir );
    void asignar ( int valor , int * salida );
    char obtener () ;
    void terminar_programa () ;
    void ejecutar () ;
    void rellenar_operaciones(string texto, int largo);
    void caso_cero();
    string mostrar_prog();
};
class Interprete {
private :
    int cant_programas ;
    int largo_salida ;
    int cargado ;
    Programa * programas ;
    int * salida ;
public :
    Interprete (int cant_programa , int largo_salid ){
        cant_programas = cant_programa;
        largo_salida = largo_salid;
    };
    Interprete(){};
    ~Interprete(){};
    void cargar_programa (int n);
    void ejecutar_programa () ;
    void mostrar_programa_cargado () ;
    void terminar_ejecucion () ;
    void asignar_cant(int n);
    void asignar_exit(int n);
    int conseguir_exit();
    void rellenar_prog(Programa *program, int cantidad);
};
#endif