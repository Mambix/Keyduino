#include "MCP23S17.h"

MCP23S17::MCP23S17(uint8_t ce) {
	_address = OPCODE;
	_ce = ce;
 SPISettings _speedSPI(100000, MSBFIRST, SPI_MODE0);
};

MCP23S17::MCP23S17(uint8_t address, uint8_t ce) {
  //make even address and shift one bit
  //bit 1 is for R/W
  _address = OPCODE | ((address & 0x07) << 1); 
  _ce = ce;
  SPISettings _speedSPI(100000, MSBFIRST, SPI_MODE0);
};

void MCP23S17::speedSPI(uint32_t speed) {
  SPISettings _speedSPI(speed, MSBFIRST, SPI_MODE0);
};

void MCP23S17::begin() {
	::pinMode(_ce, OUTPUT);
	::digitalWrite(_ce, HIGH);
  SPI.begin();

  writeRegister(_address, IOCON, 0x08);
  //on reset they are all input
  //enable all pullUP
  pinPullUP(0xFFFFFFFF);
};

void MCP23S17::writeRegister(uint8_t address, uint8_t reg, uint8_t val) {
  SPI.beginTransaction(_speedSPI);
  ::digitalWrite(_ce, LOW);
  SPI.transfer(address & 0xFE);
  SPI.transfer(reg);
  SPI.transfer(val);
  ::digitalWrite(_ce, HIGH);
  SPI.endTransaction();
  //delay??
//  SPI.transfer(0x00);
};

uint8_t MCP23S17::readRegister(uint8_t address, uint8_t reg) {
  uint8_t val = 0;
  SPI.beginTransaction(_speedSPI);
  ::digitalWrite(_ce, LOW);
  SPI.transfer(address | 0x01);
  SPI.transfer(reg);
  val = SPI.transfer(0x00);
  ::digitalWrite(_ce, HIGH);
  SPI.endTransaction();
  return val;
};

// 1= input; 0= output;
void MCP23S17::pinMode(uint32_t state) {
  _BA0 = state & 0xFF; state = state >> 8;
  _BA1 = state & 0xFF; state = state >> 8;
  _BB0 = state & 0xFF; state = state >> 8;
  _BB1 = state & 0xFF;

  writeRegister(_address | 0x02, IODIRB, _BB1);
  writeRegister(_address | 0x02, IODIRA, _BB0);
  writeRegister(_address, IODIRB, _BA1);
  writeRegister(_address, IODIRA, _BA0);
};

// 1= pullup; 0= disabled;
void MCP23S17::pinPullUP(uint32_t state) {
  _BA0 = state & 0xFF; state = state >> 8;
  _BA1 = state & 0xFF; state = state >> 8;
  _BB0 = state & 0xFF; state = state >> 8;
  _BB1 = state & 0xFF;

  writeRegister(_address | 0x02, GPPUB, _BB1);
  writeRegister(_address | 0x02, GPPUA, _BB0);
  writeRegister(_address, GPPUB, _BA1);
  writeRegister(_address, GPPUA, _BA0);
};

void MCP23S17::pinWrite(uint32_t state) {
  _BA0 = state & 0xFF; state = state >> 8;
  _BA1 = state & 0xFF; state = state >> 8;
  _BB0 = state & 0xFF; state = state >> 8;
  _BB1 = state & 0xFF;

  writeRegister(_address | 0x02, GPIOB, _BB1);
  writeRegister(_address | 0x02, GPIOA, _BB0);
  writeRegister(_address, GPIOB, _BA1);
  writeRegister(_address, GPIOA, _BA0);
};

uint32_t MCP23S17::pinRead(void) {
  _BB1 = readRegister(_address | 0x02, GPIOB);
  _BB0 = readRegister(_address | 0x02, GPIOA);
  _BA1 = readRegister(_address, GPIOB);
  _BA0 = readRegister(_address, GPIOA);
  uint32_t val = _BB1; val = val << 8;
  val += _BB0; val = val << 8;
  val += _BA1; val = val << 8;
  val += _BA0;
  return val;
};
