#include "ChristmasTree.h"

ChristmasTree::ChristmasTree(SDL_Renderer* renderer, const FilledPolygon& body, const int bodySize, const std::pair<double, double>& scale, const SDL_Point& translate, const FilledPolygon& trunk)
	:renderer(renderer), body(body), bodySize(bodySize), scale(scale), translateVector(translate), trunk(trunk)
{

}

bool ChristmasTree::Render()
{
	FilledPolygon newBody = body;
	for (int i = 0; i < bodySize; i++)
	{
		newBody.Render();
		newBody.scale(scale);
		newBody.translate(translateVector);
	}

	trunk.Render();
	return true;
}

void ChristmasTree::translate(SDL_Point vec)
{
	trunk.translate(vec);
	body.translate(vec);
}
