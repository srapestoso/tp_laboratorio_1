/*
 * employee.h
 *
 *  Created on: 12 may. 2021
 *      Author: Usuario
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define TRUE 1
#define FALSE 0

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;
	int isEmpty;
}Employee;

/* brief: Pone en TRUE, todas las casillas isEmpty del array.
 * param1: Puntero al array del tipo estructura
 * param2: Tamaño del array
 * return: Retorna (0) si no hubo errores o (-1) si no pudo verificar que el puntero no sea nulo o el tamaño invalido.
 */
int initEmployees(Employee* list, int len);

/* brief: Busca en el array de la estructura si el campo isEmpty esta en TRUE
 * param1: Array del tipo estructura.
 * param2: Tamaño del array.
 * return: Retorna la posicion del array libre o (-1) si hubo errores.
 */
int findEmpty(Employee list[], int len);

/* brief: Agrega un empleado a la lista de empleados
 * param1: Puntero al array
 * param2: Tamaño del array
 * param3: ID del empleado a cargar
 * return: Retorna (0) si pudo realizarse la carga o (-1) si encontró algun error.
 */
int addEmployees(Employee* list,int tam,int* i);

/* brief: Realiza la carga de todos los campos de un empleado
 * param1: Puntero al array
 * param2: Posicion del empleado a cargar
 * param3: ID del empleado a cargar
 * return: Retorna (0) si pudo realizarse la carga o (-1) si encontró algun error.
 */
int addEmployee(Employee* employee,int index,int* i);

/* brief: Imprime la lista de empleados
 * param1: Puntero al array de empleados
 * param2: Tamaño total del array
 * return: Retorna (0) si hay empleados cargados o (-1) si el array es NULL o si el tamaño es menor o igual a 0.
 */
int printEmployees(Employee* list,int len);

/* brief: Imprime un empleado
 * param1: ID del empleado
 * param2: Nombre del empleado
 * param3: Apellido del empleado
 * param4: Salario del empleado
 * param5: ID del sector
 */
void printEmployee(int i, char* name, char* lastName, float salary, int idSector);

/* brief: Busca un empleado por ID
 * param1: Puntero al array
 * param2: Tamaño del array
 * param3: ID del empleado a buscar
 * return: Retorna el indice si lo encuentra o (-1) si hubo un error o no existe el id.
 */
int findEmployeeById(Employee* list, int len, int i);

/* brief: Elimina un empleado de la lista de empleados.
 * param1: Puntero al array del tipo estructura
 * param2: Tamaño del array
 * return: Retorna (0) si pudo realizarse la baja o (-1) si encontró o hubo algun error.
 */
int removeEmployee(Employee* list, int len);

/* brief: Modifica un dato de un empleado.
 * param1: Puntero al array del tipo estructura
 * param2: Tamaño del array
 * return: Retorna (0) si pudo realizarse la baja o (-1) si encontró o hubo algun error.
 */
int modifyEmployees(Employee* list, int len);

/* brief: Modifica el nombre del empleado
 * param1: Puntero donde se escribirá en nuevo nombre
 * param2: Indice del empleado a modificar
 */
void modify_Name(Employee* list, int i);

/* brief: Modifica el apellido del empleado
 * param1: Puntero donde se escribirá en nuevo nombre
 * param2: Indice del empleado a modificar
 */
void modify_LastName(Employee* list, int i);

/* brief: Modifica el salario del empleado
 * param1: Puntero donde se escribirá en nuevo nombre
 * param2: Indice del empleado a modificar
 */
void modify_salary(Employee* list, int i);

/* brief: Modifica el sector del empleado
 * param1: Puntero donde se escribirá en nuevo nombre
 * param2: Indice del empleado a modificar
 */
void modify_Sector(Employee* list, int i);

/* brief: Ingresa a un menu de informes permitiendo elegir mostrar la lista Ordenada y el Total/Promedio de la lista
 * param1: Puntero a la lista
 * param2: Tamaño de la lista
 */
void inform(Employee* list, int tam);

/* brief: Ordena el array de empleados por apellido y sector
 * param1: Puntero a la lista de empleados
 * param2: Tamaño de la lista
 * param3: Criterio de ordenamiento (1) Ascendente - (2) Descendente
 */
void sortEmployees(Employee* list,int len, int order);

/* brief: Calcula el total y promedio de salarios y muestra la cantidad de empleados que lo superan
 * param1: Puntero a la lista de empleados
 * param2: Tamaño de la lista
 */
void calculateProm(Employee* list,int len);
#endif /* ARRAYEMPLOYEES_H_ */
