#include <iostream>
#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../DestoryObject/DestoryObject.h"
#include "../CloneObject/CloneObject.h"
#include "../AdditionalGameObject/AdditionalGameObject.h"

using namespace std;

void Game::Run()
{
	//�R�}���h���͒l
	string command = "";

	auto gameObject = GameObjectManager::GenerateGameObject("ObjectA");
	gameObject.lock()->CreateComponent<TestOutPut>();
	gameObject.lock()->CreateComponent<DestoryObject>("ObjectB");
	gameObject.lock()->CreateComponent<CloneObject>(3);
	gameObject.lock()->CreateComponent<AdditionalGameObject>("add", ",");
	cout << "�v���O�����J�n" << endl;

	//�R�}���h����
	while (command != "end")
	{

		cout << "�t���[���X�V" << endl;

		ComponentManager::Update();

		cout << endl;

		ComponentManager::Draw();

		cout << endl;
		
		ComponentManager::UpdateComponentList();
		GameObjectManager::UpdateGamObjectList();
		
		//update��draw�̕\��

		cin >> command;
		
		ComponentManager::sendInputStr(command);

		ComponentManager::DeleteComponent();
		GameObjectManager::DeleteGameObject();
		
		std::cout << endl;

	}
	//�I�����ɓ���
	std::cout << "�v���O�����I��" << endl;
}
