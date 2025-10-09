#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nombre[100];
  long ptr_ent; //sig. entidad
  long ptr_atrib; //sig. atributo
  long direccion;
}TEntidad;

typedef struct {
  char nombre[100];
  int tipo; //1. int 2. float 3. char 4. string
  int tam;
  int clave; //1. Primaria 2. Externa 3. No clave
  long ptr_ent; //sig. entidad
  long ptr_atrib; //sig. atributo
  long direccion;
}TAtributo;

typedef struct nodA {
  TAtributo info;
  struct nodA *sig;
} TNodoA;

typedef struct nodE {
  TEntidad info;
  struct nodE *sigE;
  struct nodA *aba;
} TNodoE;

typedef struct {
  void *bloque;
  int tam;
} TBloque;

void menu_principal();
void menu_entidades_atributos(char *nom_arch);
void menu_datos_registros(TNodoE *cab);
void crear_diccionario(char **nom_arch);
int abrir_diccionario(char *nom_arch);

//capturas
void captura_entidad(TEntidad *e);
void captura_atributo(TAtributo *a);
//Auxiliares
void captura_tipo(int *tipo, int *tam);
void captura_clave(int *clave);

//impresion
void imprime_diccionario(char *nom_arch);
void imprime_entidad(TEntidad e);
void imprime_atributo(TAtributo a);

//altas
void altaEntidad(char nom_arch[], TEntidad en);
void altaAtributo(char nom_arch[], char nom_ent[], TAtributo at);
void alta_bloque(TBloque bn, TNodoE *e);
//bajas
TEntidad bajaEntidad(char nom_arch[], char nom_ent[]);
TAtributo bajaAtributo(char nom_arch[], char nom_ent[], char nom_atr[]);
TBloque bajaBloque(TBloque b, TNodoE *e);
//modificaciones
void modificaEntidad(char nom_arch[], char nom_ent[]);
void modificaAtributo(char nom_arch[], char nom_ent[], char nom_atr[]);
//consultas
void consultaEntidad(char nom_arch[], char nom_ent[]);
void consultaAtributo(char nom_arch[], char nom_ent[], char nom_atr[]);
//Funciones de carga para la lista de listas
TNodoE *crea_nodoE(TEntidad e);
TNodoA *crea_nodoA(TAtributo a);
void inserta_finalE(TNodoE **cab, TEntidad e);
void inserta_finalA(TNodoE **cab, TAtributo a, TEntidad e);
void carga_diccionario(char nom_arch[], TNodoE **cab);
void imprime_diccionario_LL(TNodoE *cab);
void limpia_diccionarioE(TNodoE **cab);
void limpia_diccionarioA(TNodoA **cab);

//Funciones de bloques.
TNodoE *busca_entidad(char nom_ent[], TNodoE *cab);
TBloque crea_bloque(TNodoE *cab);
void captura_bloque(TNodoE *cab, TBloque *b);
void captura_bloqueE(TNodoE *cab, TBloque *b);
void imprime_bloque(TNodoE *cab, TBloque b);
int compara_bloque(TNodoE *cab, TBloque b1, TBloque b2);

//Prueba
void imprime_tabla(TNodoE *e);


//Codigo principal.
int main() {
  menu_principal();
}

//Funciones de menus.
void menu_principal() {
  int opc, aux, ban;
  char *nombre;
  while(opc!=3) {
    printf("\n1. Crear diccionario\n");
    printf("2. Abrir diccionario\n");
    printf("3. Salir\n");
    scanf("%d", &opc);
    switch(opc) {
      case 1:
        crear_diccionario(&nombre);
        menu_entidades_atributos(nombre);
        break;
      case 2:
        strcpy(nombre, "\0");
        ban = abrir_diccionario(nombre);
        if(ban==1) {
          menu_entidades_atributos(nombre);
        }
        break;
      case 3:
        printf("\nSaliendo...\n");
        return;
      default:
        printf("\nOpcion invalida\n");
        break;
    }
  }
}

