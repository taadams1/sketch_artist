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

void addEyes(wstring &, vector<wstring>);
void addNose(wstring &, vector<wstring>);
void addMouth(wstring &, vector<wstring>);
void addHair(wstring &, vector<wstring>);
void addShape(wstring &, vector<wstring>);
void displayFace(wstring);

int faceRand();

int main() {

	Face testFace;

	int randEyes, randNose, randMouth, randHair, randShape,
		userEyes, userNose, userMouth, userHair, userShape;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//force output to unicode
	_setmode(_fileno(stdout), _O_U16TEXT);

	//use wide string (L) to hold special characters and string literal (R"()") to ignore escape characters
	wstring faceString = LR"(-------------------------|                       ||                       ||       _________       ||      /         \      ||     /           \     ||    |  ---------  |    ||    | ----------- |    ||    |      |      |    ||    \     d b     /    ||     \   -----   /     ||      \         /      ||        -------        ||                       |-------------------------)";
	
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

	output = L"";
	wstring criminalFace = faceString;
	vector<wstring> criminalVec = faceTemplate;

	randEyes = faceRand();
	randNose = faceRand();
	randMouth = faceRand();
	randHair = faceRand();
	randShape = faceRand();

	/*addEyes(criminalFace, eyes[randEyes]);
	addNose(criminalFace, noses[randNose]);
	addMouth(criminalFace, mouths[randMouth]);
	addHair(criminalFace, hair[randHair]);
	addShape(criminalFace, shape[randShape]);*/

	testFace.AddEyes(criminalVec, eyes[randEyes]);
	testFace.AddNose(criminalVec, noses[randNose]);
	testFace.AddMouth(criminalVec, mouths[randMouth]);
	testFace.AddHair(criminalVec, hair[randHair]);
	testFace.AddShape(criminalVec, shape[randShape]);

	/*/for (int i = 0; i < criminalFace.length(); i++) {
		output += criminalFace.at(i);
		if ((i + 1) % 25 == 0) {
			output += L"\n";
		}
	}
	wcout << output;
	wcout << endl;*/

	testFace.DisplayFace(criminalVec);

	std::this_thread::sleep_for(std::chrono::milliseconds(1300));
	system("CLS");

	wcout << L"The criminal got away!" << endl;
	wcout << L"Help the detective by describing the criminal." << endl;

	wstring playerFace = faceString;
	output = L"";

	for (int i = 0; i < playerFace.length(); i++) {
		output += playerFace.at(i);
		if ((i + 1) % 25 == 0) {
			output += L"\n";
		}

	}

	wcout << output << endl;

	//menu code by Mikaela

	int selection = 0;
	int selection2 = 0;
	const int SIZE = 5;
	wstring menu[SIZE];
	menu[0] = L"Eyes"; menu[1] = L"Nose"; menu[2] = L"Mouth"; menu[3] = L"Hair"; menu[4] = L"Face Shape";

	vector <wstring> eyesMenu = {
		L"  === ≡ ===  \n─(¯¶¯)─(¯¶¯)─",
		L"  ___   ___    \n   õ,' '¸õ   ",
		L"  ‗‗‗    ‗‗‗    \n  ~º.   .º~  ",
		L"  ___   ___   \n ¨.ç_   _ç.¨ ",
		L"  ___   ___   \n ¨.ð,> <,ð.¨ "
	};
	
	vector <wstring> noseMenu = {
		L"   \n(_)",
		L" | \n'-'",
		L"| |\n«_»",
		L" ≡ \nd_b",
		L" ¦ \nd_b"
	};
	
	vector <wstring> mouthMenu = {
		L"/_____\\\n   =   ",
		L" ¬===⌐\n        ",
		L" _‗‗‗_\n  ¯¯¯  ",
		L" -═══-\n   -   ",
		L" =═══=\n   ¯   "
	};

	wstring hairMenu[SIZE];

	wstring shapeMenu[SIZE];

	vector<vector<wstring>> opts;//test for face shape output

	int count = 0;
	while (count < 5) {
		wcout << L"Please Pick a Feature to Edit:" << endl;
		for (int i = 0; i < 5; i++) {
			wcout << i + 1 << L") ";
			wcout << menu[i] << endl;
		}

		cin >> selection;
		switch (selection) {
		case 1:
			wcout << L"Eye Options: " << endl;
			/*for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << eyesMenu[i] << endl;
			}*/
			testFace.MenuOptions(eyes);
			cin >> selection2;
			addEyes(playerFace, eyes[selection2 -1]);
			output = L"";
			for (int i = 0; i < playerFace.length(); i++) {
				output += playerFace.at(i);
			if ((i + 1) % 25 == 0) {
				output += L"\n";
				}
			}
			wcout << output << endl;
			break;
		case 2:
			wcout << L"Nose Options: " << endl;
			/*for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")\n" << endl;
				wcout << noseMenu[i] << endl;
			}*/
			testFace.MenuOptions(noses);
			cin >> selection2;
			addNose(playerFace, noses[selection2 -1]);
			output = L"";
			for (int i = 0; i < playerFace.length(); i++) {
				output += playerFace.at(i);
			if ((i + 1) % 25 == 0) {
				output += L"\n";
				}
			}
			wcout << output << endl;
			break;
		case 3:
			wcout << L"Mouth Options: " << endl;
			/*for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << mouthMenu[i] << endl;
			}*/
			testFace.MenuOptions(mouths);
			cin >> selection2;
			addMouth(playerFace, mouths[selection2 -1]);
			output = L"";
			for (int i = 0; i < playerFace.length(); i++) {
				output += playerFace.at(i);
			if ((i + 1) % 25 == 0) {
				output += L"\n";
				}
			}
			wcout << output << endl;
			break;
		case 4:
			wcout << L"Hair Options: " << endl;
			opts.clear();
			for (int i = 0; i < SIZE; i++) {
				//wcout << i + 1 << L")" << endl;
				//wstring hairOpt = faceString;
				vector<wstring> hairOpt = faceTemplate;
				//addHair(hairOpt, hair[i]);
				testFace.AddHair(hairOpt, hair[i]);
				opts.push_back(hairOpt);
				//displayFace(hairOpt);
			}
			testFace.MenuOptions(opts);
			cin >> selection2;
			addHair(playerFace, hair[selection2 -1]);
			output = L"";
			for (int i = 0; i < playerFace.length(); i++) {
				output += playerFace.at(i);
			if ((i + 1) % 25 == 0) {
				output += L"\n";
				}
			}
			wcout << output << endl;
			break;
		case 5:
			wcout << L"Face Shape Options: " << endl;
			opts.clear();
			for (int i = 0; i < SIZE; i++) {
				//wcout << i + 1 << L")" << endl;
				//wstring shapeOpt = faceString;
				vector<wstring> shapeOpt = faceTemplate;
				//addShape(shapeOpt, shape[i]);
				testFace.AddShape(shapeOpt, shape[i]);
				opts.push_back(shapeOpt);
			}
			testFace.MenuOptions(opts);
			cin >> selection2;
			addShape(playerFace, shape[selection2 -1]);
			output = L"";
			for (int i = 0; i < playerFace.length(); i++) {
				output += playerFace.at(i);
			if ((i + 1) % 25 == 0) {
				output += L"\n";
				}
			}
			wcout << output << endl;
			break;
		default:
			cout << "Please try again" << endl;
			break;
		}

	}
	count++;
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	//system("CLS");


	
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

void displayFace(wstring face) {
	wstring display;
	for (int i = 0; i < face.length(); i++) {
		display += face.at(i);
		if ((i + 1) % 25 == 0) {
			display += L"\n";
		}
	}
	wcout << display << endl;
}

