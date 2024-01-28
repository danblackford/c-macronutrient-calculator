#include <iostream>
#include <iomanip>
using namespace std;

//FUNCTION DECLARATIONS
char getMF();
void menu(void);
void menuGoals(void);
int getAge();
int getGoalChoice(int upperRange);
int getActivityLevel(int upperRange);
double getHeight();
double getWeight();
double calcActivityLevel(int activityLevel);
double calcMaleBMR(double userHeight, double userWeight, int userAge);
double calcFemaleBMR(double userHeight, double userWeight, int userAge);
double calcMaleCalories(double maleBMR, double calcActivity);
double calcFemaleCalories(double femaleBMR, double calcActivity);
double calcProtein(double goalCals);
double calcCarbs(double goalCals);
double calcFats(double goalCals);
double gramsOfFat(double userFat, double caloriesFat);
double gramsOfProtein(double userProtein, double caloriesProtein);
double gramsOfCarbs(double userCarbs, double caloriesCarbs);
double goalCalories(double userCalories, int goalChoice);

const double caloriesFat = 9;
const double caloriesProtein = 4;
const double caloriesCarbs = 4;

int main() {

  char getGender = ' ';
  int userAge = 0;
  int goalChoice = 0;
  int activityLevel = 0;
  double userHeight = 0.0;
  double userWeight = 0.0;
  double goalCals = 0.0;
  double calcActivity = 0.0;
  double maleBMR = 0.0;
  double femaleBMR = 0.0;
  double userBMR = 0.0;
  double userCalories = 0.0;
  double maleCalories = 0.0;
  double femaleCalories = 0.0;
  double userProtein = 0.0;
  double userCarbs = 0.0;
  double userFats = 0.0;
  double userFatCals = 0.0;
  double userProteinCals = 0.0;
  double userCarbsCals = 0.0;
  

  cout << fixed << setprecision(3);

//INPUT
  userHeight = getHeight();
  userWeight = getWeight();
  userAge = getAge();

//GET GENDER
  cout << "What is your gender? (m/f): ";
  getGender = getMF();

//WHILE LOOP FOR MALE
  while (getGender == 'm')
    {
      maleBMR = calcMaleBMR(userHeight, userWeight, userAge);
    

//MENU
      menu();
      activityLevel = getActivityLevel(6);
      calcActivity = calcActivityLevel(activityLevel);
      userBMR = maleBMR;
      maleCalories = calcMaleCalories(maleBMR, calcActivity);
      userCalories = maleCalories;
      menuGoals();
      goalChoice = getGoalChoice(5);
      goalCals = goalCalories(userCalories, goalChoice);
      userProtein = calcProtein(goalCals);
      userProteinCals = gramsOfProtein(userProtein, caloriesProtein);
      userCarbs = calcCarbs(goalCals);
      userCarbsCals = gramsOfCarbs(userCarbs, caloriesCarbs);
      userFats = calcFats(goalCals);
      userFatCals = gramsOfFat(userFats, caloriesFat);


      cout << fixed << setprecision(0);
      cout                                                        << endl;
      cout << "DAILY CALORIC INTAKE:         " << goalCals        << endl;
      cout                                                        << endl;
      cout << "DAILY CALORIES FROM PROTEIN:  " << userProtein     << endl;
      cout << "DAILY CALORIES FROM CARBS:    " << userCarbs       << endl;
      cout << "DAILY CALORIES FROM FAT:      " << userFats        << endl;
      cout << endl;
      cout << "DAILY GRAMS OF PROTEIN:       " << userProteinCals << endl;
      cout << "DAILY GRAMS OF CARBS:         " << userCarbsCals   << endl;
      cout << "DAILY GRAMS OF FAT:           " << userFatCals     << endl;

      break;
    }

//WHILE LOOP FOR FEMALE
  while (getGender == 'f')
    {
      femaleBMR = calcFemaleBMR(userHeight, userWeight, userAge);


      //MENU
      menu();
      activityLevel = getActivityLevel(6);
      calcActivity = calcActivityLevel(activityLevel);
      userBMR = femaleBMR;
      femaleCalories = calcFemaleCalories(femaleBMR, calcActivity);
      userCalories = femaleCalories;
      menuGoals();
      goalChoice = getGoalChoice(5);
      goalCals = goalCalories(userCalories, goalChoice);
      userProtein = calcProtein(goalCals);
      userProteinCals = gramsOfProtein(userProtein, caloriesProtein);
      userCarbs = calcCarbs(goalCals);
      userCarbsCals = gramsOfCarbs(userCarbs, caloriesCarbs);
      userFats = calcFats(goalCals);
      userFatCals = gramsOfFat(userFats, caloriesFat);


      cout << fixed << setprecision(0);
      cout                                                        << endl;
      cout << "DAILY CALORIC INTAKE:         " << goalCals        << endl;
      cout                                                        << endl;
      cout << "DAILY CALORIES FROM PROTEIN:  " << userProtein     << endl;
      cout << "DAILY CALORIES FROM CARBS:    " << userCarbs       << endl;
      cout << "DAILY CALORIES FROM FAT:      " << userFats        << endl;
      cout << endl;
      cout << "DAILY GRAMS OF CARBS:         " << userCarbsCals   << endl;
      cout << "DAILY GRAMS OF PROTEIN:       " << userProteinCals << endl;
      cout << "DAILY GRAMS OF FAT:           " << userFatCals     << endl;

      break;
    }
}

