// NPCPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
///<summary>
///Welcome to NPC++, A Dungeons and Dragons 5e NPC stat generator
///this is licensed under the Unlicense
///You have full permission to download, change, and redistribute this code 
///I have no affiliations with any repos or forks of NPC aside from 
///thefool309/NPCplusplus and it's original repo on my deadname github
///Happy Adventures and Happy Coding!
/// </summary>

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>

#include "TheDiceBag.h"
using namespace std;

int main()
{
	//AS in this context is ability scores shortened for brevity
	// this is to represent the minimum and maximum amount you can roll on ability scores 
	srand(time(NULL));
	int ASmaxValue = 18;
	int ASminValue = 9;

	//roll ability scores
	vector<int> scores = Dice::RollAS();
	//print the ability scores back
	for (int i = 0; i < scores.size(); i++) {
		cout << "Ability Score rolled: " << scores[i] << endl;
	}
	
	

	//define variables for ability scores and bonuses
	int str;
	int strBonus;

	int dex;
	int dexBonus;

	int con;
	int conBonus;

	int intel;
	int intelBonus;

	int wis;
	int wisBonus;

	int cha;
	int chaBonus;

	//as or AS in these contexts stands for ability score

	string asPrimeText = "please assign this score";
	string strPromptText = "          STR: ";
	string dexPromptText = "          DEX: ";
	string conPromptText = "          CON: ";
	string intPromptText = "          INT: ";
	string wisPromptText = "          WIS: ";
	string chaPromptText = "          CHA: ";
	//define input constants for the programs min and max values

	const int PROF_MIN_INPUT = 1; // Proficiency bonus input minimum
	const int PROF_MAX_INPUT = 6; // proficiency bonus input maximum

	const int NUMBER_OF_DICE_MIN = 0; //lowest input for numberOfDice
	const int NUMBER_OF_DICE_MAX = 20;//Highest input for numberOfDice

	const int HITDIE_INPUT_MIN = 0; //lowest input for maxHitDie
	const int HITDIE_INPUT_MAX = 12; //highest input for maxHitDie

	const int MISC_ATTACK_BONUS_MIN = -1; //lowest input for misc attack mods
	const int MISC_ATTACK_BONUS_MAX = 10; //highest input for misc attack mods

	//take user input on where they would like to assign these scores
	UI::TakeAllAbilityScores(str, dex, con, wis, intel, cha, strBonus, dexBonus, conBonus, intelBonus, wisBonus, chaBonus);

	UI::ClearConsole();

	int profBonus;

	string profBonusPrime = "What is your proficiency bonus? ";
	string profBonusPrompt = "Proficiency Bonus: ";				//intake user input on prof bonus
	profBonus = UI::VerifyIntegerInput(PROF_MIN_INPUT, PROF_MAX_INPUT,
										profBonusPrime , profBonusPrompt);

	UI::ClearConsole();

	int miscPhysAttackMod;
	string miscAttackPrime = "Any other bonuses to physical attacks? ";
	string miscAttackPrompt = "Miscellaneous Attack Modifier: ";		//intake user input on misc attack mods
	miscPhysAttackMod = UI::VerifyIntegerInput(MISC_ATTACK_BONUS_MIN, MISC_ATTACK_BONUS_MAX,
												miscAttackPrime, miscAttackPrompt);	
	
	UI::ClearConsole();

	int strBasedAttackBonus = strBonus + profBonus + miscPhysAttackMod; //str based attack bonus
	int dexBasedAttackBonus = dexBonus + profBonus + miscPhysAttackMod; //dex based attack bonus

	// in this context SC is Spell Casting abbreviated
	cout << "1- WIS" << endl
		<< "2- INT" << endl
		<< "3- CHA" << endl
		<< "Input the number corresponding with your spell casting ability: ";

	short SCinput;
	cin >> SCinput;

	UI::ClearConsole();

	int SCattackBonus;
	int spellSaveDC;
	// DC stands for Difficulty Class
	switch (SCinput)
	{
	case 1:
		SCattackBonus = (wisBonus + profBonus);
		spellSaveDC = (8 + wisBonus + profBonus);
		break;
	case 2:
		SCattackBonus = (intelBonus + profBonus);
		spellSaveDC = (8 + intelBonus + profBonus);
		break;
	default:
		SCattackBonus = (chaBonus + profBonus);
		spellSaveDC = (8 + chaBonus + profBonus);
		break;
	}

	int maxHitDie = 0;
	//define prompts for the ui input method
	string hitdiePrime = "Please enter the maximum value of the hit die";
	string hitdiePrompt = "Largest Number on Hit Die: ";
	

	//user inputs maxHitDie and program verifies that it is in range
	maxHitDie = UI::VerifyIntegerInput(HITDIE_INPUT_MIN, HITDIE_INPUT_MAX, hitdiePrime, hitdiePrompt);
	
	UI::ClearConsole();

	int numberOfDice = 0;
	//define prompts for the ui input method
	string numberOfDicePrime = "Please enter the number of Hit Dice (a.k.a. the LVL)";
	string numberOfDicePrompt = "Number of Hit Dice: ";
	

	//user inputs numberOfDice and program verifies that it is in range
	numberOfDice = UI::VerifyIntegerInput(NUMBER_OF_DICE_MIN, NUMBER_OF_DICE_MAX, numberOfDicePrime, numberOfDicePrompt);

	UI::ClearConsole();

	int hitpoints = Dice::RollHP(maxHitDie, numberOfDice, conBonus);

	cout << "these are your final scores:" << endl
		<< setw(10) << "STR:" << setw(3) << str << setw(3)
		<< "  STR Bonus: " << setw(3) << strBonus << endl

		<< setw(10) << "DEX:" << setw(3) << dex << setw(3)
		<< "  DEX Bonus: " << setw(3) << dexBonus << endl

		<< setw(10) << "CON:" << setw(3) << con << setw(3)
		<< "  CON Bonus: " << setw(3) << conBonus << endl

		<< setw(10) << "INT:" << setw(3) << intel << setw(3)
		<< "  INT Bonus: " << setw(3) << intelBonus << endl

		<< setw(10) << "WIS:" << setw(3) << wis << setw(3)
		<< "  WIS Bonus: " << setw(3) << wisBonus << endl

		<< setw(10) << "CHA:" << setw(3) << cha << setw(3)
		<< "  CHA Bonus: " << setw(3) << chaBonus << endl;

	cin.get();

	cout << "These are your attack bonuses: " << endl
		<< "STR based Attack Bonus: " << strBasedAttackBonus << endl
		<< "DEX based Attack Bonus: " << dexBasedAttackBonus << endl << endl << endl;

	cout << "Your Spell attack bonus: " << SCattackBonus << endl
		<< "Your Spell Save DC: " << spellSaveDC << endl;

	cin.get();

	cout << endl << "Your HitPoints: " << hitpoints << endl;

	cout << "Press any key to continue...";

	cin.get();
	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
