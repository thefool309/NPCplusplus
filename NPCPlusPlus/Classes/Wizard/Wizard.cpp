#include "Wizard.h"

void Wizard::DetermineSpellStats()
{
	SpellSave(8 + IntelBonus() + ProfBonus());	//spell save and spell attack
	SpellAttack(IntelBonus() + ProfBonus());

	switch (Lvl()) {
	case 1:
		mCantripsKnown = 2;
		mSpellSlots["Level 1"] = 2;
		break;
	case 2:
		mCantripsKnown = 2;
		mSpellSlots["Level 1"] = 3;
		break;
	case 3:
		mCantripsKnown = 2;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 2;
		break;
	case 4:
		mCantripsKnown = 3;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		break;
	case 5:
		mCantripsKnown = 3;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 2;
		break;
	case 6:
		mCantripsKnown = 3;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		break;
	case 7:
		mCantripsKnown = 3;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 1;
		break;
	case 8:
		mCantripsKnown = 3;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 2;
		break;
	case 9:
		mCantripsKnown = 3;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 1;
		break;
	case 10:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		break;
	case 11:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		break;
	case 12:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		break;
	case 13:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		mSpellSlots["Level 7"] = 1;
		break;
	case 14:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		mSpellSlots["Level 7"] = 1;
		break;
	case 15:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		mSpellSlots["Level 7"] = 1;
		mSpellSlots["Level 8"] = 1;
		break;
	case 16:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		mSpellSlots["Level 7"] = 1;
		mSpellSlots["Level 8"] = 1;
		break;
	case 17:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		mSpellSlots["Level 7"] = 1;
		mSpellSlots["Level 8"] = 1;
		mSpellSlots["Level 9"] = 1;
		break;
	case 18:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 1;
		mSpellSlots["Level 7"] = 1;
		mSpellSlots["Level 8"] = 1;
		mSpellSlots["Level 9"] = 1;
		break;
	case 19:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 2;
		mSpellSlots["Level 7"] = 1;
		mSpellSlots["Level 8"] = 1;
		mSpellSlots["Level 9"] = 1;
		break;
	default:
		mCantripsKnown = 4;
		mSpellSlots["Level 1"] = 4;
		mSpellSlots["Level 2"] = 3;
		mSpellSlots["Level 3"] = 3;
		mSpellSlots["Level 4"] = 3;
		mSpellSlots["Level 5"] = 2;
		mSpellSlots["Level 6"] = 2;
		mSpellSlots["Level 7"] = 2;
		mSpellSlots["Level 8"] = 1;
		mSpellSlots["Level 9"] = 1;
		break;
	}
}

void Wizard::DetermineArcaneRecovery()
{
	mArcaneRecovery = Lvl() / 2;
}
