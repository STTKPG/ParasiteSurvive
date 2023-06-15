#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectBase.h"

class Player : public ObjectBase
{
public:
	~Player(){}

public:
	VECTOR GetRotate()
	{
		return Rotate;
	}
protected:
	void Draw(int modeldata)override;
	void Update()override;

private:
	void PlayerVector();

};

#endif // !PLAYER_H
