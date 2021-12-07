#!/bin/bash

# finding the number of statements in file
# ./counter.sh

# part a
# grep -oc \\. myexamfile.txt

# part b
echo ""
echo "Statement/Line            Word Count:             Letter Count: "
echo "Number: "
# using the line number to line up with the tabular
awk '{ print NR,"\t\t\t" NF, "\t\t\t" length}' myexamfile.txt
