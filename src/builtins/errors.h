/*
    Copyright (c) 2024-2026 SharpScript Programming Language
    
    Licensed under the MIT License
*/

// START OF errors.h

#ifndef ERRORS_H
#define ERRORS_H

#include "../include/interpreter.h"

Value *value_create_error(const char *name, const char *message, int code);

#endif // ERRORS_H

// END OF errors.h