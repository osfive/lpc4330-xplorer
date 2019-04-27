APP =		lpc4330-xplorer
MACHINE =	arm

CC =		${CROSS_COMPILE}gcc
LD =		${CROSS_COMPILE}ld
OBJCOPY =	${CROSS_COMPILE}objcopy

OBJDIR =	obj

LDSCRIPT =	${CURDIR}/ldscript

OBJECTS =	main.o						\
		osfive/sys/arm/nxp/lpc43xx_scu.o		\
		osfive/sys/arm/nxp/lpc43xx_usart.o		\
		start.o

KERNEL =
LIBRARIES = libc

CFLAGS =	-mthumb -mcpu=cortex-m4		\
		-nostdlib -fno-builtin-printf	\
		-g -Wall -Werror

all:	${OBJDIR}/${APP}.elf

clean:
	@rm -f ${OBJECTS} ${OBJDIR}/${APP}.elf

include osfive/lib/libc/Makefile.inc
include osfive/mk/default.mk
