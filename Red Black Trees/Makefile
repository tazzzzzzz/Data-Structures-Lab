
RBTProg : RBT_Driver.o RBT_Utils.o 
	gcc -o RBTProg RBT_Driver.o RBT_Utils.o 	
RBT_Driver.o : RBT_Driver.c RBT_Header.h
	gcc -c RBT_Driver.c
RBT_Utils.o : RBT_Utils.o RBT_Header.h
	gcc -c RBT_Utils.c
clean :
	rm RBTProg *.o 