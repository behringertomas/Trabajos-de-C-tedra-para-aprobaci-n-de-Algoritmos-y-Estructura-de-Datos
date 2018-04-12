/*


Ejercicio 3
Procesar los archivos generados en el punto anterior para cargar un Array con la siguiente estructura:
? Nombre Agrupación
? Número de Lista
? Nombre Candidato
? Cantidad de Votos
( L I S T O )
Mostrar por pantalla el ordenamiento del Array cargado por cada una de las siguientes condiciones
y utilizando al menos 3 modos de ordenamiento distintos:
1. Cantidad de Votos.( L I S T O )
2. Nombre de la Agrupación Política.( L I S T O )
3. Número de Lista( L I S T O )
4. Nombre del Candidato.( L I S T O )
5. Nombre del la Agrupación Política y Cantidad de Votos.( L I S T O )
6. Nombre del Candidato y Cantidad de Votos.( L I S T O )
7. Nombre de la Agrupación Política, Nombre del Candidato y Cantidad de Votos.( L I S T O )





*/


#include<stdio.h> // Carga de un archivo de Texto separado los campos por comas
#include<stdlib.h> // Convierte e inserta en un Archivo binario
#include<conio.h> // Probado con strtok
#include<string.h>
#define p printf
#define s scanf
typedef struct
{
     char partido[20];
     int lista;
     char nom_cand[30];
     int cantvot;
 } registro;
typedef struct
{
     char partido_candidato[50];
     int lista;
     int cantvot;
 } registro2;

int sacapal(char [],int d, char [] );
int menprin(void);
void cargar(FILE*,registro);
void tecla(void);
void sacar(char[],registro*);
void ordenarNombreAgrupacionOnombre(registro [], int, int);
void ordenarVotos(registro [],int ,int );
void imprimeLista(registro[],int,char*);
void menu(registro [], registro [],registro2 [], registro2 [], int, int);
void sortMerge(registro[] , int , int );
void merging(registro[] ,int, int, int);
void imprimeListaConCorteDeControl(registro[],int,char*);
void imprimeListaConCorteDeControlPorCandidato(registro[],int,char*);
void ordenarNombreAgrupacionYnombre (registro2[],int );
void CargaEstructura2(registro[],registro2[],int ,char*);
void imprimeLista2(registro2 [],int ,char*);
void imprimeListaConCorteDeControl2(registro2 [],int,char*);

