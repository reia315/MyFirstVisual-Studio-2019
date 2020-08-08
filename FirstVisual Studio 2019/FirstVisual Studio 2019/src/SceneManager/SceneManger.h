#pragma once
#include <memory>
#include "../Scene/Scene.h"

class SceneManger
{
public:

	template<class T,class... Args>
	static void CreationAndSet(const Args&... args);
private:
	static std::shared_ptr<Scene>m_rightNowScene;
};

//作成して設定みたいな名前に
template<class T, class ...Args>
inline void SceneManger::CreationAndSet(const Args& ...args)
{
	if (m_rightNowScene != nullptr)
	{
		//シーン終了処理
		m_rightNowScene->End();
	}

	//新しいシーンのセット
	//reset:リソースの所有権を放棄し、新たなリソースの所有権を設定する
	m_rightNowScene.reset(new T(args...));

	//シーン開始処理
	m_rightNowScene->State();
}
