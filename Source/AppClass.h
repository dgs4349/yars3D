/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/09
----------------------------------------------*/
#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Camera.h"
#include "Enemy.h"
#include <SFML\Audio.hpp>

using namespace ReEng; //Using ReEng namespace to use all the classes in the dll

class AppClass : public ReEngAppClass
{
	//PrimitiveClass* m_pPlayer = nullptr;
	PrimitiveClass* m_pEnemy = nullptr;
	PrimitiveClass* m_pBullet = nullptr;
	PrimitiveClass* m_pKillBullet = nullptr;
	PrimitiveClass* m_pTrackingBullet = nullptr;
	PrimitiveClass* m_pPlayerBoundaries = nullptr;
	matrix4 m_m4Cube;
	matrix4 m_mPlayerBoundaries;

	//GAME STATE VARIABLES
	int gameState = 0;
	bool dead = false;
	bool win = false;
	bool change = false;

	//Enum for game states
	enum STATE {BEGIN = 0, GAME = 1, END = 2};

	// array of pointers to primitives for disruptor field
	PrimitiveClass** fieldCubes;
	const int numCubes = 240;
	const float sizeCubes = 0.5f;

	// Player object
	Player* player = nullptr;
	// Camera object
	Camera* camera = nullptr;
	// Enemy object
	Enemy* enemy = nullptr;
	// disruptor field switch timer
	int timer = 0;

	vector3 playerPos;

	int frameCount;

	// ENEMY BULLETS
	Bullet* trackingBullet = nullptr;

	// Audio stuff
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::Music soundBGM;

public:
	PrimitiveClass** GenerateDisruptorField();
	void SwitchColors();
	void EnemyLaunch();
	void Reset();
	typedef ReEngAppClass super;
	/*
	USAGE: Constructor
	ARGUMENTS:
	- HINSTANCE hInstance -> Instance of the window
	- LPWSTR lpCmdLine -> Command line
	- int nCmdShow -> Number or arguments
	- bool a_bConsole = false -> create command window flag
	OUTPUT: ---
	*/
	AppClass(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow, bool a_bUsingConsole = false) : super(hInstance, lpCmdLine, nCmdShow, a_bUsingConsole) {}
	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~AppClass(void) { Release(); }
	/*
	USAGE: Reads the configuration of the application to a file
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void ReadConfig(void) final {}
	/*
	USAGE: Writes the configuration of the application to a file
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void WriteConfig(void) final {}
	/*
	USAGE: Initialize ReEng variables necessary to create the window
	ARGUMENTS: String a_sWindowName -> Name of the window
	OUTPUT: ---
	*/
	virtual void InitWindow(String a_sWindowName) final;
	/*
	USAGE: Initializes user specific variables, this is executed right after InitApplicationVariables,
	the purpose of this member function is to initialize member variables specific for this lesson
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void InitVariables(void) final;
	/*
	USAGE: Updates the scene
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void Update(void) final;
	/*
	USAGE: Displays the scene
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void Display(void) final;
	/*
	USAGE: Manage the response of key presses
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void ProcessKeyboard(void) final;
	/*
	USAGE: Manage the response of key presses and mouse position
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void ProcessMouse(void) final;
	/*
	USAGE: Releases the application
	IF INHERITED AND OVERRIDEN MAKE SURE TO RELEASE BASE POINTERS (OR CALL BASED CLASS RELEASE)
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void Release(void) final;
};

#endif //__APPLICATION_H_
