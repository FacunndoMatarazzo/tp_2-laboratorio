/*
 ============================================================================
 Name        : tp_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArraysPasajeros.h"
#include <string.h>
#include <ctype.h>
#define TAMPASAJEROS 2000
#define TAMTIPOPASAJEROS 3


int main(void) {

	int opcionMP;
	int opcionMM;
	int opcionMInfo;
	int opcionIdModificar;
	int indiceAModificar;
	int opcionIdBajar;
	int indiceABajar;
	int id = 0;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoDeVuelo[10];
	int tipoDePasajero;
	float precioTotal;
	float precioPromedio;
	int cantPasajeroPorEncimaDelPromedio;
	int estadoDelVuelo;
	int estadoVueloYTipoPas;

	sPasajero listaDePasajeros[TAMPASAJEROS];
	StatusYTypePasassenger(estadoVueloYTipoPas, TAMTIPOPASAJEROS)
	;

	setbuf(stdout, NULL);

	if(Passengers(listaDePasajeros, TAMPASAJEROS)!= 0)
	{
		printf("\nError al inicializar la estructura.\n");
	}

	if(StatusYTypePasassenger(estadoVueloYTipoPas, TAMTIPOPASAJEROS) != 0)
	{
		printf("\nError al inicializar la estructura.\n");
	}

	do{
		printf("\nMenu principal: \n"
				"1- ALTA de pasajero.\n"
				"2- MODIFICAR pasajero.\n"
				"3- BAJA de pasajero.\n"
				"4- INFORMAR.\n"
				"5- Carga Forzada.\n"
				"6- Salir.\n"
				"Elija una opción: ");
		fflush(stdin);
		scanf("%d",&opcionMP);

		switch(opcionMP)
		{
			case 1:
				id++;
				utn_getName(nombre, "Ingrese el nombre del pasajero: ", "Error. Por favor, ingrese el nombre correctamente.\n");
				utn_getName(apellido, "Ingrese el apellido del pasajero: ", "Error. Por favor, ingrese el apellido correctamente.\n");
				utn_getFloat(&precio, "Ingrese el precio del vuelo: ", "Error. Ingrese un dato valido.\n", 1, 1100);
				utn_getInt(&tipoDePasajero, "Ingrese 1 si es Business, 2 si es  Economico, 3 si es  Turista: ",
											"Error. Ingrese una opción valida.\n", 1, 3);
				pedirFlyCode(codigoDeVuelo, "Ingrese el codigo de vuelo: ");
				utn_getInt(&estadoDelVuelo, "Ingrese 1 si el vuelo esta Activo, 2 si esta Inactivo, 3 si esta Demorado: ",
						"Error. Ingrese una opción valida.\n",1,3);
				if(AddPassenger(listaDePasajeros,  TAMPASAJEROS,  id,  nombre, apellido, precio, tipoDePasajero, codigoDeVuelo, estadoDelVuelo) == 0)
				{
					printf("\nSe ha agregado un pasajero exitosamente.\n");
				}
				else
				{
					printf("\nHubo un error al intentar agregar el pasajero.\n");
				}
				break;
			case 2:
				do{
					printf("\nMenu de modificaciones de datos: \n"
							"1- Nombre.\n"
							"2- Apellido.\n"
							"3- Precio.\n"
							"4- Tipo de pasajero.\n"
							"5- Código de vuelo.\n"
							"6- Volver...\n"
							"Elija una opción: ");
					fflush(stdin);
					scanf("%d", &opcionMM);
					switch(opcionMM)
					{
						case 1:
							printf("Indique el ID del pasajero que desea modificar: ");
							fflush(stdin);
							scanf("%d", &opcionIdModificar);
							indiceAModificar = BuscarLibre(listaDePasajeros, TAMPASAJEROS, opcionIdModificar);
							if (indiceAModificar > -1)
							{
								if(ModificarPasajero(listaDePasajeros, TAMPASAJEROS, indiceAModificar, opcionMM) == 0)
								{
									printf("\nSe ha modificado al pasajero con exito.\n");
								}
								else
								{
									printf("\nHubo un error al intentar modificar al pasajero.\n");
								}
							}
							else
							{
								printf("\nEl ID ingresado no coincide con ningún pasajero de la lista.\n");
							}
							break;
						case 2:
							printf("\nVolviendo al menú principal.\n");
							break;
						default:
							printf("\nElija una opción valida.\n");
					}
				}while(opcionMM != 6);
				break;
			case 3:
				printf("Ingrese el ID del pasajero que desea dar de baja: ");
				fflush(stdin);
				scanf("%d", &opcionIdBajar);
				indiceABajar = BuscarLibre(listaDePasajeros, TAMPASAJEROS, opcionIdBajar);
				if (indiceABajar > -1)
				{
					if(removePassenger(listaDePasajeros, TAMPASAJEROS, indiceABajar) == 0)
					{
						printf("\nSe ha dado de baja con exito al pasajero.\n");
					}
					else
					{
						printf("\nHubo un error al intentar dar de baja al pasajero.\n");
					}
				}
				else
				{
					printf("\nEl ID ingresado no coincide con ningun pasajero de la lista.\n\n");
				}
				break;
			case 4:
				do{
					printf("\nMenu para informar pasajeros:\n"
							"1- Listado de pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
							"2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
							"3- Listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVO'\n"
							"4- Volver al menú principal\n"
							"Elija una opción: ");
					fflush(stdin);
					scanf("%d",&opcionMInfo);
					switch(opcionMInfo)
					{
					case 1:
						if(sortPassengersByLastName(listaDePasajeros, TAMPASAJEROS, 1) == 0)
						{
							if(printPassenger(listaDePasajeros, estadoVueloYTipoPas ,TAMPASAJEROS, TAMTIPOPASAJEROS) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHubo un error al intentar ordenar los pasajero por apellido.\n");
						}
						break;
					case 2:
						if(PromedioPassenger(listaDePasajeros,TAMPASAJEROS , &precioTotal, &precioPromedio) == 0)
						{
							cantPasajeroPorEncimaDelPromedio = SuperaElPromedio(listaDePasajeros, TAMPASAJEROS, precioPromedio);
							printf("\nEl precio total de los vuelos es $%.2f.\nEn promedio cada pasajero pagó $%.2f."
								"\nEn total hay %d pasajeros que paga por encima del promedio.\n", precioTotal, precioPromedio, cantPasajeroPorEncimaDelPromedio);
						}
						else
						{
							printf("\nHubo un error al intentar conseguir los calculos solicitados.\n");
						}
						break;
					case 3:
						if(sortPassengersByCode(listaDePasajeros, TAMPASAJEROS, 1) == 0)
						{
							if(printPassenger(listaDePasajeros, estadoVueloYTipoPas ,TAMPASAJEROS, TAMTIPOPASAJEROS) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHubo un error al intentar ordenar los pasajeros por codigo de vuelo.\n");
						}
						break;
					case 4:
						printf("\nVolviendo al menú principal.\n");
						break;
					default:
						printf("\nElija una opción valida.\n");
					}
				}while(opcionMInfo != 4);
				break;
			case 5:
				/*id++;
				AddPassenger(listaDePasajeros,  TAMPASAJEROS,  id, "Juan", "Perez", 58259.25, 1, "AMOA-85", 1);
				id++;
				AddPassenger(listaDePasajeros,  TAMPASAJEROS,  id,  "Ramiro", "Orta", 25853.36, 3, "DADD-02", 3);
				id++;
				AddPassenger(listaDePasajeros,  TAMPASAJEROS,  id,  "Facundo", "Soliz", 15953.85, 2, "DADW-85", 2);
				id++;
				AddPassenger(listaDePasajeros,  TAMPASAJEROS,  id,  "Joaquin", "Alvarez", 27125.5,	0, 1, "CHDQ-52", 1);

				printf("\nSe cargaron con exito todos los usuarios de la carga forzada.\n");*/
				break;
			case 6:
				printf("\n Sistema cerrado.\n");
				break;
			default:
				printf("\nElija una opcion correcta.\n");
		}

	}while(opcionMP != 6);

	return 0;
}
