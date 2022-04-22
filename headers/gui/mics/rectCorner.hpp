#pragma once
#include "../../../headers/stdafx.h"
namespace Corner {
	void GetRoundRectPath(GraphicsPath* pPath, Rect r, int dia);
	void DrawRoundRect(Graphics* pGraphics, Rect r, Color color, int radius, int width);
	void FillRoundRect(Graphics* pGraphics, Brush* pBrush, Rect r, Color border, int radius);
}
