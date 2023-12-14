//#include "Color.h"
//#include "Screen.h"
//#include "Game.h"
//#include "Menu.h"
//
//int main() {
//	Screen::getInstance()->consoleInit();
//	Color::getInstance()->consoleColor(Color::BLACK, Color::WHITE);
//	Game game = Game();
//	game.runTetris();
//	/*Menu menu = Menu();
//	menu.MainMenu();*/
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v = { 2, 1, 4, 7, 8, 5 };
	int r = 0, l = v.size() - 1;
	while (r <= l) {
		if (v[r] % 2 == 0) {
			if (v[l] % 2 != 0) {
				swap(v[r], v[l]);
			}
			l--;
		}
		else {
			r++;
		}
	}
	int mark = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			mark = i;
			break;
		}
	}
	sort(v.begin(), v.begin() + mark);
	sort(v.begin() + mark, v.end());

	for (auto i : v) {
		cout << i << " ";
	}

	return 0;
}