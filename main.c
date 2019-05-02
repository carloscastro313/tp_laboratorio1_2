#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#define T 1000
#define S 3

int main()
{
    eEmployee arrayEmpleados[T];
    eSectores arraySectores[S] = {{1,"Gerente"},{2,"Repositor"},{3,"Cajero"}};;
    int flag=0;
    char opcion;

    initEmployees(arrayEmpleados, T);

    do{

        opcion=opciones("1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\nSeleccion:");


        switch(opcion)
        {
            case'1':
                flag=crearEmpleado(arrayEmpleados, T);

            break;
            case'2':
                modificarEmpleado(arrayEmpleados, T, flag);

            break;
            case'3':
                flag=bajaEmpleado(arrayEmpleados, T, flag);

            break;
            case'4':
                mostrarEmpleados(arrayEmpleados, arraySectores, T, S, flag);

            break;
            case'5':
                printf("Que tenga un buen dia...\n");
                system("pause");

            break;
            default:
                printf("Opcion Invalida...\n");
                system("pause");

            break;
        }

        system("cls");

    }while(opcion!='5');

    return 0;
}



