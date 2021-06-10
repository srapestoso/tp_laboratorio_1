/*
 * utn.c
 *
 *  Created on: 11 abr. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena)
{
	int ret=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				break;
			}
			i++;
		}
		if(cadena[i]=='\0')
		{
			ret=1;
		}
	}
	return ret;
}

static int	getInt(int* pResultado){
	int ret=-1;
	char buffer[8];
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';
	if(esNumerica(buffer)){
		*pResultado = atoi(buffer);
		ret=1;
	}
	return ret;
}


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int ret;
	int num;
	while(reintentos>=0)
	{
		printf(mensaje);
		fflush(stdin);
		if(getInt(&num)==1)
		{
			if(num<=maximo && num>=minimo)
			{
				break;
			}
		}
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos==0){
		ret=-1;
	}
	else
	{
		ret=0;
		*pResultado = num;
	}
	return ret;
}

float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%f",&bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int ret = -1;
	char bufferString[30];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		while(reintentos>0)
		{
			fflush(stdin);
			printf("%s", mensaje);

			scanf("%s", bufferString);

			if(strlen(bufferString) < 30)
			{
				strcpy(aux, bufferString);

				break;
			}
				printf("%s", mensajeError);
				reintentos--;
		}
	}
	if(reintentos==0)
	{
		ret = -1;
	}
	else
	{
		ret =0;
	}

	return ret;
}

int utn_getRespuesta(char* pCaracter,char* mensaje,char* mensajeError, int reintentos)
{
	int ret;
	char bufferChar;
	if(pCaracter != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		while(reintentos>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar=='s'|| bufferChar=='n')
				{
					*pCaracter = bufferChar;
					break;
				}
				printf("%s", mensajeError);
				reintentos--;
		}
		if(reintentos==0){
			ret = -1;
		}
		else{
			ret = 0;
		}

	}
	return ret;
}

void menuPrincipial(void){
	printf("\n****************************************************\n"
    "Menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
     "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
     "3. Alta de empleado\n"
     "4. Modificar datos de empleado\n"
     "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    "10. Salir\n"
	"*****************************************************/\n");
}

void menuModificar(void){
	printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n"
		    "�Qu� desea modificar? : \n"
		     "1. Modificar Nombre\n"
		     "2. Modificar Horas trabajadas\n"
		     "3. Modificar Sueldo\n"
		     "4. Cancelar\n"
			"|||||||||||||||||||||||||||||||||||||||||||||||||||||/\n");
}
