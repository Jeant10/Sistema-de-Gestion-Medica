#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include "otros.h"
#include "medicos.h"


//2.-Medicos

void medicos(tListaMedicos& lista, tMedico& medico) 
{
	bool exito;
	int op, pos;
	cargar_medico(lista, exito);
	if (!exito) 
  {
    cout << "   " << "No se ha podido cargar la lista!" << endl;
	}
	else {
		do {
			op = menu_medico();
			switch (op) {
			case 1:
			{
        cout << "   " << "_____________________________________________________" << endl;
				leermedico(medico);
				insertarmedico(lista, medico, exito);
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
				eliminarmedico(lista, pos - 1, exito);
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
        modificar_medico(lista, pos - 1, exito);
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
        cout << "________________________________________________________" << endl;
        cout << endl << setw(91) << "L I S T A  D E  M E D I C O S " << endl << endl;
        cout << "   " << "_____________________________________________________"; 
        cout << "_____________________________________________________";
        cout << "________________________________________________________" << endl;
        ordenarBurbuja_medicos(lista,medico);
			}
			}
		} while (op != 0);
		guardar_medico(lista);
	}
}

int menu_medico() 
{
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(30) << " MEDICOS " <<setw(24) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  AÑADIR MEDICO" << setw(38) << " |" << endl;
   cout << "  |" << "2  ELIMINAR MEDICO" << setw(36) << " |" << endl;
   cout << "  |" << "3  MODIFICAR MEDICO" << setw(35) << " |" << endl;
   cout << "  |" << "4  LISTADO DE MEDICOS" << setw(33) << " |" << endl;
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

void cargar_medico(tListaMedicos& lista, bool& ok) {
	tMedico medico;
	ifstream archivo;
	char aux;
	lista.contador = 0;
	archivo.open("medicos.txt");
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		getline(archivo, medico.nombre);
		while ((medico.nombre != "") && (lista.contador < MAX)) {
			getline(archivo, medico.apellidos);
			archivo >> medico.edad;
      archivo.get(aux);
			getline(archivo,medico.cedula);
      archivo >> medico.nacimiento.dia;
      archivo >> medico.nacimiento.mes;
      archivo >> medico.nacimiento.year;
      archivo >> medico.telefono;
      archivo.get(aux);
      getline(archivo,medico.genero);
      getline(archivo,medico.especialidad);
      getline(archivo,medico.direccion);
      getline(archivo,medico.email);
			lista.medicos[lista.contador] = medico;
			lista.contador++;
			getline(archivo, medico.nombre);
		} 
	}
  archivo.close();
}

void guardar_medico(const tListaMedicos lista) {
	ofstream archivo;
	archivo.open("medicos.txt");
	for (int i = 0; i < lista.contador; i++) {
		archivo << lista.medicos[i].nombre << endl;
		archivo << lista.medicos[i].apellidos << endl;
		archivo << lista.medicos[i].edad << endl;
		archivo << lista.medicos[i].cedula << endl;
    archivo << lista.medicos[i].nacimiento.dia << endl;
    archivo << lista.medicos[i].nacimiento.mes << endl;
    archivo << lista.medicos[i].nacimiento.year << endl;
    archivo << lista.medicos[i].telefono << endl;
    archivo << lista.medicos[i].genero << endl;
    archivo << lista.medicos[i].especialidad<< endl;
    archivo << lista.medicos[i].direccion << endl;
    archivo << lista.medicos[i].email << endl;
	}
	archivo << "";
	archivo.close();
}

void leermedico(tMedico& medico) 
{
	cin.ignore();
  cout << "   " << "_____________________________________________________" << endl;
  cout << "   " << "INGRESE SUS DATOS"<<endl;
	cout << "   " << "Nombre: ";
	getline(cin, medico.nombre);
	cout << "   " << "Apellidos: ";
	getline(cin, medico.apellidos);
	cout << "   " << "Edad: ";
	cin >> medico.edad;
  cin.ignore();
	cout << "   " << "Cedula: ";
	getline(cin, medico.cedula);
  cout << "   " << "Fecha de nacimiento:\n";
  pedirFecha_medico(medico);
	cout << "   " << "Telefono: ";
	cin >> medico.telefono;
  cout << "   " << "Genero: ";
  cin.ignore();
	getline(cin,medico.genero);
  cout << "   " << "Especialidad: ";
	getline(cin,medico.especialidad);
  cout << "   " << "Direccion: ";
	getline(cin,medico.direccion);
  cout << "   " << "Email: ";
	getline(cin,medico.email);
  cout << "   " << "_____________________________________________________" << endl;
}