void menu_entidades_atributos(char *nom_arch) {
  int opc = 0;
  TEntidad ent;
  TNodoE *cab = NULL;
  TAtributo atrib;
  char ent_aux[100];
  char a_aux[100];
  while(opc!=11) {
    printf("\n1. Alta de Entidades\n");
    printf("2. Baja de Entidades\n");
    printf("3. Modificacion de Entidades\n");
    printf("4. Consulta de Entidades\n");
    printf("5. Alta de Atributos\n");
    printf("6. Baja de Atributos\n");
    printf("7. Modificacion de Atributos\n");
    printf("8. Consulta de Atributos\n");
    printf("9. Impresion de diccionario\n");
    printf("10. Datos\n");
    printf("11. Salir\n");
    scanf("%d", &opc);
    printf("\n");
    switch(opc) {
      case 1:
        captura_entidad(&ent);
        altaEntidad(nom_arch, ent);
        break;
      case 2:
        printf("Nombre de la entidad: \n");
        scanf("%s", ent_aux);
        ent = bajaEntidad(nom_arch, ent_aux);
        break;
      case 3:
        printf("Nombre de entidad a modificar: \n");
        scanf("%s", ent_aux);
        modificaEntidad(nom_arch, ent_aux);
        break;
      case 4:
        printf("Nombre de la entidad: \n");
        scanf("%s", ent_aux);
        consultaEntidad(nom_arch, ent_aux);
        break;
      case 5:
        printf("Nombre de la entidad: \n");
        scanf("%s", ent_aux);
        captura_atributo(&atrib);
        altaAtributo(nom_arch, ent_aux, atrib);
        break;
      case 6:
        printf("Nombre de la entidad: \n");
        scanf("%s", ent_aux);
        printf("Nombre del atributo: \n");
        scanf("%s", a_aux);
        atrib = bajaAtributo(nom_arch, ent_aux, a_aux);
        break;
      case 7:
        printf("Nombre de la entidad: \n");
        scanf("%s", ent_aux);
        printf("Nombre del atributo: \n");
        scanf("%s", a_aux);
        modificaAtributo(nom_arch, ent_aux, a_aux);
        break;
      case 8:
        printf("Nombre de la entidad: \n");
        scanf("%s", ent_aux);
        printf("Nombre del atributo: \n");
        scanf("%s", a_aux);
        consultaAtributo(nom_arch, ent_aux, a_aux);  
        break;
      case 9:
        imprime_diccionario(nom_arch);
        break;
      case 10:
        limpia_diccionarioE(&cab);
        carga_diccionario(nom_arch, &cab);
        //imprime_diccionario_LL(cab);
        if(cab!=NULL) {
          menu_datos_registros(cab);
        }
        break;
      case 11:
        printf("Saliendo...\n");
        break;
      default:
        printf("Opcion invalida\n");
        break;
    }
  }
}

void menu_datos_registros(TNodoE *cab) {
  char ent_aux[50];
  TNodoE *aux_e;
  TBloque b1, b2 = {NULL, 0};
  int opc = 0;
  imprime_diccionario_LL(cab);
  while(opc!=6) {
    printf("\n1. Alta de registros\n");
    printf("2. Baja de registros\n");
    printf("3. Modificacion de registros\n");
    printf("4. Consulta de registros\n");
    printf("5. Imprime tabla\n");
    printf("6. Salir\n");
    scanf("%d", &opc);
    switch(opc) {
      case 1:
        printf("\nNombre de la entidad: \n");
        scanf(" %[^\n]", ent_aux);
        aux_e = busca_entidad(ent_aux, cab);
        if(aux_e) {
          printf("\nDatos del bloque 1: \n");
          b1 = crea_bloque(aux_e);
          captura_bloque(aux_e, &b1);
          alta_bloque(b1, aux_e);
        }
        break;
      case 2:
        printf("\nNombre de la entidad: \n");
        scanf(" %[^\n]", ent_aux);
        aux_e = busca_entidad(ent_aux, cab);
        if(aux_e) {
          printf("\nDatos del bloque 1: \n");
          b1 = crea_bloque(aux_e);
          captura_bloqueE(aux_e, &b1);
          b2 = bajaBloque(b1, aux_e);
        }
        break;
      case 3:
        //modificacion Registro;
        break;
      case 4:
        //consulta Registro;
        break;
      case 5:
        printf("\nNombre de la entidad: \n");
        scanf(" %[^\n]", ent_aux);
        aux_e = busca_entidad(ent_aux, cab);
        if(aux_e) {
          imprime_tabla(aux_e);
        }
        break;
      case 6:
        printf("\nSaliendo...\n");
        break;
      default:
        printf("\nOpcion invalida\n");
        break;
    }
  }
}

//Funciones de diccionario.
void crear_diccionario(char **nom_arch) {
  FILE *arch;
  char aux[100];
  long cab = -1;
  printf("\nIngrese el nombre del archivo: ");
  scanf("%s", aux);
  strcat(aux, ".dic");
  *nom_arch = aux;
  arch = fopen(aux, "wb+");
  if(arch==NULL) {
    printf("\nError al crear el archivo\n");
    return;
  }
  fwrite(&cab, sizeof(long), 1, arch);
  fclose(arch);
}

int abrir_diccionario(char *nom_arch) {
  FILE *arch;
  int ban = 0;
  printf("Cual es el nombre del archivo: \n");
  scanf("%s", nom_arch);
  strcat(nom_arch, ".dic");
  arch = fopen(nom_arch, "rb");
  if(arch==NULL) {
    printf("\nDiccionario no existente\n");
    return ban;
  }
  printf("Diccionario abierto\n");
  ban = 1;
  fclose(arch);
  return ban;
}

//Funciones de captura.
void captura_entidad(TEntidad *e) {
  printf("-| Captura de datos de la entidad |-\n");
  printf("Captura nombre: \n");
  scanf("%s", e->nombre);
  e->ptr_ent = -1;
  e->ptr_atrib = -1;
  e->direccion = -1;
}

void captura_atributo(TAtributo *a) {
  int aux = 0, naux = 0;
  int auxtipo, auxtam, auxclave;
  printf("-| Captura de datos del atributo |-\n");
  printf("Captura nombre: \n");
  scanf("%s", a->nombre);
  a->tipo = 0;
  printf("Captura tipo: \n");
  captura_tipo(&auxtipo, &auxtam);
  a->tipo = auxtipo;
  a->tam = auxtam;
  printf("Captura clave: \n");
  captura_clave(&auxclave);
  a->clave = auxclave;
  a->ptr_ent = -1;
  a->ptr_atrib = -1;
  a->direccion = -1;
}

