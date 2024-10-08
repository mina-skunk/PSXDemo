#pragma once

#include "psyqo/cdrom.hh"

#define CD_MODE_SECTOR_SIZE_WHOLE 0b00100000
#define CD_MODE_REPORT_INT 0b00000100
#define CD_MODE_AUTO_PAUSE 0b00000010
#define CD_MODE_ENABLE_CDDA 0b00000001

class SimpleCDAudio {
  public:
    static void init();
    static void play(uint8_t track);
};
