#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class SceneManager
{
public:
	static SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}
public:
	~SceneManager(){}

private:
	SceneManager(){}
	SceneManager(const SceneManager& Ins) = delete;
};

#endif // !SCENEMANAGER_H
