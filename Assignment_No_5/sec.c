#!bin/bash

while true 
do

	echo "---------------------------------------------"
	echo "1.Date 2.Cal 3.Ls 4.pwd 5.exit"
	echo "---------------------------------------------"


	read -p "enter the choice (1-5): " choice

	case $choice in
		1) 
		   echo "Current date and time:"
		   date
		   ;;
		2)
		   echo "calender:"
		   cal
		   ;;
		3)
		   echo "listing file in current directory:"
		   ls
		   ;;
		4)
		   echo "current working directory:"
		   pwd
		   ;;
		5)
		   echo "Exiting the program. "
		   exit 0
		   ;;
		*)
		   echo "Invalid"
		   ;;
	esac 

	echo ""
done

                     