void captura_tipo(int *tipo, int *tam) {
  int opc, aux = 0;
  while(opc!=1 && opc!=2 && opc!=3 && opc!=4) {
    printf("\n1. Int\n");
    printf("2. Float\n");
    printf("3. Char\n");
    printf("4. String\n");
    scanf("%d", &opc);
    switch(opc) {
      case 1:
        *tipo = 1;
        *tam = sizeof(int);
        break;
      case 2:
        *tipo = 2;
        *tam = sizeof(float);
        break;
      case 3:
        *tipo = 3;
        *tam = sizeof(char);
        break;
      case 4:
        printf("N° de caracteres: \n");
        scanf("%d", &aux);
        *tipo = 4;
        *tam = aux * sizeof(char);
        break;
      default:
        printf("Opcion invalida\n");
        break;
    }
  }
}

void captura_clave(int *clave) {
  int opc;
  while(opc!=1 && opc!=2 && opc!=3) {
    printf("\n1. Primaria\n");
    printf("2. Externa\n");
    printf("3. No clave\n");
    scanf("%d", &opc);
    switch(opc) {
      case 1:
        *clave = 1;
        break;
      case 2:
        *clave = 2;
        break;
      case 3:
        *clave = 3;
        break;
      default:
        printf("Opcion invalida\n");
        break;
    }
  }
}

//Funciones de impresion.
void imprime_diccionario(char *nom_arch) {
  FILE *arch;
  long pos;
  TEntidad e_act;
  TAtributo a_act;
  arch = fopen(nom_arch, "rb");
  if(arch) {
    fread(&pos, sizeof(long), 1, arch);
    while(pos!=-1) {
      fseek(arch, pos, SEEK_SET);
      fread(&e_act, sizeof(TEntidad), 1, arch);
      imprime_entidad(e_act);
      pos = e_act.ptr_atrib;
      while(pos!=-1) {
        fseek(arch, pos, SEEK_SET);
        fread(&a_act, sizeof(TAtributo), 1, arch);
        imprime_atributo(a_act);
        pos = a_act.ptr_atrib;
      }
      pos = e_act.ptr_ent;
    }
    fclose(arch);
  }
}

void imprime_entidad(TEntidad e) {
  printf("\nDatos de la entidad: \n");
  printf("Nombre: %s\n", e.nombre);
  printf("Ptr_ent: %ld\n", e.ptr_ent);
  printf("Ptr_atrib: %ld\n", e.ptr_atrib);
  printf("Direccion: %ld\n", e.direccion);
}

void imprime_atributo(TAtributo a) {
  printf("\nDatos del atributo: \n");
  printf("Nombre: %s\n", a.nombre);
  printf("Tipo: %d\n", a.tipo);
  printf("Tam: %d\n", a.tam);
  printf("Clave: %d\n", a.clave);
  printf("Ptr_ent: %ld\n", a.ptr_ent);
  printf("Ptr_atrib: %ld\n", a.ptr_atrib);
  printf("Direccion: %ld\n", a.direccion);
}

void imprime_diccionario_LL(TNodoE *cab) {
  TNodoE *aux;
  TNodoA *auxA;
  printf("Diccionario: \n");
  for(aux = cab; aux != NULL; aux = aux->sigE) {
    printf("%s\n", aux->info.nombre);
    for(auxA = aux->aba; auxA != NULL; auxA = auxA->sig) {
      printf("\t%s\n", auxA->info.nombre);
    }
  }
  if(cab == NULL) {
    printf("Diccionario vacio\n");
  }
}

//Funciones de entidades.
void altaEntidad(char nom_arch[], TEntidad en) {
  FILE *arch;
  long cab, pos;
  TEntidad e_act, e_ant;
  arch = fopen(nom_arch, "rb+");
  if(arch) {
    fread(&cab, sizeof(long), 1, arch);
    fseek(arch, 0, SEEK_END); //Movimiento al final del archivo
    en.direccion = ftell(arch);
    if(cab==-1) {
      fseek(arch, 0, SEEK_SET); //Movimiento al inicio del archivo
      cab = en.direccion;
      fwrite(&cab, sizeof(long), 1, arch);
    } else {
      fseek(arch, cab, SEEK_SET); //Movimiento a la 1ra. entidad
      fread(&e_act, sizeof(TEntidad), 1, arch);
      if(strcmp(en.nombre, e_act.nombre)<0) {
        en.ptr_ent = cab;
        fseek(arch, 0, SEEK_SET);
        cab=en.direccion;
        fwrite(&cab, sizeof(long), 1, arch);
      } else {
        while(e_act.ptr_ent!=-1 && strcmp(en.nombre, e_act.nombre)>0) {
          e_ant = e_act;
          fseek(arch, e_ant.ptr_ent, SEEK_SET);
          fread(&e_act, sizeof(TEntidad), 1, arch);
        }
        if(strcmp(en.nombre, e_act.nombre)<0) {
          e_ant.ptr_ent = en.direccion;
          en.ptr_ent = e_act.direccion;
          fseek(arch, e_ant.direccion, SEEK_SET);
          fwrite(&e_ant, sizeof(TEntidad), 1, arch);
        } else {
          e_act.ptr_ent = en.direccion;
          fseek(arch, e_act.direccion, SEEK_SET);
          fwrite(&e_act, sizeof(TEntidad), 1, arch);
        }
      }
    }
    fseek(arch,en.direccion,SEEK_SET);
    fwrite(&en, sizeof(TEntidad), 1, arch);
    fclose(arch);
  }
}

