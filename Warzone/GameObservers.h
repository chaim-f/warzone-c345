#pragma once
//#include "wx/wx.h"
//#include <wx/richtext/richtextctrl.h>
#include <list>
//#include "GameEngine.h"
using namespace std;



class GameEngine;
class GameStart;
class StartUpPhase;
class MainGameLoop;

class GameObservers
{


public:
	~GameObservers();
	virtual void Update(const char* msg) = 0;
protected:
	GameObservers();


};

class Subject
{

public:
	virtual void Attach(GameObservers* o);
	virtual void Detach(GameObservers* o);
	virtual void Notify();
	virtual void Notify(const char* message);
	Subject();
	~Subject();
private:
	list<GameObservers*>* _observers;
};

class GameInstance : public Subject
{
private:

public:
	GameInstance();
	void StartGame();
	void AddPlayers();



};



/*******************************************/
/*Observers Section*************************/


class PlayerObserver : public GameObservers
{

private:
	GameEngine* gameModel;
	MainGameLoop* gameloop;
	StartUpPhase* startup;

	//wxRichTextCtrl* m_txt1;
	GameStart* gameStats;



public:
	PlayerObserver();
	PlayerObserver(MainGameLoop* gameloop);
	//PlayerObserver(MainGameLoop* gameloop, wxRichTextCtrl* m_txt1);

	void Update(const char* msg);
	//void Display(wxRichTextCtrl* m_txt1, const char* msg);
	~PlayerObserver();
};


class PhaseObserver : public GameObservers
{

private:
	GameEngine* gameModel; //Subject
	MainGameLoop* gameloop;
	StartUpPhase* startup;

	/*wxRichTextCtrl* m_txt1;
	wxRichTextCtrl* m_txt2;*/
	GameStart* gameStats;

public:
	PhaseObserver();
	PhaseObserver(StartUpPhase* startup);
	//PhaseObserver(GameEngine* model, wxRichTextCtrl* m_txt1);
	//PhaseObserver(StartUpPhase* startup, wxRichTextCtrl* m_txt2);
	void Update(const char* msg);
	void Display(const char* msg);
	~PhaseObserver();

};




/*******************************************/
/*Controller Section*************************/

class GameController
{
private:

	GameEngine* myModel;
	PlayerObserver* playerEventsView;
	PhaseObserver* gameStatsView;
	GameStart* start;

public:
	GameController();
	GameController(GameEngine* model, GameStart* start, PlayerObserver* playerEventsView, PhaseObserver* gameStatsView);
	~GameController();
	void setGameControls();
};


