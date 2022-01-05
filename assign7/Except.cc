#include <iostream>
#include <string.h>
#include "Except.h"

Except::Except(char *str) {

  error=strdup(str);

}
