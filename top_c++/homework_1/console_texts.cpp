#include <iostream>

using namespace std;

string task_1();
string task_2();
string task_3();

void main()
{
    cout << task_1();
    cout << "\n\n\tPress any key for the next task ";
    cin.get();

    cout << string(50, '\n');
    cout << task_2();
    cout << "\n\n\tPress any key for the final task ";
    cin.get();

    cout << string(50, '\n');
    cout << task_3();
}

string task_1()
{   
    string poem;
    return poem = 
        "\t\'Jabberwocky\' by Lewis Carroll\n\n"
        "\'Twas brillig, and the slithy toves\n"
        "Did gyre and gimble in the wabe:\n"
        "All mimsy were the borogoves,\n"
        "And the mome raths outgrabe.\n\n"
        "\"Beware the Jabberwock, my son\n"
        "The jaws that bite, the claws that catch!\n"
        "Beware the Jubjub bird, and shun\n"
        "The frumious Bandersnatch!\"\n\n"
        "He took his vorpal sword in hand;\n"
        "Long time the manxome foe he sought—\n"
        "So rested he by the Tumtum tree\n"
        "And stood awhile in thought.\n"
        "And, as in uffish thought he stood,\n"
        "The Jabberwock, with eyes of flame,\n"
        "Came whiffling through the tulgey wood,\n"
        "And burbled as it came!\n\n"
        "One, two!One, two!And through and through\n"
        "The vorpal blade went snicker - snack!\n"
        "He left it dead, and with its head\n"
        "He went galumphing back.\n\n"
        "\"And hast thou slain the Jabberwock\?\n"
        "Come to my arms, my beamish boy!\n"
        "O frabjous day!Callooh!Callay!\"\n"
        "He chortled in his joy.\n\n"
        "\'Twas brillig, and the slithy toves\n"
        "Did gyre and gimble in the wabe:\n"
        "All mimsy were the borogoves,\n"
        "And the mome raths outgrabe.\n\n";
}

string task_2()
{
    string hunter_text;
    return hunter_text = 
        "Every\n"
        "\tHunter\n"
        "\t\tWants\n"
        "\t\t\tTo Know\n"
        "\t\t\t\tWhere\n"
        "\t\t\t\t\tDoes\n"
        "\t\t\t\t\t\tPheasant\n"
        "\t\t\t\t\t\t\tSit";
}

string task_3()
{
    setlocale(LC_ALL, "Russian");
    string advertisement;
    return advertisement =
        "\t\tÏðîäàì ìîïåä\n\n"
        "           r==                        \n"
        "      _   //                          \n"
        "      |_)//(''''':                    \n"
        "        //  \\_____:_____.-----.P     \n"
        "       //   | ===  |   /        \\    \n"
        "   .:'//.   \\ \\=|   \\ /  .:'':.    \n"
        "  : ' // ' : \\ \\ ''..'--:'-.. ':    \n"
        "  '. '' .'    \\ : ....--'.-'' .'     \n"
        "   ':..:'                ':..:'       "
        "\n\n\t\tÌîïåä íå ìîé\n"
        "\t\tÒåë. 123-456-789\n\n";
}