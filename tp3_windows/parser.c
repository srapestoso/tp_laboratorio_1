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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{	int ret = -1;
	int qty;
	char buffer[4][128];
	Employee* auxEmployee = employee_new();

	if(pFile != NULL && pArrayListEmployee != NULL ){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		do{
			qty = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(qty == 4){
				auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				if(auxEmployee!=NULL){
					ll_add(pArrayListEmployee,auxEmployee);
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
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{	int ret = -1;
	int qty;
	//char buffer[4][128];
	Employee* auxEmployee;
	int cont = 0;

	if(pFile != NULL && pArrayListEmployee!=NULL ){
		while(!feof(pFile)){
			auxEmployee = employee_new();
			qty = fread(auxEmployee,sizeof(auxEmployee),1,pFile);
			printf("\n CANTIDAD LEIDA : %d", qty);
			if(qty == 1 && auxEmployee != NULL){
//				if(employee_setId(auxEmployee,atoi(buffer[0]))== 0 &&
//						employee_setNombre(auxEmployee,buffer[1]) == 0 &&
//						employee_setHorasTrabajadas(auxEmployee,atoi(buffer[3])) == 0 &&
//						employee_setSueldo(auxEmployee,atoi(buffer[4])) == 0 ){

					if(ll_add(pArrayListEmployee,auxEmployee)==0){
						ret = 0;
						cont++;
				}
			}
		}
	}
	printf("\n leimos : %d \n",cont);
    return ret;
}
