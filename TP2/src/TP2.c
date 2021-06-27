/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "utn.h"
#define QTY_EMP 1000


int main(void){
	setbuf(stdout,NULL);
	int respuesta;
	int id = 1000;
	int flag = 0;
	int r;

	//Employee listEmployee[QTY_EMP] = { {1001,"Nicolas","Rolon",30000,3,0} , {1002,"Pepito","Rolon",35000,1,0} , {1003,"Pancho","Diaz",27500,2,0} };
	Employee listEmployee[QTY_EMP];
	initEmployees(listEmployee,QTY_EMP);

	do{
		if(!utn_getNumero(&respuesta,"\n1 - ALTA\n2 - MODIFICAR\n3 - BAJA\n4 - INFORMES\n5 - SALIR\nSu opcion: ","Error reingrese: \n",1,5,3)){
			switch (respuesta){
			case 1:
				r = addEmployees(listEmployee,QTY_EMP,&id);
				if(!r){
					flag = 1;
				}
				break;
			case 2:
				if(flag){
				r = modifyEmployees(listEmployee,QTY_EMP);
				}else{
					printf("\nSe debe realizar por lo menos una carga para acceder a esta opcion.");
				}
				break;
			case 3:
				if(flag){
				 r = removeEmployee(listEmployee,QTY_EMP);
				 if(!r){
				 printf("\nBAJA EXITOSA!\n");
				 }
				}
				else{
				printf("\nSe debe realizar por lo menos una carga para acceder a esta opcion.");
				}
				break;
			case 4:
				if(flag){
				// printEmployees(listEmployee,QTY_EMP);
				inform(listEmployee,QTY_EMP);
				}else{
				printf("\nNo hay nada para mostrar porque no se realizó ninguna carga.");
				}
				break;
			case 5:
				printf("\nSaliendo del programa . . .");
				break;
			}
		}
	}while(respuesta!=5);
	return EXIT_SUCCESS;
}


