typedef struct
{
    int idSector;
    char descripcion[51];
    float totalSalarySector;

}eSectores;


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

void initEmployees(eEmployee[], int);
char opciones(char[]);

int crearEmpleado(eEmployee[], int);
int buscarLibre(eEmployee[], int);

void modificarEmpleado(eEmployee[], int, int);
int findEmployeeById(eEmployee[], int, int);
void opcionesCambio(eEmployee[], int, char);

int bajaEmpleado(eEmployee[], int, int);
void removeEmployee(eEmployee[], int, int);


void ingresoPalabra(char[], char[]);
float ingresoNumero(char[]);

void mostrarEmpleados(eEmployee[], eSectores[], int, int, int);
void ordenaVector(eEmployee[], int);
int calcularSueldoSectores(eEmployee[], eSectores[], int, int);

void cargarDatos(eEmployee[], eSectores[], int);
void desplegarDatos(eEmployee, eSectores[]);
void cargarDatosSueldos(eEmployee[], eSectores[], int, int, int);
