#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectBase.h"

class Player : public ObjectBase
{
public:
	~Player(){}

protected:
	void Draw()override;
	void Update()override;
};

#endif // !PLAYER_H
