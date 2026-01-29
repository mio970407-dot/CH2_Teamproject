#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

void APlayer::Attack(ACharacter* Target)
{
	cout << Name << "은 집중하고 있습니다." << endl;

	ACharacter::Attack(Target);
};

void APlayer::UseItem()
{
};

void APlayer::LevelUp()
{
};

