#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Board {
public:
    Board(int size) : _size(size) {
        _cells = new int*[_size];
        for (int i = 0; i < _size; ++i) {
            _cells[i] = new int[_size];
            for (int j = 0; j < _size; ++j) {
                _cells[i][j] = 0;
            }
        }
    }
    ~Board() {
        for (int i = 0; i < _size; ++i) {
            delete[] _cells[i];
        }
        delete[] _cells;
    }
    int getXat(int row, int col) const {
        return col * _cellSize;
    }
    int getYat(int row, int col) const {
        return row * _cellSize;
    }
    int getSize() const {
        return _size;
    }
    void setCheck(int x, int y, int check) {
        _cells[y / _cellSize][x / _cellSize] = check;
    }
    int getCheck(int x, int y) const {
        return _cells[y / _cellSize][x / _cellSize];
    }
private:
    int _size;
    int _cellSize = 32;  // assuming the size of each cell is 32 pixels
    int** _cells;
};

