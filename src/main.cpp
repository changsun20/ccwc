#include <CLI/CLI.hpp>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

namespace wc {
uint64_t count_bytes(std::ifstream &input) {
    char buffer[1024];

    uint64_t byte_count = 0;
    while (input.read(buffer, sizeof(buffer))) {
        byte_count += sizeof(buffer);
    }
    byte_count += input.gcount();

    return byte_count;
}

uint64_t count_lines(std::ifstream &input) {
    uint64_t line_count = 0;

    std::string line;
    while (std::getline(input, line)) {
        line_count += 1;
    }

    return line_count;
}
} // namespace wc

int main(int argc, char **argv) {
    CLI::App app;

    std::string filename;
    app.add_option("filename", filename, "File to read")->default_val("");

    bool cflag;
    app.add_flag("-c", cflag, "Calculate binary size");

    bool lflag;
    app.add_flag("-l", lflag, "Calculate total number of lines");

    CLI11_PARSE(app, argc, argv);

    if (lflag) {
        std::ifstream file(filename);
        std::cout << " " << wc::count_lines(file);
    }

    if (cflag) {
        std::ifstream file(filename, std::ios::binary);
        std::cout << " " << wc::count_bytes(file);
    }

    std::cout << " " << filename << std::endl;
}
