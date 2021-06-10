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
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{	int ret = -1;
	FILE* pFile = NULL;
	int f;

	if(path!=NULL && pArrayListEmployee != NULL){
		pFile = fopen(path,"r");

		if(pFile != NULL){
			f = parser_EmployeeFromText(pFile,pArrayListEmployee);
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{	int ret = -1;
	FILE* pFile;
	int f;
	pFile = fopen(path,"rb");
	if(pFile != NULL){

		f = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
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
	Employee* aux = employee_new();
	int auxId;
	int opcion;

	if(pArrayListEmployee != NULL && aux != NULL ){
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&auxId,"\nIngrese el ID del empleado a modificar:","\nID invalido o no existente, reingrese: ",0,10000,3)){
			menuModificar();
			if(!utn_getNumero(&opcion,"\nSu opcion: ","\nError, reingrese: ",1,4,3)){
				switch(opcion){
				case 1:
					//modificarNombre;
					break;
				case 2:
					//modificarHoras;
					break;
				case 3:
					//modificarSueldo;
					break;
				case 4:
					printf("\nAcción cancelada por el usuario, volviendo al menu anterior...");
					break;
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
		printf("\nID\t  Nombre   Horas Trabajadas Sueldo\t\n\n");
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
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
