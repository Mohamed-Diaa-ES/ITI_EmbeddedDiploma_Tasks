/**
 * @file    PATIENT_interface.h
 * @brief   Header file for the Patient module.
 * @details Contains macros, structures, and function prototypes for managing patient data.
 * @author  Mohammed Diaa mohammeddiaato@gmail.com
 */
#ifndef PATIENT_H
#define PATIENT_H

/**
 * @def     PATIENTS_ID_ERROR
 * @brief   Error code for an invalid patient ID.
 */
#define PATIENTS_ID_ERROR (u8)0

/**
 * @def     PATIENTS_ADD_ERROR
 * @brief   Error code when failing to add a patient.
 */
#define PATIENTS_ADD_ERROR 0

/**
 * @def     PATIENTS_EDIT_ERROR
 * @brief   Error code when failing to edit a patient.
 */
#define PATIENTS_EDIT_ERROR 0

/**
 * @def     MAX_PATIENTS_SLOTS
 * @brief   Maximum number of patients the system can hold.
 */
#define MAX_PATIENTS_SLOTS 10

/**
 * @def     MAX_NAME_SIZE
 * @brief   Maximum number of characters allowed for a patient's name.
 */
#define MAX_NAME_SIZE 50

/**
 * @def     MAX_ID_SIZE
 * @brief   Maximum number of characters allowed for a patient's ID.
 */
#define MAX_ID_SIZE 50

/**
 * @def     Success
 * @brief   Status code indicating a successful operation.
 */
#define Success 1

/**
 * @enum    Gender_t
 * @brief   Defines the available genders for a patient.
 */
typedef enum
{
    MALE,
    FEMALE
} Gender_t;

/**
 * @struct  Patient_t
 * @brief   Structure holding all information for a single patient.
 */
typedef struct
{
    u8 id[MAX_ID_SIZE];
    u8 name[MAX_NAME_SIZE];
    u32 age;
    u8 gender;
    u8 isUsed;
} Patient_t;

/**
 * @fn      PATIENT_voidInit
 * @brief   Initializes the patient list.
 * @details Sets all patient slots as unused so they are ready to store new data.
 * @return  void
 */
void PATIENT_voidInit();

/**
 * @fn      PATIENT_u8ViewPatientInfoByID
 * @brief   Prints the patient details using their ID.
 * @details Finds the patient and prints their name, age, and gender.
 * @param   id Pointer to the patient's ID string.
 * @return  Status code indicating success or an ID error.
 */
u8 PATIENT_u8ViewPatientInfoByID(u8 *id);

/**
 * @fn      PATIENT_u8AddPatientInfo
 * @brief   Adds a new patient to the system.
 * @details Finds an empty slot and saves the new patient data. For example, it returns an error if the system is full or the ID already exists.
 * @param   id Pointer to the new patient's ID string.
 * @param   name Pointer to the new patient's name string.
 * @param   age The age of the new patient.
 * @param   gender The gender of the new patient.
 * @return  Status code indicating success or an add error.
 */
u8 PATIENT_u8AddPatientInfo(u8 *id, u8 *name, u32 age, u8 gender);

/**
 * @fn      PATIENT_u8EditPatientInfo
 * @brief   Updates an existing patient's data.
 * @details Finds the patient by ID and updates their information. For example, it changes their name or age.
 * @param   id Pointer to the existing patient's ID string.
 * @param   name Pointer to the updated name string.
 * @param   age The updated age.
 * @param   gender The updated gender.
 * @return  Status code indicating success or an edit error.
 */
u8 PATIENT_u8EditPatientInfo(u8 *id, u8 *name, u32 age, u8 gender);

/**
 * @fn      PATIENT_s64GetPatientIndexById
 * @brief   Finds the array position of a patient.
 * @details Searches the system to find where the patient is saved based on their ID.
 * @param   id Pointer to the patient's ID string.
 * @return  The index number of the patient in the array, or -1 if not found.
 */
s64 PATIENT_s64GetPatientIndexById(u8 *id);

/**
 * @fn      PATIENT_u8PGetPatientID
 * @brief   Gets the ID string of a patient.
 * @details Takes a patient structure and returns its ID.
 * @param   Patient Pointer to the patient structure.
 * @return  Pointer to the patient's ID string.
 */
u8 *PATIENT_u8PGetPatientID(Patient_t *Patient);

/**
 * @fn      PATIENT_xPGetPatientFromID
 * @brief   Gets a patient structure using their ID.
 * @details Finds the patient in the system and returns a pointer to all their data.
 * @param   id Pointer to the patient's ID string.
 * @return  Pointer to the patient structure, or NULL if not found.
 */
Patient_t *PATIENT_xPGetPatientFromID(u8 *id);

#endif