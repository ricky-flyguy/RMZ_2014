LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
            ../../Classes/AppDelegate.cpp\
                   	../../Classes/HelloWorldScene.cpp\
			../../Classes/Civilian.cpp\
			../../Classes/RMZHelper.cpp\
			../../Classes/Options.cpp\
			../../Classes/CivFactory.cpp\
			../../Classes/RMZScene.cpp\
			../../Classes/ArrowBtn.cpp\
			../../Classes/SceneManager.cpp\
			../../Classes/MainMenu.cpp\
			../../Classes/Background.cpp\
			../../Classes/Audio.cpp\
			../../Classes/Balloon.cpp\
			../../Classes/Credits.cpp\
			../../Classes/GameOver.cpp\
			../../Classes/HighScore.cpp\
			../../Classes/HowToPlay.cpp\
			../../Classes/LoadingScreen.cpp\
			../../Classes/Player.cpp\
			../../Classes/PullIndicator.cpp\
			../../Classes/Social.cpp\
			../../Classes/Splash.cpp\



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