TEntidad bajaEntidad(char nom_arch[], char nom_ent[]) {
  FILE *arch;
  long cab;
  TEntidad e_act, e_ant, rest;
  arch = fopen(nom_arch, "rb+");
  if (arch) {
    fread(&cab, sizeof(long), 1, arch);
    if (cab != -1) {
      fseek(arch, cab, SEEK_SET);
      fread(&e_act, sizeof(TEntidad), 1, arch);
      if (strcmp(nom_ent, e_act.nombre) == 0) {
        rest = e_act;
        cab = e_act.ptr_ent;
        fseek(arch, 0, SEEK_SET);
        fwrite(&cab, sizeof(long), 1, arch);
      } else {
        while (e_act.ptr_ent != -1 && strcmp(nom_ent, e_act.nombre) != 0) {
          e_ant = e_act;
          fseek(arch, e_ant.ptr_ent, SEEK_SET);
          fread(&e_act, sizeof(TEntidad), 1, arch);
        }
        if (strcmp(nom_ent, e_act.nombre) == 0) {
          rest = e_act;
          e_ant.ptr_ent = e_act.ptr_ent;
          fseek(arch, e_ant.direccion, SEEK_SET);
          fwrite(&e_ant, sizeof(TEntidad), 1, arch);
        }
        if(e_act.ptr_ent==-1 && strcmp(nom_ent, e_act.nombre)!=0) {
          printf("\nLa entidad no existe\n");
        }
      }
    } else {
      printf("\nEl diccionario esta vacio\n");
    }
    fclose(arch);
  }
  return rest;
}

void modificaEntidad(char nom_arch[], char nom_ent[]) {
  TEntidad e_aux, e_mod;
  e_aux = bajaEntidad(nom_arch, nom_ent);
  printf("Ingrese los nuevos datos de la entidad: \n");
  captura_entidad(&e_mod);
  e_mod.ptr_atrib = e_aux.ptr_atrib;
  altaEntidad(nom_arch, e_mod);
}

void consultaEntidad(char nom_arch[], char nom_ent[]) {
  FILE *arch;
  long cab, pos;
  TEntidad e_act;
  arch = fopen(nom_arch, "rb");
  if (arch) {
    fread(&cab, sizeof(long), 1, arch);
    if (cab != -1) {
      fseek(arch, cab, SEEK_SET);
      fread(&e_act, sizeof(TEntidad), 1, arch);
      while (strcmp(nom_ent, e_act.nombre) != 0 && e_act.ptr_ent != -1) {
        pos = e_act.ptr_ent;
        fseek(arch, pos, SEEK_SET);
        fread(&e_act, sizeof(TEntidad), 1, arch);
      }
      if (strcmp(nom_ent, e_act.nombre) == 0) {
        imprime_entidad(e_act);
      }
      if(e_act.ptr_ent==-1 && strcmp(nom_ent, e_act.nombre)!=0) {
        printf("\nLa entidad no existe\n");
      }
    } else {
      printf("\nEl diccionario esta vacio\n");
    }
  }
}

//Funciones de atributos.
void altaAtributo(char nom_arch[], char nom_ent[], TAtributo at) {
  FILE *arch;
  TEntidad e_act;
  TAtributo atrib;
  long pos;
  int enc = 0;
  arch = fopen(nom_arch, "rb+");
  if(arch) {
    fread(&pos, sizeof(long), 1, arch);
    if(pos!=-1) {
      while(pos!=-1 && !enc) {
        fseek(arch, pos, SEEK_SET);
        fread(&e_act, sizeof(TEntidad), 1, arch);
        if(strcmp(nom_ent, e_act.nombre)==0) {
          enc = 1;
        }
        pos = e_act.ptr_ent;
      }
      if(enc) {
        fseek(arch, 0, SEEK_END);
        at.direccion = ftell(arch);
        at.ptr_ent = e_act.ptr_ent;
        if(e_act.ptr_atrib==-1) {
          e_act.ptr_atrib = at.direccion;
          fseek(arch, e_act.direccion, SEEK_SET);
          fwrite(&e_act, sizeof(TEntidad), 1, arch);
        } else {
          pos = e_act.ptr_atrib;
          while(pos!=-1) {
            fseek(arch, pos, SEEK_SET);
            fread(&atrib, sizeof(TAtributo), 1, arch);
            pos = atrib.ptr_atrib;
          }
          atrib.ptr_atrib = at.direccion;
          fseek(arch, atrib.direccion, SEEK_SET);
          fwrite(&atrib, sizeof(TAtributo), 1, arch);
        }
        fseek(arch, at.direccion, SEEK_SET);
        fwrite(&at, sizeof(TAtributo), 1, arch);
      } else {
        printf("\n");
        printf("La entidad no existe\n");
      }
    } else {
      printf("\n");
      printf("Diccionario vacio\n");
    }
    fclose(arch);
  } else {
    printf("\n");
    printf("Diccionario no existente\n");
  }
}

