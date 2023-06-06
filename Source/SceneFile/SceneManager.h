#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class SceneManager
{
public:
	SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}
public:
	~SceneManager(){}

private:
	SceneManager(){}
	SceneManager(const SceneManager &obj)
};

#endif // !SCENEMANAGER_H
