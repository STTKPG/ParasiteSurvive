#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneBase
{
public:
	enum class SceneKind
	{
		MainScene,
		OverScene
	};
public:
	SceneBase(){}
	virtual ~SceneBase(){}

public:
	virtual SceneKind Update() = 0;
	virtual void Draw() = 0;

};

#endif // !
