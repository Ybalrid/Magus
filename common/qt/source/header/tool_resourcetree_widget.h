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

#ifndef MAGUS_TOOL_RESOURCE_WIDGET_H
#define MAGUS_TOOL_RESOURCE_WIDGET_H

#include <QMenu>
#include <QWidget>
#include <QMouseEvent>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "magus_treewidget.h"

/*
 * TODO:
 * - emits resourceRenamed, when a resource is renamed
 * - Add to contextmenu: Duplicate asset (create new entry and emit signal with existing resourceId and new resourceId)
 * - Save asset (emits signal only)
 * - Edit asset (emits signal only)
 * - getAssets (returns only the assets of all groups and subgroups, but not the groups themselves)
 * - getGroups (returns only the groups/subgroups, but not the assets)
 * - getResources (returns all groups, subgroups and assets)
 * - Show warning when a resource is deleted (through the context menu)
*/

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

namespace Magus
{
    static const int TOOL_RESOURCETREE_ICON_WIDTH = 24;
    static const int TOOL_RESOURCETREE_KEY_RESOURCEID = 1;
    static const int TOOL_RESOURCETREE_KEY_PARENTID = 2;
    static const int TOOL_RESOURCETREE_KEY_ICONNAME = 3;
    static const int TOOL_RESOURCETREE_KEY_TYPE = 4;
    static const int TOOL_RESOURCETREE_KEY_TYPE_TOPLEVEL_GROUP = 1;
    static const int TOOL_RESOURCETREE_KEY_TYPE_GROUP = 2;
    static const int TOOL_RESOURCETREE_KEY_TYPE_ASSET = 3;
    static const QString TOOL_RESOURCETREE_OBJECT_NAME = QString("QtResourceTreeWidget");
    static const QString TOOL_RESOURCETREE_ICON_SEARCH = QString("search_bold.png");
    static const QString TOOL_RESOURCETREE_ICON_CLOSE = QString("close_bold.png");
    static const QString TOOL_RESOURCETREE_ACTION_CREATE_TOPLEVEL_GROUP = QString("Create a toplevel group");
    static const QString TOOL_RESOURCETREE_ACTION_CREATE_SUBGROUP = QString("Create a subgroup");
    static const QString TOOL_RESOURCETREE_ACTION_CREATE_ASSET = QString("Create an asset");
    static const QString TOOL_RESOURCETREE_ACTION_IMPORT_ASSET = QString("Import asset(s)");
    static const QString TOOL_RESOURCETREE_ACTION_DELETE_RESOURCE = QString("Delete selected item");
    static const QString TOOL_RESOURCETREE_WARNING_1 = QString("Toplevel groups may not be moved");
    static const QString TOOL_RESOURCETREE_WARNING_2 = QString("Attaching a subgroup to an asset is not allowed");
    static const QString TOOL_RESOURCETREE_WARNING_3 = QString("Attaching an asset to another asset is not allowed");
    static const QString TOOL_RESOURCETREE_WARNING_4 = QString("Items may only be moved within the same toplevel group");
    static const QString TOOL_RESOURCETREE_WARNING_5 = QString("Only items within this widgets are allowed to be dropped");

    /****************************************************************************
    Struct for resource info
    ***************************************************************************/
    struct QtResourceInfo
    {
        int resourceId;
        int parentId;
        QString iconName;
        QString resourceName;
    };

    /****************************************************************************
    Main widget class for resource tree. This widget contains a tree structure with
    resources:
    - Groups (or folders) in the most top-level and subgroups in deeper levels.
    - Assets are located in the lowest levels.
    ***************************************************************************/
    class QtResourceTreeWidget : public QWidget
    {
        Q_OBJECT

        public:
            QtResourceTreeWidget(const QString& iconDir, QWidget* parent = 0);
            virtual ~QtResourceTreeWidget(void);
            bool eventFilter(QObject* object, QEvent* event);

            // Set the maximum depth level of the tree. The default is 4.
            void setMaxDepth(int maxDepth);

            // Return the maximum depth level.
            int getMaxDepth(void) const;

            // A registered resource does not automatically show up in the resource tree, but is used in the contextmenu.
            // By means of the contextmenu, the resource can be added (once) to the resource tree, but it can
            // also be used as a selection item (eg. select icon of a subgroup)
            void registerResource (int resourceId, const QString& resourceName, const QString& iconName);

            // Returns a list of registered resources
            QVector<QtResourceInfo*>& getRegisteredResources (void);

            // If true, a context menu is displayed when the right mousebutton is selected.
            void setContextMenuEnabled(bool enabled);
            bool isContextMenuEnabled(void);

            // If true, the context menu is extended with an option to create a toplevel group
            void setCreateTopLevelGroupContextMenuItemEnabled(bool enabled);
            bool isCreateTopLevelGroupContextMenuItemEnabled(void);

