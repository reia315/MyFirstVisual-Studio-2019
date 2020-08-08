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

//�쐬���Đݒ�݂����Ȗ��O��
template<class T, class ...Args>
inline void SceneManger::CreationAndSet(const Args& ...args)
{
	if (m_rightNowScene != nullptr)
	{
		//�V�[���I������
		m_rightNowScene->End();
	}

	//�V�����V�[���̃Z�b�g
	//reset:���\�[�X�̏��L����������A�V���ȃ��\�[�X�̏��L����ݒ肷��
	m_rightNowScene.reset(new T(args...));

	//�V�[���J�n����
	m_rightNowScene->State();
}
