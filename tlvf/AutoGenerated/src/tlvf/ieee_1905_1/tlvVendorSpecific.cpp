///////////////////////////////////////
// AUTO GENERATED FILE - DO NOT EDIT //
///////////////////////////////////////

/*
#############################################################################
# INTEL CONFIDENTIAL
# Copyright 2018 Intel Corporation All Rights Reserved.
#
# The source code contained or described herein and all documents related to
# the source code ("Material") are owned by Intel Corporation or its
# suppliers or licensors.  Title to the Material remains with Intel
# Corporation or its suppliers and licensors.  The Material contains trade
# secrets and proprietary and confidential information of Intel or its
# suppliers and licensors.  The Material is protected by worldwide copyright
# and trade secret laws and treaty provisions. No part of the Material may
# be used, copied, reproduced, modified, published, uploaded, posted,
# transmitted, distributed, or disclosed in any way without Intel's prior
# express written permission.
#
# No license under any patent, copyright, trade secret or other intellectual
# property right is granted to or conferred upon you by disclosure or
# delivery of the Materials,  either expressly, by implication, inducement,
# estoppel or otherwise.  Any license under such intellectual property
# rights must be express and approved by Intel in writing.
#############################################################################
*/

#include <tlvf/ieee_1905_1/tlvVendorSpecific.h>
#include <tlvf/tlvflogging.h>

using namespace ieee1905_1;

tlvVendorSpecific::tlvVendorSpecific(uint8_t* buff, size_t buff_len, bool parse, bool swap_needed) :
    BaseClass(buff, buff_len, parse, swap_needed) {
    m_init_succeeded = init();
}
tlvVendorSpecific::tlvVendorSpecific(std::shared_ptr<BaseClass> base, bool parse, bool swap_needed) :
BaseClass(base->getBuffPtr(), base->getBuffRemainingBytes(), parse, swap_needed){
    m_init_succeeded = init();
}
tlvVendorSpecific::~tlvVendorSpecific() {
}
const eTlvType& tlvVendorSpecific::type() {
    return (const eTlvType&)(*m_type);
}

uint16_t& tlvVendorSpecific::length() {
    return (uint16_t&)(*m_length);
}

std::tuple<bool, uint8_t&> tlvVendorSpecific::vendor_oui(size_t idx) {
    bool ret_success = ( (m_vendor_oui_idx__ > 0) && (m_vendor_oui_idx__ > idx) );
    size_t ret_idx = ret_success ? idx : 0;
    if (!ret_success) {
        TLVF_LOG(ERROR) << "Requested index is greater than the number of available entries";
    }
    return std::forward_as_tuple(ret_success, m_vendor_oui[ret_idx]);
}

void tlvVendorSpecific::class_swap()
{
    tlvf_swap(16, reinterpret_cast<uint8_t*>(m_type));
    tlvf_swap(16, reinterpret_cast<uint8_t*>(m_length));
}

size_t tlvVendorSpecific::get_initial_size()
{
    size_t class_size = 0;
    class_size += sizeof(eTlvType); // type
    class_size += sizeof(uint16_t); // length
    class_size += 3 * sizeof(uint8_t); // vendor_oui
    return class_size;
}

bool tlvVendorSpecific::init()
{
    if (getBuffRemainingBytes() < kMinimumLength) {
        TLVF_LOG(ERROR) << "Not enough available space on buffer. Class init failed";
        return false;
    }
    m_type = (eTlvType*)m_buff_ptr__;
    if (!m_parse__) *m_type = eTlvType::TLV_VENDOR_SPECIFIC;
    m_buff_ptr__ += sizeof(eTlvType) * 1;
    m_length = (uint16_t*)m_buff_ptr__;
    if (!m_parse__) *m_length = 0x3;
    m_buff_ptr__ += sizeof(uint16_t) * 1;
    m_vendor_oui = (uint8_t*)m_buff_ptr__;
    m_buff_ptr__ += (sizeof(uint8_t) * 3);
    m_vendor_oui_idx__  = 3;
    if (m_buff_ptr__ - m_buff__ > ssize_t(m_buff_len__)) {
        TLVF_LOG(ERROR) << "Not enough available space on buffer. Class init failed";
        return false;
    }
    if (m_parse__ && m_swap__) { class_swap(); }
    return true;
}


