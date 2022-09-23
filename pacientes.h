#ifndef pacientes_h
#define pacientes_h

#include <string>
using namespace std;


//Struct Pacientes

typedef struct{
  string nombre;
  string apellidos;
  int edad;
  string cedula;
  tFecha nacimiento;
  int telefono;
  string genero;
  string direccion;
  string email;
}tPaciente;

typedef struct {
  tPaciente pacientes[MAX];
  int contador;
} tListaPacientes;

//Prototipos Pacientes
void pacientes(tListaPacientes& lista, tPaciente& paciente);
int menu_pacientes();
void cargar_pacientes(tListaPacientes& lista, bool& ok);
void guardar_pacientes(const tListaPacientes lista);
void leerpaciente(tPaciente& paciente);
void insertarpaciente(tListaPacientes& lista, tPaciente paciente, bool& ok);
void eliminarpaciente(tListaPacientes& lista, int pos, bool& ok);
string nombreCompleto(tPaciente paciente);
void listado_pacientes(const tListaPacientes lista);
void modificar_paciente(tListaPacientes& lista, int pos, bool& encontrado);
int dato_paciente(tListaPacientes& lista,int pos);
void pedirFecha_paciente(tPaciente& paciente);
void ordenarBurbuja_pacientes(tListaPacientes& lista, tPaciente& paciente);

#endif