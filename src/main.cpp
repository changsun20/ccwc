#include <CLI/CLI.hpp>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <ostream>
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

        if (!file.is_open()) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            return EXIT_FAILURE;
        }

        if (auto lines_num = wc::count_lines(file)) {
            std::cout << " " << lines_num.value();
        } else {
            std::cerr << "Failed when counting lines of the file.\n";
            return EXIT_FAILURE;
        }
    }

    if (cflag) {
        std::ifstream file(filename, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            return EXIT_FAILURE;
        }

        if (auto bytes_num = wc::count_bytes(file)) {
            std::cout << " " << bytes_num.value();
        } else {
            std::cerr << "Failed when counting lines of the file.\n";
            return EXIT_FAILURE;
        }
    }

    std::cout << " " << filename << std::endl;
    return 0;
}
