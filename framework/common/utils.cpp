/* SPDX-License-Identifier: BSD-2-Clause-Patent
 *
 * Copyright (c) 2019 Tomer Eliyahu (Intel)
 *
 * This code is subject to the terms of the BSD+Patent license.
 * See LICENSE file for more details.
 */

#include <iomanip>
#include <mapf/common/utils.h>
#include <sstream>

namespace mapf {
namespace utils {

std::string dump_buffer(uint8_t *buffer, size_t len)
{
    std::ostringstream hexdump;
    for (size_t i = 0; i < len; i += 16) {
        for (size_t j = i; j < len && j < i + 16; j++)
            hexdump << std::hex << std::setw(2) << std::setfill('0') << (unsigned)buffer[j] << " ";
        hexdump << std::endl;
    }
    return hexdump.str();
}

} // namespace utils
} // namespace mapf
