##########################################################
# Created by: rtarkunde                                  #
# Created on: Friday 02 December 2022 02:06:54 PM IST #
##########################################################


SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
CFLAGS = -c -g -Wall -I${INCLUDEDIR}


all:
	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${CFLAGS}  ${SRCDIR}/menu.c -o ${OBJDIR}/menu.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/utility.o ${OBJDIR}/menu.o -o ${BINDIR}/IOTDataLogger.bin


clean:

	rm ${OBJDIR}/main.o ${OBJDIR}/utility.o ${OBJDIR}/menu.o ${BINDIR}/IOTDataLogger.bin


#################### End of Makefile #####################