int main()
{

 FILE *archivo;
 char* mesa68="Mesa_4580.txt";// nombre físico del archivo
 char*ptr, *car=" ";
 char cadena[80],nom_chof[80],*pri,*seg,*ter,*cuar;
 registro reg, diputados[100],senadores[100];
 // esto lo utilizo solo por los 3 campos que tengo que agrupar para el punto 7 y los inicializo vacios para
 // evitar problemas de basura en memoria
 registro2 reg2, diputados2[100]={{'\0',0,0}},senadores2[100]={{'\0',0,0}};


 int cod, i,j,ban=0,cd=0,cs=0,cvbsen,cvisen,cvbdip,cvidip;
 // Cantidad de Votos Blanco SENadores (cvbsen)
 // Cantidad de Votos Impugnados SENadores (cvisen)
 // Cantidad de Votos Blanco DIPutados (cvbdip)
 // Cantidad de Votos Impugnados DIPutados (cvidip)


 system("color 9f");
if((archivo=fopen(mesa68,"r+"))==NULL) p("\n\n***El archivo %s no pudo abrirse ***\n",mesa68); // crea el archivo para escritura y lectura
   else
    {
        p("\n CONTENIDO DEL ARCHIVO DE TEXTO EN FORMATO PLANO \n\n");
         while(fgets(cadena,81,archivo) )  //!=NULL)  hasta \n n-1 o salto de linea
           p("%s",cadena);
         tecla();
         rewind(archivo);
        p("\n\n CONTENIDO DE LOS CAMPOS EN MEMORIA");
         p("\n\n Codigo\t\tNombre\t\t\t  \n\n");
         while(fgets(cadena,81,archivo) ) // Recorro el Archivo de Texto
         {
               if(strcmpi(cadena,"Acta de la mesa: 4580\n")==0) p("%s",cadena);
               if(strcmpi(cadena,"Senadores:\n")==0)  ban=1;
               if(strcmpi(cadena,"Diputados:\n")==0)  ban=2;

            ptr=strtok(cadena,car);


             // chequeo votos impugnados DIPUTADOS

            if(strcmpi(ptr,"Votos")==0 && ban==4)
             {
                   //p("\n entro para impugnados diputados!!!");
                   ban=0;
                   seg=strtok(NULL," ");
                  ter=strtok(NULL,":");
                  cvidip=atoi(ter);
                  p("\nCantidad de Votos impugnados Diputados %3d",cvidip);
             }
            // chequeo votos impugnados SENADORES

            if(strcmpi(ptr,"Votos")==0 && ban==3)
             {
                   //p("\n Entro para impugnados SENADORES!!!");
                   ban=0;
                   seg=strtok(NULL," ");
                  ter=strtok(NULL,":");
                  cvisen=atoi(ter);
                  p("\nCantidad de Votos impugnados Senadores:%3d",cvisen);
             }
            // chequeo votos en blanco SENADORES
             if(strcmpi(ptr,"Votos")==0 && ban==1)
             {
                   //p("\n entro para votos en blanco senadores !!!");
                   ban=3;
                   seg=strtok(NULL," ");
                  ter=strtok(NULL,":");
                  cuar=strtok(NULL," ");
                  cvbsen=atoi(cuar);
                  p("\nCantidad de Votos en Blanco Senadores%3d",cvbsen);
             }
            // chequeo votos en blanco DIPUTADOS
             if(strcmpi(ptr,"Votos")==0 && ban==2)
             {
                   //p("\n entro para votos en blanco diputados !!!");
                   ban=4;
                   seg=strtok(NULL," ");
                  ter=strtok(NULL,":");
                  cuar=strtok(NULL," ");
                  cvbdip=atoi(cuar);
                  p("\nCantidad de Votos en blanco Diputados %3d",cvbdip);
             }

            //  p("\n Ban es:%d",ban); getch();
                 if (ban==1)
                 {
                     // p("\nBan:%d\tCadena:%s",ban,cadena); getch();
                    if(strcmpi(cadena,"\n")!=0)
                            {
                               if(strcmpi(cadena,"Senadores:\n")!=0)
                                {
                                    sacar(cadena,&reg);
                                    p("\n%d   Cadena:%s",ban,cadena);
                                    ///  esto es para cargar en el vector senadores
                                    senadores[cs]=reg;
                                    cs++;
                                 }
                            }
                 }
                if (ban==2)
                 {
                   //   p("\nBan:%d\tCadena:%s",ban,cadena); getch();
                    if(strcmpi(cadena,"\n")!=0)
                            {
                               if(strcmpi(cadena,"Diputados:\n")!=0)
                                {
                                    sacar(cadena,&reg);
                                    p("\nCadena:%s",cadena);
                                    //getch(); ///  esto es para cargar en el vector Diputados
                                    diputados[cd]=reg;
                                    cd++;
                                }
                            }
                 }
        }
    }

    imprimeLista(senadores,cs,"\nLISTADO DE SENADORES SIN ORDENAR");
    imprimeLista(diputados,cd,"\nLISTADO DE DIPUTADOS SIN ORDENAR");

    menu(senadores,diputados,senadores2,diputados2,cs,cd);


 fclose(archivo);
 tecla();
 system("cls");
 return(0);
}



