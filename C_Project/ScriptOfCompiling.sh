#!/bin/bash

SOURCES=(
        "ReservationInterface/Reservation_interface.c"
        "SystemInterface/SYSTEM_interface.c"
        "PatientInterface/PATIENT_interface.c"
        "main.c"
)
Includes=(
        "-ILIB"
        "-IReservationInterface"
        "-ISystemInterface"
        "-IPatientInterface"
)

gcc "${Includes[@]}" "${SOURCES[@]}" -o prog.exe

clear

./prog.exe