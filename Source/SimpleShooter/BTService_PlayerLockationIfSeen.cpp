// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLockationIfSeen.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void UBTService_PlayerLockationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
                                                float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if(PlayerPawn == nullptr) return;
	if(OwnerComp.GetAIOwner() == nullptr) return;

	if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),
				PlayerPawn->GetActorLocation());

	}
	else
	{
			OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}


UBTService_PlayerLockationIfSeen::UBTService_PlayerLockationIfSeen()
{
		NodeName = TEXT("Player Lockation if Seen");
}
