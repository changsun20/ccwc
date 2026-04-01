#include <cstdint>
#include <istream>

#ifndef WC_UTILS_H_
#define WC_UTILS_H_

namespace wc {

uint64_t count_bytes(std::istream &input);
uint64_t count_lines(std::istream &input);

} // namespace wc

#endif // WC_UTILS_H_
