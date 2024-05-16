#include "SearchFriendWidget.h"
#include "ui_searchfriendwidget.h"

SearchFriendWidget::SearchFriendWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchFriendWidget),
    m_resultListVLayout(nullptr),
    m_resultUserIds(QVector<quint32>())
{
    ui->setupUi(this);

    // 给搜索框添加搜索图标
    QAction* search_action = new QAction(this);
    QIcon search_icon(":/qqicons/qrc/search.svg");
    search_action->setIcon(search_icon);
    ui->edtSearch->addAction(search_action, QLineEdit::LeadingPosition);
    // 窗口图标
    this->setWindowIcon(QIcon(":/qqicons/qrc/search.svg"));
    // 默认显示第1页：用户还没有进行搜索
    ui->stkwResultShow->setCurrentIndex(0);
    // 给搜索结果栏添加垂直布局
    m_resultListVLayout = new QVBoxLayout(ui->wSearchResult);
    m_resultListVLayout->setSpacing(0);
    m_resultListVLayout->setContentsMargins(0, 0, 0, 0);
    QSpacerItem* infoListVSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_resultListVLayout->addItem(infoListVSpacer);
    // 信号与槽
    connect(ui->edtSearch, &QLineEdit::textChanged, this, &SearchFriendWidget::slot_edtSearch_textChanged);
    connect(this, &SearchFriendWidget::signal_searchTextChanged, AssembleBytes::getInstance(), &AssembleBytes::slot_asmSearchUser);

    this->setWindowFlags(Qt::Window);
}

SearchFriendWidget::~SearchFriendWidget()
{
    delete ui;
}

QVector<quint32> SearchFriendWidget::m_getResultUserIds() const
{
    return m_resultUserIds;
}

void SearchFriendWidget::slot_edtSearch_textChanged(const QString &text)
{
    emit signal_searchTextChanged(Config::getInstance()->m_getLoginClientId(), text);
    if(text.isEmpty())
    {
        ui->stkwResultShow->setCurrentIndex(0);
    }
    else
    {
        ui->stkwResultShow->setCurrentIndex(1);
    }
}

void SearchFriendWidget::slot_updateSearchRecords(const QString search_text, QVector<sttFriendInfo> update_records)
{
    if(ui->edtSearch->text() != search_text)
        return;
    if(search_text.isEmpty())
        return;
    m_resultUserIds.clear();
    m_resultUserIds.resize(update_records.size());

    // 先清除掉布局中所有的控件
    QLayoutItem* cur_child;
    while((cur_child = m_resultListVLayout->takeAt(0)) != nullptr)
    {
        QWidget* cur_widget = cur_child->widget();
        if(cur_widget)
        {
            cur_widget->setParent(nullptr);
            cur_widget->deleteLater();
            cur_widget = nullptr;
        }
        delete cur_child;
        cur_child = nullptr;
    }

    // 然后添加一个弹簧
    QSpacerItem* infoListVSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_resultListVLayout->addItem(infoListVSpacer);

    // 最后把搜索结果显示到界面上
    if(update_records.isEmpty())
    {
        ui->stkwResultShow->setCurrentIndex(2);
    }
    else
    {
        ui->stkwResultShow->setCurrentIndex(1);
        int i = 0;
        for(sttFriendInfo cur_user_info : update_records)
        {
            SearchUserLittleBox* cur_user_box = new SearchUserLittleBox(this, cur_user_info, search_text);
            cur_user_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            int _insert_pos = m_resultListVLayout->count() - 1;
            m_resultListVLayout->insertWidget(_insert_pos, cur_user_box);
            connect(cur_user_box, &SearchUserLittleBox::signal_sendMsgToFriend, [this](const quint32 friend_id){
                emit signal_sendMsgToFriend(friend_id);
            });
            m_resultUserIds[i++] = cur_user_info.id;
        }
    }
}

void SearchFriendWidget::m_checkSetUserHead(const quint32 &user_id, const QString &head_path)
{
    if(!m_resultUserIds.contains(user_id))
        return;
    if(head_path.isEmpty() || !QFile(head_path).exists())
        return;

    for(int i=0; i<m_resultListVLayout->count(); ++i)
    {
        QLayoutItem* cur_item = m_resultListVLayout->itemAt(i);
        if(cur_item)
        {
            SearchUserLittleBox* cur_result_box = qobject_cast<SearchUserLittleBox*>(cur_item->widget());
            if(cur_result_box)
            {
                quint32 _cur_client_id = cur_result_box->m_getFriendId();
                if(_cur_client_id == user_id)
                {
                    cur_result_box->m_setHeadPic(head_path);
                    break;
                }
            }
        }
    }
}
