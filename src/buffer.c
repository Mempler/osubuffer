#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OSUBUFFER_EXPORT

#include <buffer.h>

buffer* make_buffer() {
    buffer* buff = malloc(sizeof(buffer));

    buff->__size = 0;
    buff->__pos  = 0;
    buff->__data = nil;

    return buff;
}

void append(buffer* buff, size len) {
    if (buff->__data == nil)
        buff->__data = malloc(sizeof(len));

    buff->__data = realloc(buff->__data, buff->__size + len);
    buff->__size += len;
}

void write(buffer* buff, void* b, size s) {
    append(buff, s);
    memcpy(buff->__data + buff->__pos, b, s);
    buff->__pos += s;
}

void write_i8(buffer* buff, i8 b) { write(buff, &b, sizeof(b)); }

void write_ui8(buffer* buff, ui8 b) { write(buff, &b, sizeof(b)); }

void write_i16(buffer* buff, i16 b) { write(buff, &b, sizeof(b)); }

void write_ui16(buffer* buff, ui16 b) { write(buff, &b, sizeof(b)); }

void write_i32(buffer* buff, i32 b) { write(buff, &b, sizeof(b)); }

void write_ui32(buffer* buff, ui32 b) { write(buff, &b, sizeof(b)); }

void write_i64(buffer* buff, i64 b) { write(buff, &b, sizeof(b)); }

void write_ui64(buffer* buff, ui64 b) { write(buff, &b, sizeof(b)); }

void write_float(buffer* buff, float b) { write(buff, &b, sizeof(b)); }

void write_double(buffer* buff, double b) { write(buff, &b, sizeof(b)); }

void write_buffer(buffer* buff, buffer* b) { write(buff, b->__data, sizeof(b)); }

void write_uleb128(buffer* buff,  uleb128 b) {
    size t = 0;
    do {
        ui8 byte;
        byte = (ui8) (b & 0x7F);
        b >>= 0x07;
        if (b != 0)
            byte |= 0x80;

        write(buff, &byte, 1);
        t++;
    } while(b > 0);
}

void write_i32_arr(buffer* buff, i32* b, size len) {
    write_i16(buff, (i16) len);

    size i = 0;

    while (i < len) {
        write_i32(buff, b[i]);
        ++i;
    }
}

void write_cstring(buffer* buff, const char* b, size str_len) { write(buff, (void *) b, str_len); }

void write_osustring(buffer* buff, const char* b, size str_len, ui8 nullable) {
    if (nullable && b == nil){
        write_ui8(buff, 0);
        return;
    }

    write_ui8(buff, 0x0b);
    if (str_len <= 0) {
        write_ui8(buff, 0);
        return;
    }

    write_uleb128(buff, str_len);

    write_cstring(buff, b, str_len);
}

void free_buffer(buffer* buff) {
    free(buff->__data);
    free(buff);
}

void print_buffer(buffer* buff) {
    printf("%s", "Buffer: {");

    size i = 0;
    while (i < buff->__size) {
        printf(" %d", buff->__data[i]);
        ++i;
    }

    printf(" }\n");
}
