#pragma once
#ifndef Asciimation_H
#define Asciimation_H
#endif // !Animation_H

#include<string>
#include<vector>
#include<iostream>
#include<chrono>
#include<thread>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <type_traits>


class Asciimation
{
public:
	//default constructor and destructor
	Asciimation();
	~Asciimation();
	//set animation speed
	void SetSpeed(float spd);
	//show current speed
	void ShowSpeed();
	//return integer value of speed
	float GetSpeed();
	//set frames for flower animation
	void Flower();
	void RevealFace();
	//animate frames
	void Animate();
	void Animate(int);
private:
	float speed;
	std::vector<std::vector<std::wstring>> frames;
};