void insertarmedico(tListaMedicos& lista, tMedico medico, bool& ok) {
	ok = true;
	if (lista.contador == MAX) {
		ok = false;
	}
	else {
		lista.medicos[lista.contador] = medico;
		lista.contador++;
	}
}

void eliminarmedico(tListaMedicos& lista, int pos, bool& ok)
{
	if ((pos < 0) || (pos > lista.contador - 1)) 
  {
		ok = false;
	}
	else {
		ok = true;
		for (int i = pos; i < lista.contador - 1; i++) {
			lista.medicos[i] = lista.medicos[i + 1];
		}
		lista.contador--;
	}
}

string nombreCompleto(tMedico medico) 
{
	return medico.nombre + " " + medico.apellidos;
}

void listado_medico(const tListaMedicos lista) 
{
  cout << "   "<< "Nº" << setw(12) << "Nombres "<<  setw(22) << "Cedula " << setw(14)<< "Edad ";
  cout << setw(25) << "Fecha de Nacimiento " << setw(13) << "Telefono " << setw(14)<< "Genero " << setw(19) << "Especialidad "<< setw(15) << "Direccion " << setw(15) << "Email " << endl;
	for (int i = 0; i < lista.contador; i++) 
  {
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "________________________________________________________" << endl;
    cout << "   " << i+1<<": ";
    cout << "   " << left<<setw(18) << nombreCompleto(lista.medicos[i]);
    cout << "   " << lista.medicos[i].cedula;
    cout << "   " << right << setw(6) << lista.medicos[i].edad <<" años";
    cout << "   " << right << setw(8) << lista.medicos[i].nacimiento.dia<< "/";
    cout << lista.medicos[i].nacimiento.mes<<"/";
    cout << lista.medicos[i].nacimiento.year;
    cout << "   " << right << setw(7) << "0" << lista.medicos[i].telefono;
    cout << "   " << right << setw(12) << lista.medicos[i].genero<<"  ";
    cout << "   " << right << setw(11) << lista.medicos[i].especialidad<<"  ";
    cout << "   " << right << setw(12) << lista.medicos[i].direccion<<"  ";
    cout << "   " << lista.medicos[i].email  << " ";
    cout << endl;
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "________________________________________________________" << endl;
	 }	
}

