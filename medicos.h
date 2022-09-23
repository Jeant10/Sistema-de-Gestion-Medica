#ifndef medicos_h
#define medicos_h

//Struct Medicos

typedef struct{
  string nombre;
  string apellidos;
  int edad;
  string cedula;
  tFecha nacimiento;
  int telefono;
  string genero;
  string especialidad;
  string direccion;
  string email;
}tMedico;

typedef struct {
  tMedico medicos[MAX];
  int contador;
} tListaMedicos;

//Prototipos Medicos
void medicos(	tListaMedicos& lista, tMedico& medico);
int menu_medico();
void cargar_medico(tListaMedicos& lista, bool& ok);
void guardar_medico(const tListaMedicos lista);
void leermedico(tMedico& medico);
void insertarmedico(tListaMedicos& lista, tMedico medico, bool& ok);
void eliminarmedico(tListaMedicos& lista, int pos, bool& ok);
string nombreCompleto(tMedico medico);
void listado_medico(const tListaMedicos lista);
void modificar_medico(tListaMedicos& lista, int pos, bool &encontrado);
int dato_medico(tListaMedicos& lista,int pos);
void pedirFecha_medico(tMedico& medico);
void ordenarBurbuja_medicos(tListaMedicos& lista, tMedico& medico);

#endif