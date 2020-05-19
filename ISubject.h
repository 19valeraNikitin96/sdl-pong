#pragma once
#include"ScoreIObserver.h"
class ISubject
{
public:
	virtual ~ISubject() {};

	virtual void attach(ScoreIObserver* observer) = 0;

	virtual void detach() = 0;

	virtual void notify() = 0;
};

