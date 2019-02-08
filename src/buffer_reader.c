#include <stdlib.h>
#include <string.h>

#include <buffer_reader.h>

bool isInRange(buffer_reader* reader, size len) {
    return reader->__pos + len <= reader->__buffer->__size;
}

buffer_reader* make_reader(buffer* buffer) {
    buffer_reader* reader = malloc(sizeof(buffer_reader));

    reader->__pos  = 0;
    reader->__buffer = buffer;

    return reader;
}

i8 read_i8(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(i8)))
        return 0;

    i8 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(i8));

    reader->__pos += sizeof(i8);

    return r;
}

ui8 read_ui8(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(ui8)))
        return 0;

    ui8 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(ui8));

    reader->__pos += sizeof(ui8);

    return r;
}

i16 read_i16(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(i16)))
        return 0;

    i16 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(i16));

    reader->__pos += sizeof(i16);

    return r;
}

ui16 read_ui16(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(ui16)))
        return 0;

    ui16 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(ui16));

    reader->__pos += sizeof(ui16);

    return r;
}

i32 read_i32(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(i32)))
        return 0;

    i32 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(i32));

    reader->__pos += sizeof(i32);

    return r;
}

ui32 read_ui32(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(ui32)))
        return 0;

    ui32 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(ui32));

    reader->__pos += sizeof(ui32);

    return r;
}

i64 read_i64(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(i64)))
        return 0;

    i64 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(i64));

    reader->__pos += sizeof(i64);

    return r;
}

ui64 read_ui64(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(ui64)))
        return 0;

    ui64 r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(ui64));

    reader->__pos += sizeof(ui64);

    return r;
}

float read_float(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(float)))
        return 0;

    float r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(float));

    reader->__pos += sizeof(float);

    return r;
}

double read_double(buffer_reader* reader) {
    if (!isInRange(reader, sizeof(double)))
        return 0;

    double r;
    memcpy(&r, reader->__buffer->__data + reader->__pos, sizeof(double));

    reader->__pos += sizeof(double);

    return r;
}

uleb128 read_uleb128(buffer_reader* reader) {
    uleb128 total = 0;
    uleb128 shift = 0;

    while(true) {
        ui8 byte = read_ui8(reader);

        total |= (byte & 0x7F) << shift;

        if ((byte & 0x80) == 0)
            break;

        shift += 7;
    }

    return total;
}

const char* read_cstring(buffer_reader* reader, size len) {
    char* ret_val = malloc(len);

    memcpy(ret_val, reader->__buffer->__data + reader->__pos, len);
    reader->__pos += len;

    return ret_val;
}

const char* read_osustring(buffer_reader* reader) {
    char string_byte = read_ui8(reader);
    if (string_byte != 0x0b)
        return nil;

    size len = (size) read_uleb128(reader);
    return read_cstring(reader, len);
}

OSUBUFFER_API void free_reader(buffer_reader* reader) {
    free(reader);
}
