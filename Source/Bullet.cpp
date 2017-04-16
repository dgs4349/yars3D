#include "Bullet.h"


// Constructor with 2 arguments (the user of the bullets position and the type of bullet being fired)
Bullet::Bullet(vector3 userPos, int type)
{
	bulletM4 = IDENTITY_M4; // Matrix for bullet movement
	bulletPos = userPos; // Where will this bullet start
	bulletType = type; // What kind of bullet is this

	switch (bulletType) {
	case 0:
		// Assign bullet details
		break;
	case 1:
		// Assign bullet details
		break;
	case 2:
		// Assign bullet details
		break;
	case 3:
		// Assign bullet details
		break;
	default:
		break;
	}
}


// Get method for the matrix
matrix4 Bullet::GetBulletMatrix()
{
	return bulletM4;
}

// Alter bullet behavior depending on bullet type
void Bullet::Disrupted()
{
	switch (bulletType) {
	case 0:
		// Effects on the bullet
		break;
	case 1:
		// Effects on the bullet
		break;
	case 2:
		// Effects on the bullet
		break;
	case 3:
		// Effects on the bullet
		break;
	default:
		break;
	}
}

// Do collision damage based on bullet type
void Bullet::BulletDamage()
{
	switch (bulletType) {
	case 0:
		// Hit resolution of bullet type
		break;
	case 1:
		// Hit resolution of bullet type
		break;
	case 2:
		// Hit resolution of bullet type
		break;
	case 3:
		// Hit resolution of bullet type
		break;
	default:
		break;
	}
}

// Bullet activates and moves depending on bullet type
void Bullet::Fire()
{
	active = true;

	switch (bulletType) {
	case 0:
		// Movement of bullet type 
		break;
	case 1:
		// Movement of bullet type 
		break;
	case 2:
		// Movement of bullet type 
		break;
	case 3:
		// Movement of bullet type 
		break;
	default:
		break;
	}
}


//Destructor
Bullet::~Bullet()
{
}