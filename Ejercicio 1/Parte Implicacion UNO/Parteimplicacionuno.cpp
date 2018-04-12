#include <string>
#include <iostream>
using namespace std;
/*
Escribir un programa que interactúa con el usuario para asignar el valor de verdad a un conjunto de proposiciones lógicas,
luego el sistema con la información que ingresa el usuario, debe resolver el valor de verdad de la implicación lógica e informar por pantalla el resultado de la misma
*/
bool pertenecePartPoli, avalAfiliados, precandidato;
string rta;

int main (){

    cout << "¿Usted pertenece al partido politico? (si o no): ";
    cin >> rta;
    if ( (rta=="Si") || (rta =="si") || (rta == "SI") || (rta == "sI") ) pertenecePartPoli = true;
    else if ( (rta =="No") || (rta == "no") || (rta=="NO") || (rta=="nO") ) pertenecePartPoli = false;

    cout << "¿Usted cuenta con el aval del 2% de los afiliados a dicho partido? (si o no): ";
    cin >> rta;
    if ( (rta=="Si") || (rta =="si") || (rta == "SI") || (rta == "sI") ) avalAfiliados = true;
    else if ( (rta =="No") || (rta == "no") || (rta=="NO") || (rta=="nO") ) avalAfiliados = false;

    if ( (pertenecePartPoli == true) && (avalAfiliados == true)  ) {cout << "Puede ser precandidato." << endl;}  // T T
    else { if ( (pertenecePartPoli == false) && (avalAfiliados == true) ) {cout << "No puede ser precandidato." << endl;}}  // F T
    if ( (pertenecePartPoli == true) && (avalAfiliados == false) ) { cout << "No puede ser precandidato." << endl;} // T F
    else {if ( (pertenecePartPoli == false) && (avalAfiliados == false) ) {cout << "No puede ser precandidato." << endl;}} // F F

}
