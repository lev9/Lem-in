# Lem-in

- a Hive Helsinki school algorithm project Lem-in

- a bunch of ants finding their way through an ant farm defined in a specific ant farm data form. Ant farms rooms are linked to each other with tubes. Each room can have a limitless amount of rooms linked to it. In the beginning all ants are in start room. On each round, each ant can make one move to a free linked room. Goal is to get all ants into end room with as few rounds as possible.   


- usage (unvalid maps return ERROR; error specifications to be added):

		./lem-in < maps/[map]

- use map generator (options: flow-one / flow-ten / flow-thousand / big / big-superposition):

		cp lemtest/generator ./
		./generator --[option] | ./lem-in


- visual (press space to move ants):

		./lem-in < maps/[map] | vizu/visu

- for strecthed visual: 

		./generator --big-superposition | ./lem-in | vizu/visu 1

- to print stats with solution (with no visual), modify lem.h & recompile:
		
		# define ANTCOUNT 1
		make re

- test time & accuracy (first define ANTCOUNT back to 0):

		cd lemtest
		./lemtest.sh 	(for instructions)
		./lemtest.sh [generator option] [rounds]

- depending on the amount of ants and the ant farm structure, the shortest way isn't necessarily the fastest (upper picture). A small ant farm & a larger ant farm: 
<img align="left" width="620" height="620" SRC="pics/lem_1.png">
<img align="left" width="620" height="620" SRC="pics/lem_2.png">
