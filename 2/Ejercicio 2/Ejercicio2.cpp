#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>


/*

    0 = Negro       8 = Gris
    1 = Azul        9 = Azul claro
    2 = Verde       A = Verde claro
    3 = Aguamarina        B = Aguamarina claro
    4 = Rojo        C = Rojo claro
    5 = Púrpura     D = Púrpura claro
    6 = Amarillo    E = Amarillo claro
    7 = Blanco      F = Blanco brillante

*/

using namespace std;

typedef struct
{ /*Senadores y Diputados*/
    char Partido[40];
    char NomApe[25];
    int Edad;
}tCandidato;

typedef struct lista
{
    tCandidato datos;
    struct lista *sig;
}nodo;

tCandidato rCandidato;

nodo *nuevonodo(tCandidato);
void cargar_Lista(nodo **,FILE*);
void insertarPorEdad(nodo**,tCandidato);
void listar(nodo *);
void insertarPorNombre(nodo **, tCandidato );
void cargar_Lista_nombre(nodo **,FILE*);
void BuscarCandidato(nodo *, int);
//-----------------------------------------------------------------------------
void mostrarArchivos(tCandidato)
//-----------------------------------------------------------------------------
{
                    system("cls");
        cout << "----------------- SENADORES -----------------" << endl;
                    FILE *fSenadores;
                    fSenadores = fopen("Senadores.dat","rb+");
                    fread(&rCandidato,sizeof(rCandidato),1,fSenadores);
                    printf("\nPartido \t\t                  Candidato   \t\t  Edad\n");
                    cout << endl;
                    while (!feof(fSenadores))
                        {
                         printf("%-40s %-25s %3d\n",rCandidato.Partido,rCandidato.NomApe,rCandidato.Edad);
                         fread(&rCandidato,sizeof(rCandidato),1,fSenadores);
                        }
                    fclose(fSenadores);
                    system("pause");
                    system("cls");
        cout << "----------------- DIPUTADOS -----------------" << endl;
                    FILE *fDiputados;
                    fDiputados = fopen("Diputados.dat","rb+");
                    fread(&rCandidato,sizeof(rCandidato),1,fDiputados);
                    printf("\n\nPartido \t\t                Candidato   \t\t  Edad\n");
                    cout << endl;
                    while (!feof(fDiputados))
                        {
                         printf("%-40s %-25s %3d\n",rCandidato.Partido,rCandidato.NomApe,rCandidato.Edad);
                         fread(&rCandidato,sizeof(rCandidato),1,fDiputados);
                        }
                    fclose(fDiputados);
                        printf("\n\n Pulse una tecla para continuar....................\n");
                        getch();
}

//-----------------------------------------------------------------------------
void creaSenadores(tCandidato)
//-----------------------------------------------------------------------------
{

    FILE *fSenadores;

    fSenadores = fopen("Senadores.dat","wb");
    if (fSenadores != NULL)
        {
            cout << "Ingrese nombre del PARTIDO: (0 finaliza)-->:" ;
            fflush(stdin);
            gets(rCandidato.Partido);
            while((strcmp(rCandidato.Partido,"0"))!=0)
            {

                cout << "Ingrese Nombre y Apellido del candidato-->:";
                fflush(stdin);
                gets(rCandidato.NomApe);

                do
                {
                    cout << "Ingrese edad-->: ";
                    cin >> rCandidato.Edad;
                    cout << endl;
                }while(rCandidato.Edad<18);

                fwrite(&rCandidato,sizeof(rCandidato),1,fSenadores); /*Escribe en el archivo SENADORES*/
                 cout << "Ingrese nombre del PARTIDO: (0 finaliza)-->:" ;
                fflush(stdin);
                gets(rCandidato.Partido);
            }
        }
    fclose(fSenadores);
    system("pause");
}

//-----------------------------------------------------------------------------
void creaDiputados(tCandidato)
//-----------------------------------------------------------------------------
{
     FILE *fDiputados;

     fDiputados = fopen("Diputados.dat","wb");
   if (fDiputados != NULL)
        {
            cout << "Ingrese nombre del PARTIDO: (0 finaliza)-->:" ;
            fflush(stdin);
            gets(rCandidato.Partido);
            while((strcmp(rCandidato.Partido,"0"))!=0)
            {

                cout << "Ingrese Nombre y Apellido del candidato-->:";
                fflush(stdin);
                gets(rCandidato.NomApe);

                do
                {
                    cout << "Ingrese edad-->: ";
                    cin >> rCandidato.Edad;
                    cout << endl;
                }while(rCandidato.Edad<18);

                fwrite(&rCandidato,sizeof(rCandidato),1,fDiputados); /*Escribe en el archivo SENADORES*/
                 cout << "Ingrese nombre del PARTIDO: (0 finaliza)-->:" ;
                fflush(stdin);
                gets(rCandidato.Partido);
            }
        }
    fclose(fDiputados);
    system("pause");
}



