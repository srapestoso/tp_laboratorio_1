#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* id)
{	int ret = -1;
	int qty;
	char buffer[4][128];
	Employee* auxEmployee = employee_new();

	if(pFile != NULL && pArrayListEmployee != NULL ){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		do{
			qty = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(qty == 4){
				auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				if(auxEmployee!=NULL){
					ll_add(pArrayListEmployee,auxEmployee);
					(*id)++;
					ret = 0;
				}else{
					printf("\nNo se pudo crear el empleado");
					break;
				}

			}
			else{
				printf("\nNo se pudo leer el archivo correctamente, volviendo al menu principal");
				break;
			}

		}while(!feof(pFile));
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee, int* id)
{	int ret = -1;
	int qty;
	Employee* auxEmployee;
	if(pFile != NULL && pArrayListEmployee!=NULL ){
		while(!feof(pFile)){
			auxEmployee = employee_new();
			qty = fread(auxEmployee,sizeof(Employee),1,pFile);
			if(qty == 1 && auxEmployee != NULL){
					ll_add(pArrayListEmployee,auxEmployee);
					(*id)++;
					ret = 0;
				}
			}
		}
    return ret;
}
