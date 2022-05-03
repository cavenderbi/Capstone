#include "../lib/hUGEDriver.h"
#include <gb/gb.h>
#include <stdint.h>

uint8_t current_module_bank = 2;
void ISR_wrapper() {
    static uint8_t _save;
    _save = _current_bank;
    SWITCH_ROM_MBC5(current_module_bank);
    hUGE_dosound();
    SWITCH_ROM_MBC5(_save);
}

void switch_hUGE_module(const hUGESong_t * module, uint8_t module_bank) {
    __critical {
        hUGE_init(module);
        current_module_bank = module_bank;
    }
}