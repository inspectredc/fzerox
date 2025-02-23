#ifndef OVL_I4_H
#define OVL_I4_H

#include "libultra/ultra64.h"

typedef enum MachineSelectState {
    MACHINE_SELECT_ACTIVE,
    MACHINE_SELECT_EXIT,
    MACHINE_SELECT_AWAIT_OK,
    MACHINE_SELECT_CONTINUE,
} MachineSelectState;

typedef enum MachineSettingsState {
    MACHINE_SETTINGS_ACTIVE,
    MACHINE_SETTINGS_EXIT,
    MACHINE_SETTINGS_AWAIT_OK,
    MACHINE_SETTINGS_CONTINUE,
} MachineSettingsState;

typedef enum PlayerSelectionLockState {
    SELECTION_FREE,
    SELECTION_LOCKED,
} PlayerSelectionLockState;

#endif // OVL_I4_H
