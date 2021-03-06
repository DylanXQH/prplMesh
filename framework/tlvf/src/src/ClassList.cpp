/* SPDX-License-Identifier: BSD-2-Clause-Patent
 *
 * Copyright (c) 2016-2019 Intel Corporation
 *
 * This code is subject to the terms of the BSD+Patent license.
 * See LICENSE file for more details.
 */

#include <tlvf/BaseClass.h>
#include <tlvf/ClassList.h>
#include <tlvf/tlvflogging.h>

ClassList::ClassList(uint8_t *buff, size_t buff_len, bool parse)
    : m_buff(buff), m_buff_len(buff_len), m_parse(parse)
{
}

size_t ClassList::getMessageLength() const
{
    if (m_buff == nullptr)
        return 0;
    size_t msg_len = 0;
    for (auto const &c : m_class_vector) {
        msg_len += c->getLen();
    }
    return msg_len;
}

void ClassList::swap()
{
    if (!m_buff)
        return;

    // call all tlv finalize functions
    for (auto const &c : m_class_vector) {
        c->class_swap();
        if (c->getInnerClassList())
            c->getInnerClassList()->swap();
    }

    m_swapped = !m_swapped;
}

void ClassList::reset(bool parse)
{
    if (!parse)
        memset(m_buff, 0, m_buff_len);
    m_parse     = parse;
    m_finalized = false;
    m_swapped   = false;
    for (auto &c : m_class_vector) {
        c.reset();
    }
    m_class_vector.clear();
}

bool ClassList::finalize()
{
    if (m_class_vector.empty()) {
        TLVF_LOG(ERROR) << "Finalize() called on an empty ClassList!";
        return false;
    }

    if (m_finalized)
        return true;

    // On every addClass, we call finalize for the previous added class.
    // We need to call it here manually for the last class added for which
    // we didn't call finalize() yet.
    if (!m_class_vector.back()->finalize())
        return false;

    m_finalized = true;
    return true;
}
