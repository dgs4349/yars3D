#pragma once
#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>
#include "RE\system\SystemSingleton.h"

using namespace ReEng;

class Bullet
{
private:
	matrix4 bulletM4; // Matrix for bullet
	vector3 bulletPos; // Position Vector
	int bulletDir; // Direction Int
	vector3 movement; //Movement Vector
	int bulletType; // Which bullet is this
	bool active;  // Is the bullet dangerous
	bool fired; // Is the bullet in motion
	bool left; // Special bullet 3 bool for direction
	bool right; // Special bullet 3 bool for direction
	bool lDist; // Special bool for bullet 3 long distance
	bool bReturn; // Return bullet 3
	float spin; // Rotation Angle for bullet 3

	// Boudaries
	float verticalBoundaryTop;
	float verticalBoundaryBottom;
	float horizontalBoundaryLeft;
	float horizontalBoundaryRight;

	float bulletLength;

public:
	Bullet(vector3 userPos, int userDir, int type);
	~Bullet();

	// Methods
	matrix4 GetBulletMatrix(); // Get method for the matrix
	vector3 GetBulletPos(); // Get bullet position
	int GetBulletType(); // Get bullet type
	void Disrupted(); // Alter bullet behavior depending on bullet type
	void BulletDamage(); // Do collision damage based on bullet type
	void Fire(); // Bullet activates and moves depending on bullet type
	void FireEnemy(vector3 playerPos); // Enemy Bullet activates and moves depending on bullet type
	void WrapBullet(); // Bullet stays with player during screen wrapping
	void ChangePosition(vector3 change, vector3 playerPos); // Update method for position
	bool GetActiveBullet(); // Get method for active state
	void SetActiveBullet(bool isActive); // Set method for active state
	bool GetFired(); // Get method for fired state
	bool GetReturn(); // Get method for bReturn state
	void SetReturn(bool isReturn); // set method for bReturn state
	void SetFired(bool isFired); // Set method for fired state
	float GetBulletLength();
	void ResetPosition();
};

