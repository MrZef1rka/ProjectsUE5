// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LMAGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LEAVEMEALONE_API ALMAGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ALMAGameMode();
	
	virtual void StartPlay() override
	{
		Super::StartPlay();
        
		// Не спавним автоматически персонажа
		// Управляем существующим в уровне
	}
};
