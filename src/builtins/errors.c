/*
    Copyright (c) 2024-2026 SharpScript Programming Language
    
    Licensed under the MIT License
*/

// START OF errors.c

#include "errors.h"
#include <string.h>

/*
 * value_create_error: Create an error value
 * 
 * Allocates memory for a new Value and initializes it as an error type.
 * Creates copies of the error name and message strings.
 * 
 * Parameters:
 *   name: The error type name (e.g., "TypeError", "RuntimeError"). If NULL, defaults to "Error"
 *   message: The error message. If NULL, defaults to empty string
 *   code: Numeric error code for categorization
 * 
 * Returns: Pointer to the newly created error Value
 */
Value *value_create_error(const char *name, const char *message, int code)
{
    Value *val = memory_allocate(sizeof(Value));
    val->type = VAL_ERROR;
    val->data.error.name = memory_strdup(name ? name : "Error");
    val->data.error.message = memory_strdup(message ? message : "");
    val->data.error.code = code;
    return val;
}

// END OF errors.c