#include "scenes/Startup.h"
#include "Config.hpp"
using namespace cocos2d;

#define DELAY_ACTION(_t, ...) Sequence::create(DelayTime::create(_t), __VA_ARGS__, nullptr)

bool Startup::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE)) return false;

    // The title. Well, a little clumsy...
    auto title_lbl_1 = lop::label("LABYRINTH", 60, 2);
    title_lbl_1->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    title_lbl_1->setNormalizedPosition(Vec2::ANCHOR_TOP_LEFT);
    this->addChild(title_lbl_1);
    auto title_lbl_2 = lop::label("of", 36, 1);
    title_lbl_2->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    title_lbl_2->setNormalizedPosition(Vec2(0, 0.89));
    this->addChild(title_lbl_2);
    auto title_lbl_3 = lop::label("PUNCTURES", 72, 2);
    title_lbl_3->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    title_lbl_3->setNormalizedPosition(Vec2(0, 0.84));
    this->addChild(title_lbl_3);
    title_lbl_3->getLetter(4)->setColor(Color3B::BLACK);
    title_lbl_3->getLetter(4)->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
    title_lbl_3->getLetter(5)->setColor(Color3B::BLACK);
    title_lbl_3->getLetter(5)->runAction(DELAY_ACTION(1,
        EaseElasticOut::create(RotateBy::create(0.7, -90))));

    return true;
}
