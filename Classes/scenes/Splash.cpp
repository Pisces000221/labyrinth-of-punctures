#include "scenes/Splash.h"
#include "scenes/Startup.h"
#include "Macros.h"
#include "Config.hpp"
using namespace cocos2d;

bool Splash::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) return false;

    auto sprite = Sprite::create(lop::res::engine_logo_file);
    sprite->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
    sprite->setPosition(Vec2(lop::vsize.width + 24, lop::vsize.height + 48));
    sprite->setOpacity(108);
    sprite->setScale(lop::vsize.height * 0.9 / sprite->getTextureRect().size.width);
    this->addChild(sprite);

    auto label_1 = lop::label("Powered by", 35, 1);
    label_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    label_1->setNormalizedPosition(Vec2(0.35, 55.0 / 660.0));
    label_1->setColor(Color3B(0, 0, 0));
    this->addChild(label_1);

    auto label_2 = lop::label("Cocos2d-x", 52, 2);
    label_2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    label_2->setNormalizedPosition(Vec2(0.35, 3.0 / 660.0));
    label_2->setColor(Color3B(0, 0, 0));
    this->addChild(label_2);

    // Fade in on startup
    auto cover = LayerColor::create(Color4B::BLACK);
    this->addChild(cover, 1024);
    cover->runAction(FadeOut::create(0.15f));

    this->scheduleOnce(schedule_selector(Splash::goOn), 2);

    return true;
}

void Splash::goOn(float dt)
{
    auto nextScene = Startup::createScene();
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.8, nextScene));
}
