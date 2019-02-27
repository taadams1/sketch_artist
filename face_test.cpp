#include <iostream>
#include <string>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>

#include "Face.h"

using namespace std;

enum Difficulty { hard = 5, medium = 8, easy = 10, };

int faceRand();

int main() {

	Face testFace;

	int randEyes, randNose, randMouth, randHair, randShape,
		userEyes, userNose, userMouth, userHair, userShape;

	float score = 0;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//force output to unicode
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"Notice: The terminal may need to be resized for the best experience." << endl;
	for (int i = 0; i < 9; i++) {
		wcout << L".";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	system("CLS");

	//use wide string (L) to hold special characters and string literal (R"()") to ignore escape characters
	
	vector<wstring> faceTemplate = {
		LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|       _________       |)",
		LR"(|      /         \      |)",
		LR"(|     /           \     |)",
		LR"(|    |  ---------  |    |)",
		LR"(|    | ----------- |    |)",
		LR"(|    |      |      |    |)",
		LR"(|    \     d b     /    |)",
		LR"(|     \   -----   /     |)",
		LR"(|      \         /      |)",
		LR"(|        -------        |)",
		LR"(|                       |)",
		LR"(-------------------------)" };
	
	wstring output;

	//facial features hard coded
	vector <wstring> hair1 = {
		LR"(                   )",
		LR"(     _________     )",
		LR"(    / ´    -  \    )",
		LR"(   /     ¨     \   )",
		LR"(  |  |  )",
		LR"( (||) )",
		LR"(  ||  )",
		LR"(    )",
		LR"(    )",
		LR"(      )"
	};
	vector <wstring> hair2 = {
		LR"(     __ ______     )",
		LR"(    ´/ ¯   \  `    )",
		LR"(  ( / /   \  \ (   )",
		LR"( ) ) ( (   )  ) )  )",
		LR"( |((( ( )",
		LR"( ))|| )",
		LR"( (||( )",
		LR"( )) )",
		LR"(( ) )",
		LR"( ) (  )"
	};
	vector <wstring> hair3 = {
		LR"(                   )",
		LR"(    ///////V\\\    )",
		LR"(   ////////\\\\\   )",
		LR"(  ////////  \\\\\  )",
		LR"( ///\\\ )",
		LR"( ┌||┐ )",
		LR"( └||┘ )",
		LR"(    )",
		LR"(    )",
		LR"(      )"
	};
	vector <wstring> hair4 = {
		LR"(                   )",
		LR"(    ╔║║║║║║║║║╗    )",
		LR"(   ╔║║║║║║║║║║║╗   )",
		LR"(  ╔║║         ║║╗  )",
		LR"(  ║║║║  )",
		LR"( {||} )",
		LR"( '||' )",
		LR"(    )",
		LR"(    )",
		LR"(      )"
	};
	vector <wstring> hair5 = {
		LR"(    ((())()(())    )",
		LR"(   ()())()(()())   )",
		LR"(  ((()()())()(())  )",
		LR"( ()(()       (()() )",
		LR"( ())()) )",
		LR"( )()( )",
		LR"( (||) )",
		LR"( )( )",
		LR"(    )",
		LR"(      )"
	};

	vector <wstring> shape1 = {
		LR"( \    / )",
		LR"( \  / )",
		LR"(  \  /  )",
		LR"(   -----   )"
	};
	vector <wstring> shape2 = {
		LR"(\      /)",
		LR"(\ `´ /)",
		LR"( `-__-´ )",
		LR"(   ¯¯¯¯¯   )"
	};
	vector <wstring> shape3 = {
		LR"(\  .   /)",
		LR"(\    /)",
		LR"( \    / )",
		LR"( ´'-----'` )"
	};
	vector <wstring> shape4 = {
		LR"(\      /)",
		LR"(\    /)",
		LR"( `.  .´ )",
		LR"(  ¯ --- ¯  )"
	};
	vector <wstring> shape5 = {
		LR"(\      /)",
		LR"(\    /)",
		LR"(  \  /  )",
		LR"(  ¯ --- ¯  )"
	};

	vector <vector<wstring>> eyes = {
		{LR"(  === ≡ ===  )",LR"(─(¯¶¯)─(¯¶¯)─)"},
		{LR"(  ___   ___  )",LR"(   õ,' '¸õ   )"},
		{LR"(  ‗‗‗   ‗‗‗  )",LR"(  ~º.   .º~  )"},
		{LR"(  ___   ___  )",LR"( ¨.ç_   _ç.¨ )"},
		{LR"(  ___   ___  )",LR"( ¨.ð,> <,ð.¨ )"}
	};
	vector <vector<wstring>> noses = {
		{LR"(   )",LR"((_))"},
		{LR"( | )",LR"('-')"},
		{LR"(| |)",LR"(«_»)"},
		{LR"( ≡ )",LR"(d_b)"},
		{LR"( ¦ )",LR"(d_b)"}
	};
	vector <vector<wstring>> mouths = {
		{LR"(/_____\)",LR"(   =   )"},
		{LR"( ¬===⌐ )",LR"(       )"},
		{LR"( _‗‗‗_ )",LR"(  ¯¯¯  )"},
		{LR"( -═══- )",LR"(   -   )"},
		{LR"( =═══= )",LR"(   ¯   )"}
	};
	vector <vector<wstring>> hair = {
		hair1, hair2, hair3, hair4, hair5
	};
	vector <vector<wstring>> shape = {
		shape1, shape2, shape3, shape4, shape5
	};

	//create template for criminal face
	vector<wstring> criminalFace = faceTemplate;

	//choose and track values for criminal features
	randEyes = faceRand();
	randNose = faceRand();
	randMouth = faceRand();
	randHair = faceRand();
	randShape = faceRand();

	//call face class functions to construct criminal face
	testFace.AddEyes(criminalFace, eyes[randEyes]);
	testFace.AddNose(criminalFace, noses[randNose]);
	testFace.AddMouth(criminalFace, mouths[randMouth]);
	testFace.AddHair(criminalFace, hair[randHair]);
	testFace.AddShape(criminalFace, shape[randShape]);

	//display criminal face
	testFace.DisplayFace(criminalFace);
	//wait then clear criminal face
	//todo - make this more intersting (animation?)
	std::this_thread::sleep_for(std::chrono::milliseconds(1700));
	system("CLS");

	//flavor text placeholder
	wcout << L"The criminal got away!" << endl;
	wcout << L"Help the detective by describing the criminal." << endl;

	//difficulty choice and tutorial around the start
	int difficulty = hard;

	wcout << L"You have " << to_wstring(hard) << L" choices." << endl;

	//create template for player face
	vector<wstring> playerFace = faceTemplate;

	testFace.DisplayFace(playerFace);

	//menu code by Mikaela
	//track player choices for menu
	int selection = 0;
	int selection2 = 0;
	
	//menu options
	const int SIZE = 5;
	wstring menu[SIZE];
	menu[0] = L"Eyes"; menu[1] = L"Nose"; menu[2] = L"Mouth"; menu[3] = L"Hair"; menu[4] = L"Face Shape";


	vector<vector<wstring>> opts;//vector to hold features for menu options

	int count = 0;
	while (count < difficulty) {
		wcout << L"Please Pick a Feature to Edit:" << endl;
		for (int i = 0; i < 5; i++) {
			wcout << i + 1 << L") ";
			wcout << menu[i] << endl;
		}

		cin >> selection;
		switch (selection) {
		case 1:
			wcout << L"Eye Options: " << endl;
			testFace.MenuOptions(eyes);

			cin >> selection2;
			userEyes = selection2 - 1;
			testFace.AddEyes(playerFace, eyes[selection2 -1]);

			system("CLS");
			testFace.DisplayFace(playerFace);
			
			break;
		case 2:
			wcout << L"Nose Options: " << endl;
			
			testFace.MenuOptions(noses);
			cin >> selection2;
			userNose = selection2 - 1;
			testFace.AddNose(playerFace, noses[selection2 -1]);
			
			system("CLS");
			testFace.DisplayFace(playerFace);
			break;
		case 3:
			wcout << L"Mouth Options: " << endl;
			
			testFace.MenuOptions(mouths);
			cin >> selection2;
			userMouth = selection2 - 1;
			testFace.AddMouth(playerFace, mouths[selection2 -1]);
			
			system("CLS");
			testFace.DisplayFace(playerFace);
			break;
		case 4:
			wcout << L"Hair Options: " << endl;
			opts.clear();
			for (int i = 0; i < SIZE; i++) {
				
				vector<wstring> hairOpt = faceTemplate;
				
				testFace.AddHair(hairOpt, hair[i]);
				opts.push_back(hairOpt);
				
			}
			testFace.MenuOptions(opts);
			cin >> selection2;
			userHair = selection2 - 1;
			testFace.AddHair(playerFace, hair[selection2 -1]);
			
			system("CLS");
			testFace.DisplayFace(playerFace);
			break;
		case 5:
			wcout << L"Face Shape Options: " << endl;
			opts.clear();
			for (int i = 0; i < SIZE; i++) {
				
				vector<wstring> shapeOpt = faceTemplate;
				
				testFace.AddShape(shapeOpt, shape[i]);
				opts.push_back(shapeOpt);
			}
			testFace.MenuOptions(opts);
			cin >> selection2;
			userShape = selection2 - 1;
			testFace.AddShape(playerFace, shape[selection2 -1]);
			
			system("CLS");
			testFace.DisplayFace(playerFace);
			break;
		default:
			wcout << L"Please try again" << endl;
			break;
		}

		count++;

	}

	if (randEyes == userEyes) {
		score++;
	}
	if (randNose == userNose) {
		score++;
	}
	if (randMouth == userMouth) {
		score++;
	}
	if (randHair == userHair) {
		score++;
	}
	if (randShape == userShape) {
		score++;
	}

	wcout << L"You recreated the criminal's features with " << (score * 20);
	wcout << L"% accuracy." << endl;
	wcout << L"-----------------" << endl;
	wcout << L"|    Criminal   |" << endl;
	wcout << L"-----------------" << endl << endl;

	testFace.DisplayFace(criminalFace);


	
	char exit;
	wcout << L"Exit? (y/n): ";
	cin >> exit;
	if (exit == 'y' || exit == 'n')//exit delay to look at faces
	{
		return 0;
	}
}


//faceRand returns random number between 0 and 4 for index of facial features
int faceRand() {
	int randNum;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	srand(seed);

	randNum = (rand() % 5);

	return randNum;
}