TAtributo bajaAtributo(char nom_arch[], char nom_ent[], char nom_atr[]) {
  FILE *arch;
  TEntidad e_act;
  TAtributo atrib, atrib_ant, rest;
  long pos;
  int enc = 0;
  arch = fopen(nom_arch, "rb+");
  if (arch) {
    fread(&pos, sizeof(long), 1, arch);
    if (pos != -1) {
      while (pos != -1 && !enc) {
        fseek(arch, pos, SEEK_SET);
        fread(&e_act, sizeof(TEntidad), 1, arch);
        if (strcmp(nom_ent, e_act.nombre) == 0) {
          enc = 1;
        }
        pos = e_act.ptr_ent;
      }
      if (enc) {
        if (e_act.ptr_atrib != -1) {
          pos = e_act.ptr_atrib;
          fseek(arch, e_act.ptr_atrib, SEEK_SET);
          fread(&atrib, sizeof(TAtributo), 1, arch);
          if (strcmp(nom_atr, atrib.nombre) == 0) {
            rest = atrib;
            e_act.ptr_atrib = atrib.ptr_atrib;
            fseek(arch, e_act.direccion, SEEK_SET);
            fwrite(&e_act, sizeof(TEntidad), 1, arch);
          } else {
            while (atrib.ptr_atrib != -1 && strcmp(nom_atr, atrib.nombre) != 0) {
              atrib_ant = atrib;
              fseek(arch, atrib.ptr_atrib, SEEK_SET);
              fread(&atrib, sizeof(TAtributo), 1, arch);
            }
            if (strcmp(nom_atr, atrib.nombre) == 0) {
              rest = atrib;
              atrib_ant.ptr_atrib = atrib.ptr_atrib;
              fseek(arch, atrib_ant.direccion, SEEK_SET);
              fwrite(&atrib_ant, sizeof(TAtributo), 1, arch);
            } else {
              printf("\nEl atributo no existe\n");
            }
          }
        } else {
          printf("\nLa entidad no tiene atributos\n");
        }
      } else {
        printf("\nLa entidad no existe\n");
      }
    } else {
      printf("\nDiccionario vacio\n");
    }
    fclose(arch);
  } else {
    printf("\nDiccionario no existente\n");
  }
  return rest;
}

void modificaAtributo(char nom_arch[], char nom_ent[], char nom_atr[]) {
  TAtributo atrib_aux, atrib_mod;
  char auxN[100];
  int opc = 0, auxT, naux;
  int auxtipo, auxtam, auxclave;
  atrib_aux = bajaAtributo(nom_arch, nom_ent, nom_atr);
  atrib_mod = atrib_aux;
  printf("¿Que datos va a modificar? \n");
  while (opc != 4) {
    printf("\n1. Nombre\n");
    printf("2. Tipo\n");
    printf("3. Clave\n");
    printf("4. Continuar\n");
    scanf("%d", &opc);
    switch (opc) {
    case 1:
      printf("Ingrese el nuevo nombre: \n");
      scanf("%s", auxN);
      strcpy(atrib_mod.nombre, auxN);
      break;
    case 2:
      printf("Captura tipo: \n");
      captura_tipo(&auxtipo, &auxtam);
      atrib_mod.tipo = auxtipo;
      atrib_mod.tam = auxtam;
      break;
    case 3:
      printf("Captura clave: \n");
      captura_clave(&auxclave);
      atrib_mod.clave = auxclave;
      break;
    case 4:
      printf("Continuando...\n");
      break;
    default:
      printf("Opcion invalida\n");
      break;
    }
  }
  atrib_mod.ptr_atrib = -1;
  atrib_mod.direccion = -1;
  altaAtributo(nom_arch, nom_ent, atrib_mod);
}

void consultaAtributo(char nom_arch[], char nom_ent[], char nom_atr[]) {
  FILE *arch;
  TEntidad e_act;
  TAtributo atrib;
  long pos;
  int encE = 0;
  int encA = 0;
  arch = fopen(nom_arch, "rb");
  if (arch) {
    fseek(arch, 0, SEEK_SET);
    fread(&pos, sizeof(long), 1, arch);
    if (pos != -1) {
      while (pos != -1 && !encE) {
        fseek(arch, pos, SEEK_SET);
        fread(&e_act, sizeof(TEntidad), 1, arch);
        if (strcmp(nom_ent, e_act.nombre) == 0) {
          encE = 1;
        } else {
          pos = e_act.ptr_ent;
        }
      }
      if (encE) {
        if (e_act.ptr_atrib != -1) {
          pos = e_act.ptr_atrib;
          fseek(arch, e_act.ptr_atrib, SEEK_SET);
          fread(&atrib, sizeof(TAtributo), 1, arch);
          while (pos != -1 && !encA) {
            if(strcmp(nom_atr, atrib.nombre) == 0) {
              encA = 1;
            } else {
              pos = atrib.ptr_atrib;
              if(pos != -1) {
                fseek(arch, pos, SEEK_SET);
                fread(&atrib, sizeof(TAtributo), 1, arch);
              }
            }
          }
          if (encA) {
            imprime_atributo(atrib);
          } else {
            printf("\nEl atributo no existe\n");
          }
        } else {
          printf("\nLa entidad no tiene atributos\n");
        }
      } else {
        printf("\nLa entidad no existe\n");
      }
    } else {
      printf("\nDiccionario vacio\n");
    }
    fclose(arch);
  } else {
    printf("\nDiccionario no existente\n");
  }
}

