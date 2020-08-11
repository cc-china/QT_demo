#include<QList>
#include <QVariant>

struct DefaultItemModel{
    int id;
    QString name;
    bool enableChange;
};
Q_DECLARE_METATYPE(DefaultItemModel);

struct FieldItemModel{
    int id;
    QString name;
    bool enableChange;
    QList<DefaultItemModel> mDefaultList;
};
Q_DECLARE_METATYPE(FieldItemModel);
typedef QList<DefaultItemModel> mDefaultItemModelList;

struct ControlItemModel{
    int id;
    QString name;
    bool enableChange;
    QList<FieldItemModel> mFieldList;
};
Q_DECLARE_METATYPE(ControlItemModel);
typedef QList<FieldItemModel> mFieldItemModelList;

struct FeatureItemModel{
    int id;
    QString name;
    bool enableChange;
    QList<ControlItemModel> mControlList;
};
Q_DECLARE_METATYPE(FeatureItemModel);
typedef QList<ControlItemModel> mControlItemModelList;


