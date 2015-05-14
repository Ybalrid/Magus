/****************************************************************************
**
** Copyright (C) 2014
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

#ifndef MAGUS_TOOL_GRADIENT_WIDGET_H
#define MAGUS_TOOL_GRADIENT_WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include "tool_gradient.h"
#include "tool_gradientmarker.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE


/*
 * TODO:
 * - Add button 'clear gradient'
 * - Add 'Close' button
 * - Add selection list with predefined gradients (create function enablePredefinedList)
 * - Add button 'Add to list' (moves the current gradient to the predefined list)
 * - Add function getColorList (returns color values)
 * - Add function getAlphaList (returns alpha values)
 * - Add function exportColorAndAlpha (returns colors and corresponding alpha values)
 * - Add function setGradientColorList / setGradientAlphaList
 */

namespace Magus
{
    /****************************************************************************
    Main class for gradient editor
    ***************************************************************************/
    class QtGradientWidget : public QWidget
    {
        Q_OBJECT

        public:
            QtGradientWidget(QWidget* parent = 0);
            virtual ~QtGradientWidget(void);

            // To be used for mouse events
            bool QtGradientWidget::eventFilter(QObject* object, QEvent* event);

            // Handle mouse events
            void mouseMoveHandler(QGraphicsSceneMouseEvent* mouseEvent);
            void mouseClickHandler(QGraphicsSceneMouseEvent* mouseEvent);

            // Create a marker for color. Argument 'mousePos' determines the mouse position
            // (where the marker is placed).
            QtGradientMarkerColor* createGradientMarkerColor(QGraphicsSceneMouseEvent* mouseEvent);

            // Create a marker for alpha value. Argument 'mousePos' determines the mouse position
            // (where the marker is placed).
            QtGradientMarkerAlpha* createGradientMarkerAlpha(QGraphicsSceneMouseEvent* mouseEvent);

            // Set/get the width and the height offset (in fraction of the total widget height) of the gradient
            void setGradientDimension (qreal width, qreal heightOffsetFraction = 0.13f);
            qreal getGradientHeightOffsetFraction(void) const {return mGradientHeightOffsetFraction;};
            qreal getGradientWidth(void) const {return mGradientWidth;};

        protected:
            QGraphicsItem* itemAt(const QPointF& pos);
            void enableAlphaWidgets(bool enabled);
            void enableColorWidgets(bool enabled);

        private slots:
            void alphaSliderValueChanged(int value);
            void alphaEditValueChanged(QString value);
            void valueChangedRGB(void);
            void valueChangedHex(void);
            void dialogButtonClicked(void);
            void deleteAlphaMarker(void);
            void deleteColorMarker(void);

        private:
            int idCounter;
            qreal mGradientHeightOffsetFraction;
            qreal mGradientWidth;
            QGraphicsView* mView;
            QGraphicsScene* mScene;
            QtGradient* mGradient;
            QSizeF mMarkerSize;
            qreal mAlphaY;
            qreal mColorY;
            qreal mMarkerMinX;
            qreal mMarkerMaxX;
            QtGradientMarker* mCurrentMarker;
            QSlider* mAlphaSlider;
            QLineEdit* mAlphaEdit;
            QColor mCurrentColorValue;
            QLineEdit* mR;
            QLineEdit* mG;
            QLineEdit* mB;
            QLineEdit* mHex;
            QLabel* mColorFill;
            QPushButton* mDialogButton;
            QPushButton* mDeleteAlphaMarkerButton;
            QPushButton* mDeleteColorMarkerButton;
            void updateRGBWithCurrentColor(void);
            void updateHexWithCurrentColor(void);
            void updateColorFill (void);
    };
}

#endif