void sacar(char x[],registro *y) // Modifico el Registro por Dirección
{
        char*pri,*seg,*ter,*cuar;
        pri=strtok(x,"-");
        strcpy(y->partido,pri);
        seg=strtok(NULL,"-");
        y->lista=atoi(seg);
        ter=strtok(NULL,"-");
        strcpy(y->nom_cand,ter);
        cuar=strtok(NULL," ");
        y->cantvot=atoi(cuar);
    p("\nPartido:%-10s lista:%3d  Candi:%s Votos:%3d\n",y->partido,y->lista,y->nom_cand,y->cantvot);

}



void tecla(void)
{
	p("\n\nPresione cualquier tecla para continuar!!!");
	getch();
}

void ordenarNombreAgrupacionOnombre (registro y[],int numero,int op)
{

    // BURBUJEO
    int i,j;
    registro tmp;

    for (i=0; i<numero-1; i++)
    {
        for (j=i+1; j<numero; j++)
        {

             if(op==2)
             {
                 if ( strcmpi( y[i].partido, y[j].partido)>0)
                {
                    tmp=y[i];
                    y[i] = y[j];
                    y[j] = tmp;


                }
             }
             if(op==4)
             {
                 if ( strcmpi( y[i].nom_cand, y[j].nom_cand)>0 )
                {
                    tmp=y[i];
                    y[i] = y[j];
                    y[j] = tmp;
                }
             }

        }
    }

}

void ordenarVotos(registro y[],int primero, int ultimo )
{
     int i,j,p;
     registro t;
    i= primero; // primer elemento
    j= ultimo; // último elemento
    p= y[(i+j)/2].cantvot;  // p se hace igual al elemento pivote del arreglo

    do {
        // se hace la partición del arreglo
        while (y[i].cantvot<p) i++;
        while (p< y[j].cantvot) j--;
        if (i<=j) {
                // se intercambian los elementos i-esimo y j-esimo del arreglo
                t= y[i];
                y[i]= y[j];
                y[j]= t;
                i++; j--;
            }
    } while (i<=j);
    if (primero<j) ordenarVotos(y,primero,j);
    if (i<ultimo) ordenarVotos(y,i,ultimo);

}
//-----------------------------------------------------------------------------------------
void imprimeLista(registro y[],int numero,char*titulo)
{
    p("\n %s\n",titulo);
    p("\n -----------------------\n\n");
    for(int i=0;i<numero;i++)
            p("\n %-20s\t%3d\t%-20s\t%3d",y[i].partido,y[i].lista,y[i].nom_cand,y[i].cantvot);
    tecla();
}
//-----------------------------------------------------------------------------------------
void CargaEstructura2(registro y[],registro2 y2[],int numero,char*titulo)
{
    int i;
    p("\n %s\n",titulo);
    p("\n -----------------------\n\n");
    for(i=0;i<numero;i++)
    {
        strcat(y2[i].partido_candidato, y[i].partido);
        strcat(y2[i].partido_candidato, "-");
        strcat(y2[i].partido_candidato, y[i].nom_cand);
        y2[i].cantvot=y[i].cantvot;
        y2[i].lista=y[i].lista;
        p("\n%-50s\t%3d\t%3d",y2[i].partido_candidato,y2[i].lista,y2[i].cantvot);
    }

    tecla();
}
//-----------------------------------------------------------------------------------------
int menprin(void)
{
int op;
 	do
	{
	system("cls");

	printf("\n\t\t*****MEN%c PRINCIPAL (Ejercicio 3) *****\n\n",233);
	p("\n\t <1> ORDENAMIENTO POR VOTOS (Quick Sort)\n");
	p("\n\t <2> ORDENAMIENTO POR AGRUPACI%cN POLITICA( Burbujeo)\n",224);
	p("\n\t <3> ORDENAMIENTO POR NRO. DE LISTA (MergeSort)\n");
	p("\n\t <4> ORDENAMIENTO POR NOMBRE DE CANDIDATO\n");
	p("\n\t <5> Nombre del la Agrupaci%cn Pol%ctica y Cantidad de Votos.\n",162,161);
	p("\n\t <6> Nombre del Candidato y Cantidad de Votos.\n");
	p("\n\t <7> Nombre de la Agrupaci%cn Pol%ctica, Nombre del Candidato y Cantidad de Votos.\n",162,161);

	p("\n\t <8> SALIR \n");
	p("\n\n\t INGRESE OPCION: ");s("%d",&op);
	}while(op<1 || op>8);
return(op);
}//CIERRA MENU
//-----------------------------------------------------------------------------------------

