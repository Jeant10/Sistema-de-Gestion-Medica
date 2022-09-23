#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include "otros.h"
#include "pacientes.h"

//1.-Pacientes

void pacientes(tListaPacientes& lista, tPaciente& paciente) {
	bool exito;
	int op, pos;
	cargar_pacientes(lista, exito);
	if (!exito) 
  {
    cout << "   " << "_____________________________________________________" << endl;
    cout << "   " << "No se ha podido cargar la lista!" << endl;
    cout << "   " << "_____________________________________________________" << endl;
	}
	else {
		do {
			op = menu_pacientes();
			switch (op) {
			case 1:
			{
        cout << "   " << "_____________________________________________________" << endl;
				leerpaciente(paciente);
				insertarpaciente(lista, paciente, exito);
				if (!exito) {
					cout << "   " << "Lista llena: imposible insertar" << endl;
				}
        cout << "   " << "_____________________________________________________" << endl;

			}
			break;
			case 2:
			{
        cout << "   " << "_____________________________________________________" << endl;
				cout << "   " << "Posición: ";
				cin >> pos;
				eliminarpaciente(lista, pos - 1, exito);
				if (!exito) {
					cout << "   " << "Elemento inexistente!" << endl;
				}
        else{
          cout << "   " << "Elemento eliminado!" << endl;
        }
        cout << "   " << "_____________________________________________________" << endl;
			}
			break;
			case 3:
			{
        cout << "   " << "_____________________________________________________" << endl;
        cout << "   " << "Posición: ";
				cin >> pos;
        modificar_paciente(lista, pos - 1, exito);
        if(exito)
        {
          cout << "\n   "  << "Elemento Modificado"<<endl;
        }
        else{
          cout << "\n   " << "Elemento no encontrado" << endl;
        }
        cout << "   " << "_____________________________________________________" << endl;
			}
			break;
			case 4:
			{
        cout << "   " << "_____________________________________________________";
        cout << "_____________________________________________________";
        cout << "_____________________________________" << endl;
        cout << endl << setw(89) << "L I S T A  D E  P A C I E N T E S" << endl << endl;
        cout << "   " << "_____________________________________________________";
        cout << "_____________________________________________________";
        cout << "_____________________________________" << endl;
        ordenarBurbuja_pacientes(lista,paciente);
			}
			}

		}while (op != 0);
		guardar_pacientes(lista);
	}
}

int menu_pacientes() 
{
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(30) << " PACIENTES " <<setw(24) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  AÑADIR PACIENTE" << setw(36) << " |" << endl;
   cout << "  |" << "2  ELIMINAR PACIENTE" << setw(34) << " |" << endl;
   cout << "  |" << "3  MODIFICAR PACIENTE" << setw(33) << " |" << endl;
   cout << "  |" << "4  LISTADO DE PACIENTES" << setw(31) << " |" << endl;
   cout << "  |" << "0  SALIR" << setw(46) << " |" << endl;
   cout << "  |" << "_____________________________________________________|" << endl << endl;
   do
   {
     cout << "   OPCION: ";
     cin >> opc;
     if (opc < 0 || opc > 4)
     {
       cout << endl << "   " << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > 4);
	return opc;
}

void cargar_pacientes(tListaPacientes& lista, bool& ok) {
	tPaciente paciente;
	ifstream archivo;
	char aux;
	lista.contador = 0;
	archivo.open("pacientes.txt");
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		getline(archivo, paciente.nombre);
		while ((paciente.nombre != "") && (lista.contador < MAX)) {
			getline(archivo, paciente.apellidos);
			archivo >> paciente.edad;
      archivo.get(aux);
			getline(archivo,paciente.cedula);
      archivo >> paciente.nacimiento.dia;
      archivo >> paciente.nacimiento.mes;
      archivo >> paciente.nacimiento.year;
      archivo >> paciente.telefono;
      archivo.get(aux);
      getline(archivo,paciente.genero);
      getline(archivo,paciente.direccion);
      getline(archivo,paciente.email);
			lista.pacientes[lista.contador] = paciente;
			lista.contador++;
			getline(archivo, paciente.nombre);
		} 
	}
  archivo.close();
}

void guardar_pacientes(const tListaPacientes lista) {
	ofstream archivo;
	archivo.open("pacientes.txt");
	for (int i = 0; i < lista.contador; i++) {
		archivo << lista.pacientes[i].nombre << endl;
		archivo << lista.pacientes[i].apellidos << endl;
		archivo << lista.pacientes[i].edad << endl;
		archivo << lista.pacientes[i].cedula << endl;
    archivo << lista.pacientes[i].nacimiento.dia << endl;
    archivo << lista.pacientes[i].nacimiento.mes << endl;
    archivo << lista.pacientes[i].nacimiento.year << endl;
    archivo << lista.pacientes[i].telefono << endl;
    archivo << lista.pacientes[i].genero << endl;
    archivo << lista.pacientes[i].direccion << endl;
    archivo << lista.pacientes[i].email << endl;
	}
	archivo << "";
	archivo.close();
}

