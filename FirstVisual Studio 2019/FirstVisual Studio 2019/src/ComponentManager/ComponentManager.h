#pragma once
#include <list>//前方配列
#include <memory>//スマートポインタ

class Component;

class ComponentManager
{
public:

	//更新
	static void Update();

	//描画
	static void Draw();

	static void DeleteComponent();

	//コンポーネントクラスの生成
	template<class T,class... Args >
    static std::weak_ptr<Component> GenerateComponent(const Args&... args);


private:

	static std::list<std::shared_ptr<Component>>m_component;
};

template<class T,class ...Args>
inline std::weak_ptr<Component> ComponentManager::GenerateComponent(const Args& ...args)
{
	auto component = std::make_shared<T>(args...);
	m_component.push_back(component);
	return component;
}
