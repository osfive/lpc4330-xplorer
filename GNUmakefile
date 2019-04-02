APP =		lpc4330-xplorer
ARCH =		arm

CC =		${CROSS_COMPILE}gcc
LD =		${CROSS_COMPILE}ld
OBJCOPY =	${CROSS_COMPILE}objcopy

OBJDIR =	obj

LDSCRIPT =	${CURDIR}/ldscript

OBJECTS =	main.o						\
		osfive/sys/arm/nxp/lpc43xx_scu.o		\
		osfive/sys/arm/nxp/lpc43xx_usart.o		\
		start.o

LIBRARIES = KERN ARM LIBC

CFLAGS =	-mthumb -mcpu=cortex-m4		\
		-nostdlib -fno-builtin-printf	\
		-g -Wall -Werror

all:	__compile __link __binary

clean:
	rm -f ${OBJECTS} ${APP}.elf

include osfive/lib/libc/Makefile.inc
include osfive/lib/kern/Makefile.inc
include osfive/mk/gnu.mk
