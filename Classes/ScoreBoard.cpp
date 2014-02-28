//
//  ScoreBoard.cpp
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#include "ScoreBoard.h"

ScoreBoard* ScoreBoard::_instance = NULL;
ScoreBoard::Grabo ScoreBoard::_grabo;

ScoreBoard::ScoreBoard()
: _iHeight(0)
, _iScore(0)
, _iMaxHeight(0)
, _iMaxScore(0)
{
    
}

ScoreBoard::~ScoreBoard()
{
    
}

void ScoreBoard::init()
{
    if (_instance) {
        _instance->clearData();
    }
    else
    {
        _instance = new ScoreBoard();
    }
}

void ScoreBoard::clearData()
{
    _instance->_iHeight = 0;
    _instance->_iScore = 0;
}