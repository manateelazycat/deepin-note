/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2018 Deepin, Inc.
 *               2011 ~ 2018 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <DTabBar>
#include <QMenu>

DWIDGET_USE_NAMESPACE

class TabWidget : public DTabBar
{
    Q_OBJECT
    
    bool eventFilter(QObject *, QEvent *event);
    
public:
    TabWidget();
    
    QList<QString> tabFiles;
    
    QMimeData *createMimeDataFromTab(int index, const QStyleOptionTab &option) const;
    QPixmap createDragPixmapFromTab(int index, const QStyleOptionTab &option, QPoint *hotspot) const;
    bool canInsertFromMimeData(int index, const QMimeData *source) const;
    void insertFromMimeData(int index, const QMimeData *source);    
    void insertFromMimeDataOnDragEnter(int index, const QMimeData *source);
                           
    void setBackground(QString startColor, QString endColor);
    void setDNDColor(QString startColor, QString endColor);
    
signals:
    void closeTab(int index);
    void closeOtherTabs(int index);
    void closeFile(QString filepath);
    
public slots:
    void handleCloseOtherTabs();
    void handleCloseTab();
    void handleTabReleaseRequested();
    void handleDragActionChanged(Qt::DropAction action);
    void handleTabRemoved(int index);

private:
    QAction *closeOtherTabAction;
    QAction *closeTabAction;
    QMenu *menu;
    int rightClickTab;
    QString backgroundStartColor;
    QString backgroundEndColor;
    QString dndStartColor;
    QString dndEndColor;
};

#endif
