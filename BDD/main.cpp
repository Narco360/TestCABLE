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
    if (!query.exec("CREATE TABLE IF NOT EXISTS Tests ("
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
        return 1;
    }

    // Exemple d'insertion de données
  /*  if (!query.exec("INSERT INTO Test (ID_Test, ID_Produit, Produit, Resultat_Test, Testeur, Client, Date, Heure, Date_Code) VALUES (1, 'DN97CNRC', 'USB RS232', '00ok', 'LM', 'SCHILLER', '01/03/2024', '16:56', '2403')")) {
        qDebug() << "Erreur lors de l'insertion de données:" << query.lastError().text();
        return 1;
    }*/

  //transaction
    QSqlQuery query;
    bool success = true;

    for (int i = 0; i < nombreDeDonnees; ++i) {
        query.prepare("INSERT INTO Tests (ID_Test, ID_Produit, Produit, Resultat_Test, Testeur, Client, Date, Heure, Date_Code) VALUES (1, 'DN97CNRC', 'USB RS232', '00ok', 'LM', 'SCHILLER', '01/03/2024', '16:56', '2403')");
        query.bindValue("1", valeur1[i]); // Assurez-vous d'avoir les données dans un tableau ou une structure similaire
        query.bindValue("DN97CNRC, valeur2[i]);
        query.bindValue("USB RS232", valeur3[i]);
        query.bindValue("00ok", valeur4[i]);
        query.bindValue("LM", valeur5[i]);
        query.bindValue("SCHILLER", valeur6[i]);
        query.bindValue("01/03/2024", valeur7[i]);
        query.bindValue("16:56", valeur8[i]);
        query.bindValue("2403", valeur9[i]);


        if (!query.exec()) {
            qDebug() << "Échec de l'insertion :" << query.lastError();
            success = false;
            break; // Sortie anticipée de la boucle en cas d'erreur
        }
    }

    // Fermeture de la base de données
    db.close();

    qDebug() << "Base de données 'testcable' créée avec succès.";

    return a.exec();
}
