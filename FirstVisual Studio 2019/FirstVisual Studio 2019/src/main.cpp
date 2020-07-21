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
	
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectA").lock()->AddComponent(component);
	}
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectB").lock()->AddComponent(component);
	}

	cout << "プログラム開始" << endl;

	//コマンド判別
	while (command!="end")
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
