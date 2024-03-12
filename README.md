# OS
How to complie : 
    - gcc -o ChocolateFactory charlie.c oompa_loompas.c children.c -pthread
Then  run  
    ./ChocolateFactory 4 1 10 100 1000 
    
Project Instruction: 
Bound Buffer Solution, a Producer-Consumer Problem, involves a producer who generates data and a consumer who processes the data. The data is stored in a shared buffer with a limited capacity. The buffer is responsible for handling the synchronisation and communication between the producer and the consumer processes:

Wonka Factory has two types of  Workers —oompa loompas and children

So the thing I that there are different types of colours for chocolate : 
ooma Loompas will  create a different  type of colour that is unique
 
And each child will create a box of candies of assorted colours. Oompa Loompas produce one candy at a time and then place the candy (when there is room) onto the assembly line (a limited-sized buffer). Children remove one candy at a time from the assembly line until they have enough candies to fill a box. Once a box of candies has been filled, the child will alert Wonka and begin filling a new box

Things to do: 
The  Glass which is the display: 
Wonka requires that the following controls for his factory be installed in his glass elevator: 
 o: the number of oompa loompa threads 
 c: the number of children threads 
 a: the size of the assembly line 
 n: the number of candies per box 
 t: the number of candies each   will produce


So at the start of the program your: 

Your executable should be named ChocolateFactory (The name must match


What to create  a file to produce a result : 

Charlie.c: 
Your main function will be responsible for the overall control of the factory: creating the assembly line (bounded-buffer array), spawning o oompa loompa, and c child workers (threads). Once all of the oompa loompas have finished producing candies, you must wait for all the candies remaining in the assembly line to get packaged then let the children go home for the day.


Oompa-loompas.c 
Each oompa loompa produces a candy of unique color and each candy is numbered sequentially. For example, oompa loompa 1 might produce candies: AliceBlue 1, AliceBlue 2, AliceBlue 3, … and oompa loompa 2 candies: PeachPuff 1, PeachPuff 2, PeachPuff 3, …, and so forth. You can assign any color you wish to each oompa Loompa but the names must be unique (so you can tell which oompa loompa produced which candy). After producing a candy, the oompa loompa will place it onto the assembly line (the bounded-buffer array). If the assembly line is full, the oompa loompa must wait until a slot 

children.c
Each child will extract candies one at a time from the assembly line (the bounded-buffer array). After retrieving n candies, the child should shout (print to stdout) the contents of the candy box: Wonka, I have a box of candies containing: Beige 2, Bisque 3, Black 9, … Bisque 10





Hint: 
man pthreads 
 Consider how structs can simplify your program 
 Use printf statements to help debug your program, be sure to indicate which thread your statement came from. You can comment out printf statements you don’t want to run in your final program 
 Look into a circular queue as the data structure of the bounded buffer 
 You will need statements for the following system calls — malloc, free (These are the C versions of new and delete. Note that free is on the man page of malloc

