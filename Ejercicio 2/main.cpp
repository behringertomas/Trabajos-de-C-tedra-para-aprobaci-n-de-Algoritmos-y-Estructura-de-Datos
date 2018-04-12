#include <iostream>
#include <fstream>
#define CANTMESAS 5

using namespace std;
void Crear_Archivo1 (int NumMesa)
{
    int i,z;
    string Partido ,Candidato;
    int Lista,Votos,VotoBlanco,VotoImpugnado;
    ofstream Mesa("Mesa_4568.txt");
    cout <<"\nMesa "<< NumMesa <<"\n"<<endl;
    cout <<"Senadores"<<endl;
    Mesa << "Acta de la mesa: " << NumMesa <<endl;
    Mesa << "Senadores:"<<endl;
   for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
        for (z=1;z<=3;z++)
        {
            Mesa << "\n"<< Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
        }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa << "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
    Mesa << "-----------------------------------------"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"\nDiputados"<<endl;
    Mesa << "Diputados:"<<endl;
    for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
            for (z=1;z<=3;z++)
            {
            Mesa <<"\n"<<Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
            }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa<< "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
}
void Crear_Archivo2 (int NumMesa)
{
    int i,z;
    string Partido ,Candidato;
    int Lista,Votos,VotoBlanco,VotoImpugnado;
    ofstream Mesa("Mesa_4569.txt");
    cout <<"\nMesa "<< NumMesa <<"\n"<<endl;
    cout <<"Senadores"<<endl;
    Mesa << "Acta de la mesa: " << NumMesa <<endl;
    Mesa << "Senadores:"<<endl;
   for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
        for (z=1;z<=3;z++)
        {
            Mesa << "\n"<< Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
        }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa << "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
    Mesa << "-----------------------------------------"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"\nDiputados"<<endl;
    Mesa << "Diputados:"<<endl;
    for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
            for (z=1;z<=3;z++)
            {
            Mesa <<"\n"<<Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
            }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa<< "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
}
void Crear_Archivo3 (int NumMesa)
{
    int i,z;
    string Partido ,Candidato;
    int Lista,Votos,VotoBlanco,VotoImpugnado;
    ofstream Mesa("Mesa_4579.txt");
    cout <<"\nMesa "<< NumMesa <<"\n"<<endl;
    cout <<"Senadores"<<endl;
    Mesa << "Acta de la mesa: " << NumMesa <<endl;
    Mesa << "Senadores:"<<endl;
   for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
        for (z=1;z<=3;z++)
        {
            Mesa << "\n"<< Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
        }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa << "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
    Mesa << "-----------------------------------------"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"\nDiputados"<<endl;
    Mesa << "Diputados:"<<endl;
    for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
            for (z=1;z<=3;z++)
            {
            Mesa <<"\n"<<Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
            }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa<< "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
}
void Crear_Archivo4 (int NumMesa)
{
    int i,z;
    string Partido ,Candidato;
    int Lista,Votos,VotoBlanco,VotoImpugnado;
    ofstream Mesa("Mesa_4580.txt");
    cout <<"\nMesa "<< NumMesa <<"\n"<<endl;
    cout <<"Senadores"<<endl;
    Mesa << "Acta de la mesa: " << NumMesa <<endl;
    Mesa << "Senadores:"<<endl;
   for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
        for (z=1;z<=3;z++)
        {
            Mesa << "\n"<< Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
        }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa << "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
    Mesa << "-----------------------------------------"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"\nDiputados"<<endl;
    Mesa << "Diputados:"<<endl;
    for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
            for (z=1;z<=3;z++)
            {
            Mesa <<"\n"<<Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
            }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa<< "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
}
void Crear_Archivo5 (int NumMesa)
{
    int i,z;
    string Partido ,Candidato;
    int Lista,Votos,VotoBlanco,VotoImpugnado;
    ofstream Mesa("Mesa_4581.txt");
    cout <<"\nMesa "<< NumMesa <<"\n"<<endl;
    cout <<"Senadores"<<endl;
    Mesa << "Acta de la mesa: " << NumMesa <<endl;
    Mesa << "Senadores:"<<endl;
   for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
        for (z=1;z<=3;z++)
        {
            Mesa << "\n"<< Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
        }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa << "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
    Mesa << "-----------------------------------------"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"\nDiputados"<<endl;
    Mesa << "Diputados:"<<endl;
    for (i=1;i<=10;i++)
    {
        cout <<"\nIngrese Agrupacion politica: ";
        cin >> Partido;
        cout <<"Ingrese N lista: ";
        cin >> Lista;
            for (z=1;z<=3;z++)
            {
            Mesa <<"\n"<<Partido;
            Mesa << "-" << Lista;
            cout << "\nIngrese nombre del candidato " << z << " : ";
            cin >> Candidato;
            Mesa << "-" << Candidato;
            cout << "Ingrese cantidad de votos: ";
            cin >> Votos;
            Mesa << "-" << Votos <<endl;
            }
    }
    cout << "\nCantidad de votos en blanco: ";
    cin >> VotoBlanco;
    Mesa<< "\nVotos en blanco: " << VotoBlanco <<endl;
    cout << "Cantidad de votos impugnados: ";
    cin >> VotoImpugnado;
    Mesa << "Votos impugnados: "<< VotoImpugnado <<endl;
}
void NumeroDeMesa(int y, int &NumMesa)
{
    switch (y)
        {
            case 1:
            {
                NumMesa = 4568;
            }

            break;
            case 2:
            {
                NumMesa = 4569;
            }

            break;
            case 3:
            {
                NumMesa = 4579;
            }

            break;
            case 4:
            {
                NumMesa = 4580;
            }

            break;
            case 5:
            {
                NumMesa = 4581;
            }
            break;
        }
}

int main()
{
    int y=1,NumMesa=0;
    for (y=1;y<=5;y++)
    {
        NumeroDeMesa(y,NumMesa);
        if (y == 1)
            Crear_Archivo1(NumMesa);
        else
        if (y==2)
            Crear_Archivo2(NumMesa);
        else
        if (y==3)
            Crear_Archivo3(NumMesa);
        else
        if (y==4)
            Crear_Archivo4(NumMesa);
        else
            Crear_Archivo5(NumMesa);
    }

    return 0;
}
