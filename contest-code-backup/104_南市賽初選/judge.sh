#!/bin/bash

if [[ -d "$1" && -x "$2" ]]
then
  path=$(realpath "$1")
  exe=$(realpath "$2")

  for infile in $(ls "$path"/*.in)
  do
    echo "$infile"

    input=$(tr -d "\r" < "$infile")
    expected=$(tr -d "\r" < "$(sed 's/in/out/' <<< $infile)")
    output=$("$exe" <<< "$input")

    if [[ "$output" == "$expected" ]]
    then
      echo "AC"
    else
      echo "WA"
      echo "Input:           $input"
      echo "Expected Output: $expected"
      echo "Real Output:     $output"
    fi

    echo
  done
else
  echo "Usage: $0 PATH EXECUTABLE"
fi