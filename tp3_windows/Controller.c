#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* id)
{	int ret = -1;
	FILE* pFile = NULL;
	int f;

	if(path!=NULL && pArrayListEmployee != NULL){
		pFile = fopen(path,"r");

		if(pFile != NULL){
			f = parser_EmployeeFromText(pFile,pArrayListEmployee,id);
			if(!f){
				ret = 0;
				fclose(pFile);
			}
		}
		else{
			printf("\nNo se puede leer el archivo, volviendo al menú principal. . .");
		}
	}

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* id)
{	int ret = -1;
	FILE* pFile;
	int f;
	pFile = fopen(path,"rb");
	if(pFile != NULL){

		f = parser_EmployeeFromBinary(pFile,pArrayListEmployee,id);
		if(!f){
			ret = 0;
			fclose(pFile);
		}
	}
    return ret;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{	int ret = -1;
	Employee* aux = employee_new();
	int auxId = *id;
	int auxSueldo;
	char auxNombre[128];
	int auxHoras;

	if(pArrayListEmployee != NULL && aux != NULL){
		if(!utn_getString(auxNombre,"\nIngrese el nombre del empleado: ","Error, datos invalidos reingrese un nombre",3)){
			if(!utn_getNumero(&auxHoras,"\nIngrese las horas de trabajo del empleado","Error dato invalido",0,1000,3)){
				if(!utn_getNumero(&auxSueldo,"\nIngrse el sueldo en pesos: ","\nError, reingrese el sueldo en PESOS: ",0,10000,3)){
					employee_setHorasTrabajadas(aux,auxHoras);
					employee_setId(aux,auxId);
					employee_setNombre(aux,auxNombre);
					employee_setSueldo(aux,auxSueldo);
					ll_add(pArrayListEmployee,aux);
					(*id)++;
					ret = 0;
				}else{
					employee_delete(aux);
					aux = NULL;
					printf("\nNo se pudo cargar correctamente el empleado, volviendo al menú anterior ... \n\n");
				}
			}
		}
	}
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{	int ret = -1;
	Employee* aux;
	int auxId;
	int opcion;
	char nombre[128];
	int horas;
	int sueldo;

	if(pArrayListEmployee != NULL){
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&auxId,"\nIngrese el ID del empleado a modificar:","\nID invalido o no existente, reingrese: ",0,10000,3)){
			aux = ll_get(pArrayListEmployee,auxId);
			if(aux!=NULL)
			{
				menuModificar();
				if(!utn_getNumero(&opcion,"\nSu opcion: ","\nError, reingrese: ",1,4,3)){
					ret = 0;
						switch(opcion){
						case 1:
							if(!utn_getString(nombre,"\nIngrese el nuevo nombre para modificar: ","\nDato invalido, ingrese un nombre: ",3 )){
								employee_setNombre(aux,nombre);
								ll_set(pArrayListEmployee,auxId,aux);
							}
							break;
						case 2:
							if(!utn_getNumero(&horas,"\nIngrese las horas trabajadas del empleado: ","\nError, reingrese las horas: ",1,1000,3 )){
								employee_setHorasTrabajadas(aux,horas);
								ll_set(pArrayListEmployee,auxId,aux);
							}
							break;
						case 3:
							if(!utn_getNumero(&sueldo,"\nIngrese el nuevo sueldo del empleado: ","\nError, reingese el sueldo: ",1,100000,3 )){
								employee_setSueldo(aux,sueldo);
								ll_set(pArrayListEmployee,auxId,aux);
							}
							break;
						case 4:
							printf("\nAcción cancelada por el usuario, volviendo al menu anterior...");
							break;
						}
						printf("\nDato modificado exitosamente !\n");
					}
			}
		}
	}

    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{	int ret = -1;
	int id;

	if(pArrayListEmployee != NULL){
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&id,"\nIngrese el id del empleado a eliminar","\nError, id invalido reingrese: ",0,10000,3)){
			ll_remove(pArrayListEmployee,id);
			ret = 0;
			printf("\nBaja exitosa !! \n");
		}else{
			printf("\nSe agotaron los intentos, no se realizo ninguna BAJA... volviendo al menú anterior. . .\n\n");
		}
	}else{
		printf("\nNo hay nada para borrar, no se realizó ninguna carga");
	}
    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int i;

	Employee* auxEmployee;

	if(pArrayListEmployee != NULL){
		printf("\nID  Nombre   Horas Trabajadas Sueldo\n\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			employee_printEmployee(auxEmployee);
		}
		ret = 0;
	}
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{	int ret = -1;
	int criterio;
	int respuesta;
	if(pArrayListEmployee != NULL){
		menuOrdenamiento1();
		if(!utn_getNumero(&criterio,"\nSu opcion: ","\nDato invalido, reingrese: ",1,2,3)){
			menuOrdenamiento2();
			if(!utn_getNumero(&respuesta,"\nSu opcion: ","\nDato invalido, reingrese: ",1,4,3)){
				switch(respuesta){
				case 1:
					if(criterio == 1){
						ll_sort(pArrayListEmployee,employee_orderID, 1);
						printf("\nSe ordeno exitosamente de manera ascendente su lista!\n");
					}else{
						ll_sort(pArrayListEmployee,employee_orderID,0);
						printf("\nSe ordeno exitosamente de manera descendente su lista!\n");
					}
					break;
				case 2:
					if (criterio == 1) {
						ll_sort(pArrayListEmployee, employee_orderName, 1);
						printf(
								"\nSe ordeno exitosamente de manera ascendente su lista!\n");
					} else {
						ll_sort(pArrayListEmployee, employee_orderName, 0);
						printf(
								"\nSe ordeno exitosamente de manera descendente su lista!\n");
					}
					break;
				case 3:
					if (criterio == 1) {
						ll_sort(pArrayListEmployee, employee_orderHorasTrabajadas, 1);
						printf(
								"\nSe ordeno exitosamente de manera ascendente su lista!\n");
					} else {
						ll_sort(pArrayListEmployee, employee_orderHorasTrabajadas, 0);
						printf(
								"\nSe ordeno exitosamente de manera descendente su lista!\n");
					}
					break;
				case 4:
					if (criterio == 1) {
						ll_sort(pArrayListEmployee, employee_orderSueldo, 1);
						printf(
								"\nSe ordeno exitosamente de manera ascendente su lista!\n");
					} else {
						ll_sort(pArrayListEmployee, employee_orderSueldo, 0);
						printf(
								"\nSe ordeno exitosamente de manera descendente su lista!\n");
					}
					break;
				}
			}
		}
		ret = 0;
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{	int ret= -1;
	Employee* employee = NULL;
	int id;
	int horasTrabajadas;
	char nombre[128];
	int sueldo;
	FILE* pArchivo;

	if(path != NULL && pArrayListEmployee != NULL){
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL )
		{
			fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i = 0; i<ll_len(pArrayListEmployee); i++)
			{
				employee = ll_get(pArrayListEmployee,i);
				employee_getId(employee,&id);
				employee_getNombre(employee,nombre);
				employee_getHorasTrabajadas(employee,&horasTrabajadas);
				employee_getSueldo(employee,&sueldo);
				fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
			}
			fclose(pArchivo);
			ret = 0;
		}else{
			printf("\nNo se pudo escribir en el archivo, hubo un error.\n");
		}
	}

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{	int ret = -1;
	FILE* pArchivo;
	Employee* employee;

	if(path != NULL && pArrayListEmployee != NULL){
		pArchivo = fopen(path,"wb");
		if(pArchivo != NULL){
			for(int i = 0; i<ll_len(pArrayListEmployee);i++){
				employee = ll_get(pArrayListEmployee,i);
				fwrite(employee,sizeof(Employee*),1,pArchivo);
			}
			fclose(pArchivo);
			ret = 0;
		}
	}
    return ret;
}
