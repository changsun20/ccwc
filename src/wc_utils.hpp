#include <cstdint>
#include <istream>
#include <optional>

#ifndef WC_UTILS_H_
#define WC_UTILS_H_

namespace wc {

std::optional<uint64_t> count_bytes(std::istream &input);
std::optional<uint64_t> count_lines(std::istream &input);

} // namespace wc

#endif // WC_UTILS_H_
