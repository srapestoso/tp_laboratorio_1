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

/*
 * \brief: Pide el ingreso de un texto al usuario.
 * \param1: Puntero a la variable donde se escribirá el texto válidado.
 * \param2: Un mensaje de ingreso.
 * \param3: Un mensaje de error en casos en los que falle.
 * \param4: Cantidad maxima de reintentos.
 * \return: Retorna (0) si válido bien y (-1) en caso de no tener más reintentos.
 */
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);

/* \brief: Valida que sea solo caracteres alfabeticos.
 * \param1: String que recibe como parametro.
 * \return: Retorna (0) si validó bien y (-1) si hubo errores.
 */
int isValidTexto(char* stringRecibido);

/*
 * brief: Pide el ingreso de una respuesta al usuario.
 * param1: Puntero a la variable donde se escribirá la respuesta válidada.
 * param2: Un mensaje de ingreso.
 * param3: Un mensaje de error en casos en los que falle.
 * param4: Cantidad maxima de reintentos.
 * return: Retorna (0) si válido bien y (-1) en caso de no tener más reintentos.
 */
int utn_getRespuesta(char* pCaracter,char* mensaje,char* mensajeError, int reintentos);

/*
 * brief: Muestra el menu principal del programa
 */
void menuPrincipial(void);

/*
 * brief: Muestra el menu para la modificación de los datos.
 */
void menuModificar(void);

/*
 * brief: Muestra un menu al usuario para seleccionar un criterio de ordenamiento.
 */
void menuOrdenamiento1(void);

/*
 * brief: Muestra un menu de seleccion de ordenamiento al usuario.
 */
void menuOrdenamiento2(void);
#endif /* UTN_H_ */
