#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "class.hpp"
/*****
* void Programa::mover
******
* Mueve el puntero de salida y el de operaciones dependiendo de la dirección especificada.
******
* Input :
* char dir : Dirección hacia la que se moverán los punteros ('>' o '<').
******
* Returns :
* void, no retorna ningún valor.
*****/
void Programa::mover(char dir){
    if ( dir == '>'){
        ++puntero_salida;
        ++puntero_operaciones;
        return;
    }
    if ( dir == '<'){
        --puntero_salida;
        ++puntero_operaciones;
        return;
    }
}
/*****
* void Programa::asignar
******
* Asigna un valor a todas las posiciones de salida.
******
* Input :
* int valor : Valor que se asignará a cada posición de salida.
* int* salida : Puntero a la memoria de salida.
******
* Returns :
* void, no retorna ningún valor.
*****/
void Programa::asignar( int valor , int * salida ){
    for(int i=0; i<cant_salida; i++){
        *salida = valor;
        ++salida;
    }   
}
/* ****
* char Programa::obtener
******
* Obtiene el carácter actual de las operaciones.
******
* Returns :
* char, carácter actual de las operaciones.
**** */
char Programa::obtener(){
    char c;
    c = *puntero_operaciones;
    return c;
}
/* ****
* void Programa::terminar_programa
******
* Libera la memoria asignada dinámicamente para operaciones y puntero_salida.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Programa::terminar_programa(){
    delete []operaciones;
    delete []puntero_base;
}
/* ****
* void Programa::ejecutar_operador
******
* Ejecuta la operación correspondiente según el carácter actual de las operaciones.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Programa::ejecutar_operador(){
    char c_actual = obtener();
    if (c_actual == '+'){
        ++(*puntero_salida);
        ++puntero_operaciones;
    }
    else if(c_actual == '-'){
        --(*puntero_salida);
        ++puntero_operaciones;
    }
    else if (c_actual == '>'){
        mover(c_actual);
    }

    else if (c_actual == '<'){
        mover(c_actual);
    }

    else if(c_actual == '.'){
        cout<< *puntero_salida;
        ++puntero_operaciones;
    }

    else if(c_actual == ':'){
        string tabla =" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789.:+-<>[]!";
        int pos = (*puntero_salida);
        while (pos > 72){
            pos= pos-72;
        }
        pos = abs(pos);
        char letra = tabla[pos];
        cout<<letra;
        ++puntero_operaciones;
    }

    else if(c_actual == '['){
        if (*puntero_salida != 0){
            ++puntero_operaciones;
        }
        else{
            caso_cero();
        }
    }
    
    else if(c_actual == ']'){
        if (*puntero_salida != 0){
            while (*puntero_operaciones != '['){
                --puntero_operaciones;
            }
        }
        else{
            ++puntero_operaciones;
        }
    }

    else if(c_actual == '!'){
        cout<<endl;
        flag_termino = false;
        return;
    }
    return;
}
/* ****
* void Programa::rellenar_operaciones
******
* Rellena el arreglo de operaciones con el texto proporcionado.
******
* Input :
* string texto : Texto con las operaciones a ejecutar.
* int largo : Cantidad de posiciones de salida que se usarán.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Programa::rellenar_operaciones(string texto, int largo){
    int i = 0;
    cant_salida = largo;
    int aux = texto.length();
    largo_operaciones = aux;
    operaciones = new char[texto.length()];
    for(char c : texto){
        operaciones[i]=c;
        i++;
    }
}
/* ****
* void Programa::ejecutar
******
* Ejecuta las operaciones del programa hasta que termine.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Programa::ejecutar(){
    puntero_operaciones = operaciones;
    puntero_base = new int[cant_salida];
    puntero_salida = puntero_base;
    asignar(0, puntero_salida);
    int i = 0;
    flag_termino = true;
    while (flag_termino==true){
        ejecutar_operador();
        i++;
    }
}
/* ****
* void Programa::caso_cero
******
* Avanza el puntero de operaciones hasta que encuentra el carácter ']' cuando la condición es cero.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Programa::caso_cero(){
    char c_actual = obtener();
    while (c_actual != ']'){
        ++puntero_operaciones;
    }
    ++puntero_operaciones;
}
/* ****
* string Programa::mostrar_prog
******
* Devuelve el programa en forma de cadena.
******
* Returns :
* string, el programa almacenado en formato de cadena.
**** */
string Programa::mostrar_prog(){
    string texto_cargado;
    for (int i = 0; i < largo_operaciones; ++i){
        texto_cargado += operaciones[i];
    }
    return texto_cargado;
}
/* ****
* void Interprete::cargar_programa
******
* Carga un programa en el intérprete.
******
* Input :
* int n : Índice del programa a cargar.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Interprete::cargar_programa (int n){
    cargado = n; 
    return;
}
/* ****
* void Interprete::asignar_exit
******
* Asigna el tamaño de salida.
******
* Input :
* int n : Tamaño de salida.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Interprete::asignar_exit(int n){
    largo_salida = n;
    return;
}
/* ****
* void Interprete::ejecutar_programa
******
* Ejecuta el programa cargado.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Interprete::ejecutar_programa(){
    programas[cargado].ejecutar();
}
/* ****
* int Interprete::conseguir_exit
******
* Obtiene el valor del tamaño de salida.
******
* Returns :
* int, valor de la salida.
**** */
int Interprete::conseguir_exit(){
    int salida = largo_salida;
    return salida;
}
/* ****
* void Interprete::mostrar_programa_cargado
******
* Muestra el programa actualmente cargado.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Interprete::mostrar_programa_cargado(){
    cout <<  programas[cargado].mostrar_prog() <<endl;
    return;
}
/* ****
* void Interprete::terminar_ejecucion
******
* Libera la memoria dinámica asignada a los programas.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Interprete::terminar_ejecucion(){
    for (int i = 0; i < cant_programas; ++i) {
        programas[i].terminar_programa();
    }
    delete [] programas;
}
/* ****
* void Interprete::rellenar_prog
******
* Rellena el arreglo de programas con una serie de programas.
******
* Input :
* Programa* program : Puntero al primer programa de un arreglo.
* int cantidad : Cantidad de programas a rellenar.
******
* Returns :
* void, no retorna ningún valor.
**** */
void Interprete::rellenar_prog(Programa *program, int cantidad){
    programas = program;
}
#endif