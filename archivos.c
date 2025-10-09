#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_lINEA 100
typedef struct empleado
{
    char CURP[19];
    char nombre[30];
    float salario;
} TEmpleado;
typedef struct empleados
{
    int clave;
    char nombre[30];
    float salario;
} TEmpleados;
typedef struct medicamento
{
    char nombre[50];
    char laboratorio[30];
    float precio;
    bool existe;
} TMedicamento;
typedef struct cuenta
{
    int num_cuenta;
    char nom_cliente[50];
    float saldo;
} TCuenta;

void agregar_alumno(char nombre[], float calificacion, char nombre_archivo[])
{
    FILE *fp = fopen(nombre_archivo, "at");
    if (fp != NULL)
    {
        fprintf(fp, "%s %f\n", nombre, calificacion);
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo %s", nombre_archivo);
    }
}

void imprimir_alumnos(char nombre_archivo[])
{
    FILE *fp;
    char nombre_alumno[30];
    float calificacion;
    fp = fopen(nombre_archivo, "rt");
    if (fp != NULL)
    {
        fscanf(fp, "%[^\n] %f", nombre_alumno, &calificacion);
        while (!feof(fp))
        {
            printf("Nombre alumno: %s, calificacion: %f", nombre_alumno, calificacion);
            fscanf(fp, "%[^\n] %f", nombre_alumno, &calificacion);
        }
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo %s", nombre_archivo);
    }
}

void estadisticas_archivo(char nom_arch_ent[], char nom_arch_sal[])
{
    FILE *f_entrada, *f_salida;
    int num_lineas = 0, num_espacios = 0, num_bytes = 0;
    char caracter;
    f_entrada = fopen(nom_arch_ent, "rt");
    f_salida = fopen(nom_arch_sal, "wt");
    if (f_entrada == NULL || f_salida == NULL)
    {
        printf("No se puede acceder a uno de los archivos");
    }
    else
    {
        caracter = fgetc(f_entrada);
        while (!feof(f_entrada))
        {
            if (caracter == '\n')
            {
                num_lineas++;
            }
            else if (caracter == ' ')
            {
                num_espacios++;
            }
            num_bytes++;
            caracter = fgetc(f_entrada);
        }
        fprintf(f_salida, "Resultados: \n");
        fprintf(f_salida, "El archivo %s contiene: \n", nom_arch_ent);
        fprintf(f_salida, "%d lineas \n", num_lineas);
        fprintf(f_salida, "%d espacios \n", num_espacios);
        fprintf(f_salida, "%d bytes \n", num_bytes);
        fclose(f_entrada);
        fclose(f_salida);
    }
}

void leer_nombres(char nom_arch_ent[], char nom_arch_sal[])
{
    FILE *f_entrada, *f_salida;
    char linea[MAX_lINEA];
    f_entrada = fopen(nom_arch_ent, "rt");
    f_salida = fopen(nom_arch_sal, "wt");
    if (f_entrada == NULL || f_salida == NULL)
    {
        printf("No se puede acceder a uno de los archivos");
    }
    else
    {
        fgets(linea, MAX_lINEA, f_entrada);
        while (!feof(f_entrada))
        {
            fputc(linea[0], f_salida);
            for (int i = 1; i < strlen(linea); i++)
            {
                if (linea[i] == ' ')
                {
                    fputc(linea[i + 1], f_salida);
                }
            }
            fputc('\n', f_salida);
            fgets(linea, MAX_lINEA, f_entrada);
        }
        fclose(f_entrada);
        fclose(f_salida);
    }
}

void escribe_empleado(TEmpleado emp, char nom_arch[])
{
    FILE *fp = fopen(nom_arch, "ab");
    if (fp != NULL)
    {
        fwrite(&emp, sizeof(TEmpleado), 1, fp);
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo");
    }
}

void imprimir_empleados(char nom_arch[])
{
    FILE *fp = fopen(nom_arch, "rb");
    if (fp != NULL)
    {
        TEmpleado emp;
        while (!feof(fp))
        {
            fread(&emp, sizeof(TEmpleado), 1, fp);
            printf("CURP del empleado: %s\n", emp.CURP);
            printf("Nombre del empleado: %s\n", emp.nombre);
            printf("Salario: %f\n", emp.salario);
        }
        fclose(fp);
    }
    else
    {
        printf("Error al leer el archivo %s", nom_arch);
    }
}

