#!/bin/bash
input="./words.txt"
while IFS= read -r line
do
  echo "$line"
done < "$input"
