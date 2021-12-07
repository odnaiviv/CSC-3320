#!/bin/bash

# helpme shell script
# ./helpme.sh

# man database file
mandatabase="mandatabase.txt"

echo -n "Enter the command for which help is needed: "
read command

# a man page for any command starts with COMMANDNAME(1) and ends with COMMANDNAME(1)

command=$(echo "$command" | tr a-z A-Z)

if [ -n "$(sed -n "/^$command(1)/,/$COMMAND(1)$/p" "$mandatabase" | more)" ]
then
        sed -n "/^$command(1)/,/$command(1)$/p" "$mandatabase" | more
else
        echo "Sorry, I cannot help you"
fi

exit 0
