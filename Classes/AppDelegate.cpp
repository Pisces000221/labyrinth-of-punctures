#include "AppDelegate.h"
#include "Config.hpp"
#include "scenes/Splash.h"
using namespace cocos2d;

#if USE_AUDIO
    #include "SimpleAudioEngine.h"
    using namespace CocosDenshion;
#endif

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLView::createWithRect(lop::title, Rect(0, 0, 440, 660));
        director->setOpenGLView(glview);
    }
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    lop::init_vars();
    auto scene = Splash::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
#if USE_AUDIO
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
#endif
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
#if USE_AUDIO
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
#endif
}
