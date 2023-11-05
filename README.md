# Week 5 Assignment

I modified the provided 'reusable' CLI code to work on the STM32F3 Discovery board.

This was done by using 'HAL_UART_Receive_IT' to trigger an interrupt whenever a character
was recieved over UART. The interrupt handler adds the received character to the received buffer. 

The 'reusable' processing loop is largely the same, except it no longer polls for new
characters, instead receiving the data via the interrupt processing.

To avoid synchronization issues with the received buffer, the 'reusable' processing loop
is treated as a critical section, and interrupts are disabled.

Three simple commands were added to the CLI:
- led_toggle - toggles a specified LED
- led_blink - puts a specified LED into "blink" mode, where a timer interrupt toggles its state every 500ms
- reset - resets the board

Additionally: 
- the 'reusable' code was forked and used as a submodule in the project.
- it has been modified to take a command table as a parameter, allowing the fork to be reused across projects (see projectCommands.h/.c)