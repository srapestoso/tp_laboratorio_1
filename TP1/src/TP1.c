/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"

int main(void) {

		setbuf(stdout,NULL);
	    int option;
	    float A,B;
	    float suma;
	    float resta;
	    float divi;
	    float multiplicar;
	    int r;
	    int r2;
	    int flagA = 0;
	    int flagB = 0;
	    do
	    {
	    	if(flagA)
	    	{
	    		printf("1. Ingresar 1er operando (A) = %.2f \n", A);
	    	}
	    	else{
	    		printf("1. Ingresar 1er operando (A) = \n");
	    	}
	    	if(flagB)
	    	{
	    		printf("2. Ingresar 1er operando (B) = %.2f\n", B);
	    	}
	    	else{
	    		printf("2. Ingresar 2do operando (B) = \n");
	    	}


	        printf("3. Calcular todas las operaciones:\n");
	        printf("	Suma, resta, division, multiplicacion y factorial de los operando\n");
	        printf("4. Informar resultados\n");
	        printf("5. SALIR\n");
	        fflush(stdin);

	        utn_getNumero(&option,"Elija una opcion\n","Dato invalido reingrese\n",1,5,3);
	        switch(option)
	        {
	            case 1:
	            	if(utn_getFloat(&A,"\nIngrese 1er operando: ","\nError.Elija un numero valido entre el 0 y 3000\n",0,3000,3) == 0)
	            	{
	            		printf("Ingreso %2.f\n",A);
	            	}
	            	else
	            	{
	            		A = 0;
	            	printf("\n No fue posible cargar el dato, se le asignará un 0\n");
	            	}
	                flagA = 1;
	                break;
	            case 2:
	            	if(utn_getFloat(&B,"\nIngrese 2er operando: ","\nError.Elija un numero valido entre el 0 y 3000\n",0,3000,3) == 0)
	            	{
	            		printf("Ingreso: %2.f\n",B);
	            	}
	            		else
	            	{
	            			B = 0;
	            			printf("\nNo fue posible cargar el dato, se le asignara un 0\n");
	            	}
	                flagB = 1;
	                break;
	            case 3:
	            	if(!flagA && !flagB){
	            		printf("\nNo se ingresaron datos por favor, intente nuevamente luego de ingresar los datos");
	            	}
	            	else{
	                printf("\n\n    Operaciones realizadas con exito!\n\n");
	                Sumar(A,B,&suma);
	                Restar(A,B,&resta);
	                Divi(A,B,&divi);
	                Multi(A,B,&multiplicar);
	                if(!(A<=0))
	                {
	                	r = Factorial(A);
	                }
	                if(!(B<=0)){
	                	r2 = Factorial(B);
	                }
	            	}
	            	break;
	            case 4:
	            	if(!flagA && !flagB)
	            	{
	            		printf("\nNo se ingresaron datos por favor, intente nuevamente luego de ingresar los datos");
	            	}
	            	else{
	                printf("Los resultados son los siguientes: \n");
	                printf("\nEl resultado de A + B es = %.2f", suma);
	                printf("\nEl resultado de A - B es = %.2f", resta);
	                    if(B==0)
	                    {
	                        printf("\nNo es posible dividir por cero");
	                    }
	                    else
	                    {
	                        printf("\nEl resultado de A / B es = %.2f", divi);
	                    }
	                printf("\nEl resultado de A*B es = %.2f", multiplicar);
	                if(!(A<=0))
	                {
	                printf("\nEl resultado del factorial de A es = %d", r);
	                }
	                else{
	                	printf("\nNo existe el factorial de un numero menor o igual a 0\n");
	                }
	                if(!(B<=0))
	                {
	                printf("\nEl resultado del factorial de B es = %d\n", r2);
	            	}
	                else{
	                	printf("\nNo existe el factorial de un numero menor o igual a 0\n");
	                }
	            	}
	                break;
	            case 5:
	                break;
	            default:
	                printf("Opcion incorrecta!!!\n");

	        }
	    system("pause");
	    system("cls");
	    }
	    while(option!=5);

	    return 0;

	return EXIT_SUCCESS;
}
