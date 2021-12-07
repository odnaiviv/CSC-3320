#!/bin/bash

# calculator that can add, subtract, multiply, divide, and modulo with cancel and clear features
# ./ calculator

echo "========================="
echo "    Simple Calculator    "
echo "========================="

results=0
input="no"

while [ $input = "no" ]
do
	# displaying list of operations calculator can do
	echo "Generating Simple Calculator Operations..."
	echo ""
	echo "1.	Addition"
	echo "2.	Subtraction"
	echo "3.	Multiplication"
	echo "4.	Division"
	echo "5.	Modulo"
	echo "	clear"
	echo "Enter Option(1-5) or 'clear': "
	read option
	case $option in 
1)
# user input numbers
echo "Enter First Number: "
read num1
echo "Enter Second Number: "
read num2
# calculating by addition & printing results
results=$(echo "scale=1; $num1 + $num2" | bc)
echo "$num1 + $num2 = " $results;;

2)
echo "Enter First Number: "
read num1
echo "Enter Second Number: "
read num2
# calculating by subtraction & printing results
results=$(echo "scale=1; $num1 - $num2" | bc)
echo "$num1 - $num2 = " $results;;

3)
echo "Enter First Number: "
read num1
echo "Enter Second Number: "
read num2
# calculating by multiplication & printing results
results=$(echo "scale=1; $num1 * $num2" | bc)
echo "$num1 * $num2 = " $results;;

4)
echo "Enter First Number: "
read num1
echo "Enter Second Number: "
read num2
# calculating by division & printing results
results=$(echo "scale=1; $num1 / $num2" | bc)
echo "$num1 / $num2 = " $results;;

5)
echo "Enter First Number: "
read num1
echo "Enter Second Number: "
read num2
# calculating by modulo & printing results
results=$(echo "scale=1; $num1 % $num2" | bc)
echo "$num1 % $num2 = " $results;;

clear)
# clearing calculator
clear ;;

*)echo "ERROR! Invalid option; try again: "
esac

# asking if user wants to cancel (yes) or continue (no)
echo "Cancel Session?(yes/no): "
read input
if [ $input != "no" ]
then
	exit
fi
done
