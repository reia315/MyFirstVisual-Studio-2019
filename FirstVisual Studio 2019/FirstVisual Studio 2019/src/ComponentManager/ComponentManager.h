#pragma once
#include <list>　　//前方配列
#include <memory>　　　　　//スマートポインタ

class Component;

class ComponentManager
{
public:

	//更新
	static void update();
	//描画
	static void draw();
	//コンポーネントクラスの生成
	static std::weak_ptr<Component> GeneratComponent();


private:

	static std::list<std::shared_ptr<Component>>m_component;
};