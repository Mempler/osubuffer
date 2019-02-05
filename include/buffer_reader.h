#ifndef OSUBUFFER_BUFFER_READER_H
#define OSUBUFFER_BUFFER_READER_H

#include "core.h"
#include "buffer.h"

OSUBUFFER_API typedef struct {
    buffer* __buffer;
    size __pos;
} buffer_reader;

OSUBUFFER_API buffer_reader* make_reader(buffer* buffer);

OSUBUFFER_API i8 read_i8(buffer_reader* reader);
OSUBUFFER_API ui8 read_ui8(buffer_reader* reader);
OSUBUFFER_API i16 read_i16(buffer_reader* reader);
OSUBUFFER_API ui16 read_ui16(buffer_reader* reader);
OSUBUFFER_API i32 read_i32(buffer_reader* reader);
OSUBUFFER_API ui32 read_ui32(buffer_reader* reader);
OSUBUFFER_API i64 read_i64(buffer_reader* reader);
OSUBUFFER_API ui64 read_ui64(buffer_reader* reader);
OSUBUFFER_API float read_float(buffer_reader* reader);
OSUBUFFER_API double read_double(buffer_reader* reader);
OSUBUFFER_API uleb128 read_uleb128(buffer_reader* reader);
OSUBUFFER_API const char* read_cstring(buffer_reader* reader, size len);
OSUBUFFER_API const char* read_osustring(buffer_reader* reader);

#endif //OSUBUFFER_BUFFER_READER_H