void pedirFecha_medico(tMedico& medico)
{
  bool valida = false;
  bool bisiesto = false;
  do
  { 
    cout << "   " << "Introduce el dia: ";
    cin>>medico.nacimiento.dia;
    cout << "   " << "Introduce el mes: ";
    cin>>medico.nacimiento.mes;
    cout << "   " << "Introduce el año: ";
    cin>>medico.nacimiento.year;
    if(((medico.nacimiento.year%4 == 0) && (medico.nacimiento.year%100!=100)) || medico.nacimiento.year%400==0)
    {
      bisiesto = true;
    }
      if(medico.nacimiento.dia>0 && medico.nacimiento.dia<32 && medico.nacimiento.mes>0 && medico.nacimiento.mes<13 && medico.nacimiento.year>0)
      {
        if(medico.nacimiento.mes==1 || medico.nacimiento.mes==3 || medico.nacimiento.mes==5 || medico.nacimiento.mes==7 || medico.nacimiento.mes==8 || medico.nacimiento.mes==10 || medico.nacimiento.mes==12)
        {
          valida=true;
        }
        else
        {
          if(medico.nacimiento.mes==2 && medico.nacimiento.dia<30 && bisiesto)
          { 
            valida=true;
            }
          else if(medico.nacimiento.mes==2 && medico.nacimiento.dia<29 && !bisiesto)
          { 
            valida=true;
            }
          else if(medico.nacimiento.mes!=2 && medico.nacimiento.dia<31)
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

void modificar_medico(tListaMedicos& lista, int pos, bool& encontrado) 
{
  int op;
  encontrado = false;
  if ((pos < 0) || (pos > lista.contador - 1)) 
  {
		encontrado = false;
	}
	else {
    encontrado = true;
    op = dato_medico(lista,pos);
    cin.ignore();
    cout << endl << "   " << "Nuevo Dato: ";
    switch(op)
    {
      case 1:
      {
        getline(cin,lista.medicos[pos].nombre);
      }
      break;
      case 2:
      {
        getline(cin,lista.medicos[pos].apellidos);
      }
      break; 
      case 3:
      {
        cin >> lista.medicos[pos].edad;
      
      }
      break;
      case 4:
      {
        getline(cin,lista.medicos[pos].cedula);
      }
      break;
      case 5:
      {
        cout << "\n   " << "Dia: ";
        cin >> lista.medicos[pos].nacimiento.dia;
        cout << "\n   " << "Mes: ";
        cin >> lista.medicos[pos].nacimiento.mes;
        cout << "\n   " << "Año: ";
        cin >> lista.medicos[pos].nacimiento.year;
      }
      break;
      case 6:
      {
        cin >> lista.medicos[pos].telefono;
      }
      break;
      case 7:
      {
        getline(cin,lista.medicos[pos].genero);
      }
      break;
      case 8:
      {
        getline(cin,lista.medicos[pos].especialidad);
      }
      break;
      case 9:
      {
        getline(cin,lista.medicos[pos].direccion);
      }
      break;
      case 10:
      {
        getline(cin,lista.medicos[pos].email);
      }
      break;
    }
	}
}

int dato_medico(tListaMedicos& lista,int pos) 
{
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(96) << "  |" << endl;
   cout << "  |" << setw(30) << " MEDICO " <<setw(10) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl << endl;
   cout << "   " << "1  NOMBRE: " << lista.medicos[pos].nombre << endl;
   cout << "   " << "2  APELLIDO: " << lista.medicos[pos].apellidos << endl;
   cout << "   " << "3  EDAD: " << lista.medicos[pos].edad  << endl;
   cout << "   " << "4  CEDULA: " << lista.medicos[pos].cedula  << endl;
   cout << "   " << "5  NACIMIENTO: " << lista.medicos[pos].nacimiento.dia << "/" << lista.medicos[pos].nacimiento.mes << "/" << lista.medicos[pos].nacimiento.year << endl;
   cout << "   " << "6  TELEFONO: " << lista.medicos[pos].telefono  << endl;
   cout << "   " << "7  GENERO: " << lista.medicos[pos].genero << endl;
   cout << "   " << "8  ESPECIALIDAD: " << lista.medicos[pos].especialidad << endl;
   cout << "   " << "9  DIRECCION: " << lista.medicos[pos].direccion << endl;
   cout << "   " << "10 EMAIL: " << lista.medicos[pos].email << endl;
   cout << "   " << "_____________________________________________________" << endl << endl;
   do
   {
     cout << "   OPCION A MODIFICAR: ";
     cin >> opc;
     if (opc < 1 || opc > 10)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 1 || opc > 10);

	return opc;
}  

void ordenarBurbuja_medicos(tListaMedicos& lista, tMedico& medico) 
{
	int i = 0;
	bool inter = true;
	tMedico temp;
	if (lista.contador == 0) {
		cout << endl << "ERROR! No existen datos en el registro" << endl << endl;
	}
	else {
		while ((i < lista.contador - 1) && inter) {
			inter = false;
			for (int j = lista.contador - 1; j > i; j--) {
				if (lista.medicos[j].nombre < lista.medicos[j - 1].nombre) {
					temp = lista.medicos[j];
					lista.medicos[j] = lista.medicos[j - 1];
					lista.medicos[j - 1] = temp;
					inter = true;
				}
			}
			if (inter) {
				i++;
			}
		}
    listado_medico(lista);
	}
}