/*
 * employee.c
 *
 *  Created on: 12 may. 2021
 *      Author: Usuario
 */
#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len){
	int ret = -1;
	if(list!=NULL && len >0){
		for(int i = 0; i<len ; i++ ){
			list[i].isEmpty = TRUE;
		}
		ret = 0;
	}
	return ret;
}

int findEmpty(Employee list[], int len)
{
    int index = -1;
    int i;

    if(list!=NULL && len > 0 )
    {
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty)
			{
				index = i;
				break;
			}
		}
    }

    return index;

}

int addEmployees(Employee* list,int len,int* id){
	int ret = -1;
	int index;

		if (list != NULL && len > 0 && id != NULL)
		{
			index = findEmpty(list, len);

			if (index!=-1)
			{

				if(!(addEmployee(list,index,id)))
				{
					printf("\nCarga exitosa!!\n");
					(*id)++;
					ret = 0;
				}
				else{
					printf("\nNo se pudo realizar la carga, volviendo al menú anterior . . .");
				}
			}
			else
			{
				printf("\nNo hay espacio disponible");
			}
		}
	return ret;
}

int addEmployee(Employee* employee,int index,int* id){
	int ret = -1;
	Employee auxEmployee;
	if(employee!=NULL && index !=-1 && id!=NULL){
		if(!utn_getString(auxEmployee.name,"\nIngrese el nombre: ","Datos invalidos, por favor reingrese",3)){
			if(!utn_getString(auxEmployee.lastName,"\nIngrese el apellido: ","Datos invalidos, por favor reingrese",3)){
				if(!utn_getFloat(&auxEmployee.salary,"\nIngrese el salario(20.000-200.000): ","Datos invalidos, por favor reingrese",20.000,200.000,3)){
					if(!utn_getNumero(&auxEmployee.idSector,"\nIngrese el id del sector(1 - 4)","\nDato invalido reingrese(1 - 4): ",1,4,3)){
						strcpy(employee[index].name,auxEmployee.name);
						strcpy(employee[index].lastName,auxEmployee.lastName);
						employee[index].salary = auxEmployee.salary;
						employee[index].idSector = auxEmployee.idSector;
						printf("\nSECTOR : %d", auxEmployee.idSector);
						employee[index].id = *id;
						employee[index].isEmpty = FALSE;
						ret = 0;
					}
				}
			}
		}
	}

	return ret;
}

int printEmployees(Employee* list,int len)
{
	if(list!=NULL && len > 0)
	{
		printf("\nID     NOMBRE     APELLIDO     SALARIO     SECTOR\n");
		for (int i = 0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printEmployee(list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].idSector);
			}
		}

	}
	return 0;
}

void printEmployee(int id, char* name, char* lastName, float salary, int idSector){
	printf("\n%-5d     %-5s     %-5s     %-5.3f     %-5d ",id,name,lastName,salary,idSector);
}

