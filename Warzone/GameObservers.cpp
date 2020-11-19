//#include "wx/wx.h"
//#include <wx/richtext/richtextctrl.h>
#include <iostream>
#include <stdlib.h>
#include "GameObservers.h"
#include "GameEngine.h"
using namespace std;


//----------------------------------------------------------------------//
//Observers definition section
//----------------------------------------------------------------------//

GameObservers::GameObservers() {


};
GameObservers::~GameObservers()
{

};


/* Player observer*/

PlayerObserver::PlayerObserver()
{

};

PlayerObserver::PlayerObserver(MainGameLoop* gameloop)
{
	gameloop = gameloop;
	gameloop->Attach(this);
};


PlayerObserver::PlayerObserver(MainGameLoop* gameloop, wxRichTextCtrl* m_txt1)
{
	gameloop = gameloop;
	gameloop->Attach(this);
	this->m_txt1 = m_txt1;
};





PhaseObserver::PhaseObserver(StartUpPhase* startup, wxRichTextCtrl* m_txt2) {
	this->startup = startup;
	startup->Attach(this);
	this->m_txt2 = m_txt2;

};

PhaseObserver::PhaseObserver(StartUpPhase* startup) {
	startup = startup;
	startup->Attach(this);


};



void PlayerObserver::Update(const char* msg)
{
	//Display(msg);
};

void PlayerObserver::Display(wxRichTextCtrl* m_txt1, const char* msg)
{

};


PlayerObserver::~PlayerObserver()

{
	gameModel->Detach(this);
};


/* Phase observer*/
PhaseObserver::PhaseObserver()
{

};


void PhaseObserver::Update(const char* msg)
{
	Display(msg);
};
void PhaseObserver::Display(const char* msg)
{

	wxRichTextAttr attr2 = this->m_txt2->GetBasicStyle();
	//attr.SetBackgroundColour(wxColour(0, 121, 122));
	attr2.SetTextColour(wxColour(0, 0, 255));
	m_txt2->SetBasicStyle(attr2);
	m_txt2->AppendText(msg);
	m_txt2->AppendText("\n");

};
PhaseObserver::~PhaseObserver()
{
	gameModel->Detach(this);
};








//----------------------------------------------------------------------//
//Controller definition section
//----------------------------------------------------------------------//

GameController::GameController()
{
};

GameController::GameController(GameEngine* model, GameStart* start, PlayerObserver* playerEventsView, PhaseObserver* gameStatsView)
{

};

void GameController::setGameControls()
{

};


GameController::~GameController()
{
};





Subject::Subject() {
	_observers = new list<GameObservers*>;
}
Subject::~Subject() {
	delete _observers;
}
void Subject::Attach(GameObservers* o) {
	_observers->push_back(o);
};
void Subject::Detach(GameObservers* o) {
	_observers->remove(o);
};
void Subject::Notify() {
	list<GameObservers*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->Update(""); //Add message here
};


void Subject::Notify(const char* message) {
	list<GameObservers*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->Update(message); //Add message here
};
