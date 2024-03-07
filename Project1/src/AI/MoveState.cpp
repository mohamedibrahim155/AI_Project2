#include "MoveState.h"
#include "Enemy.h"
#include "../Math.h"

using namespace MathUtils;

MoveState::MoveState(Enemy* _enemy)
{
	enemy = _enemy;
	startPosition = glm::vec3(0);
	endPosition = glm::vec3(0);
	direction = glm::vec3(0);
}

void MoveState::StartState()
{
	SetStartPosition(enemy->transform.position);

	glm::vec3 randomPoint = GetRandomPoint();
	std::cout << "RandomPoint: " << randomPoint.x
		<< " " << randomPoint.y
		<< " " << randomPoint.z << std::endl;


	SetEndPosition(randomPoint);
}

void MoveState::UpdateState(float deltatime)
{
	glm::vec3 displacement =   endPosition - enemy->transform.position;




	if (glm::length(displacement) != 0)
	{
		direction = glm::normalize(displacement);
	}

	float distance = glm::length(displacement);

	if (distance >=range)
	{
		glm::quat rotation = glm::quatLookAt(-direction, glm::vec3(0, 1, 0));

		enemy->transform.SetQuatRotation(rotation);

		enemy->transform.position += direction * moveSpeed * deltatime;
	}
	else
	{
		ChangeState(IDLE);
	}
		
	
}

void MoveState::ExitState()
{

}

void MoveState::SetStartPosition(const glm::vec3& position)
{
	startPosition = position;
}

void MoveState::SetEndPosition(const glm::vec3& position)
{
	endPosition = position;

}

glm::vec3 MoveState::GetRandomPoint()
{
	float x =  Math::GetRandomFloatNumber(-30,30);
	float y = enemy->transform.position.y;
	float z = Math::GetRandomFloatNumber(-17, 17);

	return glm::vec3(x,y,z);
}
