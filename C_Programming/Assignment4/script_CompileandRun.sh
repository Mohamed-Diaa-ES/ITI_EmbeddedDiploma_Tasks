#!/bin/bash
clear
echo "Choose what to compile"
echo "1 -> task 1"
echo "2-> Task 2"
echo "3 -> all tasks"

read WhichTask

if [[ "$WhichTask" == "1" ]]; then
echo -e "\nTask 1 Compilation and running "
gcc Task1.c -o Taskexe/Task1.exe 

./Taskexe/Task1.exe

elif [[ "$WhichTask" == "2" ]]; then
echo -e "\nTask 2 Compilation and running "

gcc Task2.c -o Taskexe/Task2.exe 

./Taskexe/Task2.exe
elif [[ "$WhichTask" == "3" ]]; then
echo -e "\nTask 1 Compilation and running "
gcc Task1.c -o Taskexe/Task1.exe 

./Taskexe/Task1.exe
echo -e "\nTask 2 Compilation and running "

gcc Task2.c -o Taskexe/Task2.exe 

./Taskexe/Task2.exe
fi





