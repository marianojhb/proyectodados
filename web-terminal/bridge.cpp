#include "terminal_io.h"
#include <emscripten.h>
#include <iostream>
#include <streambuf>

EM_ASYNC_JS(int, terminal_read_key, (int timeout), {
    return await Module.terminalInput.readByte(timeout);
});

EM_JS(int, terminal_key_count, (), {
    return Module.terminalInput.pending();
});

EM_ASYNC_JS(int, terminal_read_line_byte, (), {
    return await Module.terminalInput.readLineByte();
});

EM_JS(void, terminal_write, (const char* text, int length), {
    Module.terminalOutput(HEAPU8.subarray(text, text + length));
});

class TerminalOutput : public std::streambuf {
    std::streamsize xsputn(const char* text, std::streamsize size) override
    {
        terminal_write(text, static_cast<int>(size));
        return size;
    }
    int_type overflow(int_type value) override
    {
        if (traits_type::eq_int_type(value, traits_type::eof())) return traits_type::not_eof(value);
        char character = traits_type::to_char_type(value);
        terminal_write(&character, 1);
        return value;
    }
};

class TerminalInput : public std::streambuf {
    char character;
    int_type underflow() override
    {
        if (gptr() && gptr() < egptr()) return traits_type::to_int_type(*gptr());
        int value = terminal_read_line_byte();
        if (value < 0) return traits_type::eof();
        character = static_cast<char>(value);
        setg(&character, &character, &character + 1);
        return traits_type::to_int_type(character);
    }
};

int console_main();

int main()
{
    // Static lifetime also covers the game's existing exit(EXIT_SUCCESS) path.
    static TerminalInput input;
    static TerminalOutput output;
    std::cin.rdbuf(&input);
    std::cout.rdbuf(&output);
    std::cerr.rdbuf(&output);
    return console_main();
}
