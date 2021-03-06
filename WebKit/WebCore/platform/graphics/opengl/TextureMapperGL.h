/*
 Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies)
 Copyright (C) 2014 FactorY Media Production GmbH

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Library General Public
 License as published by the Free Software Foundation; either
 version 2 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Library General Public License for more details.

 You should have received a copy of the GNU Library General Public License
 along with this library; see the file COPYING.LIB.  If not, write to
 the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 Boston, MA 02110-1301, USA.
 */

/* FYWEBKITMOD BEGIN integrated from https://gitorious.org/webkit/noamrs-webkit/source/cb48ff9f4067b8ebcbb8a54e9dfef2d6fda0b82f:WebCore/platform/graphics/opengl/TextureMapperGL.cpp */

#ifndef TextureMapperGL_h
#define TextureMapperGL_h

#if USE(ACCELERATED_COMPOSITING)

#include "FloatQuad.h"
#include "IntSize.h"
#include "TransformationMatrix.h"
#include "texmap/TextureMapper.h"

namespace WebCore {

class TextureMapperGL : public TextureMapper {
public:
    TextureMapperGL(GraphicsContext* gc);
    virtual ~TextureMapperGL() {}

    // reimps from TextureMapper
    virtual void drawTexture(const BitmapTexture& texture, const IntRect&, const TransformationMatrix& transform, float opacity, const BitmapTexture* maskTexture);
    virtual void bindSurface(BitmapTexture* surface);
    virtual void setClip(const IntRect&);
    virtual void paintToTarget(const BitmapTexture&, const IntSize&, const TransformationMatrix&, float opacity, const IntRect& visibleRect);
    virtual bool allowSurfaceForRoot() const { return true; }
    virtual PassRefPtr<BitmapTexture> createTexture();
    virtual const char* type() const;
    virtual void cleanup();

private:
    TransformationMatrix m_projectionMatrix;
    int m_curProgram;
};

class RGBA32PremultimpliedBuffer : public RefCounted<RGBA32PremultimpliedBuffer> {
public:
    virtual ~RGBA32PremultimpliedBuffer() {}
    virtual PlatformGraphicsContext* beginPaint(const IntRect& dirtyRect, bool opaque) = 0;
    virtual void endPaint() = 0;
    virtual const void* data() const = 0;
    static PassRefPtr<RGBA32PremultimpliedBuffer> create();
};

static inline int npot(int num)
{
    for (int i = 0x10000000; i > 0; i >>= 1) {
        if (num == i)
            return num;
        if (num & i)
            return (i << 1);
    }
    return 1;
}

static inline IntSize npot(const IntSize& s)
{
    return IntSize(npot(s.width()), npot(s.height()));
}

};

#endif

#endif

/* FYWEBKITMOD END */
