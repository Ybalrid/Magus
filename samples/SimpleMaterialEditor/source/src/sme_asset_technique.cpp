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

// Include
#include "constants.h"
#include "asset_containerwidget.h"
#include "sme_asset_technique.h"

namespace Magus
{
    //****************************************************************************/
    QtAssetTechnique::QtAssetTechnique(const QString& fileNameIcon, QWidget* parent) : QWidget(parent)
    {
        mTechniqueNode = 0;
        QVBoxLayout* mainLayout = new QVBoxLayout;
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mAssetWidget = new QtAssetWidget(QString("Technique"), fileNameIcon, this);
        mAssetWidget->setFileNameIconCollapsed(ASSET_ICON_COLLAPSE);
        mAssetWidget->setFileNameIconExpanded(ASSET_ICON_EXPAND);
        mAssetWidget->setHeaderTitleBold();
        mainLayout->addWidget(mAssetWidget);

        // Create dummy container (there are no properties) - General
        QtContainerWidget* container = 0;
        container = mAssetWidget->createContainer(ASSET_CONTAINER_TECHNIQUE_GENERAL, QString("General"));
        container->setTitleIcon(ASSET_ICON_CUBE_BOLD);
        container->setTitleBold();

        setLayout(mainLayout);
        mAssetWidget->expandAllContainers();
    }

    //****************************************************************************/
    QtAssetTechnique::~QtAssetTechnique(void)
    {
    }

    //****************************************************************************/
    void QtAssetTechnique::setObject (QtNodeTechnique* techniqueNode)
    {
        // No actions
    }

    //****************************************************************************/
    void QtAssetTechnique::propertyValueChanged(QtProperty* property)
    {
        // No actions
    }

}
