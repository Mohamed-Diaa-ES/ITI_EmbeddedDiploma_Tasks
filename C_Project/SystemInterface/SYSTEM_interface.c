/**
 * @file
 * @brief
 * @details
 * @author Mohammed Diaa mohammeddiaato@gmail.com
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "PATIENT_interface.h"
#include "RESERVATION_interface.h"
#include "SYSTEM_interface.h"
/**
 * @var
 * @brief
 */
static System_t MyClinicSystem;

void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
        )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
        )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

void SYSTEM_voidInit()
{
    // Initialize The System Parts
    PATIENT_voidInit();
    RESERVATION_voidInit();
    
    // Set default password and mode
    strcpy((char*)MyClinicSystem.password, "1234");
    MyClinicSystem.SginType = User;
}

void SYSTEM_voidStartProgram()
{
    SYSTEM_voidInit();
    u32 choice;
    u8 Response;
    while (1) {
        ClearScreen();
        printf("\n=== Clinic Reservation System ===\n");
        printf("1. Sgin in as Admin\n");
        printf("2. Sgin in as User\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if(scanf("%d", &choice) < 1) 
        {
            scanf("%*[^\n]"); 
            choice = INVALID_CHOICE;
        }
        
        switch (choice) {
            case 2:
            case 1:
                Response = SYSTEM_u8SginIn((SYSTEM_Sgin_t)choice);
                if(Response == INVALID_LOGIN)
                {
                    ClearScreen();
                    printf("\n===You have used all three trails.have a nice day===\n");
                    return ;
                }
                break;
            case 0:
                printf("Exiting program.\n");
                return ;
            default:
                printf("Invalid choice. Try again.\n");
                Sleep(500);
        }
    }	
}

u8 SYSTEM_u8SginIn(SYSTEM_Sgin_t SginType)
{
    if (SginType == Admin)
    {
        return SYSTEM_u8AdminIn();
    }
    else if (SginType == User)
    {
        return SYSTEM_u8UserIn();
    }
    return INVALID_LOGIN;
}

u8 SYSTEM_u8AdminIn()
{
    u32 choice;
    u8 Response;
    
    // Check password before entering Admin Mode
    Response = SYSTEM_u8CheckPassword();
    if (Response == INVALID_PASSWORD)
    {
        return INVALID_LOGIN;
    }else if (Response==NULL_POINTER_TO_INVALID_PASSWORD)
	{
		printf("\nMEMORY_ERROR_REOPEN_THE_PROGRAM_LATER!!");
		exit(0);
	}
    
    while (1) {
        ClearScreen();
        printf("\n=== Clinic Reservation System ===\n");
        printf("===          AdminMode        ===\n");
        printf("1. Add patient record\n");
        printf("2. Edit patient record\n");
        printf("3. Book reservation\n");
        printf("4. Cancel reservation\n");
        printf("0. MainMenu\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice) < 1) 
        {
            scanf("%*[^\n]"); 
            choice = INVALID_CHOICE;
        }

        switch (choice) {
            case 1:
                SYSTEM_u8AddPatientInfo();
                break;
            case 2:
                SYSTEM_u8EditPatientInfo();
                break;
            case 3:
                SYSTEM_u8AddReservation();
                break;
            case 4:
                SYSTEM_u8CancelReservation();
                break;
            case 0:
                return VALID_LOGIN;
            default:
                printf("Invalid choice. Try again.\n");
        }
        Sleep(1500); // Pause to allow admin to read results before clearing screen
    }
    return VALID_LOGIN;
}

u8 SYSTEM_u8CheckPassword()
{
    u8 inputPassword[MAX_SYSTEM_PASS_LEN];
    
    for(u8 Tests = 0; Tests < MAX_PASSWORD_TESTS; Tests++)
    {
        ClearScreen();
        printf("\n=== Clinic Reservation System ===\n");
        printf("===          AdminMode        ===\n");
        printf("Enter Password: ");		
        
        // Use the interface function to get the input
    	if(SYSTEM_u8InputPassword(inputPassword)==NULL_POINTER_TO_INPUT_PASSWORD) 
			return NULL_POINTER_TO_INVALID_PASSWORD;


        
        if (strcmp((char*)inputPassword, (char*)MyClinicSystem.password) == 0)
        {
            return VALID_PASSWORD;
        }
        else
        {
            printf("Invalid Password.\n");
            Sleep(1000);
        }
    }
    
    return INVALID_PASSWORD;
}

u8 SYSTEM_u8UserIn()
{
    u32 choice;
    while (1) {
        ClearScreen();
        printf("\n=== Clinic Reservation System ===\n");
        printf("===          UserMode         ===\n");
        printf("1. View patient record\n");
        printf("2. View today's reservations\n");
        printf("0. MainMenu\n");
        printf("Enter choice: ");
        
        if(scanf("%d", &choice) < 1) 
        {
            scanf("%*[^\n]"); 
            choice = INVALID_CHOICE;
        }

        switch (choice) {
            case 1:
                SYSTEM_u8DisplayPatientInfo();
                break;
            case 2:
                SYSTEM_voidDisplayReservationInfo();
                break;
            case 0:
                return VALID_LOGIN;
            default:
                printf("Invalid choice. Try again.\n");
        }
        Sleep(2500); // Pause to allow user to read screen data
    }
    return VALID_LOGIN;
}

u8 SYSTEM_u8DisplayPatientInfo()
{
    u8 id[MAX_ID_SIZE];
    printf("Enter ID: ");
    scanf("%49s", id); // 49 is the maximum chars possible 
    
    u8 status = PATIENT_u8ViewPatientInfoByID(id);
    if (status != 1) // Assuming Success macro resolves to 1 based on your previous edit
    {
        printf("=== Error There is no patient with this id ===\n");
        return INVALID_PATIENT_ID;
    }
    return VALID_PATIENT_ID;
}

void SYSTEM_voidDisplayReservationInfo()
{
    RESERVATION_voidViewReservations();
}

u8 SYSTEM_u8AddPatientInfo()
{	
    u8 id[MAX_ID_SIZE];
    u8 name[MAX_NAME_SIZE];
    u32 age;
    u8 genderInput[10];
    u8 gender;

    printf("Enter ID: ");
    scanf("%49s", id); // 49 is the maximum chars possible 
    
    printf("Enter Name: ");
    scanf("%49s", name); // 49 is the maximum chars possible 
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter Gender: ");
    scanf("%9s", genderInput); // 9 is the maximum chars possible 
    
    // Map text to enum
    if (genderInput[0] == 'm' || genderInput[0] == 'M')
    {
        gender = MALE;
    }
    else
    {
        gender = FEMALE;
    }
    
    u8 status = PATIENT_u8AddPatientInfo(id, name, age, gender);
    if (status == 1) // Success
    {
        printf("=== Done Prosess ===\n");
        return VALID_PATIENT_ADD;
    }
    
    printf("=== Error Cannot Add Patient (ID may exist or limit reached) ===\n");
    return ERROR_MAX_PATIENT_CAPACITY; // Or return generic error
}

u8 SYSTEM_u8EditPatientInfo()
{
    u8 id[MAX_ID_SIZE];
    u8 name[MAX_NAME_SIZE];
    u32 age;
    u8 genderInput[10];
    u8 gender;

    printf("Enter ID: ");
    scanf("%49s", id);// 49 is the maximum chars possible 
    
    // Validate ID exists first before asking for new data
    Patient_t* p = PATIENT_xPGetPatientFromID(id);
    if (p == NULL)
    {
        printf("=== Error There is no patient with this id ===\n");
        return ERROR_PATIENT_ID_NOT_EXIST;
    }

    printf("Enter Name: ");
    scanf("%49s", name);    // 49 is the maximum chars possible 
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter Gender: ");
    scanf("%9s", genderInput);// 9 is the maximum chars possible 
    
    if (genderInput[0] == 'm' || genderInput[0] == 'M')
    {
        gender = MALE;
    }
    else
    {
        gender = FEMALE;
    }

    u8 status = PATIENT_u8EditPatientInfo(id, name, age, gender);
    if (status == 1) // Success
    {
        printf("=== Done Prosess ===\n");
        return VALID_PATIENT_EDIT;
    }
    return INVALID_PATIENT_ID;
}

u8 SYSTEM_u8AddReservation()
{
    u8 id[MAX_ID_SIZE];
    u32 slot;
    
    // Show available slots to the Admin first
    RESERVATION_voidViewReservations();
    
    printf("Enter ID To Book: ");
    scanf("%49s", id); // 49 is the maximum chars possible 
    
    Patient_t* patient = PATIENT_xPGetPatientFromID(id);
    if (patient == NULL)
    {
        printf("=== Error There is no patient with this id ===\n");
        return ERROR_PATIENT_ID_NOT_EXIST;
    }
    
    printf("Enter Time Slot To Book: ");
    if(scanf("%d", &slot) < 1) 
    {
        scanf("%*[^\n]"); 
    }
    
    // Validate slot time
    if (slot < 1 || slot > 5)
    {
        printf("=== Error Invalid Slot ===\n");
        return ERROR_RESERVATION_SLOT_NOT_EXIST;
    }
    
    u8 status = RESERVATION_u8AddReservation(patient, (RESERVATIONS_SlotsTimes)slot);
    if (status == RESERVATION_RESERVED)
    {
        printf("=== Done Prosess ===\n");
        return VALID_RESERVATION_ADD;
    }
    
    printf("=== Error This Reservation Already reserve ===\n");
    return ERROR_RESERVATION_BOOKED;
}

u8 SYSTEM_u8CancelReservation()
{
    u32 slot;
    
    // Display reservations so admin knows which slot to free
    RESERVATION_voidViewReservations();
    
    printf("Enter Time Slot TO Free: ");
    if(scanf("%d", &slot) < 1) 
    {
        scanf("%*[^\n]"); 
    }
    
    if (slot < 1 || slot > 5)
    {
        printf("=== Error Invalid Slot ===\n");
        return ERROR_RESERVATION_SLOT_NOT_EXIST;
    }
    
    u8 status = RESERVATION_u8CancelReservation((RESERVATIONS_SlotsTimes)slot);
    if (status == RESERVATION_UNRESERVED)
    {
        printf("=== Done Prosess ===\n");
        return VALID_RESERVATION_CANCEL;
    }
    
    printf("=== Error This Reservation Already empty ===\n");
    return ERROR_RESERVATION_EMPTY;
}

u8 SYSTEM_u8InputPassword(u8 *str_password)
{
    // Ensure the pointer is valid before writing to it
    if (str_password != NULL)
    {
        scanf("%99s", str_password);// 99 is the maximum chars possible 
        return 1; // Success
    }
    return NULL_POINTER_TO_INPUT_PASSWORD; // Error
}