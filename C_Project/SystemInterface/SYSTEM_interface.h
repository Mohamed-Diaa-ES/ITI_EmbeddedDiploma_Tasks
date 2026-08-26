/**
 * @file    SYSTEM_interface.h
 * @brief   Header file for the Clinic Reservation System.
 * @details Contains macros, enumerations, structures, and function prototypes for the system control and menus.
 * @author  Mohammed Diaa mohammeddiaato@gmail.com
 */
#ifndef SYSTEM_H
#define SYSTEM_H

/**
 * @def     MAX_SYSTEM_PASS_LEN
 * @brief   Maximum length allowed for the system password.
 */
#define MAX_SYSTEM_PASS_LEN 100

/**
 * @def     INVALID_LOGIN
 * @brief   Status code indicating a failed login attempt.
 */
#define INVALID_LOGIN 0

/**
 * @def     VALID_LOGIN
 * @brief   Status code indicating a successful login attempt.
 */
#define VALID_LOGIN 1

/**
 * @def     INVALID_PATIENT_GENDER
 * @brief   Error code for an invalid gender input.
 */
#define INVALID_PATIENT_GENDER 20

/**
 * @def     INVALID_PATIENT_AGE
 * @brief   Error code for an invalid age input.
 */
#define INVALID_PATIENT_AGE 21

/**
 * @def     INVALID_PATIENT_NAME
 * @brief   Error code for an invalid name input.
 */
#define INVALID_PATIENT_NAME 22

/**
 * @def     INVALID_PATIENT_ID
 * @brief   Error code for an invalid or non-existent patient ID.
 */
#define INVALID_PATIENT_ID 2

/**
 * @def     VALID_PATIENT_ID
 * @brief   Status code for a valid and existing patient ID.
 */
#define VALID_PATIENT_ID 3

/**
 * @def     MAX_PASSWORD_TESTS
 * @brief   Maximum number of incorrect password attempts allowed.
 */
#define MAX_PASSWORD_TESTS 3

/**
 * @def     INVALID_PASSWORD
 * @brief   Error code for entering the wrong password.
 */
#define INVALID_PASSWORD 4

/**
 * @def     VALID_PASSWORD
 * @brief   Status code for entering the correct password.
 */
#define VALID_PASSWORD 5

/**
 * @def     ERROR_RESERVATION_BOOKED
 * @brief   Error code when trying to book a slot that is already reserved.
 */
#define ERROR_RESERVATION_BOOKED 6

/**
 * @def     ERROR_RESERVATION_EMPTY
 * @brief   Error code when trying to cancel a slot that is already empty.
 */
#define ERROR_RESERVATION_EMPTY 7

/**
 * @def     ERROR_RESERVATION_SLOT_NOT_EXIST
 * @brief   Error code when an invalid slot number is selected.
 */
#define ERROR_RESERVATION_SLOT_NOT_EXIST 15

/**
 * @def     ERROR_PATIENT_ID_EXIST
 * @brief   Error code when trying to add a new patient with an ID that already exists.
 */
#define ERROR_PATIENT_ID_EXIST 9

/**
 * @def     ERROR_PATIENT_ID_NOT_EXIST
 * @brief   Error code when a required patient ID cannot be found.
 */
#define ERROR_PATIENT_ID_NOT_EXIST 23

/**
 * @def     ERROR_MAX_PATIENT_CAPACITY
 * @brief   Error code when there is no more space to add new patients.
 */
#define ERROR_MAX_PATIENT_CAPACITY 10

/**
 * @def     VALID_PATIENT_ADD
 * @brief   Status code for successfully adding a patient.
 */
#define VALID_PATIENT_ADD 11

/**
 * @def     VALID_PATIENT_EDIT
 * @brief   Status code for successfully editing a patient's information.
 */
#define VALID_PATIENT_EDIT 12

/**
 * @def     VALID_RESERVATION_ADD
 * @brief   Status code for successfully booking a reservation.
 */
#define VALID_RESERVATION_ADD 13

/**
 * @def     VALID_RESERVATION_CANCEL
 * @brief   Status code for successfully canceling a reservation.
 */
#define VALID_RESERVATION_CANCEL 14

/**
 * @def     INVALID_CHOICE
 * @brief   Error code for selecting an invalid menu option.
 */
#define INVALID_CHOICE 255

/**
 * @def     NULL_POINTER_TO_INPUT_PASSWORD
 * @brief   Error code when the password input pointer is null.
 */
#define NULL_POINTER_TO_INPUT_PASSWORD 0

/**
 * @def     NULL_POINTER_TO_INVALID_PASSWORD
 * @brief   Error code indicating a memory error during password validation.
 */
