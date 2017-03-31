#ifndef ALLHEADERS_H
#define ALLHEADERS_H
//#define DB_NAME "arsmssv2"
#define DB_NAME "Correct_Database"
#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "password"

    //db.setDatabaseName("arsmssv2");
    //db.setUserName("root");
    //db.setPassword("password");



#include "dbconn.h"
#include "db_VisualParam.h"
#include "Signal.h"
#include "db_signal.h"
#include <QDateTime>
#include <QDate>
#include <QTime>
#include "CheckPointProperties.h"
#include "db_CheckPointProperties.h"
#include "CheckpointPropDialog.h"
#include "vec_signal.h"
#include "CheckpointMessages.h"
#include "VideoFrame.h"
#include "VisualParam.h"
#include "db_VideoFrame.h"
#include "LoginPassword.h"
#include "DbLoginPasswords.h"
#include "LoginDialog.h"
#include "ModelLoginPassword.h"
#include "TableEditDialog.h"
#include "ModelVisualParam.h"
#include "CheckPointEditDialog.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QHash>
#include "plot.h"
#include <memory>
#include "ModelArchivSignal.h"
#include "DelegatArchivSignal.h"



#endif // ALLHEADERS_H
