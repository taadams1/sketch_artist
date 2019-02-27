#pragma once
#ifndef Face_H
#define Face_H
#endif // !Face

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Face
{
private:
	vector<wstring> face;
public:
	Face();
	~Face();
	void MenuOptions(vector<vector<wstring>> features);
	void AddEyes(vector<wstring>& face, vector<wstring> eyes);
	void AddNose(vector<wstring>& face, vector<wstring> nose);
	void AddMouth(vector<wstring>& face, vector<wstring> mouth);
	void AddHair(vector<wstring>& face, vector<wstring> eyes);
	void AddShape(vector<wstring>& face, vector<wstring> eyes);
	void DisplayFace(vector<wstring> face);
};

