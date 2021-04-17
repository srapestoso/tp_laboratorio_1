/*
 * calculos.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Usuario
 */

void Sumar(float a, float b, float *resultado)
{
	*resultado = a + b;
}

void Restar(float a, float b, float *resultado)
{
	*resultado = a - b;
}

void Divi(float a, float b, float *resultado)
{
	*resultado = a / b;
}

void Multi(float a, float b, float *resultado)
{
	*resultado = a * b;
}

int Factorial(int numero)
{
	int resp;
		if (numero == 1)
			return 1;
		resp = numero * Factorial(numero - 1);
		return (resp);
}
