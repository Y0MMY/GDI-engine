#ifndef __BITMAPHELPER_H__
#define __BITMAPHELPER_H__
#include <memory>
#include "../../headers/stdafx.h"
#include <Wincodec.h>


namespace BitmapHelper
{
    
    std::shared_ptr<CachedBitmap> createCachedBitmap(Bitmap* originalBitmap, HDC hdc);
	// static Bitmap* resizeBitmap(Bitmap* source, int newWidth, int newHeight);
	// static Bitmap* loadScaledFromResource(Bitmap* originalBitmap, float xScale, float yScale);
	// static Bitmap* ResizeClone(Bitmap* bmp, INT width, INT height);
}

#endif // __BITMAPHELPER_H__