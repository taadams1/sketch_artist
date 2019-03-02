//Advanced C++ Midterm Group Project
//Trevor Adams, taadams1@dmacc.edu
//Mikaela Stanislav, mstanislav@dmacc.edu
//Ethan Douglass, etdouglass@dmacc.edu
//Alan Sanders, acsanders1@dmacc.edu

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
#include "Asciimation.h"

using namespace std;

enum Difficulty { hard = 5, medium = 8, easy = 10, };

//Functions - Trevor Adams
int faceRand();
bool selectionRange(int);

//Functions - Ethan Douglass
void intro(int random);


int main() {

	//initialize Face class
	Face testFace;
	//initialize Asciimation class
	Asciimation hideFace;
	//set animation to reveal face
	hideFace.RevealFace();

	int randEyes, randNose, randMouth, randHair, randShape;
	//initialize with negative one in case feature is not selected in game
	int	userEyes = -1;
	int userNose = -1;
	int userMouth = -1;
	int userHair = -1;
	int userShape = -1;

	float score = 0;

	//flag to quit game
	bool quit = false;

	//seed for rand
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//force output to unicode
	_setmode(_fileno(stdout), _O_U16TEXT);

	//print notice about optimal window size
	wcout << L"Notice: The terminal may need to be resized for the best experience." << endl;
	for (int i = 0; i < 9; i++) {
		wcout << L".";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	system("CLS");

	//use wide string (L) to hold special characters and
	//string literal (R"()") to ignore escape characters
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
	

	//facial features hard coded
	//todo - move to face class
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

	//main game loop
	while (!quit) {

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

		//difficulty choice hard coded
		//todo - give player choice for difficulty
		int difficulty = hard;

		//intro and randIntro by Ethan Douglass
		string beginningInput;

		wcout << L"	Living in this city isn’t easy.  \nWhat other cities would classify as a rare meteorological natural disaster, happen as if it’s just another Tuesday.\n";
		wcout << L"At first, the ice cream snows, spaghetti showers and burger blizzards built the town into a tourist powerhouse;  \nBringing attention to a small, formerly uninteresting island in the middle of the atlantic.\n";
		wcout << L"The newsreels were rolling, spinning and spiraling out of control, “Flint Lockwood!  Genius inventor of food weather!”, “World food problems solved? \nFlint Lockwood and his food weather machine, the FLDSMDFR!”.\n";
		wcout << L"	The new, quite untested, FLDSMDFR and Lockwood found themselves on every tv screen in the midwest.\n";
		wcout << L"But soon after the first waves of treats;  \nCrammed in every corner and crevice were sticky sweets, savory meats; \nOnce revered scientific feats that permeate still throughout the sewers and streets.\n";
		wcout << L"Buckling building buttresses, and guiding this gilded town straight into the ground.\n";
		wcout << L"\n	I ponder daily why I stay in this town.  I ponder daily why I do not instead wonder.  \nThen of course ponder whether pondering is any different than wondering; and if so, how?\n";
		wcout << L"Anyway, I wonder this as my tires squeal and cut through the pooling pink lemonade puddled by the side of the road;\n";
		wcout << L"My mind is directed back to the present as I hear the satisfying click of the car’s gears shifting into park.\n";
		wcout << L"Reaching to the carseat in the back, I squeeze down on Tim’s tiny toes to wake him up and shift to undo his buckles.\n";
		wcout << L"Swinging my feet out of the car, I can taste the sweet, pink rain as it rolls down my face.\n";

		wcout << L" Enter any key to continue...\n";
		cin >> beginningInput;

		int randomIntro = rand() % 5;
		intro(randomIntro);

		wcout << L" \n\nEnter any key to continue...\n";
		cin >> beginningInput;

		//animation for revealing face
		hideFace.Animate();

		//display criminal face
		testFace.DisplayFace(criminalFace);
		//wait then clear criminal face
		//todo - make this more intersting (animation?)
		std::this_thread::sleep_for(std::chrono::milliseconds(600*difficulty));
		system("CLS");


		//flavor text placeholder
		wcout << L"Help locate this person by describing their face." << endl;


		wcout << L"You have " << to_wstring(hard) << L" choices." << endl;

		//create template for player face
		vector<wstring> playerFace = faceTemplate;

		testFace.DisplayFace(playerFace);

		//menu code by Mikaela Stanislav
		//track player choices for menu
		char selection = '0';
		int selection2 = 0;

		//menu options
		const int SIZE = 5;
		wstring menu[SIZE];
		menu[0] = L"Eyes"; menu[1] = L"Nose"; menu[2] = L"Mouth"; menu[3] = L"Hair"; menu[4] = L"Face Shape";


		vector<vector<wstring>> opts;//vector to hold features for menu options

		int count = 0;
		while (count < difficulty) {
						
			bool validSelection = true;
			do {

				wcout << L"Please Pick a Feature to Edit:" << endl;
				wcout << L"To exit enter X" << endl;
				for (int i = 0; i < 5; i++) {
					wcout << i + 1 << L") ";
					wcout << menu[i] << endl;
				}
				
				cin >> selection;
				switch (selection) {
				case 'X':
				case 'x':
					wcout << L"Goodbye.";
					std::this_thread::sleep_for(std::chrono::milliseconds(2000));
					return 0;
				case '1':
					wcout << L"Eye Options: " << endl;
					opts.clear();
					for (int i = 0; i < SIZE; i++) {

						vector<wstring> eyeOpt = faceTemplate;

						testFace.AddEyes(eyeOpt, eyes[i]);
						opts.push_back(eyeOpt);

					}
					testFace.MenuOptions(opts);
					cin >> selection2;
					if (!selectionRange(selection2)) {
						wcout << L"Enter correct number for feature selection." << endl;
						break;
					}
					userEyes = selection2 - 1;
					testFace.AddEyes(playerFace, eyes[selection2 - 1]);

					system("CLS");
					testFace.DisplayFace(playerFace);

					break;
				case '2':
					wcout << L"Nose Options: " << endl;
					opts.clear();
					for (int i = 0; i < SIZE; i++) {

						vector<wstring> noseOpt = faceTemplate;

						testFace.AddNose(noseOpt, noses[i]);
						opts.push_back(noseOpt);

					}
					testFace.MenuOptions(opts);
					cin >> selection2;
					if (!selectionRange(selection2)) {
						wcout << L"Enter correct number for feature selection." << endl;
						break;
					}
					userNose = selection2 - 1;
					testFace.AddNose(playerFace, noses[selection2 - 1]);

					system("CLS");
					testFace.DisplayFace(playerFace);
					break;
				case '3':
					wcout << L"Mouth Options: " << endl;
					opts.clear();
					for (int i = 0; i < SIZE; i++) {

						vector<wstring> mouthOpt = faceTemplate;

						testFace.AddMouth(mouthOpt, mouths[i]);
						opts.push_back(mouthOpt);

					}
					testFace.MenuOptions(opts);
					cin >> selection2;
					if (!selectionRange(selection2)) {
						wcout << L"Enter correct number for feature selection." << endl;
						break;
					}
					userMouth = selection2 - 1;
					testFace.AddMouth(playerFace, mouths[selection2 - 1]);

					system("CLS");
					testFace.DisplayFace(playerFace);
					break;
				case '4':
					wcout << L"Hair Options: " << endl;
					opts.clear();
					for (int i = 0; i < SIZE; i++) {

						vector<wstring> hairOpt = faceTemplate;

						testFace.AddHair(hairOpt, hair[i]);
						opts.push_back(hairOpt);

					}
					testFace.MenuOptions(opts);
					cin >> selection2;
					if (!selectionRange(selection2)) {
						wcout << L"Enter correct number for feature selection." << endl;
						break;
					}
					userHair = selection2 - 1;
					testFace.AddHair(playerFace, hair[selection2 - 1]);

					system("CLS");
					testFace.DisplayFace(playerFace);
					break;
				case '5':
					wcout << L"Face Shape Options: " << endl;
					opts.clear();
					for (int i = 0; i < SIZE; i++) {

						vector<wstring> shapeOpt = faceTemplate;

						testFace.AddShape(shapeOpt, shape[i]);
						opts.push_back(shapeOpt);
					}
					testFace.MenuOptions(opts);
					cin >> selection2;
					if (!selectionRange(selection2)) {
						wcout << L"Enter correct number for feature selection." << endl;
						break;
					}
					userShape = selection2 - 1;
					testFace.AddShape(playerFace, shape[selection2 - 1]);

					system("CLS");
					testFace.DisplayFace(playerFace);
					break;
				default:
					wcout << L"Please try again" << endl;
					validSelection = false;
					break;
				}
			} while (!validSelection);

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

		wcout << L"You recreated their features with " << (score * 20);
		wcout << L"% accuracy." << endl;
		wcout << L"-----------------" << endl;
		wcout << L"|   Comparison  |" << endl;
		wcout << L"-----------------" << endl;

		testFace.DisplayFace(criminalFace);


		//ask if user wants to play again
		char exit;
		bool exitFlag = false;

		do {
			
			wcout << L"Would you like to play again?(y/n): ";
			cin >> exit;
			if (exit == 'y' || exit == 'Y')
			{
				quit = false;
				exitFlag = true;
				system("CLS");
			}
			else if (exit == 'n' || exit == 'N')
			{
				quit = true;
				exitFlag = true;
			}
			else
			{
				wcout << L"Please enter valid option." << endl;
				exitFlag = false;
			}
		} while (!exitFlag);
	}
	wcout << L"Goodbye.";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	return 0;
}


//faceRand returns random number between 0 and 4 for index of facial features
int faceRand() {
	int randNum;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	srand(seed);

	randNum = (rand() % 5);

	return randNum;
}

//check for correct value in menu selection
bool selectionRange(int s) {
	if (s > 0 && s < 6) {
		return true;
	}
	return false;
}


//intro and rand intro by Ethan Douglass
void intro(int random) {

	if (random == 0) {


		wcout << L"\n\n	My eye catches some movement to my right;  A man walking down the sidewalk holding a banana phone to his ear.\n";
		wcout << L"Kind of odd to be having a stroll in this weather, but to each his own I guess.  I reach for the back door of the car.\n";
		wcout << L"Suddenly, a low, scratchy voice emerges from behind me,  “Nice and slow, I want your wallet and your keys.”.\n";
		wcout << L"I turn and see that the man has taken the banana from his ear and is now pointing it at my heart.  \nI have made a grave mistake.\n";
		wcout << L"	In the pink haze of the rain, I had missed the outcropping of a trigger in the banana’s peel.  \nIt is but a banana gun disguised as a banana phone.";
		wcout << L"I slowly pull my wallet out of my pocket and hand it to the man,  \n“I gotta kid in the car man.  I can’t give you the keys.”.";
		wcout << L"The man’s eyes dart towards the backseat.  \nGiving a slight nod, he starts to back away.";
		wcout << L"I can feel the wind pushing me even from behind the car’s protection.  \nAs soon as he steps away, his hood snaps back, revealing his face;\n";
		wcout << L"\n	“Are you able to describe the man?”, The officer pulls up a nearby chair and sits down opposite me.\n";

		wcout << L"\nThe face of the perpetrator will flash before you.\n";
		wcout << L"Be prepared to describe the face you see.\n";

	}
	else if (random == 1) {

		wcout << L"\n\n	Reaching towards the back door of the car, my foot snags on the curb, \nand my hands snap up just in time to skirt across the rough of the concrete.\n";
		wcout << L"My knees pressing against the hard grit of the sidewalk, my arm feels unusually warm.\n";
		wcout << L"I glance down to see a gash cut into my forearm, \ncreating a stream of deep red swirling to mix in with the light pink rain pooling around me.\n";
		wcout << L"I try reaching to my phone in my back pocket, but feel a wave of nausea wash over me.\n";
		wcout << L"A black vignette threatens to take over my vision.  \nSuddenly, I feel myself turning over, and see a face standing over me.\n";

		wcout << L"\nI seem to be in some sort of hospital bed.\n";
		wcout << L"“Hello, my name is Jenelle with channel seven news.  Could describe the man that saved your life?”\n";

		wcout << L"\nThe face of your savior will flash before you.\n";
		wcout << L"Be prepared to describe the face you see.\n";

	}
	else if (random == 2) {

		wcout << L"\n\n	Reaching towards the back door of the car, I hear heavy splashing from behind me.\n";
		wcout << L"I glance over my shoulder just as a pipe made of both twizzler and melted marshmallows smashes into my head.\n";
		wcout << L"I crumple to the ground as the man rips the keys from my pocket and dives into the driver’s side.\n";
		wcout << L"I only have enough consciousness to utter but one word, “Tim”.\n";

		wcout << L"\nI wake up in a hospital bed.\n";
		wcout << L"An officer pulls a chair from nearby, “Are you able to describe the man that hit you?”\n";

		wcout << L"\nThe face of the perpetrator will flash before you.\n";
		wcout << L"Be prepared to describe the face you see.\n";

	}
	else if (random == 3) {

		wcout << L"\n\n	Reaching towards the back door of the car, I see man walking up the sidewalk eating a bowl of spaghetti.\n";
		wcout << L"Odd to eat spaghetti in the rain.  I guess some people are just a bit odd.\n";
		wcout << L"However as I am reaching in to grab Tim,  the man starts yelling, seemingly at the storefront across from me.\n";
		wcout << L"He lifts a brown ball from the bowl and posies it as if to throw.\n";
		wcout << L"My god... that is no regular meatball.  It is but a MEATBALL GRENADE!!\n";
		wcout << L"I dive down as the explosive wave hits and throws me against the car.\n";

		wcout << L"\nI wake up in a hospital bed.\n";
		wcout << L"An officer pulls a chair from nearby, “Are you able to describe the man that hit you?”\n";

		wcout << L"\nThe face of the perpetrator will flash before you.\n";
		wcout << L"Be prepared to describe the face you see.\n";
	}
	else if (random == 4) {

		wcout << L"\n\n	Reaching towards the back door of the car, I suddenly hear loud screaming behind me. \n";
		wcout << L"Glancing over my shoulder, I see a man brandishing a large sandwich toothpick charging towards me.\n";
		wcout << L"Diving into the backseat, I click the lock on the doors.  \nThe man then pivots and thrusts into the rubber of my car’s tires.\n";
		wcout << L"The car shifts as the tire quickly releases the stored air and the man runs away down the street.\n";

		wcout << L"	“Are you able to describe the man?”, The officer pulls up a nearby chair and sits down opposite me.\n";

		wcout << L"\nThe face of the perpetrator will flash before you.\n";
		wcout << L"Be prepared to describe the face you see.\n";


	}


}


