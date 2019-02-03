# lpc4330-xplorer
Hello world on lpc4330-xplorer board

Connect UART pins as follows:

| J8 header | UART-to-USB adapter |
| --------- | ------------------- |
|         9 |             UART RX |
|        10 |             UART TX |

### Build under Linux or FreeBSD
    $ setenv CROSS_COMPILE arm-none-eabi-
    $ git clone --recursive https://github.com/osfive/lpc4330-xplorer
    $ cd lpc4330-xplorer
    $ make

### Program
    $ cp lpc4330-xplorer.bin lpc4330-xplorer.dfu
    $ dfu-suffix --pid=0x000c --vid=0x1fc9 -a lpc4330-xplorer.dfu
    $ dfu-prefix -L -a lpc4330-xplorer.dfu
    $ # press the reset button on the board
    $ sudo dfu-util -D lpc4330-xplorer.dfu

![alt text](https://raw.githubusercontent.com/osfive/lpc4330-xplorer/master/images/lpc4330-xplorer.jpg)
