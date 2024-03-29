/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-wilson.bordichon
** File description:
** snake
*/

#include <vector>
#include "LibSnake.hpp"
#include <iostream>
#include <ostream>
#include <functional>
#include <utility>
arcade::LibSnake::LibSnake()
{
    init();
}

void arcade::LibSnake::init()
{

    map = {
        "###############################",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#             <==8            #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "#                             #",
        "###############################"
    };
    mapSize = 1;
    direction = DROITE;
    SnakeLenght = 4;
}

std::array<std::string, 23> arcade::LibSnake::getMap()
{
    return map;
}

std::size_t arcade::LibSnake::getMapCellSize()
{
    return mapSize;
}

int arcade::LibSnake::findPlayer()
{
    size_t y = 0;
    size_t x = 0;
    size_t y_map = 20;
    size_t x_map = 31;

    for (y = 0; y != y_map; y++) {
        for(x = 0; x != x_map; x++)
            if (map[y][x] == '8') {
                playerY = y;
                playerX = x;
            }
    }
}

void arcade::LibSnake::getQueue()
{
    size_t y = 0;
    size_t x = 0;
    size_t y_map = 20;
    size_t x_map = 31;

    for (y = 0; y != y_map; y++) {
        for(x = 0; x != x_map; x++)
            if (map[y][x] == '<') {
                queueY = y;
                queueX = x;
            }
    }
}

bool arcade::LibSnake::isAvailable(char c)
{
    if (c == '#') {
        gameStatus = arcade::LOOSE;
        return false;
    }
    return true;
}

void arcade::LibSnake::getSnakeLenght()
{
    if (MyVector.empty() == false)
        SnakeLenght = MyVector.size();
}

void arcade::LibSnake::updateKeyPressed(arcade::KeyPressed key)
{
    if (key != arcade::OTHER) {
        keyPressed = key;
    }
}


arcade::GameStatus arcade::LibSnake::updateMap(arcade::KeyPressed key)
{
    findPlayer();
    getSnakeLenght();
    getQueue();
     size_t y = queueY;
     size_t x = queueX;
    std ::vector<std :: pair<int, int>> MyVector((SnakeLenght), {1, 2});
    for(int i = 0; i < MyVector.size(); i++) {
        MyVector[i].first = y;
        MyVector[i].second = x;
        x++;
    }
    for(auto it : MyVector)
        std::cout << "Premier"<< it.first << " " << it.second << std::endl;
    // if (key == arcade::RIGHT) {
    //     if (isAvailable(map.at(playerY).at(playerX + 1)) == true) {
    //         playerX++;
    //         map[playerY][playerX] = '8';
    //         MyVector[SnakeLenght].second = playerX;
    //         map[MyVector[0].first][MyVector[0].second] = ' ';
    //         std ::vector<std :: pair<int, int>> VectorTemp = MyVector;
    //         for(int i = 0; i < (MyVector.size() - 1); i++) {
    //             MyVector[i].first = VectorTemp[i + 1].first;
    //             MyVector[i].second = VectorTemp[i + 1].second;
    //         }
    //         map[MyVector[0].first][MyVector[0].second] = '<';
    //         for(int i = 1; i < (MyVector.size() - 1); i++) {
    //             map[MyVector[i].first][MyVector[i].second] = '=';
    //         }
    //     }
    // }
    // if (isAvailable(map.at(playerY).at(playerX + 1)) == true) {
    //     map[playerY][playerX - (SnakeLenght)] = ' ';
    //     SnakeLenght--;
    //     map[playerY][playerX - (SnakeLenght)] = '<';
    //     SnakeLenght--;
    //     for (; SnakeLenght != -1; SnakeLenght--)
    //         map[playerY][playerX - SnakeLenght] = '=';
    //     // map[playerY][playerX] = '=';
    //     map[playerY][playerX + 1] = '8';
    // }
    // playerX++;


    // if (key == arcade::UP) {
    //     if (isAvailable(map.at(playerY - 1).at(playerX)) == true) {
    //         playerY--;
    //         map[playerY][playerX] = '8';
    //         MyVector[SnakeLenght].first = playerY;
    //         map[MyVector[0].first][MyVector[0].second] = ' ';
    //         std ::vector<std :: pair<int, int>> VectorTemp = MyVector;
    //         for(int i = 0; i < (MyVector.size() - 1); i++) {
    //             MyVector[i].first = VectorTemp[i + 1].first;
    //             MyVector[i].second = VectorTemp[i + 1].second;
    //         }
    //         for(auto it : VectorTemp)
    //             std::cout << "Temp "<< it.first << " " << it.second << std::endl;
    //         for(auto it : MyVector)
    //             std::cout << "MyVector "<< it.first << " " << it.second << std::endl;
    //         map[MyVector[0].first][MyVector[0].second] = '<';
    //         for(int i = 1; i < (MyVector.size() - 1); i++) {
    //             map[MyVector[i].first][MyVector[i].second] = '=';
    //         }
    //     }
    // }
    // if (key == arcade::DOWN) {
    //     if (isAvailable(map.at(playerY + 1).at(playerX)) == true) {
    //         playerY++;
    //         map[playerY][playerX] = '8';
    //         MyVector[SnakeLenght].first = playerY;
    //         map[MyVector[0].first][MyVector[0].second] = ' ';
    //         std ::vector<std :: pair<int, int>> VectorTemp = MyVector;
    //         for(int i = 0; i < (MyVector.size() - 1); i++) {
    //             MyVector[i].first = VectorTemp[i + 1].first;
    //             MyVector[i].second = VectorTemp[i + 1].second;
    //         }
    //         map[MyVector[0].first][MyVector[0].second] = '<';
    //         for(int i = 1; i < (MyVector.size() - 1); i++) {
    //             map[MyVector[i].first][MyVector[i].second] = '=';
    //         }
    //     }
    // }
    // if (key == arcade::LEFT) {
    //     if (isAvailable(map.at(playerY).at(playerX - 1)) == true) {
    //         playerX--;
    //         map[playerY][playerX] = '8';
    //         MyVector[SnakeLenght].second = playerX;
    //         map[MyVector[0].first][MyVector[0].second] = ' ';
    //         std ::vector<std :: pair<int, int>> VectorTemp = MyVector;
    //         for(int i = 0; i < (MyVector.size() - 1); i++) {
    //             MyVector[i].first = VectorTemp[i + 1].first;
    //             MyVector[i].second = VectorTemp[i + 1].second;
    //         }
    //         map[MyVector[0].first][MyVector[0].second] = '<';
    //         for(int i = 1; i < (MyVector.size() - 1); i++) {
    //             map[MyVector[i].first][MyVector[i].second] = '=';
    //         }
    //     }
    // }
    return arcade::PLAYING;
}


// fonction sens qui me donne le sens du snake
//  et faire les autres fonction tout droit pour en haut, en bas et à gauche
// fonction pour donné la pos de la tete au debut


//mettre la configuration du vector dans le init pour pas qu'il se re met au debut a chaque fois