#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

char *readline_gets(void);
int get_function(char *input);
std::vector<std::string> splitString(std::string str, char splitter);

#endif /* MAIN_H */
