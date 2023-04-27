#!/bin/bash

echo 'Hello'
echo 'Путь до файла:'
read file
if [[ -z $file ]] 
then 
    echo "Путь не задан"
    exit
fi
if ! [ -e $file ]
then 
   echo "Такого файла нет"
   exit
fi 

echo 'Искомая строка:'

read search
if [[ -z $search ]] 
then 
    echo "Задана пустая строка"
    exit
fi
if ! grep -q $search $file 
then 
    echo "Такой строки нет"
    exit
fi


echo 'Замена для строки:'
read replace

sed -i ''  "s/$search/$replace/" $file 

datte=$( stat -f %Sm -t %Y-%m-%d $file )
timme=$( stat -f %Sm -t %H:%M $file )
sizes=$( du $file | cut -f 1 )
bite=$(($sizes / 8))
sum=$( shasum -a 256 $file | cut -b 1-64 )
result="$file - $bite - $datte $timme - $sum - sha256"

echo $result >> ./files.log





