#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using std::fixed;

// Définition des constantes du programme selon l'énoncé
#define NB_EMPLOYEES 50
#define HOURLY_RATE 17
#define SMOKING_TIME 5
#define WORK_DAY_PER_WEEK 5
#define WORK_WEEK_PER_MONTH 4

// Definition d'une structure pour les statistiques
struct stats {
  float coutJournalier;
  float coutHebdomadaire;
  float coutMensuel;
  float coutAnnuel;
  float heuresPerduJournalier;
  float heuresPerduHebdomadaire;
  float heuresPerduMensuel;
  float heuresPerduAnnuel;
};

/*
** Cette fonction affiche les statistiques passées en paramètre.
*/
static void displayStats(const struct stats& stats){
  cout << std::setfill('-') << setw(56) << "" << endl;
  cout << "| Periode  | Temps perdu (heures) | Cout correspondant |" << endl;
  cout << std::setfill('-') << setw(56) << "" << endl;
  cout << std::setfill(' ');
  cout << "| Jour     | " << setw(20) << setprecision(2) << fixed << stats.heuresPerduJournalier << " | " << setw(11) <<  "$" << stats.coutJournalier << "  |" << endl;
  cout << "| Semaine  | " << setw(20) << setprecision(2) << fixed << stats.heuresPerduHebdomadaire << " | " << setw(11) <<  "$" << stats.coutHebdomadaire  << "  |" << endl;
  cout << "| Mois     | " << setw(20) << setprecision(2) << fixed << stats.heuresPerduMensuel << " | " << setw(11) <<  "$" << stats.coutMensuel  << " |" << endl;
  cout << "| Annee    | " << setw(20) << setprecision(2) << fixed << stats.heuresPerduAnnuel << " | " << setw(11) <<  "$" << stats.coutAnnuel  << " |" << endl;
  cout << std::setfill('-') << setw(56) << "" << endl;
}

int main(void){
  struct stats stats;

  stats.heuresPerduJournalier = static_cast<float>(NB_EMPLOYEES * SMOKING_TIME) / 60;
  stats.heuresPerduHebdomadaire = stats.heuresPerduJournalier * WORK_DAY_PER_WEEK;
  stats.heuresPerduMensuel = stats.heuresPerduHebdomadaire * WORK_WEEK_PER_MONTH;
  stats.heuresPerduAnnuel = stats.heuresPerduMensuel * 12;
  stats.coutJournalier = stats.heuresPerduJournalier * HOURLY_RATE;
  stats.coutHebdomadaire = stats.heuresPerduHebdomadaire * HOURLY_RATE;
  stats.coutMensuel = stats.heuresPerduMensuel * HOURLY_RATE;
  stats.coutAnnuel = stats.heuresPerduAnnuel * HOURLY_RATE;

  displayStats(stats);
  return EXIT_SUCCESS;
}
