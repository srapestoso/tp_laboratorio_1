/*
 * utn.h
 *
 *  Created on: 11 abr. 2021
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_



/*
 * \brief: Pide un numero por teclado al usuario
 * \param: Puntero a la variable donde se escribirá el numero
 * \param: Un mensaje de ingreso
 * \param: Un mensaje en caso de no ingresar un numero o los minimos, maximos
 * \param: Establece el minimo numero que se puede ingresar
 * \param: Estable el maximo numero que se puede ingresar
 * \param: Cantitdad maxima de reintentos
 * \return: Si salio todo bien retorna 0 , sino -1
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/*
* \brief: Solicita un flotante al usuario, lo valida, verifica y devuelve el resultado
* \param: Puntero a la variable donde se escribirá el numero
* \param: mensaje Es el mensaje a ser mostrado
* \param: mensajeError Es el mensaje a ser mostrado en caso de error
* \param: minimo Valor minimo aceptado
* \param: maximo Valor maximo aceptado
* \param: reintentos Cantidad de reintentos en el caso de error
* \return: En caso de exito 0, en caso de error -1
*
*/
float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* UTN_H_ */
