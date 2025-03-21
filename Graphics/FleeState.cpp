#include "FleeState.h"
#include "PatrolState.h"
#include "RequestResourcesState.h"
#include "Warrior.h"
#include <iostream>

void FleeState::OnEnter(NPC* p)
{
    // Initialize combat behavior
    Warrior* w = (Warrior*)p;
    w->SetIsMoving(true);
    std::cout << "Entering FleeState\n";
}

void FleeState::Transition(NPC* p)
{
	// Exiting from current state
    OnExit(p);

	Warrior* w = (Warrior*)p;
    w->SetState(new PatrolState());

    // entering new state
    p->GetState()->OnEnter(p);
   
}

void FleeState::OnExit(NPC* p)
{
    // Clean up flee behavior
    p->SetIsMoving(true);
    std::cout << "Exiting FleeState\n";
}
