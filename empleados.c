#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#define TRUE 0
#define FALSE 1

char opciones(char mensaje[])
{
    char opcion;

    printf(mensaje);
    fflush(stdin);
    scanf("%c",&opcion);
    system("cls");

    return opcion;
}

void initEmployees(eEmployee list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty=TRUE;

    }
}

int crearEmpleado(eEmployee list[], int len)
{
    int i, flag;
    i=buscarLibre(list, len);
    if(i!=-1)
    {
        list[i].id=i+1;

        ingresoPalabra(list[i].name, "Ingrese nombre: ");
        ingresoPalabra(list[i].lastName, "Ingrese apelldio: ");
        list[i].sector=ingresoNumero("Ingrese sector\n1.Gerente\n2.Repositor\n3.Cajero\nSelecion:");
        list[i].salary=ingresoNumero("Ingrese sueldo: ");

        list[i].isEmpty=FALSE;

        system("cls");

        flag=i+1;

    }

    return flag;
}

int buscarLibre(eEmployee list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            break;

        }

    }
    return i;
}

void modificarEmpleado(eEmployee list[], int len, int flag)
{
    int id, indice;
    char opcion;

    if(flag!=0)
    {
        id=ingresoNumero("Ingrese id: ");

        indice=findEmployeeById(list, len, id);

        if(indice!=-1)
        {
            opcion=opciones("Que desea cambiar?\n\n\n1.nombre\n2.Apelldio\n3.Salario\n4.Sector\nSeleccion:");
            opcionesCambio(list, indice, opcion);

        }else
        {
            printf("No se encontro ID\n");

        }
    }
    else
    {
        printf("No hay datos ingresados\n");

    }
    system("pause");
}

int findEmployeeById(eEmployee list[], int len, int id)
{
    int indice, i;

    indice=-1;

    for(i=0;i<len;i++)
    {
        if(id==list[i].id)
        {
            indice=i;
            break;

        }
    }

    return indice;
}


void opcionesCambio(eEmployee list[], int indice, char opcion)
{
    switch(opcion)
        {
            case'1':
                ingresoPalabra(list[indice].name, "Ingrese nuevo nombre: ");

            break;
            case'2':
                ingresoPalabra(list[indice].lastName, "Ingrese nuevo apellido: ");

            break;
            case'3':
                list[indice].salary=ingresoNumero("Ingrese nuevo sueldo: ");

            break;
            case'4':
               list[indice].sector=ingresoNumero("Ingrese nuevo sector\n1.Gerente\n2.Repositor\n3.Cajero\nSelecion:");

            break;
            default:
                printf("Opcion Invalida...\n");
                system("pause");

            break;
        }

}

void ingresoPalabra(char buffer[],char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(buffer);

}

float ingresoNumero(char mensaje[])
{
    float bufferN;
    printf(mensaje);
    scanf("%f",&bufferN);

    return bufferN;
}

int bajaEmpleado(eEmployee list[], int len, int flag)
{
    int id;

    if(flag!=0)
    {
        id=ingresoNumero("Ingrese id: ");
        removeEmployee(list, len, id);

    }else
    {
        printf("No hay datos ingresados\n");

    }

    return flag;
}

void removeEmployee(eEmployee list[], int len, int id)
{
    int indice;
    char respuesta;

    indice=findEmployeeById(list, len, id);

    if(indice!=0)
    {
        printf("esta seguro de eliminar a %s %s de la lista?(s/n)", list[indice].name, list[indice].lastName);
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta=='s')
        {
            list[indice].isEmpty=TRUE;

        }

    }else
    {
        printf("No se encontro ID\n");

    }

}
void mostrarEmpleados(eEmployee listEmpleados[], eSectores listSectores[], int len, int lenS, int flag)
{
    int totalEmpleados;

    totalEmpleados=0;

    if(flag!=-1)
    {
    ordenaVector(listEmpleados, len);
    cargarDatos(listEmpleados, listSectores, len);
    totalEmpleados=calcularSueldoSectores(listEmpleados, listSectores, len, lenS);
    cargarDatosSueldos(listEmpleados, listSectores, len, lenS, totalEmpleados);
    system("pause");

    }else
    {
        printf("No se encontro ID\n");

    }

}

void ordenaVector(eEmployee list[] , int len)
{
    int i ,j, comp;
    eEmployee aux;


    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            comp=stricmp(list[i].lastName,list[j].lastName);

            if(comp==1&&list[i].sector==list[j].sector)
            {
                strcpy(aux.name,list[i].name);
                strcpy(list[i].name,list[j].name);
                strcpy(list[j].name,aux.name);

                strcpy(aux.lastName,list[i].lastName);
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[j].lastName,aux.lastName);

                aux.id=list[i].id;
                list[i].id=list[j].id;
                list[j].id=aux.id;

                aux.sector=list[i].sector;
                list[i].sector=list[j].sector;
                list[j].sector=aux.sector;

                aux.salary=list[i].salary;
                list[i].salary=list[j].salary;
                list[j].salary=aux.salary;

            }
        }
    }

}

int calcularSueldoSectores(eEmployee listEmpleados[], eSectores listSectores[], int len, int lenS)
{
    int i, j, contador;

    contador=0;
    for(i=0;i<lenS;i++)
    {
        listSectores[i].totalSalarySector=0;

    }

    for(j=0;j<lenS;j++)
    {

        for(i=0;i<len;i++)
        {
            if(listEmpleados[i].sector==listSectores[j].idSector&&listEmpleados[i].isEmpty==FALSE)
            {
                listSectores[j].totalSalarySector=listEmpleados[i].salary+listSectores[j].totalSalarySector;
                contador++;
            }
        }
    }

    return contador;
}

void cargarDatosSueldos(eEmployee listEmpleados[],eSectores listSectores[], int len, int lenS, int contador)
{
    int i, superarPromedio;
    float sueldototal, sueldoPromedio;

    sueldoPromedio=0;
    superarPromedio=0;
    sueldototal=0;

    for(i=0; i<lenS; i++)
    {
        sueldototal=listSectores[i].totalSalarySector+sueldototal;

    }

    sueldoPromedio=sueldototal/contador;

    for(i=0;i<len;i++)
    {
        if(listEmpleados[i].salary>sueldoPromedio&&listEmpleados[i].isEmpty==FALSE)
        {
            superarPromedio++;

        }
    }

    printf("\nSueldo total: %f\n",sueldototal);
    printf("Sueldo promedio: %f\n",sueldoPromedio);
    printf("Cantidad de empleados que superan el promedio son: %d\n", superarPromedio);
    printf("\nSueldo total por sector: \n");

    for(i=0; i<lenS; i++)
    {
        printf("%s: %f\n",listSectores[i].descripcion ,listSectores[i].totalSalarySector);

    }


}

void cargarDatos(eEmployee list[], eSectores listSectores[], int len)
{
    int i;

    printf("ID |Nombre  |Apellido  |Sector |Sueldo\n");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            desplegarDatos(list[i], listSectores);

        }
    }


}

void desplegarDatos(eEmployee list, eSectores listSectores[])
{
    int i;
    char descripcion[20];

    for(i=0;i<3;i++)
    {
        if(list.sector==listSectores[i].idSector)
        {
            strcpy(descripcion,listSectores[i].descripcion);
            break;

        }
    }

    printf("%2d |%5s |%5s |%5s |%.2f\n", list.id, list.name, list.lastName, descripcion, list.salary);

}
