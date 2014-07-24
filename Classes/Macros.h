#ifndef __lop__Macros__
#define __lop__Macros__

// Code related
#define SCENE_FUNC(__type__) \
    static cocos2d::Scene* createScene() \
    { \
        cocos2d::Scene *scene = cocos2d::Scene::create(); \
        __type__ *layer = __type__::create(); \
        scene->addChild(layer); \
        return scene; \
    }

#define IS_ON_PC (CC_TARGET_PLATFORM == CC_PLATFORM_WINDOWS) \
    || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

// Display related
#define ACTIONS(...) cocos2d::Sequence::create(__VA_ARGS__, nullptr)
#define DELAY_ACTIONS(_t, ...) cocos2d::Sequence::create(cocos2d::DelayTime::create(_t), __VA_ARGS__, nullptr)

// Scene-navigation related
// Requires cocos2d.h and using namespace cocos2d
#define GO_TO_SCENE(__layer_type__) do { \
    Scene *nextScene = __layer_type__::createScene(); \
    Director::getInstance()->pushScene(TransitionFade::create(0.8, nextScene, Color3B::WHITE)); \
    LayerColor *cover = LayerColor::create(Color4B::WHITE); \
    cover->setOpacity(0); \
    this->addChild(cover, INT_MAX); \
    cover->runAction(Sequence::create( \
        DelayTime::create(0.8), \
        CallFunc::create([cover]() { cover->setOpacity(255); }), \
        FadeOut::create(0.4), \
        RemoveSelf::create(), nullptr)); } while (0)
// Runs an animation and go back
#define CREATE_GO_BACK_MENUITEM(_layername, _varname) \
    MenuItemImage *_varname = MenuItemImage::create( \
        "images/back.png", "images/back.png", \
        CC_CALLBACK_1(_layername::goBack, this)); \
    _varname->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT); \
    _varname->setNormalizedPosition(Vec2::ANCHOR_TOP_LEFT); \
    _varname->setScale((onclr::ratio - 1) * 0.4 + 1);
#define GO_BACK_ANIMATED do { \
    LayerColor *cover = LayerColor::create(Color4B::WHITE); \
    this->getScene()->addChild(cover, INT_MAX); \
    cover->setOpacity(0); \
    cover->runAction(Sequence::create( \
        FadeIn::create(0.4), \
        CallFunc::create([]() { Director::getInstance()->popScene(); }), nullptr)); } while (0)

#endif
