#include <iostream>
#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../DestoryObject/DestoryObject.h"
#include <memory>

using namespace std;

void Game::Run()
{
	//コマンド入力値
	string command = "";

	auto gameObject = GameObjectManager::GenerateGameObject("ObjectA");
	gameObject.lock()->CreateComponent<TestOutPut>();
	gameObject.lock()->CreateComponent<DestoryObject>("ObjectB");

	
	//{
	//	auto component = ComponentManager::GenerateComponent();
	//	GameObjectManager::GenerateGameObject("ObjectA").lock()->AddComponent(component);
	//}
	//{
	//	auto component = ComponentManager::GenerateComponent();
	//	GameObjectManager::GenerateGameObject("ObjectB").lock()->AddComponent(component);
	//}

	cout << "プログラム開始" << endl;

	//コマンド判別
	while (command != "end")
	{

		cout << "フレーム更新" << endl;

		ComponentManager::update();

		cout << endl;

		ComponentManager::draw();

		cout << endl;

		//updateとdrawの表示

		cin >> command;

		if (command == "add")
		{
			string name;
			cout << "オブジェクト名入力 ->";
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



	//終了時に入力
	std::cout << "プログラム終了" << endl;
}
