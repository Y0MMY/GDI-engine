#include "../../headers/gui/buttons.hpp"
#include "../../headers/gui/mics/rectCorner.hpp"
Buttons::Buttons(/* args */) noexcept
{
    this->position = {};
    this->hovered = false;
	this->pressed = false;
	this->clicked = false;
	this->disabled = false;
	this->isColor = false;
	this->extendLeftAmount = 0;
}
Buttons::Buttons(std::wstring text, Color normal, Color hovered, Color clicked, RectF rect): Buttons()
{
    this->isColor = true;
    this->text = text;
    this->colorNormal = new SolidBrush(normal);
    this->colorHovered = new SolidBrush(hovered);
    this->colorClick = clicked;
    stringCenter->SetAlignment(StringAlignmentCenter);
	stringCenter->SetLineAlignment(StringAlignmentCenter);
}
Buttons::Buttons(Bitmap* normalBitmap, Bitmap* hoveredBitmap,  Bitmap* disabledBitmap, HDC hdc): Buttons()
{

}
void Buttons::invalidateButton(HWND hWnd)
{
	RECT rect = Helper::getAbsoluteRect(position);
	InvalidateRect(hWnd, &rect, true);
}
bool Buttons::isHovered() 
{
	return hovered;
}
bool Buttons::isClicked()
{
	if (clicked)
	{
		clicked = false;
		hovered = false;
		return true;
	}

	return false;
}
// void Buttons::draw(Graphics*	 g) 
// {
// 	if (isColor) {
// 		if (hovered)
// 		{
// 			Corner::FillRoundRect(g, colorNormal, crect, colorClick, 5);

// 			g->DrawString(
// 				text.c_str(),
// 				-1,
// 				Main::fontLato,
// 				rect,
// 				&stringCenter,
// 				Main::solidColors[Main::pSolidEnumCoolor::solidBtn]);
// 		}
// 		else if (!hovered )
// 		{
// 			Corner::FillRoundRect(g, hhovered, crect, hclicked, 5);

// 			g->DrawString(
// 				text.c_str(),
// 				-1,
// 				Main::fontLato,
// 				rect,
// 				&stringCenter,
// 				Main::solidColors[Main::pSolidEnumCoolor::solidBtn]);
			
// 		}
// 	}
// 	else 
// 	g->DrawCachedBitmap(getBitmap().get(), position.x, position.y);
// }
// void Buttons::mouseReleased(HWND hWnd, int x, int y)
// {
// 	if (disabled)
// 		return;

// 	if (std::abs(position.x - x) < extendLeftAmount)
// 		x = position.x;
// 	if (Helper::isPointInRect(x, y, position))
// 	{
// 		pressed = false;
// 		hovered = true;
// 		invalidateButton(hWnd);
// 		clicked = true;
// 	}
// }
std::shared_ptr<CachedBitmap> Buttons::getBitmap()
{
	if (disabled)
		return disabledCachedBitmap;
	else if (pressed)
		return pressedCachedBitmap;
	else if (hovered)
		return hoveredCachedBitmap;

	return normalCachedBitmap;
}
