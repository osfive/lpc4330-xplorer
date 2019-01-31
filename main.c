/*-
 * Copyright (c) 2019 Ruslan Bukin <br@bsdpad.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#include <sys/console.h>
#include <sys/systm.h>
#include <sys/malloc.h>

#include <machine/frame.h>

#include <arm/arm/nvic.h>
#include <arm/nxp/lpc43xx.h>

void app_main(void);
struct usart_softc usart_sc;
struct scu_softc scu_sc;

#define	UART_BAUDRATE	115200
#define	PCLK		12000000
#define	SCU_NPINS	2

const struct scu_pin pins[SCU_NPINS] = {
	{ 6, 4, SFSP_MODE(2) },			/* USART0 TX */
	{ 6, 5, SFSP_MODE(2) | SFSP_EZI },	/* USART0 RX */
};

const struct usart_baud_entry bauds[] = {
	{ 0, 4, 5, 8 },		/* 12000000 / 115200 */
};

static void
uart_putchar(int c, void *arg)
{
	struct usart_softc *sc;
 
	sc = arg;
 
	if (c == '\n')
		lpc43xx_usart_putc(sc, '\r');

	lpc43xx_usart_putc(sc, c);
}

void
app_main(void)
{

	lpc43xx_scu_init(&scu_sc, BASE_SCU, pins, SCU_NPINS);
	lpc43xx_usart_init(&usart_sc, BASE_USART0, &bauds[0]);
	console_register(uart_putchar, (void *)&usart_sc);

	while (1)
		printf("Hello world!\n");
}
