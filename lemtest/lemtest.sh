#!/bin/bash
G='\033[0;32m'
P='\033[0;35m'
B='\033[0;34m'
Z1='\033[48;5;152m'
Z2='\033[48;5;190m'
C='\033[0;36m'
NO_COLOR='\033[0m'

clear
if (( $# < 2 )); then
echo -e "${B}${Z2}
 USAGE: ${G} ****************************************\n
${NO_COLOR}Make sure you have the ${Z1} generator ${NO_COLOR}
int this directory with this ${Z1} lemtest.sh ${NO_COLOR}.
Place this directory in the same directory with
your ${Z1} lem-in ${NO_COLOR}.\n
./lemtest.sh [generator option] [rounds]\n
generator options:\n
flow-ten
flow-thousand
big
big-superposition\n
${G}*************************************************\n"
        exit 0
        fi
ARG=$1
echo " "
echo -e "   🐜                     $2 rounds"
echo -e "  ${B}${Z2} $ARG ${NO_COLOR}\n"
        printf "\r"
echo -e -n "${NO_COLOR}     request "
        printf "\r\t\t"
        echo -n "you "
        printf "\r\t\t\t"
        echo -e -n "time "
        printf "\r\t\t\t\t"
        echo -e "difference "
	echo " ----------------------------------------"
i=1;
a=0;
MIN=1000;
MAX=-1000;
SLOW=0;
while [ $i -le $2 ]
do
        ./generator --$ARG > mapfile;
        { time -p ../lem-in < mapfile > resfile; } 2>&1 | grep real | awk '{print $2}' > timefile
	ALL=$(wc -l "mapfile" | awk '{print $1}')
        RES=$(wc -l "resfile" | awk '{print $1}')
        REQ=$(head -5 'mapfile' |  grep 'require' | awk '{print $8}')
        LINES=$(( $RES - $ALL - 1 ))
        DIF=$(($LINES - $REQ))
	if (( $DIF < $MIN ))
	then
	MIN=$(($DIF))
	fi
	if (( $DIF > $MAX ))
	then
	MAX=$(($DIF))
	fi
	TIME=$(awk 'NR==1' timefile)
        echo -e -n "${NO_COLOR} $i. "
        printf "\r\t"
	echo -e -n "${NO_COLOR}$REQ "
        printf "\r\t\t"
        echo -n "$LINES "
        printf "\r\t\t\t"
	NUM=$(head -c1 timefile)
	NUM2=$(cut -c3 timefile) 
	NUM3=$(cut -c4 timefile) 
	if (( $NUM > 2 && ($NUM2 > 0 || $NUM3 > 0))); then
        echo -e -n "${B}${Z1}$TIME${NO_COLOR} "
        ((SLOW++))
	else
        echo -e -n "${NO_COLOR}$TIME "
	fi
        printf "\r\t\t\t\t\t"
        echo -e "${G}$DIF "
        ((a+=$DIF))
        ((i++))
done
((i--))
echo -e  "${NO_COLOR}"
printf "\r\t\t-------------------------\n\n"
b=$(($a/$i))
printf "\t\t"
echo -n -e "average: "
printf "\r\t\t\t\t\t"
echo -e "$b\n"
printf "\r\t\t"
echo -e -n "min difference:"
printf "\r\t\t\t\t\t"
echo -e "$MIN"
printf "\r\t\t"
echo -e -n "max difference: "
printf "\r\t\t\t\t\t"
echo -e "$MAX\n"
printf "\r\t"
echo -e -n "slower than ${B}${Z1} 3.00 ${NO_COLOR}: "
printf "\r\t\t\t\t"
echo -e -n "$SLOW "
if (( $SLOW == 1 )); then
echo -e "time\n\n\n"
else
echo -e "times\n\n\n"
fi
rm mapfile
rm resfile
rm timefile
#rm timefile
