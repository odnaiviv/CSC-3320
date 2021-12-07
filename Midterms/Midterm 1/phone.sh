#!/bin/bash

# phone book utility shell script that manages the phone directory
# ./phonebook.sh

# phonebook filename
infile="phonebook.txt"
# displaying menu
menu() {
	echo ""
	echo "==================================="
	echo "      Phone Directory Manager      "
	echo "==================================="
	echo "1.	Display Phone Directory"
	echo "2.	Find People"
	echo "3.	Add a New Entry"
	echo "4.	Modify an Entry"
	echo "5.	Delete an Entry"
	echo "6.	Exit"
	echo ""
}

while [ "$option" != "6" ]
do
	# reset variables
	firstname=""
	lastname=""
	phone=""
	address=""

	oldfname=""
	oldlname=""
	oldphone=""
	oldaddress=""

	newfname=""
	newlname=""
	newphone=""
	newaddress=""

	case "$option" in
		1)
if [ -s "$infile" ]
then
	echo ""
	echo "Sorting by Last Name..."
	echo ""

	# sorting by last name
	sort -t":" -k2 "$infile" | column -s: -t | more
else
	echo ""
	echo "No Phone Directory '$infile' found."
fi

menu
echo -n "Enter option(1-6): "
read option
continue
;;

2)
if [ ! -r "$infile" ]
then
	echo ""
	echo "ERROR! You are not allowed to read '$infile'."
	echo ""

	exit 1
fi

echo ""

while [ -z "$firstname" ]
do
	echo -n "Enter First Name (type 'exit' to end): "
	read firstname

	if [ "$firstname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$lastname" ]
do
	echo -n "Enter Last Name (type 'exit' to end): "
	read lastname

	if [ "$lastname" = "exit" ]
	then
		exit 0
	fi
done

# removing extra spaces to clean up & make everything look neater
firstname=$(echo "$firstname" | tr -s ' ')
lastname=$(echo "$lastname" | tr -s ' ')

echo ""
entry=$(grep -iw "$firstname:$lastname" "$infile")

# if no match is found
if [ -z "$entry" ]
then
	echo "Info: No match found."

	menu
	echo -n "Enter option(1-6): "
	read option
	continue
else
	echo "$entry"
fi

menu
echo -n "Enter option(1-6): "
read option
continue
;;

3)
if [ ! -w "$infile" ]
then
	menu
	echo "ERROR! You are not allowed to read '$infile'."
	echo ""

	exit 1
fi

echo ""
while [ -z "$firstname" ]
do
	echo -n "Enter First Name (type 'exit' to end): "
	read firstname

	if [ "$firstname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$lastname" ]
do
	echo -n "Enter Last Name (type 'exit' to end): "
	read lastname

	if [ "$lastname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$phone" ]
do
	echo -n "Enter Phone # (type 'exit' to end): "
	read phone
	if [ "$phone" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$address" ]
do
	echo -n "Enter Address (type 'exit' to end): "
	read address
	if [ "$address" = "exit" ]
	then
		exit 0
	fi
done

echo "$firstname:$lastname:$phone:$address" >> "$infile"
echo ""
echo "Info: New Phone Added."

menu
echo -n "Enter option(1-6): "
read option

continue
;;

4)
if [ ! -w "$infile" ]
then
	echo ""
	echo "ERROR! You are not allowed to read '$infile'."
	echo ""

	exit 1
fi

echo ""

while [ -z "$oldfname" ]
do
	echo -n "Enter old First Name (type 'exit' to end): "
	read oldfname

	if [ "$oldfname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$oldlname" ]
do
	echo -n "Enter old Last Name (type 'exit' to end): "
	read oldlname

	if [ "$oldlname" = "exit" ]
	then
		exit 0
	fi
done

echo ""

while [ -z "$newfname" ]
do
	echo -n "Enter new First Name (type 'exit' to end): "
	read newfname

	if [ "$newfname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$newlname" ]
do
	echo -n "Enter new Last Name (type 'exit' to end): "
	read newlname

	if [ "$newlname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$newphone" ]
do
	echo -n "Enter new Phone # (type 'exit' to end): "
	read newphone

	if [ "$newphone" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$newaddress" ]
do
	echo -n "Enter new Address (type 'exit' to end): "
	read newaddress

	if [ "$newaddress" = "exit" ]
	then
		exit 0
	fi
done

# removing spaces again
oldfname=$(echo "$oldfname" | tr -s ' ')
oldlname=$(echo "$oldlname" | tr -s ' ')

echo ""
oldentry=$(grep -iw "$oldfname:$oldlname" "$infile")
newentry="$newfname:$newlname:$newphone:$newaddress"

# if no match is found
if [ -z "$oldentry" ]
then
	echo "Info: No match found."
	menu
	echo -n "Enter option(1-6): "
	read option
	continue
else
	sed -i "s/$oldentry/$newentry/" "$infile"
	echo "Info: Modified phone."
fi

menu
echo -n "Enter option(1-6): "
read option
continue
;;

5) echo ""
while [ -z "$firstname" ]
do
	echo -n "Enter First Name (type 'exit' to end): "
	read firstname

	if [ "$firstname" = "exit" ]
	then
		exit 0
	fi
done

while [ -z "$lastname" ]
do
	echo -n "Enter Last Name (type 'exit' to end): "
	read lastname

	if [ "$lastname" = "exit" ]
	then
		exit 0
	fi
done

# removing spaces again
firstname=$(echo "$firstname" | tr -s " ")
lastname=$(echo "$lastname" | tr -s " ")

# deleting line
tempfile=$(mktemp)
grep -iwv "$firstname:$lastname" "$infile" > "$tempfile"

# checking for rows deleted in tempfile
orginalrow=$(wc -l < "$infile")
temprow=$(wc -l < "$tempfile")

if [ "$orginalrow" -eq "$temprow" ]
then
	echo ""
	echo "No match found."

	menu
	echo -n "Enter option(1-6): "
	read option
	continue
else
	mv "$tempfile" "$infile"
	echo ""
	echo "Info: Deleted phone."

	echo -n "Enter option(1-6): "
	read option
	continue
fi
;;

6) echo ""
exit 0
;;

*) menu
echo -n "Enter option(1-6): "
read option
esac
done

echo ""
exit 0
