#include <iostream>
#include <memory>
#include "GameObject/GameObject.h"
#include "ComponentManager/ComponentManager.h"
#include "GameObjectManager/GameObjectManager.h"

using namespace std;

int main()
{
	//コマンド入力値
	string command="";
	bool count = true;
	
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectA").lock()->AddComponent(component);
	}
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectB").lock()->AddComponent(component);
	}

	std::cout << "プログラム開始" << endl;

	//コマンド判別
	while (command!="end")
	{
		std::cout << "フレーム更新" << endl;

		if (command == "a" || count == true)
		{
			ComponentManager::update();

			std::cout << endl;

			ComponentManager::draw();

			std::cout << endl;

			//updateとdrawの表示
			
			count = false;
		}

		cin >> command;
	

	    if (command == "add")
		{
		    string name;
			std::cout << "オブジェクト名入力 ->";
			cin >> name;

			{
				auto component = ComponentManager::GenerateComponent();
				GameObjectManager::GenerateGameObject(name).lock()->AddComponent(component);
			}		

			ComponentManager::update();

			std::cout << endl;

			ComponentManager::draw();

			std::cout << endl;
		}

		std::cout << endl;
		
	}

	//終了時に入力
	std::cout << "プログラム終了" << endl;
}
