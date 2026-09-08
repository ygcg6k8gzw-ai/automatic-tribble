#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>   // для system()
#include <windows.h> // для Sleep() на Windows

using namespace std;

class GameOfLife {
public:
	GameOfLife(int rows, int cols)
	: rows_(rows), cols_(cols),
	current_(rows, vector<bool>(cols, false)),
	next_(rows, vector<bool>(cols, false)) {}
	
	// Установка живой клетки по координатам (0-based)
	void setAlive(int r, int c) {
		if (r >= 0 && r < rows_ && c >= 0 && c < cols_) {
			current_[r][c] = true;
		}
	}
	
	int countLiveCells() const {
		int count = 0;
		for (int r = 0; r < rows_; ++r) {
			for (int c = 0; c < cols_; ++c) {
				if (current_[r][c]) ++count;
			}
		}
		return count;
	}
	
	bool step() {
		// Вычисляем следующее поколение в next_
		bool changed = false;
		
		for (int r = 0; r < rows_; ++r) {
			for (int c = 0; c < cols_; ++c) {
				int neighbors = countNeighbors(r, c);
				bool isAlive = current_[r][c];
				bool willBeAlive = false;
				
				if (isAlive) {
					// Живая клетка выживает, если у неё 2 или 3 соседа
					if (neighbors == 2 || neighbors == 3) {
						willBeAlive = true;
					} else {
						willBeAlive = false;
					}
				} else {
					// Мёртвая клетка оживает, если ровно 3 соседа
					if (neighbors == 3) {
						willBeAlive = true;
					} else {
						willBeAlive = false;
					}
				}
				
				next_[r][c] = willBeAlive;
				
				if (willBeAlive != isAlive) {
					changed = true;
				}
			}
		}
		
		// Переносим next_ в current_
		current_ = next_;
		return changed; // true, если состояние изменилось
	}
	
	void print(int generation, int liveCount) const {
		cout << "Поколение: " << generation << "\n";
		cout << "Живых клеток: " << liveCount << "\n\n";
		
		for (int r = 0; r < rows_; ++r) {
			for (int c = 0; c < cols_; ++c) {
				cout << (current_[r][c] ? "* " : "- ");
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
private:
	int rows_, cols_;
	vector<vector<bool>> current_;
	vector<vector<bool>> next_;
	
	int countNeighbors(int r, int c) const {
		int count = 0;
		// 8 направлений
		static const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		static const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		
		for (int i = 0; i < 8; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nr < rows_ && nc >= 0 && nc < cols_) {
				if (current_[nr][nc]) ++count;
			}
		}
		return count;
	}
};

int main(int argc, char* argv[]) {
	string filename;
	
	if (argc > 1) {
		filename = argv[1];
	} else {
		cout << "Введите имя файла с начальной конфигурацией: ";
		cin >> filename;
	}
	
	ifstream inFile(filename);
	if (!inFile.is_open()) {
		cerr << "Ошибка: не удалось открыть файл \"" << filename << "\"\n";
		return 1;
	}
	
	int rows, cols;
	if (!(inFile >> rows >> cols)) {
		cerr << "Ошибка: неверный формат файла (ожидаются два числа: строки и столбцы)\n";
		return 1;
	}
	
	GameOfLife game(rows, cols);
	
	int r, c;
	while (inFile >> r >> c) {
		// Если в вашем файле координаты начинаются с 1 (первая строка = 1), 
		// раскомментируйте следующую строку и закомментируйте строку ниже:
		// game.setAlive(r - 1, c - 1); 
		
		// По умолчанию считаем, что координаты в файле 0-based (как в примере задачи)
		game.setAlive(r, c);
	}
	inFile.close();
	
	int generation = 0;
	int liveCount = game.countLiveCells();
	
	while (true) {
		system("cls"); // Очистка консоли в Windows
		game.print(generation, liveCount);
		
		if (liveCount == 0) {
			cout << "Игра завершена: живых клеток не осталось.\n";
			break;
		}
		
		bool changed = game.step();
		++generation;
		liveCount = game.countLiveCells();
		
		if (!changed) {
			system("cls");
			game.print(generation, liveCount);
			cout << "Игра завершена: конфигурация стала стабильной (нет изменений).\n";
			break;
		}
		
		Sleep(1000); // Задержка 1000 мс (1 секунда) для Windows
	}
	
	return 0;
}