void leerpaciente(tPaciente& paciente) 
{
	cin.ignore();
  cout << "   " << "_____________________________________________________" << endl;
  cout << "   " << "INGRESE SUS DATOS"<<endl;
	cout << "   " << "Nombre: ";
	getline(cin, paciente.nombre);
	cout << "   " << "Apellidos: ";
	getline(cin, paciente.apellidos);
	cout << "   " << "Edad: ";
	cin >> paciente.edad;
  cin.ignore();
	cout << "   " << "Cedula: ";
	getline(cin, paciente.cedula);
  cout << "   " << "Fecha de nacimiento:\n";
  pedirFecha_paciente(paciente);
	cout << "   " << "Telefono: ";
	cin >> paciente.telefono;
  cout << "   " << "Genero: ";
  cin.ignore();
	getline(cin,paciente.genero);
  cout << "   " << "Direccion: ";
	getline(cin,paciente.direccion);
  cout << "   " << "Email: ";
	getline(cin,paciente.email);
  cout << "   " << "_____________________________________________________" << endl;
}

void insertarpaciente(tListaPacientes& lista, tPaciente paciente, bool& ok) {
	ok = true;
	if (lista.contador == MAX) {
		ok = false;
	}
	else {
		lista.pacientes[lista.contador] = paciente;
		lista.contador++;
	}
}

void eliminarpaciente(tListaPacientes& lista, int pos, bool& ok)
{
	if ((pos < 0) || (pos > lista.contador - 1)) 
  {
		ok = false;
	}
	else {
		ok = true;
		for (int i = pos; i < lista.contador - 1; i++) {
			lista.pacientes[i] = lista.pacientes[i + 1];
		}
		lista.contador--;
	}
}

string nombreCompleto(tPaciente paciente) 
{
	return paciente.nombre + " " + paciente.apellidos;
}

void listado_pacientes(const tListaPacientes lista) 
{
  cout << "   "<< "Nº" << setw(12) << "Nombres "<<  setw(21) << "Cedula " << setw(14)<< "Edad ";
  cout << setw(25) << "Fecha de Nacimiento " << setw(13) << "Telefono " << setw(13)<< "Genero " << setw(16) << "Direccion " << setw(18) << "Email " << endl;
	for (int i = 0; i < lista.contador; i++) 
  {
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "_____________________________________" << endl;
    cout << "   " << i+1 << ": ";
    cout << "   " << left << setw(18) << nombreCompleto(lista.pacientes[i]);
    cout << "   " << lista.pacientes[i].cedula;
    cout << "   " << right << setw(5) << lista.pacientes[i].edad <<" años";
    cout << "   " << right << setw(8) << lista.pacientes[i].nacimiento.dia<< "/";
    cout << lista.pacientes[i].nacimiento.mes<<"/";
    cout << lista.pacientes[i].nacimiento.year;
    cout << "   " << right << setw(8) << "0" << lista.pacientes[i].telefono;
    cout << "   " << right << setw(12) << lista.pacientes[i].genero<<"  ";
    cout << "   " << right << setw(11) << lista.pacientes[i].direccion<<"  ";
    cout << "   " << lista.pacientes[i].email  << " ";
    cout << "   " << endl;
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "_____________________________________" << endl;
	 }	
}

void pedirFecha_paciente(tPaciente& paciente)
{
  bool valida = false;
  bool bisiesto = false;
  do
  { 
    cout << "   " << "Introduce el dia: ";
    cin>>paciente.nacimiento.dia;
    cout << "   " << "Introduce el mes: ";
    cin>>paciente.nacimiento.mes;
    cout << "   " << "Introduce el año: ";
    cin>>paciente.nacimiento.year;
    if(((paciente.nacimiento.year%4 == 0) && (paciente.nacimiento.year%100!=100)) || paciente.nacimiento.year%400==0)
    {
      bisiesto = true;
    }
      if(paciente.nacimiento.dia>0 && paciente.nacimiento.dia<32 && paciente.nacimiento.mes>0 && paciente.nacimiento.mes<13 && paciente.nacimiento.year>0)
      {
        if(paciente.nacimiento.mes==1 || paciente.nacimiento.mes==3 || paciente.nacimiento.mes==5 || paciente.nacimiento.mes==7 || paciente.nacimiento.mes==8 || paciente.nacimiento.mes==10 || paciente.nacimiento.mes==12)
        {
          valida=true;
        }
        else
        {
          if(paciente.nacimiento.mes==2 && paciente.nacimiento.dia<30 && bisiesto)
          { 
            valida=true;
            }
          else if(paciente.nacimiento.mes==2 && paciente.nacimiento.dia<29 && !bisiesto)
          { 
            valida=true;
            }
          else if(paciente.nacimiento.mes!=2 && paciente.nacimiento.dia<31)
          { 
            valida=true;
            }
          else
          { 
            cout << "\n   " << "Fecha no valida ... Intentelo de nuevo.\n"; 
          }
        }
      }
      else
      { 
        cout << "\n   " << "Fecha no valida ... Intentelo de nuevo.\n"; 
      } 
  }while(valida==false);
}

