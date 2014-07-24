#include "scenes/Startup.h"
using namespace cocos2d;

bool Startup::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE)) return false;
    return true;
}
