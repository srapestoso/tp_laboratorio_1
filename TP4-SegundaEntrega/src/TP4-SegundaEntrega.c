/*
 ============================================================================
 Name        : TP4-SegundaEntrega.c
 Author      : Rolon Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagText = 0;
    int flagBin = 0;
    int flagABM = 0;
    int text;
    int bin;
    int abm;
    int id=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	menuPrincipial();
    	if(!utn_getNumero(&option,"\nSu opcion: ","\nError, dato invalido reingrese(1-10): ",1,10,5)){
			switch(option)
			{
					case 1:
						text = controller_loadFromText("data.csv",listaEmpleados,&id);
						if(!text){
							flagText = 1;
							id++;
						}
						break;
					case 2:
						bin = controller_loadFromBinary("dataB.bin",listaEmpleados,&id);
						if(!bin){
							flagBin = 1;
							id++;
						}
						break;
					case 3:
						abm = controller_addEmployee(listaEmpleados,&id);
						if(!abm){
							flagABM = 1;
							id++;
						}
						break;
					case 4:
						if(flagABM || flagText || flagBin){
						controller_editEmployee(listaEmpleados);
						}else{
							printf("\nPara acceder a esta opcion debe realizarse una carga o una lectura de archivo... volviendo al menu...");}
						break;
					case 5:
						if(flagABM || flagText || flagBin){
							controller_removeEmployee(listaEmpleados);
						}else{
							printf("\nPara acceder a esta opcion debe realizarse una carga o una lectura de archivo... volviendo al menu...");
						}
						break;
					case 6:
						if(flagABM || flagText || flagBin){
						controller_ListEmployee(listaEmpleados);
						}else{
							printf("No hay nada para mostrar, se debe realizar una lectura de archivo o por lo menos una carga... volviendo al menu...");
						}
						break;
					case 7:
						if(flagABM || flagText || flagBin){
						controller_sortEmployee(listaEmpleados);
						}else{
							printf("\nPara acceder a esta opcion debe realizarse una carga o una lectura de archivo... volviendo al menu...");
						}
						break;
					case 8:
						if(flagText){
						controller_saveAsText("data.csv",listaEmpleados);
						}else{
							printf("\nDebe realizarse primero alguna lectura de archivo para poder acceder a esta opcion... volviendo al men�...");
						}
						break;
					case 9:
						if(flagBin){
						controller_saveAsBinary("dataB.bin",listaEmpleados);
						}else{
							printf("\nDebe realizarse primero alguna lectura de archivo para poder acceder a esta opcion... volviendo al men�...");
						}
						break;
					case 10:
						printf("\nSaliendo del programa . . . ");
						break;
			}
    	}
		}while(option != 10);
    return 0;
}
