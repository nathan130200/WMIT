/*
	Copyright 2010 Warzone 2100 Project

	This file is part of WMIT.

	WMIT is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	WMIT is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with WMIT.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <QDialog>
#include <QMap>

#include "WZM.hpp"

class QListWidgetItem;

namespace Ui {
    class TextureDialog;
}

class TextureDialog : public QDialog
{
	Q_OBJECT

public:
	explicit TextureDialog(QWidget *parent = 0);
	~TextureDialog();

	void createTextureIcons(const QString& workdir, const QString& modelname);
	void getTexturesFilepath(QMap<wzm_texture_type_t, QString>& files) const;

public slots:
	void setSearchDirs(const QStringList& list);
	void setTexturesMap(const QMap<wzm_texture_type_t, QString>& texnames);

private slots:
	void iconDoubleClicked(QListWidgetItem *icon);

private:
	Ui::TextureDialog *ui;

	QString m_model_filepath;
	QMap<wzm_texture_type_t, QString> m_texnames; // actual data read from model

	QMap<wzm_texture_type_t, QListWidgetItem*> m_icons;
	QStringList m_predefined_textures; // for predefined searches
	QString m_work_dir; // for open dialogs

	void scanForTexturesInDirs(const QStringList& dirs);
	QString findTexture(wzm_texture_type_t type) const;
	QString selectTextureFile();
	void addTextureIcon(wzm_texture_type_t type);
};