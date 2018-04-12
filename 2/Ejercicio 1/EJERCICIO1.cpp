#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <list>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define PI 3.14159265358979323846 //Lo usaremos para generar el valor entre 0 y 1
#define MAX 9 //maximo numero de vértices
#define Node pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta con que sea superior al maximo valor del peso en alguna de las aristas

//La cola de prioridad de C++ por default es un max-Heap (elemento de mayor valor en el tope)
//por ello es necesario realizar nuestro comparador para que sea un min-Heap
struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};
vector< Node > ady[ MAX ]; //lista de adyacencia
int distancia[ MAX ];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
bool visitado[ MAX ];      //para vértices visitados
priority_queue< Node , vector<Node> , cmp > Q; //priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
int V;                     //numero de vertices
int previo[ MAX ];         //para la impresion de caminos


//-----------------------------------------------------------------------------
float generaNumAleatorio () //GENERA LA DEMORA
//-----------------------------------------------------------------------------
{
    float aleatorio = 0;
    float num = 0;
    srand(time(NULL));
    aleatorio=(sin((float)rand()+1.0))*50.0; //Esto genera números aleatorios entre 0 y 100 pero le aplicamos el Seno.
    num = (aleatorio * PI)/180;
    if (num < 0){ //Si es negativo, se hace positivo. (funcion valor absoluto)
        num = num*(-1);
    }
    return num;
}

//función de inicialización
//-----------------------------------------------------------------------------
void init()
//-----------------------------------------------------------------------------
{
    for( int i = 0 ; i < V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado[ i ] = false; //inicializamos todos los vértices como no visitados
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
//-----------------------------------------------------------------------------
void relajacion( int actual , int adyacente , int peso )
//-----------------------------------------------------------------------------
{
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        Q.push( Node( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
//-----------------------------------------------------------------------------
void print( int destino )
//-----------------------------------------------------------------------------
{
    if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        print( previo[ destino ] );  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

//-----------------------------------------------------------------------------
void dijkstra( int inicial )
//-----------------------------------------------------------------------------
{
    init(); //inicializamos nuestros arreglos
    Q.push( Node( inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){                   //Mientras cola no este vacia
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   //id del vertice adyacente
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }
    int sumatoria =0;
    system("cls");
    printf( "\nDistancias mas cortas iniciando en el vertice %d\n" , inicial );
    for( int i = 0 ; i < V ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
        sumatoria += distancia[i];
    }
    cout << "El camino mas corto recorrido da un total de: " << sumatoria <<endl;
    puts("\n************** EL CAMINO HASTA EL CENTRO DE COMPUTOS FUE **************");
    int destino = 8;
    print( destino );
    printf("\n");
}

//***********************************************************
int main()
//***********************************************************
{
    int E , origen, destino , peso , inicial,op;
    float velocidad,demora, aleatorio;
    double distanciaEntreColegios;
    system("color E");

    cout << "Ingrese velocidad promedio del movil :--> ";
    cin >> velocidad;
    cout << endl;
    cout << "Desea ingresar la distancia entre cada nodo manualmente, o prefiere que se asignen automaticamente al azar? " <<endl;
    cout << "0 = se ingresan automaticamente" << endl;
    cout << "1 = ingresar manualmente" << endl;
    cout << "2. salir" << endl;
    do {
        cout << "Ingrese su opcion:--> ";
        cin >> op;

    } while ((op < 0)||(op >2));
    switch (op) {

        case 0: /* INGRESO AUTOMATICO AL AZAR */

            srand(time(NULL));
            V = 9; //HAY 9 NODOS (vertices)
            E = 14; //HAY 14 ARISTAS

            origen = 0;
            destino = 1;
            if ( (origen == 0) && (destino == 1))
            {
            distanciaEntreColegios = (1 + rand() % 200);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));
            origen++;
            destino++;
                while (destino < V) /*ACA ASIGNO TODOS LOS CAMINOS EN ORDEN, 0 1 2 3 4 5 6 7 8 9 */
                {
                distanciaEntreColegios = (1 + rand() % 203);
                cout << endl;
                demora = generaNumAleatorio()*velocidad;
                peso = demora + distanciaEntreColegios;
                ady[origen].push_back(Node(destino ,peso));

                origen++;
                destino++;
                }
            }

            origen = 0;
            destino = 2;
            distanciaEntreColegios = (1 + rand() % 195);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));

            origen = 2;
            destino = 4;
            distanciaEntreColegios = (1 + rand() % 134);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));

            origen =1;
            destino =3;
            distanciaEntreColegios = (1 + rand() % 211);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));

            origen = 3;
            destino = 5;
            distanciaEntreColegios = (1 + rand() % 287);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));

            origen = 5;
            destino = 7;
            distanciaEntreColegios = (1 + rand() % 194);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));

            origen = 6;
            destino = 8;
            distanciaEntreColegios = (1 + rand() % 187);
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            ady[origen].push_back(Node(destino ,peso));

        cout << "********* EL VERTICE INICIAL ES EL CENTRO DE LOGISTICA ***********";
        inicial = 0;
        dijkstra( inicial );
        break;

        case 1: /* INGRESO MANUAL */

            cout << "------------------------------------------------------------------------------" << endl;
            V = 9; //HAY 9 NODOS (vertices)
            E = 14; //HAY 14 ARISTAS

            origen = 0;
            destino = 1;
            if ( (origen == 0) && (destino == 1))
            {
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

            origen++;
            destino++;
                while (destino < V) /*ACA ASIGNO TODOS LOS CAMINOS EN ORDEN, 0 1 2 3 4 5 6 7 8 9 */
                {
                cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
                cin >> distanciaEntreColegios;
                cout << endl;
                demora = generaNumAleatorio()*velocidad;
                peso = demora + distanciaEntreColegios;
                fflush(stdin);
                ady[origen].push_back(Node(destino ,peso));

                origen++;
                destino++;
                }
            }
            /* ACA ASIGNO LOS CAMINOS QUE FALTAN */
            origen = 0;
            destino = 2;
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

            origen = 2;
            destino = 4;
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

            origen =1;
            destino =3;
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

            origen = 3;
            destino = 5;
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

            origen = 5;
            destino = 7;
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

            origen = 6;
            destino = 8;
            cout << "Ingrese distancia entre nodo " << origen << " y " << destino << ":-->";
            cin >> distanciaEntreColegios;
            cout << endl;
            demora = generaNumAleatorio()*velocidad;
            peso = demora + distanciaEntreColegios;
            fflush(stdin);
            ady[origen].push_back(Node(destino ,peso));

        /* TERMINO EL INGRESO DE TODOS LOS CAMINOS */
        cout << "********* EL VERTICE INICIAL ES EL CENTRO DE LOGISTICA ***********";
        inicial = 0;
        dijkstra( inicial );
        break;

        case 2:
            cout << "Fin de programa." << endl;
            break;
        default:
        break;
        }



    return 0;
}
