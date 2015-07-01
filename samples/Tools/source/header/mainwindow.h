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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>
#include "constants.h"
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QToolBar>
#include "tool_simple_texturewidget.h"
#include "tool_extended_texturewidget.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

/****************************************************************************
 MainWindow is the main container window
 ***************************************************************************/
class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(void);
		~MainWindow(void);
		void update(void);
		bool mIsClosing;

	private slots:
        void doGradientMenuAction(void);
        void doGlSphereMenuAction(void);
        void doTextureMenuAction(void);
        void doExtendedTextureMenuAction(void);
        void doLayerAndSceneViewMenuAction(void);
        void textureSelected(const QString& fileName);
        void textureRead(QPixmap pixMap, const QString& fileName, const QString& baseName);
        void textureReadExt(QPixmap pixMap, const QString& fileName, const QString& baseName);

	private:
		void createActions(void);
		void createMenus(void);
		void createToolBars(void);
		void createStatusBar(void);
		void createDockWindows(void);
		void closeEvent(QCloseEvent* event);

        QMenu* mToolsMenu;
        QAction* mGradientMenuAction;
        QAction* mGlSphereMenuAction;
        QAction* mTextureMenuAction;
        QAction* mExtendedTextureMenuAction;
        QAction* mLayerAndSceneViewMenuAction;
        Magus::QtSimpleTextureWidget* mTextureSelection;
        Magus::QtExtendedTextureWidget* mTextureSelectionExt;
};

#endif

