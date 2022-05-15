/*
 * ArraysPasajeros.c
 *
 *  Created on: 14 may. 2022
 *      Author: Fakui
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "ArraysPasajeros.h"
#define TAM 2000
#define VACIO 0
#define LLENO 1

int initPassengers(sPasajero* lista, int len)
{
	int index;
	int i;

	if(lista!=NULL)
	{
		if(len>=0)
		{
			for(i=0;i<len;i++)
			{
				lista[i].isEmpty=0;
			}
			index=0;
		}
	}
	return index;
}
int findPassengerById(sPasajero* listaa, int len,int id)
{
	int index;
	index=-1;
	 for(int i=0;i<len;i++)
	 {
		 if(listaa[i].id==id)
		 {
			 index=i;
			 break;
		 }
	 }
	return index;
}
int BuscarLibre(sPasajero* lista, int len)
{
	int retorno = -1;
	int index;

	if (lista != NULL)
	{
	if (len >= 0)
	{
		for (index = 0; index < len; index++)
		{
			if(lista[index].isEmpty == 0)
			{
				retorno = index;
				break;
			}
		}
	}
	}
	return retorno;
}

int printPassenger(sPasajero* lista, sTypeStatusPassenger* statusType ,int length, int lenTypeStatus)
{
	int retorno = -1;
	int i;

	if (lista != NULL)
	{
		if (length >= 0)
		{
			printf("\nID:    Nombre: \t Apellido: \t  Precio: \t Codigo de Vuelo: \t Tipo de Pasajero: \tEstado del vuelo: \n");
		for (i = 0; i < length; i++)
		{
		if(lista[i].isEmpty == LLENO)
			{
				for(int j = 0; j < lenTypeStatus; j++)
				{
					if(lista[i].statusFlight == statusType[j].statusFlight)
					{
					for(int z = 0; z < lenTypeStatus; z++)
					{
						if(lista[i].typePassenger == statusType[z].typePassenger)
						{
							printf("%-4d %-16s %-19s %-15.2f %-21s %-26s %s\n", lista[i].id, lista[i].lastName, lista[i].name,
											lista[i].price, lista[i].flycode, statusType[z].descripcionStatus, statusType[j].descripcionType);
							break;
						}
					}
					break;
					}
				}
				retorno = 0;
			}
		}
	}
	}

	return retorno;
}
int sortPassengersByLastName(sPasajero* list, int len, int orden)
{
	sPasajero auxiliar;
	int retorno = -1;

	if (list != NULL)
		{
		if (len >= 0)
		{
		if (orden == 1)
		{
			for (int i = 0; i < len; i++)
				{
				for(int j = i + 1; j < len - 1; j++)
					{
						if (strcmp(list[i].lastName, list[j].lastName) > 0)
						{
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			}
			else
			{
			for (int i = 0; i < len; i++)
			{
				for(int j = i + 1; j < len - 1; j++)
				{
					if (strcmp(list[i].lastName, list[j].lastName) < 0)
					{
						auxiliar = list[j];
						list[j] = list[i];
						list[i] = auxiliar;
					}
					if(strcmp(list[i].lastName, list[j].lastName) == 0)
					{
						if(list[i].typePassenger > list[j].typePassenger)
						{
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
					}
				}
			}
			}
			retorno = 0;
		}
	}

	return retorno;
}
int AddPassenger(sPasajero* lista, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight)
{

	int retorno = -1;
	int libre;
	sPasajero auxiliar;

		if (lista != NULL)
		{
			if (len >= 0)
			{
				libre = BuscarLibre(lista, len);
				if (libre >= 0)
				{
					auxiliar.id = id;
					strcpy(auxiliar.name, name);
					strcpy(auxiliar.lastName, lastName);
					auxiliar.price = price;
					strcpy(auxiliar.flycode, flycode);
					auxiliar.typePassenger = typePassenger;
					auxiliar.isEmpty = 1;
					auxiliar.statusFlight = statusFlight;

					lista[libre] = auxiliar;
					retorno = 0;
				}
			}
		}

		return retorno;
	}



int sortPassengersByCode(sPasajero* lista, int len, int order)
{
	sPasajero auxiliar;
	int retorno = -1;

	if (lista != NULL)
		{
			if (len >= 0)
			{
				if (order == 1)
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(lista[i].flycode, lista[j].flycode) > 0)
							{
								auxiliar = lista[j];
								lista[j] = lista[i];
								lista[i] = auxiliar;
							}
							if(strcmp(lista[i].flycode, lista[j].flycode) == 0)
							{
								if(lista[i].statusFlight > lista[j].statusFlight)
								{
									auxiliar = lista[j];
									lista[j] = lista[i];
									lista[i] = auxiliar;
								}
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(lista[i].flycode, lista[j].flycode) < 0)
							{
								auxiliar = lista[j];
								lista[j] = lista[i];
								lista[i] = auxiliar;
							}
							if(strcmp(lista[i].flycode, lista[j].flycode) == 0)
							{
								if(lista[i].statusFlight > lista[j].statusFlight)
								{
									auxiliar = lista[j];
									lista[j] = lista[i];
									lista[i] = auxiliar;
								}
							}
						}
					}
				}
				retorno = 0;
			}
		}

	return retorno;
}


int StatusYTypePasassenger(sTypeStatusPassenger* statusType, int len)
{
	int retorno = -1;
	if (statusType != NULL)
	{
		if (len >= 0)
		{
			statusType[0].statusFlight = 1;
			strcpy(statusType[0].descripcionStatus, "ACTIVO");
			statusType[0].typePassenger = 1;
			strcpy(statusType[0].descripcionType, "Business");

			statusType[1].statusFlight = 2;
			strcpy(statusType[1].descripcionStatus, "INACTIVO");
			statusType[1].typePassenger = 2;
			strcpy(statusType[1].descripcionType, "Economica");

			statusType[2].statusFlight = 3;
			strcpy(statusType[2].descripcionStatus, "RETRASADO");
			statusType[2].typePassenger = 3;
			strcpy(statusType[2].descripcionType, " Turista");

			retorno = 0;
		}
	}
	return retorno;
}
int ModificarPasajero(sPasajero* lista, int len, int index, int opcion)
{
	int retorno = -1;
	char nameCambiado[51];
	float priceCambiado;
	int TipoCambiado;

	if (lista != NULL)
	{
		if (len >= 0)
		{
			switch(opcion)
			{
				case 1:
					utn_getName(nameCambiado, "Ingrese el nuevo nombre del pasajero: ",
							"Error. Ingrese correctamente el nombre.\n");
					strcpy(lista[index].name, nameCambiado);
					break;
				case 2:
					utn_getName(nameCambiado, "Ingrese el nuevo apellido del pasajero: ",
							"Error. Ingrese correctamente el apellido.\n");
					strcpy(lista[index].lastName, nameCambiado);
					break;
				case 3:
					utn_getFloat(&priceCambiado, "Ingrese el nuevo precio del vuelo: ",
							"Error. Ingrese un dato valido.\n", 1, 1000);
					lista[index].price = priceCambiado;
					break;
				case 4:
					utn_getInt(&TipoCambiado, "Ingrese 1 si es Business, 2 si es  Economica"
							", 3 si es  Turista: ",	"Error. Ingrese una opción valida.\n", 1, 3);
					lista[index].typePassenger = TipoCambiado;
					break;
				default:
					pedirFlyCode(lista[index].flycode, "Ingrese el nuevo codigo de vuelo: ");
			}
			retorno = 0;
		}
	}

	return retorno;
}
int PromedioPassenger(sPasajero* lista, int len, float* totalPrice, float* promedio)
{
	int retorno = -1;
	int contador = 0;
	float total;

		if(lista != NULL)
		{
			if(len > 0)
			{
				for(int i = 0; i < len; i++)
				{
					if(lista[i].isEmpty == LLENO && lista[i].price >= 0)
					{
						contador++;
						total+= lista[i].price;
						retorno = 0;
					}
				}
			}
		}
		*promedio = total / contador;
		*totalPrice = total;
	return retorno;
}

int SuperaElPromedio(sPasajero* lista, int len, float promedio)
{
	int retorno = -1;
	int contador = 0;

	if(lista != NULL)
	{
		if(len > 0)
		{
		for(int i = 0; i < len; i++)
			{
			if(lista[i].isEmpty == LLENO && lista[i].price > promedio)
				{
					contador++;
					retorno = contador;
				}
			}
		}
	}

	return retorno;
}
int removePassenger(sPasajero* lista, int len, int id)
{
	int retorno = -1;
	if(lista != NULL)
	{
		if(len >= 0)
		{
			lista[id].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}


