/**
 * @file	main.c
 * @brief	The main function that calls the system start program function
 * @author 	Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include <stdio.h>
#include "STD_TYPES.h"
#include "SYSTEM_interface.h"

int main()
{
    // Start the main system program loop
    SYSTEM_voidStartProgram();
    
    return 0;
}