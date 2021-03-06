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

// Include
#include "tool_filereader.h"
#include "tool_resourcewidget.h"
#include "tool_resourcewidget_sources.h"

namespace Magus
{
    //****************************************************************************/
    QtSourcesDockWidget::QtSourcesDockWidget(const QString& iconDir, const QString& title, QMainWindow* parent, Qt::WindowFlags flags) :
        QDockWidget (title, parent, flags),
        mParent(parent)
    {
        mIconDir = iconDir;
        mResourceTreeWidget = new Magus::QtResourceTreeWidget(iconDir);
        mResourceTreeWidget->setCreateTopLevelGroupContextMenuItemEnabled(false);
        mResourceTreeWidget->setDeleteTopLevelGroupEnabled(false);
        mResourceTreeWidget->setCreateAssetContextMenuItemEnabled(false);
        mResourceTreeWidget->setTopLevelGroupItemEditable(false);
        mResourceTreeWidget->setSubLevelGroupItemEditable(true);
        mResourceTreeWidget->setAssetItemEditable(false);

        // Listen to events.
        // Note, that although the 'create asset' context menu is disabled, the QtSourcesDockWidget must still handle the 'resourceAdded'
        // signal, because it is also emitted when a subgroup is created in the mResourceTreeWidget; the subgroup must be added to
        // mSourceInfo after creation, to be able to recursively delete any assets resided in subgroups (these assets must also be
        // properly deleted from the QtAssetsDockWidget).
        connect(mResourceTreeWidget, SIGNAL(resourceSelected(int)), this, SLOT(handleResourceSelected(int)));
        connect(mResourceTreeWidget, SIGNAL(resourceAdded(int)), this, SLOT(handleResourceAdded(int)));
        connect(mResourceTreeWidget, SIGNAL(resourceImported(int)), this, SLOT(handleResourceImported(int)));
        connect(mResourceTreeWidget, SIGNAL(resourceDeleted(int)), this, SLOT(handleResourceDeleted(int)));
        connect(mResourceTreeWidget, SIGNAL(resourceMoved(int)), this, SLOT(handleResourceMoved(int)));
        connect(mResourceTreeWidget, SIGNAL(resourceSearched(QString)), this, SLOT(handleResourceSearched(QString)));
        connect(mResourceTreeWidget, SIGNAL(resourceSearchReset()), this, SLOT(handleResourceSearchReset()));
        mInnerMain = new QMainWindow();
        mInnerMain->setCentralWidget(mResourceTreeWidget);
        setWidget(mInnerMain);
        QWidget* oldTitleBar = titleBarWidget();
        setTitleBarWidget(new QWidget());
        delete oldTitleBar;

        // Add toplevel groups
        initializeResourceTree();
    }

    //****************************************************************************/
    void QtSourcesDockWidget::initializeResourceTree (void)
    {
        // Initialize; add toplevel groups to the mResourceTreeWidget up front
        QtSourcesInfo info;

        // Audio
        mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_AUDIO, TOOL_SOURCES_LEVEL_X000_AUDIO, 0, QString("Audio"), QString(""), TOOL_RESOURCE_ICON_AUDIO);
        info.toplevelId = TOOL_SOURCES_LEVEL_X000_AUDIO;
        info.resourceId = TOOL_SOURCES_LEVEL_X000_AUDIO;
        info.parentId = 0;
        info.fileName = QString("Audio");
        info.baseName = info.fileName;
        info.fileDialogTitle = QString("Audio");
        info.filter = TOOL_SOURCES_FORMAT_AUDIO;
        mSourceInfo[TOOL_SOURCES_LEVEL_X000_AUDIO] = info;

