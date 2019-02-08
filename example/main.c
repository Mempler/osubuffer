#include <buffer.h>
#include <buffer_reader.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Allocate an Buffer named buff
    buffer* buff = make_buffer();
    // Allocate an Buffer Reader named reader
    buffer_reader* reader = make_reader(buff);

    // Write an string with the value of "Test\0" and length of 5 and isn't nullable
    write_osustring(buff, "Test", 5, false);

    // Print the existing buffer. Result should be "Buffer: { 11 5 84 101 115 116 0 }"
    print_buffer(buff);

    // Read an Osu string from the Buffer.
    const char* str = read_osustring(reader);

    // Print the Osu string from the Buffer.
    printf("%s\n", str);

    // Cleanup memory.
    free((void*) str);
    free_reader(reader);
    free_buffer(buff);
    return 0;
}