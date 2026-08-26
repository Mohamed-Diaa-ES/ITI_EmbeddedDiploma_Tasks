/**
 * @file    RESERVATION_interface.c
 * @brief   Implementation file for managing reservations.
 * @details Contains the functions to create, cancel, and view time slots. 
 * @author  Mohammed Diaa mohammeddiaato@gmail.com
 */
#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "PATIENT_interface.h"
#include "RESERVATION_interface.h"
/**
 * @var     reservationTimeStr
 * @brief   List of text strings showing the schedule. it holds text like "2pm to 2:30pm".
 */
static u8 reservationTimeStr[MAX_RESERVATIONS_SLOTS][50];
/** 
 * @var     Reservations_List
 * @brief   Array that holds the booking status and patient data for each time slot.
 */
static Reservation_t Reservations_List[MAX_RESERVATIONS_SLOTS];

void RESERVATION_voidInit()
{
	// Initialize the reservation time strings
	strcpy((char *)reservationTimeStr[0], "2pm to 2:30pm");
	strcpy((char *)reservationTimeStr[1], "2:30pm to 3pm");
	strcpy((char *)reservationTimeStr[2], "3pm to 3:30pm");
	strcpy((char *)reservationTimeStr[3], "4pm to 4:30pm");
	strcpy((char *)reservationTimeStr[4], "4:30pm to 5pm");

	// Initialize all slots as unreserved with no patient assigned
	for (u32 i = 0; i < MAX_RESERVATIONS_SLOTS; i++)
	{
		Reservations_List[i].slotReserved = RESERVATION_UNRESERVED;
		Reservations_List[i].Patient = NULL;
	}
}

void RESERVATION_voidViewReservations()
{
	for (u32 i = 0; i < MAX_RESERVATIONS_SLOTS; i++)
	{
		// If the slot is reserved, print the time and the assigned patient's ID
		if (Reservations_List[i].slotReserved == RESERVATION_RESERVED && Reservations_List[i].Patient != NULL)
		{
			printf("%s is Reserved to patient with Id: %s\n", reservationTimeStr[i], Reservations_List[i].Patient->id);
		}
		else // Otherwise, indicate it is not reserved
		{
			printf("%s is not Reserved\n", reservationTimeStr[i]);
		}
	}
}

u8 RESERVATION_u8AddReservation(Patient_t *Patient, RESERVATIONS_SlotsTimes SlotTime)
{
	// Validate inputs
	if (Patient == NULL || SlotTime < TWO_PM || SlotTime > FOUR_HALF_PM)
	{
		return RESERVATION_ADD_SLOT_ERROR;
	}

	// Convert Enum to zero-based array index (TWO_PM is 1, so index is 0)
	u32 index = SlotTime - 1;

	// Book the slot if it is available
	if (Reservations_List[index].slotReserved == RESERVATION_UNRESERVED)
	{
		Reservations_List[index].Patient = Patient;
		Reservations_List[index].slotReserved = RESERVATION_RESERVED;

		return RESERVATION_RESERVED;
	}

	// Return error if the slot is already booked
	return RESERVATION_ADD_SLOT_ERROR;
}

u8 RESERVATION_u8CancelReservation(RESERVATIONS_SlotsTimes SlotTime)
{
	// Validate input bounds
	if (SlotTime < TWO_PM || SlotTime > FOUR_HALF_PM)
	{
		return RESERVATION_CANCEL_SLOT_ERROR;
	}

	u32 index = SlotTime - 1;

	// make  the slot free  if it is currently reserved
	if (Reservations_List[index].slotReserved == RESERVATION_RESERVED)
	{
		Reservations_List[index].Patient = NULL;
		Reservations_List[index].slotReserved = RESERVATION_UNRESERVED;

		return RESERVATION_UNRESERVED;
	}

	// Return error if the slot was already empty
	return RESERVATION_CANCEL_SLOT_ERROR;
}