        // Materials
        mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_MATERIALS, TOOL_SOURCES_LEVEL_X000_MATERIALS, 0, QString("Materials"), QString(""), TOOL_RESOURCE_ICON_MATERIAL);
        info.toplevelId = TOOL_SOURCES_LEVEL_X000_MATERIALS;
        info.resourceId = TOOL_SOURCES_LEVEL_X000_MATERIALS;
        info.fileName = QString("Materials");
        info.baseName = info.fileName;
        info.fileDialogTitle = QString("Materials");
        info.filter = TOOL_SOURCES_FORMAT_MATERIALS;
        mSourceInfo[TOOL_SOURCES_LEVEL_X000_MATERIALS] = info;

        // Meshes
        mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_MESHES, TOOL_SOURCES_LEVEL_X000_MESHES, 0, QString("Meshes"), QString(""), TOOL_RESOURCE_ICON_MESH);
        info.toplevelId = TOOL_SOURCES_LEVEL_X000_MESHES;
        info.resourceId = TOOL_SOURCES_LEVEL_X000_MESHES;
        info.fileName = QString("Meshes");
        info.baseName = info.fileName;
        info.fileDialogTitle = QString("Meshes");
        info.filter = TOOL_SOURCES_FORMAT_MESHES;
        mSourceInfo[TOOL_SOURCES_LEVEL_X000_MESHES] = info;

        // Scripts
        mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_SCRIPTS, TOOL_SOURCES_LEVEL_X000_SCRIPTS, 0, QString("Scripts"), QString(""), TOOL_RESOURCE_ICON_SCRIPT);
        info.toplevelId = TOOL_SOURCES_LEVEL_X000_SCRIPTS;
        info.resourceId = TOOL_SOURCES_LEVEL_X000_SCRIPTS;
        info.fileName = QString("Scripts");
        info.baseName = info.fileName;
        info.fileDialogTitle = QString("Scripts");
        info.filter = TOOL_SOURCES_FORMAT_SCRIPTS;
        mSourceInfo[TOOL_SOURCES_LEVEL_X000_SCRIPTS] = info;

        // Textures
        mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_TEXTURES, TOOL_SOURCES_LEVEL_X000_TEXTURES, 0, QString("Textures"), QString(""), TOOL_RESOURCE_ICON_TEXTURE);
        info.toplevelId = TOOL_SOURCES_LEVEL_X000_TEXTURES;
        info.resourceId = TOOL_SOURCES_LEVEL_X000_TEXTURES;
        info.fileName = QString("Textures");
        info.baseName = info.fileName;
        info.fileDialogTitle = QString("Textures");
        info.filter = TOOL_SOURCES_FORMAT_TEXTURES;
        mSourceInfo[TOOL_SOURCES_LEVEL_X000_TEXTURES] = info;

        // Determine what is enabled/disabled if a toplevelgroup is selected
        mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(TOOL_RESOURCETREE_ACTION_CREATE_TOPLEVEL_GROUP, false);
        mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(TOOL_RESOURCETREE_ACTION_CREATE_SUBGROUP, true);
        mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(TOOL_RESOURCETREE_ACTION_CREATE_ASSET, true);
        mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(TOOL_RESOURCETREE_ACTION_IMPORT_ASSET, true);
        mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(TOOL_RESOURCETREE_ACTION_DUPLICATE_ASSET, false);
        mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(TOOL_RESOURCETREE_ACTION_DELETE_RESOURCE, false);

        // Determine what is enabled/disabled if a subgroup is selected
        mResourceTreeWidget->enableContextMenuItemForSubGroup(TOOL_RESOURCETREE_ACTION_CREATE_TOPLEVEL_GROUP, false);
        mResourceTreeWidget->enableContextMenuItemForSubGroup(TOOL_RESOURCETREE_ACTION_CREATE_SUBGROUP, true);
        mResourceTreeWidget->enableContextMenuItemForSubGroup(TOOL_RESOURCETREE_ACTION_CREATE_ASSET, true);
        mResourceTreeWidget->enableContextMenuItemForSubGroup(TOOL_RESOURCETREE_ACTION_IMPORT_ASSET, true);
        mResourceTreeWidget->enableContextMenuItemForSubGroup(TOOL_RESOURCETREE_ACTION_DUPLICATE_ASSET, false);
        mResourceTreeWidget->enableContextMenuItemForSubGroup(TOOL_RESOURCETREE_ACTION_DELETE_RESOURCE, true);

        // Determine what is enabled/disabled if an asset is selected
        mResourceTreeWidget->enableContextMenuItemForAsset(TOOL_RESOURCETREE_ACTION_CREATE_TOPLEVEL_GROUP, false);
        mResourceTreeWidget->enableContextMenuItemForAsset(TOOL_RESOURCETREE_ACTION_CREATE_SUBGROUP, false);
        mResourceTreeWidget->enableContextMenuItemForAsset(TOOL_RESOURCETREE_ACTION_CREATE_ASSET, false);
        mResourceTreeWidget->enableContextMenuItemForAsset(TOOL_RESOURCETREE_ACTION_IMPORT_ASSET, false);
        mResourceTreeWidget->enableContextMenuItemForAsset(TOOL_RESOURCETREE_ACTION_DUPLICATE_ASSET, true);
        mResourceTreeWidget->enableContextMenuItemForAsset(TOOL_RESOURCETREE_ACTION_DELETE_RESOURCE, true);

        // Set 'Audio' selected
        mResourceTreeWidget->selectResource(TOOL_SOURCES_LEVEL_X000_AUDIO, false);
    }

    //****************************************************************************/
    QtSourcesDockWidget::~QtSourcesDockWidget(void)
    {
    }

    //****************************************************************************/
    QVector<QtResourceInfo*>& QtSourcesDockWidget::getResources (void)
    {
        // Delegate to mResourceTreeWidget; this is the component that actually retrieves the data
        return mResourceTreeWidget->getResources();
    }

    //****************************************************************************/
    void QtSourcesDockWidget::setResources(const QVector<QtResourceInfo*>& resources)
    {
        // Delegate to mResourceTreeWidget; this is the component that actually sets the data in the tree
        mResourceTreeWidget->setResources(resources);
    }

    //****************************************************************************/
    void QtSourcesDockWidget::selectTopLevel(int toplevelId)
    {
        mResourceTreeWidget->selectResource(toplevelId, false);
    }

    //****************************************************************************/
    void QtSourcesDockWidget::clearContent(void)
    {
        mResourceTreeWidget->clear();
        initializeResourceTree();
    }

    //****************************************************************************/
    void QtSourcesDockWidget::addAssetQuiet(int toplevelId, const QString& name, const QString& baseName)
    {
        // Suppress the signal that a resource was added, otherwise the signal causes the asset to
        // be added to the asset widget
        int resourceId = mResourceTreeWidget->addResource(toplevelId, baseName, name, QString(""), true, true);
        mResourceTreeWidget->expand(toplevelId);

        // Also add it to mSourceInfo
        QtSourcesInfo info;
        info.toplevelId = toplevelId;
        info.resourceId = resourceId;
        info.parentId = toplevelId;
        info.fileName = name;
        info.baseName = baseName;
        mSourceInfo[resourceId] = info;
    }

    //****************************************************************************/
    void QtSourcesDockWidget::deleteAssetQuiet(int toplevelId, const QString& name, const QString& baseName)
    {
        mResourceTreeWidget->deleteResource(toplevelId, name, true);
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceSelected(int resourceId)
    {
        // Determine which type is selected
        QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
        if (it != mSourceInfo.end())
        {
            QtSourcesInfo info = it.value();
            emit resourceSelected(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseName);
            //QMessageBox::information(0, QString("this"), QVariant(info.toplevelId).toString()); // test
        }
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceAdded(int resourceId)
    {
        QtSourcesInfo info;
        int toplevelId = mResourceTreeWidget->getToplevelParentId(resourceId);
        QString name = mResourceTreeWidget->getResourceName(resourceId);
        QString fullQualifiedName = mResourceTreeWidget->getFullQualifiedName(resourceId);
        info.toplevelId = toplevelId;
        info.resourceId = resourceId;
        info.parentId = mResourceTreeWidget->getParentId(resourceId);
        info.fileName = fullQualifiedName;
        info.baseName = name;
        mSourceInfo[resourceId] = info;

        // Emit file info to QtResourceMain, because the QtAssetsDockWidget must be appended with the new files
        // Do this only in case the resource is an asset
        if (mResourceTreeWidget->isResourceAsset(resourceId))
            emit resourceAdded(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseName);
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceImported(int resourceId)
    {
        // Get type of resource; this is done by determine the toplevel item
        int toplevelId = mResourceTreeWidget->getToplevelParentId(resourceId);

        // Determine file dialog filter; toplevel items are stored with additional info (file dialog title and file dialog filter)
        QtSourcesInfo info;
        info = mSourceInfo.value(toplevelId);
        QString title = info.fileDialogTitle;
        QString filter = info.filter;

        // Open file dialog
        setCursor(Qt::WaitCursor);
        QMap<QString, QFileInfo> fileNames;
        fileNames = mFileReader.readFileNames(title, QString(""), filter);
        setCursor(Qt::ArrowCursor);

        // Handle each file; Assume that the resourceId is always a group
        if (!fileNames.empty())
        {
            QMap<QString, QFileInfo>::iterator it;
            QFileInfo fileInfo;
            for (it = fileNames.begin(); it != fileNames.end(); ++it)
            {
                // Add an asset to the resourceId that is passed in this function (this is the parent)
                // nB. Also add the info to mSourceInfo (file dialog title and file dialog filter are omitted)
                // fileInfo.fileName() is the base file name
                // fileInfo.absoluteFilePath() is the full qualified filename
                fileInfo = it.value();
                int childResourceId = mResourceTreeWidget->addResource(resourceId,
                                                                       fileInfo.fileName(),
                                                                       fileInfo.absoluteFilePath(),
                                                                       QString(""),
                                                                       true);
                info.toplevelId = toplevelId;
                info.resourceId = childResourceId;
                info.parentId = resourceId;
                info.fileName = fileInfo.absoluteFilePath();
                info.baseName = fileInfo.fileName();
                mSourceInfo[childResourceId] = info;

                // Emit file info to QtResourceMain, because the QtAssetsDockWidget must be appended with the new files
                emit resourceImported(toplevelId, info.parentId, info.resourceId, info.fileName, info.baseName);
            }
            mResourceTreeWidget->expand(resourceId);
        }
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceDeleted(int resourceId)
    {
        // Do not handle resources with resourceId = 0
        if (resourceId == 0)
            return;

        // Get all the underlying assets (filenames) + delete them from the mSourceInfo
        foreach(QtSourcesInfo info, mSourceInfo)
        {
            if (info.parentId == resourceId)
                handleResourceDeleted(info.resourceId);
            else if (info.resourceId == resourceId)
            {
                // Delete from mSourceInfo
                emit resourceDeleted(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseName);
                mSourceInfo.remove(resourceId);
            }
        }
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceMoved(int resourceId)
    {
        // Search the info object
        QtSourcesInfo info;
        QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
        if (it == mSourceInfo.end())
            return;

        // Update the parentId and toplevelId (Although in this version it is not possible to move to a different toplevel)
        // Emitting again is not needed, because nothing changed in the assets widget
        info = it.value();
        info.toplevelId = mResourceTreeWidget->getToplevelParentId(resourceId);
        info.parentId = mResourceTreeWidget->getParentId(resourceId);
        mSourceInfo[resourceId] = info; // Overwrite existing one
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceSearched(const QString& searchPattern)
    {
        // Signal
        emit resourceSearched(searchPattern);
    }

    //****************************************************************************/
    void QtSourcesDockWidget::handleResourceSearchReset(void)
    {
        // Signal
        emit resourceSearchReset();
    }
}


