#include <QCoreApplication>
#include <QtSql>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Création d'une connexion à une base de données SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/2BTS/TESTCABLE/BDD.db");

    // Ouverture de la base de données
    if (!db.open()) {
        qDebug() << "Erreur: Impossible d'ouvrir la base de données";
        return 1;
    }

   // Création d'une table
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS Test ("
                    "ID_Test INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "ID_Produit TEXT,"
                    "Produit TEXT,"
                    "Resultat_Test TEXT,"
                    "Testeur TEXT,"
                    "Client TEXT,"
                    "Date TEXT,"
                    "Heure TEXT,"
                    "Date_Code TEXT,"
                    "Tension REAL"
                    ")")) {

        qDebug() << "Erreur lors de la création de la table:" << query.lastError().text();
        return 2;
    }

    // Insertion de données
    if (!query.exec("INSERT INTO Test  (ID_Test,    ID_Produit,     Produit,      Resultat_Test,     Testeur,     Client,       Date,            Heure,     Date_Code)"
                    " VALUES           (9,          'DN97C021',    'USB RS485',   '00ok',            'FR',      'LLF',    '19/03/2024',    '10:49',    '2403')")) {
        qDebug() << "Erreur lors de l'insertion de données:" << query.lastError().text();
        return 3;
    }


    // Fermeture de la base de données
    db.close();

    qDebug() << "Base de données 'testcable' créée avec succès.";



          /*  // Création du message
            QMailMessage message;
            message.setSender(QMailAddress("ericbelouet@ebconnections.com"));
            message.addTo(QMailAddress("destinataire@example.com"));
            message.setSubject("BDD");
            message.setBody("Corps de l'email");

            // Configuration du transport
            QMailTransport smtpTransport;
            smtpTransport.setService("smtp.gmail.com"); // Serveur SMTP
            smtpTransport.setUsername("ericbelouet@ebconnections.com"); // Votre adresse e-mail
            smtpTransport.setPassword("votre_mot_de_passe"); // Votre mot de passe
            smtpTransport.connectToHost();

            // Envoi du message
            if (smtpTransport.sendMail(message)) {
                qDebug() << "E-mail envoyé avec succès.";
            } else {
                qDebug() << "Erreur lors de l'envoi de l'e-mail:" << smtpTransport.lastError();
                return 4;
            }*/
    return a.exec();
}