#define NULL_POINTER_TO_INVALID_PASSWORD 200

/**
 * @enum    SYSTEM_Sgin_t
 * @brief   Defines the types of users that can log into the system.
 */
typedef enum
{
	Admin = 1,
	User = 2
} SYSTEM_Sgin_t;

/**
 * @struct  System_t
 * @brief   Holds the main configuration and state of the system.
 */
typedef struct
{
	SYSTEM_Sgin_t SginType;
	u8 password[MAX_SYSTEM_PASS_LEN];

} System_t;

/**
 * @fn      SYSTEM_voidInit
 * @brief   Initializes the clinic reservation system.
 * @details Sets up the default password and initializes the patient and reservation databases.
 * @return  void
 */
void SYSTEM_voidInit();

/**
 * @fn      SYSTEM_voidStartProgram
 * @brief   Starts the main program loop.
 * @details Displays the main menu, takes user input, and routes to Admin or User modes.
 * @return  void
 */
void SYSTEM_voidStartProgram();

/**
 * @fn      SYSTEM_u8SginIn
 * @brief   Routes the user to the correct mode based on their selection.
 * @param   SginType The user type (Admin or User).
 * @return  The login status (VALID_LOGIN or INVALID_LOGIN).
 */
u8 SYSTEM_u8SginIn(SYSTEM_Sgin_t SginType);

/**
 * @fn      SYSTEM_u8AdminIn
 * @brief   Enters the Admin mode.
 * @details Checks the password, then displays the admin menu for managing patients and reservations.
 * @return  The login status (VALID_LOGIN or INVALID_LOGIN).
 */
u8 SYSTEM_u8AdminIn();

/**
 * @fn      SYSTEM_u8UserIn
 * @brief   Enters the User mode.
 * @details Displays the user menu for viewing patients and reservations.
 * @return  The login status (VALID_LOGIN).
 */
u8 SYSTEM_u8UserIn();

/**
 * @defgroup UserFunctions
 * @brief    Functions available in User Mode.
 * @{
 */
		/**
		 * @fn      SYSTEM_u8DisplayPatientInfo
		 * @brief   Displays the information of a specific patient.
		 * @details Prompts the user for a patient ID and prints the details if found.
		 * @return  Status code indicating success or invalid ID.
		 */
		u8 SYSTEM_u8DisplayPatientInfo();

		/**
		 * @fn      SYSTEM_voidDisplayReservationInfo
		 * @brief   Displays the current schedule of all reservations.
		 * @details Prints the times slots and whether they are reserved or empty.
		 * @return  void
		 */
		void SYSTEM_voidDisplayReservationInfo();
/**
 * @}
 */

/**
 * @defgroup Admin functions
 * @brief    Functions available in Admin Mode.
 * @{
 */
		/**
		 * @fn      SYSTEM_u8InputPassword
		 * @brief   Takes the password input from the user.
		 * @param   str_password Pointer to the array where the inputted password will be stored.
		 * @return  Status code indicating success or a null pointer error.
		 */
		u8 SYSTEM_u8InputPassword(u8 *str_password);

		/**
		 * @fn      SYSTEM_u8CheckPassword
		 * @brief   Validates the entered password against the system password.
		 * @details Gives the user a limited number of trials to enter the correct password.
		 * @return  Status code indicating VALID_PASSWORD or INVALID_PASSWORD.
		 */
		u8 SYSTEM_u8CheckPassword();

		/**
		 * @fn      SYSTEM_u8AddPatientInfo
		 * @brief   Creates a new patient record.
		 * @details Prompts the admin for new patient details and saves them to the system.
		 * @return  Status code indicating success or failure.
		 */
		u8 SYSTEM_u8AddPatientInfo();

		/**
		 * @fn      SYSTEM_u8EditPatientInfo
		 * @brief   Edits an existing patient record.
		 * @details Prompts the admin for a patient ID, then asks for new details to update the record.
		 * @return  Status code indicating success or an invalid patient ID.
		 */
		u8 SYSTEM_u8EditPatientInfo();

		/**
		 * @fn      SYSTEM_u8AddReservation
		 * @brief   Reserves a time slot for a patient.
		 * @details Prompts the admin for a patient ID and a desired time slot to book.
		 * @return  Status code indicating success or failure.
		 */
		u8 SYSTEM_u8AddReservation();

		/**
		 * @fn      SYSTEM_u8CancelReservation
		 * @brief   Cancels a previously booked reservation.
		 * @details Prompts the admin for a time slot to clear and make available again.
		 * @return  Status code indicating success or failure.
		 */
		u8 SYSTEM_u8CancelReservation();
/**
 * @}
 */

#endif