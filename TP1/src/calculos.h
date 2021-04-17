/*
 * calculos.h
 *
 *  Created on: 17 abr. 2021
 *      Author: Usuario
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/** \brief Calcula la suma de 2 numeros flotantes
**  \param El numero que se usara para el calculo
**  \param El segundo numero que se usara para el calculo
**  \param El puntero para escribir el resultado
**/
void Sumar(float a, float b, float *resultado);

/** \brief Calcula la diferencia de 2 numeros flotantes
**  \param El numero que se usara para el calculo
**  \param El segundo numero que se usara para el calculo
**  \param El puntero para escribir el resultado
**/
void Restar(float a, float b, float *resultado);

/** \brief Calcula la division de 2 numeros flotantes
**  \param El numero que se usara para el calculo
**  \param El segundo numero que se usara para el calculo
**  \param El puntero para escribir el resultado
**/
void Divi(float a, float b, float *resultado);

/** \brief Calcula el producto de 2 numeros flotantes
**  \param El numero que se usara para realizar el calculo
**  \param El segundo numero que se usara para el calculo
**  \param El puntero para escribir el resultado
**/
void Multi(float a, float b, float *resultado);

/** \brief Calcula el factorial de un numero
**  \param El numero entero el cual se ultilizará para el calculo
**
**/
int Factorial(int numero);

#endif /* CALCULOS_H_ */