//Funciones de carga de lista de listas
TNodoE *crea_nodoE(TEntidad e) {
  TNodoE *aux;
  aux = (TNodoE *)malloc(sizeof(TNodoE));
  if(aux) {
    aux->info = e;
    aux->sigE = NULL;
    aux->aba = NULL;
  }
  return aux;
}

TNodoA *crea_nodoA(TAtributo a) {
  TNodoA *aux;
  aux = (TNodoA *)malloc(sizeof(TNodoA));
  if(aux) {
    aux->info = a;
    aux->sig = NULL;
  }
  return aux;
}


//Hechos por mi
void inserta_finalE(TNodoE **cab, TEntidad e) {
  TNodoE *corre = *cab;
  if(*cab == NULL) {
    *cab = crea_nodoE(e);
  } else {
    while(corre->sigE != NULL) {
      corre = corre->sigE;
    }
    corre->sigE = crea_nodoE(e);
  }
}

void inserta_finalA(TNodoE **cab, TAtributo a, TEntidad e) {
  TNodoE *corre = *cab;
  TNodoA *auxA;
  while(corre->info.direccion != e.direccion) {
    corre = corre->sigE;
  }
  if(corre->aba == NULL) {
    corre->aba = crea_nodoA(a);
  } else {
    auxA = corre->aba;
    while(auxA->sig != NULL) {
      auxA = auxA->sig;
    }
    auxA->sig = crea_nodoA(a);
  }
}

void carga_diccionario(char nom_arch[], TNodoE **cab) {
  FILE *arch;
  long pos;
  TEntidad e;
  TAtributo a;
  arch = fopen(nom_arch, "rb");
  if(arch) {
    fread(&pos, sizeof(long), 1, arch);
    while(pos!=-1) {
      fseek(arch, pos, SEEK_SET);
      fread(&e, sizeof(TEntidad), 1, arch);
      inserta_finalE(cab, e);
      pos = e.ptr_atrib;
      while(pos!=-1) {
        fseek(arch, pos, SEEK_SET);
        fread(&a, sizeof(TAtributo), 1, arch);
        inserta_finalA(cab, a, e);
        pos = a.ptr_atrib;
      }
      pos = e.ptr_ent;
    }
    fclose(arch);
  }
}

void limpia_diccionarioE(TNodoE **cab) {
  TNodoE *aux = *cab;
  TNodoE *aux2;
  while(aux != NULL) {
    aux2 = aux->sigE;
    limpia_diccionarioA(&aux->aba);
    free(aux);
    aux = aux2;
  }
  *cab = NULL;
}

void limpia_diccionarioA(TNodoA **cab) {
  TNodoA *aux = *cab;
  TNodoA *sig;
  while(aux != NULL) {
    sig = aux->sig;
    free(aux);
    aux = sig;
  }
}
//Hechos por mi


//Hechos en clase
/*
TNodoE *inserta_finalE(TNodoE **cab, TEntidad e) {
  TNodoE *aux;
  if(cab == NULL) {
    aux=*cab = crea_nodoE(e);
  } else {
    aux = inserta_finalE(&(*cab)->sigE, e);
  }
  return aux;
}

void inserta_finalA(TNodoA **cab, TAtributo a) {
  if(cab == NULL) {
    *cab = crea_nodoA(a);
  } else {
    inserta_finalA(&(*cab)->sig, a);
  }
}

TNodoE *carga_dic(char nom_arch[]) {
  FILE *arch;
  long pos;
  TNodoE *cab = NULL, *auxE;
  TEntidad e_act;
  TAtributo a_act;
  arch = fopen(nom_arch, "rb");
  if(arch) {
    fread(&pos, sizeof(long), 1, arch);
    while(pos!=-1) {
      fseek(arch, pos, SEEK_SET);
      fread(&e_act, sizeof(TEntidad), 1, arch);
      imprime_entidad(e_act);
      auxE = inserta_finalE(&cab, e_act);
      pos = e_act.ptr_atrib;
      while(pos!=-1) {
        fseek(arch, pos, SEEK_SET);
        fread(&a_act, sizeof(TAtributo), 1, arch);
        imprime_atributo(a_act);
        inserta_finalA(&auxE->aba, a_act);
        pos = a_act.ptr_atrib;
      }
      pos = e_act.ptr_ent;
    }
    fclose(arch);
  } else {
    printf("\nDiccionario no existente\n");
  }
  return cab;
}
*/
//Hechos en clase


//Funciones de bloques

TNodoE *busca_entidad(char nom_ent[], TNodoE *cab) {
  TNodoE *aux = NULL;
  if(cab) {
    if(strcmp(nom_ent, cab->info.nombre) == 0) {
      aux = cab;
    } else {
      aux = busca_entidad(nom_ent, cab->sigE);
    }
  }
  return aux;
}

TBloque crea_bloque(TNodoE *cab) {
  TBloque b;
  TNodoA *a;
  b.tam = 0;
  for(a = cab->aba;a; a = a->sig) {
    b.tam += a->info.tam;
  }
  b.tam += sizeof(long)*2;
  b.bloque = malloc(b.tam);
  return b;
}

