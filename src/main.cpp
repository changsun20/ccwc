#include <CLI/CLI.hpp>
#include <ios>
#include <iostream>
#include <string>

#include "wc_utils.hpp"

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
