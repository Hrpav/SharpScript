/*
    Copyright (c) 2024-2026 SharpScript Programming Language Hrpavi

    Licensed under the MIT License
*/

// START of memory.h


#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

void* memory_allocate(size_t size);
void* memory_reallocate(void* ptr, size_t size);
void memory_free(void* ptr);
char* memory_strdup(const char* str);

#endif

