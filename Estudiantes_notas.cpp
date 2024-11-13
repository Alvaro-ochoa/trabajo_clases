#include <iostream>
#include <vector>
//adicional, ver si aprobo la materia
using namespace std;

/* DEFINICION DE ESTRUCTURAS */
struct Estudiante
{
    int ci;
    char nombres[30];
    char apellidos[30];
    char paralelo[4];
    double nota_parcial1;
    double nota_parcial2;
    double nota_parcial3;
    char email[50];
};

/* DEFINICIONES DE FUNCIONES */
void SeleccionarOpcionMenu(vector<Estudiante>&);
void AgregarEstudiante(vector<Estudiante>&);
void MostrarEstudiante(vector<Estudiante>);
void EliminarEstudiante(vector<Estudiante>&);
void ModificarEstudiante(vector<Estudiante>&);
void BuscarEstudiante(vector<Estudiante>);

/* PROGRAMA PRINCIPAL */
int main()
{
    vector<Estudiante> notas;
    SeleccionarOpcionMenu(notas);
    return 0;
}

/* FUNCIONES */

void MenuPrincipal()
{
    system("cls");
    cout << "\tMENU PRINCIPAL" << endl;
    cout << "==========================" << endl;
    cout << "\t1. Agregar estudiante" << endl;
    cout << "\t2. Ver estudiante" << endl;
    cout << "\t3. Buscar estudiante" << endl;
    cout << "\t4. Eliminar estudiante" << endl;
    cout << "\t5. Modificar estudiante" << endl;
    cout << "\t0. SALIR" << endl;
}

void SeleccionarOpcionMenu(vector<Estudiante> &notas)
{
    int opcion = 0;
    do
    {
        MenuPrincipal();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 0:
                break;
            case 1:
                AgregarEstudiante(notas);
                system("pause");
                break;
            case 2:
                MostrarEstudiante(notas);
                system("pause");
                break;
            case 3:
                BuscarEstudiante(notas);
                system("pause");
                break;
            case 4:
                EliminarEstudiante(notas);
                system("pause");
                break;
            case 5:
                ModificarEstudiante(notas);
                system("pause");
                break;
            default:
                cout << "USTED NO HA SELECCIONADO NINGUNA OPCION" << endl;
                system("pause");
                break;
        }
    } while (opcion != 0);
}

void AgregarEstudiante(vector<Estudiante> &notas)
{
    Estudiante DatosEstudiante;
    system("cls");
    cin.ignore();
    cout << endl << "Agregar Estudiante" << endl;
    cout << "Ingresar el CI del estudiante: ";
    cin >> DatosEstudiante.ci;
    cin.ignore();
    cout << "Ingresar el nombre del estudiante: ";
    cin.getline(DatosEstudiante.nombres, 30);
    cout << "Ingresar apellidos del estudiante: ";
    cin.getline(DatosEstudiante.apellidos, 30);
    cout << "Ingresar el paralelo del estudiante: ";
    cin.getline(DatosEstudiante.paralelo, 4);
    cout << "Ingresar la nota del 1er parcial: ";
    cin >> DatosEstudiante.nota_parcial1;
    cin.ignore();
    cout << "Ingresar la nota del 2do parcial: ";
    cin >> DatosEstudiante.nota_parcial2;
    cin.ignore();
    cout << "Ingresar la nota del 3er parcial: ";
    cin >> DatosEstudiante.nota_parcial3;
    cin.ignore();
    notas.push_back(DatosEstudiante);
    cout << "El estudiante a sido agregado al sistema." << endl;
}

void MostrarEstudiante(vector<Estudiante> notas)
{
    system("cls");
    cout << endl << "LISTADO ESTUDIANTES" << endl;
    cout << "=================" << endl;
    for (int i = 0; i < notas.size(); i++)
    {
        int total=notas[i].nota_parcial1+notas[i].nota_parcial2+notas[i].nota_parcial2;
        cout << "\tEstudiante CI: " << notas[i].ci << endl;
        cout << "\t----------------" << endl;
        cout << "\tNombres: " << notas[i].nombres << endl;
        cout << "\tApellidos: " << notas[i].apellidos << endl;
        cout << "\tParalelo: " << notas[i].paralelo << endl;
        cout << "\tNota parcial 1: " << notas[i].nota_parcial1 << endl;
        cout << "\tNota parcial 2: " << notas[i].nota_parcial2 << endl;
        cout << "\tNota parcial 3: " << notas[i].nota_parcial3 << endl;
        cout << "\tNota total: " <<total << endl;
        if(total<60)
        {
            cout<<"el estudiante no aprobo la materia"<<endl;
        }
        else
        {
            cout<<"el estudiante aprobo la materia"<<endl;
        }
        cout << "\t-------------------------" << endl << endl;
    }
}

