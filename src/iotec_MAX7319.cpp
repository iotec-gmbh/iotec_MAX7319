/* Copyright (c) 2021 iotec GmbH */
#include "iotec_MAX7319.h"

iotec_MAX7319::iotec_MAX7319(uint8_t addr, TwoWire &wire) :
    m_i2cAddr(addr),
    m_i2c(wire){
    // nothing to do
}

bool iotec_MAX7319::begin(){
    // check if given address is fine
    if ((m_i2cAddr < 0x60) || (m_i2cAddr > 0x6F)) {
        // set address to default
        m_i2cAddr = 0x60;
        // return error
        return false;
    }

    // start i2c connection
    m_i2c.begin();
    // return all good
    return true;
}

bool iotec_MAX7319::read(uint8_t *port, uint8_t *flags) {
    // check for null pointer
    if (nullptr == port || nullptr == flags) {
        return false;
    }

    uint8_t readByteQantity = 2;

    // request bytes from device
    int returnedBytes = m_i2c.requestFrom(m_i2cAddr, readByteQantity, static_cast<uint8_t>(true));

    // check if requested bytes are received
    if (returnedBytes != readByteQantity){
        return false;
    }
    
    // pop results to parameters
    *port = m_i2c.read();
    *flags = m_i2c.read();
    return true;
}