void menu(registro y[], registro z[],registro2 y2[], registro2 z2[],int cs,int cd)
{
    // y es el vector estructurado de Senadores
    // z es el vector estructurado de Diputados
    // cs es cantidad de senadores
    // cd es cantidad de diputados
    // op opcion elegida en el menu
    int op;
    do
	{
	op=menprin();
	switch(op)
		{
		case 1:
            {
                ordenarVotos(y,0,cs);
                imprimeLista(y,cs,"\nLISTADO DE SENADORES ORDENADO POR VOTOS");
                ordenarVotos(z,0,cd);
                imprimeLista(z,cd,"\nLISTADO DE DIPUTADOS ORDENADO POR VOTOS");
                break;
            }

        case 2:
            {
                ordenarNombreAgrupacionOnombre(y,cs,op);
                imprimeLista(y,cs,"\nLISTADO DE SENADORES ORDENADO POR AGRUPACION POLITICA");
                ordenarNombreAgrupacionOnombre(z,cd,op);
                imprimeLista(z,cd,"\nLISTADO DE DIPUTADOS ORDENADO POR AGRUPACION POLITICA");
                break;
            }

		case 3:
		     {
                sortMerge(y,0,cs);
                imprimeLista(y,cs,"\nLISTADO DE SENADORES ORDENADO POR VOTOS");

                sortMerge(z,0,cd);
                imprimeLista(z,cd,"\nLISTADO DE DIPUTADOS ORDENADO POR VOTOS");
                break;

			}
        case 4:
		     {
                ordenarNombreAgrupacionOnombre(y,cs,op);
                imprimeLista(y,cs,"\nLISTADO DE SENADORES ORDENADO POR CANDIDATO");

                ordenarNombreAgrupacionOnombre(z,cd,op);
                imprimeLista(z,cd,"\nLISTADO DE DIPUTADOS ORDENADO POR CANDIDATO");
                break;

			}
        case 5:
             {
                ordenarNombreAgrupacionOnombre(y,cs,2);
                imprimeListaConCorteDeControl(y,cs,"\nLISTADO DE SENADORES\nCANTIDAD DE VOTOS POR AGRUPACION POLITICA");

                ordenarNombreAgrupacionOnombre(z,cd,2);
                imprimeListaConCorteDeControl(z,cd,"\nLISTADO DE DIPUTADOS\nCANTIDAD DE VOTOS POR AGRUPACION POLITICA");
                break;
             }
        case 6:
		     {
                ordenarNombreAgrupacionOnombre(y,cs,4);
                imprimeListaConCorteDeControlPorCandidato(y,cs,"\nLISTADO DE SENADORES\nCANTIDAD DE VOTOS POR CANDIDATO");

                ordenarNombreAgrupacionOnombre(z,cd,4);
                imprimeListaConCorteDeControlPorCandidato(z,cd,"\nLISTADO DE DIPUTADOS\nCANTIDAD DE VOTOS POR CANDIDATO");
                break;

			}
        case 7:
		     {
                CargaEstructura2(y,y2,cs ,"\n Carga Estructura Senadores");
                ordenarNombreAgrupacionYnombre(y2,cs);
                imprimeLista2(y2,cs,"\nLISTADO DE SENADORES ORDENADO POR AGRUPACION Y CANDIDATO");
                imprimeListaConCorteDeControl2(y2,cs,"\nLISTADO DE SENADORES\nPOR AGRUPACION Y CANDIDATO");

                CargaEstructura2(z,z2,cd ,"\n Carga Estructura Diputados");
                ordenarNombreAgrupacionYnombre(z2,cd);
                imprimeLista2(y2,cs,"\nLISTADO DE DIPUTADOS ORDENADO POR AGRUPACION Y CANDIDATO");
                imprimeListaConCorteDeControl2(z2,cd,"\nLISTADO DE DIPUTADOS\nPOR AGRUPACION Y CANDIDATO");
                break;

			}
		} // Cierra el swich
	}while(op<8);
}
void merging(registro y[], int low, int mid, int high) {
   int l1, l2, i;
   registro b[100];
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(y[l1].lista <= y[l2].lista)
         b[i].lista = y[l1++].lista;
      else
         b[i].lista = y[l2++].lista;
   }

   while(l1 <= mid)
      b[i++].lista = y[l1++].lista;

   while(l2 <= high)
      b[i++].lista = y[l2++].lista;

   for(i = low; i <= high; i++)
      y[i].lista = b[i].lista;
}

