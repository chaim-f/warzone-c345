#include "GameEngine.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void GameEngine::readMapDir()
{
	for (const auto& p : fs::directory_iterator("maps")) {
		const auto fileName = p.path().filename().string();
		const auto extension = p.path().filename().extension();
		if (p.is_regular_file() && extension == ".map") {
			cout << fileName << '\n';
		}
	}
}
