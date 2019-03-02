//Implementation of Face class functions
//Trevor Adams, taadams1@dmacc.edu

#include "Face.h"

//default constructor, sets face to blank template on object creation
Face::Face()
{
	this->face = {
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
		LR"(-------------------------)"};
}
//default destructor
Face::~Face()
{
}


//function to print menu options
void Face::MenuOptions(vector<vector<wstring>> features)
{

	int featSize = features[0].size();

	for (int i = 0; i < featSize; i++) {

		wstring menuOptions = LR"()";

		for (int j = 0; j < 3; j++) {

			if (i == 0) {

				menuOptions += L"  " + to_wstring(j+1) + L"  " + features[j][i];
			}
			else {

				menuOptions += L"     " + features[j][i];
			}
			
		}
		wcout << menuOptions << endl;
	}
	for (int i = 0; i < featSize; i++) {

		wstring menuOptions = LR"()";

		for (int j = 3; j < features.size(); j++) {

			if (i == 0) {

				menuOptions += L"  " + to_wstring(j + 1) + L"  " + features[j][i];
			}
			else {

				menuOptions += L"     " + features[j][i];
			}

		}
		wcout << menuOptions << endl;
	}
	wcout << L"Choice: ";
}


//function to add eyes to face
void Face::AddEyes(vector<wstring>& face, vector<wstring> eyes) {

	face[6].replace(6, 13, eyes[0]);
	face[7].replace(6, 13, eyes[1]);
}

//function to add nose to face
void Face::AddNose(vector<wstring> &face, vector<wstring> nose) {

	face[8].replace(11, 3, nose[0]);
	face[9].replace(11, 3, nose[1]);
}

//function to add mouth to face
void Face::AddMouth(vector<wstring> &face, vector<wstring> mouth) {

	face[10].replace(9, 7, mouth[0]);
	face[11].replace(9, 7, mouth[1]);
}

//function to add hair to face
void Face::AddHair(vector<wstring> &face, vector<wstring> hair) {

	face[2].replace(3, 19, hair[0]);
	face[3].replace(3, 19, hair[1]);
	face[4].replace(3, 19, hair[2]);
	face[5].replace(3, 19, hair[3]);
	face[6].replace(3, 4, (hair[4]).substr(0, 4));
	face[6].replace(18, 4, (hair[4]).substr(4, 7));
	face[7].replace(3, 3, (hair[5]).substr(0, 3));
	face[7].replace(19, 3, (hair[5]).substr(3, 5));
	face[8].replace(3, 3, (hair[6]).substr(0, 3));
	face[8].replace(19, 3, (hair[6]).substr(3, 5));
	face[9].replace(3, 2, (hair[7]).substr(0, 2));
	face[9].replace(20, 2, (hair[7]).substr(2, 3));
	face[10].replace(3, 2, (hair[8]).substr(0, 2));
	face[10].replace(20, 2, (hair[8]).substr(2, 3));
	face[11].replace(3, 3, (hair[9]).substr(0, 3));
	face[11].replace(19, 3, (hair[9]).substr(3, 5));
}

//function to add shape to face
void Face::AddShape(vector<wstring> &face, vector<wstring> shape) {

	face[9].replace(5, 4, (shape[0]).substr(0, 4));
	face[9].replace(16, 4, (shape[0]).substr(4, 7));
	face[10].replace(6, 3, (shape[1]).substr(0, 3));
	face[10].replace(16, 3, (shape[1]).substr(3, 5));
	face[11].replace(6, 4, (shape[2]).substr(0, 4));
	face[11].replace(15, 4, (shape[2]).substr(4, 7));
	face[12].replace(7, 11, shape[3]);
}

//function to display face on screen
void Face::DisplayFace(vector<wstring> face) {
	
	for (int i = 0; i < face.size(); i++) {
		wcout << face[i] << endl;
	}
}

