#ifndef DACTYL_LIGHTCYCLE_H
#define DACTYL_LIGHTCYCLE_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2cmaster.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern uint8_t mcp23018_status;

void init_dactyl_lightcycle(void);
uint8_t init_mcp23018(void);

#define KEYMAP(                                                 \
                                                                \
    /* left hand, spatial positions */                          \
    k00,k01,k02,k03,k04,k05,                                    \
    k10,k11,k12,k13,k14,k15,                                    \
    k20,k21,k22,k23,k24,k25,                                    \
    k30,k31,k32,k33,k34,                                        \
                            k26,k06,                            \
						k35,k36,k16,                            \
                                                                \
    /* right hand, spatial positions */                         \
            k08,k09,k0A,k0B,k0C,k0D,                            \
            k18,k19,k1A,k1B,k1C,k1D,                            \
            k28,k29,k2A,k2B,k2C,k2D,                            \
                k39,k3A,k3B,k3C,k3D,                            \
    k07,k27,                                                    \
    k17,k37,k38 )                                               \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    { k30, k20, k10, k00, }, \
    { k31, k21, k11, k01, }, \
    { k32, k22, k12, k02, }, \
    { k33, k23, k13, k03, }, \
    { k34, k24, k14, k04, }, \
    { k35, k25, k15, k05, }, \
    { k36, k26, k16, k06, }, \
                             \
    { k07, k17, k27, k37, }, \
    { k08, k18, k28, k38, }, \
    { k09, k19, k29, k39, }, \
    { k0A, k1A, k2A, k3A, }, \
    { k0B, k1B, k2B, k3B, }, \
    { k0C, k1C, k2C, k3C, }, \
    { k0D, k1D, k2D, k3D, }  \
   }

#define LAYOUT_dactyl_lightcycle KEYMAP

#endif
