/*
Copyright (C) 2012-2016 Teddy Michel

This file is part of TMediaPlayer.

TMediaPlayer is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TMediaPlayer is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TMediaPlayer. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FILE_C_DIALOG_LAST_PLAYS
#define FILE_C_DIALOG_LAST_PLAYS

#include <QDialog>
#include "ui_DialogLastPlays.h"


class CMainWindow;
class QStandardItemModel;


/**
 * Boite de dialogue affichant la liste des dernières lectures.
 */

class CDialogLastPlays : public QDialog
{
    Q_OBJECT

public:

    explicit CDialogLastPlays(CMainWindow * mainWindow);
    virtual ~CDialogLastPlays();
    
signals:

    void closed();

protected slots:

    void changeMaxPlays(int maxPlays);
    void resetList();

protected:

    void closeEvent(QCloseEvent * event);

private:

    Ui::DialogLastPlays * m_uiWidget;
    CMainWindow * m_mainWindow;
    QStandardItemModel * m_model;
};

#endif // FILE_C_DIALOG_LAST_PLAYS
