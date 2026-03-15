/*
    Copyright (c) 2024-2026 SharpScript Programming Language
    
    Licensed under the MIT License
*/

// START OF io.c

#include "io.h"
#include <stdio.h>
#include <string.h>

/*
 * io_read_file: Read the contents of a file into a string
 * 
 * Opens a file in binary mode, reads its entire contents, and returns them as a string Value.
 * Handles file size detection, memory allocation, and proper cleanup on errors.
 * 
 * Parameters:
 *   path: The file path to read
 * 
 * Returns: String Value containing file contents, or null Value on error
 */
Value *io_read_file(const char *path)
{
    // Validate input path
    if (!path) return value_create_null();
    
    // Open file in binary mode for accurate size reading
    FILE *f = fopen(path, "rb");
    if (!f) return value_create_null();
    
    // Determine file size
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    // Allocate buffer for file contents plus null terminator
    char *buf = malloc(sz + 1);
    if (!buf) { fclose(f); return value_create_null(); }
    
    // Read entire file contents
    fread(buf, 1, sz, f);
    buf[sz] = '\0'; // Ensure null termination
    fclose(f);
    
    // Create string Value from buffer and cleanup
    Value *s = value_create_string(buf);
    free(buf);
    return s;
}

/*
 * io_write_file: Write data to a file
 * 
 * Opens a file in binary write mode and writes the provided data to it.
 * Supports writing string values directly and number values as formatted text.
 * 
 * Parameters:
 *   path: The file path to write to
 *   data: The Value to write (string or number). If NULL, writes nothing.
 * 
 * Returns: Always returns null Value (operation result indicated by success/failure)
 */
Value *io_write_file(const char *path, Value *data)
{
    // Validate input path
    if (!path) return value_create_null();
    
    // Open file in binary write mode
    FILE *f = fopen(path, "wb");
    if (!f) return value_create_null();
    
    // Write data if provided
    if (data)
    {
        if (data->type == VAL_STRING)
        {
            // Write string data directly
            fwrite(data->data.string, 1, strlen(data->data.string), f);
        }
        else if (data->type == VAL_NUMBER)
        {
            // Format number as string and write
            char buf[64];
            int n = snprintf(buf, sizeof(buf), "%g", data->data.number);
            fwrite(buf, 1, n, f);
        }
    }
    
    fclose(f);
    return value_create_null();
}

// END OF io.c