//-----------------------------------------------------------------------------
nodo *nuevonodo(tCandidato rCandidato)
//-----------------------------------------------------------------------------

{
    nodo *a;
    a=(nodo*)malloc(sizeof(nodo));

    a->datos.Edad =rCandidato.Edad;
    strcpy(a->datos.NomApe,rCandidato.NomApe);
    strcpy(a->datos.Partido,rCandidato.Partido);
    a->sig = NULL;
    return (a); /* Retorna la direccion donde esta el nodo ese */
}

//-----------------------------------------------------------------------------
void cargar_Lista(nodo **l, FILE *x)
//-----------------------------------------------------------------------------
{
    tCandidato r;
    fread(&r,sizeof(r),1,x);
    while(!feof(x))
    {
        insertarPorEdad(l,r);
        fread(&r,sizeof(r),1,x);
    }

}
//-----------------------------------------------------------------------------
void cargar_Lista_nombre(nodo **l, FILE *x)
//-----------------------------------------------------------------------------
{
    tCandidato r;
    fread(&r,sizeof(r),1,x);
    while(!feof(x))
    {
        insertarPorNombre(l,r);
        fread(&r,sizeof(r),1,x);
    }

}


//-----------------------------------------------------------------------------
void insertarPorEdad(nodo **l, tCandidato x)
//-----------------------------------------------------------------------------
{
    nodo *nuevo;
    nuevo= nuevonodo(x);
    if(*l==NULL) *l=nuevo;
       else
            if((*l)->datos.Edad>x.Edad)
                {
                    nuevo->sig=*l;
                    *l=nuevo;
                }
                else insertarPorEdad(&(*l)->sig,x);

}
//-----------------------------------------------------------------------------
void insertarPorNombre(nodo **l, tCandidato x)
//-----------------------------------------------------------------------------
{
    nodo *nuevo;
    nuevo= nuevonodo(x);
    if(*l==NULL)
        *l=nuevo;
    else
        if(strcmpi((*l)->datos.NomApe,x.NomApe)>0)
            {
                nuevo->sig=*l;
                *l=nuevo;
            }
        else
            insertarPorNombre(&(*l)->sig,x);

}



//-----------------------------------------------------------------------------
void listar (nodo *l)
//-----------------------------------------------------------------------------
{
    if(l!=NULL)
    {
            printf("%-40s %-25s %3d\n",l->datos.Partido,l->datos.NomApe,l->datos.Edad);
            listar(l->sig);
    }
}

//-----------------------------------------------------------------------------
void BuscarCandidato (nodo *l, int edad)
//-----------------------------------------------------------------------------
{
    if(l!=NULL)
    {
            if(l->datos.Edad==edad)
                printf("%-40s %-25s %3d\n",l->datos.Partido,l->datos.NomApe,l->datos.Edad);
            BuscarCandidato(l->sig,edad);
    }
}


