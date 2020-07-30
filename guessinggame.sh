#! /bin/bash

# The function check_num takes user input and validates whether the input is a number
	function check_num {
		read -p "Enter the number of files in the directory: " file_num_check
		while [[ ! $file_num_check =~ ^[0-9]+$ ]]
		do
			echo "Uh-oh. You should enter a number (base-10)."
			read -p "Enter the number of files again: " file_num_check
		done
	}	

# The function guess_game loops until the user guesses the number of files correctly
	function guess_game {
		check_num
		if [[ $file_num_check -ne $file_num_act ]]; then
			while [[ $file_num_check -ne $file_num_act ]]
			do
				if [[ $file_num_check -lt $file_num_act ]]; then
					echo "You guessed too low."
				else 
					echo "You guessed too high."
				fi
				
				check_num
			done
			echo "Congratulations, you guessed correctly!"
		fi
	}

	echo "Welcome to the file guessing game."
	echo "Guess the number of files in the directory correctly!"
	
	# Calculating the actual number of files in the current directory.
	file_num_act=$(ls -al | grep -e "^-" | wc -l)
	
	# Initialising a global varible for the functions
	file_num_check=0
	# Calling the function guess_game
	guess_game