            // If true, the toplevel items can be editted (false is the default)
            void setTopLevelGroupItemEditable(bool editable);
            bool isTopLevelGroupItemEditable(void);

            // If true, the toplevel group cannot be deleted
            void setDeleteTopLevelGroupEnabled (bool enabled);
            bool isDeleteTopLevelGroupEnabled (void);

            // If true, the context menu is extended with an option to create a subgroup
            void setCreateSubGroupContextMenuItemEnabled(bool enabled);
            bool isCreateSubGroupContextMenuItemEnabled(void);

            // If true, a created subgroup inherits the icon from its parent
            void setInheritSubGroupIconFromParent(bool inherit);
            bool isInheritSubGroupIconFromParent(void);

            // If true, the context menu is extended with an option to create an asset
            void setCreateAssetContextMenuItemEnabled(bool enabled);
            bool isCreateAssetContextMenuItemEnabled(void);

            // If true, the context menu is extended with an option to import an asset
            // Importing is not actually working, but it emits a signal. The application that
            // uses this widget can react on this signal.
            void setImportAssetContextMenuItemEnabled(bool enabled);
            bool isImportAssetContextMenuItemEnabled(void);

            // If true, the context menu is extended with an option to delete a resource
            void setDeleteResourceContextMenuItemEnabled(bool enabled);
            bool isDeleteResourceContextMenuItemEnabled(void);

            // Add a resource to the resource tree. A resource in this context is:
            //     - a group (Meshes, Audio, Light, etc.)
            //     - a subgroup (eg. Main_Character, Vehicles.)
            //     - an asset (mesh, image/texture, script, etc.)
            // The resource is identified by means of the resourceId (value >= 0).
            //       The resourceId does not represent the order in the resource tree.
            // parentId is the parent of the asset. If parentId == 0, the resource is added to the top-level.
            // The name of the resource is identified by means of resourceName
            // An optional icon can be provided; the iconName is the name of the imagefile
            // If isAsset is false, the resource is a toplevel group or a subgroup
            void addResource (int resourceId, int parentId, const QString& resourceName, const QString& iconName, bool isAsset = false);

            // Add a resource to the resource tree, but automatically determine the resourceId (and return it)
            int addResource (int parentId, const QString& resourceName, const QString& iconName, bool isAsset = false);

            // Returns a list of all resources in the resource tree
            QVector<QtResourceInfo*>& getResources (void);

            // Delete a resource from the resource tree. If the resource - identified by means of resourceId (value >= 0) - has
            // child items, the underlying childs are also deleted
            void deleteResource (int resourceId);

            // Delete a resource - identified by resourceName - from the resource tree. The first occurence of
            // 'resourceName' is deleted
            //void deleteResource (const QString& resourceName);

            // Move a resource - identified by means of resourceId - from the resource tree to another parent -
            // identified by means of parentId. Both resourceId and parentId must exist, of course.
            void moveResource (int resourceId, int parentId);

            // Select a resource in the resource tree
            void selectResource (int resourceId);

            // Return the currently selected resource
            int getSelectedResource (void);

            // Return the first resource of a parent. If resourceId == 0, the first top-level resource is returned
            int getFirstInParent (int parentId);

            // Return true if the given resourceId is the first of a parentId
            bool QtResourceTreeWidget::isFirstInParent (int resourceId, int parentId);

            // Return the last resource of a parent.
            int getLastInParent (int parentId);

            // Return true if the given resourceId is the last of a parentId
            bool isLastInParent (int resourceId, int parentId);

            // Return the previous resource (as an int). If 'resourceId' is the first of a parent, the parent itself is returned.
            // If 'resourceId' is the first resource of the whole resource tree, 0 is returned.
            int getPrevious (int resourceId);

            // Return the next resource (as an int). If 'resourceId' is the last of a parent, the next parent is returned.
            // If 'resourceId' is the last resource of the whole resource tree, 0 is returned.
            int getNext (int resourceId);

            // Return a list of child resources of the resource, identifed by means of parentId.
            // If the resource has not childs, the list is empty
            QVector<int> getChildIdVector (int parentId);

            // Expand the tree under resourceId
            void expand (int resourceId);

            // Expand the complete tree (resursive)
            void expandAll (void);

            // Collapse the tree under resourceId
            void collapse (int resourceId);

            // Collapse the complete tree, so only the top-level resources are displayed
            void collapseAll (void);

            // Return a pointer to QTreeWidgetItem, based on a resourceId
            QTreeWidgetItem* getResourceItem(int resourceId);

            // Return the resourceId of a QTreeWidgetItem
            int getResourceIdFromItem (QTreeWidgetItem* item);

            // Return the parentId of a QTreeWidgetItem
            int getParentIdFromItem (QTreeWidgetItem* item);

            // Return the resourceId of the toplevel parent of a QTreeWidgetItem
            int getToplevelParentIdFromItem (QTreeWidgetItem* item);

