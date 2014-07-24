#ifndef __lop__Macros__
#define __lop__Macros__

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

#endif
