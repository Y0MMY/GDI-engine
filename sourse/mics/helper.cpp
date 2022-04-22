#include "../../headers/mics/helper.hpp"
RECT Helper::getAbsoluteRect(RRECT relativeRect)
{
	RECT r;
	r.left = relativeRect.x;
	r.top = relativeRect.y;
	r.right = relativeRect.x + relativeRect.width;
	r.bottom = relativeRect.y + relativeRect.height;
	return r;
}