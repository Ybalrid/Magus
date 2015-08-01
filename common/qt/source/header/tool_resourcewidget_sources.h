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

#ifndef MAGUS_TOOL_RESOURCES_SOURCES_H
#define MAGUS_TOOL_RESOURCES_SOURCES_H

#include <QtWidgets>
#include "constants.h"
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QToolBar>
#include <QTabWidget>
#include "tool_filereader.h"
#include "tool_resourcetree_widget.h"

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

namespace Magus
{
    static const QString TOOL_SOURCES_FORMAT_AUDIO = QString("Audio (*.wav *.mp3)");
    static const QString TOOL_SOURCES_FORMAT_MATERIALS = QString("Materials (*.mat)");
    static const QString TOOL_SOURCES_FORMAT_MESHES = QString("Meshes (*.mesh *.x *.fbx *.3ds)");
    static const QString TOOL_SOURCES_FORMAT_SCRIPTS = QString("Scripts (*.lua)");
    static const QString TOOL_SOURCES_FORMAT_TEXTURES = QString("Textures (*.bmp *.jpg *.jpeg *.koa *.iff *.lbm *.mng *.pbm *.pcd *.pcx *.pgm *.pgm *.png *.ppm *.ppm *.ras *.tga *.targa *.tif *.tiff *.wap *.wbmp *.wbm *.psd *.cut *.xbm *.xpm *.gif *.hdr *.g3 *.sgi *.exr *.j2k *.j2c *.jp2 *.pfm *.pct *.pict *.pic *.dds)");

    /****************************************************************************
    Struct for source info
    ***************************************************************************/
    struct QtSourcesInfo
    {
        int resourceId;
        int toplevelId;
        int parentId;
        QString fileName;
        QString baseName;
        QString fileDialogTitle;
        QString filter;
    };

    /****************************************************************************
    This class represents a generic dock widget for sources. The QtSourcesDockWidget
    contains the resourcetree with groups and assets. QtSourcesDockWidget uses the
    following settings:
    - The resourcetree contains audio, materials, meshes, scripts and textures groups by default
    - The contexmenu is enabled (default)
    - Toplevel groups are added up front (by means of its parent
    - Disable the contextmenu-item to add/create a new toplevel group
    - Don't register the resource (with mResourceTreeWidget->registerResource)
        => icons of subgroups cannot be selected from the contextmenu, but are inherited from toplevel group
    - Toplevel groups cannot be deleted
    - Subgroups and assets are not added up front
        => Add them by means of the contextmenu
    ***************************************************************************/
    class QtSourcesDockWidget : public QDockWidget
    {
        Q_OBJECT

        public:
            QtSourcesDockWidget(const QString& iconDir, const QString& title, QMainWindow* parent, Qt::WindowFlags flags = 0);
            ~QtSourcesDockWidget(void);

            // Select a toplevel resource.
            void selectTopLevel(int toplevelId);

        signals:
            void resourceSelected(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName);
            void resourceAdded(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName);
            void resourceImported(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName);
            void resourceDeleted(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName);

        private slots:
            void handleResourceSelected(int resourceId);
            void handleResourceAdded(int resourceId);
            void handleResourceImported(int resourceId);
            void handleResourceDeleted(int resourceId);
            void handleResourceMoved(int resourceId);

        private:
            QMainWindow* mParent;
            QMainWindow* mInnerMain;
            Magus::QtResourceTreeWidget* mResourceTreeWidget;
            QString mIconDir;
            QtFileReader mFileReader;
            QMap<int, QtSourcesInfo> mSourceInfo;
    };
}

#endif

