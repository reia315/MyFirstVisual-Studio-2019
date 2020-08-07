#pragma once
#include "../Scene/Scene.h"

//タイトルシーン
class TitleScene:public Scene
{
public:

	//タイトルシーン開始処理
	virtual void State() override;

    //タイトルシーン終了シーン
	virtual void End() override;

};