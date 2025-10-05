#!/bin/sh

SLEEP=0
if [ "$#" -gt 0 ]; then
	SLEEP=$1
fi

draw_symb() {
  tput cup $(($1 - 1)) $(($2 - 1))
  echo -n $3
  sleep $SLEEP
}

tput clear

row=1
while IFS= read -r line; do
  col=1
  string_length=${#line}
  while [ $col -le $string_length ]
  do
    char=$(echo "$line" | cut -b "$col")
    case $char in
      " ")
      ;;
      *)
      echo "$row $col $char"
      ;;
    esac
    col=$(($col + 1))
  done
  row=$(($row + 1))
done | shuf | while IFS= read -r row col char; do
  draw_symb $row $col $char
done
tput cup $(($(tput lines) - 1)) 0
