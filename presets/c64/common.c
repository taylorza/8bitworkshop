
#include "common.h"

void raster_wait(byte line) {
  while (VIC.rasterline < line) ;
}

void wait_vblank(void) {
  raster_wait(255);
}

static byte VIC_BANK_PAGE[4] = {
  0xc0, 0x80, 0x40, 0x00
};

char* get_vic_bank_start(void) {
  return (char*)(VIC_BANK_PAGE[CIA2.pra & 3] << 8);
}
