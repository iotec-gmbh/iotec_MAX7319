/* Copyright (c) 2021 iotec GmbH */
#ifndef IOTEC_MAX7319_H
#define IOTEC_MAX7319_H

#include <Arduino.h>
#include <Wire.h>

/*!
 * @brief Class to read port state and transition flags from MAX7319.
 */
class iotec_MAX7319 {
public:
  /**
   * @brief Constructor to specify I2C interface with address.
   * 
   * @param addr I2C address. Default to 0x60. 
   *             Valid addresses are 0x60 to 0x6F.
   * @param wire I2C TwoWire Interface. Defaults to Wire.
   */
  iotec_MAX7319(uint8_t addr = 0x60, TwoWire &wire = Wire);
  
  /**
   * @brief Use begin function in case you want to start Wire from this lib.
   *        Sanity check for given address and start I2C interface on valid address.
   * 
   * @return True on valid address, else false and set of address to default.
   */
  bool begin();

  /**
   * @brief Read the current port state and its transition flags.
   *        After reading the transition flags will be resetted.
   * 
   * @param port Port input state where the MSB is Input7 and the LSB Input0.
   * @param flags Interrupt flag where the MSB is Flag7 and the LSB Flag0.
   * @return True on success, else false. 
   */
  bool read(uint8_t *port, uint8_t *flags);

private:
  // I2C address
  uint8_t m_i2cAddr;
  TwoWire &m_i2c;
};

#endif // IOTEC_MAX7319_H
