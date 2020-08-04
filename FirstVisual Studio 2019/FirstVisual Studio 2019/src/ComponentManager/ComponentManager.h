#pragma once
#include <list>//�O���z��
#include <memory>//�X�}�[�g�|�C���^
#include <string>

class Component;

class ComponentManager
{
public:

	//�X�V
	static void Update();

	//�`��
	static void Draw();

	static void sendInputStr(const std::string& inputStr);

	static void UpdateComponentList();

	static void DeleteComponent();

	//�R���|�[�l���g�N���X�̐���
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
