#include "funciones.hpp"
int main() {
    int largo;
    int cant;
    ifstream archivo("Programas.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    archivo >> largo;;
    archivo >> cant;
    Interprete interprete(cant,largo);
    Programa* programa = new Programa[cant];
    for(int i=0; i<cant ; i++){
        string linea_programa;
        archivo >> linea_programa;
        programa[i].rellenar_operaciones(linea_programa, largo);
    }
    interprete.rellenar_prog(programa, cant);
    char respuesta;
    cin >> respuesta;
    while (respuesta != 's'){
        if (respuesta == 'c'){
            int numero;
            cin >> numero;
            interprete.cargar_programa(numero);
        }
        else if (respuesta == 'm'){
            interprete.mostrar_programa_cargado();
        }
        else if (respuesta == 'e'){
            interprete.ejecutar_programa();
        }
        cin >> respuesta;
    }
    interprete.terminar_ejecucion();
    archivo.close();
    return 0;
}   