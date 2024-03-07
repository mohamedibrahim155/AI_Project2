#include "IdleState.h"

IdleState::IdleState(Enemy* enemy)
{
	this->enemy = enemy;
}

void IdleState::StartState()
{
	SetTime();
}

void IdleState::ExitState()
{
}

void IdleState::UpdateState(float deltatime)
{
	if (timeStep>= waitTime)
	{
		SetTime();

		ChangeState(MOVE_TO);
	}
	else
	{
		timeStep += deltatime;
	}
}

void IdleState::SetTime()
{
	timeStep = 0;
	waitTime = 2;
}