            // Return the resourceId of the toplevel parent of a child resourceId
            int getToplevelParentId (int resourceId);

            // Return the QTreeWidgetItem* of the toplevel parent of a QTreeWidgetItem
            QTreeWidgetItem* getToplevelParentItemFromItem (QTreeWidgetItem* item);

            // Return the parentId of a resourceId
            int getParentId (int resourceId);

            // Return the iconName of a QTreeWidgetItem
            const QString& getIconNameFromItem (QTreeWidgetItem* item);

            // Return the resource name of a QTreeWidgetItem
            const QString& getResourceNameFromItem(QTreeWidgetItem* item);
            const QString& getResourceName(int resourceId);

            // Return the type Name of a QTreeWidgetItem. It returns:
            // 0                                         : type is undetermined
            // TOOL_RESOURCETREE_KEY_TYPE_TOPLEVEL_GROUP : type is toplevel group
            // TOOL_RESOURCETREE_KEY_TYPE_GROUP          : type is a subgroup
            // TOOL_RESOURCETREE_KEY_TYPE_ASSET          : type is an asset
            int getTypeFromItem (QTreeWidgetItem* item);
            int getTypeFromResourceId (int resourceId);

            // Return true if the item is a toplevel group
            bool isItemToplevelGroup(QTreeWidgetItem* item);

            // Return true if the resourceId is a toplevel group
            bool isResourceToplevelGroup(int resourceId);

            // Return true if the item is a subgroup
            bool isItemSubGroup(QTreeWidgetItem* item);

            // Return true if the resourceId is a subgroup
            bool isResourceSubGroup(int resourceId);

            // Return true if the item is a an asset
            bool isItemAsset(QTreeWidgetItem* item);

            // Return true if the resourceId is a an asset
            bool isResourceAsset(int resourceId);

            // Generate an id with the highest value of both the resources in the resource tree and
            // the registered resources
            int generateUniqueResourceId(void);

            // Returns true if all the child items are hidden
            bool allChildrenHidden(int parentId);

        public slots:
            // Activated when a contextmenu item is selected
            void contextMenuItemSelected(QAction* action);

            // Called when the search clearbutton is pressed
            void clearSearchLine(void);

            // Called when the search string changes
            void searchLineTextChanged(QString text);

        signals:
            // Emitted when a resource is added to the resource tree
            void resourceAdded (int resourceId);

            // Emitted when a resource is deleted from the resource tree
            void resourceDeleted (int resourceId);

            // Emitted when a resource is selected
            void resourceSelected (int resourceId);

            // Emitted when a resource is imported
            void resourceImported (int resourceId);

            // Emitted when a resource is moved
            void resourceMoved (int resourceId);

            // Emitted when a resource is expanded
            void resourceExpanded (int resourceId);

            // Emitted when a resource is collapsed
            void resourceCollapsed (int resourceId);

        protected:
            QtResourceInfo* getRegisteredResourceInfo (int resourceId);
            int getDepth(int resourceId); // Depth in the tree
            void buildContextMenu(void);
            void enableContextMenuItemsForSelectedResource(void);
            void enableContextMenuItem(const QString& menuItemText, bool enabled);
            QAction* getContextMenuAction(const QString& menuItemText);
            void mouseClickHandler(QMouseEvent* event);
            void dragMoveHandler(QObject* object, QEvent* event);
            void dropHandler(QObject* object, QEvent* event);
            void resetSearch(void);
            void findAndShowItems(const QString& searchPattern);
            void hideParentIfChildrenAreHidden(int parentId);

        private:
            void clearRegisteredResources (void);
            void clearResourceInfoVec (void);
            bool mContextMenuEnabled;
            bool mCreateTopLevelGroupContextMenuItemEnabled;
            bool mTopLevelGroupItemEditable;
            bool mDeleteTopLevelGroupEnabled;
            bool mCreateSubGroupContextMenuItemEnabled;
            bool mInheritSubGroupIconFromParent; // If true, no submenu / if false, a submenu with icons is displayed
            bool mCreateAssetContextMenuItemEnabled;
            bool mImportAssetContextMenuItemEnabled;
            bool mDeleteResourceContextMenuItemEnabled;
            int mMaxDepth;
            QString mIconDir;
            Magus::QtTreeWidget* mResourceTree;
            QVector<int> mChildIdVector;
            QVector<QtResourceInfo*> mRegisteredResources;
            QVector<QtResourceInfo*> mResourceInfoVec;
            QString mTempString;
            QMenu* mContextMenu;
            QMenu* mToplevelGroupSubMenu;
            QMenu* mSubGroupSubMenu;
            QHBoxLayout* mSearchLayout;
            QLineEdit* mSearchLine;
            QLabel* mSearchLabel;
            QPushButton* mSearchClearButton;
    };
}

#endif