void captura_bloque(TNodoE *cab, TBloque *b) {
  TNodoA *a;
  int desp=0;
  for(a = cab->aba;a; a = a->sig) {
    printf("%s: ", a->info.nombre);
    switch(a->info.tipo) {
      case 1:
        scanf("%d", (int*)(b->bloque+desp));
        break;
      case 2:
        scanf("%f", (float*)(b->bloque+desp));
        break;
      case 3:
        scanf("%c", (char*)(b->bloque+desp));
        break;
      case 4:
        scanf(" %[^\n]", (char*)(b->bloque+desp));
        break;
    }
    desp += a->info.tam;
  }
  *((long*)(b->bloque+desp)) = -1L;
  desp+=(sizeof(long));
  *((long*)(b->bloque+desp)) = -1L;
}

void captura_bloqueE(TNodoE *cab, TBloque *b) {
  TNodoA *a;
  int desp=0;
  for(a = cab->aba;a; a = a->sig) {
    if (a->info.clave == 1) {
      printf("%s: ", a->info.nombre);
      switch (a->info.tipo) {
      case 1:
        scanf("%d", (int *)(b->bloque + desp));
        break;
      case 2:
        scanf("%f", (float *)(b->bloque + desp));
        break;
      case 3:
        scanf("%c", (char *)(b->bloque + desp));
        break;
      case 4:
        scanf(" %[^\n]", (char *)(b->bloque + desp));
        break;
      }
    } else {
      switch (a->info.tipo) {
      case 1:
        *(int *)(b->bloque + desp) = 0;
        break;
      case 2:
        *(float *)(b->bloque + desp) = 0.0;
        break;
      case 3:
        *(char *)(b->bloque + desp) = '\0';
        break;
      case 4:
        strcpy((char *)(b->bloque + desp) ,"\0");
        break;
      }
    }
    desp += a->info.tam;
  }
  *((long*)(b->bloque+desp)) = -1L;
  desp+=(sizeof(long));
  *((long*)(b->bloque+desp)) = -1L;
}

void imprime_bloque(TNodoE *cab, TBloque b) {
  TNodoA *a;
  int desp=0;
  printf("\n");
  for(a = cab->aba;a; a = a->sig) {
    printf("%s: ", a->info.nombre);
    switch(a->info.tipo) {
      case 1:
        printf("%d\n", *(int*)(b.bloque+desp));
        break;
      case 2:
        printf("%f\n", *(float*)(b.bloque+desp));
        break;
      case 3:
        printf("%c\n", *(char*)(b.bloque+desp));
        break;
      case 4:
        printf("%s\n", (char*)(b.bloque+desp));
        break;
    }
    desp += a->info.tam;
  }
  printf("Dir: %ld\n", *((long*)(b.bloque+desp)));
  desp+=sizeof(long);
  printf("Dir Sig: %ld\n", *((long*)(b.bloque+desp)));
}

int compara_bloque(TNodoE *cab, TBloque b1, TBloque b2) {
  TNodoA *a;
  int desp=0, b=0;
  a = cab->aba;
  while(a && a->info.clave != 1) {
    desp += a->info.tam;
    a = a->sig;
  }
  if(a) {
    switch(a->info.tipo) {
      case 1:
        if( *(int*)(b1.bloque+desp) < *(int*)(b2.bloque+desp)) {
          b = -1;
        } else {
          if( *(int*)(b1.bloque+desp) > *(int*)(b2.bloque+desp)) {
            b = 1;
          }
        }
        break;
      case 2:
        if( *(float*)(b1.bloque+desp) < *(float*)(b2.bloque+desp)) {
          b = -1;
        } else {
          if( *(float*)(b1.bloque+desp) > *(float*)(b2.bloque+desp)) {
            b = 1;
          }
        }
        break;
      case 3:
        if( *(char*)(b1.bloque+desp) < *(char*)(b2.bloque+desp)) {
          b = -1;
        } else {
          if( *(char*)(b1.bloque+desp) > *(char*)(b2.bloque+desp)) {
            b = 1;
          }
        }
        break;
      case 4:
        b = strcmp((char*)(b1.bloque+desp), (char*)(b2.bloque+desp));
        break;
    }
  } else {
    b = 2;
  }
  return b;
}

