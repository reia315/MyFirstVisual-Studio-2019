#include <iostream>
#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../DestoryObject/DestoryObject.h"
#include "../CloneObject/CloneObject.h"

using namespace std;

void Game::Run()
{
	//�R�}���h���͒l
	string command = "";

	auto gameObject = GameObjectManager::GenerateGameObject("ObjectA");
	gameObject.lock()->CreateComponent<TestOutPut>();
	gameObject.lock()->CreateComponent<DestoryObject>("ObjectB");
	gameObject.lock()->CreateComponent<CloneObject>(2);

	
	//{
	//	auto component = ComponentManager::GenerateComponent();
	//	GameObjectManager::GenerateGameObject("ObjectA").lock()->AddComponent(component);
	//}
	//{
	//	auto component = ComponentManager::GenerateComponent();
	//	GameObjectManager::GenerateGameObject("ObjectB").lock()->AddComponent(component);
	//}

	cout << "�v���O�����J�n" << endl;

	//�R�}���h����
	while (command != "end")
	{

		cout << "�t���[���X�V" << endl;

		ComponentManager::Update();

		cout << endl;

		ComponentManager::Draw();

		cout << endl;

		//update��draw�̕\��

		cin >> command;

		if (command == "add")
		{
			string name;
			cout << "�I�u�W�F�N�g������ ->";
			cin >> name;

			auto gameObject = GameObjectManager::GenerateGameObject(name);
			gameObject.lock()->CreateComponent<TestOutPut>();
			//{
			//	auto component = ComponentManager::GenerateComponent();
			//	GameObjectManager::GenerateGameObject(name).lock()->AddComponent(component);
			//}
	
		}

		ComponentManager::DeleteComponent();
		GameObjectManager::DeleteGameObject("ObjectB");
		
		std::cout << endl;

		

	}



	//�I�����ɓ���
	std::cout << "�v���O�����I��" << endl;
}
