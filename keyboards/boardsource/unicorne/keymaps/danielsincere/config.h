#pragma once
#include <stdint.h>
#define POINTING_DEVICE_ROTATION_270
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_LGUI_SWAP

typedef struct _master_to_slave_t {
    int8_t is_swapped;
} master_to_slave_t;
