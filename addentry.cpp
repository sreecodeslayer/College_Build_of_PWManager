#include "addentry.h"
#include "ui_addentry.h"
#include <QListWidget>
#include <QString>
#include <QDebug>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "tinyaes.h"
#include <QMessageBox>
#include "myaccounts.h"
#define PRIVATE_KEY "729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E37011" //this must be replaced by master password


AddEntry::AddEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Entry");
    createConnection();
}

AddEntry::~AddEntry()
{
    delete ui;
}
/*QString AddEntry::decrypt(const QString &password)
{
    QString plain;
    QString encrypted = password.toStdString();
    // Hex decode symmetric key:
    HexDecoder decoder;
    decoder.Put( (byte *)PRIVATE_KEY,32*2 );
    decoder.MessageEnd();
    word64 size = decoder.MaxRetrievable();
    char *decodedKey = new char[size];
    decoder.Get((byte *)decodedKey, size);
    // Generate Cipher, Key, and CBC
    byte key[ AES::MAX_KEYLENGTH ], iv[ AES::BLOCKSIZE ];
    StringSource( reinterpret_cast<const char *>(decodedKey), true,
                  new HashFilter(*(new SHA256), new ArraySink(key, AES::MAX_KEYLENGTH)) );
    memset( iv, 0x00, AES::BLOCKSIZE );
    try {
        CBC_Mode<AES>::Decryption Decryptor
        ( key, sizeof(key), iv );
        StringSource( encrypted, true,
                      new HexDecoder(new StreamTransformationFilter( Decryptor,
                                     new StringSink( plain ) ) ) );
    }
    catch (Exception &e) { // ...
    }
    catch (...) { // ...
    }
    return QString::fromStdString(plain);
}

QString AddEntry::encrypt(const QString &password)
{
    string plain = password.toStdString();
    string ciphertext;
    // Hex decode symmetric key:
    HexDecoder decoder;
    decoder.Put( (byte *)PRIVATE_KEY, 32*2 );
    decoder.MessageEnd();
    word64 size = decoder.MaxRetrievable();
    char *decodedKey = new char[size];
    decoder.Get((byte *)decodedKey, size);
    // Generate Cipher, Key, and CBC
    byte key[ AES::MAX_KEYLENGTH ], iv[ AES::BLOCKSIZE ];
    StringSource( reinterpret_cast<const char *>(decodedKey), true,
                  new HashFilter(*(new SHA256), new ArraySink(key, AES::MAX_KEYLENGTH)) );
    memset( iv, 0x00, AES::BLOCKSIZE );
    CBC_Mode<AES>::Encryption Encryptor( key, sizeof(key), iv );
    StringSource( plain, true, new StreamTransformationFilter( Encryptor,
                  new HexEncoder(new StringSink( ciphertext ) ) ) );
    return QString::fromStdString(ciphertext);
}*/
bool AddEntry::createConnection()
{

    db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    //Setting the relative path
    db.setDatabaseName("../Lock-Up/Db/passwordmanager.sqlite");
    if(!db.open())
         {
             QMessageBox::information(0, "Connection Failed!", db.lastError().text(),QMessageBox::Ok, QMessageBox::NoButton);
         }
    else
        qDebug ()<<"Connected!"; // TEST
    return true;
}

QString listitem;
void AddEntry::on_Ok_Button_clicked()
{
    //Get the inputs
    acc_password = ui->add_password->text();
    QString acc_username = ui->add_username->text();
    QString acc_link = ui->add_link->text();

    qDebug() << acc_link << " "<< acc_password << " " << acc_username;

    QSqlQuery qry(db);
    qry.prepare("INSERT INTO useraccount (Username,Password,Link,AccType) VALUES(:usr,:pass,:l,:acc)");
    qry.bindValue(":usr",acc_username);
    qry.bindValue(":pass",encrPassword(acc_password)); //----> encryptPassword(acc_password)
    qry.bindValue(":l",acc_link);
    //qry.bindValue(":m","o1");
    qry.bindValue(":acc",listitem);
    qry.exec();
    MyAccounts *goback = new MyAccounts;
    goback->show();
    close();
}

void AddEntry::on_account_type_list_itemClicked(QListWidgetItem *item)
{
    listitem = ui->account_type_list->currentItem()->text();
    //qDebug()<<listitem;
}

void AddEntry::on_Cancel_Button_clicked()
{
    QMessageBox::StandardButton cancel;
    cancel = QMessageBox::question(this,"Cancel","Do you want to cancel the entry?",QMessageBox::Yes|QMessageBox::No);

    if(cancel == QMessageBox::Yes)
    {
        MyAccounts *goback = new MyAccounts;
        goback->show();
        close();
        db.close();
    }
}

//Encryption Codes
TinyAES pass;
QByteArray en_de_key = pass.HexStringToByte("729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E");//if changing, change in myaccounts.cpp as well

//actually is there a need to replace the key with MasterPassword?

QString AddEntry::encrPassword(QString acc_password)
{
    QByteArray encr_password = pass.HexStringToByte(acc_password);
    QByteArray encr_result;
    encr_result = pass.Encrypt(encr_password,en_de_key);

    qDebug()<<QString(encr_result)<< "Encrypted";
    decrPassword(encr_result);//just to test both function
    return encr_result;
}

QString AddEntry::decrPassword(QByteArray encr_password)
{
    QByteArray plain_text = pass.Decrypt(encr_password,en_de_key);
    QString actual_pass = plain_text.toHex();
    qDebug()<< QString(plain_text)<<" Decrypted & actuall pass = "<<actual_pass.toUtf8();

    return plain_text;
}

