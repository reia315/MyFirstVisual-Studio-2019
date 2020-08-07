#pragma once
#include "../Scene/Scene.h"

//メインシーン
class MainScnen :public Scene
{
public:

	//メインシーン開始処理
	virtual void State() override;

	//メインシーン終了処理
	virtual void End() override;
};