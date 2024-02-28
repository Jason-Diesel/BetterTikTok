#include "DeltaTime.h"
#include "Game.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(0));
	GameState* current = nullptr;
	State currentState = State::NO_CHANGE;
	DeltaTime dt;
	
	//change to menu
	current = new Game();
	currentState = State::NO_CHANGE;
	
	while (currentState != State::EXIT) {

		if (currentState != State::EXIT) {
			current->render();
		}
		currentState = current->update(dt.dt());
		current->handleEvents();
		dt.restartClock();
		if (currentState != State::NO_CHANGE) {
			switch (currentState)
			{
			default:
				break;
			}
		}
	}
	delete current;
	return 0;
}