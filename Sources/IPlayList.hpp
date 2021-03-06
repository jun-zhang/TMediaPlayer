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

#ifndef FILE_I_PLAYLIST_HPP_
#define FILE_I_PLAYLIST_HPP_

#include <QString>
#include "CMediaTableView.hpp"


class CFolder;


/**
 * Classe de base des listes de lecture.
 * Gère les paramètres communs aux listes : le nom, le dossier, et la position dans le dossier.
 */

class IPlayList : public CMediaTableView
{
    Q_OBJECT

    friend class CMainWindow;
    friend class CFolder;
    friend class CLibraryView;
    friend class CLibraryModel;

public:

    explicit IPlayList(CMainWindow * mainWindow, const QString& name = QString());
    virtual ~IPlayList() = 0;

    inline QString getName() const;
    inline CFolder * getFolder() const;
    bool hasAncestor(CFolder * folder) const;
    virtual bool isModified() const;

public slots:

    void setName(const QString& name);
    void setFolder(CFolder * folder);

signals:

    /**
     * Signal émis lorsque le nom de la liste change.
     * Utilisez la méthode sender() dans le slot pour connaitre la liste de lecture.
     *
     * \param oldName Ancien nom de la liste.
     * \param newName Nouveau nom de la liste.
     */

    void nameChanged(const QString& oldName, const QString& newName);

    /**
     * Signal émis lorsque le dossier contenant la liste change.
     * Utilisez la méthode sender() dans le slot pour connaitre la liste de lecture.
     *
     * \param oldFolder Pointeur sur l'ancien dossier.
     * \param newFolder Pointeur sur le nouveau dossier.
     */

    void folderChanged(CFolder * oldFolder, CFolder * newFolder);

    /**
     * Signal émis lorsque le contenu de la liste change.
     * Utilisez la méthode sender() dans le slot pour connaitre la liste de lecture.
     */

    void listModified();

protected:

    virtual bool updateDatabase();
    virtual void removeFromDatabase();

    QString m_name;            ///< Nom de la liste de lecture.
  //int m_position;            ///< Position de la liste dans le dossier.

private:

    CFolder * m_folder;        ///< Dossier contenant la liste.
    bool m_isPlayListModified; ///< Indique si la liste de lecture a été modifiée.
    bool m_folderChanging;     ///< Indique si le dossier est en train d'être changé.
  //QModelIndex m_index;       ///< Index de la liste dans la vue.
};


/**
 * Retourne le nom de la liste de lecture.
 *
 * \return Nom de la liste.
 */

inline QString IPlayList::getName() const
{
    return m_name;
}


/**
 * Retourne le dossier contenant la liste de lecture.
 *
 * \return Pointeur sur le dossier, ou nullptr si la liste est à la racine.
 */

inline CFolder * IPlayList::getFolder() const
{
    return m_folder;
}

#endif // FILE_I_PLAYLIST_HPP_
