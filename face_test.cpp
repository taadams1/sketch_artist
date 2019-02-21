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

	//vector <vector <wstring>> features = { eyes, noses, mouths, hair, faces };

	//features[0][0] = testEyes;
	//features[2][0] = testMouth;

	/*for (int i = 0; i < 26; i++) {
		cout << eyeNums[i] << " ";
	}*/
	/*cout << "{";
	for (int i = 32; i < 255; i++) {

		cout << (char)i << ",";

	}
	cout << "}";*/

	for (int i = 0; i < faceString.length(); i++) {
		output += faceString.at(i);
		if ((i + 1) % 25 == 0) {
			output += L"\n";
		}
		
	}

	wcout << output << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("CLS");

	for (int i = 0; i < 14; i++) {
		output = L"";
		wstring faceString = LR"(-------------------------|                       ||                       ||       _________       ||      /         \      ||     /           \     ||    |  ---------  |    ||    | ----------- |    ||    |      |      |    ||    \     d b     /    ||     \   -----   /     ||      \         /      ||        -------        ||                       |-------------------------)";
		addEyes(faceString, eyes[faceRand()]);
		addNose(faceString, noses[faceRand()]);
		addMouth(faceString, mouths[faceRand()]);
		addHair(faceString, hair[faceRand()]);
		addShape(faceString, shape[faceRand()]);

		for (int i = 0; i < faceString.length(); i++) {
			output += faceString.at(i);
			if ((i + 1) % 25 == 0) {
				output += L"\n";
			}
		}
		wcout << output;
		wcout << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1300));
		system("CLS");

	}
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

