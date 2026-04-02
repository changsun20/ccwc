#include <cstdint>
#include <istream>
#include <optional>
#include <sys/types.h>

namespace wc {
std::optional<uint64_t> count_bytes(std::istream &input) {
    char buffer[1024];

    uint64_t byte_count = 0;
    while (input.read(buffer, sizeof(buffer))) {
        byte_count += sizeof(buffer);
    }
    byte_count += input.gcount();

    return byte_count;
}

std::optional<uint64_t> count_lines(std::istream &input) {
    uint64_t line_count = 0;

    std::string line;
    while (std::getline(input, line)) {
        line_count += 1;
    }

    return line_count;
}
} // namespace wc
