#ifndef citas_h
#define citas_h

//Struct Citas

typedef struct {
  string paciente;
  string centromedico;
  tFecha fecha;
  tTime hora;
  string sintomas;
  string enfermedad;
  string tratamiento;
  string doctor;
  string descripcion;
  string estado;
  string pago;
  double costo;
} tCita;

typedef struct {
  tCita citas[MAX];
  int contador;
} tListaCitas;

//Prototipos  Citas
void citas(tListaCitas& lista, tCita& cita, tListaPacientes& lista_uno, tListaMedicos& lista_dos);
int menu_cita();
void cargar_cita(tListaCitas& lista, bool& ok);
void guardar_cita(const tListaCitas lista);
void leercita(tCita& cita, tListaPacientes& lista, tListaMedicos& lista_dos);
void insertarcita(tListaCitas& lista, tCita cita, bool& ok);
void eliminarcita(tListaCitas& lista, int pos, bool& ok);
string nombreCompleto(tCita cita);
void listado_cita(const tListaCitas lista);
void modificar_cita(tListaCitas& lista, int pos, bool& encontrado,tListaMedicos& lista_dos);
int dato_cita(tListaCitas& lista,int pos);
void pedirFecha_cita(tCita& cita);
void leerhora(tCita& cita);
void ordenarBurbuja_citas(tListaCitas& lista, tCita& cita);
int paciente_medico(const tListaMedicos lista);
void buscar_fecha(const tListaCitas &lista, int dia,int mes, int year);
void buscar_especialidad(const tListaCitas &lista, tListaMedicos lista_dos, string dato);
int paciente_cita(const tListaPacientes lista);
int cita_opcion();
void descripcion_cita(const tListaCitas lista, int i);
void fecha_cita(const tListaCitas lista, int i);
void ordenarBurbuja_fecha(tListaCitas& lista, tCita& cita);

#endif