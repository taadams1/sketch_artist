#include <iostream>
#include <string>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

void addEyes(wstring &, wstring);
void addNose(wstring &, wstring);
void addMouth(wstring &, wstring);
void addHair(wstring &, vector<wstring>);
void addShape(wstring &, vector<wstring>);

int faceRand();

int main() {

	int randEyes, randNose, randMouth, randHair, randShape,
		userEyes, userNose, userMouth, userHair, userShape;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//force output to unicode
	_setmode(_fileno(stdout), _O_U16TEXT);

	//use wide string (L) to hold special characters and string literal (R"()") to ignore escape characters
	wstring faceString = LR"(-------------------------|                       ||                       ||       _________       ||      /         \      ||     /           \     ||    |  ---------  |    ||    | ----------- |    ||    |      |      |    ||    \     d b     /    ||     \   -----   /     ||      \         /      ||        -------        ||                       |-------------------------)";
	//wstring testEyes = LR"(  === ≡ ===  ─(¯¶¯)─(¯¶¯)─)";
	//unsigned char eyeNums[] = { 32,32,61,61,61,32,240,32,61,61,61,32,32,196,40,249,233,249,41,196,40,249,233,249,41,196,40 };
	//wstring testMouth = LR"(/_____\   =   )";
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

	vector <wstring> eyes = {
		LR"(  === ≡ ===  ─(¯¶¯)─(¯¶¯)─)",
		LR"(  ___   ___     õ,' '¸õ   )",
		LR"(  ‗‗‗   ‗‗‗    ~º.   .º~  )",
		LR"(  ___   ___   ¨.ç_   _ç.¨ )",
		LR"(  ___   ___   ¨.ð,> <,ð.¨ )"
	};
	vector <wstring> noses = {
		LR"(   (_))",
		LR"( | '-')",
		LR"(| |«_»)",
		LR"( ≡ d_b)",
		LR"( ¦ d_b)"
	};
	vector <wstring> mouths = {
		LR"(/_____\   =   )",
		LR"( ¬===⌐        )",
		LR"( _‗‗‗_   ¯¯¯  )",
		LR"( -═══-    -   )",
		LR"( =═══=    ¯   )"
	};
	vector <vector<wstring>> hair = {
		hair1, hair2, hair3, hair4, hair5
	};
	vector <vector<wstring>> shape = {
		shape1, shape2, shape3, shape4, shape5
	};

	output = L"";
	wstring criminalFace = faceString;

	randEyes = faceRand();
	randNose = faceRand();
	randMouth = faceRand();
	randHair = faceRand();
	randShape = faceRand();

	addEyes(criminalFace, eyes[randEyes]);
	addNose(criminalFace, noses[randNose]);
	addMouth(criminalFace, mouths[randMouth]);
	addHair(criminalFace, hair[randHair]);
	addShape(criminalFace, shape[randShape]);

	for (int i = 0; i < criminalFace.length(); i++) {
		output += criminalFace.at(i);
		if ((i + 1) % 25 == 0) {
			output += L"\n";
		}
	}
	wcout << output;
	wcout << flush;
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

	wstring eyesMenu[SIZE];
	eyesMenu[0] = LR"(  === ≡ ===  
─(¯¶¯)─(¯¶¯)─)";
	eyesMenu[1] = LR"(  ___   ___  
   õ,' '¸õ   )";
	eyesMenu[2] = LR"(  ‗‗‗   ‗‗‗  
  ~º.   .º~  )";
	eyesMenu[3] = LR"(  ___   ___  
 ¨.ç_   _ç.¨ )";
	eyesMenu[4] = LR"(  ___   ___  
 ¨.ð,> <,ð.¨ )";

	wstring noseMenu[SIZE];
	noseMenu[0] = L"Bigger"; noseMenu[1] = L"Thinner"; noseMenu[2] = L"Higher"; noseMenu[3] = L"Lower"; noseMenu[4] = L"Unibrow";

	wstring mouthMenu[SIZE];
	mouthMenu[0] = L"option"; mouthMenu[1] = L"option"; mouthMenu[2] = L"option"; mouthMenu[3] = L"option"; mouthMenu[4] = L"option";

	wstring hairMenu[SIZE];
	hairMenu[0] = L"option"; hairMenu[1] = L"option"; hairMenu[2] = L"option"; hairMenu[3] = L"option"; hairMenu[4] = L"option";

	wstring shapeMenu[SIZE];
	shapeMenu[0] = L"option"; shapeMenu[1] = L"option"; shapeMenu[2] = L"option"; shapeMenu[3] = L"option"; shapeMenu[4] = L"option";

	while (selection != -1) {
		wcout << L"Please Pick a Feature to Edit: (or -1 to exit)" << endl;
		for (int i = 0; i < 5; i++) {
			wcout << i + 1 << L") ";
			wcout << menu[i] << endl;
		}


		cin >> selection;
		switch (selection) {
		case 1:
			wcout << L"Eye Options: " << endl;
			for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << eyesMenu[i] << endl;
			}
			cin >> selection2;
			break;
		case 2:
			wcout << L"Nose Options: " << endl;
			for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << noseMenu[i] << endl;
			}
			cin >> selection2;
			break;
		case 3:
			wcout << L"Mouth Options: " << endl;
			for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << mouthMenu[i] << endl;
			}
			cin >> selection2;
			break;
		case 4:
			wcout << L"Hair Options: " << endl;
			for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << hairMenu[i] << endl;
			}
			cin >> selection2;
			break;
		case 5:
			wcout << L"Mouth Options: " << endl;
			for (int i = 0; i < SIZE; i++) {
				wcout << i + 1 << L")" << endl;
				wcout << shapeMenu[i] << endl;
			}
			cin >> selection2;
			break;
		default:
			cout << "Please try again" << endl;
			break;
		}

	}
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

