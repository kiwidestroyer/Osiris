#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "../Interfaces.h"
#include "../Memory.h"
#include "Triggerbot.h"

void runTriggerbot(UserCmd* cmd)
{
    if (GetAsyncKeyState(VK_MENU) & 1) {
        auto inCrosshair = (*memory.localPlayer)->getCrosshairID();
        if (inCrosshair > 0 && inCrosshair <= 64) {
            auto target = interfaces.clientEntityList->getClientEntity(inCrosshair);
            if (!reinterpret_cast<ClientEntity*>(target)->IsDormant() && target->getTeamNumber() != (*memory.localPlayer)->getTeamNumber())
            {
                constexpr int IN_ATTACK{ 1 };
                cmd->buttons |= IN_ATTACK;
            }
        }
    }
}