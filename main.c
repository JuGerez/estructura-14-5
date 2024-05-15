#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"

#define DIM 100

void funciones();
void menuFunciones();
void pto1y2();
void ptoX();
void pto3();
void pto4();
void pto5();
void pto6();
void pto7();
void pto8();
int cargaAlumnos (stAlumno a[], int v, int dim);
void muestraAlumnos (stAlumno a[], int v);
stAlumno buscaMenorLegajo (stAlumno a[], int v, int pos);
stAlumno buscaMenorApellido (stAlumno a[], int v);
stAlumno buscaPorLegajo (stAlumno a[], int v, int legajo);
int ingresarLegajo();
void ordenarPorSeleccion (stAlumno a[], int v, int dim);

int main()
{
   funciones();
   return 0;
}
void funciones()
{
    char opcion;

    do
    {
        system("cls");
        menuFunciones();


        printf("\n\n\n");
        opcion = getch();
        printf("ESC para salir o cualquier tecla para continuar.\n");
        system("cls");


        switch(opcion)
        {
            case '1':
                pto1y2();
                break;
            case '2':
                ptoX();
            case '3':
                pto3();
                break;
            case '4':
                pto4();
                break;
            case '5':
                pto5();
                break;
            case '6':
                pto6();
                break;
            case '7':
                pto7();
                break;
            case '8':
                pto8();
                break;
        }
        system("pause");
    }
    while(opcion!=27);
}
void menuFunciones()
{
    printf("Ingrese una opcion:\n\n\n");
    printf("\n 1 - Pto 1 y 2");
    printf("\n 2 - Pto Menor Apellido y Menor Legajo");
    printf("\n 3 - Pto 3");
    printf("\n 4 - Pto 4");
    printf("\n 5 - Pto 5");
    printf("\n 6 - Pto 6");
    printf("\n 7 - Pto 7");
    printf("\n 8 - Pto 8");
}
//Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
//Hacer una función que muestre un arreglo de alumnos por pantalla. Modulariza
void pto1y2()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;

    vAlumnos = cargaAlumnos (alumnos, vAlumnos, DIM);

    printf("\n Alumnos: \n");
    muestraAlumnos(alumnos, vAlumnos);
}
void ptoX()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;
    vAlumnos = cargaAlumnos (alumnos, vAlumnos, DIM);

    stAlumno alumnoMenorApellido;
    stAlumno alumnoMenorLegajo;

    alumnoMenorApellido = buscaMenorApellido(alumnos, vAlumnos);
    if (alumnoMenorApellido.legajo > -1){
            printf("\nEl alumno con menor apellido: \n");
            muestraUnAlumno(alumnoMenorApellido);
    }

    alumnoMenorLegajo = buscaMenorLegajo(alumnos, vAlumnos, 0);
    printf("\nEl alumno con menor legajo: \n");
    muestraUnAlumno(alumnos[alumnoMenorLegajo]);//volver atras y crear la vieja de menor
    }
}
//Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula.
void pto3()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;
    vAlumnos = cargaAlumnos (alumnos, vAlumnos, DIM);

    stAlumno alumnoABuscar;

    getch();
    system("cls");

    int legajo = ingresarLegajo();

    alumnoABuscar = buscaPorLegajo(alumnos, vAlumnos, legajo);
    if (alumnoABuscar.legajo > -1){
            printf("\nEl alumno que corresponde al legajo %d es: \n", legajo);
            muestraUnAlumno(alumnoABuscar);
    }
}
void pto4()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;
    vAlumnos = cargaAlumnos (alumnos, vAlumnos, DIM);

    ordenarPorSeleccion(alumnos, vAlumnos, DIM);
    printf("\nDatos ordenados por legajo: \n");
    muestraAlumnos(alumnos, vAlumnos);

}
void pto5()
{

}
void pto6()
{

}
void pto7()
{

}
void pto8()
{

}
int cargaAlumnos (stAlumno a[], int v, int dim)
{
    char opcion = 0;

    while(opcion != 27 && v < dim){
        a[v] = cargaUnAlumno();
        v++;
        printf("\nESC para salir o cualquier tecla para continuar... \n");
        opcion = getch();
        system("cls");
    }

    return v;
}
void muestraAlumnos (stAlumno a[], int v)
{
    for(int i = 0; i < v; i++){
        muestraUnAlumno(a[i]);
    }
}
int buscaMenorLegajo (stAlumno a[], int v, int pos)
{
    alumnoMenor.legajo = -1;
    int posMenor = pos;
    pos++;

    while (pos < v){
            if(a[pos].legajo < a[posMenor].legajo){
                posMenor = pos;
            }
            pos++;
        }

    return posMenor;
}
stAlumno buscaMenorApellido (stAlumno a[], int v)
{
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;

    int i = 0;
    if(v > 0){
        alumnoMenor = a[i];
        i++;
        while (i < v){
                if(strcmp (a[i].apellido, alumnoMenor.apellido) < 0){
                    alumnoMenor = a[i];
                }
                i++;
        }
    }

    return alumnoMenor;
}
stAlumno buscaPorLegajo (stAlumno a[], int v, int legajo)
{
    stAlumno alumnoABuscar;
    alumnoABuscar.legajo = -1;
    int i = 0;

    while (i < v){
            if(a[i].legajo = legajo){
            alumnoABuscar = a[i];
            }
            i++;
        }

    return alumnoABuscar;
}
int ingresarLegajo ()
{
    int legajo = 0;
    printf("Ingrese el numero de legajo a buscar: \n");
    scanf("%d", &legajo);
    system("cls");

    return legajo;
}
//4.Hacer una funci�n que ordene el arreglo de alumnos por medio del m�todo de selecci�n.
//El criterio de ordenaci�n es el n�mero de matr�cula.
void ordenarPorSeleccion (stAlumno a[], int v, int dim)
{
    int posMenor;
    int i = 0;
    while (i < v -1){
        posMenor = buscaMenorLegajo(a, v, i);
        //hacer funcion de intercambio y ponerla aca
        i++;
    }
}