int findEmployeeById(Employee* list, int len, int id){
	int index = -1;
	int i;
	if(list!=NULL && len > 0){
		for(i=0;i<len;i++)
		{
			if(id == list[i].id && list[i].isEmpty == 0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int removeEmployee(Employee* list, int len){
	int ret = -1;
	int index;
	int id;
	char respuesta;

	if(list!=NULL && len > 0){
		printEmployees(list,len);
		utn_getNumero(&id,"\nIngrese el ID del empleado para la baja: ","\nError, dato invalido reingrese",1000,3000,3);
		index = findEmployeeById(list,len,id);
		if(index!=-1){
			printEmployee(list[index].id,list[index].name,list[index].lastName,list[index].salary,list[index].idSector);
			utn_getRespuesta(&respuesta,"\nEstá seguro que quiere borrar este empleado de la lista? (s/n)","Error, reingrese (s/n)",3);
			if(respuesta == 's'){
				list[index].isEmpty = TRUE;
				ret = 0;
			}
			else{
				printf("\nAccion cancelada por el usuario, volviendo al menú principal. . .");
			}
		}
	}
	return ret;
}

int modifyEmployees(Employee* list, int len){
	int ret = -1;
	int i;
	int id;
	int opcion;
	if(list!=NULL && len >0){
		printEmployees(list,len);
		utn_getNumero(&id,"\nIngrese el ID del empleado para la baja: ","\nError, dato invalido reingrese",1000,3000,3);
		i = findEmployeeById(list,len,id);
			if(i!=-1){
			printEmployee(list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].idSector);
			utn_getNumero(&opcion,"\nQue dato desea modificar?\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n5)Cancelar\nSu opicion: ","Error, reingrese (1-5)",1,5,3);
			switch(opcion){
			case 1:
				modify_Name(list,i);
				break;
			case 2:
				modify_LastName(list,i);
				break;
			case 3:
				modify_salary(list,i);
				break;
			case 4:
				modify_Sector(list,i);
				break;
			case 5:
				printf("\nAccion cancelada por el usuario, volviendo al menu anterior . . .");
				break;
			}
		}
	}
	return ret;
}

void modify_Name(Employee* employee, int i){
	Employee auxEmployee;
	char respuesta;
	if(employee!=NULL && employee[i].isEmpty==FALSE){
		if(!utn_getString(auxEmployee.name,"\nIngrese el nuevo dato: ","\nError ingrese solo letras: ",3)){
			printf("\nDato anterior: %s \\\\ Dato que lo reemplazará: %s", employee[i].name,auxEmployee.name);
			if(!utn_getRespuesta(&respuesta,"\nEstá seguro que quiere modificar el dato del empleado? (s/n)","\nError reingrese (s/n)",3)){
				if(respuesta =='s'){
					strcpy(employee[i].name,auxEmployee.name);
				}else{
					printf("\nAccion cancelada por el usuario, volviendo al menu principal. . .");
				}
			}
		}
	}
}
void modify_LastName(Employee* employee, int i){
	Employee auxEmployee;
	char respuesta;
	if(employee!=NULL && employee[i].isEmpty==FALSE){
		if(!utn_getString(auxEmployee.lastName,"\nIngrese el nuevo dato: ","\nError ingrese solo letras: ",3)){
			printf("\nDato anterior: %s \\\\ Dato que lo reemplazará: %s", employee[i].lastName,auxEmployee.lastName);
			if(!utn_getRespuesta(&respuesta,"\nEstá seguro que quiere modificar el dato del empleado? (s/n)","\nError reingrese (s/n)",3)){
				if(respuesta =='s'){
					strcpy(employee[i].lastName,auxEmployee.lastName);
				}else{
					printf("\nAccion cancelada por el usuario, volviendo al menu principal. . .");
				}
			}
		}
	}

}
void modify_salary(Employee* employee, int i){
	Employee auxEmployee;
	char respuesta;
	if(employee!=NULL && employee[i].isEmpty==FALSE){
		if(!utn_getFloat(&auxEmployee.salary,"\nIngrese el nuevo dato (20.000 - 200.000): ","\nError reingrese (20.000 - 200.000): ",20000,200000,3)){
			printf("\nDato anterior: %f \\\\ Dato que lo reemplazará: %f", employee[i].salary,auxEmployee.salary);
			if (!utn_getRespuesta(&respuesta,
					"\nEstá seguro que quiere modificar el dato del empleado? (s/n)",
					"\nError reingrese (s/n)", 3)) {
				if (respuesta == 's') {
					employee[i].salary = auxEmployee.salary;
				} else {
					printf(
							"\nAccion cancelada por el usuario, volviendo al menu principal. . .");
				}
			}
		}
	}
}
void modify_Sector(Employee* employee, int i){
		Employee auxEmployee;
		char respuesta;
		if (employee != NULL && employee[i].isEmpty == FALSE) {
			if (!utn_getNumero(&auxEmployee.idSector,
					"\nIngrese el nuevo dato (1 - 4): ",
					"\nError reingrese (1 - 4): ", 1, 4,
					3)) {
				printf("\nDato anterior: %d \\\\ Dato que lo reemplazará: %d",
						employee[i].idSector, auxEmployee.idSector);
				if (!utn_getRespuesta(&respuesta,
						"\nEstá seguro que quiere modificar el dato del empleado? (s/n)",
						"\nError reingrese (s/n)", 3)) {
					if (respuesta == 's') {
						employee[i].idSector = auxEmployee.idSector;
					} else {
						printf(
								"\nAccion cancelada por el usuario, volviendo al menu principal. . .");
					}
				}
			}
		}
}

void inform(Employee* list, int tam){
	int r;
	int opcion;
	if(!utn_getNumero(&r,"\n1) Listado de empleados ordenados alfabeticamente y por sector\n2)Total y promedio de los salarios,y cuántos empleados superan el promedio\nSu opcion: ","\nDato invalido reingrese (1 - 2)",1,2,3)){
		switch (r){
		case 1:
			if(!utn_getNumero(&opcion,"\nComo desea ordenar su listado?\n1)Ascendente\n2)Descendente\nSu opcion: ","Dato invalido, reingrese (1- Ascendente, 2- Descendente): ",1,2,3))
			{
				switch(opcion){
				case 1:
					sortEmployees(list,tam,opcion);
					printEmployees(list,tam);
					break;
				case 2:
					printf("\nCASE 2");
					sortEmployees(list,tam,opcion);
					printEmployees(list,tam);
					break;
				}
			}
				break;
		case 2:
			calculateProm(list,tam);
			break;
		}
	}else{
		printf("\nAgoto sus reintentos, intente nuevamente más tarde. Volviendo al menú anterior . . .");
	}

}

void sortEmployees(Employee* list,int len, int order){
	int i;
	int flagDesordenado =-1;
	Employee auxList;

			if(order)  //Ascendente{
			do
			{
				flagDesordenado = 0;
				for(i=0;i<len-1;i++)
				{

						if(strcmp(list[i].lastName,list[i+1].lastName)>0)
						{
							auxList = list[i];
							list[i] = list[i+1];
							list[i+1] = auxList;
							flagDesordenado = -1;
						}
						if(strcmp(list[i].lastName,list[i+1].lastName)==0){
							if(list[i].idSector>list[i+1].idSector){
								auxList = list[i];
								list[i] = list[i+1];
								list[i+1] = auxList;
								flagDesordenado = -1;
							}
						}

				}
			}while(flagDesordenado==-1);
		if(order==2)
		{
			do
			{
				flagDesordenado = 0;
				for(i=0;i<len-1;i++)
				{

					if(strcmp(list[i].lastName,list[i+1].lastName)<0)
					{
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						flagDesordenado = -1;
					}
					if(strcmp(list[i].lastName,list[i+1].lastName)==0){
						if(list[i].idSector<list[i+1].idSector){
							auxList = list[i];
							list[i] = list[i+1];
							list[i+1] = auxList;
							flagDesordenado = -1;
						}
					}

				}
			}while(flagDesordenado==-1);
		}
}

void calculateProm(Employee* list,int len){
	float acumulador=0;
	float total;
	int i;
	int cont=0;
	int contSalario=0;

	if(list!=NULL && len> 0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == FALSE){
				acumulador+=list[i].salary;
				cont++;
			}
		}
		total = acumulador / cont;
		for(i=0;i<len;i++){
			if(total>list[i].salary){
				contSalario++;
			}
		}

	printf("\nEl total y promedio de los salarios es: %f y la cantidad de empleados que supera el promedio es: %d",total,contSalario);
	}
}
