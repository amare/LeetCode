#/!bin/bash
echo "file name: $0"

git status -s | 

perl ./Scripts/mysecondperl.pl |

while read line
do
#echo $line
git add $line
read processed_line
#echo "add $processed_line"
git commit -m "add $processed_line"
done

git push
#rm tmp