void modificar_paciente(tListaPacientes& lista, int pos, bool& encontrado) 
{
  int op;
  encontrado = false;
  if ((pos < 0) || (pos > lista.contador - 1)) 
  {
		encontrado = false;
	}
	else {
    encontrado = true;
    op = dato_paciente(lista,pos);
    cin.ignore();
    cout << endl << "   " << "Nuevo Dato: ";
    switch(op)
    {
      case 1:
      {
        getline(cin,lista.pacientes[pos].nombre);
      }
      break;
      case 2:
      {
        getline(cin,lista.pacientes[pos].apellidos);
      }
      break; 
      case 3:
      {
        cin >> lista.pacientes[pos].edad;
      }
      break;
      case 4:
      {
        getline(cin,lista.pacientes[pos].cedula);
      }
      break;
      case 5:
      {
        cout << "\n   " << "Dia: ";
        cin >> lista.pacientes[pos].nacimiento.dia;
        cout << "\n   " << "Mes: ";
        cin >> lista.pacientes[pos].nacimiento.mes;
        cout << "\n   " << "Año: ";
        cin >> lista.pacientes[pos].nacimiento.year;
      }
      break;
      case 6:
      {
        cin >> lista.pacientes[pos].telefono;
      }
      break;
      case 7:
      {
        getline(cin,lista.pacientes[pos].genero);
      }
      break;
      case 8:
      {
        getline(cin,lista.pacientes[pos].direccion);
      }
      break;
      case 9:
      {
        getline(cin,lista.pacientes[pos].email);
      }
      break;
    }
	}
}

int dato_paciente(tListaPacientes& lista,int pos) 
{
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(30) << " PACIENTE " <<setw(24) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl << endl;
   cout << "   " << "1  NOMBRE: " << lista.pacientes[pos].nombre << endl;
   cout << "   " << "2  APELLIDO: " << lista.pacientes[pos].apellidos << endl;
   cout << "   " << "3  EDAD: " << lista.pacientes[pos].edad << endl;
   cout << "   " << "4  CEDULA: " << lista.pacientes[pos].cedula << endl;
   cout << "   " << "5  NACIMIENTO: " << lista.pacientes[pos].nacimiento.dia << "/" << lista.pacientes[pos].nacimiento.mes << "/" << lista.pacientes[pos].nacimiento.year << endl;
   cout << "   " << "6  TELEFONO: " << lista.pacientes[pos].telefono << endl;
   cout << "   " << "7  GENERO: " << lista.pacientes[pos].genero << endl;
   cout << "   " << "8  DIRECCION: " << lista.pacientes[pos].direccion << endl;
   cout << "   " << "9  EMAIL: " << lista.pacientes[pos].email << endl;
   cout << "   " << "_____________________________________________________" << endl << endl;
   do
   {
     cout << "   OPCION A MODIFICAR: ";
     cin >> opc;
     if (opc < 1 || opc > 9)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 1 || opc > 9);

	return opc;
}  

void ordenarBurbuja_pacientes(tListaPacientes& lista, tPaciente& paciente) 
{
	int i = 0;
	bool inter = true;
	tPaciente temp;
	if (lista.contador == 0) {
		cout << endl << "ERROR! No existen datos en el registro"  << endl << endl;
	}
	else {
		while ((i < lista.contador - 1) && inter) {
			inter = false;
			for (int j = lista.contador - 1; j > i; j--) {
				if (lista.pacientes[j].nombre < lista.pacientes[j - 1].nombre ) 
        {
					temp = lista.pacientes[j];
					lista.pacientes[j] = lista.pacientes[j - 1];
					lista.pacientes[j - 1] = temp;
					inter = true;
				}
			}
			if (inter) {
				i++;
			}
		}
    listado_pacientes(lista);
	}
}