#ifndef OSUBUFFER_BUFFER_H
#define OSUBUFFER_BUFFER_H

#include <corecrt.h>

typedef unsigned char ui8;
typedef char i8;

typedef unsigned short ui16;
typedef short i16;

typedef unsigned int ui32;
typedef int i32;

typedef unsigned long long ui64;
typedef long long i64;

typedef ui64 uleb128;

typedef unsigned int size;

#define nil (void*)0

typedef struct {
    ui8* __data;
    size  __size;
    size  __pos;
} buffer;

buffer* make_buffer();

void append(buffer* buff, size len);

void write_i8(buffer* buff,        i8 b);
void write_ui8(buffer* buff,       ui8 b);
void write_i16(buffer* buff,       i16 b);
void write_ui16(buffer* buff,       ui16 b);
void write_i32(buffer* buff,       i32 b);
void write_ui32(buffer* buff,      ui32 b);
void write_i64(buffer* buff,       i64 b);
void write_ui64(buffer* buff,      ui64 b);
void write_float(buffer* buff,     float b);
void write_double(buffer* buff,    double b);
void write_uleb128(buffer* buff,   uleb128 b);
void write_cstring(buffer* buff, const char* b, size str_len);
void write_osustring(buffer* buff, const char* b, size str_len, ui8 nullable);

void free_buffer(buffer* buff);
void print_buffer(buffer* buff);

#endif //OSUBUFFER_BUFFER_H
