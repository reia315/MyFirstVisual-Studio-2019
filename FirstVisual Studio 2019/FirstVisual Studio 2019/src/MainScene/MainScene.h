#pragma once
#include "../Scene/Scene.h"

//���C���V�[��
class MainScnen :public Scene
{
public:

	//���C���V�[���J�n����
	virtual void State() override;

	//���C���V�[���I������
	virtual void End() override;
};