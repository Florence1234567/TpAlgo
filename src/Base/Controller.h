//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "Character.h"
#include <iostream>


class Controller {
public:
    Controller(Character* character): owner(character) {};
protected:
    Character* owner;
};