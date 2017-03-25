#!/bin/bash
SOURCE_FILE=~/LeetCode/README.md
DIR=`cd $(dirname ${1}) && pwd -P`
FILE=${DIR}/$(basename ${1})
URL=`grep Source ${FILE} | awk '{print $2}' | dos2unix`
#title_str=`curl ${URL} | grep -A2 question-title`

#dirname ${1} | sed "s/\.//g; s/_/ /g; s/0//g" > tmp
echo ${DIR} | sed "s/.*LeetCode\///g; s/_/ /g; s/0//g" > tmp
NUM=`awk '{print $1}' tmp`
TITLE=`awk '{print $2,$3}' tmp`
rm tmp

DIFFICULTY=`grep Difficulty ${FILE} | awk '{print $2}' | dos2unix`
FILE=`echo ${FILE} | sed "s/.*LeetCode/\./"`
TIME=`date "+%Y/%m/%d"`
sed -i.bak '/insert flag/i\'$''"|${NUM}|[${TITLE}][${NUM}]|[C++](${FILE})|${DIFFICULTY}|${TIME}|"$'\n' ${SOURCE_FILE}
echo "[${NUM}]:${URL}" >> ${SOURCE_FILE} 
