#include "bridge.h"
#include <QMessageBox>

bridge* bridge::instance()
{
	static bridge s_obj;
	return &s_obj;
}

bridge::bridge(QObject *parent) : QObject(parent)
{
}

void bridge::showMsgBox()
{
	QMessageBox::aboutQt(0, tr("Qt"));
}
void bridge::showMsgBoxx()
{
	QMessageBox::aboutQt(0, tr("Qt"));
}