void sortMerge(registro y[], int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sortMerge(y,low, mid);
      sortMerge(y, mid+1, high);
      merging(y, low, mid, high);
   } else {
      return;
   }
}
void imprimeListaConCorteDeControl(registro y[],int numero,char*titulo)
{
    char partido[20];

    int i=0,TotalVotos=0;
    system("cls");
    p("\n %-20s",titulo);
    p("\n -----------------------\n\n");

     while(i<numero)
     {
        TotalVotos=0;
        strcpy(partido,y[i].partido);
        while(strcmpi(partido,y[i].partido)==0)
            {
                TotalVotos+=y[i].cantvot;
                i++;
            }
            p("\n %-20s \t Cantidad de Votos:%4d",partido,TotalVotos);
            p("\n ----------------------------------------------\n");

     }
     tecla();
}
void imprimeListaConCorteDeControlPorCandidato(registro y[],int numero,char*titulo)
{
    char nom_cand[30];

    int i=0,TotalVotos=0;
    system("cls");
    p("\n %-20s",titulo);
    p("\n -----------------------\n\n");

     while(i<numero)
     {
        TotalVotos=0;
        strcpy(nom_cand,y[i].nom_cand);
        while(strcmpi(nom_cand,y[i].nom_cand)==0)
            {
                TotalVotos+=y[i].cantvot;
                i++;
            }
            p("\n %-20s \t Cantidad de Votos:%4d",nom_cand,TotalVotos);
            p("\n ----------------------------------------------\n");

     }
     tecla();
}
void imprimeListaConCorteDeControl2(registro2 y2[],int numero,char*titulo)
{
    char PartidoyCandidato[50];

    int i=0,TotalVotos=0;
    system("cls");
    p("\n %-20s",titulo);
    p("\n -----------------------\n\n");

     while(i<numero)
     {
        TotalVotos=0;
        strcpy(PartidoyCandidato,y2[i].partido_candidato);
        while(strcmpi(PartidoyCandidato,y2[i].partido_candidato)==0)
            {
                TotalVotos+=y2[i].cantvot;
                i++;
            }
            p("\n %-20s \t Cantidad de Votos:%4d",PartidoyCandidato,TotalVotos);
            p("\n ----------------------------------------------\n");

     }
     tecla();
}
void ordenarNombreAgrupacionYnombre (registro2 y2[],int numero)
{

    // BURBUJEO
    int i,j;
    registro2 tmp;

    for (i=0; i<numero-1; i++)
    {
        for (j=i+1; j<numero; j++)
        {
            if ( strcmpi( y2[i].partido_candidato, y2[j].partido_candidato)>0 )
            {
                tmp=y2[i];
                y2[i] = y2[j];
                y2[j] = tmp;
            }
        }
    }

}

void imprimeLista2(registro2 y2[],int numero,char*titulo)
{
    p("\n %s\n",titulo);
    p("\n -----------------------\n\n");
    for(int i=0;i<numero;i++)
            p("\n %-20s\t%3d\t%3d",y2[i].partido_candidato,y2[i].lista,y2[i].cantvot);
    tecla();
}
