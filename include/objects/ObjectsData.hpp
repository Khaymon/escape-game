#pragma once

#include <include/draw.h>

#include <cinttypes>

const uint32_t PLAYER_ID = 0;

const uint32_t TRAP_CHEST_ID = 1;
const uint32_t TRAP_PORTAL_ID = 2;
const uint32_t TRAP_DOOR_ID = 3;

const uint32_t FAKE_CHEST_ID = 1;
const uint32_t FAKE_PORTAL_ID = 2;
const uint32_t FAKE_DOOR_ID = 3;

const uint32_t NORMAL_CHEST_ID = 1;
const uint32_t NORMAL_PORTAL_ID = 2;
const uint32_t NORMAL_DOOR_ID = 3;

const uint32_t WALL_ID = 4;

const uint32_t EXIT_ID = 5;

const uint32_t ENTER_ID = 6;

const uint32_t POSITION_POINTER_ID = 7;

///////////////////////////////////////////////////////////////////////////////

const char PLAYER_CHAR = '@';
const char DOOR_CHAR = ']';
const char PORTAL_CHAR = '0';
const char CHEST_CHAR = '^';
const char WALL_CHAR = '#';
const char EXIT_CHAR = '8';
const char ENTER_CHAR = '%';
const char POSITION_POINTER_CHAR = '_';

///////////////////////////////////////////////////////////////////////////////

const uint32_t PLAYER_COLOR = RED;
const uint32_t DOOR_COLOR = BROWN;
const uint32_t PORTAL_COLOR = MAGENTA;
const uint32_t CHEST_COLOR = GREEN;
const uint32_t WALL_COLOR = WHITE;
const uint32_t EXIT_COLOR = CYAN;
const uint32_t ENTER_COLOR = YELLOW;
const uint32_t POSITION_POINTER_COLOR = MAGENTA;