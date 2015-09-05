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

// Include
#include "tool_resourcewidget.h"
#include <QMessageBox>

namespace Magus
{
    //****************************************************************************/
    QtResourceWidget::QtResourceWidget(const QString& iconDir, QWidget* parent) : QWidget(parent)
    {
        mIconDir = iconDir;
        QHBoxLayout* mainLayout = new QHBoxLayout;
        mResourceMain = new QtResourceMain(iconDir); // Don't set parent
        connect(mResourceMain, SIGNAL(loadButtonClicked()), this, SLOT(handleLoadResources()));
        connect(mResourceMain, SIGNAL(saveButtonClicked()), this, SLOT(handleSaveResources()));
        mainLayout->addWidget(mResourceMain);
        setLayout(mainLayout);
    }

    //****************************************************************************/
    QtResourceWidget::~QtResourceWidget(void)
    {
    }

    //****************************************************************************/
    QVector<QtResourceInfo*>& QtResourceWidget::getResources (void)
    {
        // Delegate to mResourceMain
        return mResourceMain->getResources();
    }

    //****************************************************************************/
    void QtResourceWidget::setResources (const QVector<QtResourceInfo*>& resources)
    {
        // TODO
        // Assume that 'QtResourceInfo->resourceName' is a filename, so the basename can be easily derived
        // Delegate to mResourceMain and from there, delegate to both mSourcesDockWidget and mAssetsDockWidget
    }

    //****************************************************************************/
    void QtResourceWidget::handleLoadResources(void)
    {
        emit loadResources();
    }

    //****************************************************************************/
    void QtResourceWidget::handleSaveResources(void)
    {
        emit saveResources();
    }
}