///////////////////////////////////////
// AUTO GENERATED FILE - DO NOT EDIT //
///////////////////////////////////////

/* SPDX-License-Identifier: BSD-2-Clause-Patent
 *
 * Copyright (c) 2016-2019 Intel Corporation
 *
 * This code is subject to the terms of the BSD+Patent license.
 * See LICENSE file for more details.
 */

#ifndef _TLVF_IEEE_1905_1_TLVENDOFMESSAGE_H_
#define _TLVF_IEEE_1905_1_TLVENDOFMESSAGE_H_

#include <cstddef>
#include <stdint.h>
#include <tlvf/swap.h>
#include <string.h>
#include <memory>
#include <tlvf/BaseClass.h>
#include <tlvf/ClassList.h>
#include "tlvf/ieee_1905_1/eTlvType.h"

namespace ieee1905_1 {


class tlvEndOfMessage : public BaseClass
{
    public:
        tlvEndOfMessage(uint8_t* buff, size_t buff_len, bool parse = false);
        explicit tlvEndOfMessage(std::shared_ptr<BaseClass> base, bool parse = false);
        ~tlvEndOfMessage();

        const eTlvType& type();
        const uint16_t& length();
        void class_swap() override;
        bool finalize() override;
        static size_t get_initial_size();

    private:
        bool init();
        eTlvType* m_type = nullptr;
        uint16_t* m_length = nullptr;
};

}; // close namespace: ieee1905_1

#endif //_TLVF/IEEE_1905_1_TLVENDOFMESSAGE_H_
