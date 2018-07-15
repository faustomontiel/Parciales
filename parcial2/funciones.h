struct
{
    int id;
    char nombre[51];
    char direccion[51];
    int hora;
    int sueldo;

}typedef eEmpleado;

eEmpleado* nuevoEmpleado();
int parser(FILE* pFile, ArrayList* pArrayListEmpleado);
void mostrarEmpleado(eEmpleado* lEmp);
int compareeEmpleado(void* pEmployeeA,void* pEmployeeB);
void printeEmpleado(eEmpleado* p);
int calcularSueldo(void* empleado);
int empleado120horas(void* this);
int empleado_getHorasTrabajadas(eEmpleado* this, int* horasTrabajadas);
int calcularHoras(void* empleado);