//-----------------------------------------------------------------------------
void mostrarLista(nodo *l)
//-----------------------------------------------------------------------------
{
    if(l) /* Cuando l apunte a NULL, no se llama mas y frena */
    {
        printf("%-40s %-25s %3d\n",l->datos.Partido,l->datos.NomApe,l->datos.Edad);
        mostrarLista(l->sig);
    }
}
//*****************************************************************************
int main()
//*****************************************************************************
{
    system("color E");
    int op,edad;
    tCandidato rCandidato;
    nodo *listaSenadores, *listaDiputados, *listaDiputadosNombre, *listaSenadoresNombre;
    listaSenadores = NULL;
    listaDiputados=NULL;

    listaSenadoresNombre = NULL;
    listaDiputadosNombre=NULL;

    FILE *fSenadores;
    FILE *fDiputados;

    do {
        system("cls");
        cout << "GENERACION / MODIFICACION DE ARCHIVOS:" << endl;
        cout << "1. Generar archivo Senadores " << endl;
        cout << "2. Generar archivo Diputados" << endl;
        cout << endl;
        cout << "VER LOS ARCHIVOS GENERADOS: " << endl;
        cout << "3. Lectura de los archivos " << endl;
        cout << endl;
        cout << "GENERACION DE LISTAS ENLAZADAS: " << endl;
        cout << "4. Generar la lista por EDAD " << endl;
        cout << "5. Generar la lista por Nombre " << endl;
        cout << endl;
        cout << "INFORME DE LISTAS CON ORDANAMIENTOS: " << endl;
        cout << "6. Informe de lista por EDAD " << endl;
        cout << "7. Informe de lista por NOMBRE " << endl;
        cout << endl;
        cout << "8. Busqueda de candidatos por edad " << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;
        cout << endl;
        switch (op) {
               case 0:
                    cout << "Fin de programa." << endl;
                    break;
               case 1:
                    creaSenadores(rCandidato);
                    break;
                case 2:
                    creaDiputados(rCandidato);
                    break;
               case 3:
                    mostrarArchivos(rCandidato);
                    break;
               case 4:
                   //SENADORES
                   if(!listaSenadores)
                   {
                    fSenadores = fopen("Senadores.dat","rb");
                    cargar_Lista(&listaSenadores,fSenadores);

                   //DIPUTADOS

                    fDiputados =fopen("Diputados.dat","rb");
                    cargar_Lista(&listaDiputados,fDiputados);

                   }
                   else
                   {
                        printf("la Lista por EDAD ya fue generada....\n");
                        system("pause");
                   }


                    break;
               case 5:
                //SENADORES
                   if(!listaSenadoresNombre)
                   {


                    fSenadores = fopen("Senadores.dat","rb");
                    cargar_Lista_nombre(&listaSenadoresNombre,fSenadores);


                   //DIPUTADOS

                    fDiputados =fopen("Diputados.dat","rb");
                    cargar_Lista_nombre(&listaDiputadosNombre,fDiputados);

                   }
                   else
                   {
                        printf("la Lista por NOMBRE ya fue generada....\n");
                        system("pause");
                   }
                   break;
               case 6:
                   if (listaSenadores)
                   {
                    system("cls");
                    cout << "-------------- SENADORES ORDENADOS POR EDAD ----------------------" << endl;
                    printf("\n\nPartido \t\t                Candidato   \t\t  Edad\n");
                    cout << endl;
                    listar(listaSenadores);
                    system("pause");
                    system("cls");
                    cout << "-------------- DIPUTADOS ORDENADOS POR EDAD ----------------------" << endl;
                    printf("\n\nPartido \t\t                Candidato   \t\t  Edad\n");
                    cout << endl;
                    listar(listaDiputados);
                    system("pause");
                   }
                   else
                   {
                        printf("la Lista Edad no fue generada aun. Generela pulsando la opcion 4 !! \n");
                        system("pause");
                   }

                    break;

               case 7:
                    // informe de Lista enlazada por NOMBRE
                    if (listaSenadoresNombre)
                    {
                    system("cls");
                    cout << "-------------- SENADORES ORDENADOS POR NOMBRE ----------------------" << endl;
                    printf("\n\nPartido \t\t                Candidato   \t\t  Edad\n");
                    cout << endl;
                    listar(listaSenadoresNombre);
                    system("pause");
                    system("cls");
                    cout << "-------------- DIPUTADOS ORDENADOS POR NOMBRE ----------------------" << endl;
                    printf("\n\nPartido \t\t                Candidato   \t\t  Edad\n");
                    cout << endl;
                    listar(listaDiputadosNombre);
                    system("pause");
                    }
                    else
                   {
                        printf("la Lista Nombre no fue generada aun. Generela pulsando opcion 5 !! \n");
                        system("pause");
                   }

                    break;
               case 8:

                    if(listaSenadores)
                    {
                        printf("Ingrese una edad:");
                        scanf("%d",&edad);
                        system("cls");
                        cout << "-------------- SENADORES ENCONTRADOS CON EDAD " << edad << " ----------------------" << endl;
                        cout << endl;
                        BuscarCandidato(listaSenadores,edad);
                        cout << endl;
                        cout << "-------------- DIPUTADOS ENCONTRADOS CON EDAD " << edad << " ----------------------" << endl;
                        cout << endl;
                        BuscarCandidato(listaDiputados,edad);
                        cout << endl;
                        cout << endl;

                        system("pause");
                    }
                    else
                        {
                        printf("Lista Vacia.... Genere la lista por edad pulsando la opcion 4 !!\n");
                        system("pause");
                        }


                    break;
               default:
                    cout << "Nro de Opcion erronea" << endl;
                    system("pause");
                    break;
        }
    }while (op != 0);



    return 0;
}