void addEyes(wstring &face, wstring eyes) {
	
	face.replace(156, 13, eyes.substr(0,13));
	face.replace(181, 13, eyes.substr(13,25));
}

void addNose(wstring &face, wstring nose) {

	face.replace(211, 3, nose.substr(0, 3));
	face.replace(236, 3, nose.substr(3, 5));
}

void addMouth(wstring &face, wstring mouth) {
	
	face.replace(259, 7, mouth.substr(0,7));
	face.replace(284, 7, mouth.substr(7,13));
}

void addHair(wstring &face, vector<wstring> hair) {

	face.replace(53, 19, hair[0]);
	face.replace(78, 19, hair[1]);
	face.replace(103, 19, hair[2]);
	face.replace(128, 19, hair[3]);
	face.replace(153, 4, (hair[4]).substr(0,4));
	face.replace(168, 4, (hair[4]).substr(4,7));
	face.replace(178, 3, (hair[5]).substr(0, 3));
	face.replace(194, 3, (hair[5]).substr(3, 5));
	face.replace(203, 3, (hair[6]).substr(0, 3));
	face.replace(219, 3, (hair[6]).substr(3, 5));
	face.replace(228, 2, (hair[7]).substr(0, 2));
	face.replace(245, 2, (hair[7]).substr(2, 3));
	face.replace(253, 2, (hair[8]).substr(0, 2));
	face.replace(270, 2, (hair[8]).substr(2, 3));
	face.replace(278, 3, (hair[9]).substr(0, 3));
	face.replace(294, 3, (hair[9]).substr(3, 5));
}

void addShape(wstring &face, vector<wstring> shape) {

	face.replace(230, 4, (shape[0]).substr(0,4));
	face.replace(241, 4, (shape[0]).substr(4, 7));
	face.replace(256, 3, (shape[1]).substr(0, 3));
	face.replace(266, 3, (shape[1]).substr(3, 5));
	face.replace(281, 4, (shape[2]).substr(0, 4));
	face.replace(290, 4, (shape[2]).substr(4, 7));
	face.replace(307, 11, shape[3]);
}

int faceRand() {
	int randNum;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	srand(seed);

	randNum = (int)floor(rand() % 5);

	return randNum;
}

