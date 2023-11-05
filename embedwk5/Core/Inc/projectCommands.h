
// The console command interface is generally used only by console.c, 
// if you want to add a command, go to consoleCommands.c

#ifndef PROJECT_COMMANDS_H
#define PROJECT_COMMANDS_H

#include <stdint.h>
#include "consoleCommands.h"

const sConsoleCommandTable_T* ConsoleCommandsGetTable(void);

#endif // PROJECT_COMMANDS_H

