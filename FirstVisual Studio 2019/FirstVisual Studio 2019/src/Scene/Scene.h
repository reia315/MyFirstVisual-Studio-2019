#pragma once

//シーン基底クラス
class Scene
{
public:
	//デストラクタ
	virtual ~Scene() = 0;

	//開始処理
	virtual void State() = 0;

	//終了処理
	virtual void End() = 0;

};