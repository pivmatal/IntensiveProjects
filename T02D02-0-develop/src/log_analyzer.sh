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


obkolvo=$( wc -l $file | awk '{print $1}' )
uniq=$( sort $file | awk '{print $1}' | uniq -u | wc -l | xargs )
edits=$( sort $file | awk '{print $8}' | uniq -u | wc -l | xargs )

let obkolvo++ 
let uniq++
let edits--

echo $obkolvo $uniq $edits

