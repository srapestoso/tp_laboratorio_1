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
	while(reintentos>0)
	{
		printf(mensaje);
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


