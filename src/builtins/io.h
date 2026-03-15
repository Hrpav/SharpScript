/*
    Copyright (c) 2024-2026 SharpScript Programming Language
    
    Licensed under the MIT License
*/

// START OF io.h

#ifndef IO_H
#define IO_H

#include "../include/interpreter.h"

Value *io_read_file(const char *path);
Value *io_write_file(const char *path, Value *data);

#endif // IO_H

// END OF io.h