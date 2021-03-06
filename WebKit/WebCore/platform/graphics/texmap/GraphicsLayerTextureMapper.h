/*
    Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies)
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

/* FYWEBKITMOD BEGIN integrated from https://gitorious.org/webkit/noamrs-webkit/source/cb48ff9f4067b8ebcbb8a54e9dfef2d6fda0b82f:WebCore/platform/graphics/texmap/GraphicsLayerTextureMapper.h */

#ifndef GraphicsLayerTextureMapper_h
#define GraphicsLayerTextureMapper_h

// #if USE(ACCELERATED_COMPOSITING) // FYWEBKITMOD removed

#include "GraphicsContext.h"
#include "GraphicsLayer.h"
#include "GraphicsLayerClient.h"
#include "Image.h"

#define ENABLE_TEXMAP_ANIMATION 1

namespace WebCore {

class TextureMapperNode;
class BitmapTexture;
class TextureMapper;

class GraphicsLayerTextureMapper : public GraphicsLayer {
    friend class TextureMapperNode;

public:
    GraphicsLayerTextureMapper(GraphicsLayerClient*);
    virtual ~GraphicsLayerTextureMapper();

    // reimps from GraphicsLayer.h
    virtual void setNeedsDisplay();
    virtual void setNeedsDisplayInRect(const FloatRect&);
    virtual void setParent(GraphicsLayer* layer);
    virtual bool setChildren(const Vector<GraphicsLayer*>&);
    virtual void addChild(GraphicsLayer*);
    virtual void addChildAtIndex(GraphicsLayer*, int index);
    virtual void addChildAbove(GraphicsLayer* layer, GraphicsLayer* sibling);
    virtual void addChildBelow(GraphicsLayer* layer, GraphicsLayer* sibling);
    virtual bool replaceChild(GraphicsLayer* oldChild, GraphicsLayer* newChild);
    virtual void removeFromParent();
    virtual void setMaskLayer(GraphicsLayer* layer);
    virtual void setPosition(const FloatPoint& p);
    virtual void setAnchorPoint(const FloatPoint3D& p);
    virtual void setSize(const FloatSize& size);
    virtual void setTransform(const TransformationMatrix& t);
    virtual void setChildrenTransform(const TransformationMatrix& t);
    virtual void setPreserves3D(bool b);
    virtual void setMasksToBounds(bool b);
    virtual void setDrawsContent(bool b);
    virtual void setBackgroundColor(const Color&);
    virtual void clearBackgroundColor();
    virtual void setContentsOpaque(bool b);
    virtual void setBackfaceVisibility(bool b);
    virtual void setOpacity(float opacity);
    virtual void setContentsRect(const IntRect& r);
    virtual void setReplicatedByLayer(GraphicsLayer*);
    virtual void setContentsToImage(Image*);
    virtual void setContentsToMedia(PlatformLayer*);
    virtual void setContentsBackgroundColor(const Color&);
    virtual void setGeometryOrientation(CompositingCoordinatesOrientation orientation);
    virtual void setContentsOrientation(CompositingCoordinatesOrientation orientation);
    virtual void syncCompositingState();
    virtual void syncCompositingStateForThisLayerOnly();
    virtual void setName(const String& name);
    virtual NativeLayer nativeLayer() const;
    virtual PlatformLayer* platformLayer() const;

    virtual bool addAnimation(const KeyframeValueList&, const IntSize& /*boxSize*/, const Animation*, 
                              const String& /*keyframesName*/, double /*timeOffset*/);
    virtual void removeAnimationsForProperty(AnimatedPropertyID);
#if ENABLE_TEXMAP_ANIMATION
    virtual void removeAnimationsForKeyframes(const String& keyframesName);
    virtual void pauseAnimation(const String& keyframesName, double timeOffset);
    virtual void suspendAnimations(double time);
    virtual void resumeAnimations();
#endif

private:
    OwnPtr<TextureMapperNode> m_node;
};

}
#endif // GraphicsLayerTextureMapper_h

/* FYWEBKITMOD END */
