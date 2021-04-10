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

///////////////////////////////////////////////////////////////////////////////

const char PLAYER_CHAR = '@';
const char DOOR_CHAR = ']';
const char PORTAL_CHAR = '0';
const char CHEST_CHAR = '^';
const char WALL_CHAR = '#';

///////////////////////////////////////////////////////////////////////////////

const uint32_t PLAYER_COLOR = DARKGREY;
const uint32_t DOOR_COLOR = BROWN;
const uint32_t PORTAL_COLOR = MAGENTA;
const uint32_t CHEST_COLOR = GREEN;
const uint32_t WALL_COLOR = WHITE;