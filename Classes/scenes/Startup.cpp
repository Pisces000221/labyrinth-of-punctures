#include "scenes/Startup.h"
#include "Config.hpp"
#include "widgets/MenuItemLabelTint.h"
using namespace cocos2d;

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
    title_lbl_3->getLetter(5)->runAction(DELAY_ACTIONS(1,
        EaseElasticOut::create(RotateBy::create(0.7, -90))));

    // The menu
    auto levelGameMenu = MenuItemLabelTint::create(
        lop::label("Levels", 56, 2, Color3B::BLUE), [](Ref *sender) { CCLOG("start game: level"); });
    levelGameMenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
    levelGameMenu->setNormalizedPosition(Vec2(1, 0.382));
    levelGameMenu->setOpacity(0);
    levelGameMenu->runAction(DELAY_ACTIONS(1.5, FadeIn::create(0.5)));
    auto mpGameMenu = MenuItemLabelTint::create(
        lop::label("Multiplayer", 56, 2, Color3B::RED), [](Ref *sender) { CCLOG("start game: multiplayer"); });
    mpGameMenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
    mpGameMenu->setNormalizedPosition(Vec2(1, 0.302));
    mpGameMenu->setOpacity(0);
    mpGameMenu->runAction(DELAY_ACTIONS(1.7, FadeIn::create(0.5)));
    auto prefMenu = MenuItemLabelTint::create(
        lop::label("Preferences", 56, 2, Color3B::YELLOW), [](Ref *sender) { CCLOG("show preferences"); });
    prefMenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
    prefMenu->setNormalizedPosition(Vec2(1, 0.222));
    prefMenu->setOpacity(0);
    prefMenu->runAction(DELAY_ACTIONS(1.9, FadeIn::create(0.5)));
    auto aboutMenu = MenuItemLabelTint::create(
        lop::label("About", 56, 2, Color3B::MAGENTA), [](Ref *sender) { CCLOG("show about page"); });
    aboutMenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
    aboutMenu->setNormalizedPosition(Vec2(1, 0.142));
    aboutMenu->setOpacity(0);
    aboutMenu->runAction(DELAY_ACTIONS(2.1, FadeIn::create(0.5)));
    auto menu = Menu::create(levelGameMenu, mpGameMenu, prefMenu, aboutMenu, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}
