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
	SceneKind Run();
	SceneKind CurrentScene();

};

#endif // !
