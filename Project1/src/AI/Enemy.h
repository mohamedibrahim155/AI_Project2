#pragma once
#include "../model.h"
#include <unordered_map>
#include "IdleState.h"
#include "MoveState.h"
class Enemy : public Model
{
public:
	Enemy();

    void DrawProperties() override;
    void SceneDraw()override;

    void Start() override;
    void Update(float deltaTime) override;
    void Render() override;
    void OnDestroy() override;

	BaseEnemyState* GetCurrentState();
	BaseEnemyState* GetState(eStates state);

	void IntialState(eStates state);
	void OnStateChange(eStates state);
	void AddState(eStates state, BaseEnemyState* enemyState);
	void RemoveState(eStates state);
private:
	BaseEnemyState* currentState;

	std::unordered_map<eStates, BaseEnemyState*> listOfEnemyStates;

};

