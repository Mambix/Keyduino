#ifndef MCP23S17_h
#define MCP23S17_h

// REGISTERS from: https://cdn-shop.adafruit.com/datasheets/mcp23017.pdf
// FROM PAGE 11

#define    OPCODE    (0x40)

//BANK 0
#define    IODIRA    (0x00)      // I/O DIRECTION REGISTER
#define    IODIRB    (0x01)      // 1 = Input (default), 0 = Output
#define    IPOLA     (0x02)      // INPUT POLARITY REGISTER
#define    IPOLB     (0x03)      // 0 = Normal (default)(low reads as 0), 1 = Inverted (low reads as 1)
#define    GPINTENA  (0x04)      // INTERRUPT-ON-CHANGE PINS
#define    GPINTENB  (0x05)      // 0 = No Interrupt on Change (default), 1 = Interrupt on Change
#define    DEFVALA   (0x06)      // DEFAULT VALUE REGISTER
#define    DEFVALB   (0x07)      // Opposite of what is here will trigger an interrupt (default = 0)
#define    INTCONA   (0x08)      // INTERRUPT-ON-CHANGE CONTROL REGISTER
#define    INTCONB   (0x09)      // 1 = pin is compared to DEFVAL, 0 = pin is compared to previous state (default)
#define    IOCON     (0x0A)      // I/O EXPANDER CONFIGURATION REGISTER
//                   (0x0B)      //     Also Configuration Register
#define    GPPUA     (0x0C)      // GPIO PULL-UP RESISTOR REGISTER
#define    GPPUB     (0x0D)      // INPUT ONLY: 0 = No Internal 100k Pull-Up (default) 1 = Internal 100k Pull-Up 
#define    INTFA     (0x0E)      // INTERRUPT FLAG REGISTER
#define    INTFB     (0x0F)      // READ ONLY: 1 = This Pin Triggered the Interrupt
#define    INTCAPA   (0x10)      // INTERRUPT CAPTURED VALUE FOR PORT REGISTER
#define    INTCAPB   (0x11)      // 1 == logic HIGH; 0 == logic LOW
#define    GPIOA     (0x12)      // GENERAL PURPOSE I/O PORT REGISTER
#define    GPIOB     (0x13)      // Value on the Port - Writing Sets Bits in the Output Latch
#define    OLATA     (0x14)      // OUTPUT LATCH REGISTER
#define    OLATB     (0x15)      // 1 = Latch High, 0 = Latch Low (default) Reading Returns Latch State, Not Port Value!

#include <Arduino.h>

class MCP23S17 {
	public:
    MCP23S17(uint8_t, uint8_t);
		MCP23S17(uint8_t);
		void begin();
    void pinMode(uint32_t);
    void pinPullUP(uint32_t);
    void pinWrite(uint32_t);
    uint32_t pinRead(void);
	private:
		uint8_t _address;
		uint8_t _ce;
    uint8_t _BA0, _BA1, _BB0, _BB1;
    void writeRegister(uint8_t, uint8_t, uint8_t);
    uint8_t readRegister(uint8_t, uint8_t);
//    void writeRegister(uint8_t, uint8_t, uint16_t);
};

#endif