void EliminarEstudiante(vector<Estudiante> &notas)
{
    unsigned long ci = 0;
    int indice = -1;
    system("cls");
    cout << "Ingrese el CI del estudiante a eliminar: ";
    cin >> ci;
    for (int i = 0; i < notas.size(); i++)
    {
        // Buscamos si existe el ID ingresado y guardamos el indice del vector que lo apunta.
        if (notas[i].ci == ci)
            indice = i;
    }
    if (indice == -1)
    {
        cout << "No se ha encontrado el CI del estudiante." << endl;
    }
    else
    {
        notas.erase(notas.begin() + indice);
        cout << "Se ha eliminado los datos del estudiante con el CI: " << ci << " correctamente." << endl;
    }    
}

void ModificarEstudiante(vector<Estudiante> &notas)
{
    unsigned long ci = 0;
    int indice1 = -1;
    system("cls");
    cout << "Ingrese el CI del estudiante a modificar: ";
    cin >> ci;
    for (int i = 0; i < notas.size(); i++)
    {
        // Buscamos si existe el ID ingresado y guardamos el indice del vector que lo apunta.
        if (notas[i].ci == ci)
            indice1 = i;
    }
    if (indice1 == -1)
    {
        cout << "No se ha encontrado el CI del estudiante." << endl;
    }
    else
    {
        cout << endl << "MODIFICAR ESTUDIANTE CI: " << ci << endl;
        cout << "-----------------------" << endl;
        cin.ignore();
        cout << "Ingresar el nombre del estudiante: ";
        cin.getline(notas[indice1].nombres, 30);
        cout << "Ingresar el apellido del estudiante: ";
        cin.getline(notas[indice1].apellidos, 30);
        cout << "Ingresar el paralelo del estudiante: ";
        cin.getline(notas[indice1].paralelo, 4);
        cout << "Ingresar las notas del 1er parcial: ";
        cin >> notas[indice1].nota_parcial1;
        cout << "Ingresar las notas del 2er parcial: ";
        cin >> notas[indice1].nota_parcial2;
       cout << "Ingresar las notas del 3er parcial: ";
        cin >> notas[indice1].nota_parcial3;
        cout << "Se ha modificado los datos del estudiante con CI: " << ci << " correctamente." << endl;
    }    
}
void MenuSecundario()
{
    cout<<"Seleccione la forma en la que quiera buscar al estudiante "<<endl;
    cout<<"1. por nombre "<<endl;
    cout<<"2. por apellido "<<endl;
    cout<<"3. por paralelo "<<endl;
    cout<<"4. por CI "<<endl;
    cout<<"0. salir "<<endl;
}
void BuscarEstudiante(vector<Estudiante> notas)
{
    int opcion1=0;
    do
    {
        MenuSecundario();
        cout << "Seleccione una opcion: ";
        cin >> opcion1;
        switch (opcion1)
        {
            case 0:
                break;
            case 1:
            {
                cin.ignore();
                char nombres[30];
                int indice2 = -1;
                system("cls");
                cout << "Ingrese el nombre del estudiante a buscar: ";
                cin.getline(nombres, 30);
                for (int i = 0; i < notas.size(); i++)
                {
                  // Buscamos si existe el ID ingresado y guardamos el indice del vector que lo apunta.
                if (notas[i].nombres == nombres)
                    indice2 = i;
                }
                if (indice2 == -1)
                {
                    cout << "No se ha encontrado el nombre del estudiante." << endl;
                }
                else
                {
                   cout << "\tEstudiante CI: " << notas[indice2].ci << endl;
                   cout << "\t----------------" << endl;
                   cout << "\tNombres: " << notas[indice2].nombres << endl;
                   cout << "\tApellidos: " << notas[indice2].apellidos << endl;
                   cout << "\tParalelo: " << notas[indice2].paralelo << endl;
                   cout << "\tNota parcial 1: " << notas[indice2].nota_parcial1 << endl;
                   cout << "\tNota parcial 2: " << notas[indice2].nota_parcial2 << endl;
                   cout << "\tNota parcial 3: " << notas[indice2].nota_parcial3 << endl;
                   cout << "\t-------------------------" << endl << endl;
               }  
            }
            break;
            case 2:
            {
                cin.ignore();
                char apellidos[30];
                int indice = -1;
                system("cls");
                cout << "Ingrese el apellido del estudiante a buscar: ";
                cin.getline(apellidos, 30);
                for (int i = 0; i < notas.size(); i++)
                {
                  // Buscamos si existe el ID ingresado y guardamos el indice del vector que lo apunta.
                if (notas[i].apellidos == apellidos)
                  indice = i;
                }
                if (indice == -1)
                {
                   cout << "No se ha encontrado el apellido del estudiante." << endl;
                }
                else
                {
                    cout << "\tEstudiante CI: " << notas[indice].ci << endl;
                    cout << "\t----------------" << endl;
                    cout << "\tNombres: " << notas[indice].nombres << endl;
                    cout << "\tApellidos: " << notas[indice].apellidos << endl;
                    cout << "\tParalelo: " << notas[indice].paralelo << endl;
                    cout << "\tNota parcial 1: " << notas[indice].nota_parcial1 << endl;
                    cout << "\tNota parcial 2: " << notas[indice].nota_parcial2 << endl;
                    cout << "\tNota parcial 3: " << notas[indice].nota_parcial3 << endl;
                    cout << "\t-------------------------" << endl << endl;
                }  
            }
               break;
            case 3:
            {
                cin.ignore();
                char paralelo[4];
                int indice = -1;
                system("cls");
                cout << "Ingrese el paralelo del estudiante a buscar: ";
                cin.getline(paralelo,4);
                for (int i = 0; i < notas.size(); i++)
            {
        // Buscamos si existe el ID ingresado y guardamos el indice del vector que lo apunta.
        if (notas[i].paralelo == paralelo)
            indice = i;
    }
    if (indice == -1)
    {
        cout << "No se ha encontrado el paralelo del estudiante." << endl;
    }
    else
    {
        cout << "\tEstudiante CI: " << notas[indice].ci << endl;
        cout << "\t----------------" << endl;
        cout << "\tNombres: " << notas[indice].nombres << endl;
        cout << "\tApellidos: " << notas[indice].apellidos << endl;
        cout << "\tParalelo: " << notas[indice].paralelo << endl;
        cout << "\tNota parcial 1: " << notas[indice].nota_parcial1 << endl;
        cout << "\tNota parcial 2: " << notas[indice].nota_parcial2 << endl;
        cout << "\tNota parcial 3: " << notas[indice].nota_parcial3 << endl;
        cout << "\t-------------------------" << endl << endl;
    }  
        }
        break;
            case 4:
            {
                unsigned long ci = 0;
                int indice = -1;
                system("cls");
                cout << "Ingrese el CI del estudiante a buscar: ";
                cin >> ci;
                for (int i = 0; i < notas.size(); i++)
                {
                 // Buscamos si existe el ID ingresado y guardamos el indice del vector que lo apunta.
                  if (notas[i].ci == ci)
                     indice = i;
                }
                if (indice == -1)
                {
                     cout << "No se ha encontrado el CI del estudiante." << endl;
                }
                else
                {
                    cout << "\tEstudiante CI: " << notas[indice].ci << endl;
                    cout << "\t----------------" << endl;
                    cout << "\tNombres: " << notas[indice].nombres << endl;
                    cout << "\tApellidos: " << notas[indice].apellidos << endl;
                    cout << "\tParalelo: " << notas[indice].paralelo << endl;
                    cout << "\tNota parcial 1: " << notas[indice].nota_parcial1 << endl;
                    cout << "\tNota parcial 2: " << notas[indice].nota_parcial2 << endl;
                    cout << "\tNota parcial 3: " << notas[indice].nota_parcial3 << endl;
                    cout << "\t-------------------------" << endl;
                }  
            }
            break;
            default:
                cout << "USTED NO HA SELECCIONADO NINGUNA OPCION" << endl;
                system("pause");
                break;
        }
    } while (opcion1 != 0);
}