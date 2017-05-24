#include "3DRenderer.h"
#include <algorithm>

Vec3 perspectiveTransform(Vec3 *input)
{
	//this assumes a camera FOV of 90 degrees
	Vec3 output;

	if (input->z == 0.0f)
	{
		output.x = input->x;
		output.y = input->y;
		output.z = input->z;

		return output;
	}

	//fake camera fuckery
	output.x = input->x / input->z;
	output.y = input->y / input->z;
	output.z = input->z;

	return output;
}

Vec3 screenspaceTransform(Vec3 *input)
{
	float safeLength = (float)std::min(SCREEN_WIDTH, SCREEN_HEIGHT) - 1.0f;
	
	Vec3 output;

	/*output.x = (input->x + 1.0f) * ((float)SCREEN_WIDTH / 2.0f);
	output.y = (input->y + 0.75f) * ((float)SCREEN_HEIGHT / 1.5f);*/

	output.x = ((float)SCREEN_WIDTH / 2.0f) + (input->x * (safeLength / 2.0f));
	output.y = ((float)SCREEN_HEIGHT / 2.0f) + (input->y * (safeLength / 2.0f));

	output.z = input->z;

	return output;
}