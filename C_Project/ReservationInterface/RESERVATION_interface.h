/**
 * @file    RESERVATION_interface.h
 * @brief   Header file for the Reservation module.
 * @details Contains macros, enumerations, structures, and function prototypes for managing clinic reservations.
 * @author  Mohammed Diaa mohammeddiaato@gmail.com
 */
#ifndef RESERVATION_H
#define RESERVATION_H

/**
 * @def     MAX_RESERVATIONS_SLOTS
 * @brief   Maximum number of reservation time slots available per day.
 */
#define MAX_RESERVATIONS_SLOTS 5

/**
 * @def     RESERVATION_RESERVED
 * @brief   Status code indicating a slot is currently booked.
 */
#define RESERVATION_RESERVED 1

/**
 * @def     RESERVATION_UNRESERVED
 * @brief   Status code indicating a slot is empty and available.
 */
#define RESERVATION_UNRESERVED 0

/**
 * @def     RESERVATION_ADD_SLOT_ERROR
 * @brief   Error code when failing to book a reservation.
 */
#define RESERVATION_ADD_SLOT_ERROR 2

/**
 * @def     RESERVATION_CANCEL_SLOT_ERROR
 * @brief   Error code when failing to cancel a reservation.
 */
#define RESERVATION_CANCEL_SLOT_ERROR 3

/**
 * @enum    RESERVATIONS_SlotsTimes
 * @brief   Defines the available time slots for clinic reservations.
 */
typedef enum
{
	TWO_PM = 1,	  // 2pm to 2:30pm
	TWO_HALF_PM,  // 2:30pm to 3pm
	THREE_PM,	  // 3pm to 3:30pm
	FOUR_PM,	  // 4pm to 4:30pm
	FOUR_HALF_PM, // 4:30pm to 5pm

} RESERVATIONS_SlotsTimes;

/**
 * @struct  Reservation_t
 * @brief   Structure holding the details of a single reservation slot.
 */
typedef struct
{
	Patient_t *Patient;
	u8 slotReserved;
} Reservation_t;

/**
* @fn      RESERVATION_voidInit
* @brief   Initializes the reservation system.
* @details Sets all time slots to be empty and unreserved.
* @return  void
*/
void RESERVATION_voidInit();

/**
* @fn      RESERVATION_u8CancelReservation
* @brief   Cancels a patient's reservation.
* @details Clears the slot so it can be booked by someone else. it changes the status to unreserved.
* @param   SlotTime The specific time slot to cancel.
* @return  Status code indicating success or a cancellation error.
*/
u8 RESERVATION_u8CancelReservation(RESERVATIONS_SlotsTimes SlotTime);

/**
* @fn      RESERVATION_u8AddReservation
* @brief   Books a new reservation for a patient.
* @details Assigns a patient to an empty time slot. it fails if the slot is already taken.
* @param   Patient Pointer to the patient structure making the reservation.
* @param   SlotTime The specific time slot to book.
* @return  Status code indicating success or an add error.
*/
u8 RESERVATION_u8AddReservation(Patient_t *Patient, RESERVATIONS_SlotsTimes SlotTime);

/**
* @fn      RESERVATION_voidViewReservations
* @brief   Displays the schedule of all reservations.
* @details Prints out each time slot and shows whether it is booked or available.
* @return  void
*/
void RESERVATION_voidViewReservations();

#endif