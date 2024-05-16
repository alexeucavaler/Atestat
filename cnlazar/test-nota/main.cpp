#include <iostream>
#include <string>
using namespace std;
int Guess;
int Total;
class intrebare {
private:
    string intrebare_text;
    string raspuns_1;
    string raspuns_2;
    string raspuns_3;
    string raspuns_4;
    int correct_raspuns;
    int intrebare_ccore;
 
public:
    // Setter Function
    void setValues(string, string,
                   string, string,
                   string, int, int);
 
    // Function to ask intrebares
    void askintrebare();
};

int main()
{
    
    cout << "\nApasa Enter ca sa incepi "<<endl;
    cin.get();

    intrebare q1;
    intrebare q2;
    intrebare q3;
    intrebare q4;
    intrebare q5;

    q1.setValues("intrebare : ", "raspuns 1",
                 "raspuns 2", "raspuns 3",
                 "raspuns 4", 3, 10);
    q2.setValues("intrebare : ", "raspuns 1",
                 "raspuns 2", "raspuns 3",
                 "raspuns 4", 3, 10);
    q3.setValues("intrebare : ", "raspuns 1",
                 "raspuns 2", "raspuns 3",
                 "raspuns 4", 3, 10);
    q4.setValues("intrebare : ", "raspuns 1",
                 "raspuns 2", "raspuns 3",
                 "raspuns 4", 3, 10);
    q5.setValues("intrebare : ", "raspuns 1",
                 "raspuns 2", "raspuns 3",
                 "raspuns 4", 3, 10);
    q1.askintrebare();
    q2.askintrebare();
    q3.askintrebare();
    q4.askintrebare();
    q5.askintrebare();
    cout << "Total scor = " << Total
         << "out of 100" << endl;
    // Display the results
    // If the player pass the quiz
    if (Total >= 70) {
        cout << "Congrats you passed the"
             << " quiz!" << endl;
    }
 
    // Otherwise
    else {
        cout << "Alas! You failed the quiz."
             << endl;
        cout << "Better luck next time."
             << endl;
    }
    return 0;
}
 
// Function to set the values of
// the intrebares
void intrebare::setValues(
    string q, string a1,
    string a2, string a3,
    string a4, int ca, int pa)
{
    intrebare_text = q;
    raspuns_1 = a1;
    raspuns_2 = a2;
    raspuns_3 = a3;
    raspuns_4 = a4;
    Correct_raspuns = ca;
    intrebare_scor = pa;
}
 
// Function to ask intrebares
void intrebare::askintrebare()
{
    cout << endl;
 
    // Print the intrebares
    cout << intrebare_text << endl;
    cout << "1. " << raspuns_1 << endl;
    cout << "2. " << raspuns_2 << endl;
    cout << "3. " << raspuns_3 << endl;
    cout << "4. " << raspuns_4 << endl;
    cout << endl;
 
    // Display the raspuns
    cout << "What is your raspuns?(in number)"
         << endl;
    cin >> Guess;
 
    // If the raspuns is correct
    if (Guess == Correct_raspuns) {
        cout << endl;
        cout << "Correct !" << endl;
 
        // Update the correct scor
        Total = Total + intrebare_scor;
        cout << "scor = " << intrebare_scor
             << " out of "
             << intrebare_scor
             << "!" << endl;
        cout << endl;
    }
 
    // Otherwise
    else {
        cout << endl;
        cout << "Wrong !" << endl;
        cout << "scor = 0"
             << " out of "
             << intrebare_scor
             << "!" << endl;
        cout << "Correct raspuns = "
             << Correct_raspuns
             << "." << endl;
        cout << endl;
    }
}
