#pragma once
#include <QObject>

#include "../SbieError.h"

class CIniSection: public QObject
{
	Q_OBJECT
public:
	CIniSection(const QString& Section, class CSbieAPI* pAPI, QObject* parent = 0);
	virtual ~CIniSection();

	virtual SB_STATUS SetText(const QString& Setting, const QString& Value);
	virtual SB_STATUS SetNum(const QString& Setting, int Value);
	virtual SB_STATUS SetNum64(const QString& Setting, __int64 Value);
	virtual SB_STATUS SetBool(const QString& Setting, bool Value);

	virtual QString GetText(const QString& Setting, const QString& Default = QString()) const;
	virtual int GetNum(const QString& Setting, int Default = 0) const;
	virtual __int64 GetNum64(const QString& Setting, __int64 Default = 0) const;
	virtual bool GetBool(const QString& Setting, bool Default = false) const;

	virtual SB_STATUS InsertText(const QString& Setting, const QString& Value);
	virtual SB_STATUS AppendText(const QString& Setting, const QString& Value);

	virtual SB_STATUS DelValue(const QString& Setting, const QString& Value);

protected:

	QString				m_Name;
	class CSbieAPI*		m_pAPI;
};