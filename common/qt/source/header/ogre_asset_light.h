/****************************************************************************
**
** Copyright (C) 2016
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

#ifndef MAGUS_OGRE_ASSET_LIGHT_H
#define MAGUS_OGRE_ASSET_LIGHT_H

#include <QWidget>
#include "Ogre.h"
#include "asset_assetwidget.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

namespace Magus
{
    /****************************************************************************
    Widget that represents the Ogre Light properties
    ***************************************************************************/
    class QtOgreAssetLight : public QWidget
    {
        Q_OBJECT

        public:
            QtOgreAssetLight(const QString& iconDir, QWidget* parent = 0);
            virtual ~QtOgreAssetLight(void);

            // Containers
            const static int CONTAINER_GENERAL = 0;
            const static int CONTAINER_TRANSFORM = 1;
            const static int CONTAINER_COLOR = 2;

            // Properties
            const static int LIGHT_NAME_PROPERTY = 0;
            const static int LIGHT_TYPE = 1;
            const static int LIGHT_POSITION_PROPERTY = 2;
            const static int LIGHT_DIRECTION_PROPERTY = 3;
            const static int LIGHT_ATTENUATION_CONSTANT = 4;
            const static int LIGHT_ATTENUATION_LINEAR = 5;
            const static int LIGHT_ATTENUATION_QUADRATIC = 6;
            const static int LIGHT_ATTENUATION_RANGE = 7;
            const static int LIGHT_POWER_SCALE = 8;
            const static int LIGHT_SPOTLIGHT_FALLOFF = 9;
            const static int LIGHT_SPOTLIGHT_NEARCLIP_DIST = 10;
            const static int LIGHT_SPOTLIGHT_INNERANGLE = 11;
            const static int LIGHT_SPOTLIGHT_OUTERANGLE = 12;
            const static int LIGHT_COLOR_DIFFUSE = 13;
            const static int LIGHT_COLOR_SPECULAR = 14;

            // Synchronize an Ogre Light with the QtOgreAssetLight widget.
            void bindObject (Ogre::Light* light);

            // Some convenient functions
            void expandAll(void);
            void collapseAll(void);

        private slots:
            //void containerAction2Clicked (QtContainerWidget* container);
            void propertyValueChanged(QtProperty* property);

        private:
            QtAssetWidget* mAssetWidget;
            Ogre::Light* mOgreLight;
    };
}

#endif
