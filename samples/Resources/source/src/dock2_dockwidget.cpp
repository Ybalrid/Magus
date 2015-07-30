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
#include "mainwindow.h"
#include "Dock2_dockwidget.h"
#include "tool_filereader.h"
#include "magus_core.h"

//****************************************************************************/
Dock2DockWidget::Dock2DockWidget(QString title, MainWindow* parent, Qt::WindowFlags flags) : 
	QDockWidget (title, parent, flags), 
	mParent(parent)
{
    /*
    //setCursor(Qt::WaitCursor);
    mAudioSelection = new Magus::QtAudioWidget(QString("../common/icons/"), this);
    mAudioSelection->setTextureSize(QSize(112, 120));

    // Create filereader and read the images from the filesystem
    Magus::QtFileReader fileReader;
    connect(&fileReader, SIGNAL(fileRead(QString,QString,QString)), this, SLOT(fileRead(QString,QString,QString)));
    fileReader.readFileNamesRecursively(QString("../../assets/audio"), QString(""));
    setCursor(Qt::ArrowCursor);
    */

    mInnerMain = new QMainWindow();
    //mInnerMain->setCentralWidget(mAudioSelection);
    setWidget(mInnerMain);

    // Perform standard functions
    createActions();
    createMenus();
    createToolBars();
}

//****************************************************************************/
Dock2DockWidget::~Dock2DockWidget(void)
{
}

//****************************************************************************/
void Dock2DockWidget::createActions(void)
{

}

//****************************************************************************/
void Dock2DockWidget::createMenus(void)
{

}

//****************************************************************************/
void Dock2DockWidget::createToolBars(void)
{

}

//****************************************************************************/
void Dock2DockWidget::fileRead(const QString& path, const QString& fileName, const QString& baseName)
{
    mAudioSelection->addAudio(Magus::SOURCE_FILE, fileName, baseName);
}



