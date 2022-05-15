/*
 * ArraysPasajeros.h
 *
 *  Created on: 14 may. 2022
 *      Author: Fakui
 */

#ifndef ARRAYSPASAJEROS_H_
#define ARRAYSPASAJEROS_H_

typedef struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;

}sPasajero;


typedef struct
{
	int statusFlight;
	char descripcionStatus[30];
	int typePassenger;
	char descripcionType[15];

}sTypeStatusPassenger;

int Passengers(sPasajero* lista, int len);

int StatusYTypePasassenger(sTypeStatusPassenger* statusType, int len);

int BuscarLibre(sPasajero* lista , int size);

int AddPassenger(sPasajero* lista, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight);

int findPassengerById(sPasajero* lista, int len,int id);

void MostrarPassenger(sPasajero unPasajero,int index);

int removePassenger(sPasajero* lista, int len, int id);



int sortPassengersByLastName(sPasajero* lista, int len, int orden);

int sortPassengersByCode(sPasajero* lista, int len, int orden);

int ModificarPasajero(sPasajero* lista, int len, int index, int opcion);

int PromedioPassenger(sPasajero* lista, int len, float* totalPrice, float* promedio);

int SuperaElPromedio(sPasajero* lista, int len, float promedio);





#endif /* ARRAYSPASAJEROS_H_ */
