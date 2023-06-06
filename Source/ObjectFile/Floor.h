#ifndef FLOOR_H
#define FLOOR_H

#include "ObjectBase.h"

class Floor : public ObjectBase
{
public:
	~Floor(){}

public:
	void Update()override;
	void Draw()override;

};

#endif // !FLOOR_H
