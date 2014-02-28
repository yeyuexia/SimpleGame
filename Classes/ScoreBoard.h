//
//  ScoreBoard.h
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#ifndef __Test__ScoreBoard__
#define __Test__ScoreBoard__

#include <iostream>

class ScoreBoard
{
private:
    int _iHeight;
    int _iMaxHeight;
    int _iScore;
    int _iMaxScore;
    static ScoreBoard* _instance;
    ScoreBoard();
    class Grabo
    {
    public:
        ~Grabo()
        {
            delete ScoreBoard::_instance;
        }
    };
    static Grabo _grabo;
public:
    ~ScoreBoard();
    
    static void init();
    
    static void clearData();
    
    static void updateScore(int score) { _instance->_iScore += score; if (_instance->_iScore > _instance->_iMaxScore) _instance->_iMaxScore = _instance->_iScore; }
    
    static int getScore() { return _instance->_iScore; }
    
    static void updateHeight(int distance) { _instance->_iHeight += distance; if (_instance->_iHeight > _instance->_iMaxHeight) _instance->_iMaxHeight = _instance->_iHeight; }
    
    static int getHeight() { return _instance->_iHeight; }
};
#endif /* defined(__Test__ScoreBoard__) */
