#pragma once
class ScoreIObserver
{
public:

	virtual ~ScoreIObserver() {};
	virtual void update(const int newScore) = 0;
};

