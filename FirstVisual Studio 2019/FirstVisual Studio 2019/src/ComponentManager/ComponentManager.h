#pragma once
#include <list>//前方配列
#include <memory>//スマートポインタ
#include <string>

class Component;

class ComponentManager
{
public:

	//更新
	static void Update();

	//描画
	static void Draw();

	static void sendInputStr(const std::string& inputStr);

	static void UpdateComponentList();

	static void DeleteComponent();

	//コンポーネントクラスの生成
	template<class T,class... Args >
    static std::weak_ptr<Component> GenerateComponent(const Args&... args);


private:

	static std::list<std::shared_ptr<Component>>m_component;

	static std::list<std::shared_ptr<Component>> m_addComponent;
};

template<class T,class ...Args>
inline std::weak_ptr<Component> ComponentManager::GenerateComponent(const Args& ...args)
{
	auto component = std::make_shared<T>(args...);
	m_addComponent.push_back(component);
	return component;
}
