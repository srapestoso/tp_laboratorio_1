#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee = NULL;
    newEmployee= (Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
    	employee_setId(newEmployee,0);
		employee_setNombre(newEmployee,"");
		employee_setHorasTrabajadas(newEmployee,0);
		employee_setSueldo(newEmployee,0);
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* newEmployee = employee_new();

    if(newEmployee != NULL && idStr!= NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL )
    {
    	employee_setId(newEmployee,atoi(idStr));
    	employee_setNombre(newEmployee,nombreStr);
    	employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr));
    	employee_setSueldo(newEmployee,atoi(sueldo));
    }else{
    	employee_delete(newEmployee);
    	newEmployee=NULL;
    }
    return newEmployee;

}

void employee_delete(Employee* this){
	if(this!=NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id){
	    int ret=-1;

	    if(this != NULL && id >= 0)
	    {
	        this->id = id;
	        ret=0;
	    }

	    return ret;
}
int employee_setNombre(Employee* this,char* nombre){
	int ret = -1;
	if(this!= NULL && nombre != NULL){
		strcpy(this->nombre ,nombre);
		ret = 0;
	}
	return ret;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int ret = -1;
	if(this!=NULL && horasTrabajadas>0){
		this->horasTrabajadas = horasTrabajadas;
		ret = 0;
	}
	return ret;
}
int employee_setSueldo(Employee* this,int sueldo){
	int ret = -1;
	if(this!=NULL && sueldo>0){
		this->sueldo = sueldo;
		ret = 0;
	}
	return ret;
}
int employee_getId(Employee* this,int* id){
	int ret = -1;
	if(this!=NULL && id!=NULL){
		*id = this->id;
		ret = 0;
	}
	return ret;
}
int employee_getNombre(Employee* this,char* nombre){
	int ret = -1;
	if(this!=NULL && nombre !=NULL){
		strcpy(nombre,this->nombre);
		ret = 0;
	}
	return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int ret=-1;
	if(this!=NULL && horasTrabajadas!=NULL){
		*horasTrabajadas = this->horasTrabajadas;
		ret = 0;
	}
	return ret;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int ret=-1;
	if(this!=NULL && sueldo!=NULL){
		*sueldo = this->sueldo;
		ret = 0;
	}
	return ret;
}

void employee_printEmployee(void* this){
	int id;
	char name[50];
	int horasTrabajadas;
	int sueldo;

	if(this!=NULL){
		if(employee_getId(this,&id) == 0 && employee_getNombre(this,name) == 0 &&	employee_getHorasTrabajadas(this,&horasTrabajadas) == 0 &&	employee_getSueldo(this,&sueldo) == 0){
			printf("\n%d %10s  %10d   %10d \n",id,name,horasTrabajadas,sueldo);
		}
	}
}
int employee_orderID(void* thisA, void* thisB){
	int criterio = -1;
	int id1;
	int id2;

	employee_getId(thisA,&id1);
	employee_getId(thisB,&id2);

	if(id1 > id2)
	{
		criterio = 1;
	}else if(id1 == id2){
		criterio = 0;
	}else{
		criterio = -1;
	}

	return criterio;
}
int employee_orderName(void* thisA, void* thisB ){
	int criterio = -1;
	char nombre1[128];
	char nombre2[128];

	employee_getNombre(thisA,nombre1);
	employee_getNombre(thisB,nombre2);

	if(strcmp(nombre1,nombre2) == 0){
		criterio = 0;
	}else if(strcmp(nombre1,nombre2) >0){
		criterio = 1;
	}else{
		criterio = -1;
	}
	return criterio;
}

int employee_orderSueldo(void* thisA, void* thisB ){
	int criterio = -1;
	int sueldo1;
	int sueldo2;

	employee_getSueldo(thisA,&sueldo1);
	employee_getSueldo(thisB,&sueldo2);

	if(sueldo1 == sueldo2){
		criterio = 0;
	}else if(sueldo1 > sueldo2){
		criterio = 1;
	}else{
		criterio = -1;
	}
	return criterio;
}

int employee_orderHorasTrabajadas(void* thisA, void* thisB ){
	int criterio = -1;
	int horas1;
	int horas2;

	employee_getHorasTrabajadas(thisA,&horas1);
	employee_getHorasTrabajadas(thisB,&horas2);

	if(horas1 == horas2){
		criterio = 0;
	}else if(horas1 > horas2){
		criterio = 1;
	}else{
		criterio = -1;
	}
	return criterio;
}
