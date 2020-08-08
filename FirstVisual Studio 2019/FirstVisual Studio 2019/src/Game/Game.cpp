#include <iostream>
#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../DestoryObject/DestoryObject.h"
#include "../CloneObject/CloneObject.h"
#include "../AdditionalGameObject/AdditionalGameObject.h"
#include "../EndProcessing/EndProcessing.h"

using namespace std;

bool Game::m_isEnd{ false };

void Game::Run()
{
	//コマンド入力値
	string command = "";

	auto gameObject = GameObjectManager::GenerateGameObject("ObjectA");
	gameObject.lock()->CreateComponent<TestOutPut>();
	gameObject.lock()->CreateComponent<DestoryObject>("ObjectB");
	gameObject.lock()->CreateComponent<CloneObject>(3);
	gameObject.lock()->CreateComponent<AdditionalGameObject>("add", ',');
	gameObject.lock()->CreateComponent<EndProcessing>("end");
	cout << "プログラム開始" << endl;

	//コマンド判別
	while (!m_isEnd)
	{

		cout << "フレーム更新" << endl;

		ComponentManager::Update();

		cout << endl;

		ComponentManager::Draw();

		cout << endl;
		
		ComponentManager::UpdateComponentList();
		GameObjectManager::UpdateGamObjectList();
		
		//updateとdrawの表示

		cin >> command;
		
		ComponentManager::sendInputStr(command);

		ComponentManager::DeleteComponent();
		GameObjectManager::DeleteGameObject();
		
		std::cout << endl;

	}
	//終了時に入力
	std::cout << "プログラム終了" << endl;
}

void Game::End()
{
	m_isEnd = true;
}
