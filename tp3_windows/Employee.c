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
//    	newEmployee->id = 0;
//    	strcpy(newEmployee->nombre,"");
//    	newEmployee->horasTrabajadas = 0;
//    	newEmployee->sueldo = 0;
    }
    return newEmployee;

	//return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* newEmployee = employee_new();
   // printf("\n///////////////////////// %s //////////////////////// \n",nombreStr);

    if(newEmployee != NULL && idStr!= NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL )
    {
        if((employee_setId(newEmployee,atoi(idStr)) && employee_setNombre(newEmployee,nombreStr) && employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr)) && employee_setSueldo(newEmployee,atoi(sueldo)))!=0)
        {
        	printf("\nNO DEBERÍA ENTRAR");
            free(newEmployee);
            newEmployee=NULL;
        }
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
		//printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!! %s !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n",nombre);
		ret = 0;
	}
	return ret;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int ret = -1;
	if(this!=NULL && (horasTrabajadas<0 || horasTrabajadas >24)){
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
			printf("\n%d\t %5s \t %5d \t\t %5d \n",id,name,horasTrabajadas,sueldo);
		}
	}
}
