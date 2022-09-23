#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include "otros.h"
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"


//Prototipos Principal

int menu();

//Funcion main

int main() 
{
  system("color B5");
  tListaPacientes lista;
	tPaciente paciente;
  tListaMedicos lista_dos;
	tMedico medico;
  tListaCitas lista_tres;
	tCita cita;
  int op;
	do
	{
		op = menu();
		switch (op)
		{
		case 1:
			cout << "   " << "________________________________________________________________" << endl;
			pacientes(lista,paciente);
			cout << endl << "   " << "________________________________________________________________" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "   " << "________________________________________________________________" << endl;
			medicos(lista_dos,medico);
			cout << endl << "   " << "________________________________________________________________" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "   " << "________________________________________________________________" << endl;
			citas(lista_tres, cita, lista, lista_dos);
			cout << endl << "   " << "________________________________________________________________" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (op != 4);
	return 0;
}

int menu()
{
	int opc;
  cout  << "   " <<"_____________________________________________________" << endl;
	cout << "  |" << setw(54) << " |" << endl;
	cout << "  |" << setw(39) << " SISTEMA DE GESTION MEDICA " <<setw(15) <<"|"<< endl;
	cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
	cout << "  |" << setw(54) << " |" << endl;
	cout << "  |" << "1  PACIENTES" << setw(42) << " |" << endl;
	cout << "  |" << "2  MEDICOS" << setw(44) << " |" << endl;
	cout << "  |" << "3  CITAS" << setw(46) << " |" << endl;
	cout << "  |" << "4  SALIR" << setw(46) << " |" << endl;
	cout << "  |" << "_____________________________________________________|" << endl << endl;
	do
	{
		cout << "   OPCION: ";
		cin >> opc;
		if (opc < 1 || opc > 4)
		{
			cout << endl << "   " << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
		}
	} while (opc < 1 || opc > 4);
	return opc;
}