//END MAIN


//FUNCTIONS

void menu(void)
{
  cout << endl;
  cout << "1. Little or no exercise"                                              << endl;
  cout << "2. Lightly active (exercise 1-3 days a week)"                          << endl;
  cout << "3. Moderately active (exercise 4-5 times a week)"                      << endl;
  cout << "4. Very active (intense exercise 6-7 times a week)"                    << endl;
  cout << "5. Extremely active (very intense exercise daily & physical job)"      << endl;
  cout << endl;
  return;
}
//END MENU FUNCTION


void menuGoals(void)
{
  cout << endl;
  cout << "1. Quickly lose weight (1-2 lbs a week)" << endl;
  cout << "2. Lose weight (0.5 lbs a week)"         << endl;
  cout << "3. Maintain weight"                      << endl;
  cout << "4. Gain weight (0.5 lbs a week)"         << endl;
  cout << "5. Quickly gain weight (1-2 lbs a week)" << endl;
  cout << endl;
  return;
}
//END MENUGOALS FUNCTION


int getActivityLevel(int upperRange)
{
  int activityLevel = 0;

  do{
      cout << "Enter your activity level: ";
      cin  >> activityLevel;
      if(activityLevel < 1 || activityLevel > 5)
      cout << "***ERROR - Enter a number between 1-5***" << endl;
    }while (activityLevel < 1 || activityLevel > 5);

    return activityLevel;
}
//END GETACTIVITYLEVEL FUNCTION


int getGoalChoice(int upperRange)
{
  int goalChoice = 0;

  do{
      cout << "Enter your goal: ";
      cin  >> goalChoice;
      if(goalChoice < 1 || goalChoice > 5)
      cout << "***ERROR - Enter a number between 1-5***" << endl;
    }while (goalChoice < 1 || goalChoice > 5);

    return goalChoice;
}
//END GETGOALCHOICE FUNCTION


double getHeight() {
  double userHeight = 0.0;
    do
    {     
      cout << "Enter your height (inches): ";
      cin >> userHeight; 
      if(userHeight <= 0)
      cout << "***ERROR - Enter a number greater than zero***" << endl;
    }while(userHeight <= 0);

    return userHeight;
  }
//END GETHEIGHT FUNCTION


double getWeight() {
double userWeight = 0.0;
  do
  {     
    cout << "Enter your weight (lbs): ";
    cin >> userWeight; 
    if(userWeight <= 0)
    cout << "***ERROR - Enter a number greater than zero***" << endl;
  }while(userWeight <= 0);

  return userWeight;
}
//END GETWEIGHT FUNCTION


