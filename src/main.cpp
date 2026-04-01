#include "CLI/CLI.hpp"
#include <CLI/CLI.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string_view>

int main(int argc, char **argv) {
    CLI::App app;

    std::string filename;
    app.add_option("filename", filename, "File to read")->default_val("");

    bool cflag;
    app.add_flag("-c", cflag, "Calculate binary size");

    bool lflag;
    app.add_flag("-l", lflag, "Calculate total number of lines");

    CLI11_PARSE(app, argc, argv);

    if (cflag) {
        char buffer[1024];
        std::ifstream file(filename, std::ios::binary);

        int cnt = 0;
        while (file.read(buffer, 1024)) {
            cnt += file.gcount();
        }
        cnt += file.gcount();

        std::cout << cnt << std::endl;

        std::cout << filename << std::endl;
    }

    if (lflag) {
        std::ifstream file(filename);

        int line_cnt = 0;

        char buffer[1024];
        while (file.getline(buffer, 1024)) {
            line_cnt += 1;
        }

        std::cout << line_cnt << std::endl;
    }
}
