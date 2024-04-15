#!/bin/bash

#create a new database file
newdb()
{
	printf "%s\n" "$2" > "$1"
	printf "New Database created\n\n"
}

#add a record to an existing databse file
newrecord()
{
	#check for valid arguments to append to the database
	if [[ "$4" -gt 1921 && "$4" -lt 2029 ]]; then
		if [[ ! -z "$2" && ! -z "$3" && ! -z "$5" ]]; then
			printf "%s, %s, %s, %s\n" "$2" "$3" "$4" "$5" >> "$1"
			printf "Successfully added a record to the database\n\n"

		else
			printf "ERROR: the make, model, and color must be strings with length >0\n"
			exit 1

		fi

	else
		printf "ERROR: the year of the car must be >1921 and <2029\n"
		exit 1

	fi
}

#show records found in an existing database
show()
{
	#check if user does not specify
	if [ $# = 1 ]; then
		printf "ERROR: specify all, single #, or range # #\n"
		exit 1

	fi

	#check against all, single, and range
	if [ "$2" = "all" ]; then
		cat "$1"
		printf "\n"

	elif [ "$2" = "single" ]; then
		sed -n $(($3 + 1))p "$1"
		printf "\n"

	elif [ "$2" = "range" ]; then
		sed -n $(($3 + 1)),$(($4 + 1))p "$1"
		printf "\n"

	else
		#catching error if incorrect input
		printf "ERROR: invalid display argument: %s\n" "$2"
		exit 1

	fi
}

#delete records from an existing database
delete()
{
	#check if user does not specify
	if [ $# = 1 ]; then
		printf "ERROR: specify all, single #, or range # #\n"
		exit 1

	fi

	#check against all, single, and range to delete lines
	if [ "$2" = "all" ]; then
		sed -i '1!d' "$1"
		printf "All records deleted\n\n"

	elif [ "$2" = "single" ]; then
		sed -i $(($3 + 1))d "$1"
		printf "1 record deleted\n\n"

	elif [ "$2" = "range" ]; then
		sed -i $(($3 + 1)),$(($4 + 1))d "$1"
		printf "$(($4 - $3 + 1)) record(s) have been deleted\n\n"

	else
		#incorrect arguments
		printf "ERROR: invalid delete argument: %s\n" "$2"
		exit 1

	fi
}

#count and print the number of rows in an existing database
count()
{
	if [[ -f "$1" && -r "$1" ]]; then
		#using wc -l and piping it to awk
		awks='{ print $1 }'
		temp=$(wc -l $1 | awk "$awks")
		printf "$((temp - 1))\n\n"

	else
		#check if the file entered is a readable file
		printf "ERROR: %s is not a readable file\n" "$1"

	fi
}

#check if in interactive mode
if [ ! $# = 0 ]; then #not interactive
	if [ $# = 1 ]; then #no command specified
		printf "ERROR: please specify a command and a database\n\n"
		exit 1

	fi

	if [ $2 = "newdb" ]; then #newdb
		if [ $# = 2 ];then #no name specified
			newdb "$1" "Untitled Database"

		else
			newdb "$1" "$3"

		fi

	elif [ $2 = "newrecord" ]; then #newrecord
		if [ $# = 6 ]; then #if all params are entered
			newrecord "$1" "$3" "$4" "$5" "$6"

		else #all parts are not specified
			printf "ERROR: newrecord requires 5 parameters\n"
			exit 1

		fi

	elif [ "$2" = "show" ]; then #show
		show "$1" "$3" "$4" "$5"

	elif [ "$2" = "delete" ]; then #delete
		delete "$1" "$3" "$4" "$5"

	elif [ "$2" = "count" ]; then #count
		count "$1"

	else #if command is invalid
		printf "ERROR: invalid command. Not: %s\n" "$2"
		exit 1

	fi

else #interactive mode
	#loop until cont != y
	cont="y"

	while [ $cont = "y" ]; do #database name must be specified
		read -p "filename of dataase to use: " dbname
		while [ -z "$dbname" ]; do
			read -p "You must specify the name of a database: " dbname

		done

		#get the command
		read -p "command? newdb, newrecord, show, delete, count: " cmd

		if [ "$cmd" = "newdb" ]; then #newdb
			read -p "Header for the database: " header #read params needed for newdb
			if [ -z "$header" ]; then #check if header is specified
				header="Untitled Database"

			fi

			newdb "$dbname" "$header"

		elif [ $cmd = "newrecord" ]; then #newrecord
			#read in all params
			read -p "Make: " carmake
			read -p "Model: " model
			read -p "Year (1922-2028): " year
			read -p "Color: " color
			newrecord "$dbname" "$carmake" "$model" "$year" "$color"

		elif [ $cmd = "show" ]; then #show
			#read in show params
			read -p "How many to show (all, single, range): " howmany

			#check how many entires to show
			if [ $howmany = "single" ]; then
				read -p "Which single: " single
				show "$dbname" "$howmany" "$single"

			elif [ $howmany = "range" ]; then
				read -p "Beginning of range: " beg
				read -p "End of range: " end
				show "$dbname" "$howmany" "$beg" "$end"

			elif [ $howmany = "all" ]; then
				show "$dbname" "$howmany"

			else #invalid argument
				printf "ERROR: %s is not valid\n" "$howmany"

			fi

		elif [ $cmd = "count" ]; then #count
			count "$dbname"

		elif [ $cmd = "delete" ]; then #delete
			#read in params
			read -p "How many to delete (all, single, range): " howmany

			#check how many entries to delete
			if [ $howmany = "single" ]; then
				read -p "Which single: " single
				delete "$dbname" "$howmany" "$single"

			elif [ $howmany = "range" ]; then
				read -p "Beginning of range: " beg
				read -p "End of range: " end
				delete "$dbname" "$howmany" "$beg" "$end"

			elif [ $howmany = "all" ]; then
				delete "$dbname" "$howmany"

			else #invalid argument
				printf "ERROR: %s is not valid\n" "$howmany"

			fi

		else #invalid command
			printf "ERROR: invalid command. Not: %s\n" "$cmd"

		fi



		#try to keep looping
		read -p "More? (y/n): " cont

	done

fi

exit 0 #success :)




