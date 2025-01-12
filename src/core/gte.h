// SPDX-FileCopyrightText: 2019-2022 Connor McLaughlin <stenzek@gmail.com>
// SPDX-License-Identifier: (GPL-3.0 OR CC-BY-NC-ND-4.0)

#pragma once
#include "gte_types.h"

class StateWrapper;

namespace GTE {

void Initialize();
void Reset();
bool DoState(StateWrapper& sw);
void UpdateAspectRatio();

// control registers are offset by +32
u32 ReadRegister(u32 index);
void WriteRegister(u32 index, u32 value);

// use with care, direct register access
u32* GetRegisterPtr(u32 index);

void ExecuteInstruction(u32 inst_bits);

using InstructionImpl = void (*)(Instruction);
InstructionImpl GetInstructionImpl(u32 inst_bits, TickCount* ticks);

const char* GetRegisterName(u32 index);

} // namespace GTE