int getAge()
{
  double userAge = 0.0;

  do
  {     
    cout << "Enter your age: ";
    cin >> userAge; 
    if(userAge <= 0)
    cout << "***ERROR - Enter a number greater than zero***" << endl;
  }while(userAge <= 0);

  return userAge;
}
//END GETAGE FUNCTION


char getMF()
{
    char mf;
    do{
      cin >> mf;                               
      mf = tolower(mf);
      if(mf != 'm' && mf != 'f')
        cout << " ***** Please enter m or f *****" << endl << "What is your gender? (m/f)" << endl;
    }while(mf != 'm' && mf != 'f');

  return mf;
}
//END GETMF FUNCTION


double calcMaleBMR(double userHeight, double userWeight, int userAge) {
  double maleBMR = 0.0;

  maleBMR = 66 + (6.23 * userWeight) + (12.7 * userHeight) - (6.8 * userAge);

  return maleBMR;
}
//END CALCMALEBMR FUNCTION


double calcFemaleBMR(double userHeight, double userWeight, int userAge) {
  double femaleBMR = 0.0;

  femaleBMR = 655 + (4.35 * userWeight) + (4.7 * userHeight) - (4.7 * userAge);

  return femaleBMR;
}
//END CALCFEMALEBMR FUNCTION


double calcActivityLevel(int activityLevel) {
  double calcActivity = 0.0;

  if (activityLevel == 1)
  {
    calcActivity = 1.2;
  }
  else if (activityLevel == 2)
  {
    calcActivity = 1.375;
  }
  else if (activityLevel == 3)
  {
    calcActivity = 1.55;
  }
  else if(activityLevel == 4)
  {
    calcActivity = 1.725;
  }
  else if (activityLevel == 5)
  {
    calcActivity = 1.9;
  }

  return calcActivity;
}
//END CALCACTIVITYLEVEL FUNCTION


double goalCalories(double userCalories, int goalChoice)
{
  double goalCals = 0.0;

  if (goalChoice == 1)
  {
    goalCals = userCalories - 500.00;
  }
  else if(goalChoice == 2)
  {
    goalCals = userCalories - 250;
  }
  else if (goalChoice == 3)
  {
    goalCals = userCalories;
  }
  else if (goalChoice == 4)
  {
    goalCals = userCalories + 250;
  }
  else if (goalChoice == 5)
  {
    goalCals = userCalories + 500;
  }
  
  return goalCals;
}
//END GOALCALORIES FUNCTION


double calcMaleCalories(double maleBMR, double calcActivity)
{
  double maleCalories = 0.0;

  maleCalories = maleBMR * calcActivity;

  return maleCalories;
}
//END CALCMALECALORIES FUNCTION


double calcFemaleCalories(double femaleBMR, double calcActivity)
{
  double femaleCalories = 0.0;

  femaleCalories = femaleBMR * calcActivity;

  return femaleCalories;
}
//END CALCFEMALECALORIES FUNCTION


double calcProtein(double goalCals)
{
  double userProtein = 0.0;
  userProtein = goalCals * 0.25;

  return userProtein;
}
//END CALCPROTEIN FUNCTION


double calcCarbs(double goalCals)
{
  double userCarbs = 0.0;
  userCarbs = goalCals * 0.50;

  return userCarbs;
}
//END CALCCARBS FUNCTION


double calcFats(double goalCals)
{
  double userFats = 0.0;
  userFats = goalCals * 0.25;

  return userFats;
}
//END CALCFATS FUNCTION


double gramsOfFat(double userFats, const double caloriesFat)
{
  double userFatCals = 0.0;

  userFatCals = userFats / caloriesFat;

  return userFatCals;
}
//END CALORIESFROMFAT FUNCTION


double gramsOfProtein(double userProtein, const double caloriesProtein)
{
  double userProteinCals = 0.0;

  userProteinCals = userProtein / caloriesProtein;

  return userProteinCals;
}
//END CALORIESFROMPROTEIN FUNCTION


double gramsOfCarbs(double userCarbs, const double caloriesCarbs)
{
  double userCarbsCals = 0.0;

  userCarbsCals = userCarbs / caloriesCarbs;
    
  return userCarbsCals;
}
//END CALORIESFROMCARBS FUNCTION
