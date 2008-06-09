/* This file is part of the KDE project
   Copyright 2007 Will Stephenson <wstephenson@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License or (at your option) version 3 or any later version
   accepted by the membership of KDE e.V. (or its successor approved
   by the membership of KDE e.V.), which shall act as a proxy 
   defined in Section 14 of version 3 of the license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KCMENUITEM_H
#define KCMENUITEM_H

#include <QList>
#include <QString>
#include <KCModuleInfo>
#include <KService>  // for KService::Ptr

/**
 * A menu consists of menu items.  An item is either another menu or a module.
 */
class MenuItem {
public:
    MenuItem( bool isMenu, MenuItem * parent );
    ~MenuItem();
    void sortChildrenByWeight();

    MenuItem * grandChildAt( int index );
    MenuItem * parent;
    QList< MenuItem * > children;
    bool menu;
    QString name;
    QString caption;
    KService::Ptr service;
    KCModuleInfo item;
};

#endif