void eliminar_medicamento(char nom_med[], char nom_arch[])
{
    FILE *fp;
    if (fp = fopen(nom_arch, "r+b") != NULL)
    {
        TMedicamento med;
        while (!feof(fp))
        {
            fread(&med, sizeof(TMedicamento), 1, fp);
            if (strcmp(med.nombre, nom_med) == 0)
            {
                med.existe = false;
                fseek(fp, -sizeof(TMedicamento), SEEK_CUR);
                fwrite(&med, sizeof(TMedicamento), 1, fp);
                break;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo");
    }
}

void imprimir_al_reves(char nom_arch[])
{
    FILE *fp = fopen(nom_arch, "rb");
    if (fp != NULL)
    {
        int n;
        TEmpleados emp;
        fseek(fp, 0, SEEK_END);
        n = ftell(fp) / sizeof(TEmpleados);
        for (int i = n - 1; i >= 0; --i)
        {
            fseek(fp, i * sizeof(TEmpleados), SEEK_SET);
            fread(&emp, sizeof(TEmpleados), 1, fp);
            imprimir_empleado(emp);
        }
        fclose(fp);
    }
}

void imprimir_empleado(TEmpleados emp)
{
    printf("Clave del empleado: %d\n", emp.clave);
    printf("Nombre del empleado: %s\n", emp.nombre);
    printf("Salario: %f\n", emp.salario);
    printf("\n");
}

void burbuja(int arreglo[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - 1; j++)
            if (arreglo[j] > arreglo[j + 1])
            {
                int aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
    }
}

void burbuja_en_un_archivo(char nom_arch[])
{
    FILE *fp = fopen(nom_arch, "r+b");
    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_END);
        int n = ftell(fp) / sizeof(TEmpleados);
        TEmpleados e1, e2;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                fseek(fp, j * sizeof(TEmpleados), SEEK_SET);
                fread(&e1, sizeof(TEmpleados), 1, fp);
                fseek(fp, (j + 1) * sizeof(TEmpleados), SEEK_SET);
                fread(&e2, sizeof(TEmpleados), 1, fp);
                if (e1.clave > e2.clave)
                {
                    fseek(fp, (j + 1) * sizeof(TEmpleados), SEEK_SET);
                    fwrite(&e1, sizeof(TEmpleados), 1, fp);
                    fseek(fp, j * sizeof(TEmpleados), SEEK_SET);
                    fwrite(&e2, sizeof(TEmpleados), 1, fp);
                }
            }
        }
    }
}

void abrir_cuenta(char nom_arch[], TCuenta nueva)
{
    FILE *fp = fopen(nom_arch, "a+b");
    if (fp != NULL)
    {
        bool existe_cuenta = false;
        TCuenta actual;
        while (!feof(fp))
        {
            fread(&actual, sizeof(TCuenta), 1, fp);
            if (actual.num_cuenta == nueva.num_cuenta)
            {
                existe_cuenta = true;
                break;
            }
        }
        fseek(fp, 0, SEEK_END);
        if (!existe_cuenta)
        {
            fwrite(&nueva, sizeof(TCuenta), 1, fp);
        }
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo %s", nom_arch);
    }
}

void cerrar_cuenta(char nom_arch[], int num_cuenta)
{
    FILE *fp = fopen(nom_arch, "rb");
    FILE *fp_aux = fopen("aux.bin", "wb");
    if (fp != NULL)
    {
        if (fp_aux != NULL)
        {
            TCuenta actual;
            while (!feof(fp))
            {
                fread(&actual, sizeof(TCuenta), 1, fp);
                if (actual.num_cuenta != num_cuenta)
                {
                    fwrite(&actual, sizeof(TCuenta), 1, fp_aux);
                }
            }
            fclose(fp);
            fclose(fp_aux);
            remove(nom_arch);
            rename("aux.bin", nom_arch);
        }
        else
        {
            printf("Error al abrir el archivo %s", "aux.bin");
        }
    }
    else
    {
        printf("Error al abrir el archivo %s", nom_arch);
    }
}

int buscar_posicion(char nom_arch[], int num_cuenta)
{
    int pos = -1;
    bool existe = false;
    FILE *fp= fopen(nom_arch,"rb");
    if(fp!=NULL) {
        TCuenta actual;
        fread(&actual, sizeof(TCuenta),1,fp);
        while(!feof(fp) && !existe) {
            if(actual.num_cuenta==num_cuenta) {
                pos = ftell(fp) - sizeof(TCuenta);
                existe = true;
            }
            fread(&actual, sizeof(TCuenta),1,fp);
        }
        fclose(fp);
    } else {
        printf("Error al abrir el archivo: %s", nom_arch);
    }
    return pos;
}