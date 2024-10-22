/*----------------------------------------------------------------------------------------------------
 * El programa permite hallar el perimetro de un poligono, ingresando como datos la cantidad de lados
 * del poligono y las coordenadas de cada punto.
 * Dato de Entrada: lados (int)   numero de lados de un poligono
 *                  las coordenadas de cada punto.
 * Dato de Salida:  perimetro  (double)
 ---------------------------------------------------------------------------------------------------*/


#include "CPunto.h"

int main()
{ int nlados;
  double x,y;

    cout << "Numero de lados del poligono: ";
    cin >> nlados;
    //-- se crea un arreglo dinamico, en donde en cada casillero hay un objeto de la clase CPunto
    CPunto *pA  = new CPunto[nlados];
    //--- se leen los valores de los puntos
    for(int i=0; i<nlados; i++)
    {
      cout << "\n";
      cout << "Punto " << i+1 <<  "\n";
      cout << "x : "; cin >> x;
      cout << "y : "; cin >> y;
      pA[i].setX(x);
      pA[i].setY(y);
    }
    //--- Hallamos el perimetro
    double perimetro =0;
    for(int i=0; i<nlados-1; i++)
        perimetro += pA[i].distancia(pA[i+1]);
    //--- se halla el ultimo lado
    perimetro += pA[nlados-1].distancia(pA[0]);
    cout << "El perimetro del poligono es: " << perimetro<< "\n";
    //-- liberamos memoria---
    delete []pA;
    pA= nullptr;
    return 0;
}
