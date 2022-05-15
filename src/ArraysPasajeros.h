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

/// @brief To indicate that all position in the array are empty, this function put the flag (isEmpty)
/// in TRUE in all position of the array
/// @param list Passenger* Pointer to array of passenger
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
///
int initPassengers(sPasajero* lista, int len);
/// @brief To indicate the values of the different types of passengers and flight statuses that exist
///
/// @param statusType
/// @param len
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int StatusYTypePasassenger(sTypeStatusPassenger* statusType, int len);
/// @brief print the content of passengers array
///
/// @param list Passenger*
/// @param length int
/// @return int
int printPassenger(sPasajero* lista, sTypeStatusPassenger* statusType ,int length, int lenTypeStatus);

int BuscarLibre(sPasajero* lista , int size);
/// @briefadd in a existing list of passengers the values received as parameters in the first empty position
///
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name char
/// @param lastName char
/// @param price float
/// @param typePassenger int
/// @param flycode char
/// @param statusFlight int
/// @returnint Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int AddPassenger(sPasajero* lista, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight);
/// @brief find a Passenger by Id and returns the index position in array.
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
int findPassengerById(sPasajero* lista, int len,int id);

void MostrarPassenger(sPasajero unPasajero,int index);
/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int removePassenger(sPasajero* lista, int len, int id);
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengersByLastName(sPasajero* lista, int len, int orden);
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengersByCode(sPasajero* lista, int len, int orden);
/// @brief Modify the field indicated by option in the slot of array of passengers indicated by index
///
/// @param list Passenger*
/// @param len int
/// @param index index where was charged the passenger and will be modify
/// @param option int [1] name [2] lastName [3] price [4] TypePassenger [5] flyCode
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int ModificarPasajero(sPasajero* lista, int len, int index, int opcion);

int PromedioPassenger(sPasajero* lista, int len, float* totalPrice, float* promedio);

int SuperaElPromedio(sPasajero* lista, int len, float promedio);





#endif /* ARRAYSPASAJEROS_H_ */
