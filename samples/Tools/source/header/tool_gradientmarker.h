/****************************************************************************
**
** Copyright (C) 2015
**
** This file is generated by the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#ifndef MAGUS_TOOL_GRADIENT_MARKER_H
#define MAGUS_TOOL_GRADIENT_MARKER_H

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

namespace Magus
{
    const static int KEY_GRADIENT_MARKER = 1;
    const static int VALUE_GRADIENT_MARKER_COLOR = 1;
    const static int VALUE_GRADIENT_MARKER_ALPHA = 2;

    /****************************************************************************
    QtGradientMarker represents a virtual marker for color and alpha values
    in a QtGradientWidget.
    ***************************************************************************/
    class QtGradientMarker : public QObject, public QGraphicsPathItem
    {
        Q_OBJECT

        public:
            QtGradientMarker(QGraphicsItem* parent = 0);
            virtual ~QtGradientMarker(void){};

            // Set/get the id of the marker; the id is used to uniquely define a marker
            void setId (int id) {mId = id;};
            qreal getId(void) const {return mId;};

            // Set/get the fraction of the marker (corresponds with the position of the marker in the gradient)
            // Value of the fraction is between [0..1]
            void setFraction (qreal fraction) {mFraction = fraction;};
            qreal getFraction(void) const {return mFraction;};

            // Set/get the width and height of the marker
            void setMarkerSize (QSizeF size);
            QSizeF getMarkerSize(void) const {return mSize;};

            // Determine whether the marker is selected
            void selectMarker(bool selected);
            bool isMarkerSelected (void)
            {
                return mPen.color() != Qt::black;
            };

            // Get/set color; this is the color value of the marker
            virtual void setColor (const QColor& color) = 0;
            const QColor& getColor(void) const {return mColor;};

            // Get/set alpha; this is the alpha value of the marker
            virtual void setAlpha (int alpha) = 0;
            int getAlpha(void) const {return mColor.alpha();};

            // Pure virtual function to draw the marker
            virtual void drawMarker(void) = 0;

        protected:
            int mId;
            qreal mFraction;
            QGraphicsPathItem* mColoredSquare;
            QGraphicsPathItem* mPointer;
            QSizeF mSize;
            QColor mColor;
            QPen mPen;
    };

    /****************************************************************************
    QtGradientMarkerColor represents a marker for colors in a QtGradientWidget.
    ***************************************************************************/
    class QtGradientMarkerColor : public QtGradientMarker
    {
        Q_OBJECT

        public:
            QtGradientMarkerColor(QGraphicsItem* parent = 0);
            virtual ~QtGradientMarkerColor(void);

            // Draw the marker on its current position
            virtual void drawMarker(void);

            // Set the color and update the marker
            virtual void setColor (const QColor& color);

            // Set the alpha and update the marker
            virtual void setAlpha (int alpha);
    };

    /****************************************************************************
    QtGradientMarkerAlpha represents a marker for alpha values in a QtGradientWidget.
    ***************************************************************************/
    class QtGradientMarkerAlpha : public QtGradientMarker
    {
        Q_OBJECT

        public:
            QtGradientMarkerAlpha(QGraphicsItem* parent = 0);
            virtual ~QtGradientMarkerAlpha(void);

            // Draw the marker on its current position
            virtual void drawMarker(void);

            // Set the color and update the marker
            virtual void setColor (const QColor& color);

            // Set the alpha and update the marker
            virtual void setAlpha (int alpha);
    };
}

#endif
