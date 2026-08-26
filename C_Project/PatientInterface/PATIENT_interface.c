/**
 * @file	Patient_Interface.h
 * @brief	The implementation of the Patient_Interface .h file.
 * @details Implementing the functions needed to do the Patient realted oerations.
 * @author 	Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "PATIENT_interface.h"
/**
 * @var     Patients_List
 * @brief   Array that holds the records of all patients. It stores names, IDs, and ages.
 */
static Patient_t Patients_List[MAX_PATIENTS_SLOTS];

void PATIENT_voidInit()
{
    // Initialize all slots as unused
    for (u32 i = 0; i < MAX_PATIENTS_SLOTS; i++)
    {
        Patients_List[i].isUsed = 0;
    }
}

s64 PATIENT_s64GetPatientIndexById(u8* id)
{
    if (id == NULL) 
    {
        return -1;
    }
    
    for (u32 i = 0; i < MAX_PATIENTS_SLOTS; i++)
    {
        // Check if the slot is used and the ID matches
        if (Patients_List[i].isUsed == 1 && strcmp((char*)Patients_List[i].id, (char*)id) == 0)
        {
            return i;
        }
    }
    return -1;
}

Patient_t* PATIENT_xPGetPatientFromID(u8* id)
{
    if (id == NULL)
    {
        return NULL;
    }

    s64 index = PATIENT_s64GetPatientIndexById(id);
    if (index != -1)
    {
        return &Patients_List[index];
    }
    
    return NULL;
}

u8 PATIENT_u8ViewPatientInfoByID(u8* id)
{
    Patient_t* patient = PATIENT_xPGetPatientFromID(id);
    
    if (patient != NULL)
    {
        printf("ID: %s\n", patient->id);
        printf("Name: %s\n", patient->name);
        printf("Age: %d\n", patient->age);
        
        if (patient->gender == MALE) 
        {
            printf("Gender: MALE\n");
        } 
        else 
        {
            printf("Gender: FEMALE\n");
        }
        return Success; 
    }
    
    return PATIENTS_ID_ERROR;
}

u8* PATIENT_u8PGetPatientID(Patient_t* Patient)
{
    if (Patient != NULL)
    {
        return Patient->id;
    }
    return NULL;
}

u8 PATIENT_u8AddPatientInfo(u8* id, u8* name, u32 age, u8 gender)
{
    if (id == NULL || name == NULL) 
    {
        return PATIENTS_ADD_ERROR;
    }

    // Reject if the entered ID already exists 
    if (PATIENT_s64GetPatientIndexById(id) != -1)
    {
        return PATIENTS_ADD_ERROR; 
    }

    // Find the first empty slot to store the new patient
    for (u32 i = 0; i < MAX_PATIENTS_SLOTS; i++)
    {
        if (Patients_List[i].isUsed == 0)
        {
            strcpy((char*)Patients_List[i].id, (char*)id);
            strcpy((char*)Patients_List[i].name, (char*)name);
            Patients_List[i].age = age;
            Patients_List[i].gender = gender;
            Patients_List[i].isUsed = 1;
            
            return Success; 
        }
    }
    
    // Return error if maximum capacity is reached
    return PATIENTS_ADD_ERROR;
}

u8 PATIENT_u8EditPatientInfo(u8* id, u8* name, u32 age, u8 gender)
{
    if (id == NULL || name == NULL) 
    {
        return PATIENTS_EDIT_ERROR;
    }

    s64 index = PATIENT_s64GetPatientIndexById(id);
    
    // If patient ID exists, allow the edit
    if (index != -1)
    {
        strcpy((char*)Patients_List[index].name, (char*)name);
        Patients_List[index].age = age;
        Patients_List[index].gender = gender;
        
        return Success; 
    }
    
    // Incorrect ID / Patient does not exist
    return PATIENTS_EDIT_ERROR;
}