void alta_bloque(TBloque bn, TNodoE *e) {
  long cab = -1L;
  FILE *f;
  char nom_arch[50];
  long dir;
  TBloque b_act = {NULL,0}, b_ant = {NULL,0};
  strcpy(nom_arch, e->info.nombre);
  strcat(nom_arch, ".dat");
  f = fopen(nom_arch,"rb+");
  if(f == NULL) {
    f = fopen(nom_arch, "wb+");
    if(f != NULL) {
      fwrite(&cab, sizeof(long),1,f);
      cab=ftell(f);
      *((long*)(bn.bloque+bn.tam-(sizeof(long)*2)))=cab;
      fseek(f,0,SEEK_SET);
      fwrite(&cab, sizeof(long),1,f);
      fwrite(bn.bloque, bn.tam,1,f);
      fclose(f);
    }
  } else {
    fread(&cab, sizeof(long),1,f);
    if(cab==-1L) {
      fseek(f,0,SEEK_END);
      cab=ftell(f);
      *((long*)(bn.bloque+bn.tam-(sizeof(long)*2)))=cab;
      fseek(f,0,SEEK_SET);
      fwrite(&cab, sizeof(long),1,f);
      fseek(f,cab,SEEK_SET);
      fwrite(bn.bloque, bn.tam,1,f);
    } else {
      fseek(f,cab,SEEK_SET);
      b_act = crea_bloque(e);
      fread(b_act.bloque, b_act.tam,1,f);
      if(compara_bloque(e, bn, b_act) < 0) {
        *((long*)(bn.bloque+bn.tam-(sizeof(long))))=cab;
        fseek(f,0,SEEK_END);
        cab=ftell(f);
        *((long*)(bn.bloque+bn.tam-(sizeof(long)*2)))=cab;
        fseek(f,0,SEEK_SET);
        fwrite(&cab, sizeof(long),1,f);
        fseek(f,cab,SEEK_SET);
        fwrite(bn.bloque, bn.tam,1,f);
      } else {
        fseek(f,0,SEEK_END);
        *((long*)(bn.bloque+bn.tam-(sizeof(long)*2)))=ftell(f);
        while(compara_bloque(e, bn, b_act) > 0 && *((long*)(b_act.bloque+b_act.tam-(sizeof(long)))) != -1L) {
          if(b_ant.bloque != NULL) {
            free(b_ant.bloque);
          }
          b_ant = b_act;
          fseek(f,*((long*)(b_act.bloque+b_act.tam-(sizeof(long)))),SEEK_SET);
          b_act = crea_bloque(e);
          fread(b_act.bloque, b_act.tam,1,f);
        }
        if(compara_bloque(e, bn, b_act) < 0) {
          *((long*)(bn.bloque+bn.tam-(sizeof(long))))=*((long*)(b_act.bloque+b_act.tam-(2*sizeof(long))));
          *((long*)(b_ant.bloque+b_ant.tam-(sizeof(long))))=*((long*)(bn.bloque+bn.tam-(2*sizeof(long))));
          fseek(f,*((long*)(b_ant.bloque+b_ant.tam-(2*sizeof(long)))),SEEK_SET);
          fwrite(b_ant.bloque, b_ant.tam,1,f);
        } else {
          *((long*)(b_act.bloque+b_act.tam-(sizeof(long))))=*((long*)(bn.bloque+bn.tam-(2*sizeof(long))));
          fseek(f,*((long*)(b_act.bloque+b_act.tam-(2*sizeof(long)))),SEEK_SET);
          fwrite(b_act.bloque, b_act.tam,1,f);
        }
        fseek(f,*((long*)(bn.bloque+bn.tam-(2*sizeof(long)))),SEEK_SET);
        fwrite(bn.bloque, bn.tam,1,f);
      }
    }
    fclose(f);
  }
} 

void imprime_tabla(TNodoE *e) {
  FILE *f;
  char nom_arch[30];
  long pos;
  TBloque b = {NULL,0};
  strcpy(nom_arch, e->info.nombre);
  strcat(nom_arch, ".dat");
  f = fopen(nom_arch,"rb");
  if(f != NULL) {
    fread(&pos, sizeof(long),1,f);
    while(pos != -1L) {
      fseek(f,pos,SEEK_SET);
      if(b.bloque!=NULL) {
        free(b.bloque);
      }
      b = crea_bloque(e);
      fread(b.bloque, b.tam,1,f);
      imprime_bloque(e, b);
      pos = *((long*)(b.bloque+b.tam-(sizeof(long))));
    }
    fclose(f);
  }
}

//Funcion de baja, modificacion y consulta de bloques.
TBloque bajaBloque(TBloque b, TNodoE *e) {
  long cab = -1L;
  FILE *f;
  char nom_arch[50];
  long dir;
  TBloque b_act = {NULL, 0}, b_eli = {NULL, 0}, b_ant = {NULL, 0};
  strcpy(nom_arch, e->info.nombre);
  strcat(nom_arch, ".dat");
  f = fopen(nom_arch, "rb+");
  if (f == NULL) {
    printf("\nEl archivo no existe\n");
  } else {
    fseek(f, 0, SEEK_SET);
    fread(&cab, sizeof(long), 1, f);
    if (cab == -1L) {
      printf("\nEl archivo esta vacio\n");
    } else {
      fseek(f, cab, SEEK_SET);
      b_act = crea_bloque(e);
      fread(b_act.bloque, b_act.tam, 1, f);
      if (compara_bloque(e, b, b_act) == 0) {
        b_eli = b_act;
        dir = *((long *)(b_act.bloque + b_act.tam - (sizeof(long))));
        fseek(f, 0, SEEK_SET);
        fwrite(&dir, sizeof(long), 1, f);
      } else {
        while (*((long *)(b_act.bloque + b_act.tam - (sizeof(long)))) != -1L && compara_bloque(e, b, b_act) > 0) {
          if (b_ant.bloque != NULL) {
            free(b_ant.bloque);
          }
          b_ant = b_act;
          fseek(f, *((long *)(b_act.bloque + b_act.tam - (sizeof(long)))),
                SEEK_SET);
          b_act = crea_bloque(e);
          fread(b_act.bloque, b_act.tam, 1, f);
        }
        if (compara_bloque(e, b, b_act) == 0) {
          b_eli = b_act;
          *((long *)(b_ant.bloque + b_ant.tam - sizeof(long))) =
              *((long *)(b_act.bloque + b_act.tam - (sizeof(long))));
          fseek(f, *((long *)(b_ant.bloque + b_ant.tam - sizeof(long) * 2)),
                SEEK_SET);
          fwrite(b_ant.bloque, b_ant.tam, 1, f);
        } else {
          printf("\nEl bloque no existe\n");
        }
      }
    }
    fclose(f);
  }
  return b_eli;
}
