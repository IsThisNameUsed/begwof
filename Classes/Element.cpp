#include "Element.h"
#include "math.h"

using namespace cocos2d;

Element::Element() {}

Element::Element(Node* parent)
{
	isClickable = true;
	draw = DrawNode::create();
	parent->addChild(draw);
	color = ccColor4F::WHITE;
	clickRadius = 4;
	isClickable = true;
}

Element::Element(int _posX, int _posY)
{
	pos = Point(_posX, _posY);
}

Element::~Element()
{
}

void Element::update(float dt)
{

}

bool Element::isClicked(Point point)
{
	// check if square magnitude is less than square radius
	Point direction = pos - point;
	if (direction.x * direction.x + direction.y * direction.y < clickRadius * clickRadius)
		return isClickable;

	return false;
}

void Element::click()
{
	CCLOG(("Clicked on element " + std::to_string(id) + " on position " + std::to_string(pos.x) + " " + std::to_string(pos.y)).c_str());
}

double Element::Distance(Element o)
{
	return sqrt((o.pos.x - pos.x)*(o.pos.x - pos.x) + (o.pos.y - pos.y)*(o.pos.y - pos.y));
}

double Element::DistanceCarre(Element o)
{
	return (o.pos.x - pos.x)*(o.pos.x - pos.x) + (o.pos.y - pos.y)*(o.pos.y - pos.y);
}
