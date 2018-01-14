#include "dactyl_lightcycle.h"
#include "i2cmaster.h"


bool i2c_initialized = 0;
uint8_t mcp23018_status = 0x20;

void matrix_init_kb(void) {
    DDRB  &= ~(1<<4);  // set B(4) as input
    PORTB &= ~(1<<4);  // set B(4) internal pull-up disabled

    // unused pins - B7, B6, B5,
    //               C7,
	//               D7, D6, D5, D4
	//               E6
	//               F7, F6
    // set as input with internal pull-up enabled
    DDRB  &= ~(1<<7 | 1<<6 | 1<<5);
    DDRC  &= ~(1<<7);
    DDRD  &= ~(1<<7 | 1<<6 | 1<<5 | 1<<4);
    DDRE  &= ~(1<<6);
    DDRF  &= ~(1<<7 | 1<<6);
    PORTB |=  (1<<7 | 1<<6 | 1<<5);
    PORTC |=  (1<<7);
    PORTD |=  (1<<7 | 1<<6 | 1<<5 | 1<<4);
    PORTE |=  (1<<6);
    PORTF |=  (1<<7 | 1<<6);

    matrix_init_user();
}

uint8_t init_mcp23018(void) {
    mcp23018_status = 0x20;

    // I2C subsystem

    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        _delay_ms(1000);
    }

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA);            if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00001111);        if (mcp23018_status) goto out;
    i2c_stop();

    // set pull-up
    // - unused  : on  : 1
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA);             if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000);        if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00001111);        if (mcp23018_status) goto out;

out:
    i2c_stop();

    return mcp23018_status;
}

