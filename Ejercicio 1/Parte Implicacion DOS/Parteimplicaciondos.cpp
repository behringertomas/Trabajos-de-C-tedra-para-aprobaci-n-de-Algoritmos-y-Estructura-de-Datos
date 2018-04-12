#include <string>
#include <iostream>
using namespace std;

bool boletaNoOfi, cualquierPapel, mismaCateDifAgrupa;
string rta;

int main (){

    cout << " ¿El voto es emitido mediante boleta no oficializada? (si o no): ";
    cin >> rta;
    if ( (rta=="Si") || (rta =="si") || (rta == "SI") || (rta == "sI") ) boletaNoOfi = true;
    else if ( (rta =="No") || (rta == "no") || (rta=="NO") || (rta=="nO") ) boletaNoOfi = false;

    cout << " ¿El voto es emitido con papel de cualquier color con inscripciones o imagenes de cualquier naturaleza? (si o no): ";
    cin >> rta;
    if ( (rta=="Si") || (rta =="si") || (rta == "SI") || (rta == "sI") ) cualquierPapel = true;
    else if ( (rta =="No") || (rta == "no") || (rta=="NO") || (rta=="nO") ) cualquierPapel = false;

    cout << " ¿El voto es emitido mediante dos o mas boletas de la misma categoria de candidatos y diferente agrupacion politica? (si o no): ";
    cin >> rta;
    if ( (rta=="Si") || (rta =="si") || (rta == "SI") || (rta == "sI") ) mismaCateDifAgrupa = true;
    else if ( (rta =="No") || (rta == "no") || (rta=="NO") || (rta=="nO") ) mismaCateDifAgrupa = false;

    if ( (boletaNoOfi == true) || (cualquierPapel == true) || (mismaCateDifAgrupa== true) ){ cout << "El voto se considerara nulo" << endl << endl << endl; }
    // con que tan solo una de las proposiciones sea verdadera, implica que el voto sea nulo.
    else if( (boletaNoOfi == false) || (cualquierPapel == false) || (mismaCateDifAgrupa== false) ) {cout << "El voto NO se considerara nulo" << endl << endl<< endl;}

}
