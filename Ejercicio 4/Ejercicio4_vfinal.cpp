/*






Ejercicio 4
Sobre el Array cargado en el punto anterior se pide calcular: ( L I S T O )
1. Los Candidatos que en esa escuela hicieron un buena elección.( L I S T O )
   Una buena elección se considera cuando un Candidato saca entre un 17% y 30% de los votos totales (en esa escuela).
2. Los primeros tres Candidatos de Agrupaciones Políticas distintas con mayor cantidad de votos para cada cargo.
3. Los Candidatos con mayor cantidad de votos dentro de cada Agrupación Política.


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
void imprimeListaConCorteDeControl(registro[],int,char*);
void imprimeListaConCorteDeControlPorCandidato(registro[],int,char*);
void ordenarNombreAgrupacionYnombre (registro2[],int );
void CargaEstructura2(registro[],registro2[],int ,char*);
void imprimeLista2(registro2 [],int ,char*);
void imprimeListaConCorteDeControl2(registro2 [],int,char*);
void imprimeMaximosporPartido(registro2[],int,char*);
void ordenarMaximos (registro2[],int);
int main()
{

 FILE *archivo;
 char mesas[][20]={"Mesa_4568.txt","Mesa_4569.txt","Mesa_4569bis.txt","Mesa_4579.txt","Mesa_4580.txt"};
 ;// nombre físico del archivo
 char*ptr, *car=" ";
 char cadena[80],nom_chof[80],*pri,*seg,*ter,*cuar;
 registro reg, diputados[300]={{'\0',0,'\0',0}},senadores[300]={{'\0',0,'\0',0}};
 // esto lo utilizo solo por los 3 campos que tengo que agrupar para el punto 7 y los inicializo vacios para
 // evitar problemas de basura en memoria
 registro2 reg2, diputados2[300]={{'\0',0,0}},senadores2[300]={{'\0',0,0}};


 int cod, i,j,ban=0,cd=0,cs=0,cvbsen,cvisen,cvbdip,cvidip;
 // Cantidad de Votos Blanco SENadores (cvbsen)
 // Cantidad de Votos Impugnados SENadores (cvisen)
 // Cantidad de Votos Blanco DIPutados (cvbdip)
 // Cantidad de Votos Impugnados DIPutados (cvidip)


system("color 9f");
for (i=0;i<5; i++)
{

ban=0;
if((archivo=fopen(mesas[i],"r+"))==NULL)
    p("\n\n***El archivo %s no pudo abrirse ***\n",mesas[i]); // crea el archivo para escritura y lectura
else
    {
        p("\n CONTENIDO DEL ARCHIVO DE TEXTO EN FORMATO PLANO %s\n\n",mesas[i]);
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
    fclose(archivo);
}
p("termino todas las lecturas ---> %d %d",cs,cd);
tecla();
system("cls");
imprimeLista(senadores,cs,"\nLISTADO DE SENADORES SIN ORDENAR");
imprimeLista(diputados,cd,"\nLISTADO DE DIPUTADOS SIN ORDENAR");

menu(senadores,diputados,senadores2,diputados2,cs,cd);

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
     int izq,der,p;
     registro t;
    izq= primero; // primer elemento
    der= ultimo; // último elemento
    p= y[(izq+der)/2].cantvot;  // p se hace igual al elemento pivote del arreglo

    do {
        // se hace la partición del arreglo
        while (y[izq].cantvot>p) izq++;
        while (p< y[der].cantvot) der--;
        if (izq>=der) {
                // se intercambian los elementos i-esimo y j-esimo del arreglo
                t= y[izq];
                y[izq]= y[der];
                y[der]= t;
                izq++; der--;
            }
    } while (izq<=der);
    if (primero>der) ordenarVotos(y,primero,der);
    if (ultimo<izq) ordenarVotos(y,izq,ultimo);

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
    int i=0;
    while(i<numero)
    {
        y2[i]={{0,0,'\0'}};
        i++;
    }

    p("\n %s\n",titulo);
    p("\n -----------------------\n\n");
    for(i=0;i<numero;i++)
    {
        strcat(y2[i].partido_candidato, y[i].partido);
        strcat(y2[i].partido_candidato, "-");
        strcat(y2[i].partido_candidato, y[i].nom_cand);
        y2[i].cantvot=y[i].cantvot;
        y2[i].lista=y[i].lista;
        p("\n %d %-50s\t%3d\t%3d",i, y2[i].partido_candidato,y2[i].lista,y2[i].cantvot);
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

	printf("\n\t\t*****MEN%c PRINCIPAL (ejercicio 4) *****\n\n",233);
	p("\n\t <1> Candidatos que en esa escuela hicieron una buena elecci%cn.\n",162);
	p("\n\t <2> Los primeros tres Candidatos de Agrup. Pol%cticas distintas con mayor cantidad de votos para cada cargo\n",161);
	p("\n\t <3> Los Candidatos con mayor cantidad de votos dentro de cada Agrupaci%cn Pol%ctica.\n",162,161);

	p("\n\t <4> SALIR \n");
	p("\n\n\t INGRESE OPCION: ");s("%d",&op);
	}while(op<1 || op>4);
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
                CargaEstructura2(y,y2,cs ,"\n Carga Estructura Senadores");
                ordenarNombreAgrupacionYnombre(y2,cs);
                imprimeListaConCorteDeControl2(y2,cs,"\nLISTADO DE SENADORES QUE SACARON ENTRE UN 17 Y 30%");

                CargaEstructura2(z,z2,cd ,"\n Carga Estructura DIPUTADOS");
                ordenarNombreAgrupacionYnombre(z2,cd);
                imprimeListaConCorteDeControl2(z2,cd,"\nLISTADO DE DIPUTADOS QUE SACARON ENTRE UN 17 Y 30%");
                break;
            }

        case 2:
            {

                CargaEstructura2(y,y2,cs ,"\n Carga Estructura Senadores");
                ordenarNombreAgrupacionYnombre(y2,cs);
                imprimeMaximosporPartido(y2,cs, "Informe de maximos Votos Por Partido SENADORES");

                CargaEstructura2(z,z2,cd ,"\n Carga Estructura DIPUTADOS");
                ordenarNombreAgrupacionYnombre(z2,cd);
                imprimeMaximosporPartido(z2,cd, "Informe de maximos Votos Por Partido DIPUTADOS");
                break;
            }

		case 3:
		     {

                break;


			 }
		} // Cierra el swich
	}while(op<4);
}

void imprimeListaConCorteDeControl(registro y[],int numero,char*titulo)
{
    char partido[20];

    int i=0,TotalVotos=0;
    int ParcialesVotos=0;
    float porcentaje=0.0;
    system("cls");
    p("\n %-20s",titulo);
    p("\n -----------------------\n\n");

    while(i<numero) TotalVotos+=y[i++].cantvot;
    i=0;
     p("total votos:%3d\n",TotalVotos);
     getch();
     while(i<numero)
     {
        ParcialesVotos=0;
        strcpy(partido,y[i].partido);
        while(strcmpi(partido,y[i].partido)==0)
            {
                ParcialesVotos+=y[i].cantvot;
                i++;
            }
            porcentaje= (float) (ParcialesVotos*100)/TotalVotos;

            if (porcentaje<=30 && porcentaje>=17)
                p("\nESTA ENTRE EL 17 Y 30%%-20s \t Cantidad de Votos:%4d ---  %2.2f%c",partido,ParcialesVotos, porcentaje,37);
            else

                p("\n%-20s \t Cantidad de Votos:%4d ---  %2.2f%c",partido,ParcialesVotos, porcentaje,37);
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
    char partido[50];
    int i=0,TotalVotos=0;
    int ParcialesVotos=0;
    float porcentaje=0.0;
    system("cls");
    p("\n %-20s",titulo);
    p("\n -----------------------\n\n");

    while(i<numero) TotalVotos+=y2[i++].cantvot;
    i=0;
     p("total votos:%3d\n",TotalVotos);
     tecla();
     while(i<numero)
     {
        ParcialesVotos=0;
        strcpy(partido,y2[i].partido_candidato);
        while(strcmpi(partido,y2[i].partido_candidato)==0)
            {
                ParcialesVotos+=y2[i].cantvot;
                i++;
            }
            porcentaje= (float) (ParcialesVotos*100)/TotalVotos;

            if (porcentaje>=17. && porcentaje<=30.)
                p("\nESTA ENTRE EL 17 Y 30%c --> %-20s \t Cantidad de Votos:%4d ---  %2.2f%c",37,partido,ParcialesVotos, porcentaje,37);
            else

                p("\n%-20s \t Cantidad de Votos:%4d ---  %2.2f%c",partido,ParcialesVotos, porcentaje,37);
            p("\n ----------------------------------------------\n");

     }
   tecla();

}
// funcion realizada para el punto 2
//************************************

void imprimeMaximosporPartido(registro2 y2[],int numero,char*titulo)
{
    char *partido, *aux;
    registro2 parcan;
    registro2 reg={0,0,'\0'},maximos[300]={{0,0,'\0'}}; // metere los maximos de cada partido
    registro2 auxiliar[300]={{0,0,'\0'}};
    int ContMax=0, maxi, i=0;
    numero--;
    system("cls");
    p("\n %-20s",titulo);
    p("\n -----------------------\n\n");
    while(i<numero)
     {
         auxiliar[i].cantvot=y2[i].cantvot;
         auxiliar[i].lista=y2[i].lista;
         strcpy(auxiliar[i].partido_candidato,y2[i].partido_candidato);
         i++;
     }

    i=0;
    while(i<numero)
    {
        partido=strtok(y2[i].partido_candidato,"-"); // estraigo el partido
        maxi=auxiliar[i].cantvot;
        reg=auxiliar[i];
        strcpy(parcan.partido_candidato,partido);
        while(strcmpi(partido,parcan.partido_candidato)==0 && i<numero)
            {
                if(y2[i].cantvot>maxi)
                  {
                      maxi=auxiliar[i].cantvot;
                      reg=auxiliar[i];
                      //reg.cantvot=auxiliar[i].cantvot;
                      //reg.lista=auxiliar[i].lista;
                      //strcpy(reg.partido_candidato,auxiliar[i].partido_candidato);
                  }
                i++;
                aux=strtok(y2[i].partido_candidato,"-");
                strcpy(parcan.partido_candidato,aux);
            }
        if(i<numero)
        {
        maximos[ContMax].cantvot=reg.cantvot;
        maximos[ContMax].lista=reg.lista;
        strcpy(maximos[ContMax].partido_candidato,reg.partido_candidato);
        ContMax++;
        }
    }
    tecla();
    ordenarMaximos(maximos,ContMax);
    p("\nPartido Candidato                  Lista                   Votos\n");
    p("\n----------------------------------------------------------------");
    for(i=0;i<ContMax-1;i++)
    {
        switch (i)
        {
            case 0: p("\n%-20s \t\t %4d \t\t\t  %3d    Primero",maximos[i].partido_candidato,maximos[i].lista,maximos[i].cantvot);
                    break;
            case 1: p("\n%-20s \t\t %4d \t\t\t  %3d    Segundo",maximos[i].partido_candidato,maximos[i].lista,maximos[i].cantvot);
                    break;
            case 2: p("\n%-20s \t\t %4d \t\t\t  %3d    Tercero",maximos[i].partido_candidato,maximos[i].lista,maximos[i].cantvot);
                    break;
            default:p("\n%-20s \t\t %4d \t\t\t  %3d    Resto",maximos[i].partido_candidato,maximos[i].lista,maximos[i].cantvot);

        }
        p("\n----------------------------------------------------------------");
    }
     tecla();
}
void ordenarMaximos (registro2 Maximos[],int numero)
{

    // BURBUJEO
    int i,j;
    registro2 tmp;

    for (i=0; i<numero; i++)
    {
        for (j=i+1; j<numero; j++)
        {
            if ( Maximos[i].cantvot<Maximos[j].cantvot )
            {
                tmp=Maximos[i];
                Maximos[i] = Maximos[j];
                Maximos[j]= tmp;
            }
        }
    }

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
