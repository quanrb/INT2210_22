//cai dat floodfill
#include "bits/stdc++.h"
using namespace std;

int ROWS;
int COLS;

bool isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

void DFS(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
    if(!isValid(x, y) || image[x][y] != oldColor) {
        return;
    }
    image[x][y] = newColor;
    DFS(image, x + 1, y, newColor, oldColor);
    DFS(image, x - 1, y, newColor, oldColor);
    DFS(image, x, y + 1, newColor, oldColor);
    DFS(image, x, y - 1, newColor, oldColor);
}

void floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
    int originalColor = image[x][y];
    if(originalColor != newColor) {
        DFS(image, x, y, newColor, originalColor);
    }
}

void printImage(vector<vector<int>> &image) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

}
