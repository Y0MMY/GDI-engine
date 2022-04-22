#ifndef __BUTTONS_H__
#define __BUTTONS_H__
#include "../../headers/mics/helper.hpp"
#include <memory>
class Buttons
{
private:
//=====================================================
//           ptr to CachedBitmap of state buttons
    std::shared_ptr<CachedBitmap> normalCachedBitmap;  
	std::shared_ptr<CachedBitmap> hoveredCachedBitmap;
	std::shared_ptr<CachedBitmap> pressedCachedBitmap;
	std::shared_ptr<CachedBitmap> disabledCachedBitmap;
//=====================================================
    RRECT position;
    uint16_t extendLeftAmount;
    std::wstring text;
    SolidBrush* colorNormal; 
    SolidBrush* colorHovered;
    Color colorClick;
	bool hovered;
	bool pressed;
	bool clicked;
	bool disabled;
	bool isColor;
    StringFormat* stringCenter;
    std::shared_ptr<CachedBitmap> getBitmap();
public:
    Buttons(/* args */) noexcept;
    ~Buttons() = default;
    Buttons(std::wstring text, Color normal, Color hovered, Color clicked, RectF rect); // btn w/t bitmap (only colors)
    Buttons(Bitmap* normalBitmap, Bitmap* hoveredBitmap,  Bitmap* disabledBitmap, HDC hdc);// btn w/. bitmaps
    void mouseReleased(HWND hWnd, int x, int y);
    void mouseMoved(HWND hWnd, int x, int y);
    bool isClicked();
    bool isHovered();
    void draw(Graphics* g);
    void invalidateButton(HWND hWnd);
};


#endif // __BUTTONS_H__