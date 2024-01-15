// NPCPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>

#include "TheDiceBag.cpp"
using namespace std;

int main()
{
	//AS in this context is ability scores shortened for brevity
	// this is to represent the minimum and maximum amount you can roll on ability scores 
	srand(time(NULL));
	int ASmaxValue = 18;
	int ASminValue = 9;

	//roll ability scores
	int ASroll1 = rand() % (ASmaxValue - ASminValue + 1) + ASminValue; 
	int ASroll2 = rand() % (ASmaxValue - ASminValue + 1) + ASminValue;
	int ASroll3 = rand() % (ASmaxValue - ASminValue + 1) + ASminValue;
	int ASroll4 = rand() % (ASmaxValue - ASminValue + 1) + ASminValue;
	int ASroll5 = rand() % (ASmaxValue - ASminValue + 1) + ASminValue;
	int ASroll6 = rand() % (ASmaxValue - ASminValue + 1) + ASminValue;

	//print the ability scores back
	cout << "Ability Score 1 rolled: " << ASroll1 << endl 
		<< "Ability Score 2 rolled: " << ASroll2 << endl
		<< "Ability Score 3 rolled: " << ASroll3 << endl
		<< "Ability Score 4 rolled: " << ASroll4 << endl
		<< "Ability Score 5 rolled: " << ASroll5 << endl
		<< "Ability Score 6 rolled: " << ASroll6 << endl;
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
	//take user input on where they would like to assign these scores
	cout << "please assign these scores:" << endl;
	cout << setw(10) << "STR: ";
	cin >> str;
	strBonus = Dice::ASModifier(str);

	cout << setw(10) << "DEX: ";
	cin >> dex;
	dexBonus = Dice::ASModifier(dex);

	cout << setw(10) << "CON: ";
	cin >> con;
	conBonus = Dice::ASModifier(con);

	cout << setw(10) << "INT: ";
	cin >> intel;
	intelBonus = Dice::ASModifier(intel);

	cout << setw(10) << "WIS: ";
	cin >> wis;
	wisBonus = Dice::ASModifier(wis);

	cout << setw(10) << "CHA: ";
	cin >> cha;
	chaBonus = Dice::ASModifier(cha);

	int profBonus;
	cout << "What is your proficiency bonus? " << endl;
	cin >> profBonus;
	int miscPhysAttackMod;
	cout << "Any other bonuses to physical attacks? " << endl;
	cin >> miscPhysAttackMod;

	int strBasedAttackBonus = strBonus + profBonus + miscPhysAttackMod;
	int dexBasedAttackBonus = dexBonus + profBonus + miscPhysAttackMod;

	// in this context SC is Spell Casting abbreviated
	cout << "1- WIS" << endl
		<< "2- INT" << endl
		<< "3- CHA" << endl
		<< "Input the number corresponding with your spell casting ability: ";

	short SCinput;
	cin >> SCinput;
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
