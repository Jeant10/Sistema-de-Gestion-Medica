#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include "otros.h"
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"



//3.-Citas

void citas(tListaCitas& lista, tCita& cita, tListaPacientes& lista_uno, tListaMedicos& lista_dos)
{
  int dia, mes, year;
	bool exito;
	int op, opc, pos;
  string dato;
	cargar_cita(lista, exito);
  cargar_pacientes(lista_uno, exito);
  cargar_medico(lista_dos, exito);
	if (!exito) 
  {
    cout << "   " << "_____________________________________________________" << endl;
    cout << "   " << " No se ha podido cargar la lista!" << endl;
    cout << "   " << "_____________________________________________________" << endl;
	}
	else {
		do {
			op = menu_cita();
			switch (op) {
			case 1:
			{
        cout << "   " << "_____________________________________________________" << endl;
				leercita(cita ,lista_uno, lista_dos);
				insertarcita(lista, cita, exito);
				if (!exito) 
        {
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
				eliminarcita(lista, pos - 1, exito);
				if (!exito) {
					cout << "   " << "Elemento inexistente!" << endl;
				}
        else
        {
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
        modificar_cita(lista, pos - 1, exito, lista_dos);
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
        cout << "   " << "_____________________________________________________" << endl;
        do{
          opc = cita_opcion();
          switch(opc)
          {
            case 1:
            {
              if (lista.contador == 0) {
                  cout << endl << "   " << "ERROR! No existen datos en el registro"  << endl << endl;
              }else{
                cout << "   " << "Fecha" << endl;
                cout << "   " << "Dia: ";
                cin >> dia;
                cout << "   " << "Mes: ";
                cin >> mes;
                cout << "   " << "Año: ";
                cin >> year;
                cout << "   " << "_____________________________________________________" << endl;
                cout << endl << setw(42) << "C I T A S  P O R  F E C H A" << endl << endl;
                ordenarBurbuja_fecha(lista,cita);
                buscar_fecha(lista,dia,mes,year);
                ordenarBurbuja_citas(lista,cita);
              }
            }
            break;
            case 2:
            {
              if (lista.contador == 0) {
                  cout << endl << "   " << "ERROR! No existen datos en el registro"  << endl << endl;
              }else{
                cin.ignore();
                cout << "   " << "Ingrese especialidad a buscar:  ";
                getline(cin,dato);
                cout << "   " << "_____________________________________________________"; 
                cout << "_____________________________________________________";
                cout << "________________________________________________" << endl;
                cout << endl << setw(99) << "C I T A S  P O R  E S P E C I A L I D A D" << endl << endl;
                ordenarBurbuja_citas(lista,cita);
                buscar_especialidad(lista,lista_dos,dato); 
              }
            }
            break;
            case 3:
            {
              if (lista.contador == 0) {
                  cout << endl << "   " << "ERROR! No existen datos en el registro"  << endl << endl;
              }else{
                cout << "   " << "_____________________________________________________"; 
                cout << "_____________________________________________________";
                cout << "________________________________________________________" << endl;
                cout << endl << setw(91) << "L I S T A  D E  C I T A S " << endl << endl;
                cout << "   " << "_____________________________________________________"; 
                cout << "_____________________________________________________";
                cout << "________________________________________________________" << endl;
                ordenarBurbuja_citas(lista,cita);
                listado_cita(lista);
              }
            }
            break;
          }
        } while(opc!=0);
        cout << "   " << "_____________________________________________________" << endl;
			}
      break;
			}
		} while (op != 0);
		guardar_cita(lista);
	}
}

int menu_cita() 
{
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(30) << " CITAS " <<setw(24) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  AÑADIR CITA" << setw(40) << " |" << endl;
   cout << "  |" << "2  ELIMINAR CITA" << setw(38) << " |" << endl;
   cout << "  |" << "3  MODIFICAR CITA" << setw(37) << " |" << endl;
   cout << "  |" << "4  LISTADO DE CITAS" << setw(35) << " |" << endl;
   cout << "  |" << "0  SALIR" << setw(46) << " |" << endl;
   cout << "  |" << "_____________________________________________________|" << endl << endl;
   do
   {
     cout << "   OPCION: ";
     cin >> opc;
     if (opc < 0 || opc > 4)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > 4);
	return opc;
}

void cargar_cita(tListaCitas& lista, bool& ok) {
	tCita cita;
	ifstream archivo;
	char aux;
	lista.contador = 0;
	archivo.open("citas.txt");
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
    getline(archivo, cita.paciente);
		while ((cita.paciente != "") && (lista.contador < MAX)) 
    {
      getline(archivo, cita.centromedico);
			archivo >> cita.fecha.dia;
      archivo >> cita.fecha.mes;
      archivo >> cita.fecha.year;
      archivo >> cita.hora.hora;
      archivo >> cita.hora.minutos;
      archivo.get(aux);
      getline(archivo,cita.sintomas);
      getline(archivo,cita.enfermedad);
      getline(archivo,cita.tratamiento);
      getline(archivo,cita.doctor);
      getline(archivo,cita.descripcion);
      getline(archivo,cita.estado);
      getline(archivo,cita.pago);
      archivo >> cita.costo;
			lista.citas[lista.contador] = cita;
			lista.contador++;
      archivo.get(aux);
			getline(archivo, cita.paciente);
		} 
	}
  archivo.close();
}

void guardar_cita(const tListaCitas lista) {
	ofstream archivo;
	archivo.open("citas.txt");
	for (int i = 0; i < lista.contador; i++) {
    archivo << lista.citas[i].paciente << endl;
		archivo << lista.citas[i].centromedico << endl;
    archivo << lista.citas[i].fecha.dia << endl;
    archivo << lista.citas[i].fecha.mes << endl;
    archivo << lista.citas[i].fecha.year << endl;
    archivo << lista.citas[i].hora.hora << endl;
    archivo << lista.citas[i].hora.minutos << endl;
    archivo << lista.citas[i].sintomas << endl;
    archivo << lista.citas[i].enfermedad << endl;
    archivo << lista.citas[i].tratamiento<< endl;
    archivo << lista.citas[i].doctor << endl;
    archivo << lista.citas[i].descripcion << endl;
    archivo << lista.citas[i].estado<< endl;
    archivo << lista.citas[i].pago<< endl;
    archivo << lista.citas[i].costo << endl;
	}
	archivo << "";
	archivo.close();
}

void leercita(tCita& cita, tListaPacientes& lista, tListaMedicos& lista_dos) 
{
    int opc, op;
    cin.ignore();
    cout << "   " << "_____________________________________________________" << endl;
    opc = paciente_cita(lista);
    cita.paciente = lista.pacientes[opc-1].nombre + " " + lista.pacientes[opc-1].apellidos; 
    cin.ignore();
    cout << "   " << "Paciente: " << cita.paciente << endl;
    cout << "   " << "INGRESE LOS DATOS DE LA CITA"<<endl;
    cout << "   " << "Centro Medico: ";
    getline(cin, cita.centromedico);
    cout << "   " << "Fecha de atencion:\n";
    pedirFecha_cita(cita);
    cout << "   " << "Hora de atencion:\n";
    leerhora(cita);
    cin.ignore();
    cout << "   " << "Sintomas: ";
    getline(cin,cita.sintomas);
    cout << "   " << "Enfermedad: ";
    getline(cin,cita.enfermedad);
    cout << "   " << "Tratamiento: ";
    getline(cin,cita.tratamiento);
    op = paciente_medico(lista_dos);
    cita.doctor = lista_dos.medicos[op-1].nombre + " " + lista_dos.medicos[op-1].apellidos; 
    cita.descripcion = lista_dos.medicos[op-1].especialidad; 
    cout << "   " << "Medico asignado: " << cita.doctor << endl;
    cout << "   " << "Descripcion: " << cita.descripcion << endl;
     cout << "   " << "Estado de cita: ";
    cin >> cita.estado;
    cout << "   " << "Estado del Pago : ";
    cin >> cita.pago;
    cout << "   " << "Costo: ";
    cin >> cita.costo;
    cout << "   " << "_____________________________________________________" << endl; 
}

void insertarcita(tListaCitas& lista, tCita cita, bool& ok) {
	ok = true;
	if (lista.contador == MAX) {
		ok = false;
	}
	else {
		lista.citas[lista.contador] = cita;
		lista.contador++;
	}
}

void eliminarcita(tListaCitas& lista, int pos, bool& ok)
{
	if ((pos < 0) || (pos > lista.contador - 1)) 
  {
		ok = false;
	}
	else {
		ok = true;
		for (int i = pos; i < lista.contador - 1; i++) {
			lista.citas[i] = lista.citas[i + 1];
		}
		lista.contador--;
	}
}

string nombreCompleto(tCita cita) 
{
	return cita.paciente;
}

void listado_cita(const tListaCitas lista) 
{
  cout << "   "<< "Nº" << setw(13) << "Paciente "<<  setw(16) << "Centro Medico " << setw(9)<< "Fecha ";
  cout << setw(11) << "Hora " << setw(14) << "Sintomas " << setw(16)<< "Enfermedad " << setw(15) << "Tratamiento "<< setw(11) << "Doctor " << setw(20) << "Descripcion " << setw(12) << "Estado" << setw(12) << "Pago" << setw(10) << "Costo" <<endl;
	for (int i = 0; i < lista.contador; i++) 
  {
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "________________________________________________________" << endl;
    cout << "   " << i+1 << ": ";
    cout << "   " << left <<setw(10) << nombreCompleto(lista.citas[i]);
    cout << "   " << lista.citas[i].centromedico;
    cout << "   " << right << setw(4) << lista.citas[i].fecha.dia<< "/";
    cout << lista.citas[i].fecha.mes<<"/";
    cout << lista.citas[i].fecha.year;
    cout << "   " << right << setw(4) << lista.citas[i].hora.hora<< ":";
    cout << lista.citas[i].hora.minutos<<" ";
    cout << "   " << right << setw(8) << lista.citas[i].sintomas;
    cout << "   " << right << setw(11) << lista.citas[i].enfermedad<<"  ";
    cout << "   " << right << setw(11) << lista.citas[i].tratamiento<<"  ";
    cout << "   " << right << setw(11) << lista.citas[i].doctor<<"  ";
    cout << "   " << right << setw(11) << lista.citas[i].descripcion<<"  ";
    cout << "  " << right << setw(11) << lista.citas[i].estado<<" ";
    cout << "   " << right << setw(9) << lista.citas[i].pago<<"  ";
    cout << "  " << lista.citas[i].costo  << " ";
    cout << endl;
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "________________________________________________________" << endl;
	 }	
}

void pedirFecha_cita(tCita& cita)
{
  bool valida = false;
  bool bisiesto = false;
  do
  { 
    cout << "   " << "Introduce el dia: ";
    cin>>cita.fecha.dia;
    cout << "   " << "Introduce el mes: ";
    cin>>cita.fecha.mes;
    cout << "   " << "Introduce el año: ";
    cin>>cita.fecha.year;
    if(((cita.fecha.year%4 == 0) && (cita.fecha.year%100!=100)) || cita.fecha.year%400==0)
    {
      bisiesto = true;
    }
      if(cita.fecha.dia>0 && cita.fecha.dia<32 && cita.fecha.mes>0 && cita.fecha.mes<13 && cita.fecha.year>0)
      {
        if(cita.fecha.mes==1 || cita.fecha.mes==3 || cita.fecha.mes==5 || cita.fecha.mes==7 || cita.fecha.mes==8 || cita.fecha.mes==10 || cita.fecha.mes==12)
        {
          valida=true;
        }
        else
        {
          if(cita.fecha.mes==2 && cita.fecha.dia<30 && bisiesto)
          { 
            valida=true;
            }
          else if(cita.fecha.mes==2 && cita.fecha.dia<29 && !bisiesto)
          { 
            valida=true;
            }
          else if(cita.fecha.mes!=2 && cita.fecha.dia<31)
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
  } while(valida==false);
}

void leerhora(tCita& cita)
{
  bool valida = true;
  do{
    
    cout<< "   " <<"Horas: "; 
    cin>>cita.hora.hora;
    cout<< "   " <<"Minutos: "; 
    cin>>cita.hora.minutos;

    if(cita.hora.hora<0 || cita.hora.hora>24)
    {  
      valida = false; 
    }
    else if(cita.hora.minutos<0 || cita.hora.minutos>59) 
    { 
      valida = false; 
    }
    else
    { 
      valida = true;
    }

    if(valida==false)
    { 
      cout<< "\n   " <<"Hora no valida\n\n"; 
    }

  }while(valida==false);

}

void modificar_cita(tListaCitas& lista, int pos, bool& encontrado, tListaMedicos& lista_dos) 
{
  int op,opc;
  encontrado = false;
  if ((pos < 0) || (pos > lista.contador - 1)) 
  {
		encontrado = false;
	}
	else {
    encontrado = true;
    op = dato_cita(lista,pos);
    cin.ignore();
    cout << endl << "   " << "Nuevo Dato: ";
    switch(op)
    {
      case 1:
      {
        getline(cin,lista.citas[pos].centromedico);
      break; 
      }
      case 2:
      {
        cout << "\n   " << "Dia: ";
        cin >> lista.citas[pos].fecha.dia;
        cout << "\n   " << "Mes: ";
        cin >> lista.citas[pos].fecha.mes;
        cout << "\n   " << "Año: ";
        cin >> lista.citas[pos].fecha.year;
      }
      break;
      case 3:
      {
        cout << "\n   " << "Hora: ";
        cin >> lista.citas[pos].hora.hora;
        cout << "\n   " << "Minutos: ";
        cin >> lista.citas[pos].hora.minutos;
      }
      break;
      case 4:
      {
        getline(cin,lista.citas[pos].sintomas);
      }
      break;
      case 5:
      {
        getline(cin,lista.citas[pos].enfermedad);
      }
      break;
      case 6:
      {
        getline(cin,lista.citas[pos].tratamiento);
      }
      break;
      case 7:
      {
        cout << endl;
        opc = paciente_medico(lista_dos);
        lista.citas[pos].doctor=lista_dos.medicos[opc-1].nombre + " " + lista_dos.medicos[opc-1].apellidos;
        lista.citas[pos].descripcion = lista_dos.medicos[opc-1].especialidad; 
      }
      break;
      case 8:
      {
        cin >> lista.citas[pos].costo;
      }
      break;
    }
	}
}

int dato_cita(tListaCitas& lista,int pos) 
{
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(30) << " CITA " <<setw(24) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl << endl;
   cout << "   " << "   PACIENTE: " << lista.citas[pos].paciente << endl;
   cout << "   " << "   ESTADO: " << lista.citas[pos].estado << endl;
   cout << "   " << "   PAGO: " << lista.citas[pos].pago  << endl;
   cout << "   " << "1  CENTRO MEDICO: " << lista.citas[pos].centromedico  << endl;
   cout << "   " << "2  FECHA DE ATENCION: " << lista.citas[pos].fecha.dia << "/" << lista.citas[pos].fecha.mes << "/" << lista.citas[pos].fecha.year << endl;
   cout << "   " << "3  HORA DE ATENCION: " << lista.citas[pos].hora.hora << ":" << lista.citas[pos].hora.minutos << endl;
   cout << "   " << "4  SINTOMAS: " << lista.citas[pos].sintomas << endl;
   cout << "   " << "5  ENFERMEDAD: " << lista.citas[pos].enfermedad << endl;
   cout << "   " << "6  TRATAMIENTO: " << lista.citas[pos].tratamiento << endl;
   cout << "   " << "7  DOCTOR: " << lista.citas[pos].doctor << endl;
   cout << "   " << "   DESCRIPCION: " << lista.citas[pos].descripcion << endl;
   cout << "   " << "8  COSTO: " << lista.citas[pos].costo << endl;
   cout << "   " << "_____________________________________________________" << endl << endl;
   do
   {
     cout << "   OPCION A MODIFICAR: ";
     cin >> opc;
     if (opc < 1 || opc > 8)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 1 || opc > 8);

	return opc;
}  

void ordenarBurbuja_citas(tListaCitas& lista, tCita& cita) 
{
	int i = 0;
	bool inter = true;
	tCita temp;
	while ((i < lista.contador - 1) && inter) {
			inter = false;
			for (int j = lista.contador - 1; j > i; j--) {
				if (lista.citas[j].paciente < lista.citas[j - 1].paciente) {
					temp = lista.citas[j];
					lista.citas[j] = lista.citas[j - 1];
					lista.citas[j - 1] = temp;
					inter = true;
				}
			}
			if (inter) {
				i++;
			}
		}
}

void descripcion_cita(const tListaCitas lista, int i)
{
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "________________________________________________" << endl;
    cout << "   " << i+1 << ": ";
    cout << "   " << left<<setw(10) << nombreCompleto(lista.citas[i]);
    cout << "   " << lista.citas[i].centromedico;
    cout << "   " << right << setw(4) << lista.citas[i].fecha.dia<< "/";
    cout << lista.citas[i].fecha.mes<<"/";
    cout << lista.citas[i].fecha.year;
    cout << "   " << right << setw(4) << lista.citas[i].hora.hora<< ":";
    cout << lista.citas[i].hora.minutos<<" ";
    cout << "   " << right << setw(8) << lista.citas[i].sintomas;
    cout << "   " << right << setw(11) << lista.citas[i].enfermedad<<"  ";
    cout << "   " << right << setw(11) << lista.citas[i].tratamiento<<"  ";
    cout << "   " << right << setw(11) << lista.citas[i].doctor<<"  ";
    cout << "   " << right << setw(11) << lista.citas[i].estado<<"  ";
    cout << "  " << right << setw(12) << lista.citas[i].pago<<"   ";
    cout << "   " << lista.citas[i].costo  << " ";
    cout << endl;
    cout << "   " << "_____________________________________________________"; 
    cout << "_____________________________________________________";
    cout << "________________________________________________" << endl;
}

void fecha_cita(const tListaCitas lista, int i)
{
    cout << "   " << "_____________________________________________________" << endl;
    cout << "   " << right << setw(4) << lista.citas[i].hora.hora<< ":";
    cout << lista.citas[i].hora.minutos << " ";
    cout << "   " << left<<setw(10) << nombreCompleto(lista.citas[i]);
    cout << "   " << lista.citas[i].centromedico;
    cout << "   " << right << setw(15)<< lista.citas[i].descripcion << endl;
    cout << "   " << "_____________________________________________________" << endl;
}

void buscar_fecha(const tListaCitas &lista, int dia, int mes, int year) 
{
  int ind;
  bool encontrado = false;
  cout << "   " << "_____________________________________________________" << endl;
  cout << endl << "     "<< "Hora " << setw(12) << "Paciente "<<  setw(16) << "Centro Medico " << setw(15)<< "Descripcion " << endl;
  for(ind = 0; ind < lista.contador; ind++)
  {
    if (lista.citas[ind].fecha.dia == dia && lista.citas[ind].fecha.mes == mes && lista.citas[ind].fecha.year == year) 
    {
      fecha_cita(lista,ind);
      encontrado = true;
    }
  } 
  if(!encontrado)
  {
    cout << endl << "   " << "Fecha no encontrada! " << endl;
  }

}

void buscar_especialidad(const tListaCitas &lista, tListaMedicos lista_dos, string dato) 
{
  int ind;
  int i;
  bool encontrado = false;
  cout << "   " << "_____________________________________________________"; 
  cout << "_____________________________________________________";
  cout << "________________________________________________" << endl;
  cout << endl << "   "<< "Nº" << setw(13) << "Paciente "<<  setw(16) << "Centro Medico " << setw(9)<< "Fecha ";
  cout << setw(11) << "Hora " << setw(14) << "Sintomas " << setw(16)<< "Enfermedad " << setw(15) << "Tratamiento "<< setw(11) << "Doctor " << setw(18) << "Estado " << setw(14) << "Pago" << setw(12) << "Costo" << endl;
  for(ind = 0; ind < lista.contador; ind++)
  {
    if (lista.citas[ind].descripcion == dato) 
    {  
      descripcion_cita(lista,ind); 
      encontrado = true;
    }
  } 
  if(!encontrado)
  {
    cout << endl << "   " << "Especialidad no encontrada! " << endl;
  }
}

int paciente_cita(const tListaPacientes lista) 
{
   int opc;
   int i;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(36) << " LISTA DE PACIENTES" <<setw(18) <<"|"<< endl;
   cout  << "  |" <<"_____________________________________________________|" << endl << endl;
   for (i = 0; i < lista.contador; i++) 
   {
     cout << "   " << i+1<<": ";
     cout << "   " << left << setw(28) << nombreCompleto(lista.pacientes[i]) << endl;
   }
   cout << "   " << "_____________________________________________________" << endl << endl;
   do
   {
     cout << "   ESCOGA EL PACIENTE: ";
     cin >> opc;
     if (opc < 0 || opc > i)
     {
       cout << endl << "   " << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > i);
	return opc;
}

int cita_opcion() 
{
   int opc;
   cout  << endl << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << right << setw(54) << " |" << endl;
   cout << "  |" << right << setw(30) << " CITA " <<setw(24) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  POR FECHA" << setw(42) << " |" << endl;
   cout << "  |" << "2  POR ESPECIALIDAD" << setw(35) << " |" << endl;
   cout << "  |" << "3  TODAS" << setw(46) << " |" << endl;
   cout << "  |" << "0  SALIR" << setw(46) << " |" << endl;
   cout << "  |" << "_____________________________________________________|" << endl << endl;
   do
   {
     cout << "   OPCION: ";
     cin >> opc;
     if (opc < 0 || opc > 3)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > 3);
	return opc;
}

void ordenarBurbuja_fecha(tListaCitas& lista, tCita& cita) 
{
	int i = 0;
	bool inter = true;
	tCita temp;
		while ((i < lista.contador - 1) && inter) {
			inter = false;
			for (int j = lista.contador - 1; j > i; j--) {
				if (lista.citas[j].hora.hora < lista.citas[j - 1].hora.hora || lista.citas[j].hora.minutos < lista.citas[j - 1].hora.minutos) {
					temp = lista.citas[j];
					lista.citas[j] = lista.citas[j - 1];
					lista.citas[j - 1] = temp;
					inter = true;
				}
			}
			if (inter) {
				i++;
			}
		}
}

int paciente_medico(const tListaMedicos lista) 
{
   int opc;
   int i;
   cout << "   " << "_____________________________________________________" << endl;
   cout << "  |" << right << setw(54) << " |" << endl;
   cout << "  |" << right << setw(34) << " LISTA DE MEDICOS" << setw(20) <<"|"<< endl;
   cout << "  |" <<"_____________________________________________________|" << endl << endl;
   for (i = 0; i < lista.contador; i++) 
   {
     cout << "   " << i+1<<": ";
     cout << "   " << left << setw(28) << nombreCompleto(lista.medicos[i]);
     cout << "   " << right << setw(11) << lista.medicos[i].especialidad << endl;
     }
   cout << "   " << "_____________________________________________________" << endl << endl;
   do
   {
     cout << "   ESCOGA EL MEDICO A ASIGNAR: ";
     cin >> opc;
     if (opc < 0 || opc > i)
     {
       cout << endl << "   " << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > i);
	return opc;
}