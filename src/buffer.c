#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <buffer.h>

buffer* make_buffer() {
    buffer* buff = malloc(sizeof(buffer));

    buff->__size = 0;
    buff->__pos  = 0;
    buff->__data = nil;

    return buff;
}

int isInRange(buffer* buff, size len) {
    return buff->__pos + len > buff->__size;
}

void append(buffer* buff, size len) {
    buff->__data = realloc(buff->__data, buff->__size + len);
    buff->__size += len;
}

void write_i8(buffer* buff, i8 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_ui8(buffer* buff, ui8 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_i16(buffer* buff, i16 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_ui16(buffer* buff, ui16 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_i32(buffer* buff, i32 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_ui32(buffer* buff, ui32 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_i64(buffer* buff, i64 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_ui64(buffer* buff, ui64 b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_float(buffer* buff, float b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_double(buffer* buff, double b) {
    append(buff, sizeof(b));
    memcpy(buff->__data + buff->__pos, &b, sizeof(b));
    buff->__pos += sizeof(b);
}

void write_uleb128(buffer* buff,  uleb128 b) {
    size t = 0;
    do {
        ui8 byte;
        byte = (ui8) (b & 0x7F);
        b >>= 0x07;
        if (b != 0)
            byte |= 0x80;

        append(buff, 1);
        memcpy(buff->__data + buff->__pos, &byte, 1);
        buff->__pos++;
        t++;
    } while(b > 0);
}

void write_cstring(buffer* buff, const char* b, size str_len) {
    append(buff, str_len);
    memcpy(buff->__data + buff->__pos, &b, str_len);
    buff->__pos += str_len;
}

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
    for (size i = 0; i < buff->__size; ++i) {
        printf(" %d", buff->__data[i]);
    }
    printf(" }");
}
